#include <iostream>
#include "Vial.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // -------------------------------
    // Create 5 vials and label them
    // 4 will hold letters, 1 will be empty
    // -------------------------------
    Vial vials[6];
    for (int i = 0; i < 6; i++)
        vials[i].setLabel(i + 1);

    // Letters for the puzzle
    // 4 of each: a, b, c, d
    char letters[] = {
        'a','a','a','a',
        'b','b','b','b',
        'c','c','c','c',
        'd','d','d','d'
    };
    srand(time(0)); // seed random generator

    // Fill vials randomly
    for (int i = 0; i < 16; i++) {
        int index;
        do { index = rand() % 16; } while (letters[index] == ' ');

        for (int j = 0; j < 6; j++) {
            if (vials[j].add(letters[index])) break;
        }

        letters[index] = ' ';
    }

    // Game loop
    bool gameComplete = false;
    while (!gameComplete) {
        cout << "\nCurrent puzzle:\n";

        // -------------------------------
        // Display vials with numbers above
        // -------------------------------

        // Print labels above vials
        for (int i = 0; i < 6; i++) {
            cout << "  " << vials[i].getLabel() << "  ";
        }
        cout << endl;

        // Print contents row by row (top to bottom)
        for (int row = 3; row >= 0; row--) {
            for (int i = 0; i < 6; i++) {
                cout << "| " << vials[i].getContentAt(row) << " | ";
            }
            cout << endl;
        }

        // Optional separator line
		for (int i = 0; i < 6; i++) // print separator between vials
            cout << "----- ";
        cout << endl;

      
        // Get player's move
        int source, destination;
        cout << "\nMove from vial (1-6): ";
        cin >> source;
        cout << "Move to vial (1-6): ";
        cin >> destination;

        // Perform the transfer
		vials[source - 1].transfer(vials[destination - 1]); // adjust for 0-based index

        // Check if puzzle is solved
		gameComplete = true; // assume solved until we find otherwise
        for (int i = 0; i < 6; i++) {
            // Only check non-empty vials
			if (!vials[i].isComplete() && !vials[i].isEmpty()) { // if vial is not complete and not empty, game is not complete
				gameComplete = false; // puzzle not solved yet
                break;
            }
        }
    }

    cout << "\nCongratulations! Puzzle solved!\n";
    return 0;
}
