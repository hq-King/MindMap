#include "common.h"
#include "mpfunc.h"
#include "hz.h"
#include"USER.h"
#include"func.h"
#include"input.h"
#include"menufunc.h"
#include"drawmenu.h"
#include"save.h"
#include "stytle.h"
#include "quit.h"
#include "help.h"
#include "popup.h"
#include"mpfunc.h"
#include "LIGANDCO.h"

/*************************************************************
函数名：void Draw_Visitor(struct mpdata mp)
参数：思维导图结构体
返回值：无
函数功能：绘制游客界面
**************************************************************/
void Draw_Visitor(struct mpdata mp)
{
   	setbkcolor(WHITE);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, 0, 640, 24);
	bar(616, 24, 640, 480);
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE, 0, 1);
	//文件
	line(60, 0, 60, 24);
	puthz(10, 4, "文件", 16, 24, DARKGRAY);
	//个性设置
	line(165, 0, 165, 24);
	puthz(68, 4, "个性设置", 16, 24, DARKGRAY);
	//添加主题
	line(255, 0, 255, 24);
	puthz(170, 4, "添加主题", 16, 20, DARKGRAY);
	//删除主题
	line(360, 0, 360, 24);
	puthz(260, 4, "删除主题", 16, 24, DARKGRAY);
	//预览
	line(415, 0, 415, 24);
	puthz(367, 4, "编辑", 16, 24, DARKGRAY);
	//帮助
	line(485,0,485,24);
	puthz(425,4,"帮助",16,24,DARKGRAY);
	//取消
	line(560,0,560,24);
	puthz(500,4,"取消",16,28,DARKGRAY);
	//错号
	line(616, 0, 616, 24);
	line(616, 0, 640, 0);
	line(616, 24, 640, 24);
	line(640, 0, 640, 24);
	line(616, 0, 640, 24);
	line(616, 24, 640, 0);
	setcolor(RED);		
}


