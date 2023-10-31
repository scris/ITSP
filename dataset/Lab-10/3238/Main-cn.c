/*
输入是三个字符串 s1、s2 和 s2。您需要用 s3 替换 s1 中所有出现的 s2。如果 s1 中没有出现 s2，则打印出不变的字符串 s1。

例如
如果字符串 s1 是 "abcxyzdefxyzghixyz"、 
s2 为 "xyz"、
s3 为 "uv"，则输出结果应为 "abcuvdefuvghiuv"。

输入格式 ：
三行输入，每行都是 "n s"的形式，其中 n 是输入字符串 s 的大小。

在上面的例子中
INPUT：
18 abcxyzdefxyzghixyz
3 xyz
2 uv

输出：
abcuvdefuvghiuv

注：可以假设输入字符串中没有空格
*/
#include <stdio.h>
#include <stdlib.h>

int get_len(char s[])
{
	int i = 0 ; 
	while(s[i] != '\0')
		i++;

	return i ; 
}

int number_occourences(char *s, char *t){
	int s_len, t_len, i,j = 0; 

	int ncount, count = 0 ; 
	s_len = get_len(s);
	t_len = get_len(t);

	for(i = 0 ; i < s_len ; i++){
		ncount = 0 ; 
		for(j = 0 ; i + j < s_len  && j < t_len; j++)
			if(s[i+j] == t[j])
				ncount++;

		count =  count + ncount/t_len;
	} 

	return count;
}

int replace_substring(char *s,char *t,char *w)
{
	int j,i=0, k=0, index=-1,ncount=0;
	char *copy,*x,*y,*z;

	int s_len = get_len(s);
	int t_len = get_len(t);
	int w_len = get_len(w);

	int max_size_new = s_len + w_len*(number_occourences(s,t) + 1);
	copy = (char *)malloc(max_size_new * sizeof(char));

	for(i = 0 ; i < s_len ; i++){
		ncount = 0 ; 

		//checking if we have an occourence of a substring
		for(j = 0 ; i + j < s_len  && j < t_len; j++)
			if(s[i+j] == t[j])
				ncount++;

		// we have found an occourence
		if (ncount/t_len) {
			for(j = 0 ;j < w_len; j++)
				copy[k + j] = w[j];

			i = i + t_len - 1;
			k = k + w_len; 
		}
		else
		{
			copy[k] = s[i];
			k++ ;
		}
	} 

	printf("%s\n",copy);
}

int main()
{
	int n1, n2, n3;
	char *s, *t, *w;

	scanf("%d" , &n1);
	s = (char *)malloc((n1 + 1) * sizeof(char));
	scanf("%s",s);

	scanf("%d" , &n2);
	t = (char *)malloc((n2 + 1) * sizeof(char));
	scanf("%s",t);


	scanf("%d" , &n3);
	w = (char *)malloc((n3 + 1) * sizeof(char));
	scanf("%s",w);

	//printf("%d" , number_occourences(s,t));
	replace_substring(s,t,w);

	return 0;

}