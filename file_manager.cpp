#include "file_manager.h"
#include <filesystem>
#include <iostream>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <sstream>
#include <iomanip>

namespace fs = std::filesystem;

std::vector<std::string> FileManager::getFiles(const std::string &directory) {
    std::vector<std::string> files;
    for (const auto &entry : fs::directory_iterator(directory))
        if (entry.is_regular_file())
            files.push_back(entry.path().string());
    return files;
}

void FileManager::copyFile(const std::string &src, const std::string &dest) {
    try {
        fs::copy(src, dest, fs::copy_options::overwrite_existing);
    } catch (fs::filesystem_error &e) {
        std::cerr << "File copy error: " << e.what() << std::endl;
    }
}

void FileManager::createDirectory(const std::string &path) {
    try {
        fs::create_directories(path);
    } catch (fs::filesystem_error &e) {
        std::cerr << "Directory creation error: " << e.what() << std::endl;
    }
}

void FileManager::createJob(const std::string &name, const std::string &date, const std::string &baseDir) {
    std::istringstream dateStream(date);
    std::tm tm = {};
    dateStream >> std::get_time(&tm, "%m/%d/%Y");
    std::ostringstream oss;
    oss << baseDir << '/' << (tm.tm_mon + 1) << '/' << tm.tm_mday << '/' << (tm.tm_year + 1900);
    createDirectory(oss.str() + '/' + name);
}

int FileManager::searchFiles(const std::string &directory, const std::string &searchTerm) {
    int count = 0;
    for (const auto &entry : fs::directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            std::string filename = entry.path().filename().string();
            if (filename.find(searchTerm) != std::string::npos) {
                count++;
            }
        }
    }
    return count;
}
