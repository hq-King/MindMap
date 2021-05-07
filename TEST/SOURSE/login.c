#include"common.h"
#include"login.h"
#include"USER.h"
#include"func.h"
#include"input.h"
#include "quit.h"
#include "popup.h"
#include "file.h"
/*************************************************************
函数名：Userslogin_func(int *func,USER*u, struct mpdata *mp,int *judge) 
参数：界面参数地址*func,用户数据地址*u,思维导图结构体地址*mp,判断是否登录成功的标志地址*judge
返回值：无
函数功能：登录界面的功能选择
**************************************************************/	
void Userslogin_func(int *func,USER*u, struct mpdata *mp,int *judge) 
{
	
	
	char	*s;
	int judge1=0;
	int judge2=0;

	draw_login();
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);

		//输入用户名
		if(MouseX>260 && MouseX<260+315 &&MouseY>190 &&MouseY<220)
		{
			if (mouse_press(260, 190, 260 + 315, 220) == 1)
			{
				settextstyle(SMALL_FONT, HORIZ_DIR, 6);
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260, 190, 260 + 315, 220, RED, LIGHTGRAY, 1);
				u->user[0]='\0';
				
				inputadmin(u->user, 260, 190, 12, LIGHTGRAY);
				if(strlen(u->user)!=0)
					judge1=1;
				else
					judge1=0;
				continue;
		    }
		}
		
		//输入密码
		if(MouseX>260 && MouseX<260+315 &&MouseY>250 &&MouseY<280)
		{
			if (mouse_press(260, 250, 260 + 315, 280) == 1)
			{
				settextstyle(SMALL_FONT, HORIZ_DIR, 6);
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260, 250, 260 + 315, 280, RED, LIGHTGRAY, 1);
				u->password[0]='\0';
				inputpassword(u->password, 260, 250, 12, LIGHTGRAY);
				if(strlen(u->password)!=0)
					judge2=1;
				else
					judge2=0;
				continue;
		    }
		}

		//游客登录
		if(MouseX>340 && MouseX<570 && MouseY >310 && MouseY<345)
		{
			if(mouse_press(340, 310, 570, 345)==2)
			{
				MouseS=1;
				continue;
			}

			else if(mouse_press(340, 310, 570, 345)==1)
			{
				clrmous(MouseX,MouseY);
				cleardevice();
				*func = 3;
				*judge = 2;
				return;
			}
		}
		
		if(MouseX>260 && MouseX<260+315 && MouseY >250 && MouseY<280)
		{
			if(mouse_press(260, 250, 260 + 315, 280)==2)
			{
				MouseS=2;
				continue;
			}		
		}
		
		if(MouseX>290 && MouseX<350 && MouseY >380 && MouseY<405)
		{
			if(mouse_press(290, 380, 350, 405)==2)
			{
				MouseS=1;

				continue;
			}			
			
			//注册
			else if(mouse_press(290, 380, 350, 405) == 1)
			{
				cleardevice();
				MouseS=0;
				*func=1;
				return;			
			}
		}

		if(MouseX>100 && MouseX<380 && MouseY >169 && MouseY<405)
		{
			if(mouse_press(100, 380, 169, 405)==2)
			{
				MouseS=1;
				continue;
			}

			//退出
	    	else if(mouse_press(100, 380, 169, 405) == 1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Popup_Func(3);
			}			
		}

		if(MouseX>480 && MouseX<570 && MouseY >380 && MouseY<405)
		{
			if(mouse_press(480, 380, 570, 405)==2)
			{
				MouseS=1;
				continue;
			}
			//忘记密码
		 	else if(mouse_press(480, 380, 570, 405) == 1)
			{
				MouseS=0;
				*func=2;
				return;
			}	
		}

		if(MouseX>260 && MouseX<260+315 && MouseY >190 && MouseY<220)
		{
			if(mouse_press(260, 190, 260 + 315, 220)==2)
			{
				MouseS=2;
				continue;
			}
		}

		if(MouseX>140 && MouseX<315 && MouseY >310 && MouseY<345)
		{
			if(mouse_press(140, 310, 315, 345)==2)
			{
				MouseS=1;
				continue;
			}

			//登录
		 	else if(mouse_press(140, 310, 315, 345) == 1)
			{
				if(login_complete(u->user, u->password))
				{
					MouseS=0;
					Copy_infor_User(u);
					clrmous(MouseX,MouseY);
					cleardevice();
					*judge = 1;
					*func=3;
					return;
				}
				else
				{
					*func=0;
					return;
				}
			}
		}
		
		if(MouseS!=0)
		{
			MouseS=0;
			continue;
		}
	}
}
/*************************************************************
函数名：draw_login() 
参数：无
返回值：无
函数功能：登录界面的绘制
**************************************************************/	
void draw_login()
//绘制登录界面
{
    	
	//画背景
	setbkcolor(GREEN);
    setcolor(YELLOW);
    puthz(230, 130, "思维导图", 48, 50, BLUE);
	
	//画文本框
    setfillstyle(SOLID_FILL,RED);
	setfillstyle(SOLID_FILL, WHITE);
	
	//用户名
	bar(140, 190, 260, 220);
	bar(260, 190, 260 + 315, 220);

	//密码
	bar(140, 250, 260, 280);
	bar(260, 250, 260 + 315, 280);	

    //画登录小人
	sector(320, 100, 230, 310, 35, 35);
	fillellipse(320, 100 - 5, 15, 15);
	setcolor(RED);
	circle(320, 100-5, 15);	
	
	//第二个登录小人
	setfillstyle(1, RED);
	sector(102, 203, 230, 310, 15, 15);
	fillellipse(102, 203 - 2, 7, 7);
	setcolor(RED);
	circle(102, 203 - 2, 7);
	
	//画锁
	setcolor(BROWN);
	rectangle(89, 260, 115, 275);
	arc(102, 260, 0, 180, 7);
	circle(102, 267, 4);
	//边框
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	line(260, 190, 260, 220);
	line(260, 250, 260, 280);	
	rectangle(140, 190, 260 + 315, 220);
	rectangle(140, 250, 260 + 315, 280);	

	puthz(153, 193, "用户名", 24, 34, LIGHTRED);
	puthz(163, 253, "密码", 24, 50, LIGHTRED);

	setfillstyle(SOLID_FILL, RED);
	bar(140, 310, 315, 345);
	puthz(180, 315, "登录", 24, 70, WHITE);

	setfillstyle(SOLID_FILL, RED);
	bar(340, 310, 570, 345);
	puthz(385, 315, "游客登陆", 24, 40, WHITE);
	
	//注册和返回
	setlinestyle(SOLID_LINE, 0, 1);
	setfillstyle(SOLID_FILL, WHITE);
	bar(290, 380, 350, 405);
	puthz(302, 385, "注册", 16, 24, LIGHTRED);
	setlinestyle(SOLID_LINE, 0, 2);
	setcolor(LIGHTRED);
	rectangle(290, 380, 350, 405);

	bar(100, 380, 169, 405);
	puthz(114, 385, "退出", 16, 24, LIGHTRED);
	rectangle(100, 380, 169, 405);

	bar(480, 380, 570, 405);
	puthz(492, 385, "忘记密码", 16, 18, LIGHTRED);
	rectangle(480, 380, 570, 405);
}

