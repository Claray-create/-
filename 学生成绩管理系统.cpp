#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	char no[8];//8λѧ��
	char name[20];//����
	int price;//�ɼ� 
 } Student;
 
typedef struct LNode
{
	Student date;//������ 
	struct LNode *next;//ָ���� 
}LNode;

void Initlist(LNode *&L)//�����ձ� 
{
	L=(LNode *)malloc(sizeof(LNode)) ;
	L->next=NULL;
}

void Insert(LNode *&L,Student student)//�������ѧ������Ϣ
{
	LNode *p=(LNode *)malloc(sizeof(LNode));
	p->date=student;
	p->next=L->next;
	L->next=p;
 } 
 

void show(LNode *&L)//�����ʾѧ����������ѧ���������Ϣ 
{
	LNode *p=L->next;
	while(p!=NULL)
	{
		printf("ѧ��:%s,����:%s,�ɼ�:%d\n",p->date.no,p->date.name,p->date.price);
		p=p->next;
	}
 }


void PInsert(int pos,LNode *&L,Student student)//����һ��ѧ������Ϣ�����뵽����ָ����λ�� 
{
	if(pos<0)
	{
		printf("�����ڸò���λ��\n");
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
			printf("����ɹ�\n");
			return; 
		}
		p=p->next;
	}
	printf("�����ڸò���λ��\n");
 } 
 
 void Delete(int pos,LNode *&L)//ɾ��ָ��λ�õ�ѧ����Ϣ
{
	if(pos<1)
	{
		printf("�����ڸ�λ�ã�ɾ��ʧ��");
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
	   	     	printf("ɾ���ɹ�\n");
	   	     	return;
			}
			pre=p;
			p=p->next;
	   }
	   printf("�����ڸ�λ�ã�ɾ��ʧ��\n");
	   
 } 
 
 
int Count(LNode*&L)//ͳ�Ʊ���ѧ������ 
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
 
 
void find(LNode *&L,char name[])//�����������в��ң����ش�ѧ���ĳɼ� 
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
	printf("���޴���\n"); 
}


void search(LNode *&L,char no[])//����ѧ�ţ����ش�ѧ���ĳɼ� 
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
	printf("ϵͳ���޸�ѧ��\n"); 
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
	puts("1)��ʼ��һ��ѧ���ɼ���Ϣ��������ָ��ѧ���������������ѧ����Ϣ������ʾ�������Ϣ��");
	puts("2)����һ��ѧ������Ϣ�����뵽����ָ����λ�á�");
	puts("3)ɾ��ָ��λ�õ�ѧ����Ϣ��");
	puts("4)ͳ�Ʊ���ѧ���ĸ���,�������ʾ������"); 
	puts("5)�����ɵ͵������У�����ʾѧ�������Ͷ�Ӧ�ķ�����") ;
	puts("6)�����������в��ң����ش�ѧ���ĳɼ���") ;
	puts("7)����ѧ�Ž��в��ң����ش�ѧ���ĳɼ���") ;
	puts("0)�˳�");
	puts("");
	
	do{
		printf("�밴�˵�����ѡ��(0-7)��");
		type=getint();
		switch(type)
		{
			case 0: run=0;Destroy(h);break;
			case 1:  //������������ѧ����Ϣ,����ʾ�������Ϣ 
			     Initlist(h);
			     printf("����ָ��ѧ��������\n");
				 n=getint();
				 printf("��Ӵ�С����ѧ��\n"); 
				 for(i=0;i<n;i++)
				 {
				 	printf("ѧ�ţ�");
				 	gets(stu.no);
				 	printf("����: ");
				 	gets(stu.name);
				 	printf("�ɼ���");
					stu.price=getint();
					Insert(h,stu);
				  } 
				  show(h);
				  break;
			case 2: //����һ��ѧ������Ϣ�����뵽����ָ����λ��
			    printf("����Ҫ�����ѧ����Ϣ\n");
					printf("ѧ�ţ�");
				 	gets(stu.no);
				 	printf("����: ");
				 	gets(stu.name);
				 	printf("�ɼ���");
					stu.price=getint();
				printf("����Ҫ�����λ�ã�");
				    pos=getint();
					PInsert(pos,h,stu);
					break;
			case 3://ɾ��ָ��λ�õ�ѧ����Ϣ
			    printf("����Ҫɾ����ѧ����λ��\n");
			    pos=getint();
			    Delete(pos,h);
			    break;
			case 4://ͳ�Ʊ���ѧ���ĸ���,�������ʾ����
			    printf("����%d��ѧ����¼\n",Count(h));
			    show(h);
			    break;
			case 5://�����ɵ͵������У�����ʾѧ�������Ͷ�Ӧ�ķ���
			    Sort(h);
			    show(h);
			    break;
			case 6://�����������в��ң����ش�ѧ���ĳɼ�
			    printf("����Ҫ���ҵ�ѧ����������");
			    gets(name);
			    find(h,name);
				break;
			case 7://����ѧ�Ž��в��ң����ش�ѧ���ĳɼ�
			    printf("����Ҫ���ҵ�ѧ����ѧ�ţ�");
			    gets(no);
			    search(h,no);
			    break;
		}
	}while(run);
}
