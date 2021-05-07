#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include "mouse.h"


int MouseX;  //鼠标位置x
int MouseY;  //鼠标位置y
int MouseS;  //鼠标形状Shape
int press;   //鼠标按压状态
void *buffer;
union REGS regs;
int flag=0;  //鼠标画面存在状态

/*************************************************************
函数名：mouseinit()
参数：无
返回值：无
函数功能：鼠标初始化
**************************************************************/	
void mouseinit()
{
	int retcode;
	int xmin,xmax,ymin,ymax,x_max=625,y_max=480;
	int size;

	xmin=2;
	xmax=x_max-1;
	ymin=8;
	ymax=y_max-2;
	regs.x.ax=0;
	int86(51,&regs,&regs);
	retcode=regs.x.ax;
	if(retcode==0)
	{
		printf("Mouse or Mouse Driver Obsent,Please Install!");
		delay(5000);
	}
	else
	{
		regs.x.ax=7;
		regs.x.cx=xmin;
		regs.x.dx=xmax;
		int86(51,&regs,&regs);
		regs.x.ax=8;
		regs.x.cx=ymin;
		regs.x.dx=ymax;
		int86(51,&regs,&regs);
	}
	MouseS = 0;
	MouseX=320,MouseY=240;
	save_bk_mou(320,240);
	mouse(MouseX,MouseY);
	flag=1;
}
/*************************************************************
函数名：mouse(int x,int y)
参数：鼠标坐标xy
返回值：无
函数功能：画不同形态的鼠标
**************************************************************/	
void mouse(int x,int y)
{
	
	switch(MouseS)
	{
		case 1:                                  //手势鼠标
		{
				setcolor(BLUE);
				setlinestyle(0,0,1);
				line(x-1,y+9,x-1,y+8);
				line(x,y+7,x,y+11);
				line(x+1,y+6,x+1,y+13);
				line(x+2,y+8,x+2,y+14);
				line(x+3,y-1,x+3,y+15);
				arc(x+4,y-1,0,180,1);
				line(x+4,y-2,x+4,y+15);
				line(x+5,y-1,x+5,y+16);
				arc(x+6,y+3,0,180,1);
				line(x+6,y+2,x+6,y+16);
				line(x+7,y+3,x+7,y+17);
				arc(x+8,y+5,0,180,1);
				line(x+8,y+4,x+8,y+17);
				line(x+9,y+5,x+9,y+16);
				arc(x+10,y+7,0,180,1);
				line(x+10,y+6,x+10,y+16);
				line(x+11,y+7,x+11,y+13);

				setcolor(BLUE);
				line(x-1,y+9,x-1,y+8);
				line(x-1,y+8,x+1,y+6);
				line(x+1,y+6,x+3,y+10);
				line(x+3,y+10,x+3,y-1);
				arc(x+4,y-1,0,180,1);
				line(x+5,y-1,x+5,y+5);
				arc(x+6,y+3,0,180,1);
				line(x+7,y+3,x+7,y+7);
				arc(x+8,y+5,0,180,1);
				line(x+9,y+5,x+9,y+9);
				arc(x+10,y+7,0,180,1);
				line(x+11,y+7,x+11,y+13);
				arc(x+7,y+13,-90,0,4);
				line(x+7,y+17,x+3,y+15);
				line(x+3,y+15,x+1,y+13);
				line(x+1,y+13,x-1,y+9);
		}
			break;
		case 2:                        //光标
		{
			setcolor(BLUE);
			setlinestyle(0,0,1);
			line(x+1,y-1,x+9,y-1);
			line(x+1,y+15,x+9,y+15);
			line(x+5,y-1,x+5,y+15);
		}
			break;
		case 3:                        //十字
		{
			setcolor(BLUE);
			setlinestyle(0,0,1);
			line(x-1,y+7,x+11,y+7);
			line(x+5,y-1,x+5,y+15);
		}
			break;
		default:              //默认鼠标
		{
			setcolor(BLUE);
			 line(x,y,x,y+15);
  			 line(x+1,y+1,x+1,y+13);
 			 line(x+2,y+3,x+2,y+11);
 			 line(x+3,y+4,x+3,y+9);
			 line(x+4,y+5,x+4,y+9);
 			 line(x+5,y+7,x+5,y+10);
 			 line(x+6,y+8,x+6,y+10);
			 line(x+7,y+9,x+7,y+11);
			 line(x+8,y+11,x+8,y+11);
			 line(x+9,y+12,x+9,y+12);
		}
		break;
	}
}

