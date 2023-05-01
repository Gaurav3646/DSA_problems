class Solution {
public:
    double average(vector<int>& salary) {
        long long maxi = 999;
        long long mini = 1e6+1;
        double sum = 0;
        for(auto &sal: salary){
            if(maxi<sal) maxi = sal;
            if(mini>sal) mini = sal;
            sum += sal;
        }
        return (sum-mini-maxi)/(salary.size()-2);
    }
};