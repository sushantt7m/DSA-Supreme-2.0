#include<iostream>
#include<list>
using namespace std;


int main(){
    list<int>myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);

    myList.push_front(1);
    myList.pop_front();
    
    // 10->20->30->40

    cout << myList.front() << endl;
    cout << myList.back() << endl;
    
    // cout << myList.at(5) << endl << endl;

    cout << myList.size() << endl;

    // Traversing the list

    list<int>::iterator it = myList.begin();

    while(it!=myList.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl;
}