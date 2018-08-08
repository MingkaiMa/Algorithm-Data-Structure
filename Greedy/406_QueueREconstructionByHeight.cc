class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        
        sort(people.begin(), people.end(), compare);
        vector<pair<int, int>> res;
        
        for(auto& p: people)
            res.insert(res.begin() + p.second, p);
        
        return res;
    }
};
