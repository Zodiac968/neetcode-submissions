class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    int n = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        n++;
        if(n%2 == 1){
            if(!minpq.empty() && minpq.top() < num){
                maxpq.push(minpq.top());
                minpq.pop();
                minpq.push(num);
            }else maxpq.push(num);
        }else{
            if(maxpq.top() > num){
                minpq.push(maxpq.top());
                maxpq.pop();
                maxpq.push(num);
            }else minpq.push(num);
        }
    }
    
    double findMedian() {
        if(n%2 == 0){
            return (double)(minpq.top() + maxpq.top()) / 2;
        }
        return maxpq.top();
    }
};
