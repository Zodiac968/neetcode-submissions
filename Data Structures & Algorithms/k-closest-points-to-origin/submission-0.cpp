class Solution {
public:
    struct Point{
        int x, y;
        bool operator<(const Point& p) const {
            return x*x+y*y < p.x*p.x+p.y*p.y;
        }
        vector<int> getVector() const {
            return {x, y};
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point> pq;
        for(int i = 0; i < points.size(); i++){
            Point p = {points[i][0], points[i][1]};
            pq.push(p);
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(pq.top().getVector());
            pq.pop();
        }
        return res;
    }
};
