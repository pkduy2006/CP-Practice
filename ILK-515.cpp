//Codeforces Round 983 (Div. 2): C. Trinity
//https://codeforces.com/contest/2032/problem/C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
int ntests, a[N], n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while (ntests--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        
        sort(a + 1, a + 1 + n);
        int i = 1, answer = n - 2;
        for(int j = 3; j <= n; j++)
        {
            while (j - i >= 2 && a[i] + a[i + 1] <= a[j])
                i++;
            answer = min(answer, n - (j - i + 1));
        }

        cout << answer << '\n';
    }

    return 0;
}