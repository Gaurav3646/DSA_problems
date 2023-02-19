class Solution {
public:
 int printWords(string str)
{
    // word variable to store word
     reverse(str.begin(), str.end());
    string word;
 
    // making a string stream
    stringstream iss(str);
 
    // Read and print each word.
    while (iss >> word)
        return word.size();
     return 0;
}
    int lengthOfLastWord(string s) {
        
        return printWords(s);
    }
};