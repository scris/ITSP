/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include
- Comments for non trivial code 
- Indentation: align your code properly 
- Use of character constants instead of ASCII values ('a', 'b, ..., 'A', 'B', ..., '0', '1' etc instead of ASCII values like 65, 66, 48 etc.) 
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

输入一个年份。请编写一个程序来确定该年是否为闰年。闰年是能被 4 整除的年份，如果能被 100 整除，那么也应该能被 400 整除。

Example: 
Input: 2004
Output: Leap Year 

Input: 1701 
Output: Not Leap Year
*/
#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	if(y % 4 == 0)
	{
		if(y % 100 == 0)
		{
			if(y % 400 == 0)
				printf("Leap Year");
			else
				printf("Not Leap Year");
		}
		else
			printf("Leap Year");
	}
	else
		printf("Not Leap Year");
	return 0;
	
}