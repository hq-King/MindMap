#include "popup.h"
#include"common.h"
#include"input.h"
#include"mpfunc.h"

/*************************************************************
函数名：redrawbar(struct mpdata mp)
参数：思维导图结构体mp
返回值：无
函数功能：重新绘制所有文本框
**************************************************************/
void redrawbar(struct mpdata mp)
{
	int i;
	int j;
	//清屏
	cleardevice();
	
	//画框
	for (i = 0; i < mp.amooflevel; i++)
	{
		for (j = 0; j < mp.amoofson[i]; j++)
		{	
			if (mp.text[i][j].state == 1)
			{
				//设置颜色
				setfillstyle(SOLID_FILL, mp.text[i][j].barcolor);
				bar(mp.text[i][j].barX, mp.text[i][j].barY, mp.text[i][j].barX + barlength, mp.text[i][j].barY + barwidth);
			}	
		}
	}
}
/*************************************************************
函数名：redrawline(int state, struct mpdata mp)
参数：思维导图版式state,思维导图结构体mp
返回值：无
函数功能：重新绘制所有连接线
**************************************************************/
void redrawline(int state, struct mpdata mp)
{
	int i;
	int j;
	int x1;
	int x2;
	int y1;
	int y2;
	char a[10];
	//设置线
    setlinestyle(SOLID_LINE, 0, 1);
	//画自动生成的线
	for (i = 0; i < mp.amoofline; i++)
	{
		if (mp.connect[i].state1 == 1 && mp.connect[i].state2 == 1)
		{
			//设置颜色
			setcolor(mp.connect[i].linecolor);
			if (state == 1)
			{
				x1 = mp.text[mp.connect[i].flevel][mp.connect[i].fnum].barX + barlength;
				y1 = mp.text[mp.connect[i].flevel][mp.connect[i].fnum].barY + barwidth / 2;
				x2 = mp.text[mp.connect[i].slevel][mp.connect[i].snum].barX;
				y2 = mp.text[mp.connect[i].slevel][mp.connect[i].snum].barY + barwidth / 2;
			}
			if (state == 2)
			{
				x1 = mp.text[mp.connect[i].flevel][mp.connect[i].fnum].barX + barlength/ 2;
				y1 = mp.text[mp.connect[i].flevel][mp.connect[i].fnum].barY + barwidth;
				x2 = mp.text[mp.connect[i].slevel][mp.connect[i].snum].barX + barlength / 2;
				y2 = mp.text[mp.connect[i].slevel][mp.connect[i].snum].barY;
			}	
			line(x1, y1, x2, y2);		
		}		
	}
	//sprintf(a,"%d",mp.amoofline);
	//put_all(50, 50, a, 10, CYAN);
	//画用户自己连接的线
	setcolor(DARKGRAY);
	for (j = 0; j < mp.amooflink; j++)
	{
		if (mp.link[j].state1 == 1 && mp.link[j].state2 == 1)
		{
			if (state == 1)
			{
				x1 = mp.text[mp.link[j].flevel][mp.link[j].fnum].barX + barlength;
				y1 = mp.text[mp.link[j].flevel][mp.link[j].fnum].barY + barwidth / 2;
				x2 = mp.text[mp.link[j].slevel][mp.link[j].snum].barX;
				y2 = mp.text[mp.link[j].slevel][mp.link[j].snum].barY + barwidth / 2;
			}
			if (state == 2)
			{
				x1 = mp.text[mp.link[j].flevel][mp.link[j].fnum].barX + barlength/ 2;
				y1 = mp.text[mp.link[j].flevel][mp.link[j].fnum].barY + barwidth;
				x2 = mp.text[mp.link[j].slevel][mp.link[j].snum].barX + barlength / 2;
				y2 = mp.text[mp.link[j].slevel][mp.link[j].snum].barY;
			}	
			line(x1, y1, x2, y2);	
		}		
	}
}
/*************************************************************
函数名：mpinputhz(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：编辑文本框，往里面输入文字
**************************************************************/	
void mpinputhz(int state, struct mpdata *mp)
{
    int i;
    int j;
    if (press == 1)
    {
        for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
                    clrmous(MouseX, MouseY);
					memset((*mp).text[i][j].hz, '\0', sizeof((*mp).text[i][j].hz));
					redrawbar(*mp);
					redrawstar(*mp);
					redrawnode(state, *mp);
					redrawline(state, *mp);
					printhz(*mp);
					//画页面
					draw_menu(*mp);
                    hz_input((*mp).text[i][j].barX, (*mp).text[i][j].barY, (*mp).text[i][j].barX + barlength, (*mp).text[i][j].barY + barwidth, (*mp).text[i][j].hz, 0, (*mp).text[i][j].hzcolor);
                }
            }
        }
    }
}
/*************************************************************
函数名：printhz(struct mpdata mp)
参数：思维导图结构体mp
返回值：无
函数功能：打印所有文本框的汉字
**************************************************************/	
void printhz(struct mpdata mp)
{
    int i;
    int j;
    for (i = 0; i < mp.amooflevel; i++)
	{
		for (j = 0; j < mp.amoofson[i]; j++)
		{
            put_all(mp.text[i][j].barX, mp.text[i][j].barY, mp.text[i][j].hz, 5, mp.text[i][j].hzcolor);
        }
    }
}
/*************************************************************
函数名：deletemp(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：选择所需删除的文本框
**************************************************************/	
void deletemp(int state, struct mpdata *mp)
{
    int i;
    int j;
	int m;
	int n;
	int k;
    //判断选中框的编号
	if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					//恢复文本框和连接线的折叠状态
					recovernode(mp);
					/*if ((*mp).text[i][j].num > 0)
					{
						deleterecord(i, j, mp);
					}*/
					deleterecord(i, j, mp);
					clrmous(MouseX, MouseY);
					//重新画文本框
					redrawbar(*mp);
					redrawnode(state, *mp);
					redrawstar(*mp);
					//重新画连接线
					redrawline(state, *mp);
					//输出汉字
					printhz(*mp);
					//画页面
					draw_menu(*mp);
					delay(100);
					break;
				}
			}
		}
	}
}

