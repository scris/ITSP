/*
Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for nontrivial code 
- Indentation: align your code properly 
- Function use and modular programming 
- Usage of string.h is NOT allowed. Do not include anything in the header other than what is already given in the template.
--------------------------------------------------------------------------------------------------------------

编写一个程序，将给定字符串的前半部分与后半部分对调，并打印最终字符串。

输入格式：
最多 100 个字符的字符串。不含空格。

输出格式：
转换后的字符串。		
	
Example 1:
Input:
abcdef 

Output:
defabc

Example 2: 
Input:
hello-@programmer 

Output:
ogrammerrhello-@p

*/
#include<stdio.h>

int strLen(char str[]) {
    int i;
    for(i=0;str[i]!='\0';i++){}
        
    return i;    

}


void swapStr (char str[])	// swap the two halves
{
		int i, len= strLen(str);
		char temp;
		
		for(i=0;i<len/2;i++)
		{
			temp = str[i];
			str[i] = str[(len+1)/2 + i];
			str[(len+1)/2 + i] = temp;			
		}
}

int main()
{
	char str[100];
	scanf("%s",str);
	int n;
	scanf("%d",&n);
	swapStr(str);
	printf("%s",str);
	return 0;
}