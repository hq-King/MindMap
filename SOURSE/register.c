#include"common.h"
#include"register.h"
#include"USER.h"
#include "func.h"
#include "file.h"
/*************************************************************
函数名：zhuce_func(int *func)
参数：界面参数地址*func
返回值：无
函数功能：注册界面功能选择
**************************************************************/	
void zhuce_func(int *func)
{		

    int light=0; 
	//输入用户名
	char name [15] = {'\0'};
	
	//输入密码
	char password1 [15] = {'\0'};
	
	//再次输入密码
	char pass [15] = {'\0'};
		
	//输入电话号码
	char tel [15] = {'\0'};

	
	//判断
	int jud1=0;
	int jud2=0;
	int jud3=0;
	int jud4=0;

	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
    draw_zhuce();
	while(1)
	{	
		
		
		newmouse(&MouseX, &MouseY, &press);
		
		//输入用户名
			
		if(MouseX>260 && MouseX<540 &&MouseY>140 && MouseY<160)
		{	
		 	if (mouse_press(260, 140, 260 + 280, 160) == 2)           
		 	//未点击账号框
			{
				MouseS = 2;
				if (light == 0 && jud1 == 0)                  
				//light = 0防止重复标亮
				{
					lightbutton_register(260, 140, 260 + 280, 160, RED, LIGHTGRAY, 1);
					light = 1;
				}
				continue;
			}
			else if(mouse_press(260, 140, 260 + 280, 160)==1)
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260, 140, 260 + 280, 160, RED, LIGHTGRAY, 1);
				name[0]='\0';
				inputadmin(name, 260, 140, 12, LIGHTGRAY);
				if(strlen(name)!=0)
					jud1=1;
				else
					jud1=0;
				continue;
			}		
		}
		//输入密码
		if(MouseX>260 && MouseX<540 &&MouseY>180 && MouseY<200)
		{	
		 	if (mouse_press(260,180,540,200) == 2)           
		 	//未点击密码框
			{
				MouseS = 2;
				if (light == 0 && jud2 == 0)                  
				//light = 0防止重复标亮
				{
					lightbutton_register(260,180,540,200, RED, LIGHTGRAY, 1);
					light = 2;
				}
				continue;
			}
			else if(mouse_press(260,180,540,200)==1)	
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260,180,540,200, RED, LIGHTGRAY, 1);
				password1[0]='\0';
				inputpassword(password1, 260, 180, 12, LIGHTGRAY);
				if(strlen(password1)!=0)
					jud2=1;
				else
					jud2=0;
				continue;
			}
		}
		//再次输入密码
		if(MouseX>260 && MouseX<540 &&MouseY>220 && MouseY<240)
		{	
		 	if (mouse_press(260, 220, 260 + 280, 240) == 2)          
		 	 //未点击密码框
			{
				MouseS = 2;
				if (light == 0 && jud3 == 0)                  
				//light = 0防止重复标亮
				{
					lightbutton_register(260,220,540,240, RED, LIGHTGRAY, 1);
					light = 3;
				}
				continue;
			}
			else if(mouse_press(260,220,540,240)==1)			
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260,220,540,240, RED, LIGHTGRAY, 1);
				pass[0]='\0';
				inputpassword(pass, 260, 220, 12, LIGHTGRAY);
				if(strlen(pass)!=0)
					jud3=1;
				else
					jud3=0;
				continue;
			}	
		}
		//输入电话号码
		if(MouseX>260 && MouseX<540 &&MouseY>260 && MouseY<280)
		{	
		 	if (mouse_press(260,260,540,280) == 2)           
		 	//未点击电话号码框
			{
				MouseS = 2;
				if (light == 0 && jud4 == 0)                  
				//light = 0防止重复标亮
				{
					lightbutton_register(260,260,540,280, RED, LIGHTGRAY, 1);
					light = 4;
				}
				continue;
			}
			else if(mouse_press(260,260,540,280)==1)	
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260,260,540,280, RED, LIGHTGRAY, 1);
				tel[0]='\0';
				inputadmin(tel, 260, 260, 18, LIGHTGRAY);
				if(strlen(tel)!=0)
					jud4=1;
				else
					jud4=0;
				continue;
			}	
		}
		
	
		if(MouseX>140 && MouseX<330&&MouseY>340 && MouseY<380)
		{
			if(mouse_press(140, 340, 330, 380) == 1)
			//确定按钮
			{
				MouseS=0;
				if(check(name,tel,password1,pass))
				{
					createfolder(name);
					clrmous(MouseX,MouseY);
					cleardevice();
					*func=0;
					return;

				}
				else 
				continue;
			}
		}


		if (MouseX > 140 && MouseX < 540 && MouseY>295 && MouseY < 330)
		{
			if (mouse_press(140, 295, 260 + 280,330) == 1)
			{
				MouseS = 0;
				clrmous(MouseX,MouseY);
				cleardevice();
				*func=1;
				return;
			}	
		}

		//返回
		if(mouse_press(350, 340, 540, 380) == 1)
		{
			clrmous(MouseX,MouseY);
			cleardevice();
			*func=0;
			return;
		}

		if (light != 0)
		{
			MouseS = 0;
			if (jud1 == 0)
			{
				recoverbutton_register(1);
			}
			if (jud2 == 0)
			{
				recoverbutton_register(2);
			}
			if (jud3 == 0)
			{
				recoverbutton_register(3);
			}
			if (jud4 == 0)
			{
				recoverbutton_register(4);
			}		
			light = 0;
		}

		if (MouseS != 0)
		{
			MouseS = 0;
		}		
	}
}
/*************************************************************
函数名：draw_zhuce()
参数：无
返回值：无
函数功能：绘制注册界面
**************************************************************/	
void draw_zhuce()
//绘制注册界面
{
	setbkcolor(CYAN);

	//画登陆小人
	sector(320, 30, 230, 310, 35, 35);
	fillellipse(320, 25, 15, 15);
	setcolor(RED);
	circle(320, 25, 15);	
	puthz(220, 80, "思维导图", 48, 55, YELLOW);
	
	//用户名
	setfillstyle(SOLID_FILL, WHITE);
	bar(140, 140, 260, 160);
	bar(260, 140, 260 + 280, 160);
	
	//密码	
    bar(140, 180, 260,200);
	bar(260, 180, 260 + 280, 200);	
	
	//确认密码
	bar(140, 220, 260,240);
	bar(260, 220, 260 + 280, 240);
	
    //电话号码
	bar(140, 260, 260,280);
	bar(260, 260, 260 + 280, 280);
	
	
	//确定,返回和重置
	setfillstyle(SOLID_FILL,RED);
	bar(140, 340, 330, 380);
	bar(350, 340, 540, 380);
	bar(140, 295, 260 + 280,330);
	//边框
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	line(260, 140, 260, 160);
	line(260, 180, 260, 200);	
	rectangle(140, 140, 260 + 280, 160);
	rectangle(140, 180, 260 + 280, 200);
	line(260, 220, 260, 240);	
	rectangle(140, 220, 260 + 280,240);
	line(260, 260, 260, 280);	
	rectangle(140, 260, 260 + 280,280);	
		
	rectangle(140, 295, 260 + 280,330);	
		
	

	puthz(148, 183, "密码", 16, 80, LIGHTRED);
	puthz(148, 143, "用户名", 16, 34, LIGHTRED);
	puthz(148, 223, "确认密码", 16, 30, LIGHTRED);
	puthz(148, 263, "电话号码", 16, 30, LIGHTRED);
	puthz(200,298,"清空输入",32,80,YELLOW);
	
	puthz(180, 343, "确定", 32, 88, YELLOW);
	puthz(380, 343, "返回", 32, 88, YELLOW);
	
}

