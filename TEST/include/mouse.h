#ifndef _mouse_h_
#define _mouse_h_
//判断鼠标点击框
int mouse_press(int x1, int y1, int x2, int y2);
//画不同形态的鼠标
void mouse(int,int);
//鼠标初始化
void mouseinit(void);
//
void mread(int *,int *,int*);
//存鼠标背景
void save_bk_mou(int x,int y);
//清除鼠标
void clrmous(int x,int y);
//画鼠标
void drawmous(int x,int y);
//鼠标状态发生变化则更新鼠标
void newmouse(int *nx,int *ny,int *nbuttons);   
//判断鼠标点击圆
int mouse_presscircle(int x, int y, int r);

int mouse_pressother(int x1,int y1,int x2,int y2);

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;
extern union REGS regs;
#endif
