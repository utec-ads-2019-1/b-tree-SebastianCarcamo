#include <iostream>

#include "btree.h"

using namespace std;

int main(int argc, char *argv[]) {

	BTree<int> a(4);
	a.insert(10);
	a.print();
    return EXIT_SUCCESS;
}