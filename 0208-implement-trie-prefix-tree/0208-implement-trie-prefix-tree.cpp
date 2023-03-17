
// structure of node
 struct node{
     node* links[26] = {NULL};
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
    
    bool startsWith(string prefix) {
           node* ptr = root;
        for(int i=0; i<prefix.size(); i++){
            if(!ptr->containKey(prefix[i])){
                return false;
            }
            ptr = ptr->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */