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

您将得到两个集合，您需要打印两个集合交集处的元素。
请注意 集合中的元素是唯一的，您将得到按排序顺序排列的集合元素。
如果一个元素同时出现在两个集合中，则该元素位于两个集合的交集处。

请使用数据结构（Data-Structures）来解决这个问题，以便指定集合的详细信息。这样的数据结构可以有两个字段，一个指定数组中元素的数量，另一个是指向整数数组的指针。您需要动态分配空间来存储集合中的元素。

输入格式：
第一行包含第一个集合的元素个数。
第二行包含按排序顺序排列的第一组元素（空格分隔）。
第三行包含第二组元素的个数。
第四行包含按排序顺序排列的第二组元素（空格分隔）。

输出格式： 
在一行中打印两个集合交集处的元素（按排序）。

输入示例 1：
4
1 2 3 4
5 
2 3 4 5 6

输出示例 1：
2 3 4

注意：集合中的元素是按排序顺序给出的，因此，如果你仔细地循环遍历集合中的元素，你将不需要排序，因为它们本身就是按排序顺序排列的：) 
*/
#include <stdio.h>
#include <stdlib.h>
struct Set{
	int size;
	int * elements;
};

void inputSet(struct Set * set, int size) {
	set->size = size;
	set->elements = (int *) malloc(sizeof(int)*size);
	int i=0;
	for(i=0;i<size;i++) {
		scanf("%d",set->elements+i);
	}
}

void printIntersect(struct Set set1,struct Set set2) {
	int i,j;
	for(i=0;i<set1.size;i++) {
		int el = set1.elements[i];
		for(j=0;j<set2.size;j++) {
			if(set2.elements[j]==el) {printf("%d ",el);break;}
		}
	}
	printf("\n");
}

int main() {
	int size;
	struct Set set1,set2;
	scanf("%d",&size);
	inputSet(&set1,size);
	scanf("%d",&size);
	inputSet(&set2,size);
	printIntersect(set1,set2);
	return 0;
}