// C++ implementation for dot product
// and cross product of two vector.
#include <bits/stdc++.h>
#define n 3

using namespace std;

// Function that return
// dot product of two vector array.
int dotProduct(int vect_A[], int vect_B[])
{

	int product = 0;

	// Loop for calculate cot product
	for (int i = 0; i < n; i++)

		product = product + vect_A[i] * vect_B[i];
	return product;
}

// Function to find
// cross product of two vector array.
void crossProduct(int vect_A[], int vect_B[], int cross_P[])

{

	cross_P[0] = vect_A[1] * vect_B[2] - vect_A[2] * vect_B[1];
	cross_P[1] = vect_A[0] * vect_B[2] - vect_A[2] * vect_B[0];
	cross_P[2] = vect_A[0] * vect_B[1] - vect_A[1] * vect_B[0];
}

// Driver function
int main()
{

	int vect_A[] = { 3, -5, 4 };
	int vect_B[] = { 2, 6, 5 };
	int cross_P[n];

	// dotProduct function call
	cout << "Dot product:";
	cout << dotProduct(vect_A, vect_B) << endl;

	// crossProduct function call
	cout << "Cross product:";
	crossProduct(vect_A, vect_B, cross_P);

	// Loop that print
	// cross product of two vector array.
	for (int i = 0; i < n; i++)

		cout << cross_P[i] << " ";
	return 0;
}