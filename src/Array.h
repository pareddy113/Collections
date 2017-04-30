/*
 * Array.h
 *
 *  Created on: Apr 23, 2017
 *      Author: Avinash
 */

#ifndef SRC_ARRAY_H_
#define SRC_ARRAY_H_
#include "Collection.h"
using namespace std;
#include <iostream>
class Array:public Collection{

public:
	Array(int n);
	Array(const Array& arr);
	Array& operator=(const Array& arr);
	virtual void add(int i);				//sub class implementation
	virtual int& operator[](int j);			//sub class implementation
	virtual ~Array();
	int* array;
	int len_;
	virtual Array* copy();
};

#endif /* SRC_ARRAY_H_ */
