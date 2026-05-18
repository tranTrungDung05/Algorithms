void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1; //number of elements of nums1
    int j = n - 1; //number of elements of nums2
    int k = m + n - 1; //number of nums1

    if(m == 0){
        for(int x = 0; x < n; x++){
            nums1[x] = nums2[x];
        }
        return;
    }
     
    while(i >= 0 && j >= 0){
        if(nums1[i] < nums2[j]){
            nums1[k] = nums2[j];
            j--;
        }else{
            nums1[k] = nums1[i];
            i--;
        }
        k--;
    }

    while(j >= 0){
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}


