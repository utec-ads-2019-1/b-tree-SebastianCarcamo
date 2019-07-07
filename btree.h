#ifndef BTREE_H
#define BTREE_H

#include "node.h"

template <typename T>
class BTree {
    private:
        Node<T>* root;
        unsigned int degree;

    public:
        BTree(unsigned int degree) : degree(degree), root(nullptr) {};

        bool search(int k) { 
            if(root == nullptr){
                return false;
            }
            return root->search(k);
        } 

        bool insert(int k) {
            if (root == nullptr){
                root = new Node<T>(degree);
                root-> keys[0] = k;
                root->currSize = 1;
            }else{
                if(root->currSize == 2*degree-1){
                    Node<T>* n = new Node<T>(degree,false);
                    n->childs[0] = root;
                    n->splitTree(0,root);
                    int i = 0;
                    if(n->keys[0] < k){
                        i++;
                    }
                    n->childs[i]->insertKeyNoConflict(k);
                    root = n;
                }else{
                    root->insertKeyNoConflict(k);
                }
            }

        }

        bool remove(int k) {
            // TODO
        }

        void print() {
            
        }

        ~BTree();
};

#endif