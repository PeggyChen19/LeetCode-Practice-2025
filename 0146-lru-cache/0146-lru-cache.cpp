class CacheNode {
public:
	int key, val;
	CacheNode* prev;
    CacheNode* next;
	CacheNode(int key, int val, CacheNode* prev): key(key), val(val), prev(prev), next(NULL) {}
};

class LRUCache { // linked list
public:
	int capacity;
	unordered_map<int, CacheNode*> cache;
	CacheNode* oldest;
	CacheNode* newest;

	LRUCache(int capacity): capacity(capacity), oldest(NULL), newest(NULL) {}
	
	int get(int key) {
		if(cache.count(key)) {
			updateFrequency(cache[key]);
			return cache[key]->val;
		} else {
			return -1;
		}
	}
	
	void put(int key, int value) {
		if (cache.count(key)) { // existed -> update
			cache[key]->val = value;
			updateFrequency(cache[key]);
		} else { // not existed -> create new one
			CacheNode* new_cache = new CacheNode(key, value, newest);
            cache[key] = new_cache;
			if (newest == NULL) { // the first cache
				oldest = new_cache;
			} else {
                newest->next = new_cache;
            }
            newest = new_cache;
			if (cache.size() > capacity) {
				removeLRU();
			}
		}
        
	}

private:
	void updateFrequency(CacheNode* node) {
		if(node != newest) {
            if (node->prev) {
                node->prev->next = node->next;
            } else {
                oldest = node->next;
            }
            if (node->next) {
                node->next->prev = node->prev;
            }
            node->next = NULL;
			node->prev = newest;
			newest->next = node;
			newest = node;
		} 
	}
	void removeLRU() {
        if (oldest == NULL) {
            return;
        }
		CacheNode* to_remove = oldest;
		oldest = oldest->next;
		if (oldest) {
            oldest->prev = NULL;
        }
		cache.erase(to_remove->key);
		delete to_remove;
		to_remove = NULL;
	}
};

/**
get key : value in avg O(1) time complexity -> unordered_map
we need to reorder the sequence easily -> linked list
Two end points: oldest & newest nodes
Pointers: prev & next

* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/