class Solution {

public:
    

    int longestStrChain(vector<string>& words) {

        vector<unordered_set<string>> MM(17);

        for (auto word : words) 

            MM[word.size()].insert(word);

        map<string, int> dpp;

        int bt = 1;

        for (int i = 16; i; i--) {

            if (MM[i-1].empty()) continue;

            for (auto word : MM[i]) {

                int Val1 = dpp[word] ? dpp[word] : 1;

                for (int j = 0; j < word.size(); j++) {

                    string prd = word.substr(0,j) + word.substr(j+1);

                    int Val2 = dpp[prd] ? dpp[prd] : 1;

                    if (MM[i-1].find(prd) != MM[i-1].end() && Val1 >= Val2) {

                        dpp[prd] = Val1 + 1;

                        bt = max(bt, Val1 + 1);

                    }

                }

            }

        }

        return bt;

    }

};