/*
<b>NEW</b>: Constraints on a[i] updated to : -10000 <= a[i] <= 10000 

ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include
- Comments for non trivial code 
- Indentation: align your code properly
- Function use and modular programming
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

给定一个数字 N 和一个包含 N 个数字的数组 a[0...N-1]，打印如下内容 

a[N-1］
a[N-1] [N-2］
a[N-1] a[N-2] a[N-3]
....
.....
a[N-1] a[N-2] .... a[0]

注 
1. 请记住，连续数字之间有空格。
2. 显然，有 N 行要打印。

输入格式 ： 
第一行包含一个整数 N。
第二行包含 N 个空格分隔的整数，指定 a[0]、a[1]、... , a[N-1]

限制条件 ： 
1 <= N <= 5555
-10000 <= a[i] <= 10000 

Example:

Input:
5
52 91 72 65 100

Output:
100 
100 65 
100 65 72 
100 65 72 91 
100 65 72 91 52
*/
#include<stdio.h>

int main (){
    int N, a[5555];
    scanf ("%d", &N);
    for (int i=0; i<N;++i)scanf ("%d", &a[(N-1)-i]);
    for (int i=0; i<N;++i){
        for (int j=0; j<=i;++j){
            printf ("%d ", a[j]);
        }   
        printf ("\n");
    }
    return 0;
}