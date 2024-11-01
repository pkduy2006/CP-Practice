//Codeforces Round 983 (Div. 2):B. Medians
//https://codeforces.com/contest/2032/problem/B

#include <bits/stdc++.h>
using namespace std;

int ntests, n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while (ntests--)
    {
        cin >> n >> k;

        if(k == 1)
        {
            if(n == 1)
                cout << 1 << '\n' << 1 << '\n';
            else
                cout << -1 << '\n';
        }
        else if(k == n)
            cout << -1 << '\n';
        else
        {
            if(n % 2 == 1)
            {
                if(k % 2 == 0)
                    cout << 3 << '\n' << 1 << ' ' << k << ' ' << k + 1 << '\n';
                else
                    cout << 5 << '\n' << 1 << ' ' << 2 << ' ' << k << ' ' << k + 1 << ' ' << k + 2 << '\n';
            }
            else
                cout << -1 << '\n';
        }
    }
    
    return 0;
}