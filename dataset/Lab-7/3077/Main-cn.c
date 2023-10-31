/*
Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for nontrivial code 
- Indentation: align your code properly 
- Function use and modular programming 
- Usage of string.h is NOT allowed. Do not include anything in the header other than what is already given in the template. --------------------------------------------------------------------------------------------------------------

编写一个程序，将给定字符串按输入量 "n"移动，并打印最终字符串。字符串只有小写字母。

输入格式：
一个最多包含 100 个小写字母的字符串。	
一个非负整数 n。

输出格式：
每个字母按 n 移位的字符串。

例1:
Input:	
abcdef 
2

Output:	
cdefgh

例2:
Input: 
wxyz
3

Output:
zabc
*/
#include<stdio.h>

int strLen(char str[]) {
    int i;
    for(i=0;str[i]!='\0';i++){}
        
    return i;    

}

void ShiftByAmount (char * str, int amount)	 // Shift all characters by a specified amount
{
		int i,len= strLen(str);
		
		for(i=0;i<len;i++)
		    str[i]=(str[i]-'a'+amount)%26 + 'a';	
		
}
int main()
{
	char str[100];
	scanf("%s",str);
	int n;
	scanf("%d",&n);
	ShiftByAmount(str,n);
	printf("%s",str);
	return 0;
}