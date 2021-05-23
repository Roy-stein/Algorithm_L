// Minimum Operations to Make a Subsequence
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        //��target��˳���������ǰ���������
        //��arr�����Ӧ��target���ֵ���������Ȼ���������������
        unordered_map<int, int> hash;
        for(int i = 0; i < target.size(); ++i){
            hash[target[i]] = i;
        }
        //��arr��targetԪ�ر��
        vector<int> copy;
        for(auto& i : arr){
            if(hash.find(i) != hash.end()){
                copy.emplace_back(hash[i]);
            }
        }
        //�����������, nlogn
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
