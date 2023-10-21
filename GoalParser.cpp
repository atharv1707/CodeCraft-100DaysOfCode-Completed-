class Solution {
public:
    string interpret(string command) {
        string interpreted = "";

        for (int i = 0; i < command.length();) {
            if (command[i] == 'G') {
                interpreted += 'G';
                i++;
            } else if (command[i] == '(' && command[i + 1] == ')') {
                interpreted += 'o';
                i += 2;
            } else if (command[i] == '(' && command[i + 1] == 'a' && command[i + 2] == 'l' && command[i + 3] == ')') {
                interpreted += "al";
                i += 4;
            } else {
                // If none of the rules match, just append the current character.
                interpreted += command[i];
                i++;
            }
        }
        return interpreted;
    }
};
