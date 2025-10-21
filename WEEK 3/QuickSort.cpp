#include <iostream>
#include <vector>
using namespace std;


int partition(int & arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int & arrayInterger [],int left,int right) {
    if (left<right){
        int pi = partition(arrayInterger,left,right);
        quicksort(arrayInterger,left,pi-1);
        quicksort(arrayInterger,pi +1,right);
    }
}



int main() {
	return 0;
}


