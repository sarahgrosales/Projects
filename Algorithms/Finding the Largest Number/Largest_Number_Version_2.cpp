// This code finds the largest number of an array by calling the int findLargest function unlike in version 1.

#include<iostream>
using namespace std;

int findLargest(int arr[], int x){
   int largestNum = 0;
   for (int i = 0; i < x; i++){
       for(int j = 0; j < x; j++){
           if (arr[i] > arr[j] && largestNum < arr[j]){
           largestNum = arr[i];
           } else if (arr[j]> largestNum) {
           largestNum = arr[j];
           }  
      
       }
   }
return largestNum;
}


int main (){
  int size = 5;
  int arr[size] = {54,23,456,23,1};
  cout << findLargest(arr, size) << endl;
}
