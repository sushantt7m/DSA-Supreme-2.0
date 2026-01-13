#include <iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    map<int,string> mp;
    mp.insert(make_pair(1,"Sushant"));
    mp.insert(make_pair(4,"Surya"));
    mp.insert(make_pair(3,"Shayank"));
    mp.insert(make_pair(2,"Nishant"));

    map<int,string>::iterator it = mp.begin();
    while(it!=mp.end()){
        cout << (*it).first << ": " << (*it).second << endl;
        it++;
    }
    return 0;
}