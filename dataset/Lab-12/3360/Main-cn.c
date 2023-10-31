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

您会收到一个学生的学号，然后是他/她的数学、物理和化学分数。您需要根据学生不同科目的分数进行排名。

数学分数越高的学生排名越靠前。
如果两个学生的数学分数相同，则物理分数高的学生排名靠前。
如果两个学生的数学和物理分数相同，那么化学分数高的学生排名更好。

保证没有两个学生三科分数相同，即没有两个学生的排名相同。

输入格式：
一行指定学生人数（N）
N 行，每行依次为 "编号 物理分数 化学分数 数学分数"。

输出格式：
N 行，每行依次为 "编号 物理分数 化学分数 数学分数"。排名靠前的先显示。

输入示例 1：
4
1 100 99 100
2 100 98 98
3 1 1 1
4 91 12 12

输出示例 1：
1 
2
4
3
*/
#include <stdio.h>
#include <stdlib.h>

struct Student{
	int roll;
	int P;
	int C;
	int M;
};

void setStudent(struct Student * student,int roll, int P, int C, int M) {
	student->roll=roll;
	student->P=P;
	student->C=C;
	student->M=M;
}

int comp (const void * elem1, const void * elem2) 
{
    struct Student s1 = *((struct Student *)elem1);
    struct Student s2 = *((struct Student *)elem2);
    if(s1.M>s2.M) return 1;
    else if(s1.M<s2.M) return -1;
    else {
    	if(s1.P>s2.P) return 1;
    	else if(s1.P<s2.P) return -1;
    	else {
    		if(s1.C>s2.C) return 1;
    		else if(s1.C<s2.C) return -1;
    		else return 0;
    	}
    }
}

int main() {
	int studentNum,i;
	int roll,P,C,M;
	scanf("%d",&studentNum);
	struct Student * students = (struct Student *) malloc(studentNum*sizeof(struct Student));
	for(i=0;i<studentNum;i++) {
		scanf("%d %d %d %d",&roll,&P,&C,&M);
		setStudent(students+i,roll,P,C,M);
	}
	qsort(students,studentNum,sizeof(struct Student),comp);
	for(i=studentNum-1;i>=0;i--) {
		printf("%d\n",students[i].roll);
	}
	return 0;
}
