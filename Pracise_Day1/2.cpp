#include<bits/stdc++.h>
using namespace std;
vector<int>v[1005];
bool vis[1005];
vector<int>ans;
void bfs(int src, int lv)
{
    queue<pair<int,int>>q;
    q.push({src,0});
    vis[src]=true;

    while(!q.empty())
    {
        pair<int,int> p = q.front();
        int par = p.first;
        int level = p.second;
        q.pop();

        if(level==lv)
        {
            ans.push_back(par);
        }
        for(auto child : v[par])
        {
            if(!vis[child])
            {
                q.push({child,level+1});
                vis[child]=true;
            }
        }
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

      int n,e; cin>>n>>e;
    while(e--)
    {
        int a,b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));
    int lv ;cin>>lv;
    bfs(0,lv);
    reverse(ans.begin(),ans.end());
    for(auto val : ans) cout <<val <<" ";
  return 0;
}