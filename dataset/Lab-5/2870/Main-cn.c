/*
ANNOUNCEMENT:
Up to 20% marks will be allotted for good programming practice. These include 
- Comments: for the non trivial part of the code 
- Indentation: align your code properly 
- Use the function in the template compulsorily and more functions, if necessary. 
-----------------------------------
给定一个正整数 N，打印数 p，使得 p 是大于或等于 N 的最小质数。

例如：
Input: 11
Output: 11

Input: 22
Output: 23

Input: 1
Output: 2
*/
#include<stdio.h>
int check_prime(int num);

int main(){
   int n,i;
   scanf("%d",&n);
   int flag = 1;
   i = n;
   
   while(flag){
       if(!check_prime(i))
            flag = 0;
        else{
            i++;
        }
   }
   printf("%d\n",i);
   return 0;
}

int check_prime(int num) /* User-defined function to check prime number*/
{
    if(num==1)
        return 1;
        
   int j,flag=0;
   for(j=2;j<=num/2;++j){
        if(num%j==0){
            flag=1;
            break;
        }
   }
   return flag;
}