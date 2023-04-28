#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H
using namespace std;
#include <string>

template<class T>
class ADJACENCYMATRIX
{
private:

	int vertices;
	int **matrix;

public:
	ADJACENCYMATRIX();
	~ADJACENCYMATRIX();
	ADJACENCYMATRIX(int);
	void initializeGraph();
	bool doesPathExist(string);

};

#endif // !ADJACENCYMATRIX
template class ADJACENCYMATRIX<int>;
