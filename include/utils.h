#pragma once

#include <cstdint>
#include <string>

#define U64 0xffffffffffffffffULL
#define U0 0x0000000000000000ULL

uint64_t get_file (char c);
uint64_t get_rank (int n);
uint64_t get_square (std::string s);
