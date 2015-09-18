#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > edge(1000001);
int longest_path = 0;

int dfs(int pre, int root ) {
    int first = 0;
    int second = 0;
    
    //travse the adjacent
    for( size_t i = 0; i < edge[root].size(); ++i ) {
        if( edge[root][i] == pre )
           continue;
        
        int tmp = dfs( root, edge[root][i] );
        if( tmp  > first ){
            second = first;
            first = tmp;
        } else if ( tmp > second ) {
            second = tmp;
        }
    }
    
    longest_path = max( longest_path, first+second );

    return first+1;
}

void AddEdge( int s, int v ) {
    edge[s].push_back(v);
    edge[v].push_back(s);
}

int main() {
    int n, v,s;
    cin >> n;
    for( int i = 1; i < n ; ++i ) {
        cin >> v >>s;
        AddEdge(v,s);
    }

    dfs(0,1);
    
    cout << longest_path <<endl;

    return 0;
}

