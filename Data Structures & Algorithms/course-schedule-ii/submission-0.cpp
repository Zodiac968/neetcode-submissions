class Solution {
public:
    struct Node{
        int val;
        int indegree;
        vector<Node*> branch;
    };

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Node*> courses;
        for(int i = 0; i < numCourses; i++){
            courses.push_back(new Node({i, 0}));
        }
        for(int i = 0; i < prerequisites.size(); i++){
            courses[prerequisites[i][1]]->branch.push_back(courses[prerequisites[i][0]]);
            courses[prerequisites[i][0]]->indegree++;
        }

        vector<int> path;
        queue<Node*> q;
        for(int i = 0; i < courses.size(); i++){
            if(courses[i]->indegree == 0) q.push(courses[i]);
        }
        while(!q.empty()){
            Node* t = q.front();
            q.pop();
            path.push_back(t->val);
            for(int i = 0; i < t->branch.size(); i++){
                if(--t->branch[i]->indegree == 0) q.push(t->branch[i]);
            }
        }
        if(path.size() < numCourses) return {};
        return path; 
    }
};
