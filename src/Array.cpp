/*
 * Array.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: Avinash
 */
#include "Array.h"

Array::Array(int n):Collection(){			//constructor with base constructor called
	array=new int[n];
	len_=n;
	cout<<"Array constructor called"<<endl;
}

Array::Array(const Array& arr):Collection(arr){		//Copy constructor along with the base constructor called
	this->len_=arr.len_;
	this->array=new int[arr.len_];					//creates a new array
	for(int j=0;j<(arr.len_);j++){
		this->array[j]=arr.array[j];				//copies the elements into the new array
	}
	cout<<"Array copy constructor called"<<endl;
}

Array& Array::operator=(const Array& arr){			//assignment operator
	if(this==&arr){					//to check if both lhs and rhs are same
		return *this;
		cout<<"Array assignment operator called"<<endl;
	}
	else{
		(Collection&)(*this)=arr;				//call the superclass assignment operator
		delete[] array;							//delete the receivers array
		this->len_=arr.len_;
		this->array=new int[arr.len_];
		for(int j=0;j<(arr.len_);j++){			//deep copy all the elements
			this->array[j]=arr.array[j];
		}
		cout<<"Array assignment operator called"<<endl;
		return *this;
	}
}

void Array::add(int i){							//add elements to the array
	cout<<"cannot add elements to the output"<<endl;
}

int& Array::operator[](int j){					//indexing operator for the array
	if(j < (this->len_)){
		size_=0;
		for(int i=0;i<len_;i++){
			if(array[i]!=0){
				size_=size_+1;
			}
		}
		return this->array[j];
	}
	else{
		cout << "out of range"<<endl;
		throw "Index out of range";
	}
}

Array::~Array(){								//destructor
	delete [] array;
}

Array* Array::copy(){							//virtual copy
	Array* arr=new Array(*this);
	return arr;
}
