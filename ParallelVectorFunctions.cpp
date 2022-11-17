// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++:
// From control structures through objects. Pearson. 

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw, setprecision for output width
#include <string>   // To implement to_string, getline functions
#include <ctime>    // To access random number generator
#include <vector>   // To use vectors (dynamic form of array) 
using namespace std;

// Global Constant Initialization
const string TITLE = "Parallel Vector Functions Program";
const string AUTHOR_LINE = "By Forrest Moulin";
const int VECTOR_SIZE = 500;

// Function prototypes to notify compiler
// Reference parameter allows void function
// to update main() vector values
void fillVector(vector<int>& passedVector);
string vectorToString(vector<int> vectorPassed);
int countParallelEvens(vector<int> v1, vector<int> v2);


int main()
{	// Seed random number generator using current time
	srand(time(NULL));

	cout << fixed << setprecision(2) << TITLE << endl
		<< AUTHOR_LINE << endl << endl;

	// Dynamic variable creation
	// Create two int vector objects
	vector<int> vector1, vector2;
	int evenCount = 0;
	double evenCountPercentage = 0.0;
	string v1Str = "", v2Str = "";

	// Call functions using int vector object reference parameters
	fillVector(vector1);
	fillVector(vector2);

	v1Str = vectorToString(vector1);
	v2Str = vectorToString(vector2);

	cout << "Vector 1: " << endl << v1Str << endl
		<< "Vector 2:" << endl << v2Str << endl;

	evenCount = countParallelEvens(vector1, vector2);
	// Divide by 500 instances, multiply by 100.0 for %
	evenCountPercentage = evenCount / 5.0;

	cout << "Number of parallel even integers: "
		<< evenCount << "/500 ("
		<< evenCountPercentage << "%)" << endl;
}
// Fills a vector with random ints 1-100
void fillVector(vector<int>& passedVector)
{
	vector<int> filledVector;
	int randomNumber;
	for (int i = 0; i < VECTOR_SIZE; i++)
	{
		// 100 options: 0-99 + 1 = 1-100
		randomNumber = rand() % 100 + 1;
		passedVector.push_back(randomNumber);
	}
}
// Return the vector in string format (10 ints per line)
string vectorToString(vector<int> vectorPassed)
{
	string vectorAsStr = "";
	int number;
	for (int i = 0; i < VECTOR_SIZE; i++)
	{
		number = vectorPassed[i];
		vectorAsStr += to_string(number) + " ";
		if ((i + 1) % 10 == 0)
		{
			vectorAsStr += "\n";
		}
	}
	return vectorAsStr;
}
// Returns # of instances in which both vector values
// even at the same location
int countParallelEvens(vector<int> v1, vector<int> v2)
{
	int evenCount = 0;
	for (int i = 0; i < VECTOR_SIZE; i++)
	{	// If both vector ints are even
		if (v1[i] % 2 == 0 && v2[i] % 2 == 0)
		{	// Update even count
			evenCount++;
		}
	}
	return evenCount;
}
/*
* CONSOLE OUTPUT
* Parallel Vector Functions Program
* By Forrest Moulin
*
* Vector 1:
* 83 66 81 91 84 51 2 81 20 70
* 36 26 81 94 62 55 28 9 37 68
* 6 35 58 76 25 9 55 77 72 15
* 28 91 73 28 34 22 98 100 35 89
* 58 51 63 28 70 76 23 38 92 40
* 56 15 6 60 14 76 81 96 14 9
* 11 97 96 57 68 69 49 36 78 98
* 48 77 7 37 28 63 78 16 13 15
* 71 41 38 82 3 57 23 67 56 63
* 62 6 82 33 55 98 43 17 67 78
* 38 44 22 58 58 12 69 28 37 86
* 82 26 31 10 55 77 65 17 23 52
* 46 12 26 13 12 35 95 26 86 1
* 92 52 29 58 91 84 16 92 67 79
* 36 70 100 20 83 42 46 31 21 54
* 42 1 93 37 72 29 22 28 97 29
* 29 79 4 53 88 76 43 78 59 25
* 70 95 30 68 88 57 48 93 24 69
* 22 91 34 94 83 40 98 15 63 54
* 61 66 17 12 15 33 89 78 24 9
* 49 24 29 81 64 97 58 64 93 58
* 5 70 89 36 30 16 51 80 41 18
* 11 38 71 5 73 92 40 33 27 32
* 92 17 90 99 34 64 81 23 37 14
* 94 95 73 39 33 45 17 63 70 89
* 73 79 74 52 66 87 29 44 33 89
* 95 18 96 81 97 31 75 29 85 91
* 75 18 44 27 16 72 58 26 40 2
* 31 91 5 94 53 53 39 96 98 22
* 84 88 79 68 4 89 30 29 45 51
* 72 2 6 29 73 10 57 20 32 100
* 91 74 66 14 15 50 43 43 3 19
* 3 84 50 47 30 58 4 6 61 35
* 76 63 39 30 19 6 64 32 26 59
* 88 1 18 62 51 50 53 60 68 44
* 88 21 44 48 62 69 89 53 36 100
* 74 59 67 57 5 73 90 18 70 13
* 17 58 13 18 88 91 43 23 36 59
* 13 58 78 5 2 36 18 19 30 95
* 27 46 98 8 92 44 18 73 78 73
* 97 74 99 73 27 52 22 89 77 57
* 20 72 93 3 79 84 68 67 20 81
* 16 9 59 65 73 85 53 64 58 56
* 33 82 88 97 39 19 79 85 29 27
* 98 41 65 82 48 78 81 41 10 57
* 5 98 11 72 30 44 13 64 31 79
* 31 17 60 61 30 66 15 66 29 37
* 30 97 21 38 3 35 15 69 8 51
* 31 17 60 61 30 66 15 66 29 37
* 77 57 49 39 36 38 60 52 84 16
* 2 6 70 52 63 36 11 36 33 51
*
* Vector 2:
* 86 32 44 12 1 6 80 20 24 33
* 87 40 91 17 64 95 10 85 91 60
* 93 77 18 60 68 61 35 45 95 85
* 75 20 10 58 34 4 1 61 52 31
* 70 26 39 53 59 16 30 14 77 64
* 14 13 25 15 30 3 18 11 61 44
* 11 92 87 52 7 75 19 60 82 76
* 79 48 6 73 21 60 94 70 62 70
* 78 46 76 35 43 98 96 95 3 76
* 56 50 32 39 57 16 65 81 41 89
* 50 37 72 38 14 86 88 83 90 91
* 85 25 47 53 74 17 23 26 38 17
* 4 39 86 91 73 5 7 36 65 83
* 58 3 49 59 74 30 37 93 53 83
* 18 24 87 67 83 52 96 96 17 63
* 21 77 95 37 37 62 26 33 27 63
* 18 77 46 93 73 89 64 7 48 2
* 44 31 58 79 28 41 7 95 46 47
* 90 10 41 2 79 52 82 39 32 69
* 15 70 64 71 7 19 92 9 59 78
* 45 42 77 69 75 97 72 15 9 82
* 15 87 53 93 1 12 17 17 80 4
* 38 52 1 52 35 89 92 54 89 98
* 47 10 26 83 88 49 72 90 18 80
* 100 93 17 71 58 9 7 89 39 16
* 45 42 40 58 86 66 60 39 4 74
* 89 36 16 24 79 50 100 96 34 63
* 4 88 93 96 82 100 6 55 97 63
* 28 14 7 16 10 27 41 56 62 41
* 68 30 31 31 26 68 87 48 87 42
* 87 90 100 13 86 35 27 42 40 89
* 52 62 68 21 20 96 1 99 8 57
* 26 67 64 47 63 95 4 45 30 99
* 11 94 73 9 83 16 49 6 24 44
* 80 37 16 35 68 67 54 58 72 10
* 29 29 31 74 88 24 81 36 20 84
* 16 5 21 97 44 58 32 56 42 90
* 64 58 63 57 8 89 67 98 33 51
* 100 100 53 57 85 60 23 2 58 94
* 72 4 45 52 84 6 26 7 29 43
* 84 45 57 45 32 7 82 21 29 40
* 71 35 36 69 96 81 88 78 74 93
* 77 77 100 14 82 42 90 82 65 59
* 92 13 27 12 33 73 43 10 28 19
* 51 67 98 73 8 53 46 32 73 97
* 66 52 99 89 46 82 87 58 45 28
* 8 46 10 27 79 20 9 81 97 53
* 71 62 52 73 32 6 92 21 58 99
* 99 63 73 75 98 71 89 62 42 99
* 11 85 24 3 75 37 17 7 57 54
*
* Number of parallel even integers: 132/500 (26.40%)
*/
