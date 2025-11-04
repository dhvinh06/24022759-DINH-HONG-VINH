#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


void merge (int & arrayInterger [],int left,int mid,int right){
    int size1 = mid - left +1;
    int size2 = right - mid;
    int array1 [size1];
    int array2 [size2];
    for (int i=0;i<size1;i++){
        array1[i] = arrayInterger;
    }for (int i=0;i<size2;i++){
        array2 [i]= arrayInterger[size1+i];
    }int count1=0;
    int count2=0;
    int i = left;
    while (count1<size1&&count2<size2){
        if (array1[count1]<array2[size2]){
            arrayInterger [i++]= array1[count1++];
        }else {
            arrayInterger[i++]= array2[count2++]
        }
    }while (count1<size1){
        arrayInterger[i++]= array1 [ count1 ++];
    }while (count2<size2){
        arrayInterger[i++]= array2[count2++]
    }
}

void mergesort(int & arrayInterger [],int left,int right) {
    if (left<right){
        int mid = (left+right)/2;
        mergesort(arrayInterger,left,mid);
        mergesort(arrayInterger,mid+1,right);
        merge(arrayInterger,left,mid,right);
    }
}



int main() {
	return 0;
}


