#include <iostream>
#include <cstdlib>   // for rand()
#include <ctime>     // for time()
#include "vial.h"

using namespace std;

int main() {

    // Seed random number generator
    srand((unsigned int)time(nullptr));

    const int VIAL_COUNT = 6;   // 4 filled + 2 empty
    const int COLORS = 4;       // a, b, c, d

    // Create array of vials
    Vial vials[VIAL_COUNT];

    // Give each vial a label (1,2,3,4,5,6)
    for (int i = 0; i < VIAL_COUNT; i++) {
        vials[i].setLabel(i + 1);
    }

    // Create a "bag" of characters
    // aaaa bbbb cccc dddd
    const int BAG_SIZE = COLORS * Vial::SIZE;
    char bag[BAG_SIZE];

    int index = 0;

    // Fill bag with characters
    for (int c = 0; c < COLORS; c++) {
        char letter = 'a' + c;  // makes 'a','b','c','d'
        for (int i = 0; i < Vial::SIZE; i++) {
            bag[index] = letter;
            index++;
        }
    }

    // Randomly fill first 4 vials
    for (int v = 0; v < COLORS; v++) {
        while (vials[v].getFilled() < Vial::SIZE) {

            int randomIndex = rand() % BAG_SIZE;

            // Only use character if not already used
            if (bag[randomIndex] != '-') {
                vials[v].add(bag[randomIndex]);
                bag[randomIndex] = '-'; // mark as used
            }
        }
    }

    int moves = 0;

    // Game loop
    while (true) {

        cout << "\nSimple Sort Puzzle\n";
        cout << "Moves: " << moves << "\n\n";

        // Display all vials
        for (int i = 0; i < VIAL_COUNT; i++) {
            vials[i].display();
        }

        // Check if solved
        // Count how many vials are complete (all same color and full)
        int completeVials = 0;

        for (int i = 0; i < VIAL_COUNT; i++) {
            if (vials[i].isComplete()) {
                completeVials++;
            }
        }

        // Game is solved when all colors are sorted (COLORS number of complete vials)
        if (completeVials == COLORS) {
            cout << "\nPuzzle completed in " << moves << " moves!\n";
            break;
        }

        // Ask user for move
        int source, destination;

        cout << "\nEnter source and destination (example: 1 5)\n";
        cout << "Enter 0 0 to quit\n";
        cout << "Source: ";
        cin >> source;
        cout << "Destination: ";
        cin >> destination;

        // Quit condition
        if (source == 0 && destination == 0) {
            cout << "Goodbye!\n";
            break;
        }

        // Check valid range
        if (source < 1 || source > VIAL_COUNT ||
            destination < 1 || destination > VIAL_COUNT) {
            cout << "Invalid vial number.\n";
            continue;
        }

        if (source == destination) {
            cout << "Cannot transfer to same vial.\n";
            continue;
        }

        // Perform transfer
        bool moved = vials[source - 1].transfer(vials[destination - 1]);

        if (moved) {
            moves++;  // Only count move if successful
        }
    }

    return 0;
}