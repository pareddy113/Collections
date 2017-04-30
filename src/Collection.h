/*
 * Collection.h
 *
 *  Created on: Apr 23, 2017
 *      Author: Avinash
 */

#ifndef SRC_COLLECTION_H_
#define SRC_COLLECTION_H_
using namespace std;
#include<iostream>
#include"Node.h"

class Collection {

protected:
	Collection();							//access only to the sub classes
	Collection(const Collection& col);


public:
	virtual void add(int i)=0;				//pure virtual functions to be implemented in subclasses
	virtual int& operator[](int j)=0;
	bool treeContains( node *root,int item );	//pure virtual functions to be implemented in subclasses
	Collection& operator=(const Collection& col);	//Assignment operator
	void treeMap( node *root);						//BST Map function
	bool contains(int a);							//BST contains function
	Collection& map(int (*fun)(int));
	int size_;
	int size(){
		return size_;
	}
};


#endif /* SRC_COLLECTION_H_ */
