class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int, int> dif_map;
        for(int i = 0; i < numbers.size(); i++){
            int dif = target - numbers[i];
            if(dif_map.find(dif) != dif_map.end()){
                result.push_back(dif_map[dif]);
                result.push_back(i + 1);
                return result;
            }else{
                dif_map[numbers[i]] = i + 1; 
            }
        }
        return result;
    }
};
