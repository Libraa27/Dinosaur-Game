#include "dohoa.h"
#include <string>
#include <vector>
#define pb push_back
//#include <graphics.h>
#define sl_ground 109 // sl_ground: số lượng phần tử mặt đất

int xdino, ydino, xdat=6, ydat,cuii,nt,check,ma=0,score=0,hs,hp;
int h=6,jump,tien,vt=0,kt[7]={0,-1,-1,-1,-1,-1,-1};
int cao, dai;
int t[3],loai[3],xb[7],yb[7],dem[7]={0,0,0,0,0,0,0},gia[7]={0,50,100,150,250,500,1000};
vector <char> ground[3];
string money[4]=
{
    "|---| ",
    "|$$$| ",
    "|---| ",
};
string dino[9]=
{
    "              __ ",
    "             /*_)",
    "      /-^^^-/ /  ",
    " _/--/       /\\-<",
    "<___.|_|--|_|  ^ ",
    "     |__\\ |__\\",
};
string khien[9]=
{
    "              __ \\ ",
    "             /*_) \\ ",
    "      /-^^^-/ /    )",
    " _/--/       /\\-<  )",
    "<___.|_|--|_|  ^  / ",
    "     |__\\ |__\\   / ",
};
string die[9]=
{
    //"                   ",
    "              __ ",
    "             /*_)",
    "      /-^^^-/ /  ",
    " _/--/       /\\-<",
    "<___.|_|--|_|  ^ ",
    "     |__\\ |__\\",
    //"                   ",
};
string xoahet[9]=
{
    "                 ",
    "                 ",
    "                  ",
    "                   ",
    "                 ",
    "                ",
};
string cui[9]=
{
    "                 ",
    "                 ",
    "      /-^^^-\\_/\\_",
    " _/--/        _*_)",
    "<___.|_|--|_| \\-< ",
    "     |__\\ |__\\ ^",
};
string khien_cui[9]=
{
    "                 \\",
    "                  \\",
    "      /-^^^-\\_/\\_  )",
    " _/--/        _*_) )",
    "<___.|_|--|_| \\-< / ",
    "     |__\\ |__\\ ^ /",
};
string xoa="                   ";
string cay[5]=
{
    " ++++++ ",
    "+  ++ ",
    "+++++  + ",
    "   +++++ ",
    "   ++ ",
};
string chim[4]=
{
    "  __ ",
    "<(o )__. ",
    "  \\ _~_/ ",
};
void play();
void ve_khung_long(int y, int z);
void tao_dat(int i);
void khoi_tao_mat_dat();
void ve_mat_dat();
void di_chuyen_mat_dat();
void ve_cay(int x, int y);
void xoa_cay(int x);
void chuyen_toa_do_cay(int &nt, int vt);
void di_chuyen_cay(int &nt);
int kt_va_cham (int x, int y,int hp);
int game_over(int y, int nt,int hp);
void ve_khung();
bool menu();
bool huongdan();
bool mo_shop();
bool buff();
void del();
void shop();
bool zoom();
int main()
{
    srand(time(NULL)); // Khởi tạo lại hàm random
    ShowCur(0); // Xóa nháy con trỏ
    HideCursor();
    system("cls");
    getTerminalSize(dai, cao);
    xdino=dai/5, ydat=cao-1-cao/10, xdat=6 , ydino=ydat-h,tien=1000;
    //ve_khung();
    //ve_khung_long(ydino);
    //khoi_tao_mat_dat();
    //ve_mat_dat();
    //menu();
    if(menu()==false) return 0;
    return 0;
}
void play()
{

    HideCursor();
    int demm=0;
    hs=1,hp=1;
    if(kt[1]==1 && dem[1]>0){
        dem[1]--;
        hp++;
    }
    if(dem[1]==0) kt[1]=-1;
    for(int i=2;i<=5;i++){
        if(kt[i]==1){
            if(dem[i]==0){
                kt[i]=-1;
            }
            else {
                hs=gia[i]*2/100;
                dem[i]--;
            }
        }
        else{
            gotoXY(dai/2,cao/2);
            cout << "-1" ;
        }
    }
    if(kt[6]==1 && dem[6]>0){
        hs=50;
        dem[6]--;
    }
    if(dem[6]==0) kt[6]=-1;
    system("cls");
    gotoXY((dai-60)/2, (cao-8)/2);
    cout << "NEU BAN DA SAN SANG, AN MOT TRONG CAC PHIM DI CHUYEN DE BAT DAU!";
    gotoXY((dai-53)/2, ((cao-8)/2)+1);
    cout << "NHAN PHIM M DE QUAY LAI MENU HOAC ESC DE THOAT!";

    getTerminalSize(dai, cao);
    xdino=dai/5, ydat=cao-1-cao/10, xdat=6 , ydino=ydat-h,cuii=0,nt=0,check=2,score=0;
    //gotoXY(0,0);
    //cout << nt ;
    //cout << dai << " " << cao ;
    int cnt=0, y=ydino;
    double v=dai/cao;
    ve_khung();
    khoi_tao_mat_dat();
    ve_khung_long(ydino, hp);
    ve_mat_dat();
    //sleep(100);
    while(true){
        if(zoom()==true) play();
        int ch=getch();
        if(int(ch)==32 || (int)ch==119 || (int)ch==115){
            gotoXY((dai-60)/2, (cao-8)/2);
            cout << "                                                                 ";
            gotoXY((dai-53)/2, ((cao-8)/2)+1);
            cout << "                                                ";
            break;
        }
        else if((int)ch==-32 || (int)ch==224){
            int ch=getch();
            if(int(ch)==80 || (int)ch==72 || (int)ch==77 || (int)ch==75){
                gotoXY((dai-60)/2, (cao-8)/2);
                cout << "                                                                 ";
                gotoXY((dai-53)/2, ((cao-8)/2)+1);
                cout << "                                                ";
                break;
            }
        }
        else if(ch=='m' || (int)ch==27 || ch=='M') menu();
    }
    while (true)
    {
        ma=max(ma,score);
        gotoXY(6,3);
        cout << "Tien:" << tien ;
        gotoXY(6,2);
        cout << "Highest score:" << ma ;
        if(zoom()==true){
            for(int i=1;i<=2;i++){
                ground[i].clear();
            }
            ve_khung_long(ydino, hp);
            ve_mat_dat();
        }
        //gotoXY(0,0);
        //cout << dai << " " << cao ;
        xdino=dai/5, ydat=cao-1-cao/10, ydino=ydat-h,jump=cao/2;
        //gotoXY(0,2);
        //cout << cuii ;
        //ve_mat_dat();
        gotoXY (dai/2 - 4,2);
        cout << "Score:" << score;
        score+=hs;
        if (cnt == 0)
        {
            t[nt]=dai-6-8;
            loai[nt]=rand()%3 + 1 ;
            if(score <= 1000*hs && loai[nt]==2) loai[nt]=1 ;
            nt++;
            cnt=rand()%(dai - dai/2 + 1) + dai/2 ;
        }
        di_chuyen_cay(nt);
        int c=game_over(y,nt,hp);
        if (c!=-1)
        {
            hp--;
            if(hp>0){
                for(int i=0;i<=5;i++){
                    gotoXY(xdino, y+i);
                    cout << xoahet[i] << "  " ;
                }
                ve_khung_long(y,hp);
                continue;
            }
            else{
                gotoXY((dai-10)/2,(cao-10)/2);
                cout << "Game Over" ;
                gotoXY((dai-25)/2,(cao-10)/2+1);
                cout << "Bam phim Space de choi lai";
                Sleep(3000);
                while(true){
                    int c=getch();
                    if(c=='m' || c=='M' || (int)c==27){
                        menu();
                        getch();
                    }
                    if(int(c)==32 || (int)c==119 || (int)c==115) break;
                    if((int)c==-32 || (int)c==224){
                        int ch=getch();
                        if(int(ch)==80 || (int)ch==72) break;
                    }
                    else continue;
                }
                play();
            }
        }
        if (_kbhit())
        {
            char c=getch();
            if (c == -32) // -32: phím mũi tên điều hướng
            {
                // Sau lần ấn phím mũi tên thì giá trị trả về sẽ được gán vào c để kiểm tra tiếp
                c=getch();
                if (c == 72 && check == 2) // 72: phím mũi tên đi lên
                {
                    check=1; // di len
                }
            }
            else if ((c == 32 && check == 2) || (check==2 && c==119)) // 32: phím cách; 119: w
            {
                check=1;
            }
        }
        else if(GetAsyncKeyState('S') & 0x8000 && check==2){
            for(int i=0;i<=5;i++){
                gotoXY(xdino, ydino+i);
                cout << xoahet[i] ;
                gotoXY(xdino, ydino+i);
                if(hp==1) cout << cui[i] ;
                else cout << khien_cui[i] ;
            }
            for(int i=0;i<nt;i++) ve_cay(t[i],loai[i]);
            cuii=2;
            ma=max(ma,score);
            gotoXY(6,3);
            cout << "Tien:" << tien ;
            gotoXY(6,2);
            cout << "Highest score:" << ma ;
        }
        else if(GetAsyncKeyState(VK_DOWN) & 0x8000 && check ==2 ){
            for(int i=0;i<=5;i++){
                gotoXY(xdino, ydino+i);
                cout << xoahet[i] ;
                gotoXY(xdino, ydino+i);
                if(hp==1) cout << cui[i] ;
                else cout << khien_cui[i] ;
            }
            for(int i=0;i<nt;i++) ve_cay(t[i],loai[i]);
            cuii=2;
            ma=max(ma,score);
            gotoXY(6,3);
            cout << "Tien:" << tien ;
            gotoXY(6,2);
            cout << "Highest score:" << ma ;
        }
        else if(cuii==2){
            cuii=0;
            ve_khung_long(y, hp);
            for(int i=0;i<nt;i++) ve_cay(t[i],loai[i]);
        }
        if (check == 1) // di len
        {
            gotoXY (xdino, y+h-1); // Xóa chân khi khủng long nhảy
            cout << xoa;
            //ve_mat_dat();
            y--;
            ve_khung_long(y, hp);
        } else if (check == 0) // di xuong
        {
            if(demm==1){
                gotoXY (xdino, y); // Xóa đầu khi khủng long nhảy
                cout << xoa;
                y++;
                ve_khung_long(y, hp);
            }
        }
        else if(check==3){
            gotoXY (xdino, y+h-1);
            cout << xoa;
            //ve_mat_dat();
            for(int i=0;i<nt;i++) ve_cay(t[i],loai[i]);
            y--;
            ve_khung_long(y, hp);
        }
        if (y == ydino-jump) // Khi đạt đến độ cao mình chọn ban đầu thì cho đi xuống
        {
            check=0;
        }
        if (y == ydino) // Khi chạm đất thì cho đi thẳng
        {
            jump=cao/2;
            check=2;
        }
        cnt--;
        demm++;
        demm%=2;
        Sleep(v);
        if(score%(500*hs)==0) v/=2;
        di_chuyen_mat_dat();
    }
}

