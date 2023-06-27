#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define so sort(a , a+n)
#define migmig ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
const int maxn=2*1e5+50;

bool compare(pair<pair<int,int>,double> a, pair<pair<int,int>,double> b) 
{return(a.second < b.second);}

int parent_find(int x, vector<int>& parent) {
    while(parent[x] != x) x = parent[x];
    return x;
}

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visit) {
    visit[u] = true;
    for(auto v : adj[u]) if(!visit[v]) dfs(v, adj, visit);
}

int unite(int v1, int v2, vector<int>& parent, vector<int>& grade) {
    v2 = parent_find(v2, parent);v1 = parent_find(v1, parent); 
    if (v1 == v2) return 0; 
    if(grade[v1] < grade[v2]) swap(v1, v2);
    parent[v2] = v1;
    if(grade[v1] == grade[v2]) grade[v1]++;
    return 1; 
}


int main() 
{
    int Num;cin >> Num;
    for(int i=1; i<=Num; i++) {
        int n, r;cin >> n >> r;

        vector<pair<int, int>> Graphland(n);
        vector<pair<pair<int,int>,double>> Graph;
	vector<int> parent(n);
        vector<int> grade(n, 0);
	vector<vector<int>> adj(n);	
	double RoadLength = 0 , RailLength = 0;
        int num_states = 0;

        for(int j=0; j<n; j++) cin >> Graphland[j].first >> Graphland[j].second;

        for(int j=0; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                double d = sqrt(pow(Graphland[j].first - Graphland[k].first, 2) + pow(Graphland[j].second - Graphland[k].second, 2));
                Graph.pb({{j, k},d});
            }
        }

        sort(Graph.begin(), Graph.end() , compare);
        for(int j=0; j<n; j++) parent[j] = j;
        for(auto e : Graph) { 
            int u = e.first.first, v = e.first.second;
            double Weight = e.second;
            if(Weight <= r && parent_find(u, parent) != parent_find(v, parent)) {
                unite(u, v, parent, grade);
                RoadLength += Weight;
                adj[u].pb(v);
                adj[v].pb(u); 
            }
        }

        vector<bool> visit(n, false);
        for(int u=0; u<n; u++) { 
            if(!visit[u]) {
            dfs(u, adj, visit);
            num_states++;
        }
    }

    for(auto e : Graph) {
        int u = e.first.first, v = e.first.second;
        double Weight = e.second;
        if(Weight > r && parent_find(u, parent) != parent_find(v, parent)) {
            unite(u, v, parent, grade);
            RailLength += Weight;

            adj[u].pb(v); 
            adj[v].pb(u);
        }
    }

    cout <<"Case #"<<i<<": "<<num_states<<' '<<
    round(RoadLength) <<' '<< round(RailLength)<<'\n';
    }
}
