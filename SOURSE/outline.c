#include"common.h"
#include"mpfunc.h"
/*************************************************************
函数名：draw_outline(struct mpdata mp)
参数：思维导图结构体mp
返回值：无
函数功能：绘制大纲模式界面
**************************************************************/	
void draw_outline(struct mpdata mp)
{
    int i;
    int j;
    int k = 0;
    cleardevice();
    setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(540, 0, 640, 50);
    puthz(541, 1, "返回", 48, 50, RED);
    for(i = 0; i < mp.amooflevel; i++)
    {
        for (j = 0; j < mp.amoofson[i]; j++)
        {
            put_all(i * 20, k * 20, mp.text[i][j].hz, 5, color_select(i, j, mp));
            k++;
        }
    }
}
/*************************************************************
函数名：color_select(int i, int j, struct mpdata mp)
参数：文本框编号ij,思维导图结构体mp
返回值：无
函数功能：选择字体颜色
**************************************************************/	
int color_select(int i, int j, struct mpdata mp)
{
    //标注的文本框用红色字体
    if (mp.text[i][j].state == 1)
    {
        return RED;
    }
    //未标注的文本框用深灰色字体
    if (mp.text[i][j].state == 0)
    {
		return DARKGRAY;
    }
}
/*************************************************************
函数名：outline_func(int state, int *func, struct mpdata mp)
参数：思维导图版式state,界面参数地址*func,思维导图结构体mp
返回值：无
函数功能：大纲模式的功能选择
**************************************************************/
void outline_func(int state, int *func, struct mpdata mp)
{
    draw_outline(mp);
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //返回
        if (MouseX > 540 && MouseX < 640 && MouseY > 0 && MouseY < 50)
        {
            if (mouse_press(540, 0, 640, 50) == 1)
            {
                delay(500);
                clrmous(MouseX, MouseY);
				cleardevice();
                if (state == 1)
                {
                    *func = 3;
                }
                if (state == 2)
                {
                    *func = 3;
                }
				return;		
            }
        }
    }
}