/*************************************************************
函数名：login(char* name, char*password)
参数：储存用户名的数组地址*name,储存密码的数组地址*password
返回值：无
函数功能：判断用户名与密码是否匹配
**************************************************************/	
int login(char* name, char*password)
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	if ((fp = fopen(".\\USERS\\userdata.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(name, u->user) == 0)
		//用户名匹配
		{
			if (strcmp(password, u->password) != 0)
			//密码不配
			{
				puthz(450, 290, "密码错误", 16, 17, RED);
				delay(1000);
				cover_tips(450,290,GREEN);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(password, u->password) == 0)
			//密码匹配
			{
				puthz(290, 355, "登录成功", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				delay(1000);
				if (fclose(fp) != 0)
				{
					printf("\n cannot close Database");
					delay(3000);
					exit(1);
				}
				return 1;
				//切换界面
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{
		puthz(450, 170, "账户未注册", 16, 17, RED);
		delay(1000);
		cover_tips(450,170,GREEN);
		//走到最后一位
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		delay(3000);
		exit(1);
	}
	return 0;
}
/*************************************************************
函数名：login_complete(char* u, char* p)
参数：储存用户名的数组地址*u,储存密码的数组地址*p
返回值：1:是 2：否
函数功能：用来判断登录信息是否输入完全和正确
**************************************************************/	
int login_complete(char* u, char* p)
{
	int state1 = 1;//是否输入的变量
	int state2 = 1;
	while (1)
	{
		
		panduan(u, &state1, 450, 170,BLACK);
		
		panduan(p, &state2, 450, 290,BLACK);
		delay(1000);
		cover_tips(450,170,GREEN);
		cover_tips(450,290,GREEN);
		if (state1 == 1 || state2 == 1)
		{
			break;
		}
		else if (state1 == 0 && state2 == 0)
		{
			if (login(u, p))
			{

				return 1;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}


