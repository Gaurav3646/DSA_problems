class node {

     node* links[26] = {NULL};
public:
     bool flag = false;
     
     bool containKey(char ch){
         return links[ch-'a'] != NULL;
     }
     void put(char ch, node* ptr){
         links[ch-'a'] = ptr;
     }
     node* get(char ch){
         return links[ch-'a'];
     }
     void setEnd(){
         flag = true;
     }
};


class Trie {
private:
    node* root;
    
public:
    Trie() {
      root = new node();
    }
    
    void insert(string word) {
        node* ptr = root;
        for(int i=0; i <word.size(); i++){
            if(!ptr->containKey(word[i])){
                ptr->put(word[i], new node());
            }
           ptr = ptr->get(word[i]);
        }
        ptr->setEnd();
    }
    
    bool search(string word) {
         node* ptr = root;
        for(int i=0; i<word.size(); i++){
            if(!ptr->containKey(word[i])){
                return false;
            }
            ptr = ptr->get(word[i]);
        }
       return ptr->flag;
        
    }
    
    bool searchString(string word, vector<int> dp){
       
        for(int i=0; i<word.size(); i++){
         if(!dp[i]) continue;
             node* ptr = root;
        bool ans = false;
        int j = i;
        while(j<word.size() && ptr->containKey(word[j])){
        ptr = ptr->get(word[j++]);
        if(ptr->flag==true) dp[j] = 1;
           
        }
        }
        return dp[word.size()];
    }
    
//     bool startsWith(string prefix) {
//            node* ptr = root;
//         for(int i=0; i<prefix.size(); i++){
//             if(!ptr->containKey(prefix[i])){
//                 return false;
//             }
//             ptr = ptr->get(prefix[i]);
//         }
//         return true;
//     }
};

class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* trie = new Trie();
        for(auto &w: wordDict){
            trie->insert(w);
        }
        vector<int> dp(s.size()+1);
        dp[0] = 1;
        return trie->searchString(s, dp);
        
    }
};