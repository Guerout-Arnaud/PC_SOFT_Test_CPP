#ifndef DICTIONARY_HPP_
    #define DICTIONARY_HPP_


    /**
     * @brief Default size of the Dictionary
     * @details This value is use upon creation of the Dictionary. It's not
     * random, it has been selected because it's either a pow of 2 and a close
     * to the average number of word in a docuemnt.
     */
    #ifndef DEFAUTL_CAPACITY
        #define DEFAULT_CAPACITY 512
    #endif

    /**
     * @brief Size to add when the Dictionary gets extended
     */
    #ifndef ADDED_CAPACITY
        #define ADDED_CAPACITY 64
    #endif

    #include <string>
    #include <stdexcept>

    #include "Index.hpp"

    // Self Implementation of Unordered Map
    /**
     * @brief Self Implementation of a kind of Unordered Map
     * @details This class is the "container" of my Key/Value map, sorted using
     *     the hash of the key.
     */
    class Dictionary {
        public:
            /**
             * @brief Construct a new empty Dictionary object
             * @details This constructor is used to create an empty Dictionary.
             *      object. Upon construction the Directory is DEFAULT_CAPACITY.
             *      size. On each extention the capacity is increased by
             *      ADDED_CAPACITY. DEFAULT_CAPACITY and ADDED_CAPACITY are both
             *      Macro and can be redefine at compile time.
             * @throw std::bad_alloc if the memory allocation fails.
             */
            Dictionary();
            // Dictionary(const Dictionary &inital);
            ~Dictionary();
            // const Dictionary &operator=(const Dictionary &rhs);

            /**
             * @brief Add a new word to the Dictionary
             * @details This function is used to add a new file to a Word.
             *      If the Word does not exist it's added
             * @param word (const std::string &) The word used as a key
             * @param fileName (const std::string &) The name (containing filepath)
             *     of the file to add to the list where the word can be found.
             */
            void add(std::string &word, const std::string &fileName);

            /**
             * @brief This method allows you to get the Index of the researched word
             *
             * @throw runtime_error if the word is not found.
             * @param word (const std::string &) The word to search for
             * @return const Index & The Index of the word
             */
            const Index &search(const std::string &word) const;

        protected:

        private:
        /*
            Old Idea. Left here to keep track of thought process.

            // typedef struct index_list_s {
                // Index index;
                // linked_list_t list;
            // } index_list_t;
            // index_list_s *_pool;
        */

            unsigned int _capacity;
            unsigned int _size;
            Index *_data;

            /**
             * @brief Add a new word to the Dictionary
             * @details This function is used to add a new file to a Word.
             *      If the Word does not exist it's added
             * @param word (const std::string &) The word used as a key
             * @param fileName (const std::string &) The name (containing filepath)
             *     of the file to add to the list where the word can be found.
             */
            void add(Index &index);

            /**
             * @brief Expand the dictionnary to capacity + ADDED_CAPACITY.
             * @details This function is used to expand the capacity of the
             *     Dictionary to capacity + ADDED_CAPACITY. Once the capacity
             *    is expanded all Index are .
             * @throw std::bad_alloc if the memory allocation fails.
             */
            void expand();

            unsigned int addToFirstAvailable(unsigned int w_hash, unsigned int idx, std::string &word, const std::string &fileName);
            unsigned int addToFirstAvailable(unsigned int idx, Index &index);
    };

#endif