#ifndef CALCY_GRAPHICS_H_INCLUDED
#define CALCY_GRAPHICS_H_INCLUDED
int trig=1;
const int x=200,y=40;
void text()
{
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    {if(trig==1)
         outtextxy(x+30,y+64,"X");                             //key 1
    else outtextxy(x+10,y+64,"TRIGNO");}             //key 1
    outtextxy(x+110,y+64,"1");                                 //key 2
    outtextxy(x+190,y+64,"2");                                 //key 3
    outtextxy(x+270,y+64,"3");                                 //key 4
    outtextxy(x+350,y+64,"+");                                 //key 5
    outtextxy(x+20,y+104,"x^y");                              //key 6
    outtextxy(x+110,y+104,"4");                                //key 7
    outtextxy(x+190,y+104,"5");                                //key 8
    outtextxy(x+270,y+104,"6");                                //key 9
    outtextxy(x+350,y+104,"-");                                 //key 10
    outtextxy(x+30,y+144,"x!");                                 //key 11
    outtextxy(x+110,y+144,"7");                                //key 12
    outtextxy(x+190,y+144,"8");                                //key 13
    outtextxy(x+270,y+144,"9");                                //key 14
    outtextxy(x+350,y+144,"*");                                //key 15
    outtextxy(x+20,y+184,"x^2");                              //key 16
    outtextxy(x+105,y+184,"AC");                             //key 17
    outtextxy(x+190,y+184,"0");                                //key 18
    outtextxy(x+265,y+184,"<--");                             //key 19
    outtextxy(x+350,y+184,"/");                                 //key 20
    outtextxy(x+25,y+224,"Pi");                                 //key 21
    outtextxy(x+95,y+224,"SQRT");                         //key 22
    outtextxy(x+190,y+224,".");                                //key 23
    outtextxy(x+270,y+224,"=");                               //key 24
    outtextxy(x+340,y+224,"+/-");                             //key 25
    outtextxy(x+30,y+264,"(");                                  //key 26
    outtextxy(x+110,y+264,")");                                //key 27
    outtextxy(x+330,y+264,"CHECK");                    //key 30
    outtextxy(x+256,y+264,"log10");

    circle(x+195,y+275,10);                 //POWER
    line(x+195,y+275,x+195,y+263);          // KEY(28)
    line(x+196,y+275,x+196,y+263);
    line(x+194,y+275,x+194,y+263);
    circle(x+195,y+275,9);

   if(trig==1)
    {outtextxy(x-60,y+64,"Sin");        //key 31
     outtextxy(x-60,y+104,"Cos");       //key 32
     outtextxy(x-60,y+144,"Tan");       //key 33
     outtextxy(x-72,y+184,"Sin^-1");    //key 34           //sine inverse button
     outtextxy(x-72,y+224,"Cos^-1");    //key 35           //cosine inverse button
     outtextxy(x-72,y+264,"Tan^-1");    //key 36           //tangent inverse button

    }
   //if(powchk==1)
   //{outtextxy(x+40,y+350,"DO YOU REALLY WANT TO EXIT ?"); outtextxy(x+38,y+370,"(Y for yes/N for no)");}

}


#endif // CALCY_GRAPHICS_H_INCLUDED
