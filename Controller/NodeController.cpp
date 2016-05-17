/*
 * NodeController.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: csad2045
 */

#include "NodeController.h"
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>
//using namespace std;

NodeController::NodeController()
{
	notHipsterInts = new CTECArray<int>(5);
	numbers = new CTECList<int>();
}

NodeController::~NodeController()
{

}

void NodeController :: testLists()
{

	numbers->addToFront(3);
	numbers->addAtIndex(2, 9);
    numbers->addToEnd(8);
	cout << "End should be 8 and it is: " << numbers->getEnd() << endl;
	cout << "Front should be 3 and it is: " << numbers->getFront() << endl;
	cout << "At index 2 the value should be 9 and is: " << numbers->getFromIndex(2) << endl;
    numbers->removeFromEnd();
    cout << "The value at End should now be 9. It is: " << numbers->getEnd() << endl;
    numbers->removeFromIndex(2);
    cout << "The value has been removed from Index 2. The value before it should be 3. It is: " << numbers->getFromIndex(1) << endl;
    cout << "The size of numbers is: " << numbers->getSize() << endl;
}

void NodeController::checkSorts()
{
    CTECArray<int> numbersInArray(5);
    CTECList<int> numbersInList;
    int cPlusPlusArray[5000];
    
    for(int spot = 0; spot < 5000; spot++)
    {
        int randomValue = rand();
        numbersInArray.set(spot, randomValue);
        numbersInList.addToEnd(randomValue);
        cPlusPlusArray[spot] = randomValue;
    }
    Timer sortTimer;
    sortTimer.startTimer();
    
    numbersInList.selectionSort();
    
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    
    sortTimer.resetTimer();
    
    sortTimer.startTimer();
    
    numbersInArray.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
}

