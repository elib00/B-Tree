#include <cstdlib>
#include <iostream>

using namespace std;

class Node {
	int *data;
	Node **children;
	int size;
	Node *parent;
	
	public:
		Node(int num, Node* parent){
			//init data
			data = (int*) calloc(4, sizeof(int));
			
			//init size
			size = 0;
			data[size++] = num;
			
			//init children
			children = (Node**) calloc(5, sizeof(Node*));
			this->parent = parent;
		}
		
		int getSize(){
			return size;
		}
		
		int increaseSize(){
			size++;
			return size;
		}
		
		int getData(int index){
			return data[index];
		}
		
		Node *getChild(int index){
			return children[index];
		}
		
		Node *getParent(){
			return parent;
		}
		
		int indexOf(int num){
			for(int i = 0; i < size; i++){
				if(num == data[i]){
					return i;
				}
			}
			
			return -1;
		}
		
		bool addKey(int num){
			int i;
			for(i = size; i > 0; i--){
				if(num < data[i - 1]){
					data[i] = data[i - 1];
				}else{
					break;
				}
			}
			
			data[i] = num;
			size++;
			return size != 4;
		}
		
		void insertChildren(Node *wp, Node *w2p, int pos){
			for(int i = size - 1; i > pos;  i--){
				children[i + 1] = children[i];
			}
			
			children[pos] = wp;
			children[pos + 1] = w2p;
		}
		
		void print(){
			for(int i = 0; i < size; i++){
				cout << data[i] << " ";
			}
			
			cout << endl;
			
			for(int i = 0; i < 5; i++){
				if(children[i]){
					children[i]->print();
				}
			}
		}
};
