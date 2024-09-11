class StockPrice {
    int latestTime;
    unordered_map<int, int> timestampPriceMap;
    priority_queue<pair<int, int>> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    
public:
    StockPrice() {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) {
        latestTime = max(latestTime, timestamp);
        timestampPriceMap[timestamp] = price;
        minHeap.push({ price, timestamp });
        maxHeap.push({ price, timestamp });
    }
    
    int current() {
        return timestampPriceMap[latestTime];
    }
    
    int maximum() {
        pair<int, int> top = maxHeap.top();
        while (timestampPriceMap[top.second] != top.first) {
            maxHeap.pop();
            top = maxHeap.top();
        }
        
        return top.first;
    }
    
    int minimum() {
        pair<int, int> top = minHeap.top();
        while (timestampPriceMap[top.second] != top.first) {
            minHeap.pop();
            top = minHeap.top();
        }
        
        return top.first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */