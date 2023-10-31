/*
--------------------------------------------
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for non-trivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
TAs: Recursive algorithm is required.
 ---------------------------------------------

给定一个正数 n，需要按下方格式输出。你需要使用递归。如果使用了循环，则不得分。

示例 1：
输入
11

输出： 11
11 6 1 -4 1 6 11

示例 2：
输入
15

输出
15 10 5 0 5 10 15
*/
#include <stdio.h>

void pattern(n){
	if(n<=0){
		printf("%d ",n);
		return;
	}	
	else{
		printf("%d ",n);
		pattern(n-5);
		printf("%d ",n);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	pattern(n);
	return 0;
}

