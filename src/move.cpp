#include <cstdint>
#include "utils.h"

/**
  * @name Piece Moves
  * @brief Functions for calculating piece moves.
  * @param b A bitboard of a single square representing the piece's position.
  * @return A bitboard of all possible moves.
  */

uint64_t king_moves (uint64_t b) {
  uint64_t moves = 0x0000000000000000ULL;

  moves |= (b >> 9) & ~get_file('a');
  moves |= (b >> 8);
  moves |= (b >> 7) & ~get_file('h');
  moves |= (b >> 1) & ~get_file('a');
  moves |= (b << 9) & ~get_file('h');
  moves |= (b << 8);
  moves |= (b << 7) & ~get_file('a');
  moves |= (b << 1) & ~get_file('h');

  return moves;
}

uint64_t knight_moves (uint64_t b) {
  uint64_t moves = 0x0000000000000000ULL;

  moves |= (b >> 17) & ~get_file('a');
  moves |= (b >> 15) & ~get_file('h');
  moves |= (b >> 10) & ~get_file('a') & ~get_file('b');
  moves |= (b >> 6) & ~get_file('h') & ~get_file('g');
  moves |= (b << 17) & ~get_file('h');
  moves |= (b << 15) & ~get_file('a');
  moves |= (b << 10) & ~get_file('h') & ~get_file('g');
  moves |= (b << 6) & ~get_file('a') & ~get_file('b');

  return moves;
}