void ve_khung_long(int y, int z) // xong
{
    if(z==2){
        for (int i=0; i<6 ; i++){
            gotoXY (xdino, y+i);
            cout << xoa ;
            gotoXY (xdino, y+i);
            cout << khien[i] ;
        }
    }
    else for (int i=0; i<6 ; i++)
    {
        gotoXY (xdino, y+i);
        cout << xoa ;
        gotoXY (xdino, y+i);
        cout << dino[i] ;
    }
    cuii=0;
    /*gotoXY(6,3);
    cout << "tien:" << tien ;
    gotoXY(6,2);
    cout << "Highest score:" << ma ;*/
}

void ve_mat_dat() // xong
{
    gotoXY(6,ydat);
    for(int i=6;i<dai-5;i++)
    {
        cout << "." ;
    }
    for (int i=1; i<3; i++) // vẽ mặt đất
    {
        for(int j=0;j<dai-11;j++){
            gotoXY(xdat + j, ydat + i);
            cout << ground[i][j] ;
        }
    }
}
void ve_cay(int x,int y)
{
    if(y==1){
        for (int i=0; i<5; i++)
        {
            gotoXY (x, ydat-5+i);
            cout << cay[i];
        }
    }
    else if(y==2){
        for (int i=0; i<=3; i++)
        {
            gotoXY (x, ydat-7+i);
            cout << chim[i];
        }
    }
    else if(y==3){
        for (int i=0; i<3; i++)
        {
            gotoXY (x, ydat-6+i);
            cout << money[i] ;
        }
    }
}

