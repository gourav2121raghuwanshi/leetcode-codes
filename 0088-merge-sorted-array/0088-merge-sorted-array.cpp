class Solution {
public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) 
    {
        int i = n - 1;  
        int j = m - 1;  
        int k = n + m - 1; 
       
        while (i >= 0 && j >= 0) {
            if (arr1[i] > arr2[j]) {
                arr1[k--] = arr1[i--];
            } else {
                arr1[k--] = arr2[j--];
            }
        }
       
        while (j >= 0) {
            arr1[k--] = arr2[j--];
        }
    }
};
