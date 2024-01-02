class Solution {
  public:
    // 1st appraoch by considering nearest 0 1 2
    int smallestSubstring(string s) {
        // Code here
        int l0 = -1, l1 = -1, l2 = -1;
        int ans = 1e6;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0') l0 = i;
            else if (s[i]=='1') l1=i;
            else l2 = i;
            
            if(l1==-1 || l2==-1 || l0==-1) continue;
            ans = min(ans, max(max(l0, l1), l2) - min(min(l0, l1), l2) + 1);
        }
        
        return (ans==1e6) ? -1: ans;
    }
    //2nd approach using unordered mp and 2 pointer
    int smallestSubstring(string s) {
        int s=3;
        int j=0;
        unordered_map<char,int>mp;
        int mn=INT_MAX;
        for(int i=0; i<S.size();i++){
            mp[S[i]]++;
            if(mp.size()==s){
                while(mp.size()==s){
                    mn=min(mn,i-j+1);
                    mp[S[j]]--;
                    if(mp[S[j]]==0){
                        mp.erase(S[j]);
                    }
                    j++;
                }
            }
        }
        if(mn==INT_MAX) return -1;
        return mn;
    }
    //3rd approach using 2 pointer and hashmap
    int smallestSubstring(string s) {
        int i=0,j=0,n= s.size(), ans = INT_MAX;
        vector<int> freq(3,0);
        while(j<n){
            freq[s[j]-'0']++;
            while(freq[0] && freq[1] && freq[2] && i<= j){
                ans = min(ans,j-i+1);
                freq[s[i]-'0']--;
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? -1: ans ;
    }
};