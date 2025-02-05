#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited;
        visited.resize(n, 0);
        deque<int> queue;
        queue.push_back(0);
        while(!queue.empty()){
            auto key = queue.front();
            for(auto i : rooms[key]){
                if(visited[i] == 0) queue.push_back(i);
            }
            visited[key] = 1;
            queue.pop_front();
        }

        for(auto visit:visited){
            if(visit == 0) return false;
        }
        return true;
    }
};