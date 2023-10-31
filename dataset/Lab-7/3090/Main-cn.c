/*
Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for nontrivial code 
- Indentation: align your code properly 
- Function use and modular programming 
- Usage of string.h is NOT allowed. Do not include anything in the header other than what is already given in the template. --------------------------------------------------------------------------------------------------------------

编写一个程序，在主字符串 (str) 中首次出现给定子字符串 (s1) 之前插入一个子字符串 (s2)。

输入格式：
字符串 str，最多 50 个字符。无空格。
字符串 s1，最多 50 个字符。无空格。
字符串 s2，最多 50 个字符。无空格。

输出格式：
修改后的主字符串（如果有）。

Example 1:
Input:
abcde
bc
re

Output:
arebcde

Example 2:
Input:
jhggd 
g 
sdfghjk

Output:
jhsdfghjkggd
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

void Insert(char *str, char *sub, int pos)
{
	int i=-1;
	int len = length(str);
	char temp[100];
	do
	{
		i++;
		temp[i]=str[i];
	}while(i!=len);
	
	int sublen=length(sub);
	int j = pos;
	
	for(i=0;i<sublen;i++)
	{
		str[j++]=sub[i];
	}
	
	for(i=pos;i<=len;i++)
	{
		str[j++]=temp[i];
	}
}

int substrCheck(char* str,char *sub,int start)
{
	int i=start,j=0;
	int flag=0;
	int len = length(str);
	int lensub = length(sub);

	if(start+lensub<=len)
	{	
		flag=1;
		for(j=0;j<length(sub);j++)
		{
			if(str[i+j]!=sub[j])
			{
				flag=0;
				
			}
		}
	}

if(flag==1)
	return start+lensub-1;
else
	return -1;
}
	

int main()
{

    char str[100];


    int i =-1,start=0;

    scanf("%s",str);

    char s1[50];
    scanf("%s",s1);

    char subs1[50];
    scanf("%s",subs1);


    for(i=0;i<length(str);i++)
    {
	    int val=substrCheck(str,s1,i);
	    if(val>=0) 
	    {
		    start=i;
		
		    Insert(str,subs1,start);
		    break;
	    }

    }

    printf("%s",str);

    return 0;
}