void xoa_cay(int x) //xong
{
    int y=ydat-5;
    for (int i=0; i<9; i++)
    {
        gotoXY(x+8, y-4+i);// dịch chuyển con trỏ về vị trí cuối cùng của cây
        cout << " "; // xuất khoảng trắng xóa đuôi của cây khi di chuyển
    }
}

// Hàm dùng để chuyển đổi dữ liệu trong mảng lưu trữ cây
// Hàm này giúp hạn chế việc duyệt qua toàn bộ mảng t[] để vẽ hoặc xoá cây khi chúng di chuyển trên màn hình
// thay vào đó, chỉ cần duyệt qua số lượng cây hiện có được lưu trong nt
void chuyen_toa_do_cay(int &nt, int vt) //t[] lưu trữ tọa độ vẽ cây, vt: vị trí, nt: n tree
{
    if(vt>nt-1){
        nt--;
        return ;
    }
    for (int i=vt; i<=nt-1; i++)
    {
        t[i]=t[i+1];
        loai[i]=loai[i+1];
    }
    nt--; // giảm 1 cây sau khi cây phía trước chạm mặt đất
}

void di_chuyen_cay(int &nt) // giảm từ từ tọa độ x của cây và xóa đi phần thừa khi vẽ lại
{
    //gotoXY(0,1);
    //cout << nt ;
    if (t[0] == xdat)
    {
        chuyen_toa_do_cay(nt,0);
        for (int i=0; i<9; i++)
        {
            xoa_cay(xdat-i) ; // xóa cây khi cây chạm khung
        }
    }
    for (int i=0; i<nt; i++) // vẽ cây theo tọa độ mới
    {
        ve_cay(t[i],loai[i]);
        //xoa_cay(t[i]);
        t[i]--;
    }
}

