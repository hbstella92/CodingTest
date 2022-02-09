#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	unordered_map<uint64_t, string> hash_map;
	string prefix = "http://tinyurl.com";

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		hash<string> hash_fn;
		uint64_t key = hash_fn(longUrl);
		hash_map[key] = longUrl;

		return prefix + to_string(key);
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		string tmp = shortUrl.substr(prefix.size());
		uint64_t key = stoul(tmp);
		return hash_map[key];
	}
};

int main() {
	Solution sol;
	string ans = sol.decode(sol.encode("https://leetcode.com/problems/design-tinyurl"));

	cout << ans << endl; // https://leetcode.com/problems/design-tinyurl
	
	return 0;
}