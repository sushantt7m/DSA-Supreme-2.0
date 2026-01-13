#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>first;
    first.push_back(10);
    first.push_back(11);
    first.push_back(12);
    first.push_back(13);

    // traversing the vector using iterator 

    // create an iterator
    vector<int>::iterator it = first.begin();
    
    while(it!=first.end()){
        cout << *it << " ";
        it++;
    }
}