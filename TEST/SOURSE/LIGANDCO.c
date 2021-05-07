#include "common.h"
#include "LIGANDCO.h"

/*************************************************************
函数名：void lightbutton_register(int x, int y, int x1, int y1, int color1, int color2, int flag)
参数：坐标信息,颜色
返回值：无
函数功能：点亮文本框
**************************************************************/

void lightbutton_register(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	
	//画边框
}

/*************************************************************
函数名：void recoverbutton_register(int status)
参数：参数
返回值：无
函数功能：恢复文本框
**************************************************************/

void recoverbutton_register(int status)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
	switch (status)
	{
	case 1:
		bar(260, 140, 260 + 280, 160);
		rectangle(260, 140, 260 + 280, 160);
		break;
	case 2:
		bar(260,180,540,200);
		rectangle(260,180,540,200);	
		break;
	case 3:
		bar(260,220,540,240);
	    rectangle(260, 220, 260 + 280,240);	
		break;
	case 4:
		bar(260,260,540,280);	
	    rectangle(260, 260, 260 + 280,280);	
		break;
	case 6:
		setfillstyle(1, RED);
		bar(140, 295, 260 + 280,330);
		puthz(200,298,"清空输入",32,80, YELLOW);
		break;
	case 7:
		setfillstyle(1, RED);
		bar(273, 370, 367, 400);
		puthz(291, 373, "注册", 24, 34, WHITE);
		break;
	case 8:
		setfillstyle(1, BLUE);
		bar(403, 370, 497, 400);
		puthz(421, 373, "返回", 24, 34, WHITE);
		break;
	}
}


