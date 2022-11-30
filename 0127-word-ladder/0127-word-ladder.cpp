class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        while(!q.empty()){
            pair<string, int> s = q.front();
            q.pop();
           string word = s.first;
            int d = s.second;
            if(word==endWord) return d;
            st.erase(word);
            for(int i=0; i<beginWord.size(); i++){
                char k = word[i];
                for(char c='a'; c<='z'; c++){
                    word[i] = c;
                    if(st.count(word)){
                         q.push({word, d+1});
                    }
                }
                word[i] = k;
            }
            
        }
        return 0;
    }
};