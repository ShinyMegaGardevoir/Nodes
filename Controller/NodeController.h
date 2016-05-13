/*
 * NodeController.h
 *
 *  Created on: Jan 29, 2016
 *      Author: csad2045
 */

#ifndef SRC_CONTROLLER_NODECONTROLLER_H_
#define SRC_CONTROLLER_NODECONTROLLER_H_

#include <iostream>
#include <string>

#include "../Model/Node.cpp"

#include "../Model/ArrayNode.cpp"

#include "../Model/CTECArray.cpp"

#include "../Model/Timer.h"

#include "../Model/CTECList.cpp"

#include "../Model/CTECBinaryTree.cpp"

#include "../Model/MorningGraph.cpp"

#include "../Model/CTECHashTable.cpp"


using namespace std;


class NodeController
{
public:
	NodeController();
	virtual ~NodeController();
	void start();

private:

	CTECArray<int> * notHipsterInts;
	CTECList<int> * numbers;
	Timer arrayTimer;
	void testLists();
    void checkSorts();
    
    void swap(int first, int second);
    void quicksort(int first, int last);
    int partition(int first, int last);
    void doQuick();
    
    int * mergeData;
    void doMergesort();
    void mergesort(int data [], int size);
    void merge(int data [], int sizeOne, int sizeTwo);
    
    void tryTree();
    
    void tryGraphs();
    
    void testHash();
    
};

#endif /* SRC_CONTROLLER_NODECONTROLLER_H_ */
