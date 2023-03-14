#ifndef SPELLCHECKER_BLOOM_FILTER_H
#define SPELLCHECKER_BLOOM_FILTER_H

#include <vector> 
#include <string>


class BloomFilter {
public:
    BloomFilter(int size, int numHashes);
    void addWord(std::string word);
    bool isWord(std::string word) const;
private:
    std::vector<bool> m_bits;
    int m_size;
    int m_numHashes;
    std::vector<int> m_hashes;
    std::hash<std::string> m_hasher;
};

#endif // SPELLCHECKER_BLOOM_FILTER_H
