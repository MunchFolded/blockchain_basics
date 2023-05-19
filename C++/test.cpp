#include <iostream>
#include <string>
#include <ctime>
#include <openssl/sha.h>

using namespace std;

class Block {
    public:
    int index; // Position of the block in the chain
    string data; // stores the info we want to record
    time_t timestamp; // time of creation
    string previousHash // hash of previousHas
    string hash; // hash of current block

    //Define a Block class with attributes such as index, data, timestamp, previousHash, and hash.

    Block(int idx, const string& d, const string$ prevHash)
        : index(idx), data(d), previousHash(prevHash) {
            timestamp = time(nullptr);
            hash = calculateHash();
        }
    // calculateHash() method computes the hash value of the block. SHA-256, ETHASH

    string calculateHash() {
        string blockData = to_string(index) + data + to_string(timestamp) + previousHash;
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(reinterpret_cast<const unsigned char*>(blockData.c_str()), blockData.length(), hash);

        string hashString;
        for (unsigned char byte : hash) {
            hashString = hashString + byte;
        }

        return hashString;
    }
};

int main() {
    // Create the genesis block
    BLock genesisBlock(0, "Genesis Block", "0");
    // Create a new block
    Block newBlock(1, "Some Data", genesisBlock.hash);
    // Print the hash of the new block
    cout << "New Block Hash: " << newBlock.hash << endl;
    
    return 0;
}
