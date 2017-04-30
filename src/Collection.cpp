/*
 * Collection.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: Avinash
 */
#include "Collection.h"
#include "Array.h"
#include "BST.h"

Collection::Collection(){				//default constructor
	size_=0;
	cout<<"Collection constructor called"<<endl;
}

Collection::Collection(const Collection& col){		//copy constructor
	size_=col.size_;
	cout<<"Collection copy constructor called"<<endl;
}

Collection& Collection::operator=(const Collection& col){	//assignment operator
	size_=col.size_;
	cout<<"Collection = constructor called"<<endl;
}

bool Collection::treeContains( node *root,int item ) {		//to check if BST contains the given node

	if ( root == NULL ) {									//if root=Null, return false
		return false;
	}
	else if ( item == root->value) {
		return true;
	}
	else if ( item < root->value ) {						//if less, move to the left sub tree
		return treeContains( root->left, item );
	}
	else {													//if more, move to the right sub tree
		return treeContains( root->right, item );
	}
}

void Collection::treeMap( node *t) {						//BST map functionality

	if(t == NULL)
		return;
	treeMap(t->left);
	t->value;
	treeMap(t->right);
}

bool Collection::contains(int a){						//Contains funtion implemented in the superclass
	BST* b1;
	cout<<"Array contains function entered"<<endl;
	cout<<"Search element: "<< a << endl;
	if(Array* a1=dynamic_cast <Array*> (this)){			//checks if the receiver is Array, if not raise null pointer
		for(int i=0;i<a1->len_;i++){					//if its array, check if the array contains the element
			if (a1->array[i]==a){
				cout<<"Array contains: true"<<endl;
				return true;
			}
		}
		return false;
	}
	else{												//goes into this condition if the above if raises a null pointer
		cout<<"Map contains function entered"<<endl;
		b1=dynamic_cast<BST*>(this);					//dynamic cast the receiver to BST
		cout<<"BST contains: 0-False | 1-True :"<<treeContains(b1->root,a)<<endl;
	}
}


Collection& Collection::map(int (*fun)(int)){			//Map functionality
	Collection* col;
	BST* bst;
	cout<<"Array Map function entered"<<endl;
	if(Array* a1=dynamic_cast<Array*>(this)){			//checks if the receiver is Array, if not raise null pointer

		for(int i=0;i<a1->len_;i++){					//if its array, implement map
			a1->array[i]=fun(a1->array[i]);
		}
		return *a1;
	}
	else{
		cout<<"BST Map function entered"<<endl;
		bst=dynamic_cast<BST*>(this);					//goes into this condition if the above if raises a null pointer
		treeMap(bst->root);
		return *bst;
	}
}

