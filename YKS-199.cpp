//Codeforces Round 993 (Div. 4) B. Normal Problem
//https://codeforces.com/contest/2044/problem/B 
#include <bits/stdc++.h>
using namespace std;

int ntests;
string a, b;

void solve()
{
    cin >> a;
    b = "";
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == 'p')
            b += 'q';
        else if(a[i] == 'q')
            b += 'p';
        else
            b += 'w';
    }
    reverse(b.begin(), b.end());
    cout << b << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}