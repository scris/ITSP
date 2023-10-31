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

如果两个圆都有某个共同点，那么这两个圆就会重叠。
您应该设计一个与圆相对应的数据结构，使其具有明确确定圆的字段、
您需要弄清楚两个圆是否重叠。即使两个圆在某一点上几乎没有接触，也会被视为重叠。

输入格式： 
第一行包含第一个圆的圆心和半径的 x 坐标和 y 坐标。
第二行包含第二个圆的圆心和半径的 x 坐标和 y 坐标。

输出格式：
YES - 如果两个圆重叠。
NO - 如果两个圆不重叠。

例1输入:
0 0 4
1 1 3

例1输出:
YES
*/
#include <stdio.h>

struct Circle{
	int x;
	int y;
	int radius;
};

void setCoordinates(struct Circle * circle,int x,int y,int radius) {
	circle->x=x;
	circle->y=y;
	circle->radius=radius;
}

int checkIntersect(struct Circle circle1,struct Circle circle2) {
	int distance = (circle1.x-circle2.x)*(circle1.x-circle2.x)+(circle1.y-circle2.y)*(circle1.y-circle2.y);
	int radSquare = circle1.radius*circle1.radius+circle2.radius*circle2.radius+2*circle1.radius*circle2.radius;
	if(radSquare>=distance) return 1;
	else return 0;
}

int main() {
	int x,y,radius;
	struct Circle circle1,circle2;
	scanf("%d %d %d",&x,&y,&radius);
	setCoordinates(&circle1,x,y,radius);
	scanf("%d %d %d",&x,&y,&radius);
	setCoordinates(&circle2,x,y,radius);
	if(checkIntersect(circle1,circle2)) printf("YES\n");
	else printf("NO\n");
	return 0;
}