int kt_va_cham (int x, int y, int hp)
{
    int z=loai[x];
    int x_cay=t[x];
    int x_tay=xdino+14, y_dino=y-cuii+5;
    if(z==1){
        int y_cay_max=ydat-5, y_cay_min=ydat, x_cay_phai=x_cay+8;
        if ((xdino >= x_cay && xdino < x_cay_phai) || (x_tay >= x_cay && x_tay <= x_cay_phai)) // xét tay và đuôi nằm trong khoảng của cây
        {
            if (y_dino >= y_cay_max && y_dino <= y_cay_min) // xét xem chân có chạm cây không khi chân nằm trong khoảng của cây
            {
                if(hp==2){
                    loai[x]=4;
                    return kt_va_cham( x, y, hp) ;
                }
                return x;
            }
        }
        return -1;
    }
    else if(z==2){
        int y_dau=ydat-7, y_chan=y_dau+2,x_duoi=x_cay+7;
        if(x_tay >= x_cay && x_tay <= x_duoi)
            if( (y<=y_chan && y>=y_dau) || (y_dino<=y_chan && y_dino>=y_dau) ){
                if(hp==2){
                    loai[x]=4;
                    return kt_va_cham ( x, y, hp) ;
                }
                return x;
            }
        if(x_tay >= x_cay && xdino < x_duoi)
            if(y_dino == y_dau){
                check=3;
            }
        if(xdino<=x_cay && x_duoi<=x_tay-3){
            if(y_dino == y_dau){
                check=3;
            }
        }
        return -1;
    }
    else if(z==3){
        if(x_cay<=x_tay && x_cay+5>=xdino){
            if(y_dino+4>=ydat-4){
                if(z==3) tien+=(hs*5);
                for (int i=0; i<6; i++)
                {
                    gotoXY (x_cay, ydat-6+i);
                    cout << xoa ;
                }
                if(cuii==2){
                    for(int i=0;i<=5;i++){
                        gotoXY(xdino, ydino+i);
                        cout << xoahet[i] ;
                        gotoXY(xdino, ydino+i);
                        if(hp==1) cout << cui[i] ;
                        else cout << khien_cui[i] ;
                    }
                }
                else ve_khung_long(y, hp);
                chuyen_toa_do_cay(nt,x);
                if(z==3) return -1;
                return x;
            }
            return -1;
        }
        return -1;
    }
    if(z==4){
                int y_cay_max=ydat-5, y_cay_min=ydat, x_cay_phai=x_cay+8;
        if ((xdino >= x_cay && xdino < x_cay_phai) || (x_tay >= x_cay && x_tay <= x_cay_phai)) // xét tay và đuôi nằm trong khoảng của cây
        {
            if (y_dino >= y_cay_max && y_dino <= y_cay_min) // xét xem chân có chạm cây không khi chân nằm trong khoảng của cây
            {
                for (int i=0; i<6; i++)
                {
                    gotoXY (x_cay, ydat-6+i);
                    cout << xoa ;
                }
                if(cuii==2){
                    for(int i=0;i<=5;i++){
                        gotoXY(xdino, ydino+i);
                        cout << xoahet[i] ;
                        gotoXY(xdino, ydino+i);
                        if(hp==1) cout << cui[i] ;
                        else cout << khien_cui[i] ;
                    }
                }
                else ve_khung_long(y, hp);
                chuyen_toa_do_cay(nt,x);
                if(z==3) return -1;
                return x;
            }
        }
        return -1;
    }
    return -1;
}

