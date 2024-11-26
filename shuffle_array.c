//
// Created by 123 on 2024/11/26.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//交换数组中两个元素的位置
void SwapElements(int Array[], int First, int Second)
{
  int temp = Array[First];
  Array[First] = Array[Second];
  Array[Second] = temp;
}
////打乱数组，第一种方式
//void ShuffleArray(int Array[], int Length)
//{
//  srand(time(NULL));
//  for (int i = 0; i < Length; ++i) {
//    int Random_Number = rand() % Length;
//    SwapElements(Array, i, Random_Number);
//  }
//}
//打乱数组，第二种方式
void ShuffleArray(int Array[], int Length)
{
  srand(time(NULL));
  for (int i = Length -i; i > 0; --i) {
    int Random_Number = rand() % i;
    SwapElements(Array, i, Random_Number);
  }
}

int main(){
  int Players[50];
  for(int i=0; i<50; ++i){
    Players[i] = i;
  }
  for(int i=0; i<50; ++i){
    printf("%d\t",Players[i]);
  }
  printf("\n");
  ShuffleArray(Players, 50);
  for(int i=0; i<50; ++i){
    printf("%d\t",Players[i]);
  }
  return 0;
}