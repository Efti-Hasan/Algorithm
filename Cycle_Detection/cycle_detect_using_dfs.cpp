#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
vector<int> adj[N];
int parentArray[N];
bool ans;
void dfs(int src)
{
    vis[src]=true;
    // cout <<src <<endl;

    for(int child : adj[src])
    {
        if(vis[child] && child!=parentArray[src])
        {
            ans =true; 
        }
        if(!vis[child])
        {
            vis[child]=true;
            parentArray[child] =src;
            dfs(child);
        }
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    ans = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (ans)
        cout << "Cycle detected";
    else
        cout << "Cycle not detected";
  return 0;
}