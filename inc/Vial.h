#pragma once

#include <string>
using namespace std;

class Vial {
private:
	char contents[4]; // each vial can hold 4 letters
	int filled; // how many letters currently in the vial
	int label; // label to identify the vial (e.g., 1, 2, 3, etc.)

public:
	Vial(); // default constructor
	bool add(char content); // add a letter to the vial
	void display() const; // show the vial contents
	bool isComplete() const; // check if vial is all the same letter
	void setLabel(int label); // set the vial's label
	bool transfer(Vial& destination); // transfer top letter to another vial if possible
	bool isEmpty() const; // check if vial is empty
	char getContentAt(int index) const; // get content at specific index
	int getLabel() const; // get the vial's label
};