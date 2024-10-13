//Free Contest 110: ODDSUM
//https://oj.vnoi.info/problem/fc110_oddsum

#include <bits/stdc++.h>
using namespace std;

int n;
long long res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        if(i % 2 == 1)
           res += x;
    }
    cout << res;
    return 0;
}