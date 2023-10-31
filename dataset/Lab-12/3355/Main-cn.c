/*
-------------------------------------------- 
Up to 20% marks will be allotted for good programming practice. These include 
 - Comments: for non-trivial code 
 - Indentation: align your code properly 
 - Function use and modular programming 
 - Do not include anything in the header other than what is already given in the template. 
 - You are required to allocate memory Dynamically instead of static memory allocation otherwise you might get 0. 
 - Use of C Structures is mandatory.
---------------------------------------------

如果两个区间都包含某个点，那么这两个区间就会重叠。
您应该设计一个数据结构，使其具有两个字段，即左索引和右索引。 
假设指定的区间是封闭区间。你需要计算给定的两个区间是否重叠。

输入格式：
第一行包含两个空格分隔的整数，指定第一个封闭区间
第二行包含两个空格分隔的整数，指定第二个封闭区间

输出格式：
"YES"或"NO"，取决于区间是否重叠

Input 1:
4 10
-1 6
Output 1:
YES

Input 2:
4 10
-1 3
Output 2:
NO
*/
#include <stdio.h>

struct Interval{
	int left;
	int right;
};

void setPoints(struct Interval * interval,int left,int right) {
	interval->left=left;
	interval->right=right;	
}

int checkIntersect(struct Interval int1, struct Interval int2) {
	if(int1.right<int2.left || int2.right<int1.left) return 0;
	return 1;
}

int main() {
	int left,right;
	struct Interval int1,int2;
	scanf("%d %d",&left,&right);
	setPoints(&int1,left,right);
	scanf("%d %d",&left,&right);
	setPoints(&int2,left,right);
	if(checkIntersect(int1,int2)) printf("YES\n");
	else printf("NO\n");
	return 0;
}