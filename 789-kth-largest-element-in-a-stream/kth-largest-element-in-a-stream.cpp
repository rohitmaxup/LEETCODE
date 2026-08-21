class KthLargest {
private:
    int maxCapacity;
    priority_queue<int, vector<int>, greater<int>> topKHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        maxCapacity = k;
        for (size_t i = 0; i < nums.size(); ++i) {
            add(nums[i]);
        }
    }

    int add(int val) {
        topKHeap.push(val);
        if (topKHeap.size() > maxCapacity) {
            topKHeap.pop();
        }
        return topKHeap.top();
    }
};
