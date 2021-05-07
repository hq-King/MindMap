#include "communit.h"
#include "common.h"
#include "file.h"
#include "save.h"
#include "history.h"
#include"mpfunc.h"
#include"menufunc.h"

/*************************************************************
函数名：void draw_community()
参数:	无
返回值：无
函数功能：绘制用户收藏界面
**************************************************************/
void Draw_Community()
{
	
    setbkcolor(LIGHTCYAN);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	pieslice(200,210,0,360,70);
	bar(170,270,170+60,270+40);
	bar(177,320,177+46,320+15);
	bar(185,345,185+30,345+15);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(200,210-90,200,210-110);
	line(200-90,210,200-110,210);
	line(200+90,210,200+110,210);
	line(200+64,210+64,200+78,210+78);
	line(200+64,210-64,200+78,210-78);
	line(200-64,210+64,200-78,210+78);
	line(200-64,210-64,200-78,210-78);
    //绘制灯泡          

    puthz(27, 20, "于此处查看您的收藏", 24,30,YELLOW);
    puthz(373, 24, "选择目录进行查看", 24,30,YELLOW);
    setfillstyle(1,WHITE);
    setcolor(BLUE);
    rectangle(369,59,601,461);
    bar(370, 60, 600, 460);

   	bar(10,390,350,450);

	bar(10,455,70,475);
	bar(290,455,350,475);
	rectangle(10,455,70,475);
	rectangle(290,455,350,475);

	rectangle(9,389,349,449);

	line(10,420,350,420);
	line(100,390,100,450);
	puthz(20,392,"查看",16,54,RED);
	puthz(20,422,"删除",16,54,RED);
	puthz(18,456,"确定",16,30,RED);
	puthz(298,456,"返回",16,30,RED);
}

/*************************************************************
函数名：void Community_func(int *func, USER *u,struct mpdata *mp,struct comparedata *CMP)
参数:	界面跳转判断值func，用户指针，结构体指针
返回值：无
函数功能：收藏功能调用
**************************************************************/
void Community_func(int *func, USER *u,struct mpdata *mp,struct comparedata *CMP)
{
	int fun;
	int format;
	int click1;
	int click2;
	int j;
    File allfile[FILEMAX];
    char filename[20];
	Draw_Community();
    //判断有无上传记录
    if(u->num!=0)
    {
		//导出并且打印出上传文件目录
        Output_CFilemenu(allfile, u->user);
        Printfilemenu_History(allfile,u->num);
	}
	


    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);

        if(MouseX > 290 && MouseX < 350 && MouseY > 455 && MouseY < 475)
        {
            //返回按钮
            if(mouse_press(290,455,350,475) == 1)
            {
            
                        clrmous(MouseX,MouseY);
						cleardevice();
						*func = 3;
                        return ;
                    
            }

            if(mouse_press(290,455,350,475) == 2)
            {
                MouseS = 1;
                continue;
            }
        }


		//查看按钮
    if(MouseX > 100 && MouseX < 350 && MouseY > 390 && MouseY < 420)
        {
            if(mouse_press(100,390,350,420) == 2)
            {
                MouseS = 2;
                continue;
            }

            if(mouse_press(100,390,350,420) == 1)
            {
				clrmous(MouseX,MouseY);
				click1=1;
				//输入文件名并且获取版式信息
				EnterFileName(filename,110,391,7,WHITE);
				format=getfileformat(u->user,filename);
				continue;
			}
		}
		//删除
		if(MouseX > 100 && MouseX < 350 && MouseY > 420 && MouseY < 450)
        {
            if(mouse_press(100,420,350,450) == 2)
            {
                MouseS = 2;
                continue;
            }

            if(mouse_press(100,420,350,450) == 1)
            {
				clrmous(MouseX,MouseY);
				click2=1;
				EnterFileName(filename,110,420,7,WHITE);			
				continue;
			}
				
		}

		//确定按钮
		if(MouseX > 10 && MouseX < 70 && MouseY > 455 && MouseY < 475)
		{
			if((mouse_press(10,455,70,475) == 1) && click2==1)
			{
				clrmous(MouseX, MouseY);
				//得到文件是否存在
				fun = Examine_Filename(u, allfile, filename);
				
				//文件存在且没达到最大文件数
				if(fun == 2)
				{
					Delete_filename(allfile, filename, u->history); 
					//删除文件名					
					u->num--; 
					//用户上传历史减一
					Input_num(u->user,u->num);
					//修改用户结构体内容
					Input_Cfilemenu(allfile, u->user);
					//重新输入文件菜单
					puthz(220,362,"删除成功",24,30,BLUE);
					delay(1500);
					cover_save(220, 362,LIGHTCYAN);
					*func = 12;
					return;
				}
				if(fun == 1 || fun ==3)
				{
					puthz(260,372,"无此文件",24,30,BLUE);
					delay(1500);
					cover_save(260, 372,CYAN);
					*func = 12;
					return;
				}
			}

			if((mouse_press(10,455,70,475) == 1) && click1 == 1)
			{
				clrmous(MouseX, MouseY);
				fun = Examine_Filename(u, allfile, filename);
				if(fun == 2 && format == 3)
				//为对比版式
				{
					memset(CMP,'\0', sizeof(struct comparedata));
					Output_Cfile(u->user,CMP,filename);
					puthz(220,362,"即将打开",24,30,BLUE);
					delay(1000);
					clrmous(MouseX,MouseY);
					cleardevice();
					//返回主界面
					*func = 13;
					return;
				}

				if(fun == 2 && format!= 3)
				{
					//为版式一或者是版式二
					memset(mp,'\0', sizeof(struct mpdata));
					initmp(format, mp);
					Output_File(u->user,mp,filename);
					//导出指定文件数据
					puthz(220,362,"即将打开",24,30,BLUE);
					delay(1000);
					clrmous(MouseX,MouseY);
					cleardevice();
					//返回主界面
					if( format == 1)
                    {
                        clrmous(MouseX,MouseY);
						cleardevice();						
						*func = 8;
                        return ;
                    }

                    if( format == 2)
                    {
                        clrmous(MouseX,MouseY);
						cleardevice();						
						*func = 9;
                        return ;
                    }
					
				}
				if(fun == 1 || fun ==3)
				{					
					puthz(260,372,"无此文件",24,30,BLUE);
					delay(1500);
					cover_save(260, 372,LIGHTCYAN);
					*func = 12;
					return;
				}				 
			}
		}
    }
}


