#include<graphics.h>

int main()
{
    DWORD x=GetSystemMetrics(SM_CXSCREEN);
    DWORD y=GetSystemMetrics(SM_CYSCREEN);

    initwindow(x,y,"");

    POINT cursor;

    while(1)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&cursor);
            setcolor(BLUE);
            bar(cursor.x,cursor.y,cursor.x+10,cursor.y+10);
            delay(5);
        }
    }

    return 0;

}
