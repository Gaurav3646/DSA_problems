class SummaryRanges {
    unordered_map<int,int> mp{};
    vector<vector<int>> intervals;

public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        // If value already added to an interval return.
        if(mp.find(value) != mp.end()) 
            return;

        ++mp[value];

        // If new disjoint interval add {value, value} in the correct place
        if(mp.find(value-1) == mp.end() &&
             mp.find(value+1) == mp.end())
        {
            // TODO Binary search would be better
            int j = 0;
            for(auto& i: intervals)
            {
                if(value < i[0])
                    break;
                ++j;
            }
            intervals.insert(intervals.begin()+j, {value,value});
            return;
        }

        // Join to existing interval and keep track whether
        // the beginning or end of an interval was changed.
        bool a = false;
        bool b = false;
        for(auto& i: intervals)
        {
            if(i[0] == value + 1)
            {
                i[0] = value;
                a = true;
            }
            if(i[1] == value - 1)
            {
                i[1] = value;
                b = true;
            }
        }

        // Merge only if needed.
        if(a && mp.find(value-1) != mp.end() ||
            b && mp.find(value+1) != mp.end())
        {
            for(int i = 0; i<intervals.size()-1; ++i)
            {
                if(intervals[i][1] == intervals[i+1][0])
                {
                    intervals[i][1] = intervals[i+1][1];
                    intervals.erase(intervals.begin() + i + 1);
                    break;
                }
            }
        }

    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};
