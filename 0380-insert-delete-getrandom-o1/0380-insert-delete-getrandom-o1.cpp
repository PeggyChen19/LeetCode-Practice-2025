class RandomizedSet {
public:
    unordered_map<int, int> indMap; //ind: val
    unordered_map<int, int> valMap; //val: ind
    int total;
    RandomizedSet() {
        total = 0;
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if (valMap.count(val)) {
            return false;
        } else {
            indMap[total] = val;
            valMap[val] = total;
            total++;
            return true;
        }
    }
    
    bool remove(int val) {
        if (valMap.count(val)) {
            int removedInd = valMap[val];
            int lastVal = indMap[total - 1];
            indMap[removedInd] = lastVal; // update indMap
            indMap.erase(total - 1);
            valMap[lastVal] = removedInd; // update valMap
            valMap.erase(val);
            total--;
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        int randomInd = rand() % total;
        return indMap[randomInd];
    }
};
/**
O(1): insert & remove & getRandom
unordered_map<int, int>: index, val
unordered_map<int, int>: val, index
create a variable total to record the map size
insert: total++
remove: total--, move the last element to the removed index
getRandom: randomly pick an index from 0~total-1
*/