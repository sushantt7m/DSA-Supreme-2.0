#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // creating a map
    unordered_map<string, string> table;

    // insertion
    // way-1
    table["ind"] = "india";

    // way-2
    // first create a pair
    pair<string, string> p;
    p.first = "br";
    p.second = "brazil";
    // insert this pair in the table/map
    table.insert(p);

    // way-3    (insert function of map)
    table.insert(make_pair("eng", "england"));

    // accessing using key -> at function
    cout << table.at("ind") << endl;
    cout << table.at("br") << endl;
    cout << table.at("eng") << endl;

    // modify the value using key
    table["ind"] = "india3";
    cout << table.at("ind") << endl;
    table.at("ind") = "india4";
    cout << table.at("ind") << endl;

    cout << "--------------------------------Break-------------------------------" << endl;

    // iterating the table
    unordered_map<string, string>::iterator it = table.begin();
    while (it != table.end())
    {
        cout << (*it).first << ": " << (*it).second << endl;
        it++;
    }
    // Or
    cout << "again" << endl;
    it = table.begin();
    while (it != table.end())
    {
        pair<string,string>p = *it;
        
        cout << p.first << ": " << p.second << endl;
        it++;
    }
    cout << table.size() << endl;
    // table.clear();
    table.erase(table.begin(),table.end());
    cout << table.size() << endl;
}