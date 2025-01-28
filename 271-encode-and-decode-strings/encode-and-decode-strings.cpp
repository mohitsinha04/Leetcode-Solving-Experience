class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";

        for (auto s : strs) {
            for (char c : s) {
                if (c == '/') {
                    encoded += "//";
                } else {
                    encoded += c;
                }
            }
            encoded += "/:";
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        string curr = "";

        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 1 && s[i] == '/' && s[i+1] == ':') {
                decoded.push_back(curr);
                curr = "";
                i++;
            } else if (i < s.size() - 1 && s[i] == '/' && s[i] == '/') {
                curr += '/';
                i++;
            } else {
                curr += s[i];
            }
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));