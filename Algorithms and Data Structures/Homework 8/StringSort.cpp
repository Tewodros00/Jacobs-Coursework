#include <vector>
#include <string>


bool compareStringAt(std::string first_word, std::string second_word, 
        unsigned int index) {   
    if (index < first_word.length() and index < second_word.length())
        return first_word[index] > second_word[index];
    else
        return first_word.length() > second_word.length();
}

void stringInsertionSort(std::vector<std::string> &words, int index) {
    for (unsigned int i = 1; i < words.size(); i++) {
        std::string key = words[i];
        int j = i - 1;
        while (j >= 0 and compareStringAt(words[j], key, index)) {
            words[j + 1] = words[j];
            j--;
        }
        words[j + 1] = key;
    }
}

void StringSort(std::vector<std::string> &words) {  
    unsigned int k = words[0].length();
    for (unsigned int i = 1; i < words.size(); i++)
        if (words[i].length() > k)
            k = words[i].length();

    for (int index = k - 1; index >= 0; index--)
        stringInsertionSort(words, index);
}

