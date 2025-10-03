class RandomizedSet {
private:
    unordered_map<int, int> data_mapping; // value: index
    vector<int> data_vector;              // index: value
public:
    RandomizedSet() {
        srand(time(NULL));
    }

    bool insert(int value) {
        if (data_mapping.count(value)) {
            return false;
        } else {
            data_mapping[value] = data_vector.size();
            data_vector.push_back(value);
            return true;
        }
    }

    bool remove(int value) {
        if (data_mapping.count(value)) {
            int index = data_mapping[value];
            // swap
            data_mapping[data_vector.back()] = index;
            swap(data_vector[index], data_vector.back());
            // remove
            data_mapping.erase(value);
            data_vector.pop_back();
            return true;
        } else { 
            return false;
        }
    }

    int getRandom() {
        if (data_vector.empty()) {
            return -1;
        }
        int randomInd = rand() % data_vector.size(); // output range: 0 ~ size - 1
        return data_vector[randomInd];
    }
};
