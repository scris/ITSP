/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for the non trivial part of the code
- Indentation: align your code properly
- Don't put extra whitespace anywhere.
---------------------------------
输入一个整数 N（N>0），你的程序应输出以下图形：

例如：
Input : 
5

Output:
5432*
543*1
54*21
5*321
*4321

eg:
Input:
2

Output:
2*
*1
*/
#include<stdio.h>
int main()
{
  int i,j;
  int N;
  scanf("%d",&N);
  for(i=1;i<=N;i++)
  {
    for(j=N;j>=1;j--)
    {
      if(i==j)
        printf("*");
      else
        printf("%d",j);
    }
    printf("\n");
  }
  return 0;
}