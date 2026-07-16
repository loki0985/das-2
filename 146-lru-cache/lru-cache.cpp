class LRUCache {
public:
    int cap;
    list<pair<int, int>> cache; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        } 
        else if (cache.size() == cap) {
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};