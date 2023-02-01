class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
          const int n = plantTime.size();
        int result = 0, all_plant_time = 0;
        std::vector<std::pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i].first = plantTime[i];
            arr[i].second = growTime[i];
        }
        std::sort(arr.begin(), arr.end(), [&](std::pair<int, int>& a, std::pair<int, int>& b) {
            return a.second > b.second;
        });
        for (const std::pair<int, int>& a : arr) {
            all_plant_time += a.first;
            result = std::max(result, all_plant_time + a.second);
        }
        return result;
    }
};