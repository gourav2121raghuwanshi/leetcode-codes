class NumberContainers {
public:
    unordered_map<int, int> idx_number;  // Maps index -> number
    unordered_map<int, set<int>> number_idx;  // Maps number -> set of indices
    
    NumberContainers() {}

    void change(int index, int number) {
        auto it = idx_number.find(index);
        if (it != idx_number.end()) {  // If index already exists, remove it from previous number's set
            int oldNumber = it->second;
            number_idx[oldNumber].erase(index);
            if (number_idx[oldNumber].empty()) {
                number_idx.erase(oldNumber);
            }
        }
        idx_number[index] = number;  // Update the mapping
        number_idx[number].emplace(index);
    }

    int find(int number) {
        auto it = number_idx.find(number);
        return (it != number_idx.end() && !it->second.empty()) ? *it->second.begin() : -1;
    }
};
