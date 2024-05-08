class Solution {
public:
    string toGoatLatin(string sentence) {

        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        stringstream check1(sentence);
        vector<string> tokens;
        string intermediate;

        // Tokenize the sentence
        while(getline(check1, intermediate, ' ')) {
            tokens.push_back(intermediate);
        }

        string result = "";
        int count = 1;

        for(string& word : tokens){
            if(vowels.find(word[0]) != vowels.end()){
                word += "ma";
            }
            else{
                word = word.substr(1) + word[0] + "ma";
            }

            word.append(count, 'a');
            count++;


            result += word + " ";
        }

        result.pop_back();

        return result;
    }
};
