#include <cstdint>
#include <string>
#include "utils.h"

/**
  * @param c The file to return.
  * @return A bitboard representing the given file.
  */
uint64_t get_file (char c) {
  return 0x8080808080808080ULL >> (c - 'a');
}

/**
  * @param n The rank to return.
  * @return A bitboard representing the given rank.
  */
uint64_t get_rank (int n) {
  return 0xffULL << (8 * (n-1));
}

/**
  * @param s The square to return.
  * @return A bitboard representing the given square.
  */
uint64_t get_square (std::string s) {
  char file = s[0];
  int rank = s[1] - '0';
  return get_file(file) & get_rank(rank);
}
