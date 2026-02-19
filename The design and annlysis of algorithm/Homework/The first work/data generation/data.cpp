#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

class SortedWordGenerator {
private:
    std::random_device rd;
    std::mt19937 gen;
    std::vector<std::string> allPossibleWords;
    
    // 递归生成所有可能的升序单词
    void generateAllWords(std::string current, char lastChar, int maxLength) {
        if (current.length() > 0) {
            allPossibleWords.push_back(current);
        }
        
        if (current.length() < maxLength) {
            for (char c = lastChar + 1; c <= 'z'; ++c) {
                generateAllWords(current + c, c, maxLength);
            }
        }
    }
    
public:
    SortedWordGenerator() : gen(rd()) {
        generateAllWords("", 'a' - 1, 7);
    }
    
    std::vector<std::string> generateWords(int count) {
        std::vector<std::string> result;
        std::uniform_int_distribution<> dist(0, allPossibleWords.size() - 1);
        
        for (int i = 0; i < count; ++i) {
            result.push_back(allPossibleWords[dist(gen)]);
        }
        
        return result;
    }
};

void generate_sorted_words(const std::string& filename, int count) {
    SortedWordGenerator generator;
    auto words = generator.generateWords(count);
    
    std::ofstream file(filename);
    file << count << std::endl;
    
    for (const auto& word : words) {
        file << word << std::endl;
    }
    
    file.close();
}

int main() {
    // 生成不同数量的随机升序单词
    generate_sorted_words("words10.txt", 10);      // 10个单词
    generate_sorted_words("words1000.txt", 1000);    // 100个单词
    generate_sorted_words("words100000.txt", 100000);  // 1000个单词
    
    return 0;
}
