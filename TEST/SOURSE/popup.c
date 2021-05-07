#include "common.h"
#include "popup.h"
#include "quit.h"

/*************************************************************
函数名：void DrawPopup(int a)
参数：编号
返回值：无
函数功能：绘制弹窗
**************************************************************/
void DrawPopup(int a)
{
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    setfillstyle(SOLID_FILL, WHITE);
    bar(200, 180, 440, 300);
    rectangle(200, 180, 440, 300);
    setfillstyle(SOLID_FILL, WHITE);
    
    if(a == 1)
    {
		rectangle(297,275,343,295);
    	puthz(302,277,"确定",16,20,4);
        puthz(270, 230, "文件已存在", 16, 20, 4);
    }
    else if(a == 2)
    {
		rectangle(297,275,343,295);
    	puthz(302,277,"确定",16,20,4);
        puthz(270, 230, "保存成功", 16, 20, 4);
    }
    else if(a == 3)
    {
		rectangle(215, 275, 263, 295);
		rectangle(377, 275, 425, 295);
    	puthz(223, 277, "确定", 16, 20, 4);
		puthz(383, 277, "取消", 16, 20, 4);
        puthz(269, 230, "确定要退出吗", 16, 20, 4);
    }
    else if(a == 4)
    {
		rectangle(215, 275, 263, 295);
		rectangle(377, 275, 425, 295);
    	puthz(223, 277, "确定", 16, 20, 4);
		puthz(383, 277, "取消", 16, 20, 4);
        puthz(280, 230, "确定要删除此项吗", 16, 20, 4);

    }
    else if(a == 5)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"确定",16,20,4);
	    puthz(280, 230, "文件未保存是否继续", 16, 20, 4);
    }
    else if(a == 6)
	{
		rectangle(297,275,343,295);
   		puthz(302,277,"确定",16,20,4);
	    puthz(280, 230, "保存失败", 16, 20, 4);
    }
	else if(a == 7)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"确定",16,20,4);
	    puthz(260, 230, "文件不存在无法查看", 16, 20, 4);
    }
   
   else if(a == 8)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"确定",16,20,4);
	    puthz(285, 230, "已达上限", 16, 20, 4);
    }

	else if(a == 9)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"确定",16,20,4);
	    puthz(285, 230, "删除成功", 16, 20, 4);

	}

	else if(a == 10)
	{
		rectangle(215, 275, 263, 295);
		rectangle(377, 275, 425, 295);
    	puthz(223, 277, "确定", 16, 20, 4);
		puthz(383, 277, "取消", 16, 20, 4);
        puthz(210, 230, "文件名", 16, 20, 4);
		rectangle(280,230,428,250);
		puthz(220, 195, "请输入您要查看的文件", 16, 20, 4);
	}

	else if(a == 11)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"确定",16,20,4);
	    puthz(285, 230, "您未登录", 16, 20, 4);
    }

	else if(a == 12)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"确定",16,20,4);
	    puthz(285, 230, "文件不存在", 16, 20, 4);
    }

	else if(a == 13)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"确定",16,20,4);
	    puthz(285, 230, "上传成功", 16, 20, 4);
    }

	else if(a == 14)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"确定",16,20,4);
	    puthz(285, 230, "仅对用户开放", 16, 20, 4);
    }

	else if(a == 15)
	{
		rectangle(297,275,343,295);
    	puthz(302,277,"确定",16,20,4);
	    puthz(285, 230, "仅对游客开放", 16, 20, 4);
    }
	}
	

/*************************************************************
函数名：void Popup_func(int statue)
参数：编号
返回值：无
函数功能：调用弹窗
**************************************************************/
void Popup_Func(int statue)
{
	int num=0;
	void *buffer;
	unsigned s;
    clrmous(MouseX, MouseY);
	s=imagesize(200, 180, 440, 300);
	buffer=malloc(s);
	getimage(200, 180, 440, 300, buffer);
	delay(10);
	DrawPopup(statue);

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if(statue == 3 && mouse_press(215, 275, 263, 295) == 1 )
		{
				cleardevice();
				Quit();
		}
        
		if(statue == 3 && mouse_press(377, 275, 425, 295) == 1)
		{
			clrmous(MouseX, MouseY);
			delay(10);
            putimage(200,180,buffer,COPY_PUT);
            free(buffer);
			return;
		}

		if(statue == 9)
		{
			clrmous(MouseX, MouseY);
			delay(10);

			if(mouse_press(215, 275, 263, 295) == 1)
			{
				clrmous(MouseX, MouseY);
				delay(10);
            	putimage(200,180,buffer,COPY_PUT);
				free(buffer);
				return;
			}

			if( mouse_press(377, 275, 425, 295) == 1)
			{
				clrmous(MouseX, MouseY);
				delay(10);
            	putimage(200,180,buffer,COPY_PUT);
            	free(buffer);
				return;
			}


		}

		//其他情况
		if((statue == 1 || statue == 2 || statue == 5 || statue == 6 || statue ==11 ||
		    statue == 7 || statue == 8 || statue == 12 || statue == 13 || statue ==14 ||statue ==15) && 
		   (MouseX > 297 && MouseY > 275 && MouseX <343 && MouseY < 295 ) )
		{

			if( mouse_press(297,275,343,295) == 1 )
			{
				clrmous(MouseX, MouseY);
				delay(10);
            	putimage(200,180,buffer,COPY_PUT);
            	free(buffer);
				return;
			}
				
			if( mouse_press(297,275,343,295) == 2 && num ==0)
			{
				MouseS = 1;	
				num = 1;
				continue;
			}
		}


		if(MouseS != 0)
		{
			MouseS = 0;
			continue;
		}

		
    }
}

