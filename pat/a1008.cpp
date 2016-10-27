#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int n,f=0,nf,t=0;
  scanf("%d",&n);
  for (int i = 1; i <= n; ++i){
    scanf("%d", &nf);
    if (nf > f){
      t += (nf - f) * 6;
    }
    if (nf < f){
      t += (f - nf) * 4;
    }
    t += 5;
    f = nf;
  }
  printf("%d\n",t);
  return 0;
}