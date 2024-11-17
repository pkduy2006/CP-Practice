//Codeforces Round 988 (Div. 3) C. Superultra's Favorite Permutation
//https://codeforces.com/contest/2037/problem/C
#include <bits/stdc++.h>
using namespace std;

int ntests, n;

bool check(int x)
{
    if(x < 2)
        return false;
    
    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x % i == 0)
            return true;
    }

    return false;
}

void solve()
{
    cin >> n;
    
    if(n < 5)
    {
        cout << -1 << '\n';
        return;
    }

    int last_odd_num, start_even_num;
    if(n % 2 == 0)
        last_odd_num = n - 1;
    else
        last_odd_num = n;
    
    for(int i = 2; i <= n; i += 2)
    {
        if(check(last_odd_num + i))
        {
            start_even_num = i;
            break;
        }
    }

    for(int i = 1; i <= n; i += 2)
        cout << i << ' ';
    cout << start_even_num << ' ';
    for(int i = 2; i <= n; i += 2)
    {
        if(i != start_even_num)
            cout << i << ' ';
    }
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