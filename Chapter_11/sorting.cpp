#include<iostream>

using namespace std;

void swap(int* xa, int* ya) {
	int temp;
	temp = *xa;
	*xa = *ya;
	*ya = temp;
}

void bubble_sort(int arr[], int n) {//O(n2)
	bool swapped;
	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {//optimization, if completely sorted
			break;
		}
	}
}

void selection_sort(int arr[], int n) {//O(n2)
	int min_ind;
	for (int i = 0; i < n-1; i++) {
		min_ind = i;
		for (int j = i+1; j < n; j++) {
			if (arr[min_ind] > arr[j]) {
				min_ind = j;
			}
			swap(&arr[i], &arr[min_ind]);
		}
	}
}

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<' ';
	}
	cout << endl;
}
int main() {

	int arr[] = { 5, 4, 6, 78, 8, 9, 7, 8, 4, 1 };
	print_array(arr, 10);
	selection_sort(arr, 10);
	print_array(arr, 10);
	return 0;
}