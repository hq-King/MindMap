#include"common.h"
#include"input.h"



/************************************************************************
FUNCTION:hz_input
DESCRIPTION: 汉字输入�?
INPUT:x1,x2,y1,y2,s,len,color
RETURN:汉字�?数len
************************************************************************/
int hz_input(int x1,int y1,int x2,int y2,char *s,int len,int color)
{
	int i;
	int ST=-1;//输入法返回方式：1.安SPACE�?返回输入汉字 2.按ENTER�?返回输入英文 3.退格键返回不输�?
	char *image;
	char *p=s+len;
	int value=0;
	int asc;
	int xx1=x1+2,xx2=x2-2;//防�?�输入溢�?
	int L_maxwords=(xx2-xx1)/8,maxline=(y2-y1)/30;
	int Line=len/L_maxwords+1,L_len=len%L_maxwords,pylen;    //当前所在�?�数Line（按0行开始�?�数�? 该�?�长�? L_len  pylen拼音长度 //行�??30像素
	int barx1,barx2,bary1,bary2;
	char str[3]={'\0','\0','\0'};//一�?汉字装入
	char py[12]={'\0','\0','\0','\0','\0','\0','\0','\0',
	            '\0','\0','\0','\0'};//拼音字�?�串(西文字�?�串)
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	while(bioskey(1))//清除�?盘缓冲区  防�?��??输入
	{
		bioskey(0);
	}
	if((image=malloc(8241))==NULL)
	{
		closegraph();
		printf("error!,hz_input");
		getch();
		exit(1);
	}
	while(1)
	{
		if(kbhit())
		{
			clrmous(MouseX,MouseY);
			value=bioskey(0);
			/*特殊�?处理*/
		    switch(value)
			{
				case BACK:
					if(L_len==0&&Line>1)//换�?��?�理
					{
						L_len=L_maxwords;
						Line--;
					}
					else if(L_len<=0&&Line==1) break;//删除结束 无法删除
					if(*(p-1)>31&&*(p-1)<127)
					{
						setfillstyle(1,color);
						bar(xx1+L_len*8-8,y1+Line*30-28,xx1+L_len*8,y1+Line*30-2);
						p--;
						*p='\0';
						len--;
						L_len--;
					}
					else
					{
						setfillstyle(1,color);
						bar(xx1+L_len*8-16,y1+Line*30-28,xx1+L_len*8,y1+Line*30-2);
						p-=2;
						p[0]='\0';
						p[1]='\0';
						len-=2;
						L_len-=2;
					}
					break;
				case ENTER:
					*p='\0';
					free(image);
					return len;	//结束输入
			}
			/*进入汉字输入�?*/
			asc=value&0xff;
			if(asc>=97&&asc<=122)
			{
				barx1=(x1+L_len*8-50>0)?(x1+L_len*8-50):0;       //计算输入法位�?  离所输入距�?�较近且不溢出屏�?
	    		barx2=(barx1+200<630)?(barx1+200):(barx1=430,630);
				bary1=y1+Line*30+10;
				bary2=(bary1+40<480)?(bary1+40):(bary1=y1+Line*30-80,bary1+40);
				getimage(barx1,bary1,barx2,bary2,image);
				pyFrm(barx1,bary1,barx2,bary2);
				setfillstyle(1,color);
				ST=input_method(barx1,bary1,str,value,py);
				switch(ST)
				{
					case 1://由数字键或空格键退出输入法  输入汉字
					    if(strlen(str))//返回字�?�串�?能为�?
						{
							if(L_len+1>=L_maxwords&&Line<maxline)//换�?�输�?
							{
								/*用空格来�?补不足位，跳�?到下一�?*/
								if(L_len+1==L_maxwords)
								{
									*p=' ';
									p++;
									len++;
								}
								Line++;
								L_len=0;
							}
							else if((L_len+1>=L_maxwords&&Line==maxline)||Line>maxline)//无法输入
							{
								putimage(barx1,bary1,image,0);
								break;
							}
							strcpy(p,str);
							puthz(xx1+L_len*8,y1+Line*30-23,str,16,16,DARKGRAY);
							p+=2;
					    	len+=2;
							L_len+=2;
						}
						putimage(barx1,bary1,image,0);
					    break;
					case 2://由回车键退出输入法 （键入西文）
						pylen=strlen(py);
					    if((L_len+pylen>L_maxwords&&Line==maxline)||(Line>maxline))//位置已满
						{
							putimage(barx1,bary1,image,0);
							break;
						}
						else if(L_len+pylen>L_maxwords&&Line<maxline)//该�?�已�? 换�??
						{
							for(i=0;i<L_maxwords-L_len;i++)
							{
								p[i]=' ';
							}
							p+=L_maxwords-L_len;
							len+=L_maxwords-L_len;
							Line++;
							L_len=0;
						}
						putimage(barx1,bary1,image,0);
						setcolor(DARKGRAY);
						xouttextxy(xx1+L_len*8,y1+Line*30-21,py,DARKGRAY);
						strcpy(p,py);
						len+=pylen;
						p+=pylen;
						L_len+=pylen;
					    break;
					case 3://西文删除�?0�?动退出输入法  不输�?
						putimage(barx1,bary1,image,0);
					    break;
				}
				value=0;
				ST=-1;
			}
			else if(asc>31&&asc<127)//字�?�输�?
			{
				py[0]=asc;
				if(L_len+1<=L_maxwords&&Line<=maxline)//正常输入
				{
					*p=asc;
				}
				else if(Line+1<=maxline)//换�?�输�?
				{
					*p=' ';
					Line++;
					L_len=0;
				}
				else
				{
					continue;
				}
				p++;
				len++;
				setcolor(DARKGRAY);
				xouttextxy(xx1+L_len*8,y1+Line*30-21,py,DARKGRAY);
				L_len++;
			}
			memset(py,'\0',12);
			memset(str,'\0',3);
		}
		if((MouseX<x1||MouseX>x2||MouseY<y1||MouseY>y2)&&press)
		{
			*p='\0';
			free(image);
			return len;
		}
	}
}

