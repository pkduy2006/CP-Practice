//Bedao Mini Contest 25: Trọng số lẻ
//https://oj.vnoi.info/problem/bedao_m25_a

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 25;
const long long MOD = 1e9 + 7;
int n, cnt_odd;
long long sum_odd, sum, a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] % 2 == 1)
        {   
            sum_odd += a[i];
            sum_odd %= MOD;
            cnt_odd++;
        }
    }
    //cout << sum_odd << ' ' << cnt_odd;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] % 2 == 0)
        {
            sum += (sum_odd + (cnt_odd * a[i]) % MOD) % MOD;
            sum %= MOD;
            //cout << a[i] << '\n';
        }
    }

    cout << sum;
    
    return 0;
}