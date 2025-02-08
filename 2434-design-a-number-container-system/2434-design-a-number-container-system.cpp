class NumberContainers {
public:
    unordered_map<int, int> idx_number;
    unordered_map<int, set<int>> number_idx;
    NumberContainers() {}

    void change(int index, int number) {
        if (idx_number.count(index)) {
            int itsNum = idx_number[index];
            number_idx[itsNum].erase(index);
        }
        idx_number[index] = number;
        number_idx[number].insert(index);
    }

    int find(int number) {
        if (number_idx.count(number) && !number_idx[number].empty())
            return *number_idx[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */