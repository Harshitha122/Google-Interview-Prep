class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=0;
        while(i<n){
            if(i<n-1 && arr[i]==arr[i+1]){
                while(i<n-1 && arr[i]==arr[i+1]){
                    i++;
                }
            }
            arr[j++]=arr[i];
            i++;
        }
        int x=n-(j);
        while(x--){
            arr.pop_back();
        }

        // for(int k=j+1;j<n;j++){
        //     arr[k]=0;
        // }
        return j;
    }
};