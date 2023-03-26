class Solution {
public:
    int longestCycle(vector<int>& e) {
    int res = -1;
    vector<pair<int, int>> memo(e.size(), {-1, -1});
    for (int i = 0; i < e.size(); ++i)
        for (int j = i, dist = 0; j != -1; j = e[j]) {
            auto [distI, fromI] = memo[j];
            if (distI == -1){
                memo[j] = {dist++, i};
            }
            else {
                if (fromI == i)
                    res = max(res, dist - distI);
                break;
            }
        }
    return res;
}
};