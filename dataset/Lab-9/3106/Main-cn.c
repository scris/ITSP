/*
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for nontrivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template.

- You have to solve this problem using recursion 
- Some marks are reserved for writing correct base case and recursive step  
-------------------------------------------------------------------------------------------

使用递归法编写一个 C 语言程序，检查给定字符串是否为回文。回文是指从前往后、从后往前读起来相同的单词、短语或句子。字符串只包含小写字母。

Input: liril
Output: Yes

Input: oolaleloo
Output: No
*/
#include <stdio.h>
#include <string.h>
 
void check(char [], int);
 
int main()
{
    char word[20];
    scanf("%s", word);
    check(word, 0);
    return 0;
}
 
void check(char word[], int index)
{
    int len = strlen(word) - (index + 1);
    if (word[index] == word[len])
    {
        if (index + 1 == len || index == len)
        {
            printf("Yes\n");
            return;
        }
        check(word, index + 1);
    }
    else
    {
        printf("No\n");
    }
}