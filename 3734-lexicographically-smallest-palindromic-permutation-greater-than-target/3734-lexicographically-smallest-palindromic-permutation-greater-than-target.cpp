class Solution {
public:
    string result = "";
    bool f(int idx,string& curr,vector<int>& count,string& target,bool greater,char midch){
        if(idx == target.size()/2){
            string right = curr;
            string full = curr;
            reverse(right.begin(),right.end());

            if(midch != '$') full += midch;
            full += right;

            if(full > target){
                result = full;
                return true;
            } 
            else return false;
        }

        for(int c = 'a'; c<='z'; c++){
            if(count[c - 'a'] == 0) continue;

            if(greater == false && c<target[idx]) continue;

            curr += c;
            count[c - 'a']--;
            bool next_greater = greater || (c > target[idx]);

            if(f(idx+1,curr,count,target,next_greater,midch)== true) return true;

            count[c - 'a']++;
            curr.pop_back();

        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> count(26, 0);
        for (char ch : s) count[ch - 'a']++;

        int oddCount = 0;
        char mid = '$';
        for (int i = 0; i<26; i++) {
            if (count[i] % 2 != 0){
                oddCount++;
                mid = i + 'a';;
            }
            count[i] /= 2;
        }

        if (oddCount > (n % 2)) return "";

        string curr = "";
    
        f(0,curr,count,target,false,mid);

        return result;
    }
};