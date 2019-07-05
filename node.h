#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

template <typename T>
class Node {
    unsigned int size;
    vector<unsigned int> keys;
    vector<Node<T>*> childs;
    bool isLeaf;

    public: 
        Node(unsigned int size, bool isLeaf = true) : size(size), isLeaf(isLeaf) {
            keys.resize(size - 1);
            childs.resize(size);
        }

        bool search(int k){
            int i =0;
            while(i < size && k > keys[i]){
                i++;
            }
            if(keys[i] == k){
                return this;
            }
            if(leaf==true){
                return NULL;
            }
            return childs[i]->search(k);
        }

    friend class BTree; 
};

#endif