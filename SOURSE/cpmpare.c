#include"common.h"
#include "compare.h"
#include "func.h"
#include "input.h"
#include "popup.h"
#include "file.h"
#include "save.h"
#include "USER.h"
#include"mpfunc.h"
#include"menufunc.h"


/*************************************************************
函数名：void drwa_input_compare
参数:	无
返回值：无
函数功能：绘制对比模式
**************************************************************/
void draw_input_compare()
{
	cleardevice();
	setbkcolor(WHITE);
    puthz(242,4,"对比模式",24,30,BLUE);
    puthz(30,40,"事物一",16,20,BLUE);
    puthz(350,40,"事物二",16,20,BLUE);
    setcolor(RED);
    outtextxy(92,45,":");
    outtextxy(412,45,":");
    
    setfillstyle(SOLID_FILL,WHITE);
    bar(118,33,200,63);
    bar(438,33,520,63);
    setfillstyle(SOLID_FILL,LIGHTCYAN);
    bar(30,88,130,118);
    puthz(32,96,"添加相同点",16,20,BLUE);
    setcolor(YELLOW);
    rectangle(30,88,130,118);

    bar(30,268,130,298);
    puthz(32,274,"添加不同点",16,20,BLUE);
    setcolor(YELLOW);
    rectangle(30,268,130,298);

    
    bar(30,440,75,470);
    puthz(35,447,"绘制",16,20,BLUE);
    setcolor(YELLOW);
    rectangle(30,440,75,470);

    setcolor(RED);
    rectangle(580,10,630,40);
    puthz(585,15,"返回",16,20,BLUE);
    puthz(185,250,"事物一",16,20,BLUE);
    puthz(185,360,"事物二",16,20,BLUE);

    setcolor(RED);
    rectangle(118,33,260,63);
    rectangle(438,33,560,63);

    bar(30,400,75,430);
    puthz(35,407,"保存",16,20,BLUE);
    setcolor(YELLOW);
    rectangle(30,400,75,430);

    puthz(10,335,"文件名",16,20,GREEN);
    setcolor(GREEN);
    rectangle(10,360,160,390);




}



