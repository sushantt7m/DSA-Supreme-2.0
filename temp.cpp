#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 6;

    // a > b ? (cout << a << endl) : (cout << b << endl);

    // a < count ? a = count : a = a;
    // a = max(count, a);
    int nums[] = {1,2,4,5,6,7};

    for(int i=0;i<6;i++){
        cout << nums[i];
    }
    cout << endl;

    for(int ans:nums){
        cout << ans ;
    }

    cout << endl;
    cout << "Explaining XOR"<< endl;
    int ans = 5;
    int x = 6;
    ans = ans ^ b;
    cout << ans;
}