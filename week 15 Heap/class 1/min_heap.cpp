#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // min-heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(7);
    pq.push(8);
    pq.push(2);
    pq.push(4);

    cout << "Top Element: " << pq.top() << endl;
    pq.pop();       // removes the minimum vlue from the heap    
    cout << "Top Element: " << pq.top() << endl;
    return 0;
}