#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string s = to_string(N);
    int ans = 0;
    while(N > 0) {
        string s = to_string(N);
        int maxi = s[0]-'0';
        for(char c : s){
            int digit = c- '0';
            maxi=max(digit,maxi);
        }
        if(maxi == 0) {
            break; // If the maximum digit is 0, we cannot remove any more digits
        }
        N -= maxi; // Remove the maximum digit from N
        ans++; // Increment the count of operations
    }

    cout << ans << endl;
    return 0;
}