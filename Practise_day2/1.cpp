#include<bits/stdc++.h>
using namespace std;
vector<int>v[1005];
bool vis[1005];
int bfs(int src,int cnt)
{
    queue<int>q;
    q.push(src);

    vis[src]= true;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout <<par <<" ";
        for(int child : v[par])
        {
            if(vis[child]==false)
            {
                cnt++;
                q.push(child);
                vis[child]=true;
            }
        }
    }
    return cnt;
}
int main() 
{
   int n,e; cin>>n>>e;

   while(e--)
   {
    int a,b;
    cin >>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);

   }
    memset(vis,false,sizeof(vis));
   int src; cin>>src;
  cout << bfs(src,1);
   
   return 0;
}
