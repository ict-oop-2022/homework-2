#include "trie.h"
#include <queue>
#include <algorithm>
#include <cassert>
#include <utility>

trie_t::trie_t()
        : size_(0)
        , string_end_count(0)
{
}

trie_t::~trie_t()
{
}

trie_t::trie_t(const trie_t &other)
        : size_(other.size_)
        , string_end_count(other.string_end_count)
        , children(other.children)
{
}

trie_t& trie_t::operator=(const trie_t& other)
{
    size_ = other.size_;
    string_end_count = other.string_end_count;
    children = other.children;
    return *this;
}

void trie_t::insert(const std::string &str)
{
    trie_t *root = this;
    for (char ch: str) {
        ++root->size_;
        auto it = root->children.find(ch);
        if (it == root->children.end()) {
            it = root->children.insert({ch, trie_t()}).first;
        }
        root = &it->second;
    }
    ++root->size_;
    ++root->string_end_count;
}

void trie_t::clear()
{
    children.clear();
    size_ = 0;
    string_end_count = 0;
}

bool trie_t::erase(const std::string &str)
{
    std::vector<trie_t*> path;
    path.push_back(this);
    for (char ch: str) {
        auto it = path.back()->children.find(ch);
        if (it == path.back()->children.end()) {
            return false;
        }
        path.push_back(&it->second);
    }
    if (!path.back()->string_end_count) {
        return false;
    }
    --path.back()->string_end_count;
    --path.back()->size_;
    path.pop_back();
    for (; !path.empty(); path.pop_back()) {
        --path.back()->size_;
        char ch = str[path.size() - 1];
        auto it = path.back()->children.find(ch);
        if (it->second.size_ == 0) {
            path.back()->children.erase(it);
        }
    }
    return true;
}

bool trie_t::find(const std::string &str) const
{
    auto current_root = reach(str);
    return current_root && current_root->string_end_count > 0;
}

size_t trie_t::count_with_prefix(const std::string &prefix) const {
    auto current_root = reach(prefix);
    if (!current_root) {
        return 0;
    }
    return current_root->size_;
}

std::string trie_t::operator[](size_t index) const
{
    assert(index < size_);
    std::string res;
    const trie_t* root = this;
    while (root) {
        if (index < root->string_end_count) {
            break;
        }
        index -= root->string_end_count;
        auto temp = root;
        root = nullptr;
        for (const auto& [ch, next_root]: temp->children) {
            if (index < next_root.size_) {
                res += ch;
                root = &next_root;
                break;
            }
            index -= next_root.size_;
        }
    }

    return res;
}

std::vector<std::string> trie_t::to_vector() const
{
    // who need dfs when we can bfs
    std::queue<std::pair<const trie_t&, size_t>> qu;
    std::vector<std::string> res(size_);

    for (qu.emplace(*this, 0); !qu.empty(); qu.pop()) {
        auto [cur_root, start_id] = qu.front();
        start_id += cur_root.string_end_count;
        for (const auto& [ch, next_root]: cur_root.children) {
            qu.emplace(next_root, start_id);
            for (int i = 0; i < next_root.size_; ++i) {
                res[start_id++] += ch;
            }
        }
    }

    return res;
}

void trie_t::swap(trie_t &other) {
    std::swap(size_, other.size_);
    std::swap(string_end_count, other.string_end_count);
    std::swap(children, other.children);
}

const trie_t* trie_t::reach(const std::string& str) const
{
    const trie_t* root = this;
    for (char ch: str) {
        auto it = root->children.find(ch);
        if (it == root->children.end()) {
            return nullptr;
        }
        root = &it->second;
    }
    return root;
}