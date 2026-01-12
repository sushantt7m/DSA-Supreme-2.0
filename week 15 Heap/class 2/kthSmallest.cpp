// index is the pointer which is pointing on the last inserted element in the array
// size is the total capacity of the array / HEAP
#include <iostream>
#include <queue>
using namespace std;

class Heap
{
public:
    int *arr;
    int index;
    int size;

    // default ctor
    Heap(int value)
    {
        size = value;
        arr = new int[size];
        index = 0;
    }
};

void heapify(int *arr, int capacity, int parentIndex)
{
    int left = 2 * parentIndex;
    int right = 2 * parentIndex + 1;
    int largestIndex = parentIndex; // assumed largest for now, we will update later

    if (left < capacity && arr[left] > arr[largestIndex])
    {
        largestIndex = left;
    }
    if (right < capacity && arr[right] > arr[largestIndex])
    {
        largestIndex = right;
    }

    // we will check if the above two ifs condition has done anything or not

    // this if condition will act as the base case for the recursion
    if (parentIndex == largestIndex)
    {
        // this means nothing has been done
        // se no heapification required
        return;
    }
    else
    {
        // this means largest value exists in childNode
        // we need to heapify
        swap(arr[parentIndex], arr[largestIndex]);
        // update the parentIndex for further heapification
        // basically recursive call statement ke liye parentIndex update krenge
        parentIndex = largestIndex;
        // recursive call
        heapify(arr, capacity, parentIndex);
    }

    // return; //we will check this later on
}

// hmlog heap build krne ka logic likhenge joki array se value aa rhi hogi
void buildHeap(int *arr, int size)
{

    for (int i = size / 2; i >= 1; i--)
    {
        heapify(arr, size, i);
    }
}

int kthSmallestElement(int arr[], int size, int k)
{
    if (k == 0)
    {
        return -1;
    }
    priority_queue<int> pq;
    // iss queue me hm insert kr denge k elements from the array
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // max heap created in pq till k elements from nums array

    // now we will check if the remaining element in the array has any element
    // lesser than the max element of the max-heap pq
    for (int i = k; i < size; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();        // dlete the top element
            pq.push(arr[i]); // push the new smaller element from array in place of larger element of maxHeap
        }
    }

    // now after this much operation
    // the element at the top of the heap would be our kth smallest eleemnt
    return pq.top();
}

int main()
{
    // creating an array to be heapified
    int arr[] = {-1, 2, 3, 10, 50, 14, 17, 9};
    int size = sizeof(arr) / sizeof(int); // size==8

    cout << "Printing the Array before buildHeap called: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // building heap array
    buildHeap(arr, size);

    // printing logic
    cout << "Printing the Array after buildHeap called: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // everythingwell and good till now
    // what i was thinking is , if i create an array with k elements and heapify it as max-Heap
    // then the three elements at the end would be consideered the 3 elem

    int nums[] = {2, 3, 10, 50, 14, 17, 9};
    int n = sizeof(nums) / sizeof(int);
    int k = 2;
    int answ = kthSmallestElement(nums, n, k);
    if (answ == -1)
    {
        cout << "Invalid value of k " << endl;
    }   
    else
    {
        cout << "The kth Smallest Element from nums array is : " << answ << endl;
    }
    return 0;
}