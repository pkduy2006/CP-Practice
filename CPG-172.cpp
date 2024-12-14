//Educational Codeforces Round 172 (Rated for Div. 2) C. Competitive Fishing
//https://codeforces.com/problemset/problem/2042/C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, k, a[N], sum, res;
string s;

void solve()
{
    fill(a, a + n, 0);
    vector<int> val;
    sum = res = 0;
    cin >> n >> k >> s;
    for (int i = n - 1; i > 0; i--)  
    {
        a[i] = a[i + 1] + ((s[i] == '1') ? 1 : -1);
        if(a[i] > 0)
            val.push_back(a[i]);
    }

    sort(val.begin(), val.end());
    //for(int i = val.size() - 1; i >= 0; i--)
      //  cout << val[i] << ' ';
   // cout << '\n';
    for(int i = val.size() - 1; i >= 0; i--)
    {
        if(sum < k)
        {
            sum += val[i];
            res++;
        }
        else
            break;
    }

    if(sum < k)
        cout << -1 << '\n';
    else
        cout << res + 1 << '\n';
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