/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int n ;

    int findPeak( MountainArray &marr ){
        int low = 1, high = n-2 ;
        while ( low <= high ){
            int mid = low + (high-low)/2 ;
            int a = marr.get(mid-1) ;
            int b = marr.get(mid) ;
            int c = marr.get(mid+1) ;

            if ( b > c && b > a)
                return mid ;
            else if ( a < b && b < c)
                low = mid+1;
            else 
                high = mid-1;
        }
        return -1 ;
    }

    int increasingArray( int target, int low, int high, MountainArray &marr ){
        while( low <= high ){
            int mid = low+(high-low)/2;
            if ( marr.get(mid) == target )
                return mid ;
            else if ( marr.get(mid) < target )
                low = mid+1;
            else
                high = mid-1;
        }
        return -1 ;
    }

    int decreasingArray( int target, int low , int high, MountainArray &marr ){
        while( low <= high ){
            int mid = low + ( high-low)/2;
            if ( marr.get(mid) == target )
                return mid ;
            else if ( marr.get(mid) < target )
                high = mid-1;
            else
                low = mid+1 ;
        }
        return -1 ;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        n = mountainArr.length() ;
        int peak = findPeak( mountainArr ) ;

        if ( target == mountainArr.get(peak))
            return peak;

        int first = increasingArray( target, 0, peak-1, mountainArr ) ;
        if ( first != -1 ) 
            return first ;
        
        int second = decreasingArray( target, peak+1, n-1, mountainArr ) ;
        return second ;
    }
};
