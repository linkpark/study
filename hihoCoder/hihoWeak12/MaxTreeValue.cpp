#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > edge_set(201);
queue<int> que;

int node_value[201] = {0};
int max_value_node[201][201] = {{0}};

void AddEdge( int to, int next ) {
    edge_set[to].push_back( next );
    edge_set[next].push_back( to );  
}

void MaxValue(int pre, int root, int M ) {
    for( size_t i = 0; i < edge_set[root].size(); ++i ) {
        if( pre == edge_set[root][i] )
            continue;
        MaxValue( root, edge_set[root][i], M );
    }

    for( size_t i = 0; i < edge_set[root].size(); ++i ) {
        if( pre == edge_set[root][i] )
            continue;

        for( int m = M ; m > 1; --m ) {
            for( int m_child = 1 ; m_child < m ; ++m_child )
                max_value_node[root][m] = std::max( max_value_node[root][m], 
                        max_value_node[root][m-m_child] + max_value_node[ edge_set[root][i] ][m_child] );
        }
    } 

}

int main() {
    int n, m;
    cin >> n >> m;
    
    for( int i = 1; i <= n; ++i ) {
        cin >> max_value_node[i][1]; 
    }

    for( int i = 1; i < n; ++i ) {
        int point_to, point_next;
        cin >> point_to >> point_next;
        
        AddEdge( point_to, point_next );
    }

    MaxValue(0, 1, m );

    cout << max_value_node[1][m] <<endl;
}

