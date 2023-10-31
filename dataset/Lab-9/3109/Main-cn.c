/*
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for nontrivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template.

- You have to solve this problem using recursion 
- Some marks are reserved for writing correct base case and recursive step  
-------------------------------------------------------------------------------------------

编写一个递归函数，为给定的 n<=20 值生成所有可能的 n 对平衡括号。每个平衡括号都应打印在新行中。

Input: 1
Output: 
{}

Input: 2
Output:
{}{}
{{}}
*/
# include<stdio.h>
# define MAX_SIZE 100

void printParenthesis(int pos, int n, int open, int close)
{
  static char str[MAX_SIZE];     
 
  if(close == n) 
  {
    printf("%s \n", str);
    return;
  }
  else
  {
    if(open > close) {
        str[pos] = '}';
        printParenthesis(pos+1, n, open, close+1);
    }
    if(open < n) {
       str[pos] = '{';
       printParenthesis(pos+1, n, open+1, close);
    }
  }
}
 
/* driver program to test above functions */
int main()
{
  int n;
  scanf("%d", &n);
  printParenthesis(0, n, 0, 0);
  getchar();
  return 0;
}