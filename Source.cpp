#include "Functions.h"

int main() {
	//createList running
	vector<int> intList = createList();

	//intExists running
	int intIndex = intExists(intList);
	checkForInt(intIndex); //output result of intExists

	//intModify running
	intModify(intList);
	outputList(intList); //output changed list
	//intAppend running
	intAppend(intList);
	outputList(intList); //output changed list
	///intReplace running
	intReplace(intList); 
	outputList(intList); //output finished changed list
}


