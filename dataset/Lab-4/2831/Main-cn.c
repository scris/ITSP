/*
输入一个正整数。请编写一个程序，打印出相反的数字。(仅使用讲座中涉及的 C 结构）。

Input:
12345
Output:
Reverse of 12345 is 54321
*/
#include <stdio.h>
int main()
{
  int n , m = 0;
  int old;
  scanf("%d", &n);

   old = n ;
    
  while(n > 0)
  {
  	  m = m*10;
  	  m = m + n%10;
      n/=10;             /* n=n/10 */
  }
  printf("Reverse of %d is %d", old, m);
}