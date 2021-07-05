// Leetcode : 401. Binary Watch

class Solution {
public:
    int ht[4] = {1, 2, 4, 8};
    int mt[6] = {1, 2, 4, 8, 16, 32};
    vector<string> ret;
    unordered_set<string> st;
    bool visH[4], visM[6];
    void dfs(int turnedOn, int cur, int hh, int mm){
        if(cur == turnedOn){
            string q;
            if(mm < 10)
                q += "0";
            q += to_string(mm);
            string s = to_string(hh) +":" + q;
            if(st.count(s) == 0){
                ret.push_back(s);
                st.insert(s);
            }
            return ;
        }
        for(int j = 0; j < 6; ++j){
            if(!visM[j] && mm + mt[j] < 60){
                visM[j] = 1;
                dfs(turnedOn, cur+1, hh, mm+mt[j]);
                visM[j] = 0;
            }
        }
        for(int i = 0; i < 4; ++i){
            if(!visH[i] && hh + ht[i] < 12){
                visH[i] = 1;
                dfs(turnedOn, cur+1, hh+ht[i], mm);
                visH[i] = 0;
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn >= 9)
            return {};
        dfs(turnedOn, 0, 0, 0);
        sort(ret.begin(), ret.end());
        return ret;
    }
};

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ret;
        for(int i = 0; i < 12; ++i)
            for(int j = 0; j < 60; ++j){
                if(__builtin_popcount(i) + __builtin_popcount(j) == turnedOn){
                    string s = to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j);
                    ret.push_back(s);
                }
            }
        return ret;
    }
};

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ret;
        for(int i = 0; i < 1024; ++i){
            int h = i >> 6, m = i & 63; //h取高4位,m取低6位
            if(h < 12 && m < 60)
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn){
                    string s = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
                    ret.push_back(s);
                }
        }
        return ret;
    }
};
