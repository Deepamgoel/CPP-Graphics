#include<graphics.h>

int main()
{
    DWORD x=GetSystemMetrics(SM_CXSCREEN);
    DWORD y=GetSystemMetrics(SM_CYSCREEN);

    int maxx, maxy;

    initwindow(x,y,"GRID");

    maxx=getmaxx();
    maxy=getmaxy();

    unsigned int rec_x=0, rec_y=0;


    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        cleardevice();

        setcolor(RED);

        if(GetAsyncKeyState(VK_RIGHT))
        {
            rec_x+=5;
        }
        else if(GetAsyncKeyState(VK_LEFT))
        {
            rec_x-=5;
        }

        else if(GetAsyncKeyState(VK_UP))
        {
            rec_y-=2;
        }

        else if(GetAsyncKeyState(VK_DOWN))
        {
            rec_y+=2;
        }

        rectangle(rec_x, rec_y, rec_x+100, rec_y+20);

        getch();

    }

}
