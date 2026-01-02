#include<iostream>
#include<vector>
using namespace std;

int ExtremePrint(vector<int>arr){
    int left=0;
    int right=arr.size()-1;
    int i=0;
    while(left<right){
        cout << arr[left] << " ";
        cout << arr[right] << " ";
        left++;
        right--;
    }
    // for(int j=0;j<arr.size();j++){
    //     cout << arr[j] << " ";
    // }
}

int main(){
    vector<int>arr{10,20,30,40,50,60,70,80};
    ExtremePrint(arr);
}