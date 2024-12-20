//Codeforces Global Round 28 C. Kevin and Binary Strings
//https://codeforces.com/contest/2048/problem/C 
#include <bits/stdc++.h>
using namespace std;

string s;
int ntests;

void solve()
{
    cin >> s;
    int l1 = 1, r1 = s.size(), l2 = 1, r2 = 1, len = 1;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '0')
        {
            len = s.size() - i;
            break;
        }
    }
    if(len == 1)
        cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
    else
    {
        string ans = "";
        for(int i = 0; i < s.size(); i++)
            ans += '0';
        for(int i = 0; i < s.size() - len + 1; i++)
        {
            string x = s.substr(i, len);
            string total = "";
            while(x.size() < s.size())
                x = '0' + x;
            for(int j = 0; j < x.size(); j++)
            {
                if(x[j] == s[j])
                    total += '0';
                else
                    total += '1';
            }
            //out << ans << ' ' << total << ' ' << x << '\n';
            if(ans < total)
            {
                l2 = i + 1;
                r2 = i + len;
                ans = total;
            }
        }
        cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
    }
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