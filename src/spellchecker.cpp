#include <fstream>
#include <iostream>
#include "spellchecker.h"

SpellChecker::SpellChecker(const std::string& dictionaryFilename, int size, int numHashes)
    : m_bloomFilter(size, numHashes)
{
    std::ifstream file(dictionaryFilename);
    if (!file) {
        std::cerr << "Error: Failed to open dictionary file: " << dictionaryFilename << std::endl;
        exit(1);
    }
    std::string word;
    while (file >> word) {
        m_bloomFilter.addWord(word);
    }
    file.close();
}

bool SpellChecker::isCorrectlySpelled(const std::string& word) const {
    return m_bloomFilter.isWord(word);
}