int game_over(int y, int nt,int hp)
{
    for (int i=0; i<nt; i++)
    {
        if (kt_va_cham(i, y+cuii,hp) == i )
        {
            for (int a=0; a<6; a++)
            {
                gotoXY(xdino, y+a);
                cout << die[a];
            }
            return i;
        }
    }
    return -1;
}

void ve_khung()
{
    for (int i=2; i<cao; i++)
    {
        gotoXY(5, i);
        cout << "|";
        gotoXY(dai-5, i);
        cout << "|";
    }
    for (int i=6; i<dai-5; i++)
    {
        gotoXY(i, 1);
        cout << "_";
        gotoXY(i, cao-1);
        cout << "_";
    }
}
void tao_dat(int i)
{
    int v=rand()%(15-1+1)+1;
    switch (v)
    {
        case 1:
        {
            ground[1].pb('.');
            ground[2].pb(' ');
            break;
        }
        case 2:
        {
            ground[1].pb('-');
            ground[2].pb(' ');
            break;
        }
        case 3:
        {
            ground[1].pb('`');
            ground[2].pb(' ');
            break;
        }
        case 4:
        {
            ground[1].pb((char)248);
            ground[2].pb(' ');
            break;
        }
        case 5:
        {
            ground[1].pb(' ');
            ground[2].pb('.');
            break;
        }
        case 6:
        {
            ground[1].pb(' ');
            ground[2].pb('-');
            break;
        }
        case 7:
        {
            ground[1].pb(' ');
            ground[2].pb('`');
            break;
        }
        case 8:
        {
            ground[1].pb(' ');
            ground[2].pb('o');
            break;
        }
        default:
        {
            ground[1].pb(' ');
            ground[2].pb(' ');
            break;
        }
    }
}

