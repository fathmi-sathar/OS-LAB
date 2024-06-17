#include<stdio.h>
#include<stdlib.h>
void main()
{
  int flag,i,j,k,n,r,alloc[20][20],avail[10],max[20][20];
  printf("Enter the no of process");
  scanf("%d",&n);
  printf("Enter the instance of resources");
  scanf("%d",&r);
    printf("Enter the allocation matrix");
  for(i=0;i<n;i++)
  {
    for(j=0;j<r;j++)
    {
      scanf("%d",&alloc[i][j]);
      }
    }
    printf("Enter the max matrix");
  for(i=0;i<n;i++)
  {
    for(j=0;j<r;j++)
    {
      scanf("%d",&max[i][j]);
      }
    }
     printf("Enter the available matrix");
 for(i=0;i<r;i++)
 {
   scanf("%d",&avail[i]);
   }
int f[n],index=0,ans[n];
for(k=0;k<n;k++)
{
  f[k]=0;
  }
  int need[n][r];
for(i=0;i<n;i++)
{
 for(j=0;j<r;j++)
 {
   need[i][j]=max[i][j]-alloc[i][j];
   }
 }
 int y;
 for(k=0;k<n;k++)
 {
  for(i=0;i<n;i++)
  {
    if(f[i]==0)
    {
      flag=0;
      for(j=0;j<r;j++)
      {
        if(need[i][j]>avail[j])
        {
          flag=1;
          break;
          }
        }
    if(flag==0)
    {
      ans[index++]=i;
      for(y=0;y<r;y++)
      {
        avail[y]=avail[y]+alloc[i][y];
        }
      f[i]=1;
      }
     }
     }
     }
  printf("the safe seq is");
  for(i=0;i<n-1;i++)
  {
    printf("p%d-> ",ans[i]);
    }
   printf("p%d",ans[n-1]);
   }
      
      
  
  
  
  
  
