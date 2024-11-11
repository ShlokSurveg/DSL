#include<string.h>
#include<stdio.h>
int q[10];
int f= -1;
int r= -1;
int size=10;
int i;
int cq[10];
void AddQ()
{
 prinƞ("Enter the element to add to the queue \n");
 scanf("%d",&i);
if(isfull())
{
 prinƞ("Queue is full");
}
else
{

 r=r+1;
 q[r]=i;
}
}
int isfull()
{
 return (r==size-1);
}
int DelQ()
{
 if(isempty())
 {
 prinƞ("Queue is empty");
 return (-1);
 }
 else
 {
 f=f+1;
 i=q[f];
 return i;
 }
}
int isempty()
{
 return (r==f);
}
int DisplayQ()
{
 int j;
 if (isempty())
 {
 prinƞ(" Queue is empty\n ");
 }
 else
 prinƞ(" The Queue aŌer the operaƟon is:\n");
 for(j=f+1;j<=r;j++)
 {
 prinƞ("%d", q[j]);
 }
}
void AddCQ()
{
prinƞ("Enter the element to add to the queue \n");
scanf("%d",&i);
 if ((r+1)%size == f)
 prinƞ("\n Queue is full");
 else
 {
 r=(r+1)%size;
 cq[r]= i;
 }
}
int DelCQ()
{
 if (f==r)
 prinƞ(" \n Queue is empty ");
 else
 {
 f=(f+1)%size;
 i=cq[f];
 return i;
 }
}
int DisplayCQ()
{
int j;
if (isempty())
{
 prinƞ("\n Queue is empty");
}
else
{

 prinƞ("Queue: ");
 for (j=f+1; j<=r; j++)
 {
 prinƞ("%d \t", cq[j]);
 }
 prinƞ("\n");
}
}
int main()
{
 int q[10];
 int cq[10];
 int choice;
 int cont;
do
{
 prinƞ("Your choices are:\n");
 prinƞ("Choice 1:enque \nChoice 2:deque \nChoice 3:Check empty \nChoice 4:Check full \nChoice 5:Add element into circular queue \nChoice 6:Delete element from circular queue\n");

 prinƞ("Enter your choice\n");
 scanf("%d", &choice);
 switch(choice)
 {
 case 1:
 AddQ(i);
 DisplayQ(q);
 break;
 case 2:
 DelQ(q);
 DisplayQ(q);
 break;
 case 3:
 isempty(q);
 break;
 case 4:
 isfull(q);
 break;

 case 5:
 AddCQ(i);
 DisplayCQ(cq);
 break;

 case 6:
 DelCQ(cq);
 DisplayCQ(cq);
 break;
 default:
 prinƞ("Enter a valid choice");
 }
 prinƞ(" \n Do you want to conƟnue? (1/0)\n");
 scanf("%d", &cont);
}
while (cont == 1);
return 0;
} 
