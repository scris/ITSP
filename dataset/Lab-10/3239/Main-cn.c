/*
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for non-trivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template.
 - Use pointers only and when required allocate memory Dynamically instead of static memory allocation otherwise you will get 0 marks.
-----------------------------------------------------------------------------------------------------------------------------------------------------
输入两个字符串。请编写一个程序，找出这两个字符串是否有效。如果一个字符串中的每个字符都出现在另一个字符串的任意位置，则这两个字符串为有效字符串。例如："abc"和 "cab"是有效字符串。

注意：输入字符只能是小写字母。字符串的大小由用户指定，并使用动态内存分配。
 
输入格式： 第一行包含第一个字符串的大小，下一行包含字符串本身。同样，下一行包含第二个字符串的大小，下一行包含字符串本身。

输出：如果两个字符串有效，则打印"Valid"，否则打印"Not Valid"。 

示例
输入 ：
3
abc
3
cab

输出：
Valid
*/
#include <stdio.h>
#include <stdlib.h>

int valid(char * s1, char * s2, int n){
    int a[26] = {0}, b[26] = {0};
    for(int i = 0; i < n; i++){
        a[s1[i] - 'a'] += 1;
        b[s2[i] - 'a'] += 1;
    }
    for(int i = 0; i < 26; i++)
        if(a[i] != b[i])
            return 0;
    return 1;        
}

int main()
{
	int n1, n2;
	char *s, *t;

	scanf("%d" , &n1);
	s = (char *)malloc((n1 + 1) * sizeof(char));
	scanf("%s",s);

	scanf("%d" , &n2);
	t = (char *)malloc((n2 + 1) * sizeof(char));
	scanf("%s",t);


	if(n1 != n2)
	    printf("Not Valid");
	else if(valid(s, t, n1))
	    printf("Valid");
	else
	    printf("Not Valid");


	return 0;

}