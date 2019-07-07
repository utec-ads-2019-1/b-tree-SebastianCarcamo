#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

template <typename T>
class Node {
    unsigned int size; // min degree instead of max
    vector<unsigned int> keys;
    vector<Node<T>*> childs;
    bool isLeaf;
    int currSize;

    public: 
        Node(unsigned int size, bool isLeaf = true) : size(size), isLeaf(isLeaf) {
            keys.resize(2*size - 1);
            childs.resize(2*size);
            currSize = 0;
        }

        bool search(int k){
            int i =0;
            while(i < size && k > keys[i]){
                i++;
            }
            if(keys[i] == k){
                return this;
            }
            if(isLeaf==true){
                return NULL;
            }
            return childs[i]->search(k);
        }
        void insertKeyNoConflict(int k){
            int i = size - 1;
            if(isLeaf == true){
                while(i >= 0 && keys[i] > k){
                    keys[i+1] = keys[i];
                    i--;
                }
                keys[i+1] = k;
                size = size+1;
            }else{
                while(i >= 0 && keys[i] > k){
                    i--;
                }
                if(childs[i+1]->currSize == 2*size-1){
                    splitTree(i+1,childs[i+1]);
                    if(keys[i+1] < k){
                        i++;
                    }
                }
                childs[i+1]->insertKeyNoConflict(k);
            }
        }

        void splitTree(int i, Node<T>* nodo){
            Node<T>* NN = new Node<T>(nodo->size,nodo->isLeaf);
            NN->currSize = size-1;

            for(int j = 0; j <size-1;j++){
                NN->keys[j] = nodo->keys[j+size];
            }
            if(nodo->isLeaf == false){
                for(int j = 0;j<size;j++){
                    NN->childs[j] = nodo->childs[j+size];
                }
            }
            nodo->currSize = size-1;
            for(int j = currSize; j>= i+1; j--){
                childs[j+1] = childs[j];
            }
            childs[i+1] = NN;

            for(int j = currSize-1; j>= i;j--){
                keys[j+1] = keys[j];
            }

            keys[i] = nodo->keys[size-1];

            size+=1;
        }

        void printN(){
            int i;
            for(i = 0;i<currSize;i++){
                if(isLeaf == false){
                    childs[i]->printN();
                }
                std::cout<< " " << keys[i];
            }
            if(isLeaf == false){
                childs[i]->printN();
            }
        }

    friend class BTree; 
};

#endif