/*
 * NodeController.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: csad2045
 */

#include "NodeController.h"
#include <iostream>
#include <cmath>
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

void NodeController :: start() //Le start method
{
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

    numbers->addToFront(1);
	testLists();

}
