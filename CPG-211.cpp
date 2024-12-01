//Rayan Programming Contest 2024 - Selection (Codeforces Round 989, Div. 1 + Div. 2) C. Trapped in the Witch's Labyrinth
//https://codeforces.com/contest/2034/problem/C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 8;
int ntests, n, m;
string a[N];
char b[N][N];
bool vis[N][N], mark[N][N];
vector<pair<int, int>> c[N][N];

void bfs(int x, int y)
{
    //cout << x << ' ' << y << '\n';
    vis[x][y] = true;
    queue<pair<int, int>> q;
    set<pair<int, int>> path;
    q.push({x, y});
    path.insert({x, y});
    while(!q.empty())
    {
        int cur_x = q.front().first, cur_y = q.front().second;
        //cout << cur_x << ' ' << cur_y << '\n';
        q.pop();

        for(auto i : c[cur_x][cur_y])
        {
            //cout << i.first << ' ' << i.second << '\n';
            if(mark[i.first][i.second] || i.first < 1 || i.first > n || i.second < 1 || i.second > m)
            {
                //cout << i.first << ' ' << i.second << '\n';
                for(auto it = path.begin(); it != path.end(); it++)
                    mark[it->first][it->second] = true;
                mark[cur_x][cur_y] = true;
                continue;
            }

            if(vis[i.first][i.second])
                continue;
            vis[i.first][i.second] = true;
            path.insert({i.first, i.second});
            q.push({i.first, i.second});
        }
    }
}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            b[i][j] = a[i][j - 1];
    }

    for(int i = 0; i <= n + 1; i++)
    {
        for(int j = 0; j <= m + 1; j++)
        {
            mark[i][j] = false;
            vis[i][j] = false;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            c[i][j].clear();
            if(b[i][j] == 'U')
                c[i][j].push_back({i - 1, j});
            else if(b[i][j] == 'D')
                c[i][j].push_back({i + 1, j});
            else if(b[i][j] == 'L')
                c[i][j].push_back({i, j - 1});
            else if(b[i][j] == 'R')
                c[i][j].push_back({i, j + 1});
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!vis[i][j])
                bfs(i, j);
        }
    }

    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << mark[i][j] << ' ';
        cout << '\n';
    }
    */
   for(int i = 1; i <= n; i++)
        mark[i][0] = mark[i][m + 1] = true;
    for(int j = 1; j <= m; j++)
        mark[0][j] = mark[n + 1][j] = true;
    
    
   for(int i = 1; i <= n; i++)
   {
        for(int j = 1; j <= m; j++)
        {
            if(b[i][j] == '?' && mark[i + 1][j] && mark[i - 1][j] && mark[i][j - 1] && mark[i][j + 1])
                mark[i][j] = true;
        }
   }

   int res = 0;
   for(int i = 1; i <= n; i++)
   {
        for(int j = 1; j <= m; j++)
        {
            if(!mark[i][j])
                res++;
        }
   }

   /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << mark[i][j] << ' ';
        cout << '\n';
    }
    */

   cout << res << '\n';
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