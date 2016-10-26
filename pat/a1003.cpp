// 参考：http://blog.csdn.net/iaccepted/article/details/21451949
// 题目的意思就是一张图，各边都有权值而且个点也有权值，求出给定两点之间最短路的条数并输出此路径上的点权值和的最大值。就是求出最短路的条数，若有多条相同的最短路输出最大的那个点权值和。
// 很简单的题目，一个dfs就可以很好的解决掉。
// 当然这个题目还可以继续增加点复杂度，就是把各条最短路的路径打印出来，这个也是很好实现的，加个pre数组，然后可以再来个dfs，当然也可以先来遍迪杰斯特拉。
#include <stdio.h>
#include <climits>
#include <iostream>
using namespace std;
#define MAX 501

int wei[MAX], visited[MAX], map[MAX][MAX];
int mind, maxw, cnt, n;
void init(int n)
{
  for (int i = 0; i < n; i++)
  {
    visited[i] = 0;
    for (int j = 0; j < n; j++){
      map[i][j] = INT_MAX;
    }
  }
}
void dfs(int sta, int end, int dist, int weit)
{
  if (sta == end){
    if (dist < mind){
      cnt = 1;
      mind = dist;
      maxw = weit;
    }
    else if (dist == mind){
      cnt++;
      maxw = weit > maxw ? weit : maxw;
    }
  }
  if (dist > mind) return;
  for (int i = 0; i < n; i++){
    if (visited[i] == 0 && map[sta][i] != INT_MAX){
      visited[i] = 1;
      dfs(i, end, dist + map[sta][i], weit + wei[i]);
      visited[i] = 0;
    }
  }
}
int main()
{
  int m, st, ed, x, y, z;
  mind = INT_MAX;
  cnt = 0;
  cin >> n >> m >> st >> ed;
  init(n);
  for (int i = 0; i < n; i++){
    cin >> wei[i];
  }
  while (m--){
    cin >> x >> y >> z;
    if (map[x][y] > z){
      map[x][y] = map[y][x] = z;
    }
  }
  dfs(st, ed, 0, wei[st]);
  printf("%d %d\n", cnt, maxw);
  return 0;
}