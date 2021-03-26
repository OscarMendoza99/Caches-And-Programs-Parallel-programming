#include <iostream>
#include <chrono>
#include <ctime> 

#define MAX 350

using namespace std;

std::chrono::time_point<std::chrono::high_resolution_clock> inicio, fin;
int64_t duracion;

int main()
{
	double A[MAX][MAX], x[MAX], y[MAX];
	//Initialize A and x, assign y = 0
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			double s = (double)rand() / RAND_MAX;
			A[i][j] = 0 + s * (1000000);
		}
		double f = (double)rand() / RAND_MAX;
		x[i] = 0 + f * (1000000);
		y[i] = 0;
	}
	//First pair of loops
	inicio = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			y[i] += A[i][j] * x[j];
		}
	}
	fin = std::chrono::high_resolution_clock::now();
	duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio) .count();
	std::cout << "Execution Time (Second pair of loops): " << duracion << endl;
	//Assign y = 0
	for (int i = 0; i < MAX; i++) {
		y[i] = 0;
	}
	//Second pair of loops
	inicio = std::chrono::high_resolution_clock::now();
	for (int j = 0; j < MAX; j++) {
		for (int i = 0; i < MAX; i++) {
			y[i] += A[i][j] * x[j];
		}
	}
	fin = std::chrono::high_resolution_clock::now();
	duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio).count();
	std::cout << "Execution Time (Second pair of loops): " << duracion << endl;
}
