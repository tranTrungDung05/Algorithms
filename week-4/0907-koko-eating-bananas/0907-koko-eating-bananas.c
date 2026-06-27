bool check(int *piles, int pilesSize, int h, int k) {
    long long hours = 0; 
    for(int i = 0; i < pilesSize; i++) {
        hours += (piles[i] + k - 1) / k;
    }
    return hours <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;
    int high = 0;
    for(int i = 0; i < pilesSize; i++) {
        if(piles[i] > high) high = piles[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (mid == 0) { low = 1; continue; }

        if (check(piles, pilesSize, h, mid)) {
            ans = mid;     
            high = mid - 1;
        } else {
            low = mid + 1; 
        }
    }

    return ans;
}