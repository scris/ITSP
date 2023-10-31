/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include
- Comments for non trivial code 
- Indentation: align your code properly 
- Use of character constants instead of ASCII values ('a', 'b, ..., 'A', 'B', ..., '0', '1' etc instead of ASCII values like 65, 66, 48 etc.) 

输入 4 个自然数。请编写一个程序，计算并打印其中第二大的数。

Input:
1 5 3 2 

Output:
The second largest number is 3
*/
#include <stdio.h>
int main() {
	int a,b,c,d;
	scanf("%d%d%d%d" , &a, &b , &c , &d);
	int largest = -1;
	int second_largest = -1;

	if (a > largest)
		largest = a;
	else if (a > second_largest)
		second_largest = a;

	if (b > largest)
		{second_largest = largest;
		largest = b;}
	else if (b > second_largest)
		second_largest = b;

	if (c > largest)
		{second_largest = largest;
		largest = c;}
	else if (c > second_largest)
		second_largest = c;

	if (d > largest)
		{second_largest = largest;
		largest = d;}
	else if (d > second_largest)
		second_largest = d;

	printf("The second largest number is %d",second_largest);

	return 0;	
} 