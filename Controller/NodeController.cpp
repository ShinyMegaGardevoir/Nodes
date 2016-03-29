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
    int cPlusPluArray[5000];
    
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
    
    sortTimer.resetTimer()
    
    sortTimer.startTimer();
    
    numbersInArray.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
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

