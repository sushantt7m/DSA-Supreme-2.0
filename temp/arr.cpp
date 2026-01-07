#include <iostream>
using namespace std;
#include <vector>

void printArr(vector<int> &arr)
{
    for (int nums : arr)
    {
        cout << nums << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};

    for (int i = 0; i < arr.size()-1; i++)
    {
        int temp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i]=temp;
        cout << "Iteration " << i << " : " << endl;
        printArr(arr);
    }
    return 0;
}