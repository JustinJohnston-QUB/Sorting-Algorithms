#include<iostream>
#include<ctime>
#include "Source.h"

using namespace std;
void createArray(int* array, int size ,int maxRand) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		array[i] = (rand() % maxRand) + 1;
	}
}

void printArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << "[" << array[i] << "] ";
	}
	cout << endl;
}

void quickSort(int* array, int first, int last) {
	//O(N log2 N)
	int i = first, j = last;
	int pivot = array[(first + last) / 2];
	while (i < j) {
		while (array[i] < pivot) i++;
		while (array[j] > pivot) j--;
		if (i <= j) {
			int temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			i++, j--;
		}
	}
	if (first < i - 1)quickSort(array,first,i-1);
	if (i < last) quickSort(array, i, last);
}

void selectionSort(int* array, int size) {
	// O(N2)
	for (int i = 0; i < size; i++) {
		int smallestIndex = i;
		for (int j = i; j < size; j++) {
			if (array[j] < array[smallestIndex])smallestIndex = j;
		}
			int temp = array[i];
			array[i] = array[smallestIndex];
			array[smallestIndex] = temp;
	}
}

void bubblesort(int* array, int size) {
	// O(N2)
	bool sorted = false;
	while(!sorted){
		sorted = true;
		for (int i = 0; i < size - 1; i++) {
			if (array[i] > array[i + 1]) {
				sorted = false;
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	
	}
}

void insertionSort(int* array, int N) {
	// iterate through array from first position 
	//get the value to be sorted
	//set position marker to 0
	//find insertion position
	//iterate from end of array to the position found 
		//swap values
//set the value at position found
	for (int x = 1; x < N; x++) {
		int value = array[x];
		int position = 0;
		while (position < x && array[position] <= value) position++;
		for (int y = x - 1; y >= position; y--) {
			array[y + 1] = array[y];
		}
		array[position] = value;
	}
}

int main() {
	//variables
	int size = 20;
	int maxRand = 100;
	int* array = new int[size];

	//methods
	createArray(array,size,maxRand);
	printArray(array, size);
	//quickSort(array, 0, size - 1);
	//bubblesort(array, size);
	//selectionSort(array, size);
	insertionSort(array, size);
	printArray(array, size);

	delete[] array;
	return 0;
}