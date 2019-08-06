/*
  535. Encode and Decode TinyURL

  TinyURL is a URL shortening service where you enter a URL such as
  https://leetcode.com/problems/design-tinyurl and it returns a short
  URL such as http://tinyurl.com/4e9iAk.

  Design the encode and decode methods for the TinyURL service. There is
  no restriction on how your encode/decode algorithm should work. You just
  need to ensure that a URL can be encoded to a tiny URL and the tiny URL
  can be decoded to the original URL.
*/

class Solution {
  hash<string> t;
  unordered_map<string, string> tinyToLongUrl; 
public:
  // Encodes a URL to a shortened URL.
  string encode( string longUrl ) {
    string key = to_string( t(longUrl) );
    tinyToLongUrl[ key ] = longUrl;
    return key;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    return tinyToLongUrl[ shortUrl ];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
