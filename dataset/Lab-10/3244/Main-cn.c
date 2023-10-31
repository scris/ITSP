/*
Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for non-trivial code. 
- Indentation: align your code properly. 
- Function use and modular programming. 
- Do not include anything in the header other than what is already given in the template. 
- Use pointers only and when required allocate memory Dynamically instead of static memory allocation otherwise you will get 0 marks.
-------------------------------------------------------------------------------------------------------------------------------------------------------------

假设有一个长度为 N 的字符串 S，其索引从 0 到 N - 1。字符串 R 是字符串 S 的反向。如果对于从 1 到 N - 1 的每个 i，条件 |S_i - S_(i - 1)| = |R_i - R_(i - 1)| 为真，则字符串 S 是好字符串。

注：对于字符串 str，str_i 表示 str[i] 字符的 ascii 值（0-索引）。|字符串的大小由用户设定，并使用动态内存分配。

输入格式 第一行包含字符串长度，下一行是字符串。
输出：“Good String”或“Not Good String”。

举例说明：
输入：
4
acxz
输出：
Good String

输入：
4
bcxz
输出：
Not Good String 
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, c = 1;
    char  * s, * r;
    scanf("%d\n", &n);
    s = (char *)malloc((n + 1) * sizeof(char));
    r = (char *)malloc((n + 1) * sizeof(char));
    for(i = 0; i < n; i++)
        scanf("%c", (s + i));
    *(s + n) = '\0';    
    c = 1;
    for(i = 0; i < n; i++){
        *(r + n - 1 - i) = *(s + i);
    }
    for(i = 1; i < n; i++){
        if(abs(*(s + i) - *(s + i - 1)) != abs(*(r + i) - *(r + i - 1))){
            c = -1;
            break;
        }
    }
    if(c == 1)
        printf("Good String");
    else
        printf("Not Good String");
    return 0;
}