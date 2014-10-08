#include "TenForkTree.h"

int main(int argc,char **argv){
    if(2 != argc){
        cout << "Usage: <test> <filename>" <<endl;
        return 0;
    }

    srand( time(NULL) );
    TenForkTree<string> t;
    t.constructRandomTree(3);
    t.serialize( argv[1] );
    t.preorderTraversal();
    cout << endl;

    t.destoryTheTree();

    t.deserialize( argv[1] ); 
    t.preorderTraversal();
    cout << endl;


    t.destoryTheTree();

    return 0;
}

