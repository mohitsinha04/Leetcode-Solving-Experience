class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        for (auto cp : cpdomains) {
            int count_i = cp.find(' ');
            int count = stoi(cp.substr(0, count_i));

            stringstream ss(cp.substr(count_i + 1));
            string item = "";
            vector<string> curr;
            while (getline(ss, item, '.')){
                curr.push_back(item);
            }
            string prev = "";
            for (int i = curr.size() - 1; i >= 0; i--) {
                string curr_domain = curr[i] + prev;
                if (i != 0) prev = "." + curr_domain;
                map[curr_domain] += count;
            }
        }

        vector<string> res;

        for (auto m : map) {
            string domain = m.first;
            int count = m.second;
            string cp = to_string(count) + " " + domain;
            res.push_back(cp);
        }
        return res;
    }
};


// ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]


// ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]