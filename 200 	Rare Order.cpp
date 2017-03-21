#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<string> vs;
string s;
vector<int> adj[N];
int vis[N];
vector<char> top;
set<char> ss;

void dfs(char c){
    vis[c] = 1;
    for(int nxt : adj[c])
        if(!vis[nxt])
            dfs(nxt);
    top.push_back(c);
}

int main()
{
    while(true){
        cin >> s;
        if(s == "#")break;
        vs.push_back(s);
        for(int i = 0 ; i < s.size() ; i++)
            ss.insert(s[i]);
    }

    for(int i = 0 ; i < vs.size() - 1 ; i++){
        for(int j = 0 ; j < min(vs[i].size() , vs[i+1].size()) ; j++){
            if(vs[i][j] == vs[i+1][j])continue;
            adj[vs[i][j]].push_back(vs[i+1][j]);
            break;
        }
    }

    for(char c : ss)
        if(!vis[c])
            dfs(c);

    reverse(top.begin() , top.end());
    for(int i = 0 ; i < top.size() ; i++)
        printf("%c",top[i]);
    puts("");

    return 0;
}
