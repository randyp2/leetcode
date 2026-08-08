#include <climits>
#include <iostream>
#include <utility>
#include <vector>

class Solution {

  public:
    double findMedianSortedArrays(std::vector<int> &nums1,
                                  std::vector<int> &nums2) {
        const std::vector<int> *A = &nums1;
        const std::vector<int> *B = &nums2;

        if (nums2.size() < nums1.size())
            std::swap(A, B); // Point A to be the smaller vector

        const int m = A->size();
        const int n = B->size();

        const int total = m + n;
        const int half = (total + 1) / 2;

        int low = 0;
        int high = m;

        // We are guaranteed a correct partition
        while (true) {
            // Cardinality of each partition
            int i = (high + low) / 2;
            int j = half - i;

            int A_left = (i > 0) ? (*A)[i - 1] : INT_MIN;
            int A_right = (i < m) ? (*A)[i] : INT_MAX;

            int B_left = (j > 0) ? (*B)[j - 1] : INT_MIN;
            int B_right = (j < n) ? (*B)[j] : INT_MAX;

            // partition is correct
            if ((A_left <= B_right) && (B_left <= A_right)) {
                // Odd
                if (total % 2)
                    return std::max(A_left, B_left);
                else
                    return (std::max(A_left, B_left) +
                            std::min(A_right, B_right)) /
                           2.0;
            } else {
                if (A_left > B_right) // Decrease left partition in A arrray
                    high = i - 1;
                else // Increase partition in A array
                    low = i + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    std::cout << "--- ---\n";
    return 0;
};
