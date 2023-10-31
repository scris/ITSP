/*
ANNOUNCEMENT: Up to 20% marks will be allotted for good programming practice. These include
- Comments for non trivial code 
- Indentation: align your code properly 
- Function use and modular programming

<b>[NEW]: One hidden test case updated. </b>
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

序列 {a} 的 d 阶递推关系定义为
a[i] = b[i] ; for 0 <= i < d
a[i] = a[i-1] + a[i-2] + .... + a[i-d]

给定 d、b[0...d-1]、N，求 a[N] 的值。

输入格式 ： 
第 1 行包含数字 d 和 N（用空格分隔）。
第二行包含 d 个空格分隔的数字，代表 b[0...d-1]

限制条件 ： 
每个 "数字 "表示 [-1000, 1000] 中的整数
0 <= N <= 30
1 <= d <= 20
输出结果将包含在一个 int 变量中。

Example:
Input:
4 4
1 2 3 4

Here, a[4] = a[3]+a[2]+a[1]+a[0] = 1+2+3+4 = 10. So, output:
10

Input:
5 0
55 32 56 12 83

Output:
55

*/
#include<stdio.h>
#define MAXN 31
#define MAXD 21

int main (){
    int N, d;
    scanf("%d\n%d", &d, &N);
    int a[MAXN], b[MAXD];
    for (int i=0;i<d;++i){
        scanf("%d", &b[i]);
        a[i]=b[i];
    }
    for (int i=d;i<=N;++i){
        a[i] = 0;
        for (int j=1;j<=d;++j)
            a[i] += a[i-j];
    }
    printf ("%d\n", a[N]);
    return 0;
}