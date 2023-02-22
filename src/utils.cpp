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
  * @param c The file of the square.
  * @param n The rank of the square.
  * @return A bitboard representing the forward diagonal of the given square.
  */
uint64_t get_forward_diagonal (char c, int n) {
  // TODO: Dynamically generate the diagonals array.
  const uint64_t diagonals[15] = {
    0x8000000000000000ULL,
    0x4080000000000000ULL,
    0x2040800000000000ULL,
    0x1020408000000000ULL,
    0x0810204080000000ULL,
    0x0408102040800000ULL,
    0x0204081020408000ULL,
    0x0102040810204080ULL,
    0x0001020408102040ULL,
    0x0000010204081020ULL,
    0x0000000102040810ULL,
    0x0000000001020408ULL,
    0x0000000000010204ULL,
    0x0000000000000102ULL,
    0x0000000000000001ULL
  };

  const std::string coords = std::string(1, c) + std::to_string(n);
  const uint64_t square_bb = get_square(coords);
  for (uint64_t d: diagonals)
    if (d & square_bb)
      return d;
  
  return 0;
}

/**
  * @param c The file of the square.
  * @param n The rank of the square.
  * @return A bitboard representing the backward diagonal of the given square.
  */
uint64_t get_backward_diagonal (char c, int n) {
  // TODO: Dynamically generate the diagonals array.
  const uint64_t diagonals[15] = {
    0x0000000000000080ULL,
    0x0000000000008040ULL,
    0x0000000000804020ULL,
    0x0000000080402010ULL,
    0x0000008040201008ULL,
    0x0000804020100804ULL,
    0x0080402010080402ULL,
    0x8040201008040201ULL,
    0x4020100804020100ULL,
    0x2010080402010000ULL,
    0x1008040201000000ULL,
    0x0804020100000000ULL,
    0x0402010000000000ULL,
    0x0201000000000000ULL,
    0x0100000000000000ULL
  };

  const std::string coords = std::string(1, c) + std::to_string(n);
  const uint64_t square_bb = get_square(coords);
  for (uint64_t d: diagonals)
    if (d & square_bb)
      return d;
  
  return 0;
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
