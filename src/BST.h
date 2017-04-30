/*
 * BST.h
 *
 *  Created on: Apr 23, 2017
 *      Author: Avinash
 */

#ifndef SRC_BST_H_
#define SRC_BST_H_
#include <iostream>
#include "Collection.h"
#include "node.h"
using namespace std;

class BST:public Collection{
public:
	BST();
	BST(BST& bst);
	BST(const Collection&);
	void copyconst(node* d);
	bool empty(void);
	node* root;
	int count_;
	node* clear(node* t);			//to clear the BST
	virtual ~BST();
	void inorder(node* t,int j);
	virtual BST* copy();
	BST& operator=(BST& arr);
	node* insert(int x, node* t);		//to insert into the BST
	virtual void add(int i);
	virtual int& operator[](int j);
};




#endif /* SRC_BST_H_ */
