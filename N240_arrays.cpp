#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // last index of nums1's real elements
        int j = n - 1;       // last index of nums2
        int k = m + n - 1;   // last index of nums1 (total size)
        // Merge from the end of nums1
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            } else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        // Copy remaining elements from nums2 (if any)
        while (j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
int main() {
    // Taking input from user
    int m, n;
    cout << "Enter size m for nums1 (non-zero elements): ";
    cin >> m;
    cout << "Enter size n for nums2: ";
    cin >> n;
    vector<int> nums1(m + n);
    vector<int> nums2(n);
    cout << "Enter " << m << " elements for nums1: "<<endl;
    for (int i = 0; i < m; i++) cin >> nums1[i];
    cout << "Enter " << n << " elements for nums2: "<<endl;
    for (int i = 0; i < n; i++) cin >> nums2[i];
    Solution().merge(nums1, m, nums2, n);
    cout << "Merged array: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    return 0;
}
