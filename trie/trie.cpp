#include "trie.h"

trie_t::trie_t() = default;

trie_t::~trie_t() = default;
trie_t::trie_t(const trie_t &other) = default;
trie_t &trie_t::operator=(const trie_t &other) = default;

void trie_t::insert(const std::string &str) {
    ++subtree_count;
    if (str.length() == 0) {
        // в случае если строка кончилась
        ++cell_count;
        return;
    }
    // рекурсивно вызываем функцию
    next_layer[str[0]].insert(str.substr(1));
}

bool trie_t::erase(const std::string &str) {
    if (str.length() == 0) {
        // в случае если строка кончилась
        if (cell_count > 0) {
            --subtree_count;
            --cell_count;
            return true;
        } else {
            return false;
        }
    }
    if (next_layer.find(str[0]) == next_layer.end()) {
        // проверяем что в следующем слое есть нужная буква
        return false;
    }
    if (next_layer[str[0]].erase(str.substr(1))) { // рекурсивно вызываем функцию
        --subtree_count;
        return true;
    }
    return false;
}

void trie_t::clear() {
    next_layer.clear();
    cell_count = 0;
    subtree_count = 0;
}

bool trie_t::find(const std::string &str) const {
    if (str.length() == 0) {
        // в случае если строка кончилась
        return true;
    }
    if (next_layer.find(str[0]) == next_layer.end()) {
        // проверяем что в следующем слое есть нужная буква
        return false;
    }
    // рекурсивно вызываем функцию
    return next_layer.at(str[0]).find(str.substr(1));
}

size_t trie_t::count_with_prefix(const std::string &prefix) const {
    if (prefix.length() == 0) {
        // в случае если строка кончилась
        return subtree_count;
    }
    if (next_layer.find(prefix[0]) == next_layer.end()) {
        // проверяем что в следующем слое есть нужная буква
        return 0;
    }
    // рекурсивно вызываем функцию
    return next_layer.at(prefix[0]).count_with_prefix(prefix.substr(1));
}

std::string trie_t::operator[](size_t index) const {
    if (index < cell_count) {
        // если мы остановились в нужной ячейке
        return "";
    }
    index -= cell_count; // вычитаем количество строк в текущей ячейке
    for (const auto &cell : next_layer) {
        if (index < cell.second.subtree_count) {
            // если мы остановились в нужной ветке
            return cell.first + cell.second[index]; // рекурсивно вызываем функцию
        } else {
            // пропускаем ветки не содержащие нужную строку
            index -= cell.second.subtree_count; // вычитаем количество строк в дочерних ветках
        }
    }
}

std::vector<std::string> trie_t::to_vector() const {
    std::vector<std::string> string_vector{};
    for (int i = 0; i < cell_count; ++i) {
        // добавляем пустые строки
        string_vector.push_back("");
    }
    for (const auto &cell : next_layer) {
        // рекурсивно добавляем вектора из дочерних веток
        std::vector<std::string> subtree_vector = cell.second.to_vector();
        for (std::string &str : subtree_vector) {
            str = cell.first + str; // добавляем букву ко всем строкам
        }
        string_vector.insert(string_vector.end(), subtree_vector.begin(),
                             subtree_vector.end()); // добавляем элементы в конец
    }
    return string_vector;
}

size_t trie_t::size() const {
    return subtree_count;
}

bool trie_t::empty() const {
    return subtree_count == 0;
}

void trie_t::swap(trie_t &other) {
    std::swap(*this, other);
}