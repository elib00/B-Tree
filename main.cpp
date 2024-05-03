#include <iostream>
#include <iostream>
#include "tree.h"

using namespace std;
 
int main(void) {
	Tree24 *tree = new Tree24();
	tree->insert(13);
//	tree->search(4)->print();
	tree->insert(4);
	tree->insert(17);
	tree->insert(5);
	tree->insert(26);
//	tree->search(10)->print();
	tree->print();
	return 0;
}
