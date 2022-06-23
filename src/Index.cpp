#include <cstring>

#include "Index.hpp"

Index::Index(): _nbFiles(0), _filesList(nullptr)
{
}

Index::Index(std::string &word, const std::string &fileName): _word(word),
    _nbFiles(0), _filesList(nullptr)
{
    addFile(fileName);
};


Index::Index(const Index &initial)
{
    _word = initial._word;
    _nbFiles = initial._nbFiles;

    /* Info : Using a shared_pointer would be better for both readability and safety */
    for (files_list_t *tmp = initial._filesList; tmp != nullptr; tmp = list_next(tmp, list)) {
        files_list_t *elem = new files_list_t;
        list_init(elem, list);
        elem->fileName = tmp->fileName;
        _filesList = list_add(_filesList, elem, list);
    }
}

Index::~Index()
{
    for (files_list_t *next = nullptr; _filesList != nullptr; _filesList = next) {
        next = list_next(_filesList, list);
        delete(_filesList);
    }
}

const Index &Index::operator=(const Index &rhs)
{
    if (this != &rhs)
    {
        _word = rhs._word;
        _nbFiles = rhs._nbFiles;

        /* Info : Using a shared_pointer would be better for both readability and safety */
        for (files_list_t *tmp = rhs._filesList; tmp != nullptr; tmp = list_next(tmp, list)) {
            files_list_t *elem = new files_list_t;
            list_init(elem, list);
            elem->fileName = tmp->fileName;
            _filesList = list_add(_filesList, elem, list);
        }
    }
    return *this;
}

void Index::setWord(const Word &word)
{
    _word = word;
}

const Word &Index::getWord() const
{
    return _word;
}

void Index::addFile(const std::string &fileName)
{
    for (files_list_t *tmp = _filesList; tmp != nullptr; tmp = list_next(tmp, list)) {
        if (tmp->fileName == fileName)
            return;
    }

    files_list_t *file = new files_list_t;

    list_init(file, list);

    file->fileName = fileName;
    _filesList = list_add(_filesList, file, list);
    _nbFiles++;

}

/* ToDo : Print and overload operator << */

const std::string Index::getFiles() const
{
    std::string files = "";

    for (files_list_t *tmp = _filesList; tmp != nullptr; tmp = list_next(tmp, list)) {
        if (tmp != _filesList)
            files += ", ";
        files += tmp->fileName;
    }
    return files;
}