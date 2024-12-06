//Codeforces Round 991 (Div. 3) D. Digital string maximization
//https://codeforces.com/contest/2050/problem/D
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
int ntests, a[N];
string s;

void solve()
{
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++)
        a[i] = s[i] - '0';
    for(int j = 0; j < s.size(); j++)
    {
        int moved = j;
        for(int i = j + 1; i <= j + 8 && i < n; i++)
        {
            if(a[i] - i + j > a[j])
            {
                if(a[i] - i + j > a[moved] - moved + j)
                    moved = i;
            }
        }

        if(moved == j)
            continue;
        
        for(int i = moved; i >= j + 1; i--)
        {
            a[i]--;
            swap(a[i], a[i - 1]);
        }
    }

    for(int i = 0; i < n; i++)
        cout << a[i];
    cout << '\n';
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