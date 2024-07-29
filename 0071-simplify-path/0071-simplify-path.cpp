class Solution {
public:
    string simplifyPath(string path) {
        vector<string> components;
        string component;
        istringstream stream(path);

        // Split the path by '/'
        while (getline(stream, component, '/')) {
            if (component == "" || component == ".") {
                continue;
            } else if (component == "..") {
                if (!components.empty()) {
                    components.pop_back();
                }
            } else {
                components.push_back(component);
            }
        }

        // Construct the simplified path
        string simplifiedPath = "/";
        for (size_t i = 0; i < components.size(); ++i) {
            simplifiedPath += components[i];
            if (i != components.size() - 1) {
                simplifiedPath += "/";
            }
        }

        return simplifiedPath;
    }
};