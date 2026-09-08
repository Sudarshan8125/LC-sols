class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int cnt = 0,ans = 0;
        for(int i = 0; i<n; i++){
            if(cnt == -1){
                ans++;
                cnt = 0;
            }
            if(s[i] == '('){
                cnt++;
            }else{
                cnt--;
            }
        }
        
        return (abs(cnt)+ans);
    }
};