/*************************************************************
函数名：void Compare_func(int *func, USER *u,struct mpdata *mp,int tate)
参数:	界面跳转判断值func，用户指针，结构体指针,用户与游客判断值
返回值：无
函数功能：对比功能调用
**************************************************************/
void comparefunc(int *func,USER *u,struct comparedata *CMP ,int tate)
{
	int i =1; 
    int fun;
    int num1=0;
    int jud1=0;
    int jud2=0;
    int click1=0;
    int click2=0;
    char file[20];
    //相同点、1事物不同点、2事物不同点的计数变量
    
    File allfile[FILEMAX];
    (*CMP).si_num=0;
    (*CMP).dif1_num=0;
    (*CMP).dif2_num=0;
    //初始化
    draw_input_compare();
    

    
    setfillstyle(SOLID_FILL,LIGHTCYAN);
    
    for(i=0;i<FILEMAX;i++)
		{
			memset(&allfile[i],'\0',sizeof(File));
		}
    if(u->history!= 0)
    {
        Output_Filemenu(allfile, u->user);
    } 
    while(1)
    {

        newmouse(&MouseX,&MouseY,&press);
        //添加事物相同点一
    if(MouseX > 30 && MouseX <130 && MouseY >88 && MouseY <118)
    {
        if(mouse_press(30,88,130,118) == 1)
        {
            delay(500);
            (*CMP).si_num++;
            setfillstyle(SOLID_FILL,LIGHTCYAN);
            bar(170,120,270,160);
            bar(310,120,410,160);                                     
            bar(450,120,550,160 );            
            bar(170,190,270,230);               
            bar(310,190,410,230);
            bar(450,190,550,230);
            
        }

        if(mouse_press(30,88,130,118) == 2)
        {
            MouseS = 1;
            continue;
        }
    
    }


      //添加事物不同点
    if(MouseX > 30 && MouseX <130 && MouseY >268 && MouseY <298)
    {
        if(mouse_press(30,268,130,298) == 1)
        {
            (*CMP).dif1_num++;
		    (*CMP).dif2_num++;
            delay(500);
            setfillstyle(SOLID_FILL,LIGHTCYAN);
           //事物一
                bar(170,280,270,310);
                bar(170,390,270,420);  
                bar(310,280,410,310);  
                bar(310,390,410,420);       
                bar(450,280,550,310 ); 
                bar(450,390,550,420 );   
                bar(170,320,270,350);   
                bar(170,430,270,460);  
                bar(310,320,410,350);
                bar(310,430,410,460);                                                      
                bar(450,320,550,350);               
                bar(450,430,550,460);                                       
        }

        if(mouse_press(30,268,130,298) == 2)
        {
            MouseS = 1;
            continue;
        }
    
    }

    if( (*CMP).si_num == 1 && mouse_press(170,120,270,160)==1)
    {
        clrmous(MouseX,MouseY);
        Light_Compare(170,120,270,160,BLUE,LIGHTCYAN);
        strcpy((*CMP).similar[0],"\0");
        hz_input(170,120,270,160,(*CMP).similar[(*CMP).si_num-1],0,LIGHTCYAN); 
        if(strlen((*CMP).similar[0])!=0)   
        {
             (*CMP).si_num++;
        }
        continue;
    }

    if( (*CMP).si_num == 2&& mouse_press(310,120,410,160)==1)
    {
        clrmous(MouseX,MouseY);
        Light_Compare(310,120,410,160,BLUE,LIGHTCYAN);
        strcpy((*CMP).similar[1],"\0");
        hz_input(310,120,410,160,(*CMP).similar[(*CMP).si_num-1],0,LIGHTCYAN);
        if(strlen((*CMP).similar[1])!=0)   
        {
             (*CMP).si_num++;
        }
        continue;
    }

    if( (*CMP).si_num == 3&& mouse_press(450,120,550,160)==1)
    {
        clrmous(MouseX,MouseY);
        Light_Compare(450,120,550,160,BLUE,LIGHTCYAN);
        strcpy((*CMP).similar[2],"\0");
        hz_input(450,120,550,160,(*CMP).similar[(*CMP).si_num-1],0,LIGHTCYAN);
        if(strlen((*CMP).similar[2])!=0)   
        {
             (*CMP).si_num++;
        }
        continue;
    }

    if( (*CMP).si_num == 4&& mouse_press(170,190,270,230)==1)
    {
        clrmous(MouseX,MouseY);
        Light_Compare(170,190,270,230,BLUE,LIGHTCYAN);
        strcpy((*CMP).similar[3],"\0");
        hz_input(170,190,270,230,(*CMP).similar[(*CMP).si_num-1],0,LIGHTCYAN);
        if(strlen((*CMP).similar[3])!=0)   
        {
             (*CMP).si_num++;
        }
		continue;
	}

	if( (*CMP).si_num == 5&& mouse_press(310,190,410,230)==1)
	{
        clrmous(MouseX,MouseY);
		Light_Compare(310,190,410,230,BLUE,LIGHTCYAN);
		strcpy((*CMP).similar[4],"\0");
		hz_input(310,190,410,230,(*CMP).similar[(*CMP).si_num-1],0,LIGHTCYAN);
		if(strlen((*CMP).similar[4])!=0)   
        {
             (*CMP).si_num++;
        }
		continue;
	}

	if( (*CMP).si_num == 6 && mouse_press(450,190,550,230)==1)
	{
        clrmous(MouseX,MouseY);
		Light_Compare(450,190,550,230,BLUE,LIGHTCYAN);
		strcpy((*CMP).similar[5],"\0");
		hz_input(450,190,550,230,(*CMP).similar[(*CMP).si_num-1],0,LIGHTCYAN);
		if(strlen((*CMP).similar[5])!=0)   
        {
             (*CMP).si_num++;
        }
		continue;
    }


        //事件一
    if(MouseX > 118 && MouseX < 260 && MouseY > 33 && MouseY <80)
    { 
        if(mouse_press(118,33,260,63) == 1)
        {
            clrmous(MouseX, MouseY);
			MouseS = 0;
            Light_Compare(118,33,260,63,RED,WHITE);
            strcpy((*CMP).theme[0],"\0");
		    hz_input(118,33,260,63,(*CMP).theme[0],0,WHITE);
            continue;

        }

        if(mouse_press(118,33,260,63) == 2)
        {
                MouseS = 1;
                continue;
        }

    }       

    if( (*CMP).dif1_num == 1 && mouse_press(170,280,270,310)==1)
    {
        clrmous(MouseX,MouseY);
        Light_Compare(170,280,270,310,BLUE,LIGHTCYAN);
        strcpy((*CMP).differ1[0],"\0");
        hz_input(170,280,270,310,(*CMP).differ1[(*CMP).dif1_num-1],0,LIGHTCYAN); 
        if(strlen((*CMP).differ1[0])!=0)   
        {
            (*CMP).dif1_num++;
        } 
        continue;
    }

    if( (*CMP).dif1_num == 2&& mouse_press(310,280,410,310)==1)
    {
        clrmous(MouseX,MouseY);
        Light_Compare(310,280,410,310,BLUE,LIGHTCYAN);
        strcpy((*CMP).differ1[1],"\0");
        hz_input(310,280,410,310,(*CMP).differ1[(*CMP).dif1_num-1],0,LIGHTCYAN);
        if(strlen((*CMP).differ1[1])!=0)   
        {
            (*CMP).dif1_num++;
        } 
        continue;
    }

    if( (*CMP).dif1_num == 3&& mouse_press(450,280,550,310 )==1)
    {
        clrmous(MouseX,MouseY);
        Light_Compare(450,280,550,310,BLUE,LIGHTCYAN);
        strcpy((*CMP).differ1[2],"\0");
        hz_input(450,280,550,310 ,(*CMP).differ1[(*CMP).dif1_num-1],0,LIGHTCYAN);
        if(strlen((*CMP).differ1[2])!=0)   
        {
            (*CMP).dif1_num++;
        } 
        continue;
    }

    if( (*CMP).dif1_num == 4&& mouse_press(170,320,270,350)==1)
    {
        clrmous(MouseX,MouseY);
        Light_Compare(170,320,270,350,BLUE,LIGHTCYAN);
        strcpy((*CMP).differ1[3],"\0");
        hz_input(170,320,270,350,(*CMP).differ1[(*CMP).dif1_num-1],0,LIGHTCYAN);
        if(strlen((*CMP).differ1[3])!=0)   
        {
            (*CMP).dif1_num++;
        } 
        continue;
    }

    if( (*CMP).dif1_num == 5&& mouse_press(310,320,410,350)==1)
    {
        clrmous(MouseX,MouseY);
        Light_Compare(310,320,410,350,BLUE,LIGHTCYAN);
        strcpy((*CMP).differ1[4],"\0");
        hz_input(310,320,410,350,(*CMP).differ1[(*CMP).dif1_num-1],0,LIGHTCYAN);
        if(strlen((*CMP).differ1[4])!=0)   
        {
            (*CMP).dif1_num++;
        } 
        continue;
    }

    if( (*CMP).dif1_num == 6&& mouse_press(450,320,550,350)==1)
    {
        clrmous(MouseX,MouseY);
        Light_Compare(450,320,550,350,BLUE,LIGHTCYAN);
        strcpy((*CMP).differ1[5],"\0");
        hz_input(450,320,550,350,(*CMP).differ1[(*CMP).dif1_num-1],0,LIGHTCYAN);
        if(strlen((*CMP).differ1[5])!=0)   
        {
            (*CMP).dif1_num++;
        } 
        continue;
    }
        //事件二
        if(MouseX > 438 && MouseX < 560 && MouseY > 33 && MouseY <80)
        { 
            if(mouse_press(438,33,560,63) == 1)
            {
                clrmous(MouseX, MouseY);
			    MouseS = 0;
                Light_Compare(438,33,560,63,RED,WHITE);
                strcpy((*CMP).theme[1],"\0");
                hz_input(438,33,560,63,(*CMP).theme[1],0,WHITE);
                continue;
            }

            if(mouse_press(438,33,560,63) == 2)
            {
                MouseS = 1;
                continue;
            }

        }

        if( (*CMP).dif2_num == 1 && mouse_press(170,390,270,420)==1)
        {
            clrmous(MouseX,MouseY);
            Light_Compare(170,390,270,420,BLUE,LIGHTCYAN);
            strcpy((*CMP).differ2[0],"\0");
            hz_input(170,390,270,420,(*CMP).differ2[(*CMP).dif2_num-1],0,LIGHTCYAN); 
            if(strlen((*CMP).differ2[0])!=0)   
        {
            (*CMP).dif2_num++;
        }   
            continue;
        }

        if( (*CMP).dif2_num == 2 && mouse_press(310,390,410,420)==1)
        {
            clrmous(MouseX,MouseY);
            Light_Compare(310,390,410,420,BLUE,LIGHTCYAN);
            strcpy((*CMP).differ2[2],"\0");
            hz_input(310,390,410,420,(*CMP).differ2[(*CMP).dif2_num-1],0,LIGHTCYAN); 
             if(strlen((*CMP).differ2[1])!=0)   
        {
            (*CMP).dif2_num++;
        }      
            continue;
        }

        if((*CMP).dif2_num == 3 && mouse_press(450,390,550,420)==1)
        {
            clrmous(MouseX,MouseY);
            Light_Compare(450,390,550,420,BLUE,LIGHTCYAN);
            strcpy((*CMP).differ2[3],"\0");
            hz_input(450,390,550,420,(*CMP).differ2[(*CMP).dif2_num-1],0,LIGHTCYAN); 
            if(strlen((*CMP).differ2[2])!=0)   
        {
            (*CMP).dif2_num++;
        }   
            continue;
        }

        if( (*CMP).dif2_num == 4 && mouse_press(170,430,270,460)==1)
        {
            clrmous(MouseX,MouseY);
            Light_Compare(170,430,270,460,BLUE,LIGHTCYAN);
            strcpy((*CMP).differ2[4],"\0");
            hz_input(170,430,270,460,(*CMP).differ2[(*CMP).dif2_num-1],0,LIGHTCYAN); 
            if(strlen((*CMP).differ2[3])!=0)   
        {
            (*CMP).dif2_num++;
        }    
            continue;
        }

        if( (*CMP).dif2_num == 5 && mouse_press(310,430,410,460)==1)
        {
            clrmous(MouseX,MouseY);
            Light_Compare(310,430,410,460,BLUE,LIGHTCYAN);
            strcpy((*CMP).differ2[5],"\0");
            hz_input(310,430,410,460,(*CMP).differ2[(*CMP).dif2_num-1],0,LIGHTCYAN); 
             if(strlen((*CMP).differ2[4])!=0)   
        {
            (*CMP).dif2_num++;
        }     
            continue;
        }

        if( (*CMP).dif2_num == 6 && mouse_press(450,430,550,460)==1)
        {
            clrmous(MouseX,MouseY);
            Light_Compare(450,430,550,460,BLUE,LIGHTCYAN);
            strcpy((*CMP).differ2[6],"\0");
            hz_input(450,430,550,460,(*CMP).differ2[(*CMP).dif2_num-1],0,LIGHTCYAN); 
             if(strlen((*CMP).differ2[5])!=0)   
        {
            (*CMP).dif2_num++;
        }      
            continue;
        }

        if(MouseX > 580 && MouseX < 630 && MouseY >10 && MouseY <40)
        {
            if(mouse_press(580,10,630,40) == 1)
            {
                clrmous(MouseX , MouseY);
                cleardevice();
                delay(500);
                *func =3;
                return;
            }
            if(mouse_press(580,10,630,40) == 2)
            {
                MouseS = 1;
                continue;
            }
        }

        if(mouse_press(10,360,160,390)==1)
        {
            Light_Compare(10,360,160,390,BLUE,WHITE);
            clrmous(MouseX,MouseY);
            EnterFileName(file,10,360,7,WHITE);
            fun=Examine_Filename(u,allfile,file);
            continue;
        }

        if(mouse_press(30,400,75,430)==1)
        {
    
			if(fun == 1 || fun ==3)
            {
                if(tate != 0)
                {
				    u->history++;
                    Insert_filemenu(allfile, file, u->format, u->history);
                    //重新排序
				    Input_Cfiledata(u->user,(*CMP).theme,(*CMP).similar,(*CMP).differ1,(*CMP).differ2,(*CMP).si_num,(*CMP).dif1_num,(*CMP).dif2_num,file);
                    //存进文件
                    Input_history(u->user,u->history);
                    //修改收藏个数
				    Input_format(u->user, u->format);
                    Input_filemenu(allfile, u->user);
                    //存入文件
                    puthz(30,370,"保存成功",24,30,BLUE);
				    clrmous(MouseX,MouseY);
                    cleardevice();
                    *func = 11;
                    return;
                }
                if(tate == 0)
                {
                
                    MouseS = 0;
			        clrmous(MouseX,MouseY);
			        Popup_Func(11);
			        continue;
                }   
            }
            if(fun == 2)
            {
                    puthz(30,370,"文件存在",24,30,BLUE);
					delay(1500);
                    clrmous(MouseX,MouseY);
                    cleardevice();
                    *func = 11;
                    return;
            }
        }
    

        if(MouseX >30 && MouseX <75 && MouseY >440 &&MouseY <470)
        {
            if(mouse_press(30,440,75,470)==2)
            {
                MouseS = 1;
                continue;
            }

            if(mouse_press(30,440,75,470)==1)
            {
                clrmous(MouseX,MouseY);
                cleardevice();
               *func = 13;
                return;
            }
        }


        if(MouseS != 0)
        {
            MouseS = 0 ;
            continue;
        }

    }   
}



