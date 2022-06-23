#include "Dictionary.hpp"

#include "Word.hpp"

Dictionary::Dictionary(): _capacity(DEFAULT_CAPACITY), _size(0), _data(nullptr)
{
    _data = new Index[_capacity];

    if (_data == nullptr)
    {
        /* Info : not catch anywhere, if this fails, the software cannot run at all
        I decided that the software should stop to avoid errors */
        throw std::bad_alloc();
    }
}

// Dictionary::Dictionary(const Dictionary &initial)
// {
// }

Dictionary::~Dictionary()
{
    delete[] _data;
}

// const Dictionary &Dictionary::operator=(const Dictionary &rhs)
// {
//     return *this;
// }

unsigned int Dictionary::addToFirstAvailable(unsigned int w_hash,
    unsigned int idx, std::string &word, const std::string &fileName)
{
    for (unsigned int i_hash = 0; idx < _capacity; idx++) {
        i_hash = _data[idx].getWord().getHash();

        if (i_hash == 0) {
            // std::cout << "New word Found : " << word << std::endl;
            _data[idx] = Index(word, fileName);
            _size++;
            break;

        }

        if (i_hash == w_hash && _data[idx].getWord().getWord() == word) {
            // std::cout << "Word already exists : " << word << std::endl;
            _data[idx].addFile(fileName);
            break;
        }
    }
    return (idx);
}

unsigned int Dictionary::addToFirstAvailable(unsigned int idx, Index &index) {

    for (unsigned int i_hash = 0; idx < _capacity; idx++) {
        i_hash = _data[idx].getWord().getHash();

        if (i_hash == 0) {
            _data[idx] = index;
            break;
        }
    }
    return (idx);
}

void Dictionary::add(std::string &word, const std::string &fileName)
{
    // no need for "safety" buffer (allocation when size gets over a defined
    // percentage of capacity) because this is single thread.
    if (_size == _capacity) {
        expand();
    }

    unsigned int w_hash = Word::hash(word);

    if (addToFirstAvailable(w_hash, w_hash % _capacity, word, fileName) == _capacity) {
        addToFirstAvailable(w_hash, 0, word, fileName);
    }
}

void Dictionary::add(Index &index)
{
    // no need for "safety" buffer (allocation when size gets over a defined
    // percentage of capacity) because this is single thread.
    if (_size == _capacity) {
        expand();
    }


    unsigned int w_hash = index.getWord().getHash();

    if (addToFirstAvailable(w_hash % _capacity, index) == _capacity) {
        addToFirstAvailable(0, index);
    }
}

const Index &Dictionary::search(const std::string &word) const
{
    unsigned int w_hash = Word::hash(word);

    for (unsigned int idx = w_hash % _capacity; idx < _capacity; idx++) {
        if (_data[idx].getWord().getHash() == w_hash) {
            return (_data[idx]);
        }
    }
    throw std::runtime_error("Word not found");
}

void Dictionary::expand()
{
    Index *tmp = new Index[_capacity + ADDED_CAPACITY];

    if (tmp == nullptr) {
        /* Info : not catch anywhere, if this fails, I decided that
            the software should stop to avoid errors */
        throw std::bad_alloc();
    }

    _capacity += ADDED_CAPACITY;
    std::swap(_data, tmp);

    for (unsigned int i = 0; i < _capacity; i++) {
        add(tmp[i]);
    }
    delete[] tmp;
}