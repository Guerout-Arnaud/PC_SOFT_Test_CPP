#include "Word.hpp"

Word::Word(): _word(""), _hash(0)
{
}

Word::Word(std::string &word)
{
    _word = clean(word);
    _hash = hash(_word);
}

// Word::Word(const Word &initial)
// {
//     _word = initial._word;
//     _hash = initial._hash;
// }

Word::~Word()
{
}

const Word &Word::operator=(const Word &rhs)
{
    if (this != &rhs)
    {
        _word = rhs._word;
        _hash = rhs._hash;
    }
    return *this;
}

const std::string &Word::getWord() const {
    return _word;
}

unsigned int Word::getHash() const {
    return _hash;
}


unsigned int Word::hash(const std::string &word)
{
    unsigned int value = 0;

    for (auto c : word) {
        value = value + c;
    }

    return (value);
}


const std::string Word::clean(std::string &word) const
{
    int to_remove = 0;

    for (auto c = word.cend() - 1; c != word.cbegin(); c--) {
        if ((*c < '0' || *c > '9') && (*c < 'A' || *c > 'Z')
            && (*c < 'a' || *c > 'z')) {
        to_remove++;
        } else {
            break;
        }

    }
    word.erase(word.size() - to_remove, to_remove);
    return (word);
}
