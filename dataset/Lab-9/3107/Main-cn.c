/*
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for nontrivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template.

- You have to solve this problem using recursion 
- Some marks are reserved for writing correct base case and recursive step  
-------------------------------------------------------------------------------------------

给定一个由 $N$ 个整数组成的数组，是否可以从其中选择一组整数，使这组整数的总和达到给定的目标值 $T$？
输入由两行组成：第一行为空格分隔的整数 $N$ 和 $T$，第二行为数组中空格分隔的整数元素（$a_1 ... a_N$ ）。
输出应为单行 - "YES"或"NO"。

假设： $T, a_i$ 和 $\Sigma a_i$ 可以用 int 数据类型表示。另外 $N \leq 30$

Input :
4 2
3 5 7 1
Output :
NO

Input :
4 10
3 5 7 2
Output :
YES
*/
#include <stdio.h>

int N, T, array[30];

int groupSum(int len_covered, int partial_sum)
{
	if(len_covered == N)
		return partial_sum == T;
	else if(partial_sum == T)
	    return 1;
	else
		return ( groupSum(len_covered+1, partial_sum+array[len_covered]) || groupSum(len_covered+1, partial_sum) );
}

int main()
{
	int i;
	scanf("%d%d", &N, &T);
	for(i=0; i<N; i++)
		scanf("%d", &array[i]);

	printf("%s\n", groupSum(0, 0)==1?"YES":"NO");
}
