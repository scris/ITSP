/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include
 - Comments: for the non trivial part of the code 
- Indentation: align your code properly
 -Don't put extra whitespace anywhere.
 ---------------------------------
给定输入数 N（0<=N<=9）、宽度 w 和高度 h，分别生成如下所示的矩形边界空间：

比如：
Input:
3 4 5

Output: 
3333 
3  3 
3  3
3  3 
3333

Input:
2 2 2
22
22


*/
#include<stdio.h>

int main()
{
    int N,width,height;
    scanf("%d %d %d",&N,&width,&height);
    int i,j;
    for(i=1;i<=height;i++)
    {
        for(j=1;j<=width;j++)
        {
            if(j==width || j==1 || i==1 || i==height)
                printf("%d",N);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}


