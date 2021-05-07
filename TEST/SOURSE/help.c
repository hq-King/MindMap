#include "common.h"
#include "help.h"

void Draw_About()
{
    int i, j;
    setcolor(RED);
    rectangle(520,0,580,30);
    rectangle(580,0,640,30);
    rectangle(460,0,520,30);
    puthz(462,2,"帮助",24,30,BLUE);
    puthz(522,2,"关于",24,30,BLUE);
    puthz(582,2,"返回",24,30,BLUE);
    
	setbkcolor(WHITE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(2, HORIZ_DIR, 6);
    puthz(246,2,"思维导图",32,40,BLUE);
    
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 620; j++)
		{
			putpixel(10 + 10 * j, 40 + 20 * i, LIGHTRED);
		}
	}
	puthz(10, 40, "开发人员：华中科技大学人工智能与自动化学院", 16, 17, RED);

	puthz(10+17*5, 60, "自动化类", 16, 17, RED);
	setcolor(RED);
	outtextxy(13 + 17 * 8, 57, "  2003");
	puthz(10 + 17 * 12, 60, "王涵情", 16, 17, BLUE);
	puthz(10 + 17 * 17, 60, "马润泽", 16, 17, BLUE);
    puthz(10, 80, "测试人员：华中科技大学人工智能与自动化学院", 16, 17, RED);
	setcolor(RED);
	outtextxy(13 + 17 * 21, 77, "C");
	puthz(10 + 22 * 17, 80, "语言教授、副教授", 16, 17, RED);

	puthz(10, 100, "更新日期：", 16, 17, RED);
	setcolor(BLUE);
	outtextxy(13 + 17 * 5, 97, "2021/4/3");

	puthz(10, 120, "大小：", 16, 17, RED);
	setcolor(BLUE);
	outtextxy(13 + 17 * 3, 117, "xxxx");

	setcolor(RED);
	outtextxy(10, 137, "VERSION: 1.0");

	puthz(10 + 17 * 2, 180, "此软件为入门级产品，对电脑配置要求较低。", 16, 17, BLUE);

	puthz(10 + 17 * 2, 200, "此软件不作为任何商业用途，如果发现有任何违规或者抄袭现象或", 16, 17, BLUE);
	puthz(10, 220, "被抄袭现象，开发者将承担或有权追究其责任。", 16, 17, BLUE);

	puthz(10 + 17 * 2, 240, "此软件的开发目的，是为了方便需要使用思维导图来让自己对某件事", 16, 17, BLUE);
	puthz(10, 260, "理解更加清晰的人员去学习与发散自己的思维", 16, 17, BLUE);
	puthz(10, 280, "此软件的构建借鉴了市面上相关软件", 16, 17, BLUE);
	puthz(10+17*2, 320, "最后，我们想感谢", 16, 17, BLUE);
	outtextxy(13 + 17 * 10, 317, "C");
	puthz(10 + 17 * 11, 320, "语言课程设计的所有老师、助教，以及帮助过", 16, 17, BLUE);
	puthz(10, 340, "我们的同学。软件依旧有很多不足或者是可更新优化的地方。希望我们", 16, 17, BLUE);
	puthz(10, 360, "能一直热爱编程",16, 17, BLUE);
	
	puthz(30+ 17 * 6, 360, "语言和编程设计，在软件开发方面走的更远。", 16, 17, BLUE);

	
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(3, HORIZ_DIR, 4);
	setcolor(RED);
	outtextxy(140, 390, "HUST:");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(2, HORIZ_DIR, 8);
	setcolor(RED);
	outtextxy(220, 397, "	   SCHOOL OF");
	setcolor(RED);
	outtextxy(50, 430, "ARTIFICIAL INTELLIGENCE AND AUTOMATION");
}

void Help_Func(int *func,int statue)
{
    Draw_Help();
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //返回按钮
        if(MouseX > 580 && MouseY > 0 && MouseX < 640 && MouseY < 30)
        {
            if(mouse_press(580,0,640,30) == 1)
            {
                if( statue == 1)
                {
                    clrmous(MouseX,MouseY);
                    cleardevice();
					*func = 8;
                    return ;
                }

                if( statue == 2)
                {
                    clrmous(MouseX,MouseY);
                    cleardevice();
                    *func = 9;
                    return ;
                }
            }

            if(mouse_press(580,0,640,30) == 2)
            {
                MouseS = 1;
                continue;
            }
        }
            //关于
        if(MouseX > 520 && MouseY > 0 && MouseX < 580 && MouseY < 30)
        {

            if(mouse_press(520,0,580,30) == 2)
            {
                
                MouseS = 1;
                continue;
            
            }

            if(mouse_press(520,0,580,30) == 1)
            {
                clrmous(MouseX , MouseY);
                cleardevice();
               *func = 7;
                return;
            }
            
        }
            //帮助
        if(MouseX > 460 && MouseY > 0 && MouseX < 520 && MouseY < 30)
        {

            if(mouse_press(460,0,520,30) == 2)
            {
                
                MouseS = 1;
                continue;
            
            }

            if(mouse_press(460,0,520,30) == 1)
            {
                clrmous(MouseX , MouseY);
                cleardevice();
                *func = 6;
                return;

            }
        }

        if(MouseS != 0)
        {
            MouseS = 0;
            continue;
        }

    }
}

