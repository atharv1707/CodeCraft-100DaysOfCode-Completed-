
//RULES : 
*// " . " ==> Continue;
//" .. " ==> Remove the before directory; -> pop()
// " // " ==> make it into "/" -> continue


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res;

        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/') {
                continue;
            }

            string temp;

            while (i < path.length() && path[i] != '/') {
                temp += path[i]; // temp stores the  content between the slashes
                i++; // Move forward, to the next char
            }
            

            if (temp == ".") {
                continue;
            } else if (temp == "..") {
                if (!st.empty()) {
                    st.pop(); // Remove the top element, basically return to the parent directory
                }
            } else {
                st.push(temp); // Push valid directory/file names onto the stack
            }
        }


        //now we start making the result string
        while (!st.empty()) {
            res = "/" + st.top() + res; // Build the result by appending directories/files from the stack
            st.pop();  // Pop the top element after it is appended into the res
        }

        if (res.length() == 0) {
            return "/"; // Root directory
        }

        return res;
    }
};
