#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

void findCppFiles(const std::string &folder, std::vector<std::string> &files)
{
    WIN32_FIND_DATAA entry;
    HANDLE search = FindFirstFileA((folder + "\\*").c_str(), &entry);

    if (search == INVALID_HANDLE_VALUE)
    {
        return;
    }

    do
    {
        const std::string name = entry.cFileName;
        if (name == "." || name == "..")
        {
            continue;
        }

        const std::string path = folder + "\\" + name;
        if (entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            findCppFiles(path, files);
        }
        else if (name.size() > 4 && name.substr(name.size() - 4) == ".cpp")
        {
            files.push_back(path);
        }
    } while (FindNextFileA(search, &entry));

    FindClose(search);
}

int main()
{
    char root[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, root);

    std::vector<std::string> files;
    findCppFiles(root, files);
    files.erase(std::remove(files.begin(), files.end(), std::string(root) + "\\run-problem.cpp"), files.end());
    std::sort(files.begin(), files.end());

    for (std::size_t index = 0; index < files.size(); ++index)
    {
        std::cout << index + 1 << ". " << files[index] << '\n';
    }

    std::size_t choice;
    std::cout << "Choose a problem (1-" << files.size() << "): ";
    std::cin >> choice;

    if (choice < 1 || choice > files.size())
    {
        return 1;
    }

    const std::string source = files[choice - 1];
    const std::string executable = std::string(root) + "\\solution.exe";
    const std::string compile = "clang++ -std=c++23 \"" + source + "\" -o \"" + executable + "\"";

    if (std::system(compile.c_str()) != 0)
    {
        return 1;
    }

    return std::system(("\"" + executable + "\"").c_str());
}