#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <functional> // pour std::hash
using namespace std;

// =======================
// Fonction de hachage simple (simulation SHA256)
// =======================
string simpleHash(const string &input) {
    hash<string> hasher;
    size_t hashValue = hasher(input);
    stringstream ss;
    ss << hex << setw(16) << setfill('0') << hashValue;
    return ss.str();
}

// =======================
// Classe Block
// =======================
class Block {
public:
    int index;
    string data;
    string previousHash;
    string hash;
    long nonce;
    time_t timestamp;

    Block(int idx, string d, string prevHash)
        : index(idx), data(d), previousHash(prevHash), nonce(0) {
        timestamp = time(nullptr);
        hash = calculateHash();
    }

    string calculateHash() const {
        stringstream ss;
        ss << index << timestamp << data << previousHash << nonce;
        return simpleHash(ss.str());
    }

    void mineBlock(int difficulty) {
        string target(difficulty, '0'); // ex: "000" pour difficulté 3
        auto start = chrono::high_resolution_clock::now();

        while (hash.substr(0, difficulty) != target) {
            nonce++;
            hash = calculateHash();
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;

        cout << "✅ Bloc " << index << " miné avec succès !" << endl;
        cout << "Hash trouvé : " << hash << endl;
        cout << "Difficulté : " << difficulty << " | Nonce : " << nonce 
             << " | Temps : " << elapsed.count() << " sec\n" << endl;
    }
};

// =======================
// Classe Blockchain
// =======================
class Blockchain {
public:
    vector<Block> chain;

    Blockchain() {
        chain.push_back(createGenesisBlock());
    }

    Block createGenesisBlock() {
        return Block(0, "Bloc Genesis", "0");
    }

    Block getLatestBlock() {
        return chain.back();
    }

    void addBlock(string data, int difficulty) {
        Block newBlock(chain.size(), data, getLatestBlock().hash);
        cout << "\n⛏️  Minage du bloc " << newBlock.index << "..." << endl;
        newBlock.mineBlock(difficulty);
        chain.push_back(newBlock);
    }
};

// =======================
// Fonction principale
// =======================
int main() {
    Blockchain myBlockchain;

    vector<int> difficulties = {2, 3, 4}; // testons plusieurs niveaux de difficulté
    int i = 1;

    for (int diff : difficulties) {
        myBlockchain.addBlock("Transaction #" + to_string(i++), diff);
    }

    cout << "\n===== CHAÎNE FINALE =====" << endl;
    for (auto &b : myBlockchain.chain) {
        cout << "Bloc " << b.index 
             << " | Hash : " << b.hash 
             << " | Prev : " << b.previousHash.substr(0,8) << "..." << endl;
    }

    return 0;
}
