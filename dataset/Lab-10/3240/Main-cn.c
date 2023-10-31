/*
Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for non-trivial code. 
- Indentation: align your code properly. 
- Function use and modular programming. 
- Do not include anything in the header other than what is already given in the template. 
- Use pointers only and when required allocate memory Dynamically instead of static memory allocation otherwise you will get 0 marks.
------------------------------------------------------------------------------------------------------------------------------------------------
给您两个字符串，请找出使两个字符串相等所需的最少字符删除数。您可以删除任何字符串中的任何字符。如果一个字符串中的每个字符都出现在另一个字符串中的任何位置，则这两个字符串相等。例如："abc"和 "cab"是相等字符串。

注：字符串只包含小写字母。字符串的大小由用户指定，并使用动态内存分配。

输入格式： 前两行包含第一个字符串和字符串本身的大小。下两行包含第二个字符串的大小和字符串本身。

输出格式： 打印使字符串相等所需的最小字符删除数。

示例
输入：
3 
cde
3
abc

输出：
4 
*/
#include <stdio.h>
#include <stdlib.h>
int makeEqual(char * s1, int n1, char * s2, int n2){
    int a[26] = {0}, b[26] = {0}, i, r = 0;
    for(i = 0; i < n1; i++)
        *(a + *(s1 + i) - 'a') += 1;
    for(i = 0; i < n2; i++)
        *(b + *(s2 + i) - 'a') += 1;
    for(i = 0; i < 26; i++)
        r = r + abs(*(a + i) - *(b + i));
    return r;    
}
int main(){
    int n1, n2;
    char *s1, *s2;
    scanf("%d\n", &n1);
    s1 = (char *)malloc(n1 * sizeof(char));
    for(int i = 0; i < n1; i++)
        scanf("%c", (s1 + i));
    scanf("\n%d\n", &n2);
    s2 = (char *)malloc(n2 * sizeof(char));
    for(int i = 0; i < n2; i++)
        scanf("%c", (s2 + i));
    printf("%d", makeEqual(s1, n1, s2, n2));
    return 0;
}