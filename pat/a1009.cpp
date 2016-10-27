#include <stdio.h>
#include <math.h>

using namespace std;
int n, x, cnt;
double a[1001], b[1001], c[2002];
int main()
{
  scanf("%d",&n);
  while (n--){
    scanf("%d", &x);
    scanf("%lf", &a[x]);
  }
  scanf("%d", &n);
  while (n--){
    scanf("%d", &x);
    scanf("%lf", &b[x]);
  }
  for (int i = 0; i < 1001; i++){
    for (int j = 0; j < 1001; j++){
      c[i + j] += a[i] * b[j];
    }
  }
  cnt = 0;
  for (int i = 0; i < 2001; i++){
    if (fabs(c[i]) > 1e-8) cnt++;
  }
  printf("%d", cnt);
  for (int i = 2000; i >= 0; --i){
    if (fabs(c[i]) > 1e-8) printf(" %d %.1lf", i, c[i]);
  }
  return 0;
}