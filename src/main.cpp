#include <cstring>

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>

#include "Dictionary.hpp"
#include "Index.hpp"
#include "Word.hpp"

/**
 * @brief Just a simple progress bar for better UX
 *
 * @param progress current progress
 * @param total max value of progress
 */
void progress_bar(int progress, int total)
{
    int percent = (progress * 100) / total;
    int num_char = percent * 40 / 100;

    std::cout << "\r[";
    for (int i = 0; i < num_char; i++)
        std::cout << "#";
    for (int i = num_char; i < 40; i++)
        std::cout << " ";
    std::cout << "] " << percent << "%";
    std::cout.flush();
}

int main(int argc, char **argv)
{
    if (argc < 2 || argv [1] == NULL || std::strcmp(argv[1], "--help") == 0
        || std::strcmp(argv[1], "-h") == 0) {
        std::cout << "Usage: " << argv[0] << " <path>" << std::endl;
        return (1);
    }

    std::filesystem::path path(argv[1]);

    /* Check if path exists */
    if (std::filesystem::exists(path)) {
        std::cout << "Path " << path << " exists" << std::endl;
    } else {
        std::cout << "Path " << path << " does not exist" << std::endl;
        return (-1);
    }

    /* Count Total Number of files */
    unsigned int totalFiles = 0;
    for (const auto &entry : std::filesystem::recursive_directory_iterator(path)) {
        if (std::filesystem::is_regular_file(entry)
            && entry.path().extension() == ".txt") {
            std::cout << entry << " found." << std::endl;
            totalFiles++;
        }
    }
    if (totalFiles == 0) {
        std::cout << "No txt file found" << std::endl;
        return (-1);
    }

    std::cout << totalFiles << " file(s) found" << std::endl;

    /* Dictionnary creation made here for efficiency reasons */
    /* Info : Throwable upon memory allocation fail */
    Dictionary dictionary = Dictionary();


    /* Word fetching, file by file, one by one. Could be made more efficient
        by adding threads*/
    std::cout << "Fetching all words, please wait. " <<
        "This may take a while if you have huge files" << std::endl;
    unsigned int progress = 0;
    progress_bar(progress, totalFiles);
    for (const auto &entry : std::filesystem::recursive_directory_iterator(path)) {
        if (!std::filesystem::is_regular_file(entry)
            || entry.path().extension() != ".txt") {
            continue;
            }

        std::ifstream file(entry.path());
        std::string word = "";

        if (file.is_open())
        {
            while(file >> word)
            {
                /* setting word to lower case for better result accuracy */
                std::transform(word.begin(), word.end(), word.begin(),
                    [](unsigned char c){ return std::tolower(c); });

                /* Info : Throwable upon memory allocation fail */
                dictionary.add(word, entry.path().string());

                // std::cout << word << std::endl;
                // std::cout << std::endl;
            }

        } else {
            std::cout << "file " << path <<
                " failed to open and wont be included in the result" << std::endl;
        }

        progress_bar(++progress, totalFiles);
    }
    std::cout << std::endl;

    std::string userInput = "";
    std::cout << "Please enter the word you want to search for. "
        "Your word will be transform to lower case anyway. (Ctrl+D to exit): ";
    std::cin >> userInput;


    while (!std::cin.eof()) {
        std::transform(userInput.begin(), userInput.end(), userInput.begin(),
            [](unsigned char c){ return std::tolower(c); });
        try {
            Index i = dictionary.search(userInput);
            std::cout << "Here are all the file containing \"" << userInput
                << "\":\n[" << i.getFiles() << "]" << std::endl;
        } catch (std::runtime_error &) {
            std::cout << "Word \"" << userInput << "\" not found" << std::endl;
        }
        std::cout << "\nPlease enter the word you want to search for" <<
            "(your word will be transform to lower case): ";
        std::cin >> userInput;
    }
    return (0);
}