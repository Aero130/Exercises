//
// Created by 123 on 2024/11/24.
//

#include<stdio.h>
            //N为单双数时，汉诺塔的处理方式不同
void Move(int n, char src, char tmp, char dest)
{
    if(n<=0) return ;
    else if(n == 1)
    {
        printf("%c--->%c\n", src, dest);
    }else
    {
        Move(n-1, src, dest, tmp);
        Move(1, src, tmp, dest);
        Move(n-1, tmp, src, dest);
    }
}

//int main()
//{
//    Move(5, 'A', 'B', 'C');
//    return 0;
//}
