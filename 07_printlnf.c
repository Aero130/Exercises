//
// Created by 123 on 2024/11/24.
//

#include<stdio.h>
#include<stdarg.h>

void PrintLNF(const char *format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  printf("\n");
  va_end(args);
}

//#define PrintLNF2(format, ...) printf(format"\n", ##__VA_ARGS__)
#define Print_INT(format, ...) printf(#format"\t%d""\n", format)
#define PrintLNF2(format, ...) printf("("__FILE__"%d)\t%s\t"format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)

//int main() {
//  int value = 2;
//  PrintLNF("hello word\t %d", value);
//  PrintLNF2("Hello Word\t %d", value);
//  PrintLNF2("Hello Word");
//  Print_INT(value);
//  int X = 3;
//  Print_INT(X);
//  Print_INT(3 + 4);
//
//  return 0;
//}