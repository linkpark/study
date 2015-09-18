#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, string > peple_info;

bool LatelyAncestor( string &name_1, string &name_2, string &result ){
    vector< string > name_1_anc;
    vector< string > name_2_anc;
    string tmp;
    
    name_1_anc.push_back( name_1 );
    name_2_anc.push_back( name_2 );

    tmp = name_1;
    while( peple_info.count(tmp) != 0 ) {
        name_1_anc.push_back( peple_info[tmp] );
        tmp = peple_info[tmp]; 
    }

    tmp = name_2;
    while( peple_info.count(tmp) != 0 ) {
        name_2_anc.push_back( peple_info[tmp] );
        tmp = peple_info[tmp]; 
    }

    for( size_t i = 0; i < name_1_anc.size(); i++ )
        for( size_t j = 0; j < name_2_anc.size(); j++ ) {
       if( name_1_anc[i] == name_2_anc[j] ) {
           result = name_1_anc[i];
           return true;
       }
    }

    return false;
}

int main() {
    int n, m;
    string name_1;
    string name_2;
    string result;

    cin >> n;
    for( int i = 0 ; i< n ; ++i ) {
        cin >> name_1 >> name_2;
        peple_info[ name_2 ] = name_1; 
    }

    cin >> m;

    for( int i = 0; i < m ; ++i ) {
        cin >> name_1 >> name_2;
        
        if( LatelyAncestor(name_1, name_2, result ) ) {
            cout << result <<endl;
        } else {
            cout << -1 <<endl;
        }
    }
}

