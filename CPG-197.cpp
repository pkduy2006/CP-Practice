//Codeforces Round 991 (Div. 3) C. Uninteresting Number
//https://codeforces.com/contest/2050/problem/C
#include <bits/stdc++.h>
using namespace std;

int ntests;
string s;

void solve()
{
    cin >> s;
    int sum = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 0; i < s.size(); i++)
    {
        sum += (s[i] - '0');
        if(s[i] == '2')
            cnt2++;
        if(s[i] == '3')
            cnt3++;
    }
    
    if(sum % 9 == 0)
        cout << "YES" << '\n';
    else if(sum % 9 == 1 && (cnt2 >= 4 || (cnt2 >= 1 && cnt3 >= 1)))
        cout << "YES" << '\n';
    else if(sum % 9 == 2 && (cnt2 >= 8 || (cnt2 >= 2 && cnt3 >= 2)) || (cnt2 >= 5 && cnt3 >= 1))
        cout << "YES" << '\n';
    else if(sum % 9 == 3 && (cnt2 >= 3 || cnt3 >= 1))
        cout << "YES" << '\n';
    else if(sum % 9 == 4 && (cnt2 >= 7 || (cnt3 >= 1 && cnt2 >= 4) || (cnt3 >= 2 && cnt2 >= 1)))
        cout << "YES" << '\n';
    else if(sum % 9 == 5 && cnt2 >= 2)
        cout << "YES" << '\n';
    else if(sum % 9 == 6 && (cnt2 >= 6 || (cnt3 >= 1 && cnt2 >= 3) || cnt3 >= 2))
        cout << "YES" << '\n';
    else if(sum % 9 == 7 && cnt2 >= 1)
        cout << "YES" << '\n';
    else if(sum % 9 == 8 && (cnt2 >= 5 || (cnt3 >= 1 && cnt2 >= 2)))
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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