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

如果两个矩形（包括边界）都包含一个点，则两个矩形会重叠。
您应该设计一个与矩形相对应的数据结构，使其具有明确确定矩形的字段、
您需要计算给定的两个轴对齐的矩形是否重叠。

输入格式： 
第一行包含第一个矩形左上角点的 x 坐标和 y 坐标，然后是第一个矩形右下角点的 x 坐标和 y 坐标。
第二行包含第二个矩形左上角点的 x 和 y 坐标，然后是第二个矩形右下角点的 x 和 y 坐标。

输出格式：
YES - 如果两个矩形重叠。
NO - 如果两个矩形重叠。

例1输入:
1 10 4 1
2 9 3 2

例1输出:
YES
*/
#include <stdio.h>

struct Rect{
	int leftX;
	int leftY;
	int rightX;
	int rightY;
};

void setCoordinates(struct Rect * rect,int lx,int ly,int rx,int ry) {
	rect->leftX=lx;
	rect->leftY=ly;
	rect->rightX=rx;
	rect->rightY=ry;
}

int checkIntersect(struct Rect rect1,struct  Rect rect2) {
	if(rect2.rightY>rect1.leftY || rect1.rightY>rect2.leftY) return 0;
	if(rect2.rightX<rect1.leftX || rect1.rightX<rect2.leftX) return 0;
	return 1;
}

int main() {
	int lx,ly,rx,ry;
	struct Rect rect1,rect2;
	scanf("%d %d %d %d",&lx,&ly,&rx,&ry);
	setCoordinates(&rect1,lx,ly,rx,ry);
	scanf("%d %d %d %d",&lx,&ly,&rx,&ry);
	setCoordinates(&rect2,lx,ly,rx,ry);
	if(checkIntersect(rect1,rect2)) printf("YES\n");
	else printf("NO\n");
	return 0;
}