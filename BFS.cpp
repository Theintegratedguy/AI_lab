/*graph traversal: BFS
- we must have a starting point, coz there is no root!

Steps: 
1. go to the immediate neighbour first, adj ke adj se pehle apne sabhi adjes traverse karle!
2.   DS = queue, a visited array
3. the operation takes place as: 
 - print(curr)
 - vis[curr]=T
 - enqueue the currnode's neighbour  

 - O(V+E) = time complexity
*/
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
        adj[y].push_back(x);    // 2 push_backs because it is an undirected graph
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

/*
        1 -- 3
       /     |\
      0      |  5 -- 6    a possible bfs=0 1 2 3 4 5 6
       \     | /    
        2 -- 4
 */
