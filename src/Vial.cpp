#include "Vial.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


// Constructor: make empty vial
Vial::Vial() {
    filled = 0;
    label = 0;

	for (int i = 0; i < 4; i++) { // initialize contents to empty
        contents[i] = ' '; // empty spaces
    }
}


// Add a letter to the vial
bool Vial::add(char content) {
    if (filled == 4) {
        return false; // vial full
    }

    contents[filled] = content; // put letter on top
    filled++;
    return true;
}

// Show the vial contents
void Vial::display() const {
    for (int i = 3; i >= 0; i--) { // top to bottom
        cout << "| " << contents[i] << " |" << endl;
    }
    cout << "----" << endl;
    cout << " " << label << endl; // show vial number
}

// Check if vial is all the same letter
bool Vial::isComplete() const {
    if (filled != 4)
        return false; // not full yet

    char firstContent = contents[0];

	for (int i = 1; i < 4; i++) { // check if all letters match
		if (contents[i] != firstContent) { // compare to first letter
            return false; // letters don't match
        }
    }

    return true; // all letters match
}

// Set the label for the vial
void Vial::setLabel(int label) {
	this->label = label; // assign label to vial
}
//checks if vial is empty
bool Vial::isEmpty() const {
	return filled == 0; // vial is empty if filled is 0
}
// Get content at specific index 
char Vial::getContentAt(int index) const {
	return contents[index]; // return content at given index
}

int Vial::getLabel() const { // Get the vial's label
    return label;
}

// Move letters from this vial to destination
bool Vial::transfer(Vial& destination) { // transfer top letter to another vial if possible

    //  Check if source is empty
    if (filled == 0) {
        cout << "Source vial is empty.\n";
        return false;
    }

    //  Check if destination is full
    if (destination.filled == 4) {
        cout << "Destination vial is full.\n";
        return false;
    }

	char sourceTop = contents[filled - 1]; // get top letter from source

    // Check if destination is empty or top letters match
    if (destination.filled > 0) {
		char destTop = destination.contents[destination.filled - 1]; // get top letter from destination

		if (sourceTop != destTop) { // letters don't match
            cout << "Contents do not match.\n";
            return false;
        }
    }

    // Move letter
	destination.contents[destination.filled] = sourceTop; // put letter on top of destination
	destination.filled++; // increase filled count for destination

	contents[filled - 1] = ' '; // remove letter from source
	filled--; // decrease filled count for source

    return true;
}