/*************************************************************
函数名：mread(int *nx,int *ny,int *nbuttons)
参数：鼠标坐标地址*nx*ny,按钮状态地址*nbuttons
返回值：无
函数功能：获取新的寄存器信息
**************************************************************/	
void mread(int *nx,int *ny,int *nbuttons)  
{
	regs.x.ax=3;
	int86(51,&regs,&regs);
	*nx = regs.x.cx;
	*ny = regs.x.dx;
	*nbuttons = regs.x.bx;
}
/*************************************************************
函数名：newmouse(int *nx,int *ny,int *nbuttons)
参数：鼠标坐标地址*nx*ny,按钮状态地址*nbuttons
返回值：无
函数功能：鼠标状态发生变化则更新鼠标
**************************************************************/	
void newmouse(int *nx,int *ny,int *nbuttons)
{
	int xn,yn,buttonsn;
	int x0=*nx,y0=*ny,buttons0=*nbuttons;
	mread(&xn,&yn,&buttonsn);
	*nx = xn;
	*ny = yn;
	*nbuttons = buttonsn;
	if(buttons0 == *nbuttons)
		*nbuttons = 0;    //使得能连续按键
	if(xn == x0 && yn == y0 && buttonsn == buttons0)
		return;            //鼠标状态不变则直接返回S
	clrmous(x0,y0);        //说明鼠标状态发生了改变
	save_bk_mou(*nx,*ny);
	drawmous(*nx,*ny);
}
/*************************************************************
函数名：save_bk_mou(int nx,int ny)
参数：鼠标坐标nxny
返回值：无
函数功能：存鼠标背景
**************************************************************/	
void save_bk_mou(int nx,int ny)
{
	int size;

	size=imagesize(nx-1,ny-2,nx+11,ny+17);
	buffer=malloc(size);
	if(buffer!=NULL)
		getimage(nx-1,ny-2,nx+11,ny+17,buffer);
	else
		printf("Error");
}
/*************************************************************
函数名：clrmous(int nx,int ny)
参数：鼠标坐标nxny
返回值：无
函数功能：清除鼠标
**************************************************************/	
void clrmous(int nx,int ny)
{
	if(flag==1)
	{
		setwritemode(XOR_PUT); 
		mouse(nx,ny);
		putimage(nx-1,ny-2,buffer,COPY_PUT);
		free(buffer);
		flag=0;
		setwritemode(COPY_PUT);
	}
}
/*************************************************************
函数名：drawmous(int nx,int ny)
参数：鼠标坐标nxny
返回值：无
函数功能：画鼠标
**************************************************************/	
void drawmous(int nx,int ny)
{
	if(flag==0)
	{
		setwritemode(COPY_PUT);
	    mouse(nx,ny);
		flag=1;
	}
}

/*************************************************************
函数名：mouse_press(int x1, int y1, int x2, int y2)
参数：鼠标点击框的左上角坐标x1y1和右下角坐标x2y2
返回值：1:在框中点击 2：在框中未点击 0：不在框中
函数功能：判断鼠标点击框
**************************************************************/	
//如果在框中点击，则返回1；在框中未点击，则返回2；不在框中则返回0
int mouse_press(int x1, int y1, int x2, int y2)
{
	//在框中点击，则返回1
	if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 1)
	{
		return 1;
	}
	
	//在框中未点击，则返回2
	else if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 0)
	{
		return 2;
	}
	
	//在框中点击右键，则返回3
	else if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 2)
	{
		return 3;
	}
	
	else
	{
		return 0;
	}
}
/*************************************************************
函数名：mouse_presscircle(int x, int y, int r)
参数：鼠标点击圆的圆心坐标x1y1,半径r
返回值：1:在框中点击 2：在框中未点击 0：不在框中
函数功能：判断鼠标点击圆
**************************************************************/	
int mouse_presscircle(int x, int y, int r)
{
	if(((MouseX - x) * (MouseX - x) + (MouseY - y) * (MouseY - y)) < r*r && press == 1)
	{
		return 1;
	}
	else if(((MouseX - x) * (MouseX - x) + (MouseY - y) * (MouseY - y)) < r*r && press == 0)
	{
		return 2;
	}
	else if(((MouseX - x) * (MouseX - x) + (MouseY - y) * (MouseY - y)) < r*r && press == 2)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int mouse_pressother(int x1,int y1,int x2,int y2)
{
	if((MouseX < x1 || MouseX > x2 || MouseY < y1 || MouseY > y2) && press == 1)
		return 1;
	else
		return 0;
}


