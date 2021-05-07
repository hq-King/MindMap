#include "common.h"
#include "stytle.h"
#include<graphics.h>
#include"drawmenu.h"
#include"menufunc.h"
#include"mpfunc.h"
/*************************************************************
函数名：Color_Bar_Choice(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：文本框颜色的选择
**************************************************************/	
void Color_Bar_Choice(int state, struct mpdata *mp)
{
    int i;
    int j;
    int flag = 0;
    if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
                    while(flag == 0)
                    {
                        newmouse(&MouseX,&MouseY,&press);
                        if( mouse_press(415, 55, 467 , 75) == 1)
                        {
                            (*mp).text[i][j].barcolor = RED;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(467, 55, 519 , 75) == 1)
                        {
                            (*mp).text[i][j].barcolor = WHITE;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(519, 55, 571 , 75) == 1)
                        {
                            (*mp).text[i][j].barcolor = LIGHTBLUE;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(571, 55, 624 , 75) == 1)
                        {
                            (*mp).text[i][j].barcolor = DARKGRAY;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(415, 75, 467, 95) == 1)
                        {       
                            (*mp).text[i][j].barcolor = BROWN;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(467, 75, 519, 95) == 1)
                        {
            
                            (*mp).text[i][j].barcolor = MAGENTA;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(519, 75, 571, 95) == 1)
                        {
            
                            (*mp).text[i][j].barcolor = GREEN;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(571, 75, 624, 95) == 1)
                        {
         
                            (*mp).text[i][j].barcolor = YELLOW;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(415, 95, 467 , 115) == 1)
                        {
            
                            (*mp).text[i][j].barcolor = LIGHTGRAY;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(467, 95, 519 , 115) == 1)
                        {
            
                            (*mp).text[i][j].barcolor = CYAN;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(519, 95, 571 , 115) == 1)
                        {
            
                            (*mp).text[i][j].barcolor = LIGHTGREEN;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(571, 95, 624 , 115) == 1)
                        {
            
                            (*mp).text[i][j].barcolor = LIGHTCYAN;
                            flag = 1;
                            break;
                        }

                        else  if( mouse_press(415, 115, 467 , 135) == 1)
                        {
           
                            (*mp).text[i][j].barcolor = BLUE;
                            flag = 1;
                            break;
                        }

                        else if( mouse_press(467, 115, 519 , 135) == 1)
                        {
            
                            (*mp).text[i][j].barcolor = LIGHTRED;
                            flag = 1;
                            break;
                        }
 
                        else if( mouse_press(519, 115, 571 , 135) == 1)
                        {
                            (*mp).text[i][j].barcolor = LIGHTMAGENTA; 
                            flag = 1;  
                            break;             
                        }       
                    } 
                    if(flag == 1)
                    {   
                        delay(10);
                        clrmous(MouseX,MouseY);
		                redrawbar(*mp);
                        redrawnode(state, *mp);
					    redrawstar(*mp);
                        redrawline(state, *mp);
                        printhz(*mp);
                        draw_menu(*mp);
                        Draw_Choice_Color();
                    }
                }
            }
        }
    }
    
}
/*************************************************************
函数名：Color_Line_Choice(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：自动生成连接线颜色的选择
**************************************************************/	
void Color_Line_Choice(int state, struct mpdata *mp)                
{
    int i;                
    int flag = 0;
    if( mouse_press(415, 55, 467 , 75) == 1)
    {
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = RED;
        }
        flag = 1;
    }

    else if( mouse_press(467, 55, 519 , 75) == 1)
    {
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = WHITE;
        }
        flag = 1;
    }

    else if( mouse_press(519, 55, 571 , 75) == 1)
    {
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = LIGHTBLUE;
        }
         flag = 1;
    }

    else if( mouse_press(571, 55, 624 , 75) == 1)
    {
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = DARKGRAY;
        }    
        flag = 1;

    }
    else if( mouse_press(415, 75, 467, 95) == 1)
    {       
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = BROWN;
        }
        flag = 1;
    }

    else if( mouse_press(467, 75, 519, 95) == 1)
    {
            
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = MAGENTA;
        }
        flag = 1;
    }

    else if( mouse_press(519, 75, 571, 95) == 1)
    {
            
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = GREEN;
        }
        flag = 1;
    }

    else if( mouse_press(571, 75, 624, 95) == 1)
    {
         
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = YELLOW;
        }
        flag = 1;
    }

    else if( mouse_press(415, 95, 467 , 115) == 1)
    {
            
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = LIGHTGRAY;
        }
        flag = 1;
    }

    else if( mouse_press(467, 95, 519 , 115) == 1)
    {
            
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = CYAN;
        }
        flag = 1;
    }

    else if( mouse_press(519, 95, 571 , 115) == 1)
    {
            
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = LIGHTGREEN;
        }
        flag = 1;
    }

    else if( mouse_press(571, 95, 624 , 115) == 1)
    {
            
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = LIGHTCYAN;
        }
        flag = 1;
    }

    else  if( mouse_press(415, 115, 467 , 135) == 1)
    {
           
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = BLUE;
        }
        flag = 1;
    }

    else if( mouse_press(467, 115, 519 , 135) == 1)
    {
            
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = LIGHTRED;
        }
        flag = 1;
    }
 
    else if( mouse_press(519, 115, 571 , 135) == 1)
    {
        for (i = 0; i < (*mp).amoofline; i++)
        {
            (*mp).connect[i].linecolor = LIGHTMAGENTA;
        }
        flag = 1;            
    }        
    if(flag == 1)
    {   
        delay(10);
        clrmous(MouseX,MouseY);
	    redrawbar(*mp);
        redrawnode(state, *mp);
		redrawstar(*mp);
        redrawline(state, *mp);
        printhz(*mp);
        draw_menu(*mp);
        Draw_Choice_Color();
    }
}
/*************************************************************
函数名：Draw_Choice_Color()
参数：无
返回值：无
函数功能：绘制选择颜色的框
**************************************************************/	
void Draw_Choice_Color()
{
    setcolor(CYAN);
    setfillstyle(1, CYAN);
    rectangle(415, 35, 624, 135);
    bar(415, 35, 624, 55);
    line(415, 55, 624, 55);
    puthz(440, 36, "请选择你需要的颜色", 16, 20, BLUE);
   
    setcolor(CYAN);
    rectangle(415,35,624,135);
    setfillstyle(1,RED);
    setcolor(CYAN);
    line(415,35,415,55);
    bar(415, 55, 467 , 75);
    setfillstyle(1,WHITE);
    bar(467, 55, 519 , 75);
    setfillstyle(1,LIGHTBLUE);
    bar(519, 55, 571 , 75);
    setfillstyle(1,DARKGRAY);
    bar(571, 55, 624 , 75);
    setfillstyle(1,BROWN);
    bar(415, 75, 467, 95);
    setfillstyle(1,MAGENTA);
    bar(467, 75, 519, 95);
    setfillstyle(1,GREEN);
    bar(519, 75, 571, 95);
    setfillstyle(1,YELLOW);
    bar(571, 75, 624, 95);
    setfillstyle(1,LIGHTGRAY);
    bar(415, 95, 467 , 115);
    setfillstyle(1,CYAN);
    bar(467, 95, 519 , 115);
    setfillstyle(1,LIGHTGREEN);
    bar(519, 95, 571 , 115);
    setfillstyle(1,LIGHTCYAN);
    bar(571, 95, 624 , 115);
    setfillstyle(1,BLUE);
    bar(415, 115, 467 , 135);
    setfillstyle(1,LIGHTRED);
    bar(467, 115, 519 , 135);
    setfillstyle(1,LIGHTMAGENTA);
    bar(519, 115, 571 , 135);
}
/*************************************************************
函数名：Color_Bk_Choice(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：背景颜色的选择
**************************************************************/	
void Color_Bk_Choice(int state, struct mpdata *mp)
{
    int flag = 0;
    if( mouse_press(415, 55, 467 , 75) == 1)
    {
        (*mp).bkcolor = RED;
        flag = 1;
    }

    else if( mouse_press(467, 55, 519 , 75) == 1)
    {
        (*mp).bkcolor = WHITE;
        flag = 1;
    }

    else if( mouse_press(519, 55, 571 , 75) == 1)
    {
        (*mp).bkcolor = LIGHTBLUE;
        flag = 1;
    }

    else if( mouse_press(571, 55, 624 , 75) == 1)
    {
        (*mp).bkcolor = DARKGRAY;
        flag = 1;
    }

    else if( mouse_press(415, 75, 467, 95) == 1)
    {       
        (*mp).bkcolor = BROWN;
        flag = 1;
    }

    else if( mouse_press(467, 75, 519, 95) == 1)
    {
            
        (*mp).bkcolor = MAGENTA;
        flag = 1;
    }

    else if( mouse_press(519, 75, 571, 95) == 1)
    {
            
        (*mp).bkcolor = GREEN;
        flag = 1;
    }

    else if( mouse_press(571, 75, 624, 95) == 1)
    {
         
        (*mp).bkcolor = YELLOW;
        flag = 1;
    }

    else if( mouse_press(415, 95, 467 , 115) == 1)
    {
            
        (*mp).bkcolor = LIGHTGRAY;
        flag = 1;
    }

    else if( mouse_press(467, 95, 519 , 115) == 1)
    {
            
        (*mp).bkcolor = CYAN;
        flag = 1;
    }

    else if( mouse_press(519, 95, 571 , 115) == 1)
    {
            
        (*mp).bkcolor = LIGHTGREEN;
        flag = 1;
    }

    else if( mouse_press(571, 95, 624 , 115) == 1)
    {
            
        (*mp).bkcolor = LIGHTCYAN;
        flag = 1;
    }

    else  if( mouse_press(415, 115, 467 , 135) == 1)
    {
           
        (*mp).bkcolor = BLUE;
        flag = 1;
    }

    else if( mouse_press(467, 115, 519 , 135) == 1)
    {
            
        (*mp).bkcolor = LIGHTRED;
        flag = 1;
    }
 
    else if( mouse_press(519, 115, 571 , 135) == 1)
    {
        (*mp).bkcolor = LIGHTMAGENTA; 
        flag = 1;                
    }       
 
  
    if(flag == 1)
    {   
        delay(10);
        clrmous(MouseX,MouseY);
		redrawbar(*mp);
        redrawnode(state, *mp);
		redrawstar(*mp);
        redrawline(state, *mp);
        printhz(*mp);
        draw_menu(*mp);
        Draw_Choice_Color();
    }
}
/*************************************************************
函数名：Color_Bk_Choice(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：文本框汉字颜色的选择
**************************************************************/	
void Color_Hz_Choice(int state, struct mpdata *mp)
{
    int i;
    int j;
    int flag = 0;
    if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
                    while(flag == 0)
                    {
                        newmouse(&MouseX,&MouseY,&press);
                        if( mouse_press(415, 55, 467 , 75) == 1)
                        {
                            (*mp).text[i][j].hzcolor = RED;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(467, 55, 519 , 75) == 1)
                        {
                            (*mp).text[i][j].hzcolor = WHITE;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(519, 55, 571 , 75) == 1)
                        {
                            (*mp).text[i][j].hzcolor = LIGHTBLUE;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(571, 55, 624 , 75) == 1)
                        {
                            (*mp).text[i][j].hzcolor = DARKGRAY;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(415, 75, 467, 95) == 1)
                        {       
                            (*mp).text[i][j].hzcolor = BROWN;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(467, 75, 519, 95) == 1)
                        {
            
                            (*mp).text[i][j].hzcolor = MAGENTA;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(519, 75, 571, 95) == 1)
                        {
            
                            (*mp).text[i][j].hzcolor = GREEN;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(571, 75, 624, 95) == 1)
                        {
         
                            (*mp).text[i][j].hzcolor = YELLOW;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(415, 95, 467 , 115) == 1)
                        {
            
                            (*mp).text[i][j].hzcolor = LIGHTGRAY;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(467, 95, 519 , 115) == 1)
                        {
            
                            (*mp).text[i][j].hzcolor = CYAN;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(519, 95, 571 , 115) == 1)
                        {
            
                            (*mp).text[i][j].hzcolor = LIGHTGREEN;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(571, 95, 624 , 115) == 1)
                        {
            
                            (*mp).text[i][j].hzcolor = LIGHTCYAN;
                            flag = 1;
                            continue;
                        }

                        else  if( mouse_press(415, 115, 467 , 135) == 1)
                        {
           
                            (*mp).text[i][j].hzcolor = BLUE;
                            flag = 1;
                            continue;
                        }

                        else if( mouse_press(467, 115, 519 , 135) == 1)
                        {
            
                            (*mp).text[i][j].hzcolor = LIGHTRED;
                            flag = 1;
                            continue;
                        }
 
                        else if( mouse_press(519, 115, 571 , 135) == 1)
                        {
                            (*mp).text[i][j].hzcolor = LIGHTMAGENTA; 
                            flag = 1;  
                            continue;              
                        }       
                    } 
                    if(flag == 1)
                    {   
                        delay(10);
                        clrmous(MouseX,MouseY);
                        redrawnode(state, *mp);
					    redrawstar(*mp);
		                redrawbar(*mp);
                        redrawline(state, *mp);
                        printhz(*mp);
                        draw_menu(*mp);
                        Draw_Choice_Color();
                    }
                }
            }
        }
    }   
}


