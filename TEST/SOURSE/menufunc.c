#include"common.h"
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
#include "file.h"
#include"outline.h"

/*************************************************************
函数名：menu_func(int state, int *func, struct mpdata *mp,USER *u)
参数：思维导图版式state,界面参数的地址*func,思维导图结构体的地址*mp,用户数据地址*u
返回值：无
函数功能：思维导图界面的所有功能的调用
**************************************************************/	
void menu_func(int state, int *func, struct mpdata *mp,USER *u)
{

	int light=0;
	int i;
	int m;
	int n;
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
	int click3=0;
	char *s;
	char *filename;
	redrawbar(*mp);
	redrawnode(state, *mp);
	redrawline(state, *mp);
	redrawstar(*mp);
	printhz(*mp);
	draw_menu(*mp);

	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		//上移思维导图
		if(MouseX > 10 && MouseX < 20 && MouseY > 450 && MouseY < 460)
		{
			if (mouse_press(10, 450, 20, 460) == 1)
			{
				mpup(state, mp);
			}	
			
		}

		//下移思维导图
		if(MouseX > 10 && MouseX < 20 && MouseY > 470 && MouseY < 480)
		{
			if (mouse_press(10, 470, 20, 480) == 1)
			{
				mpdown(state, mp);					
			}
		}	

		//左移思维导图
		if(MouseX > 0 && MouseX < 10 && MouseY > 460 && MouseY < 470)
		{
			if (mouse_press(0, 460, 10, 470) == 1)
			{			
				mpleft(state, mp);
			}
		}

		//右移思维导图
		if(MouseX > 20 && MouseX < 30 && MouseY > 460 && MouseY < 470)
		{
			if (mouse_press(20, 460, 30, 470) == 1)
			{			
				mpright(state, mp);
			}
		}	

		//大纲模式
		if(MouseX>0 && MouseX<60 && MouseY>84 && MouseY<104)	
		{
			if(click1 == 1 && mouse_press(0, 84, 60, 104)==1)
			{
				clrmous(MouseX, MouseY);
				cleardevice();
				if (state == 1)
				{
					*func = 14;
					return;
				}
				if (state == 2)
				{
					*func = 15;
					return;
				}					
			}
		}

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
					if(MouseX>472 && MouseX<525 && MouseY>0 && MouseY<24)
					{	
						if(mouse_press(472,0,525,24)==1)
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
					if(MouseX>472 && MouseX<525 && MouseY>0 && MouseY<24)
					{	
						if(mouse_press(472,0,525,24)==1)
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
					if(MouseX>472 && MouseX<525 && MouseY>0 && MouseY<24)
					{	
						if(mouse_press(472,0,525,24)==1)
						break;
					}
					
				}	
			}
		}

		//取消
		if(MouseX>474 && MouseX<525 && MouseY>0 && MouseY<24)
		{
			if(mouse_press(464,10,515,24)==2)			
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

			if(mouse_press(606,0,630,24) == 2)
			{
				MouseS = 1;
				continue;
			}
		}

		//编辑标亮
		if(MouseX>360 && MouseX<415 && MouseY>0 && MouseY<24)
		{
			if(mouse_press(350,0,405,24)==2)
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

		//帮助
		if(MouseX>415 && MouseX<472 && MouseY>0 && MouseY<24)
		{
			if(mouse_press(405,0,475,24)==2)
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

			if(mouse_press(415,0,472,24) == 1)
			{
				clrmous(MouseX, MouseY);
				cleardevice();
				MouseS=0;
				*func =6;
				return;
			}
		}
		//鼠标形状变换
		if(MouseS!=0)
		{
			MouseS=0;
		}

		//编辑标亮
		if(MouseX>360 && MouseX<415 && MouseY>0 && MouseY<24)
		{
			if(mouse_press(350,0,405,24)==2)
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
			if(mouse_press(245,0,350,24)==2)
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
			if(mouse_press(155,0,245,24)==2)
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
			if(mouse_press(50,0,155,24)==2)
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
			
			if(mouse_press(0,0,50,24)==2)
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
				redrawbar(*mp);
				redrawstar(*mp);
				redrawnode(state, *mp);
				redrawline(state, *mp);
				printhz(*mp);
				draw_menu(*mp);
				click1 = 0;
				continue;
			}
			
			if((MouseX <= 60 || MouseX > 165 || MouseY > 184) && click2 == 1 )
			{
				//menu_z_recover(2);
				redrawbar(*mp);
				redrawstar(*mp);
				redrawnode(state, *mp);
				redrawline(state, *mp);
				printhz(*mp);
				draw_menu(*mp);
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
			if(state == 1)
				*func = 8;
			if(state == 2)
				*func = 9;
			return;
		}



		//保存	
		if(click1 == 1 && (mouse_press(0,44,60,64) ==1 ))
		{
			clrmous(MouseX,MouseY);
			cleardevice();
			*func=4;
			return;
		}

		//历史
		if(click1 == 1 && (mouse_press(0,65,60,85)) == 1)
		{
			clrmous(MouseX,MouseY);
			cleardevice();
			*func = 5;
			return;
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
				if(MouseX>472 && MouseX<525 && MouseY>0 && MouseY<24)
				{	
					if(mouse_press(472,0,525,24)==1)
					{
						redrawbar(*mp);
						redrawstar(*mp);
						redrawnode(state, *mp);
						redrawline(state, *mp);
						printhz(*mp);
						draw_menu(*mp);
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
				if(MouseX>472 && MouseX<525 && MouseY>0 && MouseY<24)
				{	
					if(mouse_press(472,0,525,24)==1)
					{
						redrawbar(*mp);
						redrawstar(*mp);
						redrawnode(state, *mp);
						redrawline(state, *mp);
						printhz(*mp);
						draw_menu(*mp);
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
				if(MouseX>472 && MouseX<525 && MouseY>0 && MouseY<24)
				{	
					if(mouse_press(472,0,525,24)==1)
					{
						redrawbar(*mp);
						redrawstar(*mp);
						redrawnode(state, *mp);
						redrawline(state, *mp);
						printhz(*mp);
						draw_menu(*mp);
						break;				
					}
				}	
			}
		}

		//连线
		if(click2 == 1 && (mouse_press(60, 124, 165, 144)) == 1)
		{
 			while(1)
			{	
				newmouse(&MouseX, &MouseY, &press);
				mplink(state, mp);
				//取消
				if(MouseX>472 && MouseX<525 && MouseY>0 && MouseY<24)
				{	
					if(mouse_press(472,0,525,24)==1)
					{
						break;				
					}
				}	
			}
		}
		//连线状态
		if(click2 == 1)
		{
			if (mouse_press(60, 144, 165, 164) == 1)
			{
				clrmous(MouseX,MouseY);
				linkstate(state, 1, mp);
			}
			if (mouse_press(60, 144, 165, 164) == 3)
			{
				clrmous(MouseX,MouseY);
				linkstate(state, 2, mp);
			}
				
		}
		//折叠
		if(click2 == 1 && mouse_press(60, 164, 165, 184) == 1)
		{
			while(1)
			{
				newmouse(&MouseX, &MouseY, &press);
				mpnode(state, mp);
				//取消
				if(MouseX>472 && MouseX<525 && MouseY>0 && MouseY<24)
				{	
					if(mouse_press(472,0,525,24)==1)
					{
						break;				
					}
				}	
			}	
				
		}
		//折叠恢复
		if(click2 == 1 && mouse_press(60, 164, 165, 184) == 3)
		{
			recovernode(mp);
			//重新画文本框
			clrmous(MouseX,MouseY);
			redrawbar(*mp);
			redrawnode(state, *mp);
			redrawstar(*mp);
			//重新画连接线
			redrawline(state, *mp);
			//输出汉字
			printhz(*mp);
			//画页面
			draw_menu(*mp);
			delay(100);
		}
		//标注
		if(click2 == 1 && (mouse_press(60, 104, 165, 124)) == 1)
		{
 			while(1)
			{	
				newmouse(&MouseX, &MouseY, &press);
				changestar(state, mp);
				//取消
				if(MouseX>472 && MouseX<525 && MouseY>0 && MouseY<24)
				{	
					if(mouse_press(472,0,525,24)==1)
					{
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
				if(MouseX>472 && MouseX<525 && MouseY>0 && MouseY<24)
				{	
					if(mouse_press(472,0,525,24)==1)
					{
						redrawbar(*mp);
						redrawstar(*mp);
						redrawnode(state, *mp);
						redrawline(state, *mp);
						printhz(*mp);
						draw_menu(*mp);
						break;				
					}
				}	
			}
		}	

		//删除
		if(MouseX > 525 && MouseX < 575 && MouseY > 0 && MouseY < 24)
		{
			if(mouse_press(515,0,565,24) == 2)
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

			if(mouse_press(525,0,575,24) == 1)
			{
				clrmous(MouseX,MouseY);
				cleardevice();
				*func = 3;
				return;	
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



