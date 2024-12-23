//
// Created by 123 on 2024/12/17.
//
#include <stdio.h>
#include <stdlib.h>
#include "io_utils.h"

//交换数组中两个元素的位置
void SwapElements(int Array[], int First, int Second)
{
  int temp = Array[First];
  Array[First] = Array[Second];
  Array[Second] = temp;
}

//void test_rand(void)
//{
//  unsigned long n;
//  srand((unsigned)time(NULL));     //随机数测试代码
//  for(int i = 0; i < 100; i++)
//  {
//    n = rand();
//    printf("%d\n", n);
//  }
//}

//打乱数组，第二种方式
void ShuffleArray(int Array[], int Length)
{
  srand((unsigned)time(NULL));
  for (int i = Length -i; i > 0; --i) {
    int a= rand();            //修改为直接将随机数插入数组
    Array[i] = a;
    //int Random_Number = rand() % i;
    //SwapElements(Array, i, Random_Number);
  }
}

//快速排序
void quick_sort(int arr[], int left, int right)
{
  if (left >= right) return;   //判断左右指针是否到达搜索边界
  int i = left, medium = arr[left], j = right;       // 定义左右界及中位数
  while (i < j)
  {
    while (arr[i] < medium) i++;
    while (arr[j] > medium) j--;
//    for (i; arr[i] < medium; ++i)
//    for (j; arr[j] > medium; --j)
    if(i < j)
    {
          SwapElements(arr, i, j);
    }
  }
  quick_sort(arr, left, j - 1);         //递归
  quick_sort(arr, j + 1, right);
}

//void quick_sort(int q[], int l, int r)
//{
//  if (l >= r) return;
//  int i = l - 1, j = r + 1, x = q[l + r >> 1];
//  while (i < j)
//  {
//    do i ++ ; while (q[i] < x);
//    do j -- ; while (q[j] > x);
//    if (i < j)
//    {
//      int temp = q[i];
//      q[i] = q[j];
//      q[j] = temp;
//    }
//  }
//  quick_sort(q, l, j);
//  quick_sort(q, j + 1, r);
//}

int main()
{
  int Players[50] = {0};             //新建数组并初始化
  for (int i = 0; i < 50; i++)
  {
    Players[i] = i;                   //插入数字
  }

  ShuffleArray(Players, 50);          //打乱数组
  PRINT_INT_ARRAY(Players, 50);    //打印数组
  quick_sort(Players, 0, 49);      //快排
  PRINT_INT_ARRAY(Players, 50);
  return 0;
}
