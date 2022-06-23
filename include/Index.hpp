/*!
** PC_SOFT_Test_CPP PROJECT, 2022
** @file Index.hpp
** File description:
** @brief Index class header
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/


#ifndef INDEX_HPP_
    #define INDEX_HPP_

    #include <string>

    #include "linked_list/linked_list.h"

    #include "Word.hpp"

    /**
     * @brief Index Class conating both Key (Word) and Value (LinkedList)
     * @details This class is used as the Key/Value in my Key/Value dictionary.
     *      It contains the values (names of the files where the Word can be find)
     *      as a linked list. This linked list comes from my own C library. It has
     *      been slightly modified to fit C++ compared to [github current version]
     *      (https://github.com/Guerout-Arnaud/C_Lib). I've made this choice to
     *      focus on the main goal of this project: the Dictionary and not lose
     *      time reinventing the wheel by creating a new container. Under normal
     *      circomptences I would have used a std::list. Since I use this library
     *      in most of my project I know this is reliable and memory safe.
     *      Also the use of my Linked List could be made easier and quicker by
     *      using a shared pointer. This would avoid me to make deep copy of the
     *      list. I didn't used smart pointers here because STL containers were
     *      banned so I thought smart pointers could be.
     */
    class Index {
        public:
            /**
             * @brief Construct a new empty Index object
             * @details This constructor is used to create an empty Index object
             *      This constructor is only used to create the pool of Index in
             *      the Dictionary and should not be used anywhere else.
             */
            Index();

            /**
             * @brief Construct a new Index object
             * @details This constructor is used to create a Index object. this is
             *      the goto function to create a Index object.
             * @param word (const Word &) The word to create the Index object
             * @param fileName (const std::string &) The name (containing filepath)
             *      of the file where the word can be found.
             */
            Index(std::string &word, const std::string &fileName);
            Index(const Index &inital);
            ~Index();
            const Index &operator=(const Index &rhs);

            /**
             * @brief word setter
             * @patam word (const Word &) The word to set
             */
            void setWord(const Word &word);
            /**
             * @brief word getter
             * @return const Word & The word as a Word object
             */
            const Word &getWord() const;

            /**
             * @brief File addition method
             * @param fileName (const std::string &) The name (containing filepath)
             *      of the file to add to the list where the word can be found.
             */
            void addFile(const std::string &fileName);
            /**
             * @brief File getter method as a std::string
             * @return const std::string The formatted (comma + space) list of
             * file where the word can be found.
             */
            const std::string getFiles() const;


/* ToDo : Print and overload operator << */
/* Won't Be Done : Not nedded anymore. might be an upgrade idea */

        protected:

        private:
            typedef struct files_list_s {
                std::string fileName;
                linked_list_t list;
            } files_list_t;

            Word _word;
            int _nbFiles;
            files_list_t *_filesList;
    };

#endif