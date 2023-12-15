class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> graph;
        map<string, bool> visited;
        map<string, int> indegrees;
        string root, last;

        for(int i = 0; i < paths.size(); i++) {
          string a = paths[i][0];
          string b = paths[i][1];
          visited[a] = false;
          visited[b] = false;
          graph[a] = b;

          indegrees[a] += 0;
          indegrees[b] += 1;
        }

        for(auto& [key, value] : indegrees) {
          if(value == 0) {
            root = key;
            break;
          }
        }

        queue<string> q;
        q.push(root);
        visited[root] = true;
        last = root;
        while(!q.empty()) {
          string u = q.front();
          q.pop();
          last = u;

          string next = graph[u];
          if(visited[next] || next.size() == 0) continue;
          visited[next] = true;
          q.push(next);
        }

        return last;
    }
};