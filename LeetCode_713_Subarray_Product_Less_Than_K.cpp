/*
  713. Subarray Product Less Than K

  Your are given an array of positive integers nums.
  Count and print the number of (contiguous) subarrays where the product of all the
  elements in the subarray is less than k.

  Example 1:
  Input: nums = [10, 5, 2, 6], k = 100
  Output: 8
  Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
  Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
*/

/*
Solution:
Assume, we have a window between start and end, and the product of all elements of it is p < k. Now, let's try to add a new element x. There are two possible cases.

Case 1. p*x < k
This means we can move the window’s right bound one step further. How many contiguous arrays does this step produce? It is: 1 + (end-start).

Indeed, the element itself comprises an array, and also we can add x to all contiguous arrays which have right border at end. There are as many such arrays as the length of the window.

Case 2. p*x >= k

This means we must first adjust the window’s left border so that the product is again less than k. After that, we can apply the formula from Case 1.
*/
    int numSubarrayProductLessThanK( vector<int>& nums, int k ) {
        int start = 0, prod = 1, count = 0;
        for( int end=0; end < nums.size(); end++ ) {
            // Move right bound by 1 step. Update the product.
            prod *= nums[end];
            // Move left bound so guarantee that p is again  
            // less than k.
            while( prod >= k && start <= end ) {
                    prod = prod / nums[start];
                    start++;
            }
            count += end - start + 1;
        }
        return count;
    }
