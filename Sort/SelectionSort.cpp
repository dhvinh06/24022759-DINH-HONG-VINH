using namespace std;


void selectionSort (int arr[], int size){
    for (int i=0;i<size-1;i++){
        int indexMin = i;
        for (int j = i+1;j<size;j++){
            if (arr[j]<arr[indexMin]){
                indexMin = j;
            }
        }swap (arr[i],arr[indexMin]);
    }
}
