using namespace std;


void bubbleSort (int arr[], int size){
    for (int i=0 ; i<size-1;i++){
        int j=0;
        while (j <=size-2-i){
            if (arr[j]>arr[j+1]){
                swap (arr[j+1],arr[j]);
            }j++;
        }
    }
}
