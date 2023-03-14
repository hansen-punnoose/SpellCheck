#include "bloom_filter.h"
#include <functional>


/**
 * Initializes a Bloom filter with a given size and number of hash functions.
 * @param size The size of the Bloom filter in bits.
 * @param numHashes The number of hash functions to use.
 */

BloomFilter::BloomFilter(int size, int numHashes)
    : m_size(size), m_numHashes(numHashes), m_bits(size), m_hasher(std::hash<std::string>())
{
    m_hashes.reserve(numHashes);
}

/**
 * Adds a word to the Bloom filter by computing hash values for the word and setting the corresponding bits in the filter.
 * @param word The word to add to the Bloom filter.
 */

void BloomFilter::addWord(std::string word)
{
    for (int i = 0; i < m_numHashes; ++i) {
        // Compute hash value for the word using the hash function.
        m_hashes[i] = m_hasher(word + std::to_string(i)) % m_size;
        // Set the corresponding bit in the filter to true.
        m_bits[m_hashes[i]] = true;
    }
}

/**
 * Checks if a word is likely to be in the Bloom filter by computing hash values for the word and checking if the corresponding bits in the filter are all set to true.
 * @param word The word to check.
 * @return True if the word is likely to be in the Bloom filter, false otherwise.
 */

bool BloomFilter::isWord(std::string word) const
{
    for (int i = 0; i < m_numHashes; ++i) {
        // Compute hash value for the word using the hash function.
        if (!m_bits[m_hasher(word + std::to_string(i)) % m_size]) {
            // If the corresponding bit is not set to true, the word is not in the filter.
            return false;
        }
    }
    // If all corresponding bits are set to true, the word is likely in the filter.
    return true;
}
