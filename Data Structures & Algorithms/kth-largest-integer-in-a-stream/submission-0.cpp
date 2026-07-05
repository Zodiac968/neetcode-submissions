class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minpq;
    int k; 
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0; i < nums.size(); i++){
            minpq.push(nums[i]);
            if(minpq.size() > k){
                minpq.pop();
            }
        }
    }
    
    int add(int val) {
        minpq.push(val);
        if(minpq.size() > k) minpq.pop();
        return minpq.top();
    }
};
