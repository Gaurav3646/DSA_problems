class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        vector<int> visited(wordList.size());
        
        q.push({beginWord, 1});
        while(!q.empty()){
            pair<string, int> s = q.front();
            q.pop();
            for(int i=0; i<wordList.size(); i++){
               
               if(!visited[i]){
                   
                   int count=0;
               for(int j=0; j<beginWord.size(); j++){
                   if(s.first[j]!=wordList[i][j]){
                       count++;
                   }
               }
                if(count==1){
                    
                    if(wordList[i]==endWord){
                    return s.second+1;
                     }
                    visited[i]=1;
                    q.push({wordList[i], s.second+1});
                }
            }
            }
            
        }
        return 0;
    }
};