#Two dimensional array hourglass problem
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[6][6],temp = -9999,a,i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<=3;i++)
        for(j=0;j<=3;j++)
        {
            a = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            if(temp<a)
                temp = a;
        }
    printf("%d",temp);
}
