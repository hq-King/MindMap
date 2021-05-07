#ifndef _MPFUNC_H__
#define _MPFUNC_H__



//文本框长
#define barlength 90
//文本框宽
#define barwidth 30
//间隙宽
#define spacewidth 30
//间隙长
#define spacelength 50
//版式1的初始框坐标
#define initbarX1 5
#define initbarY1 237
//版式2的初始框坐标
#define initbarX2 263
#define initbarY2 29
//文本框数据
struct bardata
{
	//横坐标
	int barX;
	//纵坐标
	int barY;
	//文本框颜色
	int barcolor;
	//汉字颜色
	int hzcolor;
	//标注状态
	int starstate1;
	//标注的隐藏状态
	int starstate2;
	//储存汉字数组
	char hz[32];
	//子框个数
	int num;
	//折叠状态
	int state;
	//折叠符号状态
	int nodestate;
};
//自动生成线的数据
struct linedata
{
	//父框编号
	int flevel;
	int fnum;
	//子框编号
	int slevel;
	int snum;
	//线的颜色
	int linecolor;
	//显示状态
	int state1;
	//折叠状态
	int state2;
};
//用户连接线的数据
struct linkdata
{
	//父框编号
	int flevel;
	int fnum;
	//子框编号
	int slevel;
	int snum;
	//显示状态
	int state1;
	//折叠状态
	int state2;
};
//思维导图数据
struct mpdata
{
	//最多画100个框
	struct bardata text[10][10];
	//最多自动生成100条线
	struct linedata connect[100];
	//用户最多连50条线
	struct linkdata link[50];
	//每层思维导图的子框个数
	int amoofson[10];
	//思维导图层数
	int amooflevel;
	//自动生成线数量
	int amoofline;
	//用户连接线数量
	int amooflink;
	//背景颜色
	int bkcolor;
};
//选择所需删除的文本框
void deletemp(int state, struct mpdata *mp);
//选中所需添加文本框的父框
void addmp(int state, struct mpdata *mp);
//初始化思维导图结构体的数据
void initmp(int state, struct mpdata *mp);
//重新计算所添加新文本框所在层所有框的坐标,添加自动生成的连接线
void addrecord(int i, int j, int state, struct mpdata *mp);
//删除所选中的文本框及其子文本框
void deleterecord(int i, int j, struct mpdata *mp);
//编辑文本框，往里面输入文字
void mpinputhz(int state, struct mpdata *mp);
//打印所有文本框的汉字
void printhz(struct mpdata mp);
//重新绘制所有连接线
void redrawline(int state, struct mpdata mp);
//重新绘制所有文本框
void redrawbar(struct mpdata mp);
//在添加新文本框之后重新排序，防止出现交叉线
void mpsort(int i, int j, struct mpdata *mp);
//重新绘制标注符号
void redrawstar(struct mpdata mp);
//改变标注状态
void starstate(int state, int i, int j, struct mpdata *mp);
//选择所需改变标注状态的文本框
void changestar(int state, struct mpdata *mp);
//使整个思维导图上移
void mpup(int state, struct mpdata *mp);
//使整个思维导图下移
void mpdown(int state, struct mpdata *mp);
//使整个思维导图左移
void mpleft(int state, struct mpdata *mp);
//使整个思维导图右移
void mpright(int state, struct mpdata *mp);
//将数据存入到思维导图结构体
void linkinput(int state, int i, int j, struct mpdata *mp);
//选择需要自主连接的文本框
void mplink(int state, struct mpdata *mp);
//改变用户连线的状态
void linkstate(int state, int flag, struct mpdata *mp);
//改变选中框及子框的折叠状态
void nodestate(int i, int j, struct mpdata *mp);
//选中需要折叠的框
void mpnode(int state, struct mpdata *mp);
//恢复文本框和连接线的折叠状态
void recovernode(struct mpdata *mp);
//绘制折叠符号
void redrawnode(int state, struct mpdata mp);
#endif
