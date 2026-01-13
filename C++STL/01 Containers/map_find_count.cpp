#include<iostream>
#include<unordered_map>
using namespace std;



int main(){
    unordered_map<string,string>table;

    table.insert(make_pair("in","India"));
    table["br"] = "brazil";
    // pair<string,string>p ("en","england");
    pair<string,string>p;
    // p.first = "en";
    // p.second = "england";
    table.insert(p);
    cout << table.size() << endl;


    if(table.find("in")!=table.end()){
        cout << "Key found "<< endl;
    }
    else{
        cout << "key Not found"<<endl;
    }

    if(table.count("indd")==0){
        // Key not found
        cout << "key not found" << endl;
    }
    else{
        cout << "key found" << endl;
    }
}