/************************************************************************
FUNCTION:input_method
DESCRIPTION: 汉字输入法调�?
INPUT:x,y,str,value,py
RETURN:1:输出汉字�?2：输出字母；3：输出空�?
************************************************************************/
int input_method(int x,int y,char *str,int value,char *py)
{
	FILE *fp=NULL,*oldfp=NULL;
	int fJudge=FAIL;
	char *p=py;
	int trigger=1;//进入时触发输入标�?
	char temphz[5][3]={{'\0','\0','\0'},{'\0','\0','\0'},
	                   {'\0','\0','\0'},{'\0','\0','\0'},
					   {'\0','\0','\0'}},temp[3];
	int fposition=0;
	int hznow=0,hznum=0;
	int asc,i;
	int PyStartx=x+8,PyStarty=y+4;
	int HzStartx=x+8,HzStarty=y+22;
	char *ABpath=".\\pinyin\\";//汉�??拼音检索标准路�?
	char pypath[45]={".\\pinyin\\"};//汉�??拼音检索相对路�?
	settextjustify(LEFT_TEXT,CENTER_TEXT);

	while(1)
	{
		if(trigger||kbhit())//�?一次进入自动触�? 以后均需�?�?
		{
			clrmous(MouseX,MouseY);
			trigger=0;
			if(kbhit()) value=bioskey(0);
			asc=value&0xff;
			/*特殊按键处理*/
			switch(value)
			{
				case BACK:
					p--;
					*p='\0';
					if(py[0]=='\0')
					{
						if(oldfp) fclose(oldfp);
						if(fp) fclose(fp);
						return 3;
					}
					break;
				case SPACE:
					strcpy(str,temphz[hznow]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case ENTER:
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 2;
				case LASTLINE:
					if(fposition>=8)//接下来重定位文件指针前八�?字节（四�?汉字�?
					{
						fposition-=8;
					}
					break;
				case NEXTLINE:
					if(!feof(fp))//接下来重定位文件指针后八�?字节（四�?汉字�?
					{
						fposition+=8;
					}
					break;
				case LEFT://左移动一�?
					if(hznow)
					{
						hznow--;
					}
					else if(fposition>=8)//需要左换页
					{
						fposition-=8;
						hznow=3;
					}
					break;
				case RIGHT:
					if(hznow<hznum-1)//同左
					{
						hznow++;
					}
					else if(!feof(fp))
					{
						fposition+=8;
						hznow=0;
					}
					break;
					/*按数字键选中输入汉字*/
				case FIRST:
					strcpy(str,temphz[0]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case SECOND:
					strcpy(str,temphz[1]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case THIRD:
					strcpy(str,temphz[2]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case FOURTH:
					strcpy(str,temphz[3]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
			}
			/*输入字�?��?�理*/
			if(asc>31&&asc<127&&strlen(py)<MAXPY&&asc!='['&&asc!=']')    //有效输入时则复位
			{
				*p=asc;
				p++;
				fposition=0;
				hznow=0;
			}
			pyFrm(x,y,x+200,y+40);
			setfillstyle(1,WHITE);
			settextstyle(1,0,2);
			outtextxy(PyStartx,PyStarty,py);        //拼音字体
		    strcat(pypath,py);
		    strcat(pypath,".txt");
		    if(fJudge) //将当前文件指针保�? 同时关闭上一�?文件  为输入特殊字符准�?
			{
				if(oldfp)
				{
					fclose(oldfp);
				}
				oldfp=fp;
			}
		    if((fp=fopen(pypath,"r"))==NULL)//特殊字�?�存�?  保留上一�?文件检索结�?
		    {
		    	fJudge=FAIL;
		    	fp=oldfp;
			}
			else
			{
				fJudge=SUCCESS;
			}
			if(fp)
			{
				fseek(fp,fposition,SEEK_SET);
		  		for(i=0;i<5;i++)
		    	{
		    		fread(temphz[i],2,1,fp);//读入一�?汉字
		    		if(feof(fp))//读到文件�?
		    		{
		    			hznum=i;//按道理�?��?�文件尾多�?�一�? 需要减一  然而�?��?�不减一的效果更�?
		    			break;
					}
				}
				if(!feof(fp))//�?读到文件�? 全显汉字
				{
					hznum=4;
				}
				for(i=0;i<hznum;i++)
				{
					setcolor(BLUE);
                    settextstyle(1,0,2);
		   		    xouttextxy(HzStartx+i*50,HzStarty+5,itostr(i+1,temp),DARKGRAY);
    				puthz(HzStartx+i*50+16,HzStarty,temphz[i],16,16,DARKGRAY);
				}
				puthz(HzStartx+hznow*50+16,HzStarty,temphz[hznow],16,16,CYAN);//显示选中汉字
			}
		}
		strcpy(pypath,ABpath);          //绝�?�路径�?�原（不�?少）
		value=0;
	}
}

/************************************************************************
FUNCTION:itostr
DESCRIPTION: 数字标号
INPUT:a,s
RETURN:数字s
************************************************************************/
char *itostr(int a,char *s)
{
	switch(a)
	{
		case 1:
			strcpy(s,"1.");
			return s;
		case 2:
			strcpy(s,"2.");
			return s;
		case 3:
			strcpy(s,"3.");
			return s;
		case 4:
			strcpy(s,"4.");
			return s;
	}
	return s;
}

/************************************************************************
FUNCTION:pyFrm
DESCRIPTION: 输入法小�?
INPUT:x1,y1,x2,y2
RETURN:�?
************************************************************************/
void pyFrm(int x1,int y1,int x2,int y2)
{
	setfillstyle(1,WHITE);
	bar(x1,y1,x2,y2);
	setcolor(BLUE);
	setlinestyle(0,0,1);
	line(x1+5,y1+20,x2-5,y1+20);
	setcolor(DARKGRAY);
	rectangle(x1,y1,x2,y2);
}
/************************************************************************
FUNCTION:xouttextxy
DESCRIPTION: 字�?�输入法
INPUT:x,y,s,color
RETURN:字�?�长�?len
************************************************************************/
int xouttextxy(int x,int y,char *s,int color)//8x16点阵字库
{
	FILE *asc=NULL;
	int i,j,k;
	char *mat,*temp;
	int len;
	long offset;
	int mask;

	len=strlen(s);
	if(!len) return 0;//空字符串不执行操�?
	if((asc=fopen(".\\TEST\\HZK\\ASC16","rb"))==NULL)
	{
		closegraph();
		printf("outtextxy can't open asc16!,xouttextxy");
		delay(3000);
		exit(1);
	}
	if((mat=(char *)malloc(16*sizeof(char)*len))==NULL)//存放点阵
	{
		closegraph();
		printf("Failed!,xouttextxy");
		fclose(asc);
		getch();
		exit(1);
	}
	temp=mat;
	for(i=0;i<len;i++)
	{
		offset=(long)16*s[i];//计算字�?�的文件偏移
		fseek(asc,offset,SEEK_SET);
		fread(temp,sizeof(char),16,asc);//将所有字符点阵存�?mat
		temp+=16;
	}
	fclose(asc);
	for(i=0;i<len;i++)//通过放点显示字�??
	{
		for(j=0;j<16;j++)
		{
			mask=0x80;
			for(k=0;k<8;k++)
			{
				if(mat[i*16+j]&mask)
				putpixel(x+8*i+k,y+j,color);
				mask>>=1;
			}
		}
	}
	free(mat);
	return len;
}

/************************************************************************
FUNCTION:hz_int
DESCRIPTION: 汉字字�?�换行显�?
INPUT:x1,y2,x2,y2,s,color
RETURN:�?
************************************************************************/
void hz_int(int x1,int y1,int x2,int y2,char *s,int color)
{
	int len=0;
	int xx1=x1+2,xx2=x2-2;
	int L_maxwords=(xx2-xx1)/8,maxline=(y2-y1)/30;
	int Line=len/L_maxwords+1,L_len=len%L_maxwords;   
	char str[3]={'\0','\0','\0'};
	char py[2]={'\0','\0'};
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	while(*s!='\0')
	{
		if(*s!='\0')
		{
			if(*s>=33&&*s<=122)
			{
				py[0]=*s;
				s++;
			}
			else 
			{
				str[0]=*s;
				s++;
				str[1]=*s;
				s++;
				str[2]='\0';
			}
		}
		if(L_len+1>=L_maxwords&&Line<maxline)
		{
			if(L_len+1==L_maxwords)
			{
				len++;
			}
			Line++;
			L_len=0;
		}
		if(strlen(str))
		{

			if((L_len+1>=L_maxwords&&Line==maxline)||Line>maxline)
			{
				break;
			}
			puthz(xx1+L_len*8,y1+Line*30-23,str,16,16,color);
			len+=2;
			L_len+=2;
			memset(str,'\0',3);
		}
		if(strlen(py))
		{
			if(Line+1<=maxline&&L_len+1>=L_maxwords)
			{
				Line++;
				L_len=0;
			}
			len++;
			setcolor(color);
			xouttextxy(xx1+L_len*8,y1+Line*30-21,py,color);
			L_len++;
			memset(py,'\0',2);
		}
	}
}