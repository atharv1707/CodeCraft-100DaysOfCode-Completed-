class Solution {
public:
    int firstHalf(int start, int mid) {
        int sum = 0;
        for (int i = start; i <= mid; ++i) {
            sum += i;
        }
        return sum;
    }

    int secondHalf(int mid, int end) {
        int sum = 0;
        for (int i = mid; i <= end; ++i) {
            sum += i;
        }
        return sum;
    }

    int pivotInteger(int n) {
        int start = 0;
        int end = n;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int sum1 = firstHalf(1, mid);
            int sum2 = secondHalf(mid, n);

            if (sum1 == sum2) {
                return mid;
            } else if (sum1 > sum2) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }
};


//approach  2  

class Solution {
public:
    int pivotInteger(int n) {

        if(n ==1 ){
            return 1;
        }


        int total_sum = (n*(n+1))/2;
        int prefix_sum = 0 ; 

        for(int i = 1; i < n ; i++){

            prefix_sum += i;
            if(prefix_sum == (total_sum+i)/2.0 ){
                return i;
            }

            if(prefix_sum > ceil((total_sum+i)/2.0) ){
                break;
            }

        }


        return -1;


        
    }
};
