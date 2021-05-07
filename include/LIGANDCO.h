#ifndef  _LIGHTANDCOVER_H__
#define  _LIGHTANDCOVER_H__
//点亮文本框
void lightbutton_register(int x, int y, int x1, int y1, int color1, int color2, int flag);
//恢复文本框
void recoverbutton_register(int status);
//点亮文本框
void light_login(int x, int y, int x1, int y1, int color1, int color2, int flag);
//点亮弹窗
void lightbutton_tc(int x, int y, int x1, int y1, int color, int flag);
//恢复弹窗
void recoverbutton_tc(void);
//点亮保存界面
void lightButton_Save(int n);
//保存界面按钮高亮恢复
void RecoverButton_Save(int n);
//点亮主界面
void menu_z_recover(int yixin);
//恢复主界面
void light_menu_recover(int flag);
//恢复子界面
void light_menu(int flag);
//覆盖
void cover(int x, int y,int color);
void cover_tips(int x, int y,int color);
void cover_TITLE(int x, int y,int color);
void cover_save(int x, int y,int color);

#endif