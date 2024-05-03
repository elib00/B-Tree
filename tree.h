#include "node.h"
#include <iostream>

using namespace std;

class Tree24{
	Node *root;
	int size;
	
	Node *search(Node *currNode, int num){
		int index = currNode->getSize(); 
		
		for(int i = 0; i < currNode->getSize(); i++){
			if(currNode->getData(i) == num){
				return currNode;
			}else if(currNode->getData(i) > num){
				index = i;
				break;
			}
		}
		
		if(!currNode->getChild(index)){
			return currNode;
		}
		
		search(currNode->getChild(index), num);
	}
		
	
	public:
		Tree24(){
			size = 0;
			root = NULL;
		}
		
		Node *search(int num){
			search(root, num);
		}
		
	
		void insert(int num){
			Node *n = new Node(num, NULL);
			if(!root){
				root = n;
			}else{
				Node *w = search(num);
				bool valid = w->addKey(num);
				
				while(!valid){
					Node *u;
					int pos;
					if(w == root){
						u = new Node(w->getData(2), NULL);
						root = u;
						pos = 0;
						valid = true;
					}else{
						u = w->getParent();
						valid = u->addKey(w->getData(2));
						pos = u->indexOf(w->getData(2));
					}
					
					Node *wPrime = new Node(w->getData(0), u);
					wPrime->addKey(w->getData(1));
					Node *w2Prime = new Node(w->getData(3), u);
					
					u->insertChildren(wPrime, w2Prime, pos);
					w = u;
				}
			}
			size++;
		}
		
		void print(){
			cout << "Size: " << size << endl;
			root->print();
		}
	
};
