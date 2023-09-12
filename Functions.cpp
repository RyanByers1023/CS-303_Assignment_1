#include "Functions.h"

vector<int> createList() { //create list of integers from file
	cout << "Enter the name of the integer file: ";
	string fileName;
	cin >> fileName;
	ifstream intFile;
	int currentInt;
	vector<int> intList;
	intFile.open(fileName);

	while (!intFile) { //file does not exist
		cout << "File could not be located..." << endl;
		cout << "Try entering the file name again: ";
		cin >> fileName;
		intFile.open(fileName);
	}

	while (intFile.good()) { //while file still has content...
		intFile >> currentInt; //store current line int currentInt
		intList.push_back(currentInt); //add this int to the end of intList
	}

	return intList;
}

int intExists(vector<int> intList){
	int checkInt; //integer to check for
	cout << "Enter an integer to check for in the list: ";
	try {
		cin >> checkInt;
		throw runtime_error("");
	}
	catch (runtime_error) {
		while (cin.fail()) { //while cin is creating errors
			cin.clear(); //clear stream
			cin.ignore(256, '\n'); //ignore the next 256 lines
			cout << "Enter the value as an integer: ";
			cin >> checkInt;
		}
	}
	
	for (int i = 0; i < intList.size(); i++) { //loop through list and check whether there exists a value that equal the value in which the user wants to check for
		if (checkInt == intList[i]) {
			return i;
		}
	}
	return -1; //index was not found--int does not exist in the list
}

void checkForInt(int intIndex) {
	if (intIndex == -1) { //if int does not exist in list
		cout << "Int does not exist." << endl;
	}
	else {
		cout << "Int exists." << " The integer is located at index " << intIndex << endl;
	}
}

void intModify(vector<int>& intList) { //take index value and an integer value and modify the specified index in intList with the specified integer value
	int newItem;
	int intListIndex;
	cout << "Enter the index you wish to change: ";
	cin >> intListIndex;
	cout << "Enter an integer value to change this index to: ";
	cin >> newItem;
	int oldValue = intList[intListIndex]; // save old value in variable to display to user later
	intList[intListIndex] = newItem; //change value of intList at specified index to specified integer
	cout << "New value of index "  << intListIndex << " : " << intList[intListIndex] << endl;
	cout << "Old value of index " << intListIndex << " : " << oldValue << endl;
}

void intAppend(vector<int>& intList) { //appends a user specified item to the list
	int newItem;
	cout << "Enter a new item to add to the list: ";
	try {
		cin >> newItem;
		throw runtime_error("");
	}
	catch (runtime_error) {
		while (cin.fail()) { //while cin is creating errors
			cin.clear(); //clear stream
			cin.ignore(256, '\n'); //ignore the next 256 lines
			cout << "Enter the value as an integer: ";
			cin >> newItem;
		}
	}
	intList.push_back(newItem);
}

void intReplace(vector<int>& intList) { //replace intList[intIndex] with a 0
	int intIndex;
	cout << "Enter the index you wish to replace with a 0: ";
	cin >> intIndex;
	intList[intIndex] = 0;
}

void outputList(vector<int> intList){
	cout << "The current list: ";
	for (int i = 0; i < intList.size(); i++) {
		cout << intList[i] << " ";
	}
	cout << endl;
}