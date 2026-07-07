class Solution {
public:
    struct Task{
        char c;
        int freq;
        int coolDown = 0;

        bool operator<(const auto& t) const {
            return freq < t.freq;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        int cycles = tasks.size();
        unordered_map<char, int> freq(26);
        queue<Task> q;
        priority_queue<Task> pq;
        for(int i = 0; i < tasks.size(); i++){
            cout << tasks[i] << " ";
            freq[tasks[i]] += 1;
        }
        for(auto &p : freq){
            Task t = {p.first, p.second};
            pq.push(t);
        }
        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!q.empty() && time-q.front().coolDown > n){
                Task t = q.front();
                q.pop();
                t.coolDown = time;
                if(t.freq > 0) pq.push(t);
            }
            if(!pq.empty()){
                Task top = pq.top();
                pq.pop();
                top.freq--;
                top.coolDown = time;
                if(top.freq > 0) q.push(top);
            }
        }

        cout << endl;
        return time;
    }
};
