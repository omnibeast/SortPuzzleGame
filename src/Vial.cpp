#include "Vial.h"
#include <iostream>
#include <string>

using namespace std;

//Empty Vial
Vial::Vial() : filled(0), label(0) {
    for (int i = 0; i < SIZE; ++i) contents[i] = ' ';
}

// Constructor with array
Vial::Vial(char arr[], int size, int filledAmount) : filled(filledAmount), label(0) {
    for (int i = 0; i < SIZE; ++i) {
        if (i < size && i < filledAmount) {
            contents[i] = arr[i];
        } else {
            contents[i] = ' ';
        }
    }
}

// Constructor with individual characters
Vial::Vial(char c1, char c2, char c3, char c4, int filledAmount) : filled(filledAmount), label(0) {
    contents[0] = c1;
    contents[1] = c2;
    contents[2] = c3;
    contents[3] = c4;
}

// Adds a character to top of vial
bool Vial::add(char content) {
    if (filled >= SIZE) {
        return false; // Vial is full
    }
    contents[filled] = content;
    filled++;
    return true;
}

// Displays vial on screen
void Vial::display() const {
    cout << "Vial " << label << ": [";
    for (int i = 0; i < SIZE; i++) {
        if (i < filled) {
            cout << contents[i];
        } else {
            cout << " ";
        }
        if (i < SIZE - 1) cout << " ";
    }
    cout << "]" << endl;
}

// Checks if vial is complete (all same character)
bool Vial::isComplete() const {
    if (filled != SIZE) {
        return false; // Not full
    }
    char first = contents[0];
    for (int i = 1; i < SIZE; i++) {
        if (contents[i] != first) {
            return false;
        }
    }
    return true;
}

// Sets label number
void Vial::setLabel(int newLabel) {
    label = newLabel;
}

// Transfers top element to another vial
bool Vial::transfer(Vial& destination) {
    if (filled == 0) {
        return false; // Source vial is empty
    }
    if (destination.filled >= SIZE) {
        return false; // Destination vial is full
    }

    // Transfer the top element (last filled position)
    char topElement = contents[filled - 1];
    if (destination.add(topElement)) {
        contents[filled - 1] = ' ';
        filled--;
        return true;
    }
    return false;
}

// Helper function
int Vial::getFilled() const {
    return filled;
}

