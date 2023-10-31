/*
Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for nontrivial code 
- Indentation: align your code properly 
- Function use and modular programming 
- Usage of string.h is NOT allowed. Do not include anything in the header other than what is already given in the template. --------------------------------------------------------------------------------------------------------------

编写一个程序，使用以下编码移位给定字符串： a "应移位 1，"b "应移位 2，.....，"z "应移位 26。打印最终字符串。该字符串只有小写字母。

输入格式：
最多包含 100 个小写字母的字符串。	

输出格式：
每个字母都经过适当移位后的字符串。

Example 1:
Input:	
abcdef 

Output:	
bdfhjl

Example 2:
Input: 
wxyz

Output:
tvxz
*/
#include<stdio.h>

int strLen(char str[]) {
    int i;
    for(i=0;str[i]!='\0';i++){}
        
    return i;    

}

void Shift(char str[])	 
{
		int i,len= strLen(str);
		
		for(i=0;i<len;i++)
		    str[i] = (2*(str[i]-'a')+1)%26 + 'a';	
		
}
int main()
{
	char str[100];
	scanf("%s",str);
	
	Shift(str);
	printf("%s",str);
	return 0;
}