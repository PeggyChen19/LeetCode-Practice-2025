class Solution {
public:
    string simplifyPath(string path) {
        string result = "";
        vector<string> names;
        int i = 0, size = path.size();
        while (i < size) {
            // skip multiple '/'
            while (i < size && path[i] == '/') {
                i++;
            }
            // find the dir or file name
            string name = "";
            while (i < size && path[i] != '/') {
                name += path[i];
                i++;
            }
            if (name == "..") {
                if (!names.empty()) names.pop_back();
            } else if (name != "" && name != ".") {
                names.push_back(name);
            }
        }
        if (names.empty()) return "/";
        for (string& name : names) {
            result += "/" + name;
        }
        return result;
    }
};
/*
. -> current dir
.. -> previous dir
Multiple / -> treated as single /
Others -> valid dir name

Return:
Start with single /
Not end with / unless it's the root dir
Only single /
Not include . or ..

E.g.
/a/b//../c/ -> /a/c

1. use vector to record all dir or file name
2. remove . and redundant /
3. combine all dir and file names with single /
*/