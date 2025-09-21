#include <iostream>
#include <vector> //for change value
#include <climits>   // For INT_MIN and INT_MAX
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // Ensure A is the smaller array
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);

        int m = A.size();
        int n = B.size();
        int low = 0, high = m;

        while (low <= high) {
            // Partition A and B
            int partitionA = (low + high) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            // Handle edges: if partition is at 0 or at the end
            int maxLeftA  = (partitionA == 0) ? INT_MIN : A[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : A[partitionA];

            int maxLeftB  = (partitionB == 0) ? INT_MIN : B[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : B[partitionB];

            // Check if partition is correct
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                // Even total length → average of two middle values
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } 
                // Odd total length → max of left side
                else {
                    return max(maxLeftA, maxLeftB);
                }
            }
            // Adjust partitionA
            else if (maxLeftA > minRightB) {
                high = partitionA - 1; // Move left
            } else {
                low = partitionA + 1;  // Move right
            }
        }
        return 0.0; // Should not reach here
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {0, 0};
    vector<int> nums2 = {0};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl; // 0

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << sol.findMedianSortedArrays(nums3, nums4) << endl; // 2.5
}
