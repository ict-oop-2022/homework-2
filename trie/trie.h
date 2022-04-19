#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>

struct leaves;

class trie_t {

    std::shared_ptr<leaves> root;

public:
    trie_t();
    trie_t(const trie_t &trie);

    ~trie_t();

    trie_t &operator=(const trie_t &trie);
    std::string operator[](size_t index) const;

    void insert(const std::string &s);
    void swap(trie_t &trie);
    void clear();

    bool erase(const std::string &s);
    bool find(const std::string &s) const;
    bool empty() const;

    size_t count_with_prefix(const std::string &prefix) const;
    size_t size() const;

    std::vector<std::string> to_vector() const;
};
