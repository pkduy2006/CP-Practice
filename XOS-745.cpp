//Olympic Sinh Viên 2020 - Không chuyên - Chăn bò
//https://oj.vnoi.info/problem/olp_kc20_cows

#include <bits/stdc++.h>
using namespace std;

long long n, s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    cout << n * (n + 1) / 2 - s;

    return 0;
}