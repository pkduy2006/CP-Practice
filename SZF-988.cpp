//Codeforces Round 994 (Div. 2) A. MEX Destruction 
//https://codeforces.com/contest/2049/problem/A
#include <bits/stdc++.h>
using namespace std;

const int N = 57;
const int INF = 1e9 + 7;
int ntests, a[N], n;

void solve()
{
    int cnt0 = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    a[0] = INF;
    vector<int> b;
    for(int i = 1; i <= n; i++)
    {
        if(a[i - 1] == 0 && a[i] == 0)
            continue;
        
        b.push_back(a[i]);
    }
    for(int i = 0; i < b.size(); i++)
    {
        if(b[i] == 0)
            cnt0++;
    }

    if(cnt0 == b.size())
        cout << 0 << '\n';
    else if(cnt0 == 0 || (cnt0 == 1 && (b[0] == 0 || b[b.size() - 1] == 0)) || (cnt0 == 2 && b[0] == 0 && b[b.size() - 1] == 0))
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
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