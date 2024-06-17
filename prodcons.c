#include<stdio.h>
int mutex=1,empty=3,full=0,x=0;
int wait(int s)
{
  return --s;
 }
 int signal(int s)
 {
   return ++s;
  }
void producer()
{
  mutex=wait(mutex);
  full=signal(full);
  empty=wait(empty);
  x++;
  printf("\nProducer produces item %d",x);
  mutex=signal(mutex);
 }
 void consumer()
 {
   mutex=wait(mutex);
   full=wait(full);
   empty=signal(empty);
   printf("\nConsumer consumed item %d",x);
   x--;
   mutex=signal(mutex);
   }
 void main()
 {
   int ch;
   do
   {
     printf("\nSELECT \n1.producer\n 2.consumer\n 3.exit");
     printf("\nEnter a choice");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:
       if(mutex==1&&empty!=0)
       {
         producer();
        }
        else
        {
           printf("\nBUffer is fulll");
         }
       break;
      case 2:
      if(mutex==1&&full!=0)
      {
        consumer();
        }
       else
       {
         printf("\nBUffer is empty");
         }
         break;
      case 3:break;
       default: printf("\ninvalid");
     }
     }while(ch!=3);
     }
       
        
     
