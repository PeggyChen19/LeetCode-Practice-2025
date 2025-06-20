class RandomizedSet {
public:
    vector<int> valVec; //ind: val
    unordered_map<int, int> valMap; //val: ind
    RandomizedSet() {
        srand(time(NULL));
    }

    bool insert(int val) {
        if (valMap.count(val)) {
            return false;
        } else {
            valMap[val] = valVec.size();
            valVec.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if (valMap.count(val)) {
            int removedInd = valMap[val];
            int lastVal = valVec.back();
            valVec[removedInd] = lastVal; // update indMap
            valVec.pop_back();
            valMap[lastVal] = removedInd; // update valMap
            valMap.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        return valVec[rand() % valVec.size()];
    }
};
/**
O(1): insert & remove & getRandom
vector<int>: index, val
unordered_map<int, int>: val, index
create a variable size to record the map size
insert: size++
remove: size--, move the last element to the removed index
getRandom: randomly pick an index from 0~size-1
*/