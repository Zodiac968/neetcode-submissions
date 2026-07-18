class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> cr(numCourses, vector<int>(numCourses+1, -1));
        for(int i = 0; i < prerequisites.size(); i++){
            cr[prerequisites[i][0]][prerequisites[i][1]] = 1;
            cr[prerequisites[i][0]][numCourses]++;
        }
        queue<int> q;
        for(int i = 0; i < cr.size(); i++){
            if(cr[i][numCourses] == -1) q.push(i);
        }
        while(!q.empty()){
            int c = q.front();
            q.pop();
            for(int i = 0; i < cr.size(); i++){
                if(cr[i][c] == 1){
                    cr[i][c] = -1;
                    if(--cr[i][numCourses] == -1) q.push(i);
                }
            }
        }
        // for(int i = 0; i < cr.size(); i++){
        //     for(int j = 0; j < cr[0].size(); j++){
        //         cout << cr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0; i < cr.size(); i++){
            if(cr[i][numCourses] != -1) return false;
        }
        return true;
    }
};
