#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
map<int,vector<int>> adjlist;
int record[101] = { 0 };
void DFS(int id, int level){
    if (adjlist[id].empty()){
        ++record[level];
        return;
    }
    vector<int>::iterator ite = adjlist[id].begin();
    for (; ite != adjlist[id].end(); ++ite){
        DFS(*ite, level + 1);
    }
}
int main()
{
    int m, n, k, cle,id,sid,cnt;
    cin >> n >> m;
    cle = n - m;
    while (m--){
        cin >> id >> k;
        while (k--){
            cin >> sid;
            adjlist[id].push_back(sid);
        }
    }
    DFS(1, 0);
    fclose(stdin);
    freopen_s(&stream, "out.txt", "w", stdout);
    cout << record[0];
    cnt = record[0];
    for (int i = 1; cnt < cle; i++){
        cout <<" "<< record[i];
        cnt += record[i];
    }
    return 0;
}