/*************************************************************
函数名：void Light_Compare(int x, int y, int x1, int y1, int color1, int color2)
参数:	框的坐标,颜色
返回值：无
函数功能：点亮文本框
**************************************************************/
void Light_Compare(int x, int y, int x1, int y1, int color1, int color2)
{
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	
	//画边框
}


/*************************************************************
函数名：void DRAW(int *func ,struct comparedata *CMP)
参数:	界面跳转值,结构体指针
返回值：无
函数功能：绘制对比模式
**************************************************************/
void DRAW(int *func ,struct comparedata *CMP)
            
{
    int i,j;
    int x=170;
    int y=225;
    int lx=x+100;
    int ly=y+30;
    setbkcolor(WHITE);
    setcolor(BLUE);
    setfillstyle(1,LIGHTCYAN);
    bar(x-30,y-10,lx-30,ly+10);
	bar(x+250-40,y-10,x+350-40,ly+10);
	put_all(x+5-25,y,(*CMP).theme[0],7,BLUE);
	put_all(x+250-40,y,(*CMP).theme[1],7,BLUE);
    rectangle(560,4,620,30);
    puthz(565,6,"返回",16,35,RED);
    
    
    for(i=0;i<(*CMP).dif1_num-1;i++)
    {
        bar(x-145,40+i*60+15,x-45,70+i*60+15);
        rectangle(x-145,40+i*60+15,x-45,70+i*60+15);
        line(x-45,((40+i*60+15)+(70+i*60+15))/2,140,240);
		put_all(x-145,40+i*60+15,(*CMP).differ1[i],7,RED);
    }
    for(i=0;i<(*CMP).dif2_num-1;i++)
    {
        bar(510,40+i*60+15,610,70+i*60+15);
        rectangle(510,40+i*60+15,610,70+i*60+15);
        line(510,((40+i*60+15)+(70+i*60+15))/2,480,240);
		put_all(510,40+i*60+15,(*CMP).differ2[i],7,RED);
    }

    for(i=0;i<(*CMP).si_num-1;i++)
    {
        bar(260,40+i*60+15,360,70+i*60+15);
        rectangle(260,40+i*60+15,360,70+i*60+15);
        line(260,((40+i*60+15)+(70+i*60+15))/2,240,240);
        line(360,((40+i*60+15)+(70+i*60+15))/2,380,240);
		put_all(260,40+i*60+15,(*CMP).similar[i],7,RED);
    }

    


    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);         
    if(MouseX > 560 && MouseX <620 && MouseY >4 && MouseY <30)
    {
        if(mouse_press(560,4,620,30)==1)
        {
            clrmous(MouseX,MouseY);
            delay(500);
            cleardevice();
			memset(CMP,'\0',sizeof(struct comparedata));
            *func = 3;
            return;
        }

        if(mouse_press(560,4,620,30)==2)
        {
            MouseS = 1;
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

/*************************************************************
函数名：void Input_Cfiledata( char *u , char theme[][18],char similar[][20],char differ1[][20]
                    ,char differ2[][20],int si_num,int dif1_num,int dif2_num,char *filename) 
参数:	用户结构体指针,主题,相同点，不同点数组，各自的个数
返回值：无
函数功能：存入文件
**************************************************************/
void Input_Cfiledata( char *u , char theme[][18],char similar[][20],char differ1[][20]
                    ,char differ2[][20],int si_num,int dif1_num,int dif2_num,char *filename)   

{
	int i,j;
	FILE *fp;
	char copath[50]= {"C:\\file\\"};
	char fpath[50]= {"C:\\file\\"};
	char fenge[5]={"\\"};
	  
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,filename);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,filename);
	strcat(fpath,".dat");
	if((fp = fopen(copath, "wb")) == NULL)
	{
		printf("can not open drawfile");
		delay(2000);
		exit(1);
	}
    fwrite(theme,2*18*sizeof(char),1,fp);
    fwrite(similar,6*20*sizeof(char),1,fp);
    fwrite(differ1,6*20*sizeof(char),1,fp);
    fwrite(differ2,6*20*sizeof(char),1,fp);
    

	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
	
	if((fp = fopen(fpath,"wb")) == NULL)
	{
		printf("can not open ffile");
		delay(2000);
		exit(1);
	}
		fwrite(&si_num,2,1,fp);
		fwrite(&dif1_num,2,1,fp);
        fwrite(&dif2_num,2,1,fp);
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
    fclose(fp);
}



