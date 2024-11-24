#include <stdio.h>
#include <stdarg.h>

void HandleVarargs(int arg_count, ...)
{
    va_list args;
    va_start(args, arg_count);
    for(int i=0; i<arg_count; i++)
    {
        int arg = va_arg(args, int);
        printf("%d : %d\n", i, arg);
    }
    va_end(args);
}

//int main() {
////    printf("Hello, World!\n");
////    for (int i = 0; i < 5; ++i) {
////        printf("i = %d Hello, World!\n", i);
////    }
//    HandleVarargs(4,1,3,4,8);
//    return 0;
//}
