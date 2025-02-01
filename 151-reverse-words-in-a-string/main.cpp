class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        vector<string> words;
        string this_word = "";
        string sentence = "";

        // replace( s.begin(), s.end(), ' ', '0');

        for(int i=0; i<size; i++) {
            if(s[i] == ' ') {
                if(!this_word.empty()) {
                    cout<<this_word<<this_word.size()<<endl;
                    if(sentence.empty()) {
                        sentence = this_word;
                    } else {
                        sentence = this_word + " " + sentence;
                    }
                }
                this_word.clear();
                continue;
            };
            this_word += s[i];
        }

        if(!this_word.empty()) {
            if(sentence.empty()) {
                sentence = this_word;
            } else {
                sentence = this_word + " " + sentence;
            }
        }

        return sentence;
    }
};