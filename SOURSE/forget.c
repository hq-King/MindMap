#include"common.h"
#include"forget.h"
#include"USER.h"

/*************************************************************
函数名：forget_func(int *func)
参数：界面参数的地址*func
返回值：无
函数功能：找回密码界面的所有功能的调用
**************************************************************/	
void forget_func(int *func)
{	
	int light = 0;
	//输入用户名
	char name [15] = {'\0'};
		
	//输入手机号码
	char tel [15] = {'\0'};
	
	//输入新密码
	char password [15] = {'\0'};
	int jud1=0;
	int jud2=0;
	int jud3=0;


	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	draw_forget();
	
	while(1)
	{	
		newmouse(&MouseX, &MouseY, &press);
		
		//输入用户名			
		if(MouseX>260 && MouseX<540 &&MouseY>180 && MouseY<200)
		{	
		 	if (mouse_press(260, 180, 260 + 280, 200) == 2)           
		 	//未点击账号框
			{
				MouseS = 2;
				if (light == 0 && jud1 == 0)                  
				//light = 0防止重复标亮
				{
					lightbutton_register(260, 180, 260 + 280, 200, RED, LIGHTGRAY, 1);
					light = 1;
				}
				continue;
			}
			else if(mouse_press(260, 180, 260 + 280, 200)==1)
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260, 180, 260 + 280, 200, RED, LIGHTGRAY, 1);
				name[0]='\0';
				inputadmin(name, 260, 180, 12, LIGHTGRAY);
				if(strlen(name)!=0)
					jud1=1;
				else
					jud1=0;
				continue;
			}	
		}

		//输入电话号码
		if(MouseX>260 && MouseX<540 &&MouseY>220 && MouseY<240)
		{	
		 if (mouse_press(260,220,540,240) == 2)           
		 //未点击电话号码框
			{
				MouseS = 2;
				if (light == 0 && jud2 == 0)                  
				//light = 0防止重复标亮
				{
					lightbutton_register(260,220,540,240, RED, LIGHTGRAY, 1);
					light = 4;
				}
				continue;
			}
			else if(mouse_press(260,220,540,240)==1)
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260,220,540,240, RED, LIGHTGRAY, 1);
				tel[0]='\0';
				inputadmin(tel, 260, 220, 12, LIGHTGRAY);
				if(strlen(tel)!=0)
					jud2=1;
				else
					jud2=0;
				continue;
			}	
		}
		
		//输入新密码		
		if(MouseX>260 && MouseX<540 &&MouseY>260 && MouseY<280)
		{	
		 if (mouse_press(260, 260, 540, 280) == 2)           
		 //未点击密码框
			{
				MouseS = 2;
				if (light == 0 && jud3 == 0)                  
				//light = 0防止重复标亮
				{
					lightbutton_register(260,260,540,280, RED, LIGHTGRAY, 1);
					light = 2;
				}
				continue;
			}
			else if(mouse_press(260,260,540,280)==1)	
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				lightbutton_register(260,260,540,280, RED, LIGHTGRAY, 1);
				password[0]='\0';
				inputpassword(password, 260, 260, 12, LIGHTGRAY);
				if(strlen(password)!=0)
					jud3=1;
				else
					jud3=0;
				continue;
			}			
		}
		
		if (light != 0)
		{
			MouseS = 0;
			if (jud1 == 0)
			{	setfillstyle(1, WHITE);
				bar(260, 180, 540,200);
				rectangle(260, 180, 540,200);
			}
			if (jud2 == 0)
			{
				setfillstyle(1, WHITE);
				bar(260, 220, 540,240);
				rectangle(260, 220, 540,240);
			}
			if (jud3 == 0)
			{
				setfillstyle(1, WHITE);
				bar(260, 260, 540, 280);
				rectangle(260, 260, 540, 280);
			}			
			light = 0;
		}

		if (MouseS != 0)
		{
			MouseS = 0;
		}
		
		//确定
		if(MouseX>140 && MouseX<300&&MouseY>290 && MouseY<330)
		{
			if(mouse_press(140, 290, 300, 330) == 1)
				//确定按钮
			{
				if(forgetpass_match(name,tel,password))
				{
					MouseS=0;
					clrmous(MouseX,MouseY);
					cleardevice();
					*func=0;
					return ;

				}
				else
				{
					*func=2;
				}
			}
		}
			
		//返回
		if(MouseX>380 && MouseX<540 && MouseY>290 && MouseY<330)
		{	
			if(mouse_press(380, 290, 540, 330) == 1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				cleardevice();
				*func=0;
				return;
			}
		}
	}

}
/*************************************************************
函数名：draw_forget()
参数：无
返回值：无
函数功能：绘制找回密码界面
**************************************************************/	
void draw_forget()
{
    //设置背景色
	setbkcolor(CYAN);
	
	//设置文本框颜色
	setfillstyle(SOLID_FILL,RED);
	setfillstyle(SOLID_FILL, WHITE);
	
	//用户名
	bar(140, 180, 260,200);
	bar(260, 180, 260 + 280, 200);
	
	//电话号码
	bar(140, 220, 260,240);
	bar(260, 220, 260 + 280, 240);
	
	//新密码
	bar(140, 260, 260, 280);
	bar(260, 260, 260 + 280, 280);
	
	//设置按钮颜色
	setfillstyle(SOLID_FILL,RED);
	
	//确定
	bar(140, 290, 300, 330);
	
	//返回
	bar(380, 290, 540, 330);


	//画登陆小人
	setcolor(CYAN);
	sector(320, 80, 230, 310, 35, 35);
	fillellipse(320, 75, 15, 15);
	setcolor(GREEN);
	circle(320, 75, 15);	
	puthz(220, 115, "思维导图", 48, 55, YELLOW);
	
	//设置边框颜色和线性
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	
	//边框
	line(260, 180, 260, 200);	
	rectangle(140, 180, 260 + 280, 200);
	line(260, 220, 260, 240);	
	rectangle(140, 220, 260 + 280, 240);
	line(260, 260, 260, 280);
	rectangle(140, 260, 260 + 280, 280);
	
	//文字
	puthz(160, 293, "确定", 24, 88, YELLOW);
	puthz(400, 298, "返回", 24, 88, YELLOW);
	puthz(148, 183, "用户名", 16, 34, LIGHTRED);
	puthz(148, 223, "电话号码", 16, 30, LIGHTRED);
	puthz(148, 263, "新密码", 16, 34, LIGHTRED);
}

