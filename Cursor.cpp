#include <graphics.h>
#include<iostream>

using namespace std;

int main(void)

{
    DWORD x=GetSystemMetrics(SM_CXSCREEN);
    DWORD y=GetSystemMetrics(SM_CYSCREEN);

    initwindow(x,y,"");

    POINT cursorPos;

    while(1)
    {
        GetCursorPos(&cursorPos);
        setcolor(BLUE);
        circle(cursorPos.x,cursorPos.y,50);
        delay(50);
    }

    return 0;

}

