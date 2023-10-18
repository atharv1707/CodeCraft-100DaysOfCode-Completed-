#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isTrue(int arr[], int N, int M, int mid) 
    {
        int studentCount = 1;
        int pageSum = 0;
        
        for(int i = 0; i < N; i++){
            if(pageSum + arr[i] <= mid){
                pageSum += arr[i];
            }
            else{
                studentCount++;
                if(studentCount > M || arr[i] > mid){
                    return false;
                }
                pageSum = 0 ; 
                pageSum = arr[i];
            }
        }
        
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        int ans = -1;
        
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum += A[i];
        }
        
        int s = 0; 
        int e = sum;
        
        if(M>N){
            return -1;
         }  
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(isTrue(A, N, M, mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        
        return ans;
    }
};