/*************************************************************
函数名：name_id(char* name, char* tel, char* password)
参数：账号数组的地址*name,电话号码数组的地址*tel,密码数组的地址*password
返回值：1:匹配 0:不匹配
函数功能：判断账号与身份证是否匹配 判断两次输入的密码是否相同 若匹配且相同则写入新密码
**************************************************************/	
int name_id(char* name, char* tel, char* password)
{
	int str;
	int len;
	int i,j;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen(".\\USERS\\userdata.dat", "rb+" )) == NULL)
	{
		printf("cannot open file UserDat.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//文件指针定位到最后一位
	len = ftell(fp) / sizeof(USER);//计算用户个数
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//每次往后移一个用户
		fread(u, sizeof(USER), 1, fp);//将信息读入u
		if (strcmp(name, u->user) == 0)
		{

			if (strcmp(tel, u->tel) == 0)
			{
				setcolor(RED);
				setlinestyle(SOLID_LINE, 0, 3);
				line(550, 228, 560, 238);
				line(560, 238, 570, 218);
				u->password[0] = '\0';
					strcpy(u->password, password);
					fseek(fp, i * sizeof(USER), SEEK_SET);
					fwrite(u, sizeof(USER), 1, fp);
					//修改完后一定要记得写入数据
					puthz(300, 480 - 10 - 60, "密码修改成功", 16, 17, RED);
					if (u != NULL)
					{
						free(u);
						u = NULL;
					}
					if (fclose(fp) != 0)
					{
						printf("\n cannot close Database");
						exit(1);
					}
					delay(2000);
					return 1;
				}
		}
	}
	if(i>=len)
	{
		puthz(50,50,"密码修改失败",24,30,RED);
		delay(1500);
		
		setfillstyle(SOLID_FILL,CYAN);
		bar(50, 50, 230, 50 + 25);

	}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		exit(1);
	}
	return 0;
}

/*************************************************************
函数名：forgetpass_match(char* u, char* tel, char* password)
参数：用户名地址*u,电话号码数组的地址*tel,密码数组的地址*password
返回值：1:可以 0:不可以
函数功能：判断是否可以更改新密码
**************************************************************/	
int forgetpass_match(char* u, char* tel, char* password)
{
	int st1 = 1;//用户名是否输入的变量
	int st2 = 1;//是否输入的变量
	int st3 = 1;//新密码是否输入的变量

	int state1 = 1;//输入格式是否正确的变量
	int state2 = 1;//密码输入格式是否正确的变量
	
	while (1)
	{
		cover(95 + 452, 138, CYAN);//遮盖汉字
		cover(95 + 452, 218,  CYAN);
		cover(95 + 452, 298,  CYAN);
		panduan(u, &st1, 95 + 452, 183,CYAN); //判断是否输入,未输入会=1
		panduan(tel, &st2, 95 + 452, 220,CYAN);
		panduan(password, &st3, 95 + 452, 263,CYAN);
		
	
		if (st1 == 1 || st2 == 1 || st3 == 1 )
		{
			break;
		}
		else if (st1 == 0 && st2 == 0 && st3 == 0 )
		{
			if (Search_S_user(u,2))//用户名不存在
			{
				puthz(95 + 450, 140, "用户不存在", 16, 17, RED);
				delay(1500);
				cover_tips(95 + 450, 140,CYAN);
				state1 = judge_name(u, 95 + 452, 220 );//判断各项格式是否正确

				state2 = judge_password(password, 95 + 452, 300);
				delay(1500);
				cover_tips(95 + 452, 220,CYAN);
				cover_tips(95 + 452, 300,CYAN);
				
				break;
			}
			else if (!Search_S_user(u,2))//用户名存在
			{
				state1 = judge_name(u, 95 + 452, 180);
				state2 = judge_tel(tel, 95 + 452, 220,1);
				delay(1000);
				cover_tips(95 + 452, 220,CYAN);
				cover_tips(95 + 452, 300,CYAN);
				
				if (state1 != 0 || state2 != 0 )
				{
					break;
				}	
				else if (state1 == 0 && state2 == 0 )
				{
					if (name_id(u,tel,password))//写入数据库
					{
						return 1;//返回登录界面
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	return 0;
}


