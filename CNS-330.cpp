//Codeforces Round 992 (Div. 2) B. Paint a Strip
//https://codeforces.com/contest/2040/problem/B
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int res[N], ntests;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    res[1] = 1;
    res[2] = res[3] = res[4] = 2;
    int ans = 3, r = 10;
    for(int i = 5; i <= 100000; i++)
    {
        res[i] = ans;
        if(i == r)
        {
            ans++;
            r = (i + 1) * 2;
        }
    }

    cin >> ntests;
    while(ntests--)
    {
        int n;
        cin >> n;
        cout << res[n] << '\n';
    }

    return 0;
}