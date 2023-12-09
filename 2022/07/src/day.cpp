#include <iostream>
#include "day.h"
#include <Assertion.h>


void Day::PrepareData() {

    for (auto data: m_data) {
        auto command = aoc.StringSplit(data, ' ');
        if (command[0] == "$") {
            if (command[1] == "cd") {
                if (command[2] == "/") {
                    m_filesystem = m_topdir;
                } else {
                    if (m_filesystem->ChangeDirectory(command[2]) != nullptr) {
                        m_filesystem = m_filesystem->ChangeDirectory(command[2]);
                    }
                }
            } else if (command[1] == "ls") { continue; }
            else {ExitIfReached(); }
        } else if (command[0] == "dir") {
            m_filesystem->AddDirectory(command[1]);
        } else if (std::all_of(command[0].begin(), command[0].end(), ::isdigit)) {
            m_filesystem->AddFile(command[1], std::stoi(command[0]));
        } else {ExitIfReached(); }
    }
    m_filesystem = m_topdir;
    int size = m_topdir->DiskUsage();
    ExitOnAssertFail((size != 0));

}

void Day::StepA(tDirectory *currDir, int &result, const int &limit) {
    int fs = currDir->DiskUsage();
    if (fs <= limit) { result += fs; }
    auto dirs = currDir->Ls();
    for (auto dir: dirs) {
        StepA(dir.second, result, limit);
    }
}


void Day::StepB(tDirectory *currDir) {
    m_dirInfo.emplace_back(currDir->PWD(), currDir->DiskUsage());
    int fs = currDir->DiskUsage();
    auto dirs = currDir->Ls();
    for (auto dir: dirs) {
        StepB(dir.second);
    }
}


void Day::RunA(bool secondData) {
    const int limit = 100000;
    StepA(m_filesystem, m_resultA, limit);
}


void Day::RunB() {
    int totalDiskSpace = 70000000;
    int updateNeed = 30000000;
    int freeNow = totalDiskSpace - m_filesystem->DiskUsage();
    int missing = updateNeed - freeNow;
    std::cout << missing;
    StepB(m_filesystem);
    std::sort(m_dirInfo.begin(), m_dirInfo.end());
    auto iterator = std::find_if(m_dirInfo.begin(), m_dirInfo.end(),
                                 [&missing](tDirInfo info) { return missing <= info.size; });
    m_resultB = iterator->size;
}

void Day::InternalCleanup(tDirectory *currDir) {
    auto dirs = currDir->Ls();
    for(auto dir :dirs) {
        InternalCleanup(dir.second);
    }
    for(auto dir :dirs) {
        delete dir.second;
    }
}

void Day::CleanUp() {
    InternalCleanup(m_filesystem);
    delete m_filesystem;
}

void Day::Report() {
    std::cout << "Part A: " << m_resultA << std::endl;
    std::cout << "Part B: " << m_resultB;
}