#ifndef READFILE_H
#define READFILE_H

#include <vector>
#include <fstream>

int readfile(std::string const& fileName, std::vector<int>& horizontal, std::vector<int>& vertical);

#endif