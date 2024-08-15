class Solution {
public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) 
    {
    int left = n - 1;
    int right = 0;
   
  
    while (left >= 0 && right < m) 
    
    {
        if (arr1[left] > arr2[right] ) 
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else 
        {
            break;
        }
    }

 
   
        sort(arr1.begin(),arr1.begin()+n);
        sort(arr2.begin(),arr2.end());

        for(int i=n; i<m+n; i++)
        {
            arr1[i] = arr2[i-n];
        }
    }
};