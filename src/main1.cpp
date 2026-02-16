#include "Vial.h" // Include the Vial class header
#include <iostream> // For input/output operations
using namespace std; // Use the standard namespace

// Helper function to display all vials
void displayAll(Vial vials[], int n) {
	for (int i = 0; i < n; ++i) {
		vials[i].display();
	}
}

// Helper function to check if all vials are either empty or complete
bool allSolved(Vial vials[], int n) {
	for (int i = 0; i < n; ++i) {
		if (vials[i].isComplete() || vials[i].add(' ')==false) continue;
		// If not complete and not empty, puzzle is not solved
		bool empty = true;
		for (int j = 0; j < 4; ++j) {
			if (vials[i].add(' ')==false) {
				empty = false;
				break;
			}
		}
		if (!empty && !vials[i].isComplete()) return false;
	}
	return true;
}

int main() {
	// Initialize vials for the puzzle
	Vial vials[4];
	vials[0].setLabel(1);
	vials[0].add('A');
	vials[0].add('B');
	vials[0].add('B');
	vials[0].add(' ');

	vials[1] = Vial('C', ' ', ' ', ' ', 1);
	vials[1].setLabel(2);

	vials[2] = Vial('B', 'C', 'C', 'D', 4);
	vials[2].setLabel(3);

	vials[3] = Vial('B', 'C', ' ', ' ', 2);
	vials[3].setLabel(4);

	cout << "Welcome to the Sort Puzzle Game!" << endl;
	cout << "Goal: Group all same letters into a single vial." << endl;

	while (true) {
		cout << "\nCurrent vials:" << endl;
		displayAll(vials, 4);

		// Check for win condition
		bool solved = true;
		for (int i = 0; i < 4; ++i) {
			if (!vials[i].isComplete() && vials[i].add(' ')==false) {
				solved = false;
				break;
			}
		}
		if (solved) {
			cout << "\nCongratulations! You solved the puzzle!" << endl;
			break;
		}

		int src, dst;
		cout << "\nEnter source vial label (1-4, 0 to quit): ";
		cin >> src;
		if (src == 0) break;
		cout << "Enter destination vial label (1-4): ";
		cin >> dst;
		if (src < 1 || src > 4 || dst < 1 || dst > 4 || src == dst) {
			cout << "Invalid input. Try again." << endl;
			continue;
		}
		if (vials[src-1].transfer(vials[dst-1])) {
			cout << "Transfer successful!" << endl;
		} else {
			cout << "Transfer failed. Try a different move." << endl;
		}
	}

	cout << "\nFinal vials:" << endl;
	displayAll(vials, 4);
	cout << "Thank you for playing!" << endl;
	return 0;
}
