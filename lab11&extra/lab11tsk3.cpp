#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class radixstringsorter {
public:
    void ascendingsort(vector<string>& words) {
        int max_len = maxlengthget(words);
        for (int pos = max_len - 1; pos >= 0; pos--) {
            counting_sort(words, pos, true);
        }
    }

    void descendingsort(vector<string>& words) {
        int max_len = maxlengthget(words);
        for (int pos = max_len - 1; pos >= 0; pos--) {
            counting_sort(words, pos, false);
        }
    }

    void charsort(vector<string>& words, int position, bool ascending = true) {
        counting_sort(words, position, ascending);
    }

private:
    int maxlengthget(const vector<string>& words) {
        int max_len = 0;
        for (const string& word : words) {
            max_len = max(max_len, (int)word.size());
        }
        return max_len;
    }

    void counting_sort(vector<string>& words, int pos, bool ascending) {
        int range = 256;
        vector<vector<string>> buckets(range);

        for (const string& word : words) {
            char ch = pos < word.size() ? word[pos] : 0;
            buckets[(unsigned char)ch].push_back(word);
        }

        words.clear();
        if (ascending) {
            for (int i = 0; i < range; i++) {
                for (const string& w : buckets[i])
                    words.push_back(w);
            }
        }
        else {
            for (int i = range - 1; i >= 0; i--) {
                for (const string& w : buckets[i])
                    words.push_back(w);
            }
        }
    }
};
