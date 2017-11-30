#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

vector<string> words;
map<string, int> cnt;

//make words to be standarded
string repr(const string& s){
	string ans = s;
	for (int i = 0; i < ans.length(); i++) ans[i] = tolower(ans[i]);
	
	sort(ans.begin(), ans.end());
	
	return ans;
}

int main(int argc, char** argv) {
	int n = 0;
	string s;
	
	//freopen("input.txt", "r", stdin); // for debug input 
	
	while (cin >> s && s[0] != '#'){
		words.push_back(s);
		cnt[repr(s)]++;
	}
	
	vector<string> ans;
	for (int i = 0; i < words.size(); i++) if (cnt[repr(words[i])] == 1) ans.push_back(words[i]);
	sort(ans.begin(), ans.end());
	
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
	
	return 0;
}
