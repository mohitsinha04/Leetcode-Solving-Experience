class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> map;
        vector<string> output;
        for(auto name : names) {
            string val = name; int i = map[val];

            // just like find in union find.(path compression)
            while(map[val] > 0) {
                val = name + "(" + to_string(i++) + ")";
                map[name] = i;
            }
            map[val]++;
            output.push_back(val);
        }
        return output;
    }
};


// ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]
// ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)",]

// i = 0;
// map["onepiece"] = 1;

// i = 1;
// map["onepiece(1)"] = 1;

// i = 2;
// map["onepiece(2)"] = 1;

// i = 3;
// map["onepiece(3)"] = 1;

// while (map["onepiece"] > 0) {
//     val = onepiece(1);
//     map[onepiece] = 1;
// }



