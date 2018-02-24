#include <graphics.h>
#include<iostream>

using namespace std;

int main(void)

{

   int gdriver = DETECT, gmode, errorcode, sec;
   int midx, midy;
   char a[50];

   cout<<"Enter Seconds Left: ";
   cin>>sec;


   /* initialize graphics and local variables */

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

   for(int i=sec;i>0;i--)
   {
        sprintf(a,"Time Left: %d Seconds",i);
        settextstyle(7,HORIZ_DIR,5);
        outtextxy(80,midy,a);
        delay(1000);
        cleardevice();
   }

   cout<<"\a";
   setcolor(GREEN);
   outtextxy(180,midy,"Time's Up");
   setcolor(YELLOW);
   delay(500);
   outtextxy(180,midy-100,"Time's Up");
   setcolor(BLUE);
   delay(500);
   outtextxy(180,midy+100,"Time's Up");

   /* clean up */

   delay(5000);

   closegraph();

   return 0;

}

