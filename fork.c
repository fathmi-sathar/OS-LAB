#include<stdio.h>
void main()
{
 int n,i,sum=0;
 printf("Enter the limit");
 scanf("%d",&n);
 int v=fork();
 if(v==0)
 {
   for(i=0;i<n;i++)
   {
     if(i%2==0)
     {
       sum=sum+i;
       }
     }
     printf("\nSum of even numbers is %d",sum);
     int s=getppid();
     printf("\nParent id%d",s);
   }
  else
  {
   for(i=0;i<n;i++)
   {
     if(i%2!=0)
     {
       sum=sum+i;
       }
     }
     printf("\nSum of odd numbers is %d",sum); 
   }
  int p=getpid();
   printf("\nProcess id %d",p);
}  