/*************************************************************
函数名：void Visitor_Func(int state, int *func, struct mpdata *mp)
参数：思维导图结构体,界面跳转参数,状态判断
返回值：无
函数功能：游客界面调用
**************************************************************/
void Visitor_Func(int state, int *func, struct mpdata *mp)
{
   int light=0;
	int jud1=1;
	int jud2=1;
	int jud3=1;
	int jud4=1;
	int jud5=1;
	int jud6=1;
	int jud7=1;
	int jud8=1;
	int click=0;
	int click1=0;
	int click2=0;
	char *s;
	Draw_Visitor(*mp);
	redrawbar(*mp);
	redrawline(state, *mp);
	printhz(*mp);
	setcolor(RED);
    rectangle(530,26,610,50);
    puthz(532,28,"游客登录",16,20,RED);
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		//添加主题
		if(MouseX>165 && MouseX<255 && MouseY>0 && MouseY<24)	
		{
			if(mouse_press(165,0,255,24)==1)
			{
				while(1)
				{
					newmouse(&MouseX, &MouseY, &press);
					addmp(state, mp);
					//取消
					if(MouseX>485 && MouseX<560 && MouseY>0 && MouseY<24)
					{	
						if(mouse_press(485,0,560,24)==1)
						break;
					}
				}	
			}
		}
		//删除主题
		if(MouseX>255 && MouseX<360 && MouseY>0 && MouseY<24)	
		{
			if(mouse_press(255,0,360,24)==1)
			{
				while(1)
				{
					newmouse(&MouseX, &MouseY, &press);
					deletemp(state, mp);
					//取消
					if(MouseX>485 && MouseX<560 && MouseY>0 && MouseY<24)
					{	
						if(mouse_press(485,0,560,24)==1)
						break;
					}
					
				}	
			}
		}
		//编辑
		if(MouseX>360 && MouseX<415 && MouseY>0 && MouseY<24)	
		{
			if(mouse_press(360,0,415,24)==1)
			{
				while(1)
				{
					newmouse(&MouseX, &MouseY, &press);
					mpinputhz(state, mp);
					//取消
					if(MouseX>485 && MouseX<560 && MouseY>0 && MouseY<24)
					{	
						if(mouse_press(485,0,560,24)==1)
						break;
					}
					
				}	
			}
		}
		//取消
		if(MouseX>474 && MouseX<525 && MouseY>0 && MouseY<24)
		
			{
			//	if(mouse_press(485,0,560,24)==1)
			//	{
			//		MouseS=0;
			//		clrmous(MouseX,MouseY);
			//		Popup_Func(3);
			//	
			//	}

				if(mouse_press(474,0,525,24)==2)			
				{
					MouseS=1;
					if(light==0 && jud7==1)
					{
						light_menu(7);
						light=1;
						jud7=0 ;
					}
					continue;
				}
			}	

			//退出
			if(MouseX>616 && MouseX<640 && MouseY>0 && MouseY<24)
			{
				if(mouse_press(616,0,640,24) == 1)
				{
					MouseS=0;
					clrmous(MouseX,MouseY);
					Popup_Func(3);
				}

				if(mouse_press(616,0,640,24) == 2)
				{
					MouseS = 1;
					continue;
				}
			}

		//帮助
		if(MouseX>415 && MouseX<485 && MouseY>0 && MouseY<24)
		{
			if(mouse_press(415,0,485,24)==2)
			{
				MouseS=1;
				if(light==0 && jud6==1)
				{
					light_menu(6);
					light=1;
					jud6=0;
				}
				continue;
			}
			if(mouse_press(415,0,485,24) == 1)
			{
				MouseS = 0;
			clrmous(MouseX,MouseY);
			Popup_Func(11);
			continue;
			}
		}

		if(MouseS!=0)
		{
			MouseS=0;
		}

		//编辑标亮
		if(MouseX>360 && MouseX<415 && MouseY>0 && MouseY<24)
		{
			if(mouse_press(360,0,415,24)==2)
			{
				MouseS=1;
				if(light==0 && jud5==1)
				{
				light_menu(5);
				light=1;
				jud5=0;
				}
				continue;
			}
		}
	

			
		//删除主题标亮
		if(MouseX>255 && MouseX<360 && MouseY>0 && MouseY<24)
		{
			if(mouse_press(255,0,360,24)==2)
			{
				MouseS=1;
				if(light==0 && jud4==1)
				{
					light_menu(4);
					light=1;
					jud4=0;
				}
				continue;
			}
		}


		//添加主题标亮
		if(MouseX>165 && MouseX<255 && MouseY>0 && MouseY<24)
		{
			if(mouse_press(165,0,255,24)==2)
			{
				MouseS=1;
				if(light==0 && jud3==1)
				{
					light_menu(3);
					light=1;
					jud3=0;
				}
				continue;
			}
		}


		//个性设置
		if(MouseX>60 && MouseX<165 && MouseY>0 && MouseY<105)
		{
			if(mouse_press(60,0,165,24)==2)
			{
				MouseS=1;
				if(light==0 && jud2==1)
				{
					light_menu(2);
					light=1;
					jud2=0;
				}
				continue;
			}

			if((mouse_press(60,0,165,24) == 1) )
			//点击个性设置
			{
				clrmous(MouseX,MouseY);
				//menu_z_recover(1);
				//隐藏文件的下拉菜单
				init_z_menu(2);
				//个性设置下拉菜单
				click2 = 1;
				jud2 = 2;
				continue;
			}
		}
		
		//文件
		if(MouseX>0 && MouseX<60 && MouseY>0 && MouseY<104)
		{
			
			if(mouse_press(0,0,60,24)==2)
			{
				MouseS=1;
				if(light==0 && jud1==1)
				{
					light_menu(1);				
				    light=1;
				    jud1=0 ;
				}
				
				continue;
			}
			
			if((mouse_press(0,0,60,24) == 1) )
			//点击文件
			{
				init_z_menu(1);
				//文件下拉菜单
				jud1=2;
				click1 = 1;
				continue;
			}					
	    }
		
		//取消下拉菜单
		if(press == 1)
		{
			if((MouseX>60 || MouseX<0 || MouseY >104) && click1 == 1 )
			{
				//menu_z_recover(1);
				cleardevice();
				draw_menu(*mp);
				redrawbar(*mp);
				redrawline(state, *mp);
				printhz(*mp);
				setcolor(RED);
   				rectangle(530,26,610,50);
    			puthz(532,28,"游客登录",16,20,RED);
				click1 = 0;
				continue;
			}
			
			if((MouseX <= 60 || MouseX > 165 || MouseY > 105) && click2 == 1 )
			{
				//menu_z_recover(2);
				cleardevice();
				draw_menu(*mp);
				redrawbar(*mp);
				redrawline(state, *mp);
				printhz(*mp);
				setcolor(RED);
    			rectangle(530,26,610,50);
    			puthz(532,28,"游客登录",16,20,RED);
				click2 = 0;
				continue;
			}
		}
		
		//新建
		if(click1 == 1 && mouse_press(0,24,60,44) == 1)
		{
			memset(mp,'\0', sizeof(struct mpdata));
			initmp(state, mp);
			clrmous(MouseX, MouseY);
			cleardevice();
			*func == 10;
			return;
		}



		//保存	
		if(click1 == 1 && (mouse_press(0,44,60,64) ==1 ))
		{
			MouseS = 0;
			clrmous(MouseX,MouseY);
			Popup_Func(11);
			continue;
		}

		//历史
		if(click1 == 1 && (mouse_press(0,65,60,85)) == 1)
		{
			MouseS = 0;
			clrmous(MouseX,MouseY);
			Popup_Func(11);
			continue;
		}
	
		//个性设置连接线颜色选择
		if(click2 == 1 && (mouse_press(60, 24, 165, 44)) == 1)
		{
			Draw_Choice_Color();
 			while(1)
			{
				newmouse(&MouseX, &MouseY, &press);
                Color_Line_Choice(state, mp);
				//取消
				if(MouseX>474 && MouseX<525 && MouseY>0 && MouseY<24)
				{	
					if(mouse_press(474,0,525,24)==1)
					{
						cleardevice();
						redrawbar(*mp);
						redrawline(state, *mp);
						printhz(*mp);
						setcolor(RED);
    					rectangle(530,26,610,50);
    					puthz(532,28,"游客登录",16,20,RED);
						break;				
					}
				}	
			}
		}	


		//个性设置文本框颜色选择
		if(click2 == 1 && (mouse_press(60,44,165,64)) == 1)
		{
			Draw_Choice_Color();
            while(1)
			{
				newmouse(&MouseX, &MouseY, &press);
                Color_Bar_Choice(state, mp);
				//取消
				if(MouseX>485 && MouseX<560 && MouseY>0 && MouseY<24)
				{	
					if(mouse_press(485,0,560,24)==1)
					{
						cleardevice();
						redrawbar(*mp);
						redrawline(state, *mp);
						printhz(*mp);
						setcolor(RED);
    					rectangle(530,26,610,50);
    					puthz(532,28,"游客登录",16,20,RED);
						break;				
					}
				}	
			}
		}

		//个性设置背景颜色选择
		if(click2 == 1 && (mouse_press(60, 64, 165, 84)) == 1)
		{
			Draw_Choice_Color();
 			while(1)
			{
				newmouse(&MouseX, &MouseY, &press);
                Color_Bk_Choice(state, mp);
				//取消
				if(MouseX>485 && MouseX<560 && MouseY>0 && MouseY<24)
				{	
					if(mouse_press(485,0,560,24)==1)
					{
						cleardevice();
						redrawbar(*mp);
						redrawline(state, *mp);
						printhz(*mp);
						setcolor(RED);
   						 rectangle(530,26,610,50);
    					puthz(532,28,"游客登录",16,20,RED);
						break;				
					}
				}	
			}
		}

		//个性设置字体颜色选择
		if(click2 == 1 && (mouse_press(60,84,165,104)) == 1)
		{
			Draw_Choice_Color();
            while(1)
			{
				newmouse(&MouseX, &MouseY, &press);
                Color_Hz_Choice(state, mp);
				//取消
				if(MouseX>485 && MouseX<560 && MouseY>0 && MouseY<24)
				{	
					if(mouse_press(485,0,560,24)==1)
					{
						cleardevice();
						redrawbar(*mp);
						redrawline(state, *mp);
						printhz(*mp);
						setcolor(RED);
    					rectangle(530,26,610,50);
    					puthz(532,28,"游客登录",16,20,RED);
						break;				
					}
				}	
			}
		}	

		if(MouseX > 525 && MouseX < 575 && MouseY > 0 && MouseY < 24)
		{
			if(mouse_press(525,0,575,24) == 2)
			{
				MouseS=1;
				if(light==0 && jud8==1)
				{
					light_menu(8);				
				    light=1;
				    jud8=0 ;
				}
				
				continue;
			}
		}
		
		
		//取消菜单标亮
		if(light!=0)
		{
			if(jud1==0)
			{
				light_menu_recover(1);
				jud1=1;
			}

			if(jud2==0)
			{
				light_menu_recover(2);
				jud2=1;
			}	
			
			if(jud3==0)
			{
				light_menu_recover(3);
				jud3=1;
			}
			if(jud4==0)
			{
				light_menu_recover(4);
				jud4=1;
			}
			if(jud5==0)
			{
				light_menu_recover(5);
				jud5=1;
			}
			if(jud6==0)
			{
				light_menu_recover(6);
				jud6=1;
			}
			if(jud7==0)
			{
				light_menu_recover(7);
				jud7=1;
			}

			if(jud8==0)
			{
				light_menu_recover(8);
				jud8=1;
			}

			light=0;

		}

		
	}

}
