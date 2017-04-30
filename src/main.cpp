/*
 * main.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: Avinash
 */
#include "Collection.h"
#include "Array.h"
#include "BST.h"
class Array;

int func(int j){
	return j+100;
}

int main(){

	/*Verification for Array class*/
	Collection* c;
	cout<<"----Array class instantiation----"<<endl;
	Array arr(6);
	cout<<"----Array Add elements ----"<<endl;
	arr[1]=2;
	arr[2]=4;
	arr[3]=13;
	cout<<"----Array Access the elements added----"<<endl;
	cout<<arr[1]<<endl;
	cout<<arr[2]<<endl;

	cout<<"----Array copy constructor----"<<endl;
	Array arr1=Array(arr);
	cout<<"----Array--verify copied output----"<<endl;
	cout<<arr1[3]<<endl;
	cout<<"----2nd Array class instantiation----"<<endl;
	Array arr2=Array(6);
	cout<<"----Array Add elements ----"<<endl;
	arr2[1]=3;
	arr2[2]=4;
	cout<<"----Array Assignment operator called----"<<endl;
	arr=arr2;
	cout<< arr.operator [](1)<<endl;
	cout<<endl<<endl;

	//	Collection* col;
	//	col=new BST;
	//	col->add(2);
	//	col->add(1);
	//	col->add(3);
	//	col->add(10);
	//
	//	col->operator [](3);
	//	cout<<"-------"<<endl;
	//	Collection* col1;
	//	col1=new BST(*col);

	/*Verification for BST class*/
	cout<<"----create a new BST----"<<endl;
	BST bst2;
	cout<<"----Add elements to BST----"<<endl;
	bst2.add(1);
	bst2.add(10);
	bst2.add(9);
	bst2.add(6);
	cout<<"----Copy Constructor BST----"<<endl;
	BST bst3(bst2);
	cout<<"----Copy Constructor output verification----"<<endl;
	bst3[1];

	cout<<"----create a new 2nd BST----"<<endl;
	BST bst4;
	cout<<"----Add elements to BST----"<<endl;
	bst4.add(100);
	bst4.add(10);
	bst4.add(1000);
	cout<<"----Assignment operator BST----"<<endl;
	bst2=bst4;
	cout<<"----Assignment operator output verification----"<<endl;
	bst2[2];

	/*Verification for Collection class*/
	cout<<"Size = "<<bst3.size_<<endl;
	cout<<"Size = "<<arr.size_<<endl;
	cout<<"----Array contains functionality----"<<endl;
	cout<< arr.contains(4)<<endl;
	cout<<"----Array Map functionality----"<<endl;
	Collection* out;
	out=&arr.map(&func);
	cout<<out->operator [](2)<<endl;
	cout<<"----BST contains functionality----"<<endl;
	Collection* out1;
	out1=new BST;
	out1->add(3);
	out1->add(10);
	cout << out1->contains(110)<<endl;
	cout<<"----BST Map functionality----"<<endl;
	Collection* out7;
	out7=&out->map(&func);
	cout<<out7->operator [](2)<<endl;
	return 0;
}



