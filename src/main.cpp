#include <cstring>

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>

#include "Dictionary.hpp"
#include "Index.hpp"
#include "Word.hpp"

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
    if (argc < 2 || argv [1] == NULL || std::strcmp(argv[1], "--help") == 0 || std::strcmp(argv[1], "-h") == 0) {
        std::cout << "Usage: " << argv[0] << " <path>" << std::endl;
        return (1);
    }

    std::filesystem::path path(argv[1]);

    if (std::filesystem::exists(path)) {
        std::cout << "Path " << path << " exists" << std::endl;
    } else {
        std::cout << "Path " << path << " does not exist" << std::endl;
    }

    unsigned int totalFiles = 0;
    for (const auto &entry : std::filesystem::recursive_directory_iterator(path)) {
        if (std::filesystem::is_regular_file(entry) && entry.path().extension() == ".txt") {
            totalFiles++;
        }
    }
    std::cout << totalFiles << " files found" << std::endl;
    std::cout << "Fetching all words, please wait. This may take a while if you have huge files" << std::endl;


    Dictionary dictionary = Dictionary();

    unsigned int progress = 0;
    progress_bar(progress, totalFiles);
    for (const auto &entry : std::filesystem::recursive_directory_iterator(path)) {
        if (!std::filesystem::is_regular_file(entry) || entry.path().extension() != ".txt")
            continue;
        // std::cout << entry << " is a text file" << std::endl;


        std::ifstream file(entry.path());
        std::string word = "";

        if (file.is_open())
        {
            while(file >> word)
            {
                std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });

                dictionary.add(word, entry.path().string());
                // std::cout << word << std::endl;
                // std::cout << std::endl;
            }

        } else {
            std::cout << "file open fail" << std::endl;
        }

        progress_bar(++progress, totalFiles);
        // std::cout << "Progress: ["
        // for (int i = 0;  ) << (progress * 100) / totalFiles << "%" << std::endl;
    }
    std::cout << std::endl;

    // return (0);
    // Index i = dictionary.search("document").getFiles();


    std::string userInput = "";
    std::cout << "Please enter the word you want to search for. Your word will be transform to lower case anyway. (Ctrl+D to exit): ";
    std::cin >> userInput;


    for (; !std::cin.eof();) {
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c){ return std::tolower(c); });
        try {
            Index i = dictionary.search(userInput);
            std::cout << "Here are all the file containing \"" << userInput << "\":\n[" << i.getFiles() << "]" << std::endl;
        } catch (std::exception &e) {
            std::cout << "Word \"" << userInput << "\" not found" << std::endl;
        }
        std::cout << "\nPlease enter the word you want to search for (your word will be transform to lower case): ";
        std::cin >> userInput;
    }
    return (0);
}