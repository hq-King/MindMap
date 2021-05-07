#ifndef  _STYLE_H__
#define  _STYLE_H__
//绘制选择颜色的框
void Draw_Choice_Color();
//文本框颜色的选择
void Color_Bar_Choice(int state, struct mpdata *mp);
//自动生成连接线颜色的选择
void Color_Line_Choice(int state, struct mpdata *mp);
//背景颜色的选择
void Color_Bk_Choice(int state, struct mpdata *mp);
//文本框汉字颜色的选择
void Color_Hz_Choice(int state, struct mpdata *mp);

#endif