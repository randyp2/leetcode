#include <iostream>
#include <stdexcept>
#include <vector>

class Solution {
  public:
    double find_median(std::vector<int> &nums1, std::vector<int> nums2,
                       int left, int right) {
        // Edge cases
        // current scope = length of 2
        // current scope = length of 1

        // Size of 1
        // Return the max number
        if (right - left == 0) {
            // return nums[right];
        }

        // Size of 2
        // Return the max number
        if (right - left == 1) {
            // return std::max(nums[left], nums[right]);
        }

        int median_idx = left + (right - left) / 2;
        double median = 0;

        if (right + 1 % 2) { // Even length

            // median = the median of the combined nums1 and num2 using some
            // index function
        }

        double median_left = find_median(nums1, num2, left, median_idx - 1);
        double median_right = find_median(nums1, num2, median_idx + 1, right);

        if (median_left <)

            throw std::runtime_error("Function not implmented yet...");
    }

    /**
     * What makes a number a true median:
     * 1) Number left of median is < median
     * 2) Number right of median is > median
     *
     * 3) Median of left half < median
     * 4) Median of right half > median
     *
     * -- Find median of the combines list
     *  (unsorted, just conceptually and index them as if combined)
     * -- Find median of left half
     * -- FInd median of right half
     * -- Recursively do this until
     *  One number remains or two numbers remain
     *
     *
     * Formula to index
     * idx  + min(leng(nums1), leng(num2))
     *
     */
    double findMedianSortedArrays(std::vector<int> &nums1,
                                  std::vector<int> &nums2) {

        const int SIZE_1 = nums1.size();
        const int SIZE_2 = nums2.size();

        int left = 0;
        int right = SIZE_1 + SIZE_2 - 1;

        while ()

            throw std::runtime_error("Function not implemented yet...");
    }
};

int main() {
    std::cout << "--- FIND MED IN SROTED ARRAYS ---\n";
    return 0;
}
