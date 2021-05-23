// Minimum Operations to Make a Subsequence
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        //按target的顺序来，就是按索引升序
        //给arr里面对应的target里的值标记索引，然后求最长升序子序列
        unordered_map<int, int> hash;
        for(int i = 0; i < target.size(); ++i){
            hash[target[i]] = i;
        }
        //给arr中target元素标号
        vector<int> copy;
        for(auto& i : arr){
            if(hash.find(i) != hash.end()){
                copy.emplace_back(hash[i]);
            }
        }
        //最长升序子序列, nlogn
        vector<int> minList;
        for(auto& i : copy){
            if(minList.empty() || i > minList.back()){
                minList.emplace_back(i);
            }else{
                *lower_bound(minList.begin(), minList.end(), i) = i;
            }
        }
        return target.size() - minList.size();
    }
};
