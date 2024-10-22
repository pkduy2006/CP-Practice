#include <bits/stdc++.h>
using namespace std;

int s_len, res;
string s;

bool check_palind(string x)
{
    for(int i = 0; i <= x.size() / 2; i++)
    {
        if(x[i] != x[x.size() - 1 - i])
            return false;
    }

    return true;
}

bool check(int len)
{
    for(int i = 0; i < s_len - len + 1; i++)
    {
        string s_sub = s.substr(i, len);
        if(check_palind(s_sub) == false)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s_len >> s;
    int l = 2, r = s_len;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
        {
            l = mid + 1;
            res = mid;
        }
        else
            r = mid - 1;
    }

    cout << res;

    return 0;
}