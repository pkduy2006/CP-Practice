//Rayan Programming Contest 2024 - Selection (Codeforces Round 989, Div. 1 + Div. 2) A. King Keykhosrow's Mystery
//https://codeforces.com/contest/2034/problem/A
#include <bits/stdc++.h>
using namespace std;

int ntests, x, y;

int count_gcd(int a, int b)
{
    while(b != 0)
    {
        int c = b;
        b = a % b;
        a = c;
    }

    return a;
}

int count_lcm(int a, int b)
{
    int tmp = count_gcd(a, b);
    return a * b / tmp;
}

void solve()
{
    cin >> x >> y;

    cout << count_lcm(x, y) << '\n';
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