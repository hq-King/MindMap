#include"common.h"
#include"USER.h"
#include"func.h"
#include"input.h"
#include"menufunc.h"
#include"mpfunc.h"
#include "select.h"
#include "popup.h"

/*************************************************************
函数名：void select(int *func, struct mpdata *mp,int *statue,USER *u,int judge,int *tate)
参数：界面跳转参数,思维导图结构体指针,用户或者游客状态判断,用户结构体指针,判断版式
返回值：无
函数功能：选择调用
**************************************************************/
void select(int *func, struct mpdata *mp,int *statue,USER *u,int judge,int *tate)
{
	int light=0;
	int jud1=0;
	int jud2=0;
	int jud3=0;
	int jud4=0;

	setbkcolor(CYAN);
	setcolor(BLUE);
	rectangle(170,60,450,90);
	puthz(178,62,"选择您所需要的版式",24,30,YELLOW);
	
	setfillstyle(SOLID_FILL,WHITE);
	
	bar(200,160,400,320);
	rectangle(200,160,400,320);
	line(200,240,400,240);
	line(300,160,300,320);
	puthz(220,190,"版式一",16,20,BLUE);
	puthz(220,270,"版式二",16,20,BLUE);
	puthz(312,190,"对比模式",16,20,BLUE);
	puthz(312,270,"用户收藏",16,20,BLUE);
	setcolor(RED);
    rectangle(580,10,630,40);
    puthz(585,15,"退出",16,20,BLUE);

	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);

		//版式一
		if(MouseX > 200 && MouseX < 300 && MouseY > 160 && MouseY <240)
		{
		if (mouse_press(200, 160, 300, 240) == 1)
			{
				if(judge == 1)
				//用户
			{
				u->format = 1;
				clrmous(MouseX, MouseY);
				initmp(1, mp);
				clrmous(MouseX,MouseY);
				cleardevice();
				*statue = 1;
				*func = 8;
				return;
			}

			if (judge == 2)
			//游客登陆
			{
				Popup_Func(14);
				delay(500);
				*func = 3;
				return;
			}
			}

			if(mouse_press(210, 150, 290, 230) == 2 )
			{
				MouseS = 1;
				if(light == 0 && jud1 ==0)
				
				{
					Light_Select(1);
					light = 1;
					jud1 = 1;
				}
				continue;
			}

		}
	//版式二
		if(MouseX > 200 && MouseX < 300 && MouseY > 240 && MouseY <320)
		{
			if (mouse_press(200,240,300,320) == 1)
			{
				if(judge == 1)
				{
					u->format = 2;
					clrmous(MouseX, MouseY);
					initmp(2, mp);
					clrmous(MouseX,MouseY);
					cleardevice();
					*statue = 2;
					*func = 9;
					return;
				}

				if (judge == 2)
				{
					Popup_Func(14);
					delay(500);
					*func = 3;
					return;
				}

			}

			if(mouse_press(190,230,290,310) == 2)
			{
				MouseS = 1;
				if(light == 0 && jud2 ==0)
				
				{
					Light_Select(2);
					light = 1;
					jud2 = 1;
				}
				continue;
			}
		}

	//对比版式
	if(MouseX >300 && MouseX < 400 && MouseY > 160 && MouseY <240)
	{
		
		if(mouse_press(290,150,390,230)==2)
		{
				MouseS = 1;
				if(light == 0 && jud3 ==0)
				
				{
					Light_Select(3);
					light = 1;
					jud3 = 1;
				}
				continue;
		}
		if(mouse_press(300,160,400,240)==1)
		{
			if(judge == 1)
			
			{
				u->format =3;
				*tate = 1;
			}

			if(judge ==2)
			{
				*tate = 0;
			}
			clrmous(MouseX,MouseY);
			cleardevice();
			*func =11;
			return;
		}
	}

	

		//用户社区
	if(MouseX >300 && MouseX < 400 && MouseY > 240 && MouseY <320)
	{
		
		if(mouse_press(290,230,390,310)==2)
		{
				MouseS = 1;
				if(light == 0 && jud4 ==0)
				
				{
					Light_Select(4);
					light = 1;
					jud4 = 1;
				}
				continue;
		}

		if(mouse_press(300,240,400,320)==1)
		{
			if(judge ==1)
			{
				MouseS = 0;
				clrmous(MouseX,MouseY);
				cleardevice();
				*func =12;
				return;
			}

			if (judge == 2)
			{
				Popup_Func(14);
				delay(500);
				*func = 3;
				return;
			}
		}

	}
	  if(MouseX > 580 && MouseX < 630 && MouseY >10 && MouseY <40)
        {
            if(mouse_press(580,10,630,40) == 1)
            {
            MouseS=0;
				clrmous(MouseX,MouseY);
				Popup_Func(3);
			}
            if(mouse_press(580,10,630,40) == 2)
            {
                MouseS = 1;
                continue;
            }
        }


		if(MouseS != 0)
		{
			MouseS = 0;
			continue;
		}

		if(light != 0)
		{
			if(jud1 == 1)
			{
				Recover_Select(1);
				jud1 = 0;
			}

			if(jud2 == 1)
			{
				Recover_Select(2);
				jud2 = 0;
			}
			if(jud3 == 1)
			{
				Recover_Select(3);
				jud3 = 0;
			}
			if(jud4 == 1)
			{
				Recover_Select(4);
				jud4 = 0;
			}
			light = 0;
		}
	}
}

/*************************************************************
函数名：void Light_Select(int n)
参数：编号
返回值：无
函数功能：高亮
**************************************************************/
void Light_Select(int n)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	delay(10);
	switch(n)
	{
		case 1:
		bar(200,160,300,240);
		rectangle(200,160,300,240);
		puthz(220,190,"版式一",16,20,WHITE);
		break;

		case 2:
		bar(200,240,300,320);
		rectangle(200,240,300,320);
		puthz(220,270,"版式二",16,20,WHITE);
		break;

		case 3:
		bar(300,160,400,240);
		rectangle(300,160,400,240);
		puthz(312,190,"对比模式",16,20,WHITE);
		break;

		case 4:
		bar(300,240,400,320);
		rectangle(300,240,400,320);
		puthz(312,270,"用户收藏",16,20,WHITE);
		break;

		default:
		printf("there is something wrong");
		break;
	}
}

/*************************************************************
函数名：void Recover_Select(int n)
参数：编号
返回值：无
函数功能：恢复高亮
**************************************************************/
void Recover_Select(int n)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(1, WHITE);

	switch(n)
	{
		case 1:
		bar(200,160,300,240);
		rectangle(200,160,300,240);
		puthz(220,190,"版式一",16,20,BLUE);

		case 2:
		bar(200,240,300,320);
		rectangle(200,240,300,320);
		puthz(220,270,"版式二",16,20,BLUE);
		break;

		case 3:
		bar(300,160,400,240);
		rectangle(300,160,400,240);
		puthz(312,190,"对比模式",16,20,BLUE);
		break;

		case 4:
		bar(300,240,400,320);
		rectangle(300,240,400,320);
		puthz(312,270,"用户收藏",16,20,BLUE);
		break;
	}
}