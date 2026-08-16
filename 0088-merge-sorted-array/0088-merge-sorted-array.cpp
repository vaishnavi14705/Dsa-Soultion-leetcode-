class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>mergeArr(m+n);
       
       int k=0;
        for(int i=0;i<m;i++){
            mergeArr[k++]=nums1[i];
        }
            for(int j=0;j<n;j++){
               mergeArr[k++] = nums2[j];  
             
                
            }

        sort(mergeArr.begin(),mergeArr.end());
           for (int x = 0; x < m + n; x++) {
            nums1[x] = mergeArr[x];
        }
       
    }
};