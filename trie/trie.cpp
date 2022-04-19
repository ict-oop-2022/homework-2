#include "trie.h"


struct leaves {
    std::shared_ptr<leaves> children[26];
    int list;
    int quantity;

    leaves() {
        list = 0;
        quantity = 0;
    }
};

static void search_for_operator(const std::shared_ptr<leaves>& v_this, const std::shared_ptr<leaves>& v_other) {
    v_this->list = v_other->list;
    v_this->quantity = v_other->quantity;

    for (int iter = 0; iter < 26; ++iter) {
        if (v_other->children[iter] != nullptr) {
            v_this->children[iter].reset(new leaves());
            search_for_operator(v_this->children[iter], v_other->children[iter]);
        }
    }
}

void search_size_with_dfs(std::shared_ptr<leaves> v, int &ans) {
    ans += (int)v->quantity;

    for (int i = 0; i < 26; ++i) {
        if (v->children[i] != nullptr) {
            search_size_with_dfs(v->children[i], ans);
        }
    }
}

void vector_dfs(std::shared_ptr<leaves> v, std::vector <std::string> &ans, std::string str) {
    for (size_t i = 0; i < (int)v->quantity; ++i) {
        ans.push_back(str);
    }

    for (int i = 0; i < 26; ++i) {
        if (v->children[i] != nullptr) {
            str.push_back('a' + i);
            vector_dfs(v->children[i], ans, str);
            str.pop_back();
        }
    }
}

void dfs_sort_and_find(std::shared_ptr<leaves> v, int &cur, int vert, std::string str, std::string &ans) {
    if (ans != "") {
        return;
    }

    cur += v->quantity;

    if (cur >= vert) {
        ans = str;
        return;
    }

    for (int i = 0; i < 26; ++i) {
        if (v->children[i] != nullptr) {
            if (v->children[i]->list + cur < vert) {
                cur += v->children[i]->list;
                continue;
            }

            str.push_back('a' + i);
            dfs_sort_and_find(v->children[i], cur, vert, str, ans);
            str.pop_back();
        }
    }
}

//-------------------------------

trie_t::trie_t(): root {new leaves()} {}
trie_t::trie_t(const trie_t &trie)
        : root { new leaves() } {
    search_for_operator(root, trie.root);
}

trie_t::~trie_t() { }

trie_t& trie_t::operator=(const trie_t &trie) {
    if (this == &trie)
        return *this;
    clear();
    root.reset(new leaves());
    search_for_operator(root, trie.root);
    return *this;
}
std::string trie_t::operator[](size_t index) const {
    std::string answer = "";
    int cur = 0;
    index++;
    dfs_sort_and_find(root, cur, index, "", answer);
    return answer;
}

void trie_t::insert(const std::string &s) {
    std::shared_ptr<leaves> current = root;
    for (int i = 0; i < s.size(); ++i) {
        char cur = s[i];
        if (!current->children[cur - 'a'])
            current->children[cur - 'a'].reset(new leaves());
        current->list++;
        current = current->children[cur - 'a'];
    }
    current->list++;
    current->quantity++;
}
void trie_t::swap(trie_t &other) {
    root.swap(other.root);
}
void trie_t::clear() {
    root.reset(new leaves());
}

bool trie_t::erase(const std::string &str) {
    std::shared_ptr<leaves> current = root;
    bool check;
    check = false;
    if (find(str) == true) {
        check = true;
    }
    for (size_t i = 0; i < str.size(); ++i) {
        char cur = str[i];
        if (current->children[cur - 'a'] == nullptr)
            return false;
        if (check)
            current->list--;
        current = current->children[cur - 'a'];
    }
    if (current->quantity) {
        current->quantity--;
        return true;
    }
    return false;
}
bool trie_t::find(const std::string &str) const {
    std::shared_ptr<leaves> current = root;
    for (size_t i = 0; i < (int)str.size(); ++i) {
        current = current->children[str[i] - 'a'];
        if (current == nullptr)
            return false;
    }
    if (current->quantity)
        return true;
    return false;
}
bool trie_t::empty() const {
    if (size() == 0)
        return true;
    return false;
}

size_t trie_t::count_with_prefix(const std::string &prefix) const {
    std::shared_ptr<leaves> current = root;
    int ans = 0;
    for (int i = 0; i < prefix.size(); ++i) {
        current = current->children[prefix[i] - 'a'];
        if (current == nullptr)
            return 0;
    }
    search_size_with_dfs(current, ans);
    return ans;
}
size_t trie_t::size() const {
    if (root == nullptr)
        return 0;
    int ans = 0;
    search_size_with_dfs(root, ans);
    return ans;
}
std::vector<std::string> trie_t::to_vector() const {
    std::vector <std::string> curans;
    vector_dfs(root, curans, "");
    return curans;
}
