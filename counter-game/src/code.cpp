#include <iostream>

using namespace std;

string counterGame(long n) {
    int zeros = 0;
    long temp = n;
    while(temp > 0 && (temp & 1) == 0) {
        zeros++;
        temp = (temp >> 1);
    }
    
    temp = n;
    int ones;
    for (ones = 0; temp; temp >>= 1)
    {
      ones += temp & 1;
    }
    
    int sum = ones - 1 + zeros;
    
    return (sum%2 == 1) ? "Louise" : "Richard";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        string result = counterGame(n);
        cout << result << endl;
    }
    return 0;
}
