#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;        
        unordered_map<char, int>chars_um;
        for (char i : chars)
            chars_um[i]++;
        for (string i : words) {
            bool flag = true;
            unordered_map<char, int>temp_um;
            for (char j : i)
                temp_um[j]++;            
            for (auto k = temp_um.begin(); k != temp_um.end(); k++) 
                if (k->second > chars_um[k->first]) { flag = false; break; }
            if (flag == false)continue;
            else ans += i.size();
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<string>words = { "cat", "bt", "hat", "tree" };
    string chars = "atach";
    cout << sol.countCharacters(words, chars);
    return 0;
}