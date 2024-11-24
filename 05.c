//
// Created by 123 on 2024/11/20.
//

#include<stdio.h>

unsigned int Factorial(unsigned int n)
{
    if(n <= 1)
    {
        return n == 0? 0:1;
    }else
    {
        return n * Factorial(n-1);
    }
}

//int main(void)
//{
//    int a =Factorial(3);
//    printf("%d\n", a);
//}