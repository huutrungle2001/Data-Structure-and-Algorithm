#include <bits/stdc++.h>
using namespace std;

void display(const vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        cout << nums[i] << ",";
    }
    cout << nums[nums.size() - 1] << endl;
}

void selectionSort(vector<int> &nums, int step) {
    for (int i = 0; i < step; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] < nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    cout << "Step " << step << ":\n";
    display(nums);
}

void insertTionSort(vector<int> &nums, int step) {
    for (int i = 0; i < step; i++) {
        int temp = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] < temp) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
    cout << "Step " << step << ":\n";
    display(nums);
}

void bubbleSort(vector<int> &nums, int step) {
    for (int i = 0; i < step; i++) {
        for (int j = 0; j < nums.size() - i - 1; j++) {
            if (nums[j] < nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    cout << "Step " << step << ":\n";
    display(nums);
}

int main() {
    // Điền dãy số vào đây
    vector<int> nums{116, 149, 69, 153, 161, 1, 184, 72, 28, 31, 21, 105, 48, 81, 54};
    // Chọn thuật toán đề bài yêu cầu, và số bước rồi chạy
    // selectionSort(nums, 5);
    // insertTionSort(nums, 5);
    bubbleSort(nums, 4);
}