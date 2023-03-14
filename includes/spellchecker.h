#ifndef SPELLCHECKER_SPELL_CHECKER_H
#define SPELLCHECKER_SPELL_CHECKER_H

#include <string>
#include "bloom_filter.h"

class SpellChecker {
public:
    SpellChecker(const std::string& dictionaryFilename, int size, int numHashes);
    bool isCorrectlySpelled(const std::string& word) const;
private:
    BloomFilter m_bloomFilter;
};

#endif //SPELLCHECKER_SPELL_CHECKER_H