//gcc 5.4.0

#include <stdio.h>
#include <stdlib.h>
#include  <sys/types.h>

int Sum(int a[],int start,int end)
{
    int sum=0;
    for(int i=start;i<end;i++)
        sum=sum+a[i];
    return sum;
}

int main() {
 
    int arr[1000],sum[10]={0},fSum=0;
  for (int c = 0; c < 1000; c++)
    arr[c]= rand() % 9 + 1;
    
    sum[9]=Sum(arr,400,500);  
    int pid=fork();
    if(pid==0)
    {
        sum[0]=Sum(arr,0,100);
        int pid=fork();
        if(pid==0)
        {
            sum[1]=Sum(arr,100,200);
            int pid=fork();
            if(pid==0)
            {
                sum[2]=Sum(arr,200,300);
                int pid=fork();
                if(pid==0)
                {
                    sum[3]=Sum(arr,600,700);
                }
                if(pid>0)
                {
                    sum[4]=Sum(arr,700,800);
                }
            }
            if(pid>0)
            {
                sum[5]=Sum(arr,300,400);
                int pid=fork();
                if(pid==0)
                {
                    sum[6]=Sum(arr,800,900);
                }
                if(pid>0)
                {
                    sum[7]=Sum(arr,900,1000);
                }
            }
        }
        if(pid>0)
        {
            sum[8]=Sum(arr,500,600);
        }
    }
    if(pid>0)
       {
           for(int i=0;i<10;i++)
           {
              fSum=fSum+sum[i]; 
           }
       }
    printf("Sum of 1000 numbers is: %d",fSum);
 
  return 0;
}