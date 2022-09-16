#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &num : nums) {
        cin >> num;
    }

    int countNonNegative = 0;
    int sumPositive = 0;

    for (int num : nums) {
        if (num >= 0) {
            countNonNegative++;
            sumPositive += num;
        }
    }

    if (countNonNegative == 0) {
        cout << 0 << endl;
    } else {
        cout << setprecision(3) << fixed << float(sumPositive * 1.0 / countNonNegative * 1.0) << endl;
    }
}