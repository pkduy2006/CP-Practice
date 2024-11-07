//Codeforces Round 984 (Div. 3) C. Anya and 1100
//https://codeforces.com/contest/2036/problem/C
#include <bits/stdc++.h>
using namespace std;

int ntests, q, pos;
char value;
string s;

void solve()
{
    cin >> s >> q;
    int cnt = 0;
    for(int i = 0; i < s.size() - 3; i++)
    {
        if(s.substr(i, 4) == "1100")
            cnt++;
    }
    while (q--)
    {
        cin >> pos >> value;
        pos--;
        int before = 0, after = 0;
        for(int i = max(0, pos - 3); i <= min(pos + 3, int(s.size() - 1)); i++)
        {
            if(s.substr(i, 4) == "1100")
                before++;
        }
        s[pos] = value;
        
        for(int i = max(0, pos - 3); i <= min(pos + 3, int(s.size() - 1)); i++)
        {
            if(s.substr(i, 4) == "1100")
                after++;
        }
        //cout << cnt << ' ' << after << ' ' << before << '\n';
        cnt += after - before;
        if(cnt > 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while (ntests--)
        solve();
    
    return 0;
}