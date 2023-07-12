#include<bits/stdc++.h> 
using namespace std; 

const int N=1e5; 
bool vis[N]; 
vector<int> adj[N]; 

int main(){
    for(int i=0; i<N; i++){
        vis[i]=false; 
    }
    int n, m; 
    cout<<endl<<"enter the number of vertices: "; 
    cin>>m;
    cout<<endl<<"enter the number of edges: "; 
    cin>>n;  

    for(int i=0; i<n; i++){
        int x, y; 
        cout<<endl<<"enter the source: "; 
        cin>>x;
        cout<<"enter the destination: "; 
        cin>>y;  
        adj[x].push_back(y);
        adj[y].push_back(x); 
    }

    queue<int> q; 
    q.push(1); 
    vis[1]=true; 
    cout<<endl<<"breadth first search: "; 
    while(!q.empty()){
        int node=q.front(); 
        q.pop(); 
        cout<<node<<" ";
        vector<int> :: iterator it; 
        for(it=adj[node].begin(); it!=adj[node].end(); it++){
            if(!vis[*it]){
                vis[*it]=true; 
                q.push(*it); 
            }
        }
    }
    return 0; 
}
