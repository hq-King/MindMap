#include"common.h"
#include"func.h"
#include"USER.h"
/*************************************************************
函数名：inputadmin(char* id, int x1, int y1, int charnum, int color)
参数：存储输入账号的数组地址*id,输入框左上角的坐标xy,最多字符数charnum,输入框的颜色color 
返回值：无
函数功能：输入账号框功能
**************************************************************/	
void inputadmin(char* id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(RED);
	settextstyle(SMALL_FONT, HORIZ_DIR, 4);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 16);
	//光标
	while(bioskey(1))
	{
		k = bioskey(0);
		//按键
	}
	while (1)
	{
	
		t = bioskey(0); 
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)
				//Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 16); 
					//遮盖光标
					outtextxy(x1 + 8 + i * 18, y1+5, id + i);
					//输出t字符(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 16);
				}
				else if (t == '\b' && i > 0)
				//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 16);
					//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 16);
					//遮盖文字
					i--;//减少一个字符?
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 16);
					//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 16);
				//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)
				//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 16);
					//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 16);
					//遮盖文字
					i--;
					//减少一个字符
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 16);
					//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 16);//遮盖光标  
				break;
			}
		}
	}
}

/*************************************************************
函数名：inputpassword(char* id, int x1, int y1, int charnum, int color)
参数：存储输入密码的数组地址*id,输入框左上角的坐标xy,最多字符数charnum,输入框的颜色color 
返回值：无
函数功能：输入密码框功能
**************************************************************/
void inputpassword(char* id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 4, x1 + 10, y1 + 15);
	while(bioskey(1))
	{
		k = bioskey(0);
		//吃
	}
	while (1)
	{
		t = bioskey(0);
		//读取键值
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)
				//033表示Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 17);
					//遮盖光标
					outtextxy(x1 + 8 + i * 18, y1 + 3, "*");
					//输出*字符
					i++;
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 17);
				}
				else if (t == '\b' && i > 0)
				//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 17);
					//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 17);
					//遮盖文字
					i--;
					//减少一个字数
					line(x1 + 10 + i * 18, y1 + 4, x1 + 10 + i * 18, y1 + 17);
					//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 17);
				//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)
				//Esc
			{
				if (t == '\b' && i > 0)
				//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 17);
					//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 17);
					//遮盖文字
					i--;
					//减少一个字数
					line(x1 + 10 + i * 18, y1 + 2, x1 + 10 + i * 18, y1 + 14);
					//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 17);
				//遮盖光标
				break;
			}
		}
	}
}

/*************************************************************
函数名：panduan(char* s, int* jud, int x, int y,int color)
参数：存储输入的数组地址*s,判断是否输入的标志地址*jud,输入框左上角的坐标xy,输入框的颜色color 
返回值：无
函数功能：判断是否输入
**************************************************************/
void panduan(char* s, int* jud, int x, int y,int color)
{
	if (strlen(s) == 0)
	{
		*jud = 1;
		puthz(x, y, "未输入", 16, 17, RED);
		delay(1000);
		cover_tips(x,y,color);
	}
	else
	{
		*jud= 0;
	}


}
/*************************************************************
函数名：Search_S_user(char * new,int z)
参数：存储输入账号的数组地址*new,显示 是否注册 还是显示 是否存在 的标志z
返回值：1:否 0:是
函数功能：判断是否重复
**************************************************************/
int Search_S_user(char * new,int z)
{
	int i;
	int len;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen(".\\USERS\\userdata.dat", "rb+")) == NULL)
	//建立数据库
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
		if (strcmp(u->user, new) == 0)
		{
			switch (z)
			{
			case 1: 
				puthz(135, 60, "用户已被注册", 16, 17, RED);
				break;
			case 2:
				puthz(450, 110, "账号存在", 16, 17, RED);
				break;
			default:
				printf("something wrong");
				delay(3000);
				exit(1);
			}
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close Database.");
				delay(3000);
				exit(1);
			}
			return 0;
		}
		free(u);
		u = NULL;
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	return 1;


}
/*************************************************************
函数名：judge_name(char* s, int x, int y)
参数：存储输入账号的数组地址*s,显示 名称应 的坐标xy
返回值：1:否 0:是
函数功能：判断用户名是否大于6位且小于12位
**************************************************************/
int judge_name(char* s, int x, int y)
{
	if (strlen(s) < 6 
	/*小于6位*/)
	{
		puthz(x, y, "名称应", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">6");
		return 1;
	}
	else if(strlen(s)>=6&&strlen(s)<=12)
	{
		setcolor(RED);
		setlinestyle(SOLID_LINE, 0, 3);		
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;

}

/*************************************************************
函数名：judge_password(char* s, int x, int y)
参数：存储输入密码的数组地址*s,显示 密码应 的坐标xy
返回值：1:否 0:是
函数功能：判断密码是否大于6位小于12位
**************************************************************/
int judge_password(char* s, int x, int y)
{

	if (strlen(s) < 6
	/*小于6位*/)
	{
		puthz(x, y, "密码应", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">=6");
		return 1;
	}
	else if(strlen(s)>=6&&strlen(s)<=12)
	{
		setcolor(RED);
		setlinestyle(SOLID_LINE, 0, 3);		
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*************************************************************
函数名：judge_ispasswordsame(char* s1, char* s2, int x, int y)
参数：存储输入密码的数组地址*s1*s2,显示 两次不一致 的坐标xy
返回值：1:否 0:是
函数功能：判断密码是否大于6位小于12位
**************************************************************/
int judge_ispasswordsame(char* s1, char* s2, int x, int y)
{
	if (strcmp(s1, s2) != 0)
	{
		puthz(x, y, "两次不一致", 16, 17, RED);
		return 1;
	}
	else if (strcmp(s1, s2) == 0)
	{
		setcolor(RED);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 0;
}

/*************************************************************
函数名： judge_tel(char* s, int x, int y,int z)
参数：存储输入电话号码的数组地址*s1,显示 应为 或 格式不正确 的坐标xy,是否打印对号的标志z
返回值：1:否 0:是
函数功能：判断电话号码是否符合格式
**************************************************************/
int judge_tel(char* s, int x, int y,int z)
{
	int i=0;
	int state = 1;
	if (strlen(s) != 11)
	{
		puthz(x, y, "应为", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x+50, y-5, "11");
		puthz(x + 73, y, "位", 16, 17, RED);
		//长度不符合
		return 1;
	}
	else if (strlen(s) == 11)
	{
		for (i = 0; i < 10; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				continue;
			}
			else
			{
				puthz(x, y, "格式不正确", 16, 17, RED);
				return 0;
			}
			
		}
		if (s[10] == 'X' || (s[10]>='0' && s[10]<='9'))
		{
			state = 0;
			//判断最后一位是否为数字和X
		}
		else
		{
			puthz(x, y, "格式不正确", 16, 17, RED);
			return 1;
		}
	}
	if (state == 0)
	{
		switch (z)
		{
		case 1:
			setcolor(RED);
			setlinestyle(SOLID_LINE, 0, 3);
			line(x + 3, y + 8, x + 13, y + 18);
			line(x + 13, y + 18, x + 23, y - 2);
			break;
		case 2:
			break;
		}
		return 0;
	}
	return 1;
}

