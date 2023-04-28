#include "ADJACENCYMATRIX.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
	int size;
	cout << "Enter the Number of Vertices of Graph: ";
	cin >> size;
	ADJACENCYMATRIX<int> graph(size);
	graph.initializeGraph();
	cout << endl;
	cout << "\t******** Checking Path ********" << endl;
	cout << "Enter the path in format 1 2 3 to check if path from 1->2->3 exists or not e.g." << endl;
	cout << "Enter 1 to check Path, 0 to Exit." << endl;
	int choice;
	do
	{
		cout << "Do you want to check path? ";
		cin >> choice;
		if (choice == 1) {
			string path;
			cin.ignore();
			cout << "Enter the Path: ";
			getline(cin, path);
			bool isValidPath = graph.doesPathExist(path);
			if (isValidPath) {
				cout << "Yes, this Path Exists!" << endl;
			}
			else {
				cout << "Sorry, this Path Does not Exists!" << endl;
			}
		}

	} while (choice != 0);


	return 0;
}