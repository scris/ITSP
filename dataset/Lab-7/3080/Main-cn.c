/*
Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for nontrivial code 
- Indentation: align your code properly 
- Function use and modular programming 
- Usage of string.h is NOT allowed. Do not include anything in the header other than what is already given in the template. --------------------------------------------------------------------------------------------------------------

输入两个字符串 s1、s2、一个字符 c 和一个数字 n。请编写一个程序，检查下列条件中是否有一项为真：
1) 给定字符 c 在字符串 s1 中出现的次数少于 n 次
2) 给定的子串 s2 出现在字符串 s1 中

输入格式：
字符串 s1，最多 100 个字符。没有空白。
一个字母 c。
一个非负整数 n。
最多 100 个字符的字符串 s2。无空格。

输出格式：
YES或NO

Example 1:
Input:
codingisfun 
i 
2 
true

Output:
NO

Example 2:
Input:
codingisfun
p
2
true

Output:
YES
*/
#include<stdio.h>

int length(char *s)
{
	int i=0;
	while(s[i]!='\0')
	{
		i++;
	}
	return i;
}


int charCountLessThan(char* str,char c,int ct)
{
	int i,len= length(str),count=0;
	for(i=0;i<len;i++)
		{
			if(str[i]==c)
			{
				count++;
			}
		}
		return count<ct;
}

int substrCheck(char* str,char *sub)
{
	int i,flag=0,count,j;
	int len= length(str);
	int len1 = length(sub);
	for(i=0;i<len-len1+1;i++)						
	// loop over elements of str (keeping the array references later on in mind)
	{
		count=0;							// initialize count
		for(j=0;j<len1;j++)					// loop over elements of sub
		{
			if(str[i+j]==sub[j])			// check whether positional characters match
				count++;					// then increase count
		}
		if(count==len1)				// if whole substring matches
		{
			flag=1	;
							// set flag to 1
			
		}
			
	}
		return flag;					// return  flag
}


int main()
{
	char s1[100];
	
	scanf("%s",s1);
	char c1;
    scanf("\n%c",&c1);
    int n1;
    scanf("%d",&n1); 
 	
	char s2[100];
    scanf("%s",s2);

	int flag1=charCountLessThan(s1,c1,n1);
	int flag2=substrCheck(s1,s2);
	
	if((flag1==1)!=(flag2==1))
		printf("YES\n");
	else
		printf("NO\n");	
	
	return 0;		
}