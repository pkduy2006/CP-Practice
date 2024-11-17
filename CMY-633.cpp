//Codeforces Round 988 (Div. 3) D. Sharky Surfing
//https://codeforces.com/contest/2037/problem/D
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 8;
int ntests, n, m, l;
pair<int, int> hurdle[N], powerup[N];

void solve()
{
    cin >> n >> m >> l;
    for(int i = 1; i <= n; i++)
        cin >> hurdle[i].first >> hurdle[i].second;
    for(int i = 1; i <= m; i++)
        cin >> powerup[i].second >> powerup[i].first;
    
    priority_queue<pair<int, int>> remained_powerup;
    int current_power = 1, cnt = 0, idx = 1;
    
    for(int i = 1; i <= n; i++)
    {
        while (powerup[idx].second < hurdle[i].first && idx <= m)
        {
            remained_powerup.push(powerup[idx]);
            idx++;
        }

        int min_power = hurdle[i].second - hurdle[i].first + 2;
        while(!remained_powerup.empty() && current_power < min_power)
        {
            int x = remained_powerup.top().first;
            current_power += x;
            remained_powerup.pop(); 
            cnt++;
        }
        //cout << current_power << ' ' << min_power << '\n';
        if(current_power < min_power)
        {
            cnt = -1;
            break;
        }
    }
    
    cout << cnt << '\n';
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