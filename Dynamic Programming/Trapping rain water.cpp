class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int la[n],ra[n],num=0;
        la[0]=height[0];
        for(int i=1;i<n;i++){
            la[i]=max(la[i-1],height[i]);
        }
        ra[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            ra[i]=max(ra[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            num+=min(ra[i],la[i])-height[i];
        }
        return num;
    }
};