/*
--------------------------------------------
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for non-trivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
 - You are required to allocate memory Dynamically instead of static memory allocation otherwise you might get 0 marks. 
 - Use Recursion.
---------------------------------------------
给定一个数字 x，打印所有和等于 x 的序列。为此，您需要使用递归。

注意：所有从 1 开始的非递增序列应在从 2 开始的序列之前打印，以此类推。

示例

输入 ： 
4

输出： 4
1 1 1 1
2 1 1
2 2
3 1
4

*/
#include <stdio.h>

void printSum(int x,int cur_sum,int result[],int len){
	if(cur_sum == x){
		for(int i=0;i<len;i++)
			printf("%d ",result[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=x;i++){
		if(i+cur_sum<=x && (len==0 || (result[len-1]>=i))){
			result[len] = i;
			printSum(x,cur_sum+i,result,len+1);
		}
	}
}

int main(){
	int x;
	scanf("%d",&x);
	int result[100];
	printSum(x,0,result,0);
	return 0;
}
