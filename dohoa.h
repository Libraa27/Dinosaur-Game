#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <chrono>
#include <thread>
#include "windows.h"
#define KEY_NONE -1
using namespace std;
// Hàm lấy thông tin về tọa độ X của con trỏ trong cửa sổ terminal
int whereX()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))
    return csbi.dwCursorPosition.X;
    return -1;
}
// Hàm lấy thông tin về tọa độ Y của con trỏ trong cửa sổ terminal
int whereY()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))
    return csbi.dwCursorPosition.Y;
    return -1;
}
// Hàm di chuyển con trỏ đến tọa độ đã được chỉ định (x, y) trong cửa sổ terminal
void gotoXY(short int x, short int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x,y};
    hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,Cursor_an_Pos);
}
// Hàm chỉnh sửa màu chữ trong cửa sổ terminal
void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput,&screen_buffer_info);

    WORD wAttributes=screen_buffer_info.wAttributes;
    color&=0x000f;
    wAttributes&=0xfff0;
    wAttributes|=color;

    SetConsoleTextAttribute(hConsoleOutput,wAttributes);
}
// Hàm chỉnh sửa màu nền cửa sổ terminal
void SetBackgroundColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
// Hàm điều chỉnh hiển thị của con trỏ trong cửa sổ terminal
void ShowCur(bool CursorVisibility)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor={1,CursorVisibility};
    SetConsoleCursorInfo(handle,&cursor);
}
// Hàm trả về mã phím được nhập
int inputKey()
{
    if (_kbhit()) {
        int key=_getch();
        if (key == 224) {
            key=_getch();
            return key+1000;
        }
        return key;
    } else {
        return KEY_NONE;
    }
    return KEY_NONE;
}
// Hàm nhấp nháy văn bản trong khoảng thời gian nhất định
void flashText(const string text, double durationInSeconds, int x, int y)
{
    bool visible = true;
    auto startTime = chrono::steady_clock::now();
    while (chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - startTime).count() < durationInSeconds)
    {
        gotoXY(x, y);
        cout << (visible ? text : string(text.length(), ' ')) << '\r';
        cout.flush();
        visible = !visible;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}
// Hàm lấy kích thước màn hình terminal
void getTerminalSize(int &width, int &height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE; // Đặt bVisible thành FALSE để tắt nháy
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
