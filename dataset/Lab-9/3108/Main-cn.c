/*
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for nontrivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template.

- You have to solve this problem using recursion 
- Some marks are reserved for writing correct base case and recursive step  
-----------------------------------------------------------------------------------------------------------

给定一个 int 数组，能否将这些 int 数据分成两组，使两组的和相同？
第一行输入将是一个整数 $n$，表示数组中的元素数。下一行是空格分隔的整数 $n$。
输出必须打印 "YES "或 "NO"。
假设：$n \leq 20$ 

Input : 
4
1 2 3 4
Output :
YES

Input : 
3
2 3 4
Output :
NO
*/
#include <stdio.h>

int n, array[20];

int areSplitsEqual(int len, int sum_split_A, int sum_split_B)
{
	if(len == n)
		return sum_split_A == sum_split_B;
	else
		return (areSplitsEqual(len+1, sum_split_A+array[len], sum_split_B) || areSplitsEqual(len+1, sum_split_A, sum_split_B+array[len]));
}

int main()
{
	int i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &array[i]);

	i = areSplitsEqual(0, 0, 0);
	printf("%s\n", i==1?"YES":"NO");
}
