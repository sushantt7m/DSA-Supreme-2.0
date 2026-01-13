#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>>arr(4,vector<int>(4,0));
    int row = arr.size();
    int col = arr[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // creating jagged array
    vector<vector<int>>jaggedArray(4);
    vector<int>row1(4,-1);
    vector<int>row2(2,0);
    vector<int>row3(5,1);
    vector<int>row4(3,2);

    jaggedArray.push_back(row1);
    jaggedArray.push_back(row2);
    jaggedArray.push_back(row3);
    jaggedArray.push_back(row4);

    // printing the jagged array
    for(int i=0;i<jaggedArray.size();i++){
        for(int j=0;j<jaggedArray[i].size();j++){
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}