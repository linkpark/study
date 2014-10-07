#include "TenForkTree.h"

int main(int argc,char **argv){
    if(3 != argc){
        cout << "Usage: <test> <deserilize file> <seriliaze file>" <<endl;
        return 0;
    }

    TenForkTree<string> t;
    t.deserialize( argv[1] ); 
    t.serialize( argv[2] );
    t.preorderTraversal();

    t.destoryTheTree();

    return 0;
}
