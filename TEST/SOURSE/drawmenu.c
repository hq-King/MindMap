#include"common.h"
#include"input.h"
#include"drawmenu.h"
#include"mpfunc.h"
/*************************************************************
函数名：draw_menu(struct mpdata mp)
参数：思维导图结构体mp
返回值：无
函数功能：重新绘制上方菜单
**************************************************************/
void draw_menu(struct mpdata mp)
{	
	setbkcolor(mp.bkcolor);

	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, 0, 640, 24);
	
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
	line(472,0,472,24);
	puthz(425,4,"帮助",16,24,DARKGRAY);
	//取消
	line(525,0,525,24);
	puthz(476,4,"取消",16,28,DARKGRAY);
	//返回
	line(575,0,575,24);
	puthz(529,4,"返回",16,24,DARKGRAY);

	//错号
	line(616, 0, 616, 24);
	line(616, 0, 640, 0);
	line(616, 24, 640, 24);
	line(640, 0, 640, 24);
	line(616, 0, 640, 24);
	line(616, 24, 640, 0);
	//左箭头
	line(0, 465, 5, 460);
	line(0, 465, 5, 470);
	line(5, 460, 5, 463);
	line(5, 467, 5, 470);
	line(5, 463, 10, 463);
	line(5, 467, 10, 467);
	line(10, 463, 10, 467);
	//右箭头
	line(20, 463, 20, 467);
	line(20, 463, 25, 463);
	line(20, 467, 25, 467);
	line(25, 463, 25, 460);
	line(25, 467, 25, 470);
	line(25, 460, 30, 465);
	line(25, 470, 30, 465);
	//上箭头
	line(15, 450, 10, 455);
	line(15, 450, 20, 455);
	line(10, 455, 13, 455);
	line(17, 455, 20, 455);
	line(13, 455, 13, 460);
	line(17, 455, 17, 460);
	line(13, 460, 17, 460);
	//下箭头
	line(13, 470, 17, 470);
	line(13, 470, 13, 475);
	line(17, 470, 17, 475);
	line(10, 475, 13, 475);
	line(17, 475, 20, 475);
	line(10, 475, 15, 480);
	line(20, 475, 15, 480);
}

/*************************************************************
函数名：init_z_menu(int flag)
参数：判断是哪个下拉菜单的标志flag
返回值：无
函数功能：重新绘制下来菜单
**************************************************************/
void init_z_menu(int flag)
{
	clrmous(MouseX,MouseY);
	setfillstyle(1,LIGHTGRAY);

	switch(flag)
	{
		case 1:
		//文件下拉菜单
		bar(0,24,60,105);
		setcolor(RED);
		rectangle(0,24,60,104);
		line(0,24,60,24);
		line(0,44,60,44);
		line(0,64,60,64);
		line(0,84,60,84);
		puthz(3,25,"新建",16,20,DARKGRAY);
		puthz(3,45,"保存",16,20,DARKGRAY);
		puthz(3,65,"历史",16,20,DARKGRAY);
		puthz(3,85,"大纲",16,20,DARKGRAY);
	
		break;

		case 2:
		//编辑下拉菜单
		bar(60,24,165,185);
		setcolor(RED);
		rectangle(60,24,165,184);
		line(60,44,165,44);
		puthz(63,25,"连接线颜色",16,20,DARKGRAY);
		line(60,64,165,64);
		puthz(63,45,"文本框颜色",16,20,DARKGRAY);
		line(60,84,165,84);
		puthz(63,65,"背景颜色",16,23,DARKGRAY);
		line(60,104,165,104);
		puthz(63,85,"字体颜色",16,23,DARKGRAY);
		line(60,124,165,124);
		puthz(63,105,"标注",16,79,DARKGRAY);
		line(60,144,165,144);
		puthz(63,125,"连线",16,79,DARKGRAY);
		line(60,164,165,164);
		puthz(63,145,"连线状态",16,23,DARKGRAY);
		line(60,184,165,184);
		puthz(63,165,"折叠",16,79,DARKGRAY);
	
	
		default:
		break;

	}

}