void khoi_tao_mat_dat()
{
    for (int i=0; i<dai-13; i++)
    {
        //ground[0][i]='_';
        tao_dat(i);
    }
    //ground[0][dai]='\0';
    //ground[1][dai]='\0';
    //ground[2][dai]='\0';
}
void di_chuyen_mat_dat()
{
    for (int i=0; i<ground[1].size(); i++)
    {
        ground[1][i]=ground[1][i+1];
        ground[2][i]=ground[2][i+1];
    }
    ground[1].pop_back();
    ground[2].pop_back();
    tao_dat(ground[1].size());
    ve_mat_dat();
}
bool menu(){
    HideCursor();
    system("cls");
    ve_khung();
    khoi_tao_mat_dat();
    ve_mat_dat();
    ve_khung_long(ydino, hp);
    if(zoom()==true) return menu();
    ve_khung_long(ydino, hp);
    ve_mat_dat();
    gotoXY(6,2);
    cout << "MENU" ;
    gotoXY(6,3);
    cout << "***************" ;
    gotoXY(6,4);
    cout << "1. Bat dau choi" ;
    gotoXY(6,5);
    cout << "2. Huong dan choi" ;
    gotoXY(6,6);
    cout << "3. Mo Shop" ;
    gotoXY(6,7);
    cout << "4. Thoat tro choi" ;
    gotoXY(6,8);
    cout << "***************" ;
    gotoXY(6,9);
    cout << "Moi ban nhan phim so tuong ung de chon!" ;
    gotoXY(dai-15,2);
    cout << "tien:" << tien ;
    gotoXY(dai-37,2);
    cout << "Highest score:" << ma ;
    char c=getch();
    if(c=='1'){
        return buff();
    }
    else if(c=='2'){
        return huongdan();
        //char d=getch();
    }
    else if(c=='3'){
        return mo_shop();
        //char d=getch();
    }
    else if(c=='4' || (int)c==27){
        system("cls");
        return false;
    }
    else return menu();
}
bool huongdan(){
    system("cls");
    ve_khung();
    if(zoom()==true) huongdan();
    gotoXY(6,2);
    cout << "Huong dan choi:" ;
    gotoXY(6,3);
    cout << "-Truoc khi bat dau choi, ban hay chon phep bo tro (neu co)" ;
    gotoXY(6,4);
    cout << "-Nhan phim Space hoac phim di len de nhan vat cua ban nhay len va nhan phim di xuong";
    gotoXY(6,5);
    cout << "de nhan vat cua ban cui xuong";
    gotoXY(6,6);
    cout << "-Nhan vat cua ban se chay khong ngung nghi cho toi khi va vao chuong ngai vat, ban";
    gotoXY(6,7);
    cout << "hay co gang de nhan vat di that xa de dat diem cao va nhat duoc nhieu tien";
    gotoXY(6,8);
    cout << " ";
    gotoXY(6,9);
    cout << "Nhan phim m de quay lai menu!";
    int c=getch();
    if((int)c==27 || c=='m' || c=='M') return menu();
}
bool mo_shop(){
    HideCursor();
    system("cls");
    ve_khung();
    gotoXY(6,2);
    cout << "Moi ban nhap phim so tuong ung de chon!" ;
    gotoXY(6,3);
    cout << "Nhan phim enter hoac space de mua!";
    gotoXY(6,4);
    cout << "Nhan phim ESC de thoat";
    if(zoom()==true) return mo_shop();
    vt=0;
    shop();
    for(int i=1;i<=6;i++){
        gotoXY(xb[i]+2,yb[i]+4);
        cout << gia[i] ;
    }
    while(true){
        if(zoom()==true) shop();
        char c=getch();
        if((int)c==27){
            system("cls");
            return menu();
        }
        if((int)c>=49 && (int)c<=54){
            vt = int(c) - 48;
            del();
        }
        if((int)c==224 || (int)c==-32 || (int)c==0){
            char c=getch();
            if(vt==0){
                if((int)c==72 || (int)c==80 || (int)c==75 || (int)c==77){
                    vt=1;
                    del();
                    continue;
                }
            }
            else if((int)c==80) if(vt<=3){
                vt+=3;
                del();
            }
            if((int)c==72) if(vt>3){
                vt-=3;
                del();
            }
            if((int)c==75) if(vt>1){
                vt--;
                del();
            }
            if((int)c==77) if(vt<6){
                vt++;
                del();
            }
        }
        if(((int)c==32 || (int)c==13) && vt!=0){
            if(tien>=gia[vt]){
                tien-=gia[vt];
                dem[vt]++;
                gotoXY(xb[vt]+11,yb[vt]);
                cout << dem[vt] << ")" ;
                gotoXY(dai-15,2);
                cout << "tien:" << tien << "  ";
            }
            else{
                gotoXY(dai/2 - 29,cao/2 - 10);
                cout << "BAN KHONG DU TIEN!" ;
                Sleep(1000);
                gotoXY(dai/2 - 13,cao/2 - 1);
                cout << "                  ";
            }
        }
        else continue;
    }
}
bool buff(){
    system("cls");
    int sl=0;
    for(int i=1;i<=6;i++) kt[i]=-1;
    ve_khung();
    shop();
    gotoXY(6,2);
    cout << "Moi ban nhap phim so tuong ung de chon!" ;
    gotoXY(6,3);
    cout << "Nhan space de chon" ;
    gotoXY(6,4);
    cout << "Nhan enter de bat dau" ;
    gotoXY(6,5);
    cout << "Nhan ESC de thoat";
    while(true){
        if(zoom()==true) shop();
        char c=getch();
        if((int)c==27){
            system("cls");
            return menu();
        }
        if((int)c>=49 && (int)c<=54){
            vt = int(c) - 48;
            del();
        }
        if((int)c==224 || (int)c==-32 || (int)c==0){
            char c=getch();
            if(vt==0) {
                if((int)c==72 || (int)c==80 || (int)c==75 || (int)c==77){
                    vt=1;
                    del();
                    continue;
                }
            }
            else if((int)c==72) if(vt>3){
                vt-=3;
                del();
            }
            if((int)c==80) if(vt<=3){
                vt+=3;
                del();
            }
            if((int)c==75) if(vt>1){
                vt--;
                del();
            }
            if((int)c==77) if(vt<6){
                vt++;
                del();
            }
        }
        if((int)c==32){
            if(vt==0)
            continue;
            if(dem[vt]==0){
                gotoXY(dai/2 - 15,cao/2 - 1);
                cout << "BAN KHONG CO DU VAT PHAM!" ;
                Sleep(1000);
                gotoXY(dai/2 - 15,cao/2 - 1);
                cout << "                         ";
                continue;
            }
            if(sl==2 && kt[vt]==-1){
                gotoXY(dai/2 - 15,cao/2 - 1);
                cout << "DA DAT GIOI HAN VAT PHAM!" ;
                Sleep(1000);
                gotoXY(dai/2 - 15,cao/2 - 1);
                cout << "                         ";
                continue;
            }
            kt[vt]=-kt[vt];
            sl+=kt[vt];
            if(kt[vt]==1){
                gotoXY(xb[vt]+8,yb[vt]);
                cout << "X" ;
            }
            else{
                gotoXY(xb[vt]+8,yb[vt]);
                cout << " " ;
            }
        }
        if((int)c==13){
            play();
        }
    }
}
void del(){
    for(int i=1;i<=6;i++){
        if(kt[i]==1) continue;
        gotoXY(xb[i]+8,yb[i]);
        cout << " " ;
    }
    gotoXY(xb[vt]+8,yb[vt]);
    cout << "X" ;
}
void shop(){
    HideCursor();
    vt=0;
    gotoXY(dai-15,2);
    cout << "tien:" << tien ;
    xb[1]=6 + (dai - 2*6)/7 ;
    yb[1]=2 + (cao- 2*2)/5;
    gotoXY(xb[1],yb[1]);
    cout << "1.khien( )(" << dem[1] << ")";
    gotoXY(xb[1]+1,yb[1]+1);
    cout << "/\\_/\\ " ;
    gotoXY(xb[1]+1,yb[1]+2);
    cout << "| O |" ;
    gotoXY(xb[1]+1,yb[1]+3);
    cout << " \\_/" ;

    xb[2]=6 + 3*(dai - 2*6)/7;
    yb[2]=2 + (cao- 2*2)/5;
    gotoXY(xb[2]-3,yb[2]);
    cout << "2.X2 score( )(" << dem[2] << ")";
    gotoXY(xb[2]+1,yb[2]+1);
    cout << " /\\" ;
    gotoXY(xb[2],yb[2]+2);
    cout << "< X2 >" ;
    gotoXY(xb[2],yb[2]+3);
    cout << " -\\/-" ;

    xb[3]=6 + 5*(dai - 2*6)/7;
    yb[3]=2 + (cao- 2*2)/5;
    gotoXY(xb[3]-3,yb[3]);
    cout << "3.X3 score( )(" << dem[3] << ")" ;
    gotoXY(xb[3]+1,yb[3]+1);
    cout << " /\\" ;
    gotoXY(xb[3],yb[3]+2);
    cout << "< X3 >" ;
    gotoXY(xb[3],yb[3]+3);
    cout << " -\\/-" ;

    xb[4]=6 + (dai - 2*6)/7;
    yb[4]=2 + 3*(cao- 2*2)/5;
    gotoXY(xb[4]-3,yb[4]);
    cout << "4.X5 score( )(" << dem[4] << ")" ;
    gotoXY(xb[4]+1,yb[4]+1);
    cout << " /\\" ;
    gotoXY(xb[4],yb[4]+2);
    cout << "< X5 >" ;
    gotoXY(xb[4],yb[4]+3);
    cout << " -\\/-" ;

    xb[5]=6 + 3*(dai - 2*6)/7;
    yb[5]=2 + 3*(cao- 2*2)/5;
    gotoXY(xb[5]-4,yb[5]);
    cout << "5.X10 score( )(" << dem[5] << ")" ;
    gotoXY(xb[5]+1,yb[5]+1);
    cout << " /\\" ;
    gotoXY(xb[5],yb[5]+2);
    cout << "< X10 >" ;
    gotoXY(xb[5],yb[5]+3);
    cout << " -\\/-" ;

    xb[6]=6 + 5*(dai - 2*6)/7;
    yb[6]=2 + 3*(cao- 2*2)/5;
    gotoXY(xb[6]-4,yb[6]);
    cout << "6.X50 score( )(" << dem[6] << ")" ;
    gotoXY(xb[6]+1,yb[6]+1);
    cout << " /\\" ;
    gotoXY(xb[6],yb[6]+2);
    cout << "< X50 >" ;
    gotoXY(xb[6],yb[6]+3);
    cout << " -\\/-" ;
}
bool zoom(){
    HideCursor();
    int d=dai,c=cao;
    getTerminalSize(dai, cao);
    if(d!=dai || c!=cao){
        for(int i=1;i<=2;i++){
            ground[i].clear();
        }
        xdino=dai/5, ydat=cao-1-cao/10, ydino=ydat-h;
        system("cls");
        khoi_tao_mat_dat();
        ve_khung();
        return true;
    }
    return false;
}
