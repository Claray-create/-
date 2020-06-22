#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	char no[8];//8位学号
	char name[20];//姓名
	int price;//成绩 
 } Student;
 
typedef struct LNode
{
	Student date;//数据域 
	struct LNode *next;//指针域 
}LNode;

void Initlist(LNode *&L)//建立空表 
{
	L=(LNode *)malloc(sizeof(LNode)) ;
	L->next=NULL;
}

void Insert(LNode *&L,Student student)//逐个输入学生的信息
{
	LNode *p=(LNode *)malloc(sizeof(LNode));
	p->date=student;
	p->next=L->next;
	L->next=p;
 } 
 

void show(LNode *&L)//逐个显示学生表中所有学生的相关信息 
{
	LNode *p=L->next;
	while(p!=NULL)
	{
		printf("学号:%s,姓名:%s,成绩:%d\n",p->date.no,p->date.name,p->date.price);
		p=p->next;
	}
 }


void PInsert(int pos,LNode *&L,Student student)//给定一个学生的信息，插入到表中指定的位置 
{
	if(pos<0)
	{
		printf("不存在该插入位置\n");
		return;
	}
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->date=student;
	LNode *p=L;
	int i=-1;
	while(p!=NULL)
	{
		i++;
		if(i==pos-1)
		{
			s->next=p->next;
			p->next=s;
			printf("插入成功\n");
			return; 
		}
		p=p->next;
	}
	printf("不存在该插入位置\n");
 } 
 
 void Delete(int pos,LNode *&L)//删除指定位置的学生信息
{
	if(pos<1)
	{
		printf("不存在该位置，删除失败");
		return; 
	}
	   LNode *pre=L,*p=pre->next;
	   int i=0;
	   while(p!=NULL)
	   {
	   	     i++;
	   	     if(i==pos)
	   	     {
	   	     	pre->next=p->next;
	   	     	free(p);
	   	     	printf("删除成功\n");
	   	     	return;
			}
			pre=p;
			p=p->next;
	   }
	   printf("不存在该位置，删除失败\n");
	   
 } 
 
 
int Count(LNode*&L)//统计表中学生个数 
{
	LNode *p=L->next;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
 
 
void Sort(LNode *&L)
{
	LNode *pre,*p,*tail,*temp;
	tail=NULL;
	pre=L;
	while((L->next)!=tail)
	{
		p=L->next;
		pre=L;
		while(p->next!=tail)
		{
			if((p->date.price)>(p->next->date.price))
			{
				pre->next=p->next;
				p->next=p->next->next;
				pre->next->next=p;
				p=pre->next;
			}
			p=p->next;
			pre=pre->next;
		}
		tail=p;
	}
}
 
 
void find(LNode *&L,char name[])//根据姓名进行查找，返回此学生的成绩 
{
	LNode *p=L->next;
	while(p!=NULL)
	{
		if(strcmp(p->date.name,name)==0)
		{
			printf("%d\n",p->date.price);
			return;
		}
		p=p->next;
	}
	printf("查无此人\n"); 
}


void search(LNode *&L,char no[])//根据学号，返回此学生的成绩 
{
	
	LNode *p=L->next;
	while(p!=NULL)
	{
		if(strcmp(p->date.no,no)==0)
		{
			printf("%d\n",p->date.price);
			return;
		}
		p=p->next;
	}
	printf("系统中无该学号\n"); 
}



void Destroy(LNode *&L)
{
	LNode *pre=L,*p=L->next;
	while(p!=NULL)
	{
		free(pre);
		pre=p;
		p=pre->next;
	}
	free(pre);
}

int getint()
 {
 	char s[10];
 	gets(s);
 	return atoi(s);
  } 

int main()
{
	LNode *h=NULL;
	int n,i,pos,type,run=1;
	char no[8];
	char name[20];
	Student stu;
	puts("1)初始化一个学生成绩信息链表，根据指定学生人数，逐个输入学生信息，并显示输入的信息。");
	puts("2)给定一个学生的信息，插入到表中指定的位置。");
	puts("3)删除指定位置的学生信息。");
	puts("4)统计表中学生的个数,并逐个显示出来。"); 
	puts("5)分数由低到高排列，并显示学生姓名和对应的分数。") ;
	puts("6)根据姓名进行查找，返回此学生的成绩。") ;
	puts("7)根据学号进行查找，返回此学生的成绩。") ;
	puts("0)退出");
	puts("");
	
	do{
		printf("请按菜单进行选择(0-7)：");
		type=getint();
		switch(type)
		{
			case 0: run=0;Destroy(h);break;
			case 1:  //建立链表，输入学生信息,并显示输入的信息 
			     Initlist(h);
			     printf("输入指定学生人数：\n");
				 n=getint();
				 printf("请从大到小输入学号\n"); 
				 for(i=0;i<n;i++)
				 {
				 	printf("学号：");
				 	gets(stu.no);
				 	printf("姓名: ");
				 	gets(stu.name);
				 	printf("成绩：");
					stu.price=getint();
					Insert(h,stu);
				  } 
				  show(h);
				  break;
			case 2: //给定一个学生的信息，插入到表中指定的位置
			    printf("输入要插入的学生信息\n");
					printf("学号：");
				 	gets(stu.no);
				 	printf("姓名: ");
				 	gets(stu.name);
				 	printf("成绩：");
					stu.price=getint();
				printf("输入要插入的位置：");
				    pos=getint();
					PInsert(pos,h,stu);
					break;
			case 3://删除指定位置的学生信息
			    printf("输入要删除的学生的位置\n");
			    pos=getint();
			    Delete(pos,h);
			    break;
			case 4://统计表中学生的个数,并逐个显示出来
			    printf("共有%d个学生记录\n",Count(h));
			    show(h);
			    break;
			case 5://分数由低到高排列，并显示学生姓名和对应的分数
			    Sort(h);
			    show(h);
			    break;
			case 6://根据姓名进行查找，返回此学生的成绩
			    printf("输入要查找的学生的姓名：");
			    gets(name);
			    find(h,name);
				break;
			case 7://根据学号进行查找，返回此学生的成绩
			    printf("输入要查找的学生的学号：");
			    gets(no);
			    search(h,no);
			    break;
		}
	}while(run);
}
