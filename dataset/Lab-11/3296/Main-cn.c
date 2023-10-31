/*
--------------------------------------------
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for non-trivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
 - You are required to allocate memory Dynamically instead of static memory allocation otherwise you might get 0 marks. 
---------------------------------------------

给定 n 个字符和一个正整数 k，打印所有长度为 k 的字符串。

注意：所有以 "a"开头的字符串应在以 "b"开头的字符串之前打印，以此类推。(即按照字典序）。

下方为一个示例：

输入（第一个数字是 n，后面分别是 n 个字符和 k）：
2
a 
b
3

输出： 
aaa
aaa
aab
aba
abb
baa
bab
bba
bbb
*/
#include <stdio.h>
int n;
int k;


void disp(char result[],int len){
	for(int i=0;i<len;i++)
			printf("%c",result[i]);
		printf("\n");
}

void printLengthK(char set1[],int len,char result[]){
	if(len==k){
		disp(result,len);
		return;
	}

	for(int i=0;i<n;i++){
		result[len] = set1[i];
		printLengthK(set1,len+1,result);
	}
		
}
int main(){

	scanf("%d\n",&n);
	char set1[n];
	for(int i=0;i<n;i++){
		scanf("%c\n",&set1[i]);
	}
	scanf("%d",&k);	
	
	char result[k];
	printLengthK(set1,0,result);
 	return 0;
}