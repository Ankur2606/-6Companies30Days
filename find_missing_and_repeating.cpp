// Using Unordered Set and Xor :

// Time Complexity : O(n)
// Auxilary Space : O(n)

vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> ans;
        int x =1 ;
        int a =0;
        int b = 0;
        unordered_set<int> st;
        for(int i = 0 ; i<n ; i++){
            a ^= x^arr[i]; 
            b ^= arr[i];
            x++;//
            st.insert(arr[i]);
        }
        for(auto it : st){
            b ^= it;
        }
        ans.push_back(b);
        ans.push_back(a^b);
        return ans;
    }

// By utilizing hashing :

vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int>v(n,0);
        int a=0,b=0;
        for(int i=0;i<n;i++){
            v[arr[i]-1]++;
        }
        for(int i=0;i<n;i++){
            if(v[i]==0){
                a=i+1;
            }
            if(v[i]==2){
                b=i+1;
            }
        }
        return {b,a};
    }