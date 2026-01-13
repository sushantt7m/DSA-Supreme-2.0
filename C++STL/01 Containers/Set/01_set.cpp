#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{
    set<int> st;

    st.insert(10);
    st.insert(15);
    st.insert(8);
    st.insert(4);
    st.insert(53);

    set<int>::iterator it = st.begin();

    while (it != st.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    cout << "------------------------unOrdered Set------------------------------" << endl;
    unordered_set<int> stt;

    stt.insert(10);
    stt.insert(15);
    stt.insert(8);
    stt.insert(4);
    stt.insert(53);

    unordered_set<int>::iterator itt = stt.begin();

    while (itt != stt.end())
    {
        cout << *itt << " ";
        itt++;
    }
    cout << endl;

    // functions

    cout << st.size() << endl;
    // st.clear();
    st.erase(st.begin(), st.end());
    cout << st.size() << endl;

    if (st.empty())
    {
        cout << "The set is Empty" << endl;
    }
    else
    {
        cout << "The set is not empty" << endl;
    }

    // find function stt
    if (stt.find(56) != stt.end())
    {
        cout << "The value is Present" << endl;
    }
    else
    {

        cout << "The value is not Present" << endl;
    }

    // count function 

    if(stt.count(53)==0){
        cout << "The value is not present" << endl;
    }
    else{
        cout << "The value is present"  << endl;
    }
    return 0;
}