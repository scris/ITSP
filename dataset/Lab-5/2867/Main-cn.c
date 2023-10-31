/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for the non trivial part of the code
- Indentation: align your code properly
---------------------------------

输入 N（N>0）后，程序应输出第 N 个四面体数。计算第 n 个四面体数 T(n) 的公式如下：
T(n) = (1) + (1+2) + (1+2+3) + (1+2+3+4) + ... + (1+2+3+4+...+n)

比如：
Input:
2
Output:
4

Input:
5
Output:
35
*/
#include <stdio.h>
int main()
{
    int i,j,n,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            sum+=j;
        }
    }
    printf("%d",sum);
    return 0;
}
 