#include<graphics.h>
#include<iostream>

using namespace std;



int main()
{
    int gd = DETECT, gm, errorcode;
    int maxx,maxy;
    char a[100];

    initgraph(&gd, &gm, "");

    errorcode = graphresult();

    if (errorcode != grOk)
    {
        /* an error occurred */
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1);               /* terminate with an error code */
    }

    maxx=getmaxx();

    for(int i=0,color;i<=maxx&&!kbhit();i++,color++)
    {
        if(i<maxx)
            cleardevice();
        sprintf(a,"Distance: %d",i);
        outtextxy(520,10,a);

        //SUN
        setcolor(YELLOW);
        circle(70,50,35);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(70,50,YELLOW);

        //ROAD
        setcolor(DARKGRAY);
        line(0,310,maxx,310);
        line(0,410,maxx,410);

        //BOARD
        setfillstyle(8,BLUE);
        bar3d(500-i*5,180,520-i*5,310,5,0);
        setfillstyle(3,BLUE);
        bar3d(430-i*5,120,590-i*5,180,5,5);
        setcolor(WHITE);
        outtextxy(485-i*5,150,"START");


        //Buildings
        setcolor(MAGENTA);
        rectangle(700-i*5,150,800-i*5,310);

        setcolor(BLUE);
        rectangle(950-i*5,150,1050-i*5,310);

        setcolor(GREEN);
        rectangle(1200-i*5,100,1300-i*5,310);

        setcolor(YELLOW);
        rectangle(1500-i*5,175,1600-i*5,310);

        setcolor(BLUE);
        rectangle(1800-i*5,100,1900-i*5,310);

        setcolor(MAGENTA);
        rectangle(2100-i*5,150,2200-i*5,310);

        setcolor(YELLOW);
        rectangle(2400-i*5,175,2500-i*5,310);

        setcolor(GREEN);
        rectangle(2750-i*5,100,2850-i*5,310);


        if(i<600)
        {
            //BUILDING
            setcolor(LIGHTRED);
            rectangle(3050-i*5,150,3150-i*5,310);

            //BOARD
            setcolor(DARKGRAY);
            setfillstyle(8,BLUE);
            bar3d(3500-i*5,180,3520-i*5,310,5,0);
            setfillstyle(3,BLUE);
            bar3d(3430-i*5,120,3590-i*5,180,5,1);
            setcolor(WHITE);
            outtextxy(3495-i*5,150,"STOP");


           //BUS
            setcolor(DARKGRAY);
            setfillstyle(LINE_FILL,CYAN);
            bar3d(-370+i,250,-130+i,350,10,1);
            setcolor(YELLOW);
            rectangle(-350+i,280,-310+i,320);
            rectangle(-300+i,280,-260+i,320);
            rectangle(-250+i,280,-210+i,320);
            rectangle(-200+i,280,-160+i,320);
            setcolor(color);
            arc(-330+i,350,180,360,25);
            arc(-170+i,350,180,360,25);

        }
       else
        {
            //BUILDING
            setcolor(LIGHTRED);
            rectangle(50,150,150,310);

            //BOARD
            setcolor(DARKGRAY);
            setfillstyle(8,BLUE);
            bar3d(505,180,525,310,5,0);
            setfillstyle(3,BLUE);
            bar3d(435,120,595,180,5,1);
            setcolor(WHITE);
            outtextxy(500,150,"STOP");

            //BUS
            setcolor(DARKGRAY);
            setfillstyle(LINE_FILL,CYAN);
            bar3d(230,250,470,350,10,1);
            setcolor(YELLOW);
            rectangle(250,280,290,320);
            rectangle(300,280,340,320);
            rectangle(350,280,390,320);
            rectangle(400,280,440,320);
            setcolor(color);
            arc(270,350,180,360,25);
            arc(430,350,180,360,25);
        }



        if(i==0)
        {
            setcolor(WHITE);
            outtextxy(200,420,"Press any key to start");
            getch();
        }
        else if(i==maxx)
        {
            setcolor(WHITE);
            outtextxy(200,420,"Press any key to Exit");
            getch();
        }

        if(color==15)
            color=1;

        delay(10);

    }

    closegraph();
}
