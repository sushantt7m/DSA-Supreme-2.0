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
    void deleteElement()
    {
        if (index == 0)
        {
            cout << "Underflow:";
            return;
        }

        swap(arr[index], arr[1]);
        index--;

        // Heapification of the element just swapped
        int parentIndex = 1;
        HeapifyElement(arr, index, parentIndex);
    }
    void HeapifyElement(int *arr, int index, int parentIndex)
    {
        int left = 2 * parentIndex;
        int right = 2 * parentIndex + 1;
        int largestElementIndex = parentIndex;
        if (left <= index && arr[left] > arr[parentIndex])
        {
            largestElementIndex = parentIndex;
        }
        if (right <= index && arr[right] > arr[largestElementIndex])
        {
            largestElementIndex = right;
        }

        // checking if the parentIndex value has been modified or same
        if (parentIndex == largestElementIndex)
        {
            return;
        }
        else
        {
            swap(arr[parentIndex], arr[largestElementIndex]);
            // update the value of parentIndex to be largestIndex
            parentIndex = largestElementIndex;
            // recursive calls
            HeapifyElement(arr, index, parentIndex);
        }
    }
};

void heapify(int *arr, int capacity, int parentIndex)
{
    int left = parentIndex * 2;
    int right = parentIndex * 2 + 1;
    int largestIndex = parentIndex;

    if (left < capacity && arr[left] > arr[parentIndex])
    {
        largestIndex = left;
    }
    if (right < capacity && arr[right] > arr[largestIndex])
    {
        largestIndex = right;
    }

    // Now we will check if there is mofification in the largestIndex or not
    if (largestIndex == parentIndex)
    {
        // there is no modification
        // So no swapping
        return;
    }
    else
    {
        // since the initial and largest are not same, we need to swap it
        swap(arr[largestIndex], arr[parentIndex]);
        parentIndex = largestIndex;
        // recursive calls for further nodes
        heapify(arr, capacity, parentIndex);
    }

    // while(childElementIndex >1){
    //     if(arr[parentIndex]<arr[childElementIndex]){
    //         swap(arr[parentIndex],arr[childElementIndex]);
    //         childElementIndex = parentIndex;
    //     }
    //     else{
    //         break;
    //     }
    // }
}

void buildHeap(int *arr, int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
}

void HeapSort(int *arr, int index)
{
    while (index > 1)
    {
        swap(arr[1], arr[index]);
        index--;
        heapify(arr, index, 1);
    }
}

int main()
{
    int arr[] = {-1, 10, 20, 30, 40, 50};
    int size = 6;
    buildHeap(arr, size);
    // Printing arr/heap

    for (int i = 1; i <size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // HeapSort Function call
    HeapSort(arr, size-1);
    cout << "printing array " << endl;
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}