/*************************************************************
函数名：void light_login(int x, int y, int x1, int y1, int color1, int color2, int flag)
参数：坐标信息,颜色
返回值：无
函数功能：点亮文本框
**************************************************************/
void light_login(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{

	case 1:
		puthz(180, 315, "登录", 24, 70, RED);
		break;
	case 2:
		puthz(385, 315, "游客登陆", 24, 40, BLUE);
		break;
	case 3:
		puthz(302, 385, "注册", 16, 24, BLUE);
		break;
	case 4:
		puthz(492, 385, "忘记密码", 16, 18, BLUE);
		break;
	case 5:
		puthz(114, 385, "退出", 16, 24, BLUE);

	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}




/*************************************************************
函数名：void lightbutton_tc(int x, int y, int x1, int y1, int color, int flag)
参数：坐标信息,颜色
返回值：无
函数功能：点亮弹窗
**************************************************************/
void lightbutton_tc(int x, int y, int x1, int y1, int color, int flag)

{
	clrmous(MouseX, MouseY);
	delay(10);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color);
	
	switch (flag)
	{
	case 1:
		bar(297,275,343,295);
		rectangle(297,275,343,295);	//画边框
	    puthz(302, 277, "确定", 16, 20, 4);
		break;
	case 2:
		puthz(223, 277, "确定", 16, 20, 4);
		puthz(383, 277, "取消", 16, 20, 4);
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}


/*************************************************************
函数名：void recoverbutton_tc(void)
参数：无
返回值：无
函数功能：恢复弹窗
**************************************************************/
void recoverbutton_tc(void)
{
    clrmous(MouseX, MouseY);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    setfillstyle(SOLID_FILL, WHITE);
    bar(297, 275, 343, 295);
    rectangle(297, 275, 343, 295);
    puthz(302, 277, "确定",16, 20, 4);
}


/*************************************************************
函数名：void lightButton_Save(int n)
参数：判断参数
返回值：无
函数功能：点亮保存界面
**************************************************************/
void lightButton_Save(int n)
{
	clrmous(MouseX,MouseY);
	delay(10);
	switch(n)
	{
		case 1:
			setcolor(YELLOW);
			setlinestyle(SOLID_LINE,0,THICK_WIDTH);
			rectangle(190+1, 405+1, 190+80-1, 405+25-1);
			break;
			
		case 2:
			setcolor(YELLOW);
			setlinestyle(SOLID_LINE,0,THICK_WIDTH);
			rectangle(370+1, 405+1, 370+80-1, 405+25-1);
			break;
			
		case 3:
			setcolor(YELLOW);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			setfillstyle(1,LIGHTGRAY);
			bar(360,335,555,335+30);
			rectangle(360,335,555,335+30);
			break;
	}
}

/*************************************************************
函数名：void recoverbutton_save(int n)
参数：按钮编号
返回值：无
函数功能：保存界面按钮高亮恢复
**************************************************************/
void RecoverButton_Save(int n)
{
	clrmous(MouseX,MouseY);
	delay(10);
	switch(n)
	{
		case 1:
			setfillstyle(1,GREEN);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			setcolor(LIGHTGRAY);
			bar(190, 405, 190+80, 405+25);
			rectangle(190, 405, 190+80, 405+25);
			puthz(209,410,"确认",16,28,WHITE);
			break;
			
		case 2:
			setfillstyle(1,GREEN);
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			setcolor(LIGHTGRAY);
			bar(370, 405, 370+80, 405+25);
			rectangle(370, 405, 370+80, 405+25);
			puthz(389,410,"取消",16,28,WHITE);
			break;
			
		case 3:
			setlinestyle(SOLID_LINE,0,THICK_WIDTH);	
			setcolor(GREEN);
			setfillstyle(1,WHITE);
			bar(360,335,555,335+30);
			rectangle(360,335,555,335+30);
			break;
	}

}

/*************************************************************
函数名：void light_menu(int flag)
参数：编号
返回值：无
函数功能：点亮主界面
**************************************************************/
void light_menu(int flag)

{
	clrmous(MouseX,MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setcolor(DARKGRAY);
	switch(flag)
	{
		    case 1:
			bar(0,0,60,24);
			line(60, 0, 60, 24);
			puthz(10, 4, "文件", 16, 24, WHITE);
			break;
			case 2:
			bar(63,0,165,24);
			line(165, 0, 165, 24);
			puthz(68, 4, "个性设置", 16, 24, WHITE);
			break;
			case 3:
			bar(167,0,255,24);
			line(255, 0, 255, 24);
			puthz(170, 4, "添加主题", 16, 20, WHITE);
			break;
			case 4:
			bar(257,0,360,24);
			line(360, 0, 360, 24);
			puthz(260, 4, "删除主题", 16, 24, WHITE);
			break;
			case 5:
			bar(363,0,415,24);
			line(415, 0, 415, 24);
	        puthz(367, 4, "编辑", 16, 24, WHITE);
			break;
			case 6:
			bar(417,0,470,24);
			line(472,0,472,24);
			puthz(425,4,"帮助",16,24,WHITE);
			break;
			case 7 :
			bar(474,0,525,24);
			line(525,0,525,24);
			puthz(476,4,"取消",16,28,WHITE);
			break;

			case 8:
			bar(526,0,575,24);
			line(575,0,575,24);
			puthz(529,4,"返回",16,24,WHITE);
			break;
			

			default:
			printf("there is something wrong");
			break;
	}




}


/*************************************************************
函数名：void light_menu_recover(int flag)
参数：编号
返回值：无
函数功能：恢复主界面
**************************************************************/
void light_menu_recover(int flag)

{
	clrmous(MouseX,MouseY);
	setfillstyle(1,LIGHTGRAY);
	setcolor(DARKGRAY);
	switch(flag)
	{
		   case 1:
			bar(0,0,60,24);
			line(60, 0, 60, 24);
			puthz(10, 4, "文件", 16, 24, DARKGRAY);
			break;
			case 2:
			bar(63,0,165,24);
			line(165, 0, 165, 24);
			puthz(68, 4, "个性设置", 16, 24, DARKGRAY);
			break;
			case 3:
			bar(167,0,255,24);
			line(255, 0, 255, 24);
			puthz(170, 4, "添加主题", 16, 20,DARKGRAY);
			break;
			case 4:
			bar(257,0,360,24);
			line(360, 0, 360, 24);
			puthz(260, 4, "删除主题", 16, 24, DARKGRAY);
			break;
			case 5:
			bar(363,0,415,24);
			line(415, 0, 415, 24);
	        puthz(367, 4, "编辑", 16, 24, DARKGRAY);
			break;
			case 6:
			bar(417,0,470,24);
			line(472,0,472,24);
			puthz(425,4,"帮助",16,24,DARKGRAY);
			break;
			case 7 :
			bar(474,0,525,24);
			line(525,0,525,24);
			puthz(476,4,"取消",16,28,DARKGRAY);
			break;

			case 8:
			bar(526,0,575,24);
			line(575,0,575,24);
			puthz(529,4,"返回",16,24,DARKGRAY);
			break;

			default:
			printf("there is something wrong");
			break;
	}

}
/*************************************************************
函数名：void menu_z_recover(int yixin)
参数：编号
返回值：无
函数功能：恢复子界面
**************************************************************/
void menu_z_recover(int yixin)
{
	setfillstyle(1,WHITE);
	switch(yixin)
	
	{
		case 1:
		bar(0,24,60,104);
		break;

		case 2:
		bar(60,24,165,105);
		break;

		default:
		printf("there is something wrong");


	}

}

/*************************************************************
函数名：void cover()四种需要不同大小的覆盖函数
参数：坐标，颜色
返回值：无
函数功能：覆盖
**************************************************************/
void cover(int x, int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 100, y + 30);
}
void cover_tips(int x, int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 100, y + 17);
}
void cover_TITLE(int x, int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 100, y + 50);
}
void cover_save(int x, int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 150, y + 30);
}