void NodeController::doMergesort()
{
    mergeData = new int[5000];
    for(int spot = 0; spot < 5000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    for(int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData, 5000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    for(int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    delete [] mergeData;
}

void NodeController::mergesort(int data[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size - sizeOne;
        
        mergesort(data, sizeOne);
        mergesort(data+sizeOne, sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
    }
    
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
    int * temp; //Link for a temporary array.
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    
    while ((copied1 < sizeOne) && (copied2 < sizeTwo)) //Smaller goes in small half
    {
        if(data[copied1] < (data + sizeOne)[copied2])
        {
            temp[copied++] = data[copied1++];
        }
        else //Larger goes in large half
        {
            temp[copied++] = (data + sizeOne)[copied2++];
        }
    }
    
    while(copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne)[copied2++];
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index]= temp[index];
    }
    delete [] temp;
}

void NodeController::quicksort(int first, int last)
{
    int pivotIndex;
    
    
    if(first < last)
    {
        pivotIndex = partition(first, last);
        quicksort(first, pivotIndex-1);
        quicksort(pivotIndex+1, last);
    }
}

int NodeController::partition(int first, int last)
{
    int pivot;
    int index, smallIndex;
    swap(first, (first + last)/2);
    
    pivot = mergeData[first];
    smallIndex = first;
    
    for(index = first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
        
    }
    
    swap(first, smallIndex);
    
    return smallIndex;
}

void NodeController::swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}

void NodeController::doQuick()
{
    mergeData = new int[50000];
    for(int spot = 0; spot < 50000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    for(int spot = 0; spot < 50000; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    quicksort(0, 49999);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    for(int spot = 0; spot < 50000; spot++)
    {
        cout << mergeData[spot] << ", " ;
    }
    delete [] mergeData;

    
}

void NodeController::tryTree()
{
    CTECBinaryTree<int> testTree;
    testTree.insert(20);
    testTree.insert(2);
    testTree.insert(1);
    testTree.insert(10);
    testTree.insert(12);
    testTree.insert(21);
    testTree.insert(7);
    
    cout << "InorderTraversal " << endl;
    testTree.inorderTraversal(testTree.getRoot());
    cout << "" << endl;
    cout << "Size of the tree after Inorder Traversal: " << testTree.getSize() << endl;
    
    testTree.insert(13);
    cout << "Inserted 13 into the tree." << endl;
    
    cout << "\nPreorderTraversal " << endl;
    testTree.preorderTraversal(testTree.getRoot());
    cout << "" << endl;
    cout << "Size of the tree after Preorder Traversal: " << testTree.getSize() << endl;
    
    testTree.insert(23);
    cout << "Inserted 23 into the tree." << endl;
    
    cout << "\nPostorderTraversal " << endl;
    testTree.postorderTraversal(testTree.getRoot());
    cout << "" << endl;
    cout << "Size of the tree after Postorder Traversal: " << testTree.getSize() << endl;
}

void NodeController :: tryGraphs()
{
    MorningGraph<int> testerGraph;
    testerGraph.addVertex(7);
    testerGraph.addVertex(10);
    testerGraph.addVertex(21);
    testerGraph.addVertex(11);
    testerGraph.addVertex(52);
    testerGraph.addVertex(3);
    testerGraph.addVertex(1);
    testerGraph.addVertex(13);
    testerGraph.addVertex(19);
    testerGraph.addVertex(23);
    testerGraph.addVertex(45);
    testerGraph.addEdge(0, 1);
    testerGraph.addEdge(1, 0);
    testerGraph.addEdge(1, 5);
    testerGraph.addEdge(1, 2);
    testerGraph.addEdge(2, 4);
    testerGraph.addEdge(5, 2);
    testerGraph.addEdge(4, 5);
    testerGraph.addEdge(2, 7);
    testerGraph.addEdge(6, 6);
    testerGraph.addEdge(7, 6);
    testerGraph.addEdge(6, 7);
    testerGraph.addEdge(4, 2);
    testerGraph.addEdge(7, 1);
    testerGraph.addEdge(5, 10);
    testerGraph.addEdge(9, 3);
    testerGraph.addEdge(3, 9);
    testerGraph.addEdge(4, 9);
    testerGraph.addEdge(3, 0);
    testerGraph.addEdge(8, 5);
    testerGraph.addEdge(5, 8);
    testerGraph.addEdge(5, 5);
    testerGraph.addEdge(10, 9);
    
    cout << "Beginning of Breadth First Traversal" << endl;
    testerGraph.breadthFirstTraversal(testerGraph, 0);
    cout << "End of Breadth First Traversal." << endl;
    cout << "" << endl;
    cout << "Beginning of Depth First Traversal." << endl;
    testerGraph.depthFirstTraversal(testerGraph, 0);
    cout << "" << endl;
    cout << "End of Depth First Traversal" << endl;
    cout << "" << endl;
}

void NodeController :: testHash()
{
    CTECHashTable<int> testerTable;
    HashNode<int> tempArray[20];
    srand(time(NULL));
    for(int spot = 0; spot < 20; spot++)
    {
        int randomValue = rand();
        int randomKey = rand();
        HashNode<int> temp = HashNode<int>(randomKey, randomValue);
        testerTable.add(temp);
        tempArray[spot] = temp;
    }
    
    
    
    
    
    bool test1 = testerTable.contains(tempArray[0]);
    
    if(test1)
    {
        cout << "The value " << tempArray[0].getValue() << " is in the Array." << endl;
    }
    else
    {
        cout << "The value " << tempArray[0].getValue() << " isn't in the Array." << endl;
    }
    
    bool test2 = testerTable.contains(tempArray[1]);
    
    if(test2)
    {
        cout << "The value " << tempArray[1].getValue() << " is in the Array." << endl;
    }
    else
    {
        cout << "The value " << tempArray[1].getValue() << " isn't in the Array." << endl;
    }
    
    bool test3 = testerTable.contains(tempArray[2]);
    
    if(test3)
    {
        cout << "The value " << tempArray[2].getValue() << " is in the Array." << endl;
    }
    else
    {
        cout << "The value " << tempArray[2].getValue() << " isn't in the Array." << endl;
    }
    
    bool test4 = testerTable.contains(tempArray[3]);
    
    if(test4)
    {
        cout << "The value " << tempArray[3].getValue() << " is in the Array." << endl;
    }
    else
    {
        cout << "The value " << tempArray[3].getValue() << " isn't in the Array." << endl;
    }
    
    bool test5 = testerTable.contains(tempArray[4]);
    
    if(test5)
    {
        cout << "The value " << tempArray[4].getValue() << " is in the Array." << endl;
    }
    else
    {
        cout << "The value " << tempArray[4].getValue() << " isn't in the Array." << endl;
    }
    
    bool test6 = testerTable.contains(tempArray[5]);
    
    if(test6)
    {
        cout << "The value " << tempArray[5].getValue() << " is in the Array." << endl;
    }
    else
    {
        cout << "The value " << tempArray[5].getValue() << " isn't in the Array." << endl;
    }





    
    
    
    
}

void NodeController :: start() //Le start method
{
    testHash();
    
    
    
    
    
    
/**	arrayTimer.startTimer();
	for(int index = 0; index < notHipsterInts->getSize(); index++)
		{
			notHipsterInts->set(index, (23 * index));
		}



	//Prints the values for each space in the array.
	for(int index = 0; index < notHipsterInts->getSize(); index++)
	{
		cout << "The contents at " << index << " are : " << notHipsterInts->get(index) << endl;
	}
	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();
**/

    
}

