class Solution {
public:
    struct Node{
        int val;
        bool isChild;
        vector<Node*> next;
    };

    bool dfs(Node* start, vector<int>& visited){
        if(visited[start->val] == 0) return false;
        visited[start->val] = 0;
        bool res = true;
        for(int i = 0; i < start->next.size(); i++){
            res &= dfs(start->next[i], visited);
        }
        visited[start->val] = 1;
        return res;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Node*> courses;
        for(int i = 0; i < numCourses; i++){
            Node* t = new Node({i, false});
            courses.push_back(t);
        }
        for(int i = 0; i < prerequisites.size(); i++){
            courses[prerequisites[i][1]]->next.push_back(courses[prerequisites[i][0]]);
            courses[prerequisites[i][0]]->isChild = true;
        }
        vector<int> visited(numCourses, -1);
        for(int i = 0; i < courses.size(); i++){
            cout << courses[i]->val << endl;
            if(courses[i]->isChild) continue;
            bool res = dfs(courses[i], visited);
            if(res == false) return false;
        }
        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == -1) return false;
        }
        return true;
    }
};
