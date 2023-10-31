/*
Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for nontrivial code 
- Indentation: align your code properly 
- Function use and modular programming 
- Usage of string.h is NOT allowed. Do not include anything in the header other than what is already given in the template.
--------------------------------------------------------------------------------------------------------------

编写一个程序，将给定字符串按输入量 "n"进行右圆周旋转，并打印最终字符串。

输入格式：
最多 100 个字符的字符串。不含空格。
一个正整数。	

输出格式：
旋转后的字符串。		
	
例1:
Input:
abcdef 
2

Output:
efabcd

例2: 
Input:
hello-@programmer 
5

Output:
ammerhello-@progr

*/
#include<stdio.h>

int strLen(char str[]) {
    int i;
    for(i=0;str[i]!='\0';i++){}
        
    return i;    

}

void RotateByAmount (char * str, int amount)	// Circular rotate a string right by amount
{
		int i,pos,len= strLen(str);
		char temp[len];
		for(i=0;i<len;i++)
		{
			temp[i]=str[i];				
		}
		for(i=0;i<len;i++)
		{
			int pos = i+amount;	
			pos=pos%len;			
			str[pos]=temp[i];			
		}
}

int main()
{
	char str[100];
	scanf("%s",str);
	int n;
	scanf("%d",&n);
	RotateByAmount(str,n);
	printf("%s",str);
	return 0;
}