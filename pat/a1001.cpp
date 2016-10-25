#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, sum, i;
    i = 1;
    cin >> a >> b;
    sum = a + b;
    if (sum < 0)
    {
        sum = -sum;
        cout << "-";
    }else if(sum == 0){
    cout << "0";
    }
    string str;
    char ch;
    while (sum)
    {
        ch = '0' + sum % 10;
        sum /= 10;
        if (i % 4 == 0)
        {
            str.push_back(',');
            i = 1;
        }
        str.push_back(ch);
        i++;
    }
    reverse(str.begin(), str.end());
    cout << str;
    system("pause");
    //return 0;
}

