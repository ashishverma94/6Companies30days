class Solution {
    void conquer( vector<int> &arr , int start , int mid , int end ){
        int mergearr[end-start+1] ;
        int indexone = start , indextwo = mid+1 , indexmerge = 0 ;
        
        while( indexone <= mid && indextwo <= end ){
            if ( arr[indexone] <= arr[indextwo])
                mergearr[indexmerge++] = arr[indexone++] ;
            else
                mergearr[indexmerge++] = arr[indextwo++] ;
        }
        while( indexone <= mid )
            mergearr[indexmerge++] = arr[indexone++] ;
        while( indextwo <= end )
            mergearr[indexmerge++] = arr[indextwo++] ;
        
        indexmerge = 0 ;
        for ( int i = start ; i <= end ; i ++ )
            arr[i] = mergearr[indexmerge++] ;
    }

    void divide(vector<int> &arr , int start , int end ){
        if ( end <= start )
            return ;
        int mid = start + ( end - start )/2 ;
        divide(arr , start , mid ) ;
        divide(arr , mid+1 , end ) ;
        conquer(arr , start , mid , end ) ;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int low = 0, high = nums.size() ;
        divide( nums, low, high-1 ) ;
        return nums ;
    }
};
