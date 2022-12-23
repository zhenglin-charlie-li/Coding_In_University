// Top K 问题
// 1. 暴力: 排序, ==> 返回数组中倒数第k个元素, Time => O(nlogn), Space => O(1)
// 2. 快速选择, 利用partition, 分治, Time => O(n), O(n^2), Space => O(1)
// 3. 小顶堆: 遍历, 先建堆至大小为K, 后处理>的情况, Time => O(n), Space => O(k)
// 4. 大顶堆: 遍历, 数组所有元素参与建堆, 后删除K-1次, Time => O(n), Space => O(n)
// 5. 桶: 桶排序, -104 <= nums[i] <= 104, Time => O(n), Space => O(1)

class Solution {
    public int findKthLargest(int[] nums, int k) {
        // num => num = 10000
        int[] bins = new int[200001];
        for (int num: nums)
            bins[num + 10000]++;
        for (int i = bins.length - 1; i >= 0; i--) {
            if (k - bins[i] <= 0)
                return i - 10000;
            k -= bins[i];
        }
        return 0;
    }
}