void Draw_Help()
{
    int i, j;
    setcolor(RED);
    rectangle(520,0,580,30);
    rectangle(580,0,640,30);
    rectangle(460,0,520,30);
    puthz(462,2,"帮助",24,30,BLUE);
    puthz(522,2,"关于",24,30,BLUE);
    puthz(582,2,"返回",24,30,BLUE);
	setbkcolor(WHITE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(2, HORIZ_DIR, 6);
    puthz(246,2,"思维导图",32,40,BLUE);

	puthz(10, 40, "一·如何使用：", 16, 17, RED);
    puthz(40,60,"鼠标左击添加按钮，点击相应的文本框就可以进行主题添加",16,17,BLUE);
    puthz(40,80,"点击删除节点按钮则可以进行删除",16,17,BLUE);
    puthz(40,100,"点击个性设置可以更换文本框颜色，连接线颜色和字体颜色",16,17,BLUE);
	puthz(40,120,"文件按钮可以进行文件的保存新建与查看历史",16,17,BLUE);

    puthz(10, 150, "二·忘记密码怎么办：", 16, 17, RED);
    puthz(40,170,"在登录界面点击忘记密码选项，输入用户名和电话号码匹配成功",16,17,BLUE);
	puthz(40,190,"则可重新写入密码",16,17,BLUE);
    puthz(10, 210, "三·如何编辑文字：", 16, 17, RED);
    puthz(40,230,"鼠标右击文本框则可以进行文字的编辑",16,17,BLUE);
    puthz(40,250,"在输入法框中，按下空格键显示中文，按下回车键显示英文",16,17,BLUE);

    puthz(10, 270, "四·想查看效果怎么办：", 16, 17, RED);
    puthz(40,290,"鼠标左键点击大纲界面则可看其预览图",16,17,BLUE);

    puthz(10, 310, "四·如何进行保存：", 16, 17, RED);
    puthz(40,330,"鼠标单击文件下拉菜单中的保存选项",16,17,BLUE);
    puthz(40,350,"在框中输入文件名，点击确定",16,17,BLUE);
    puthz(40,370,"则可在相应文件夹中找到保存的文件",16,17,BLUE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(3, HORIZ_DIR, 4);
	setcolor(RED);
	outtextxy(140, 390, "HUST:");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(2, HORIZ_DIR, 8);
	setcolor(RED);
	outtextxy(220, 397, "	   SCHOOL OF");
	setcolor(RED);
	outtextxy(50, 430, "ARTIFICIAL INTELLIGENCE AND AUTOMATION");
}

void About_func(int *func,int statue)
{
    Draw_About();
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //返回按钮
        if(MouseX > 580 && MouseY > 0 && MouseX < 640 && MouseY < 30)
        {
            if(mouse_press(580,0,640,30) == 1)
            {
                if( statue == 1)
                {
                    clrmous(MouseX,MouseY);
                    cleardevice();
					*func = 8 ;
                    return ;
                }

                if( statue == 2)
                {
                    clrmous(MouseX,MouseY);
                    cleardevice();
				  *func = 9;
                    return ;
                }
            }

            if(mouse_press(580,0,640,30) == 2)
            {
                MouseS = 1;
                continue;
            }
        }
            //关于
        if(MouseX > 520 && MouseY > 0 && MouseX < 580 && MouseY < 30)
        {

            if(mouse_press(520,0,580,30) == 2)
            {
                
                MouseS = 1;
                continue;
            }
        

            if(mouse_press(520,0,580,30) == 1)
            {
                clrmous(MouseX , MouseY);
                cleardevice();
                *func = 7;
                return;
                
            }
            
        }
            //帮助
        if(MouseX > 480 && MouseY > 0 && MouseX < 520 && MouseY < 30)
        {

            if(mouse_press(480,0,520,30) == 2)
            {
                
                MouseS = 1;
                continue;
            }

            if(mouse_press(480,0,520,30) == 1)
            {
                clrmous(MouseX , MouseY);
                cleardevice();
                *func = 6;
                return;
            }
        }

        if(MouseS != 0)
        {
            MouseS = 0;
            continue;
        }

    }
}



