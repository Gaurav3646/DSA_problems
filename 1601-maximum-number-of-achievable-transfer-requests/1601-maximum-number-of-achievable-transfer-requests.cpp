class Solution {
public:
    int memo[21] = {};
int maximumRequests(int n, vector<vector<int>>& requests, int i = 0) {
    if (i == requests.size())
        return count(begin(memo), begin(memo) + n, 0) == n ? 0 : INT_MIN;
    --memo[requests[i][0]];
    ++memo[requests[i][1]];
    auto take = 1 + maximumRequests(n, requests, i + 1);
    ++memo[requests[i][0]];
    --memo[requests[i][1]];
    return max(take, maximumRequests(n, requests, i + 1));
}
};