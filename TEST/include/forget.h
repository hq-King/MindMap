#ifndef  _FORGET_H__
#define  _FORGET_H__


//找回密码界面的所有功能的调用
void forget_func(int *func);
//判断是否可以更改新密码
int forgetpass_match(char* u, char* tel, char* password);
//判断账号与身份证是否匹配 判断两次输入的密码是否相同 若匹配且相同则写入新密码
int name_id(char* name, char* tel, char* password);
//绘制找回密码界面
void draw_forget(void);

#endif