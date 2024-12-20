//Codeforces Round 994 (Div. 2) B. pspspsps
//https://codeforces.com/contest/2049/problem/B
#include <bits/stdc++.h>
using namespace std;

int ntests, n;
string s;

bool check(string a)
{
    int cnts = 0, cntdot = 0, cntp = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == 's')
            cnts++;
        else if(a[i] == '.')
            cntdot++;
        else
            cntp++;
    }

    if(cnts + cntdot == a.size())
        return true;
    if(cntp + cntdot == a.size())
        return true;
    if(cntp == 1 && a[a.size() - 1] == 'p')
        return true;
    if(cnts == 1 && a[0] == 's')
        return true;
    return false;
}

void solve()
{
    cin >> n >> s;
    
    if(check(s))
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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