/*
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for nontrivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template.

- You have to solve this problem using recursion 
- Some marks are reserved for writing correct base case and recursive step  
-------------------------------------------------------------------------------------------

编写一个递归 C 函数，将给定字符串反转并打印出来。输入由两行组成： 第一行给出字符串的长度；第二行给出字符串。字符串长度不超过 100 个字符。

比如：
Input:
6 
Hello
Output: 
olleH

Input: 
14
baL noisruceR
Output: 
Recursion Lab
*/
#include <stdio.h>
#include <string.h>
 
void reverse(char [], int, int);
int main()
{
    char str[100];
    int size, i;
    scanf("%d", &size);
    for (i=0; i<size; i++)
        scanf("%c", &str[i]);
    str[size] = '\0';    
    reverse(str, 0, size-1);
    printf("%s\n", str);
    return 0;
}
 
void reverse(char str1[], int index, int size)
{
    char temp;
    temp = str1[index];
    str1[index] = str1[size - index];
    str1[size - index] = temp;
    if (index == size / 2)
    {
        return;
    }
    reverse(str1, index + 1, size);
}