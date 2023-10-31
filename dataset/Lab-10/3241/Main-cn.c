/*

Amber 是一名大一学生，她最近学习了 GCD 以及如何计算两个数的 GCD。她想把除数和 GCD 的定义扩展到字符串。以下是她的想法

字符串 s1 是字符串 s2 的除数，当且仅当存在一个正整数 x 时，如果我们连续 x 次写出字符串 s1，就会得到字符串 s2。例如，字符串 "abab "有两个除数--"ab "和 "abab"。

现在，Amber 想要计算两个字符串的最大公约数。她不擅长编码，希望得到您的帮助。

输入：
第一行输入非空字符串 s1。
第二行输入非空字符串 s2。

输出 ：
打印 s1 和 s2 的最大公约数。如果不存在公因子，则仅返回空字符串。
*/
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0


// a program to check if the first i characters of the string are a factor of it. 
int isfactor(char s[] , int n , int i ){
	if (n % i != 0 )
		return false; 

	if( i == 0 || i > n )
		return false; 

	if (n == 0) 
		return true; 

	for(int j = 0 ; j < n ; j++)
		if(*(s + j) != *(s + j%i))
			return false;

	return true;
}

int get_len(char s[])
{
	int i = 0 ; 
	while(*(s + i) != '\0')
		i++;

	return i ; 
}

int main(){

	int n1, n2 , i; 
	char *s, *t ; 

	scanf("%d" , &n1);
	s = (char *)malloc((n1 + 1) * sizeof(char));
	scanf("%s",s);

	scanf("%d" , &n2);
	t = (char *)malloc((n2 + 1) * sizeof(char));
	scanf("%s",t);

 	int max = -1;

	for( i = 0  ; i < get_len(s) && i < get_len(t) ; i++)
	{
		if (isfactor(s , get_len(s) , i + 1) && isfactor(t , get_len(t) , i + 1))
			max = i;
	}

	s[max + 1] = '\0';
	printf("%s", s);
	return 0 ; 

}