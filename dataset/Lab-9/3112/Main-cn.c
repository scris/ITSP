/*
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for nontrivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template.

- You have to solve this problem using recursion 
- Some marks are reserved for writing correct base case and recursive step  
-----------------------------------------------------------------------------------------------------------

如果一个字符串中的所有字符（小写英文字母）都按照词典顺序排列，并且没有重复，那么这个字符串就被称为有序字符串。因此，"ahs"是一个有序字符串，而 "ahhe"和 "ahh"则不是。
给定两个数字 $n$ 和 $k$，你必须打印所有可能的长度为 $k$ 的有序字符串，这些字符串由前 $n$ 个小写英文字母中的字符组成。
假设： 1 < k < n < 26
每个字符串都应打印在新行中，并按词典顺序打印，即 "abc"应打印在 "abd"之前，而 "abd"又应打印在 "bcd"之前。

Input : 
3 1
Output :
a
b
c

Input : 
4 2
Output :
ab
ac
ad
bc
bd
cd
*/
#include <stdio.h>
 
void printArr(char arr[], int k)
{
    int i;
    for (i=0; i<k; i++)
        printf("%c", arr[i]);
    printf("\n");
}

void printSeq(int n, int m, int len, char arr[])
{
    if(len == m)
        printArr(arr, m);
    char last_element = len==0?'a'-1:arr[len-1];
    if(last_element >= 'a'-1+n)
        return;
    
    char i;
    for(i = last_element+1; i<='a'-1+n; i++)
    {
        arr[len] = i;
        printSeq(n, m, len+1, arr);
    }
}

 
int main()
{
    int k, n;
    scanf("%d%d", &n, &k);
    char arr[k];
    printSeq(n, k, 0, arr);
    return 0;
}