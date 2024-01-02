// Question
// We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:

// arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
// arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
// No integer is present in both arr1 and arr2.
// Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.

 

#define ll long long
class Solution {
 ll getGCD(int a,int b){
        if(b==0)return a;

        return getGCD(b,a%b);
    }
public:
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        ll ans=INT_MAX;
        ll low=1,high=INT_MAX;
        
        // Iterate with binary search to get Solution.
        while(low<=high){
            ll mid=(low+high)/2;
            // Remaining Numbers Divisible by div1 from total mid numbers
            ll total1=mid-mid/div1;
            // Remaining Numbers Divisible by div2 from total mid numbers
            ll total2=mid-mid/div2;

            // GCD of both div1 and div2
            ll gcd=getGCD(div1,div2);
            // Get the LCM of 2 numbers
            ll lcm=(ll)(((ll)div1)*((ll)div2))/gcd;

            // Remaining numbers that are not divisible by div1 and div2 from total mid numbers.
            ll temp=mid-mid/lcm;

            // If we have all satisfied then 
            // set the high value to left of mid and store the mid val as ans.
            if(total1>=cnt1 and total2>=cnt2 and temp>=cnt1+cnt2){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    //approach 2
    // int minimizeSet(int d1, int d2, int uC1, int uC2) {
    //     int ans= 0;
    //     int end1 = 0;
    //     int end2=0;
    //     int c1 = uC1;
    //     int c2= uC2;
    //     int temp = uC1;
    //     int a = 1;
    //     int b =1;
    //     while(c1){
    //         if(a%d1!=0){
    //             end1 = a;
    //             a++;
    //             c1--;
    //         }
    //         a++;
    //     }
    //     while(c2){
    //         b++;
    //         if(b%d2!=0 && b%d1==0 && temp){
    //             end2 = b;
    //             b++;
    //             c2--;
    //             temp--;
    //         }
    //         if(b%d2!=0 && temp ==0){
    //             end2 = b;
    //             b++;
    //             c2--;
    //         }
    //     }
    //     int maxi1 = max(end1,end2);
    //     a=1;
    //     b=1;
    //     end1 =0;
    //     end2 =0;
    //     temp = uC2;
    //     while(uC2){
    //         if(b%d2!=0){
    //             end2 = b;
    //             b++;
    //             uC2--;
    //         }
            
    //         b++;
    //     }
    //     while(uC1){
    //         a++;
    //         if(a%d1!=0 && a%d2==0 &&temp ){
    //             end1 = a;
    //             a++;
    //             uC1--;
    //             temp--;
    //         }
    //         if(a%d1!=0 && temp ==0){
    //             end1 = a;
    //             a++;
    //             uC1--;
    //         }
    //     }
    //     int maxi2 = max(end1,end2);
    //     ans = min(maxi1,maxi2);
    //     return ans;
    // }
};