#include "ADJACENCYMATRIX.h"
#include <iostream>
#include <string>
using namespace std;

template<typename T>
ADJACENCYMATRIX<T>::ADJACENCYMATRIX() {
	vertices = 0;
	matrix = NULL;
}

template<typename T>
ADJACENCYMATRIX<T>::~ADJACENCYMATRIX() {
	//To avoid memory leak
	for (int i = 0; i < vertices; i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}

template<typename T>
ADJACENCYMATRIX<T>::ADJACENCYMATRIX(int size) {
	
	vertices = size;
	matrix = new T*[size];
	//creating matrix for storing graph information
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new T[size];
	}
	//initializing graph with 0
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			matrix[i][j] = 0;
		}
	}


}


template<typename T>
void ADJACENCYMATRIX<T>::initializeGraph() {
	cout << "\t------------------ Initialization Begins ------------------" << endl;
	//cout << "Enter the connectivity between Vertices(if respective vertices are connected or not)." << endl;
	//cout << "Enter 1 for connected, 0 for not connected" << endl;
	//cout << "Tell us to what vertices ";
	
	/*for (int i = 0; i < vertices; i++)
	{
		cout << "\tTell us to what vertices the Vertice # " << i + 1 << " is connected?" << endl;
		for (int j = 0; j < vertices; j++)
		{
			if (i != j) {
				bool isConnected = false;
				cout << "If Vertix # "<<i + 1<<" is connected to Vertix # "<<j + 1<<" or not: ";
				cin >> isConnected;
				if (isConnected) {
					matrix[i][j] = 1;
				}
			}
		}
	}*/

	cout << "Enter vertices numbers to which respective vertix is connected" << endl;
	cout << "Enter -1 to stop Entering connecting vertices for current Vertix otherwise Enter Vertix Number." << endl;
	
	for (int i = 0; i < vertices; i++)
	{
		cout << endl;
		int choice;
		cout << "Enter vertices that are connected with Vertix # " << i + 1 << endl;
		do
		{
			cout << "Enter vertix: ";
			cin >> choice;
			if (choice != -1) {
				matrix[i][choice - 1] = 1;
			}

		} while (choice != -1);
	}
	
}

template<typename T>
bool ADJACENCYMATRIX<T>::doesPathExist(string path) {
	string trimmedPath = "";
	//removing spaces from path string
	for (int i = 0; i < path.length(); i++)
	{
		if (path[i]!=' ') {
			trimmedPath += path[i];
		}
	}
	cout << "TRIMMED " << trimmedPath << endl;
	//checking if path is valid or not	
	bool flag = true;
	for (int i = 0; i < trimmedPath.length() - 1; i++)
	{
		//converting vertices to integer as it was given in string
		int m = trimmedPath[i] - '0';
		int n = trimmedPath[i + 1] - '0';
		if (matrix[m-1][n-1] != 1) {
			flag = false;
		}
	}
	if (flag) {
		return true;
	}
	else {
		return false;
	}

}