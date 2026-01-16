#include<unordered_map>
#include<iostream>
using namespace std;


int main(){
    unordered_map<int,string>mp;

    // storing the values inside the map
    // mp[1] = "Sushantt";
    // mp[2]  = "Nishant";


    for(int i=0;i<4;i++){
        cout << "Enter the value for the key:"<< i << " ";
        cin >> mp[i]; 
    }


    // Printing the values stored in the map
    for(auto it:mp){
        cout << it.first <<  "->" << it.second << endl;
    }

    // iterating thru the iterator
    unordered_map<int,string>:: iterator it = mp.begin();

    

}