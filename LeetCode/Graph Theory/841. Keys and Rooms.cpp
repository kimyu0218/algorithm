class Solution {
public:
    void dfs(int room, vector<bool> &unlock, vector<vector<int>> &rooms) {
        unlock[room] = true;

        for(int i = 0; i < rooms[room].size(); i++) {
            int next_room = rooms[room][i];
            if(!unlock[next_room]) {
                dfs(next_room, unlock, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> unlock(n, false);

        dfs(0, unlock, rooms);
        for(int i = 1; i < n; i++) {
            if(!unlock[i]) {
                return false;
            }
        }
        return true;
    }
};