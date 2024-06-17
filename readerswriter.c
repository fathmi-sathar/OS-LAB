#include<stdio.h>
 int mutex=1;
 int reading=0;
 int writing=0;
 int readercount=0;
 void read()
 {
   mutex=0;
   reading=1;
   readercount++;
   printf("\nThe reader %d is reading",readercount);
   mutex=1;
 }
 void writer()
 {
   mutex=0;
   writing=1;
   printf("\nThe writer %d is writing",writing);
   mutex=1;
  }
void main()
{
 int c;
  do
  {
    printf("\n SELECT\n1.read\n2.write\n3.delete last reader\n4.delete last writer\n5.exit\n");
    printf("\nEnter a choice");
    scanf("%d",&c);
    if(c == 1)
    {
      if((writing==0)&&(mutex == 1))
      {
        read();
        }
      else
      {
        printf("\ncannot read, a writer is writing");
       }
    }
   else if(c == 2)
   {
     if(reading == 0 && mutex==1 && writing == 0)
     {
       writer();
       }
       else if(writing == 1)
       {
         printf("\ncannot write because a writer is writing");
        }
        else{
        printf("\ncannot write because a reader is reading");
      }
      }
     else if(c == 3)
     {
       if(readercount==0)
       {
         printf("\nno one is reading");
         }
         else
         {
           printf("\nTHe reader %d is removed",readercount);
           readercount--;
           if(readercount==0)
           {
             reading=0;
            }
         }
       }
       else if(c == 4)
       {
         if(writing == 0)
         {
           printf("\nno one is writing");
         }
        else 
        {
          printf("\nThe writer is removed");
              writing=0;
        }
        }
    else if(c == 5)
    {
      printf("\nExit code");
      }
   }while(c!=5);
  }
  
         
