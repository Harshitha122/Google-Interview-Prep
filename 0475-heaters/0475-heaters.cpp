
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // Sort the houses and heaters
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int maxRadius = 0;

        // For each house, find the closest heater
        for (int house : houses) {
            int heaterRadius = findClosestHeater(house, heaters);
            maxRadius = max(maxRadius, heaterRadius);
        }

        return maxRadius;
    }

private:
    int findClosestHeater(int house, const vector<int>& heaters) {
        // Binary search to find the closest heater to the house
        int left = 0, right = heaters.size() - 1;
        
        // Binary search to find the position in heaters array
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (heaters[mid] < house) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Once binary search is done, we have two possible closest heaters
        // Heaters[left] is either the closest heater or the heater after the closest one
        int dist1 = abs(heaters[left] - house);
        int dist2 = (left > 0) ? abs(heaters[left - 1] - house) : INT_MAX;

        // Return the minimum of the two distances
        return min(dist1, dist2);
    }
};