/*************************************************************
函数名：addmp(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：选中所需添加文本框的父框
**************************************************************/	
void addmp(int state, struct mpdata *mp)
{	
	int i;
	int j;
	//判断被点击文本框的编号
	if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					//恢复文本框和连接线的折叠状态
					recovernode(mp);
					//重新计算所有数据
					addrecord(i, j, state, mp);
					//重新画文本框
					redrawbar(*mp);
					redrawnode(state, *mp);
					redrawstar(*mp);
					//重新画连接线
					redrawline(state, *mp);
					//输出汉字
					printhz(*mp);
					//画页面
					draw_menu(*mp);
					delay(100);
					break;
				}
			}
		}
	}
}
/*************************************************************
函数名：initmp(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：初始化思维导图结构体的数据
**************************************************************/	
void initmp(int state, struct mpdata *mp)
{
	int i;
	int m;
	int n;
	int k;
	int l;
	if (state == 1)
	{
		(*mp).text[0][0].barX = initbarX1;
		(*mp).text[0][0].barY = initbarY1;
	}	
	if (state == 2)
	{
		(*mp).text[0][0].barX = initbarX2;
		(*mp).text[0][0].barY = initbarY2;
	}
	(*mp).text[0][0].barcolor = CYAN;
	(*mp).text[0][0].hzcolor = DARKGRAY;
	(*mp).text[0][0].state = 1;
	(*mp).bkcolor = WHITE;
	(*mp).amoofson[0] = 1;
	for (m = 0; m < 10; m++)
	{
		for (n = 0; n < 10; n++)
		{
			for (k = 0; k < 32; k++)
			{
				(*mp).text[m][n].hz[k] = '\0';
			}
			(*mp).text[m][n].num = 0;
			(*mp).text[m][n].starstate1 = 0;
			(*mp).text[m][n].starstate2 = 1;
		}
	}
	for (i = 1; i < 10; i++)
	{
		(*mp).amoofson[i] = 0;
	}
	(*mp).amooflevel = 1;
	(*mp).amoofline = 0;
	(*mp).amooflink = 0;
}
/*************************************************************
函数名：addrecord(int i, int j, int state, struct mpdata *mp)
参数：所添加新框的父框编号ij,思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：重新计算所添加新文本框所在层所有框的坐标,添加自动生成的连接线
**************************************************************/	
void addrecord(int i, int j, int state, struct mpdata *mp)
{
	int k;
	//判断是否超出上限
	if (i == 9)
	{	
		Popup_Func(8);
		return;
	}
	else
	{	
		//判断下一层是否为新一层
		if ((*mp).amoofson[i + 1] == 0)
		{
			(*mp).amooflevel++;			
		}
	}
	//判断是否超出上限
	if ((*mp).amoofson[i + 1] == 10)
	{
		Popup_Func(8);
		return;
	}
	else
	{
		(*mp).amoofson[i + 1]++;
		(*mp).text[i][j].num++;
	}
	//计算坐标并存储
	if (state == 1)
	{
		for (k = 0; k < (*mp).amoofson[i + 1]; k++)
		{
			(*mp).text[i + 1][k].barX = (i + 1) * (barlength + spacelength) + (*mp).text[0][0].barX;
			(*mp).text[i + 1][k].barY = 24 + (480 - 24 - (*mp).amoofson[i + 1] * barwidth - ((*mp).amoofson[i + 1] - 1) * spacewidth) / 2 + k * (spacewidth + barwidth);
		}
	}
	//计算坐标并存储
	if (state == 2)
	{
		for (k = 0; k < (*mp).amoofson[i + 1]; k++)
		{
			(*mp).text[i + 1][k].barX = (640 - 24 - (*mp).amoofson[i + 1] * barlength - ((*mp).amoofson[i + 1] - 1) * spacelength) / 2 + k * (spacelength + barlength);
			(*mp).text[i + 1][k].barY = (i + 1) * (barwidth + spacewidth) + (*mp).text[0][0].barY;
		}
	}
	
	//初始化颜色
	(*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].barcolor = CYAN;
	(*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].hzcolor = DARKGRAY;
	(*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].state = 1;
	(*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].nodestate = 0;
	//存储需要连接的父节点和子节点
	(*mp).amoofline++;
	(*mp).connect[(*mp).amoofline - 1].linecolor = CYAN;
	(*mp).connect[(*mp).amoofline - 1].state1 = 1;
	(*mp).connect[(*mp).amoofline - 1].state2 = 1;
	(*mp).connect[(*mp).amoofline - 1].flevel = i;
	(*mp).connect[(*mp).amoofline - 1].fnum = j;
	(*mp).connect[(*mp).amoofline - 1].slevel = i + 1;
	(*mp).connect[(*mp).amoofline - 1].snum = (*mp).amoofson[i + 1] - 1;
	mpsort(i, j, mp);
}
/*************************************************************
函数名：deleterecord(int i, int j, struct mpdata *mp)
参数：所需删除的框编号ij,思维导图结构体的地址*mp
返回值：无
函数功能：删除所选中的文本框及其子文本框
**************************************************************/	
void deleterecord(int i, int j, struct mpdata *mp)
{
	int g;
	int h;
	int k;
	int l;
	int m;
	int n;
	int count;
	//如果选中框没有子框
	if ((*mp).text[i][j].num == 0)
	{	
		//找到选中框作为子框的线
		for (k = 0; k < (*mp).amoofline; k++)
		{
			if ((*mp).connect[k].slevel == i && (*mp).connect[k].snum == j && (*mp).connect[k].state1 == 1)
			{
				//隐藏这条线
				(*mp).connect[k].state1 = 0;
				//父框的子框数减1
				(*mp).text[i - 1][(*mp).connect[k].fnum].num--;
			}
		}
		//找到选中框下面的框
		for (g = j + 1; g < (*mp).amoofson[i]; g++)
		{
			strcpy((*mp).text[i][g - 1].hz, (*mp).text[i][g].hz);
			(*mp).text[i][g - 1].hzcolor = (*mp).text[i][g].hzcolor;
			(*mp).text[i][g - 1].barcolor = (*mp).text[i][g].barcolor;
			(*mp).text[i][g - 1].num = (*mp).text[i][g].num;
			(*mp).text[i][g - 1].starstate1 = (*mp).text[i][g].starstate1;
			(*mp).text[i][g - 1].starstate2 = (*mp).text[i][g].starstate2;
			(*mp).text[i][g - 1].state = (*mp).text[i][g].state;
			(*mp).text[i][g - 1].nodestate = (*mp).text[i][g].nodestate;
			for (h = 0; h < (*mp).amoofline; h++)
			{
				//找到选中框下面的框作为父框的线
				if ((*mp).connect[h].flevel == i && (*mp).connect[h].fnum == g && (*mp).connect[h].state1 == 1)
				{
					(*mp).connect[h].fnum--;
				}
				//找到选中框下面的框作为子框的线
				if ((*mp).connect[h].slevel == i && (*mp).connect[h].snum == g && (*mp).connect[h].state1 == 1)
				{
					(*mp).connect[h].snum--;
				}
			}			
		}
		//选中框所在层的框数减1
		(*mp).amoofson[i]--;
		//如果选中框为所在层唯一框
		if ((*mp).amoofson[i] == 0)
		{
			//思维导图层数减1
			(*mp).amooflevel--;
		}		 
	}
	//如果选中框有子框
	/*if ((*mp).text[i][j].num > 0)
	{
		for (l = 0; l < (*mp).amoofline; l++)
		{
			if ((*mp).connect[l].flevel == i && (*mp).connect[l].fnum == j && (*mp).connect[l].state1 == 1)
			{
				//如果子框有子框
				if((*mp).text[i + 1][(*mp).connect[l].snum].num > 0)
				{
					deleterecord(i + 1, (*mp).connect[l].snum, mp);
				}
				deleterecord(i + 1, (*mp).connect[l].snum, mp);;
			}
		}

	}
	*/
}
/*************************************************************
函数名：changestar(int state, struct mpdata *mp)
参数：思维导图版式,思维导图结构体的地址*mp
返回值：无
函数功能：选择所需改变标注状态的文本框
**************************************************************/	
void changestar(int state, struct mpdata *mp)
{
	int i;
	int j;
	//判断选中框的编号
	//鼠标左键为添加
	if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					
					//改变标注状态
					starstate(1, i, j, mp);
					redrawbar(*mp);
					redrawnode(state, *mp);
                    redrawline(state, *mp);
					redrawstar(*mp);
                    printhz(*mp);
					//画页面
					draw_menu(*mp);
					delay(100);
					break;
				}
										
			}
		}
	}
	//判断选中框的编号
	//鼠标右键为删除
	if (press == 2)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					
					//改变标注状态
					starstate(2, i, j, mp);
					redrawbar(*mp);
					redrawnode(state, *mp);
                    redrawline(state, *mp);
					redrawstar(*mp);
                    printhz(*mp);
					//画页面
					draw_menu(*mp);
					delay(100);
					break;
				}
										
			}
		}
	}		
}
/*************************************************************
函数名：starstate(int state, int i, int j, struct mpdata *mp)
参数：判断删除还是添加的标志state,思维导图结构体的地址*mp
返回值：无
函数功能：改变标注状态
**************************************************************/	
void starstate(int state, int i, int j, struct mpdata *mp)
{
	if (state == 1)
	{
		if((*mp).text[i][j].starstate1 == 0)
		{
			(*mp).text[i][j].starstate1 =1;
		}	
	}
	if (state == 2)
	{
		if((*mp).text[i][j].starstate1 == 1)
		{
			(*mp).text[i][j].starstate1 =0;
		}	
	}
}
/*************************************************************
函数名：redrawstar(struct mpdata mp)
参数：思维导图结构体mp
返回值：无
函数功能：重新绘制标注符号
**************************************************************/		
void redrawstar(struct mpdata mp)
{
	int i;
	int j;
	int x;
	int y;
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 3);
	for (i = 0; i < mp.amooflevel; i++)
	{
		for (j = 0; j < mp.amoofson[i]; j++)
		{
			if (mp.text[i][j].starstate1 == 1 && mp.text[i][j].starstate2 == 1)
			{
				x = mp.text[i][j].barX + barlength + 2;
				y = mp.text[i][j].barY + barwidth - 10;
				line(x, y + 5, x + 10, y + 5);
				line(x, y, x + 10, y + 10);
				line(x + 5, y, x + 5, y + 10);
				line(x + 10, y, x, y + 10);
			}
		}
	}
}
/*************************************************************
函数名：mpsort(int i, int j, struct mpdata *mp)
参数：思维导图结构体的地址*mp
返回值：无
函数功能：在添加新文本框之后重新排序，防止出现交叉线
**************************************************************/	
void mpsort(int i, int j, struct mpdata *mp)
{
    int m;
    int n;
	int h;
	int l;
	int count = 0;
	struct bardata temp;
	//如果新增框的父框不是所在层最下面的
    if (j != (*mp).amoofson[i] - 1)
	{	
		//如果新增框的父框下面的框有子框
		for (m = j + 1; m < (*mp).amoofson[i]; m++)
		{
			if ((*mp).text[i][m].num > 0)
			{
				strcpy(temp.hz,(*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].hz);
				temp.hzcolor = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].hzcolor;
				temp.barcolor = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].barcolor;
				temp.num = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].num;
				temp.starstate1 = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].starstate1;
				temp.starstate2 = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].starstate2;
				temp.state = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].state;
				temp.nodestate = (*mp).text[i + 1][(*mp).amoofson[i + 1] - 1].nodestate;
				for (l = 0; l < j; l++)
				{
					count = count + (*mp).text[i][l].num;
				}
				//挪移数据
				for (n = (*mp).amoofson[i + 1] - 2; n >= 0 + count + (*mp).text[i][j].num - 1; n--)
				{
					strcpy((*mp).text[i + 1][n + 1].hz, (*mp).text[i + 1][n].hz);
					(*mp).text[i + 1][n + 1].hzcolor = (*mp).text[i + 1][n].hzcolor;
					(*mp).text[i + 1][n + 1].barcolor = (*mp).text[i + 1][n].barcolor;
					(*mp).text[i + 1][n + 1].num = (*mp).text[i + 1][n].num;
					(*mp).text[i + 1][n + 1].starstate1 = (*mp).text[i + 1][n].starstate1;
					(*mp).text[i + 1][n + 1].starstate2 = (*mp).text[i + 1][n].starstate2;
					(*mp).text[i + 1][n + 1].state = (*mp).text[i + 1][n].state;
					(*mp).text[i + 1][n + 1].nodestate = (*mp).text[i + 1][n].nodestate;

					for (h = 0; h < (*mp).amoofline; h++)
					{
						//找到新增框的父框下面框的子框作为父框的线
						if ((*mp).connect[h].flevel == i + 1 && (*mp).connect[h].fnum == n && (*mp).connect[h].state1 == 1)
						{
							(*mp).connect[h].fnum++;
						}
						//找到新增框的父框下面框的子框作为子框的线
						if ((*mp).connect[h].slevel == i + 1 && (*mp).connect[h].snum == n && (*mp).connect[h].state1 == 1)
						{
							(*mp).connect[h].snum++;
						}
					}
				}
				strcpy((*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].hz, temp.hz);
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].hzcolor = temp.hzcolor;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].barcolor = temp.barcolor;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].num = temp.num;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].starstate1 = temp.starstate1;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].starstate2 = temp.starstate2;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].state = temp.state;
				(*mp).text[i + 1][0 + count + (*mp).text[i][j].num - 1].nodestate = temp.nodestate;
				(*mp).connect[(*mp).amoofline - 1].snum = 0 + count + (*mp).text[i][j].num - 1;
				break;
			}
		}	
	}
}
/*************************************************************
函数名：mpup(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：使整个思维导图上移
**************************************************************/	
void mpup(int state, struct mpdata *mp)
{
	int i;
	int j;
	for (i = 0; i < (*mp).amooflevel; i++)
	{
		for (j = 0; j < (*mp).amoofson[i]; j++)
		{
			(*mp).text[i][j].barY = (*mp).text[i][j].barY - 100; 
		}
	}
	redrawbar(*mp);
	redrawnode(state, *mp);
    redrawline(state, *mp);
	redrawstar(*mp);
    printhz(*mp);
	//画页面
	draw_menu(*mp);
	delay(100);

}
/*************************************************************
函数名：mpdown(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：使整个思维导图下移
**************************************************************/	
void mpdown(int state, struct mpdata *mp)
{
	int i;
	int j;
	for (i = 0; i < (*mp).amooflevel; i++)
	{
		for (j = 0; j < (*mp).amoofson[i]; j++)
		{
			(*mp).text[i][j].barY = (*mp).text[i][j].barY + 100; 
		}
	}
	redrawbar(*mp);
	redrawnode(state, *mp);
    redrawline(state, *mp);
	redrawstar(*mp);
    printhz(*mp);
	//画页面
	draw_menu(*mp);
	delay(100);

}
/*************************************************************
函数名: mpleft(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：使整个思维导图左移
**************************************************************/	
void mpleft(int state, struct mpdata *mp)
{
	int i;
	int j;
	for (i = 0; i < (*mp).amooflevel; i++)
	{
		for (j = 0; j < (*mp).amoofson[i]; j++)
		{
			(*mp).text[i][j].barX = (*mp).text[i][j].barX - 150; 
		}
	}
	redrawbar(*mp);
	redrawnode(state, *mp);
    redrawline(state, *mp);
	redrawstar(*mp);
    printhz(*mp);
	//画页面
	draw_menu(*mp);
	delay(100);

}
/*************************************************************
函数名: mpright(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：使整个思维导图右移
**************************************************************/	
void mpright(int state, struct mpdata *mp)
{
	int i;
	int j;
	for (i = 0; i < (*mp).amooflevel; i++)
	{
		for (j = 0; j < (*mp).amoofson[i]; j++)
		{
			(*mp).text[i][j].barX = (*mp).text[i][j].barX + 150;
		}
	}
	redrawbar(*mp);
	redrawnode(state, *mp);
    redrawline(state, *mp);
	redrawstar(*mp);
    printhz(*mp);
	//画页面
	draw_menu(*mp);
	delay(100);

}
/*************************************************************
函数名: mplink(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：选择需要自主连接的文本框
**************************************************************/	
void mplink(int state, struct mpdata *mp)
{
	int i;
	int j;
	//判断选中框的编号
	//左键选择第一个框
	if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					
					//存数据
					linkinput(1, i, j, mp);
					break;
				}
										
			}
		}
	}
	//右键选择第二个框
	if (press == 2)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth)
				{	
					
					//存数据
					linkinput(2, i, j, mp);
					redrawbar(*mp);
					redrawnode(state, *mp);
        			redrawline(state, *mp);
					redrawstar(*mp);
        			printhz(*mp);
					//画页面
					draw_menu(*mp);
					delay(100);
					break;
				}
										
			}
		}
	}

}
/*************************************************************
函数名: linkinput(int state, int i, int j, struct mpdata *mp)
参数：判断点击是左键还是右键的标志state,所点击文本框的编号ij,state,思维导图结构体的地址*mp
返回值：无
函数功能：将数据存入到思维导图结构体
**************************************************************/	
void linkinput(int state, int i, int j, struct mpdata *mp)
{

	int k;
	if (state == 1)
	{
		(*mp).link[(*mp).amooflink].flevel = i;
		(*mp).link[(*mp).amooflink].fnum = j;
	}
	if (state == 2)
	{
		(*mp).link[(*mp).amooflink].slevel = i;
		(*mp).link[(*mp).amooflink].snum = j;
		(*mp).link[(*mp).amooflink].state1 = 1;
		(*mp).link[(*mp).amooflink].state2 = 1;
		(*mp).amooflink++;
	}
	
}
/*************************************************************
函数名:linkstate(int state, int flag, struct mpdata *mp)
参数：思维导图版式state,用户连线的状态flag,思维导图结构体的地址*mp
返回值：无
函数功能：改变用户连线的状态
**************************************************************/	
void linkstate(int state, int flag, struct mpdata *mp)
{
	int i;
	if (flag == 2)
	{
		for (i = 0; i < (*mp).amooflink; i++)
		{
			(*mp).link[i].state1 = 0;
		}
	}
	if (flag == 1)
	{
		for (i = 0; i < (*mp).amooflink; i++)
		{
			(*mp).link[i].state1 = 1;
		}
	}	
	redrawbar(*mp);
	redrawnode(state, *mp);
    redrawline(state, *mp);
	redrawstar(*mp);
    printhz(*mp);
	//画页面
	draw_menu(*mp);
	delay(100);
}
/*************************************************************
函数名: nodestate(int i, int j, struct mpdata *mp)
参数：选中框的编号ij,思维导图结构体的地址*mp
返回值：无
函数功能：改变选中框及子框的折叠状态
**************************************************************/	
void nodestate(int i, int j, struct mpdata *mp)
{
	int g;
	int h;
	int k;
	int l;
	int count = 0;
	//找到选中框子框的编号
	for (g = 0; g < j; g++)
	{
		count = count + (*mp).text[i][g].num;
	}
	for (h = 0; h < (*mp).text[i][j].num; h++)
	{
		//递归使用
		nodestate(i + 1, count + h, mp);	
	}
	//折叠选中框
	(*mp).text[i][j].state = 0;
	(*mp).text[i][j].starstate2 = 0;
	//折叠选中框作为父框的线
	for (k = 0; k < (*mp).amoofline; k++)
	{
		if ((*mp).connect[k].flevel == i && (*mp).connect[k].fnum == j && (*mp).connect[k].state2 == 1)
		{
			(*mp).connect[k].state2 = 0;
		}
	}
	for (l = 0; l < (*mp).amooflink; l++)
	{
		if ((*mp).link[l].flevel == i && (*mp).link[l].fnum == j && (*mp).link[l].state2 == 1)
		{
			(*mp).link[l].state2 = 0;
		}
	}
	
}
/*************************************************************
函数名: mpnode(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：选中需要折叠的框
**************************************************************/	
void mpnode(int state, struct mpdata *mp)
{
	int i;
	int j;
	//判断被点击文本框的编号
	if (press == 1)
	{
		for (i = 0; i < (*mp).amooflevel; i++)
		{
			for (j = 0; j < (*mp).amoofson[i]; j++)
			{
				if (MouseX > (*mp).text[i][j].barX && MouseX < (*mp).text[i][j].barX + barlength && MouseY > (*mp).text[i][j].barY && MouseY < (*mp).text[i][j].barY + barwidth && (*mp).text[i][j].state == 1)
				{	
					//改变文本框与连接线的折叠状态
					nodestate(i, j, mp);
					//恢复选中框的折叠状态
					(*mp).text[i][j].state = 1;
					(*mp).text[i][j].nodestate = 1;
					//重新画文本框
					redrawbar(*mp);
					//重新绘制标志符
					redrawstar(*mp);
					//重新绘制折叠符号
					redrawnode(state, *mp);
					//重新画连接线
					redrawline(state, *mp);
					//输出汉字
					printhz(*mp);
					//画页面
					draw_menu(*mp);
					delay(100);
					break;
				}
			}
		}
	}
}
/*************************************************************
函数名: recovernode(struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：恢复文本框和连接线的折叠状态
**************************************************************/	
void recovernode(struct mpdata *mp)
{
	int g;
	int h;
	int l;
	int m;	
	for (g = 0; g < (*mp).amooflevel; g++)
	{
		for (h = 0; h < (*mp).amoofson[g]; h++)
		{
			//恢复文本框的折叠状态
			if((*mp).text[g][h].state == 0)
			{
				(*mp).text[g][h].state = 1;
			}
			//恢复折叠符号的状态
			if ((*mp).text[g][h].nodestate == 1)
			{
				(*mp).text[g][h].nodestate = 0;
			}
			//恢复标注的隐藏状态
			if ((*mp).text[g][h].starstate2 == 0)
			{
				(*mp).text[g][h].starstate2 = 1;
			}
		}
	}
	//恢复连接线的折叠状态
	for (l = 0; l < (*mp).amoofline; l++)
	{
		if ((*mp).connect[l].state2 == 0)
		{
			(*mp).connect[l].state2 = 1;
		}
	}
	for (m = 0; m < (*mp).amooflink; m++)
	{
		if ((*mp).link[l].state2 == 0)
		{
			(*mp).link[l].state2 = 1;
		}
	}
	
}
/*************************************************************
函数名: redrawnode(int state, struct mpdata *mp)
参数：思维导图版式state,思维导图结构体的地址*mp
返回值：无
函数功能：绘制折叠符号
**************************************************************/	
void redrawnode(int state, struct mpdata mp)
{
	int x;
	int y;
	int i;
	int j;
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE, 0, 1);
	for (i = 0; i < mp.amooflevel; i++)
	{
		for (j = 0; j < mp.amoofson[i]; j++)
		{
			if(mp.text[i][j].state == 1 && mp.text[i][j].nodestate == 1)
			{
				if(state == 1)
				{
					x = mp.text[i][j].barX + barlength + 5;
					y = mp.text[i][j].barY + barwidth / 2;
				}
				if(state == 2)
				{
					x = mp.text[i][j].barX + barlength / 2;
					y = mp.text[i][j].barY + barwidth + 5;
				}			
				circle(x, y, 5);
				line(x - 5, y, x + 5, y);
				line(x, y - 5, x, y + 5);
			}
		}
	}
}