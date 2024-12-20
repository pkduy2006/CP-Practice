//Codeforces Global Round 28 A. Kevin and Combination Lock
//https://codeforces.com/contest/2048/problem/A 
#include <bits/stdc++.h>
using namespace std;

int ntests;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
    {
        int x;
        cin >> x;

        if(x % 33 == 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}