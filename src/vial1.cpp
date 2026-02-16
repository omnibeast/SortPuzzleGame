#include "Vial.h" // Include the Vial class header
#include <iostream> // For input/output operations
using namespace std; // Use the standard namespace

// Default constructor: initializes vial as empty and label to 0
Vial::Vial() : filled(0), label(0) {
	for (int i = 0; i < SIZE; ++i) contents[i] = ' '; // Fill contents with spaces
}

// Constructor: initialize from array, set filled and label
Vial::Vial(const char arr[], int size, int filled) : filled(filled), label(0) {
	for (int i = 0; i < SIZE; ++i) {
		if (i < size) contents[i] = arr[i]; // Copy from input array
		else contents[i] = ' '; // Fill remaining with spaces
	}
}

// Constructor: initialize from 4 characters, set filled and label
Vial::Vial(char c1, char c2, char c3, char c4, int filled) : filled(filled), label(0) {
	contents[0] = c1; // Set first content
	contents[1] = c2; // Set second content
	contents[2] = c3; // Set third content
	contents[3] = c4; // Set fourth content
}

// Add a character to the vial if not full
bool Vial::add(char content) {
	if (filled < SIZE) {
		contents[filled++] = content; // Add content and increment filled
		return true; // Success
	}
	return false; // Vial is full
}

// Display the vial's contents, label, and filled count
void Vial::display() const {
	cout << "["; // Start bracket
	for (int i = 0; i < SIZE; ++i) {
		cout << contents[i]; // Print each content
		if (i < SIZE - 1) cout << ","; // Comma between items
	}
	cout << "] (Label: " << label << ", Filled: " << filled << ")" << endl; // End bracket and info
}

// Check if the vial is full and all contents are the same (not space)
bool Vial::isComplete() const {
	if (filled != SIZE) return false; // Not full
	char first = contents[0]; // First content
	if (first == ' ') return false; // Empty
	for (int i = 1; i < SIZE; ++i) {
		if (contents[i] != first) return false; // Not all same
	}
	return true; // All same and full
}

// Set the label for the vial
void Vial::setLabel(int l) {
	label = l;
}

// Transfer the top item to another vial if possible
bool Vial::transfer(Vial& destination) {
	if (filled == 0) return false; // Nothing to transfer
	if (destination.filled >= SIZE) return false; // Destination full
	char top = contents[filled - 1]; // Top item
	// Can transfer if destination is empty or top matches destination's top
	if (destination.filled == 0 || destination.contents[destination.filled - 1] == top) {
		destination.add(top); // Add to destination
		contents[--filled] = ' '; // Remove from source
		return true; // Success
	}
	return false; // Cannot transfer
}
