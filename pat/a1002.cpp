// 题意

// 给定两多项式，相加并格式化输出结果。

// 分析

// 两种思路

// 1.采用链表的处理方式；
// 2.预设好a[1001]的数组，用下标表示次方，数组中元素值表示对应系数。
// 第一种方法某种程度上看能节省空间，实现上需要注意操作链表时，循环时的越界问题； 方法二用空间换取时间，且实现上更不容易出错。同时，由于浮点数本身精确位数不够，在判定两浮点数相加是否为0时， 需要对结果值取绝对值后，与1e-6做对比。

#include <iostream>
#include <math.h>
using namespace std;
#define M 1000
double a[M + 1];

int main()
{
  int expo,k;
  double coef;
  int count = 0;
  int loop = 2;
  while (loop--){
    cin >> k;
    for (int i = 0; i < k; ++i){
      cin >> expo >> coef;
      if (fabs(a[expo]) < 1e-8){
        ++count;
      }
      a[expo] += coef;
      if (fabs(a[expo]) < 1e-8){
        --count;
      }
    }
  }
  cout << count;
  for (int i = 1000; i >= 0; --i){
    if (fabs(a[i]) > 1e-8){
      printf(" %d %.1lf",i,a[i]);
    }
  }
  return 0;
}