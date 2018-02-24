#include<graphics.h>
#include<iostream>
#include<time.h>

using namespace std;

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    int midx, midy,i;
    char a[100];

    time_t rawTime;
    struct tm * currentTime;

    initgraph(&gdriver, &gmode, "");

    errorcode = graphresult();

    if (errorcode != grOk) /* an error occurred */
    {

        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1);               // terminate with an error code

   }

    while(!kbhit())
    {
        rawTime=time(NULL);
        currentTime= localtime(&rawTime);

        //TIME
        setcolor(CYAN);
        strftime(a,100,"%I:%M:%S",currentTime);
        settextstyle(9,HORIZ_DIR,8);
        outtextxy(100,150,a);

        //AM/PM
        setcolor(LIGHTCYAN);
        strftime(a,100,"%p",currentTime);
        settextstyle(8,HORIZ_DIR,2);
        outtextxy(580,10,a);

        //DATE
        strftime(a,100,"%d/%m/%Y  %a",currentTime);
        settextstyle(8,HORIZ_DIR,4);
        outtextxy(160,240,a);

        //EXIT
        setcolor(WHITE);
        settextstyle(0,HORIZ_DIR,1);
        outtextxy(230,400,"Press any key to exit");

        delay(1000);
        cleardevice();
    }

    closegraph();

}
