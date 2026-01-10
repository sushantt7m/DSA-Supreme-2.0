// complete Binary Tree -> except Last level, saare level complete Honge
// all the Nodes in the last Level filled from left to right in continuous manner
// Implementation of the heap is done by Array not tree
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(7);
    pq.push(8);
    pq.push(2);
    pq.push(4);

    cout << "Size is : " << pq.size() << endl;
    cout << "isEmpty : " << pq.empty() << endl;
    cout << "Top Element : " << pq.top() << endl;
    pq.pop();       // removes the max element/highest element
    cout << "Top Element : " << pq.top() << endl;     

    return 0;
}