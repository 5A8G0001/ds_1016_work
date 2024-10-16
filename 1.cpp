#include<bits/stdc++.h>

using namespace std;

bool cmp(const pair<char,int>&a , const pair<char,int>&b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second > b.second;
    }
}


int main()
{
    int x = 0;
    cin >> x;

    vector<string> v;
    vector<pair<char,int>> ans;
    unordered_map<char,int> mp;


    for(int i = 0 ; i < x+1 ; i++)
    {
        string ret;
        getline(cin,ret);
        v.emplace_back(ret);
    }

    for(int i = 0 ; i < v.size() ; i++)
    {
        //cout << v[i] << endl;
        for(int j = 0 ; j < v[i].size() ; j++)
        {
            if(isalpha(v[i][j]))
            {
                //cout << v[i][j] << ' ';
                if(v[i][j] > 90)
                {
                    mp[v[i][j]-32]++;
                }
                else
                {
                    mp[v[i][j]]++;
                }
            }
        }
    }

    for(auto i : mp)
    {
        //cout << i.first << " " << i.second << endl;
        ans.push_back(make_pair(i.first,i.second));
    }

    sort(ans.begin(),ans.end(),cmp);

    for(auto i : ans)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