/*************************************************************
函数名：check(char *name,char *tel,char *password1,char * password2)
参数：储存用户名的数组地址*name,储存电话号码的数组地址*tel,储存密码的数组地址*password1,储存确认密码的数组地址*password2
返回值：1:是 0:否
函数功能：判断注册账号时所填信息是否符合格式
**************************************************************/	
int check(char *name,char *tel,char *password1,char * password2)
{
	int q=0;
	
	int std1=1;
	//判断用户名是否输入正确的格式
	int std2=1;
	//判断密码是否输入正确的格式
	int std3=1;
	//判断密码是否一致
	int std4=1;
	//判断电话号码是否输入正确的格式
	

	while(1)
	{
		cover(545,140,CYAN);
		cover(545,180,CYAN);
		cover(545,220,CYAN);
		cover(545,260,CYAN);
		panduan(name,&q,545,140,CYAN);
		panduan(password1,&q,545,180,CYAN);
		panduan(password2,&q,545,220,CYAN);
		panduan(tel,&q,545,260,CYAN);
		
		if(q==1)
		{
			break;
		}
		else if(q==0)
		{
			if(!Search_S_user(name,1))
			//判断是否重名,重名返回0，否则返回 1
			{
				std1=judge_name(name,545,140);
				std2=judge_password(password1,545,180);
				std3=judge_ispasswordsame(password1,password2,545,220);
				std4=judge_tel(tel,545,260,1);
				break;


			}

			else if(Search_S_user(name,1))
			//没有重名
			{
				puthz(530,100, "可用的用户名", 16, 17, RED);
				std1=judge_name(name,545,140);
				std2=judge_password(password1,545,180);
				std3=judge_ispasswordsame(password2,password1,545,220);
				std4=judge_tel(tel,545,260,1);
				if (std1 != 0 || std2 != 0 || std3 != 0 || std4 != 0 )
				{
					break;
				}
				else if (std1 == 0 && std2 == 0 && std3 == 0 && std4 == 0 )
				{
					inputtofile(name,tel,password1);
					//写入数据库
					puthz(280,420, "注册成功", 16, 17, RED);
					delay(2000);				
					return 1;
					//返回
				}

			}

		}
    }
	return 0;
}