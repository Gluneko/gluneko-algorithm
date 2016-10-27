#include <string>
#include <iostream>
#include <vector>

using namespace std;
string str[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int main()
{
  int sum = 0, di = 0;
  string num;
  vector<string> res;
  cin >> num;
  for (auto n : num){
    sum += n - '0';
  }
  int temp = sum;
  while (temp){
    ++di;
    temp /= 10;
  }
  if (sum == 0){
    cout << "zero";
    return 0;
  }
  while (di){
    res.push_back(str[sum % 10]);
    sum /= 10;
    --di;
  }
  for (int i = res.size() - 1; i > 0; --i){
    cout << res[i] << " ";
  }
  cout << res[0] << endl;
  system("pause");
  return 0;
}