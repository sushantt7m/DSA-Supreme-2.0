#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> marks;
    // push_back(const T&value) :Adds an element at the end of the vector
    marks.push_back(10);
    marks.push_back(20);
    marks.push_back(30);
    marks.push_back(40);
    // pop_back() :Removes the last element from the vector
    marks.pop_back();
    // size() :Returns the number of elements in the vector
    cout << marks.size() << endl;
    // front() :Accesses the first element in the vector
    cout << "Front Element: " << marks.front() << endl;
    // back() :Accesses the last element in the vector
    cout << "last element: " << marks.back() << endl;
    // begin() :Returns iterator pointing to the first element in vector
    cout << *marks.begin() << endl;
    // end() :returns iterator pointing just after the last element in the vector
    cout << *marks.end() << endl;
    // empty() :checks if the vector is empty
    if (marks.empty())
    {
        cout << "vector is empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }

    // at(size_type n) :Accessed the element at the specified index with bound checking
    cout << "'at' function: " << marks[0] << endl;
    cout << "'at' function: " << marks.at(0) << endl;
    // capacity() :Returns the number of element that the vector can hold before needing to allocate more spaces
    cout << "capacity: " << marks.capacity() << endl;
    // max_size() :Returns the maximum number of elements that the vectror can hold due to system or library limitations
    cout << marks.max_size() << endl;

    // clear() :Removes all the elements from the vector,which are destroyed and leaves  it with size 0
    // marks.clear();
    // cout << marks.size() << endl;
    // insert(iterator position, const T&value) :Inserts a new element before the specified position in the vector
    marks.insert(marks.begin(), 50);
    cout << marks[0] << endl;
    // erase(iterator position) or erase(iterator first,iterator last) :Removes on or more elements from the vector starting at the specified location
    // marks.erase(marks.begin(),marks.end());
    // cout << marks.size() << endl;

    vector<int> first;
    vector<int> second;

    first.push_back(10);
    first.push_back(20);
    first.push_back(30);
    first.push_back(40);

    second.push_back(100);
    second.push_back(200);
    second.push_back(300);
    second.push_back(400);

    // swap(vector&x): swaps the content of the vector with those of another vector of the same type, including their size and capacity
    first.swap(second);
    cout << first[0] << " " << first[1] << " " << first[2] << " " << first[3] << " " << endl;
}

// member functions
// reserve(size_type n) :Requests that the vector capacity be increased to at least n elements,potentially reducing the number of reallocations
// operator[](size_type n) :Accesses  the element at the specified index without bounds checking