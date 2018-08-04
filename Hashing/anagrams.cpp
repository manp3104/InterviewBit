// https://www.interviewbit.com/problems/anagrams/

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    unordered_map<string, vector<int> > mp;
    vector<int> index;
    for(int j=0;j<A.size();j++) {
        string s1 = A[j];
        sort(s1.begin(), s1.end());
        if(mp.find(s1)==mp.end()) {
            for(int i=j;i<A.size();i++) {
                string s2 = A[i];
                sort(s2.begin(), s2.end());
                if(s1==s2)
                    index.push_back(i+1);
            }
            mp[s1] = index;
            index.clear();
        }
    }
    vector<vector<int> > ang_groups;
    for(auto a=mp.begin();a!=mp.end();a++) {
        ang_groups.push_back(a->second);
    }
    sort(ang_groups.begin(), ang_groups.end());
    return ang_groups;
}

