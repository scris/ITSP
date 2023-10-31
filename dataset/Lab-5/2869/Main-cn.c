/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for the non trivial part of the code 
- Indentation: align your code properly 
-Don't put extra whitespace anywhere.
 ---------------------------------
 
输入整数 N（N>0），然后程序应输出以下模式： 
示例

Input
5

Output
55555
45555
34555
23455
12345

Input 
2

Output
22
12

*/
#include <stdio.h>

int main()
{
  int n;
  scanf("%d",&n);
  int i, j, k;
  for(i=n;i>=1;i--)
  {
    k = i;
    for(j=1;j<=n;j++)
    {
      if(k <= n)
      {
        printf("%d",k);
      }
      else
      {
        printf("%d",n);
      }
      k++;
    }
  printf("\n");
  }
  return 0;
}
