// library management system
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct std
{
int sno;
float code;
char bookname[100];
char author[100];
struct std *prev,*next;
};
int c=0;
struct std *head;
struct std *temp,*temp1,*del;
void delete()
{
del=temp1;
temp1=temp1->prev;
temp1->next=NULL;
free(del);
printf("\n\t\tDeletion Succesfully\n");
}
void display()
{
int i;
temp=head;
printf("\n|Display\n");
printf("|si No| ");
printf("|book Name| ");
printf("|author |");
printf("|book code| ");
printf("\n");
while(temp!=NULL)
{
	printf("|%d ",temp->sno);
printf("|%s ",temp->bookname);
printf("|%s ",temp->author);
printf("|%f |\n",temp->code);
temp=temp->next;
}
}
void insert()
{
struct std *ptr;
int s;
float c;
char n[100];
char a[100];
ptr = (struct std*)malloc(sizeof(struct std));
printf("\nEnter si.no:");
scanf("%d",&s);
printf("\nEnter book Name:");
scanf("%s",n);
printf("\nEnter author Name:");
scanf("%s",a);
printf("\nEnter book code:");
scanf("%f",&c);
if(head==NULL)
{
head=ptr;
ptr->prev=NULL;
ptr->next=NULL;
strcpy(ptr->bookname,n);
strcpy(ptr->author,a);
ptr->sno=s;
ptr->code=c;
display();
temp1=head;
c=c+1;
}
else
{
ptr->next=NULL;
strcpy(ptr->bookname,n);
strcpy(ptr->author,a);
ptr->sno=s;
ptr->code=c;
temp1->next=ptr;
ptr->prev=temp1;
temp1=ptr;
c=c+1;
display();
}
}

void search()
{
int i,r=0,flag=0;
printf("\nInput si.no or book code to find : ");
scanf("%d",&r);
printf("\n\n");
temp=head;
while(temp!=NULL)
{
	
if(temp->sno==r||temp->code==r)
{
flag=1;
break;
}
temp=temp->next;
}
if(flag==1)
{
printf("\n\nbook available\n");
printf("\ si no: %d ",temp->sno);
printf("book Name : %s ",temp->bookname);
printf(" author : %s ",temp->author);
printf("\nbookcode : %f\n ",temp->code);
}
else
{
printf("\nbook not available\n");
}
}
int main()
{
int i,opt=10;
printf("Enter: 1.Insert, 2.delete, 3.Display, 4.Search, 0.Exit\n");
while(opt!=0){
printf("Enter your operation : ");
scanf("%d",&opt);
switch(opt){
case 1 : {
insert();
break;
}
case 2:
	{
		delete();
		break;
	}
case 3 : {
display();
break;
}
case 4 : {
search();
break;
}
case 0 : {
break;
}
default : {
printf("Enter a valid number\n");
break;
}
}
}
}