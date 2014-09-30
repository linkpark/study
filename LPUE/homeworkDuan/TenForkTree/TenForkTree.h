#ifndef TENFORKTREE_H_
#define TENFORKTREE_H_
#define TREEFORKNUMBER 10

const int SUCCESSFUL = 0;
const int FAILED = -1;

template<class T>
struct node{
    T value;
    struct node *next[TREEFORKNUMBER];
}; 

template<class T>
class TenForkTree{
public:
    TenForkTree();
    ~TenForkTree();

public:
    int serialize(const char * filePath);
    int deserialize(const char *filePath);
    
    void preorderPrint();

private:
    struct node<T> *m_pRoot;
    struct node<T> *m_pCurrentPosition;
};

#endif
