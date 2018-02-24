#include<graphics.h>
#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    int midx, midy,i,j,num;
    char a[100];

    int hrx[12];
    int hry[12];

    int minx[60];
    int miny[60];

    int secx[60];
    int secy[60];


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

    midx=getmaxx()/2;
    midy=getmaxy()/2;

    //HOURS COORDINATES
    for(i=30,j=0;j<12;i+=30,j++)
    {
        hrx[j]=100*sin(i*3.14/180);
        hry[j]=-(100*cos(i*3.14/180));
    }

    //MINUTES COORDINATES
    for(i=6,j=0;j<60;i+=6,j++)
    {
        minx[j]=130*sin(i*3.14/180);
        miny[j]=-(130*cos(i*3.14/180));
    }

    //SECOND COORDINATES
    for(i=6,j=0;j<60;i+=6,j++)
    {
        secx[j]=150*sin(i*3.14/180);
        secy[j]=-(150*cos(i*3.14/180));
    }


     while(!kbhit())
    {
        cleardevice();

        rawTime=time(NULL);
        currentTime= localtime(&rawTime);

        settextstyle(0,HORIZ_DIR,2);

        //CIRCLE
        setcolor(BLUE);
        circle(midx,midy,200);

        //NUMBERS
        setcolor(LIGHTBLUE);
        outtextxy(midx+100,midy-155,"1");
        outtextxy(midx+160,midy-85,"2");
        outtextxy(midx+175,midy,"3");
        outtextxy(midx+150,midy+85,"4");
        outtextxy(midx+95,midy+140,"5");
        outtextxy(midx,midy+180,"6");
        outtextxy(midx-100,midy+145,"7");
        outtextxy(midx-160,midy+85,"8");
        outtextxy(midx-190,midy,"9");
        outtextxy(midx-170,midy-85,"10");
        outtextxy(midx-105,midy-155,"11");
        outtextxy(midx-10,midy-190,"12");

        //HOUR
        strftime(a,100,"%I",currentTime);
        sscanf(a,"%d",&num);
        setcolor(LIGHTMAGENTA);
        line(midx,midy,midx+hrx[num-1],midy+hry[num-1]);


        //MIN
        strftime(a,100,"%M",currentTime);
        sscanf(a,"%d",&num);
        setcolor(MAGENTA);
        line(midx,midy,midx+minx[num-1],midy+miny[num-1]);

        //SEC
        strftime(a,100,"%S",currentTime);
        sscanf(a,"%d",&num);
        setcolor(LIGHTRED);
        line(midx,midy,midx+secx[num-1],midy+secy[num-1]);

        setcolor(BLUE);
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(290,150,"D&G");

        //EXIT
        setcolor(WHITE);
        settextstyle(0,HORIZ_DIR,1);
        outtextxy(230,450,"Press any key to exit");

        delay(1000);

    }

    closegraph();

}
