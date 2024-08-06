#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>

class FileManager {
public:
    static std::vector<std::string> getFiles(const std::string &directory);
    static void copyFile(const std::string &src, const std::string &dest);
    static void createDirectory(const std::string &path);
    static void createJob(const std::string &name, const std::string &date, const std::string &baseDir);
    static int searchFiles(const std::string &directory, const std::string &searchTerm);
};

#endif // FILE_MANAGER_H
