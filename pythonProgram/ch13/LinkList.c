   /*******************************************************************
	> File Name: LinkList.c
    > Author: guoxiaoming
    > Mail: wuxinliulei@gmail.com 
    > Created Time: 2014年03月23日 星期日 01时05分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
//采用头插法建立具有head节点的单链表
typedef struct node{
   int data;
   struct node * next;
}LinkList;
LinkList * head;

LinkList * creatLinkList(){
	int data;
	LinkList *head, *p;
	head = (LinkList *)malloc(sizeof(LinkList));
	head->next = NULL;
	printf("请输入数据直到输入0结束:\n");
	scanf("%d",&data);
	while(data != 0){
		p = (LinkList *)malloc(sizeof(LinkList));
		p->data = data;
		p->next = head->next;
		head->next = p;
		scanf("%d",&data);
	}
	return head;
}

//打印函数
void printLinkList(LinkList *head){
	LinkList *q = head->next;
	while(q!= NULL){
		printf("%d ",q->data);
		q = q->next;
	}
}

//插入数据到指定结点后面 
int  insertLinkList(LinkList * head,int goal, int data){
	LinkList * q = head->next;
	while(q->data != goal && q->next != NULL){
		q = q->next;
	}
	if(q->next == NULL){
		return 0;
	}
	else
	{
		LinkList * temp;
		temp = (LinkList *)malloc(sizeof(LinkList));
		temp->data = data;
		temp->next = q->next;
		q->next = temp;
		return 1;
	}
}


int deleteLinkList(LinkList *head,int data){
	LinkList *q = head->next;
	LinkList *p = head;
    while(q != NULL){
		if(data == q->data){
			break;
		}
		p = p->next;
		q = q->next;
	}
	if(q == NULL) return 0;
	else{
		//显然要删除q节点
		p->next = q->next;
		free(q);
		return 1;
	}
}

void usage(){
	printf("\n\n请输入您要做的选择：\n1:创建链表\n2:打印链表\n3:插入数据到指定节点\n4:删除数据\n5:结束程序\n");
}


int main(){
   LinkList * head;
   int choice;
   usage();
   scanf("%d",&choice);
   while(1){
	   if(1 == choice)
	   {
		  head = creatLinkList();
		  usage();
		  scanf("%d",&choice);
		  continue;
	   }
	   else if(2 == choice)
	   {
		  printLinkList(head);
		  usage();
		  scanf("%d",&choice);
		  continue;
	   }
	   else if(3 == choice)
	   {
		  printf("插入前的数据：\n");
		  printLinkList(head);
		  printf("\n请依次输入要插入的数据和插入的指定节点：");
		  int goal,data;
		  scanf("%d %d",&data,&goal);
		  int result = insertLinkList(head,goal,data);
		  if(result){
			  printf("插入成功！\n");
			  printLinkList(head);
		  }else{
			  printf("插入失败！你输入的节点不存在！");
		  }
		  usage();
		  scanf("%d",&choice);
	   }
	   else if(4 == choice){
		  int data;
		  printf("删除前的数据：\n");
		  printLinkList(head);
		  printf("\n");
		  printf("请输入要删除的数据：");
		  scanf("%d",&data);
		  int result = deleteLinkList(head,data);
		  if(result){
			  printf("删除成功！\n");
			  printLinkList(head);
		  }else{
			  printf("删除失败！不存在你要删除的节点！");
		  }
		  usage();
		  scanf("%d",&choice);
	   }
	   else if(5 == choice)
	   {
		   break;
	   }
   };
   return 0;
}
