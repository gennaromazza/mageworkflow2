#include "file_manager.h"
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <iomanip>

namespace fs = boost::filesystem;

std::vector<std::string> FileManager::getFiles(const std::string &directory) {
    std::vector<std::string> files;
    for (const auto &entry : fs::directory_iterator(directory)) {
        if (fs::is_regular_file(entry)) {
            files.push_back(entry.path().string());
        }
    }
    return files;
}

void FileManager::copyFile(const std::string &src, const std::string &dest) {
    try {
        fs::copy_file(src, dest, fs::copy_option::overwrite_if_exists);
    } catch (const fs::filesystem_error &e) {
        std::cerr << "File copy error: " << e.what() << std::endl;
    }
}

void FileManager::createDirectory(const std::string &path) {
    try {
        fs::create_directories(path);
    } catch (const fs::filesystem_error &e) {
        std::cerr << "Directory creation error: " << e.what() << std::endl;
    }
}

void FileManager::createJob(const std::string &name, const std::string &date, const std::string &baseDir) {
    std::istringstream dateStream(date);
    std::tm tm = {};
    dateStream >> std::get_time(&tm, "%m/%d/%Y");
    
    std::ostringstream oss;
    oss << baseDir << '/' << (tm.tm_mon + 1) << '/' << tm.tm_mday << '/' << (tm.tm_year + 1900);
    
    fs::path jobPath = fs::path(oss.str()) / name;
    createDirectory(jobPath.string());
}

int FileManager::searchFiles(const std::string &directory, const std::string &searchTerm) {
    int count = 0;
    for (const auto &entry : fs::recursive_directory_iterator(directory)) {
        if (fs::is_regular_file(entry)) {
            std::string filename = entry.path().filename().string();
            if (boost::algorithm::contains(filename, searchTerm)) {
                count++;
            }
        }
    }
    return count;
}
