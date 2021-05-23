class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ret = 0, n = s.size();

        for(int i = 0; i < n; ++i){
            if(i < n-1 && mp[s[i]] < mp[s[i+1]]){
                ret -= mp[s[i]];
            }else{
                ret += mp[s[i]];
            }
        }
        return ret;
    }
};

class Solution {
public:
    string intToRoman(int num) {
        int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string reps[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ret = "";
        for(int i = 0; i < 13; ++i)
            while(num >= values[i]){
                num -= values[i];
                ret += reps[i];
            }
        return ret;
    }
};
