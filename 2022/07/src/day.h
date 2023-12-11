#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include "AoC/aoc.h"
#include <vector>
#include <string>

enum tCommand {
    cdRoot = 0,
    cdUp = 1,
    cdDir = 2,
    ls = 3
};
struct tCommands {
    tCommand command;
    std::vector<std::string> data;
};

struct tDirInfo {
    tDirInfo(std::string fp, int s) : fullPath(fp), size(s) {}

    bool operator<(const tDirInfo &rhs) const {
        return size < rhs.size;
    }

    std::string fullPath;
    int size;
};

struct tFile {
    tFile(std::string n, int s) : name(n), size(s) {}

    const std::string name;
    const uint size;
};

class tDirectory {
public:
    tDirectory() = default;

    tDirectory(std::string n, std::string fn, tDirectory *p = nullptr) : m_fullPath(fn), m_name(n) {
        m_directories[".."] = p;

    }

    void AddFile(std::string n, int s) {
        m_files.emplace_back(n, s);
    }

    tDirectory *AddDirectory(std::string n) {
        std::string fullPath = m_fullPath;
        fullPath.append(n);
        fullPath.append("/");
        tDirectory *newDir = new tDirectory(n, fullPath, this);
        if (m_directories.find(n) != m_directories.end()) {
            return nullptr;
        }
        m_directories[n] = newDir;
        return newDir;
    }

    tDirectory *ChangeDirectory(std::string n) {
        return m_directories.find(n) != m_directories.end() ? m_directories[n] : nullptr;
    }

    int DiskUsage() {
        uint size = 0;
        for (auto dir: m_directories) {
            if (dir.first != "..") {
                size += dir.second->DiskUsage();
            }
        }
        for (auto file: m_files) {
            size += file.size;
        }
        return size;
    }

    std::string PWD() { return m_fullPath; }

    std::string WD() { return m_name; }

    std::unordered_map<std::string, tDirectory *> Ls() {
        std::unordered_map<std::string, tDirectory *> ret = m_directories;
        for (auto it = ret.begin(); it != ret.end();) {
            if (it->first == "..") {
                ret.erase(it);
                return ret;
            }
            ++it;
        }
        return ret;
    }

    std::string GetDirName() { return m_name; }

private:
    std::string m_name;
    std::string m_fullPath;
    std::unordered_map<std::string, tDirectory *> m_directories;
    std::vector<tFile> m_files;
};

class Day {
public:
    Day(std::vector<std::string> data)
            : m_resultA(0), m_resultB(0), m_data(data) {
        m_filesystem = new tDirectory("/", "/");
        m_topdir = m_filesystem;
    }

    ~Day() { CleanUp(); }

    void PrepareData();

    void RunA(bool secondData = false);

    void RunB();

    void Report();

    void CleanUp();

    int ResultA() { return m_resultA; }

    int ResultB() { return m_resultB; }

private:
    void StepA(tDirectory *currDir, int &result, const int &limit);

    void StepB(tDirectory *currDir);

    void InternalCleanup(tDirectory *currDir);

    AoC::AoC aoc;
    const std::vector<std::string> m_data;
    std::vector<tCommands> m_commands;
    tDirectory *m_filesystem = nullptr;
    tDirectory *m_topdir = nullptr;
    std::vector<tDirInfo> m_dirInfo;
    int m_resultA = 0;
    int m_resultB = 0;
};

#endif //ADVENTOFCODE_DAY_H
