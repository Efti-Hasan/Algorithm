#include<bits/stdc++.h>
using namespace std;
vector<int>v[1005];
bool vis[1005];
int level[1005];
void bfs(int src,int des)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src] = 0;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        if(par==des) cout <<level[par] <<endl;
        else cout <<-1<<endl;
        for(auto child : v[par])
        {
            if(vis[child]!=true)
            {
                q.push(child);
                vis[child]=true;
                level[child] = level[par]+1;
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
  int q; cin>>q;
  while(q--)
  {
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    int src,des ;cin>>src>>des;
    bfs(src,des);
  }
     
  return 0;
}