/*
 * BST.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: Avinash
 */
#include "BST.h"

node* BST::insert(int x, node* t)		//Inserts the elelments into the BST
{
	if(t == NULL)
	{
		t = new node;
		t->value = x;
		t->left = t->right = NULL;
		cout<<t->value<<endl;
	}
	else if(x < t->value)
		t->left = insert(x, t->left);
	else if(x > t->value)
		t->right = insert(x, t->right);
	else{
		cout<<"cannot be inserted";
	}
	return t;

}

void BST::inorder(node* t,int j)		//Prints the BST inorder
{
	if (root == NULL){
		cout<<"Tree is empty"<<endl;
		return;
	}
	if(t != NULL){
		inorder(t->left,j);
		count_=count_+1;
		if(count_==(j+1)){				//print the inorder index
			cout<<"Element at index is: "<<t->value<<endl;
		}
		inorder(t->right,j);
	}
}

bool BST::empty(void){					//check if BST is empty
	return !root;
}
node* BST::clear(node* t)				//to delete all the dynamic allocations
{
	if(t == NULL)
		return NULL;
	{
		clear(t->left);
		clear(t->right);
		delete t;
	}
	return NULL;
}

void BST::copyconst(node* t){			//copying of the BST

	if(t){
		add(t->value);
		copyconst(t->left);
		copyconst(t->right);
	}
}

BST::BST():Collection(){			//default constructor with base constructor called
	cout<<"BST constructor called"<<endl;
	root=NULL;
	count_=0;
}


BST::BST(BST& bst):Collection(bst){		//copy constructor with base copy constructor called
	cout<<"BST copy constructor called"<<endl;
	this->root=NULL;
	this->size_=0;
	count_=bst.count_;
	copyconst(bst.root);

}

BST& BST::operator=(BST& arr){			//assignment operator
	if(this==&arr){						//to check if the receiver and the argument objects are the same
		cout<<"BST assignment operator called"<<endl;
		return *this;
	}
	else{
		cout<<"BST assignment operator called"<<endl;
		(Collection&)(*this)=arr;		//call the base class assignment operator
		count_=arr.count_;
		this->size_=0;
		this->clear(root);				//delete the receivers existing values
		this->root=NULL;
		this->copyconst(arr.root);		//copy the BST
	}
}

void BST::add(int i){					//insert element into BST
	root=insert(i,root);
	size_=size_+1;
}

int& BST::operator[](int j){			//retrivce an index from the BST based on inorder traversal
	inorder(root,j);
	if(size_<j+1){
		cout<<"Index out of range"<<endl;
	}
}

BST::~BST(){							//destructor
	root=clear(root);
}

BST* BST::copy(){					//virtual copy
	BST* bst=new BST(*this);
	return bst;
}
