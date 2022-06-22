/*!
** PC_SOFT_Test_CPP PROJECT, 2022
** @file Word.hpp
** File description:
** @brief Word class header
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/


#ifndef WORD_HPP_
    #define WORD_HPP_

    #include <string>

    /**
     * @brief Word Class used as a Key in my dictionary
     * @details This class is used as the Key in my Key/Value dictionary. For
     *      efficiency reasons I compute and store the hash to use it again
     *      when reindexing. To have better results this class cleans the entry
     *      of any non-alphanumeric character before computing the hash. This
     *      means that end of sentence word will be freed from their ponctuation.
     */
    class Word {
        public:
            /**
             * @brief Construct a new empty Word object
             * @details This constructor is used to create an empty Word object
             *      This constructor is only used to create the pool of Index in
             *      the Dictionary and should not be used anywhere else.
             */
            Word();

            /**
             * @brief Construct a new Word object
             * @details This constructor is used to create a Word object. this is
             *      the goto function to create a Word object.
             * @param word (const std::string &) The word to create the Word object
             */
            Word(std::string &word);
            // Word(const Word &inital);
            ~Word();
            const Word &operator=(const Word &rhs);

            /**
             * @brief word getter
             * @return const std::string & The word as a string
             */
            const std::string &getWord() const;

            /**
             * @brief hash getter
             * @return unsigned int the hash of the word
             */
            unsigned int getHash() const;

            /**
             * @brief Hash computation funtion
             * @details This function is used to compute the hash of the word.
             *      The hash is the sum of all the characters from the word based
             *      on their ascii value.
             * @param word (std::string) : the word to compute the hash
             * @return unsigned int : the hash of the word
             */
            static unsigned int hash(const std::string &word);

        protected:

        private:
            std::string _word;
            unsigned int _hash;

            /**
             * @brief Clean the word of any non-alphanumeric character
             * @param word (std::string &) : the word to clean
             * @return std::string : the cleaned word
             * @ This function is used to clean the word of any
             *     non-alphanumeric character.
            */
            const std::string clean(std::string &word) const;
    };

#endif