//Codeforces Round 984 (Div. 3) D. I Love 1543
//https://codeforces.com/contest/2036/problem/D
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 8;
int ntests, n, m, a[N][N];

void solve() 
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++)
            a[i][j] = s[j - 1] - '0';
    }
    
    int left = 1, right = m, top = 1, bottom = n, res = 0;
    while(left < right && top < bottom)
    {
        vector<int> wire;
        for(int i = left; i <= right - 1; i++)
            wire.push_back(a[top][i]);
        for(int i = top; i <= bottom - 1; i++)
            wire.push_back(a[i][right]);
        for(int i = right; i >= left + 1; i--)
            wire.push_back(a[bottom][i]);
        for(int i = bottom; i >= top + 1; i--)
            wire.push_back(a[i][left]);
        wire.push_back(wire[0]);
        wire.push_back(wire[1]);
        wire.push_back(wire[2]);
        //for(int i = 0; i < wire.size(); i++)
        //    cout << wire[i] << ' ';
        //cout << '\n';
        for(int i = 0; i < wire.size() - 3; i++)
        {
            if(wire[i] == 1 && wire[i + 1] == 5 && wire[i + 2] == 4 && wire[i + 3] == 3)
                res++;
        }
        
        left++;
        right--;
        top++;
        bottom--;
    }

    cout << res << '\n';
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