/*
 * CTECArray.h
 *
 *  Created on: Feb 2, 2016
 *      Author: Christina Sadlier
 */

#ifndef MODEL_CTECARRAY_H_
#define MODEL_CTECARRAY_H_

#include "ArrayNode.h"

template <class Type>
class CTECArray {
public:
	CTECArray(int size);
	virtual ~CTECArray();
	int getSize();
	Type get(int position);
	void set(int position, const Type& value);
    void selectionSort();

private:
	int size;
	ArrayNode<Type> * head;
    void swap(int indexOne, int indexTwo);
};

#endif /* MODEL_CTECARRAY_H_ */
