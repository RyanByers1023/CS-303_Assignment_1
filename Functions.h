#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

vector<int> createList();
int intExists(vector<int> intList);
void checkForInt(int intIndex);
void intModify(vector<int>& intList);
void intAppend(vector<int>& intList);
void intReplace(vector<int>& intList);
void outputList(vector<int> intList);
