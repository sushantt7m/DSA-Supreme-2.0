#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int index;
    int size;

    // ctor
    Heap(int capacity)
    {
        size = capacity;
        arr = new int[size];
        index = 0;
    }

    void insertElement(int value)
    {
        if (index == size - 1)
        {
            cout << "Overflow" << endl;
        }

        index++;
        arr[index] = value;

        // the elemnt which needs to be heapified is "index"
        // now we need to heapify the element we just added
        int childIndex = index;
        int parentIndex = childIndex / 2;

        while (childIndex > 1)
        {

            // checking whether the child index is greater than the parenIndex or not
            if (arr[childIndex] > arr[parentIndex])
            {
                swap(arr[childIndex], arr[parentIndex]);
                // update the indedx of the new child which is the parentIndex
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void deleteElement(){
        if(index == 0){
            cout << "Underflow:";
            return;
        }

        swap(arr[index],arr[1]);
        index--;

        // Heapification of the element just swapped
        int parentIndex = 1;
        HeapifyElement(arr,index,parentIndex);
    }
    void HeapifyElement(int*arr,int index,int parentIndex){
        int left = 2*parentIndex;
        int right = 2*parentIndex+1;
        int largestElementIndex = parentIndex;
        if(left <= index && arr[left]>arr[parentIndex] ){
            largestElementIndex = parentIndex;
        }
        if(right<=index && arr[right]>arr[largestElementIndex]){
            largestElementIndex = right;
        }

        // checking if the parentIndex value has been modified or same 
        if(parentIndex == largestElementIndex){
            return;
        }
        else{
            swap(arr[parentIndex],arr[largestElementIndex]);
            // update the value of parentIndex to be largestIndex
            parentIndex = largestElementIndex;
            // recursive calls
            HeapifyElement(arr,index,parentIndex);
        }
    }
};
void printHeap(Heap pq)
{
    int index = pq.index;
    cout << "The Heap Element are: ";
    for (int i = 1; i <= index; i++)
    {
        cout << pq.arr[i] << " ";
    }
    cout << endl;

}






int main()
{
    int size;
    cout << "Enter the Size of the Heap you want to create: ";
    cin >> size;


    Heap pq(size);
    int data;
    cout << "Enter the Data to be Inserted: ";
    cin >> data;

    while (data != -1)
    {
        pq.insertElement(data);
        cout << "Enter Data: ";
        cin >> data;
    }

    // Now we will just print the Heap
    printHeap(pq);
    pq.deleteElement();
    printHeap(pq);
    return 0;
}