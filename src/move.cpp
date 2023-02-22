#include <cstdint>
#include "utils.h"
#include "move.h"

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

uint64_t queen_moves (uint64_t b) {
  return rook_moves(b) | bishop_moves(b);
}

uint64_t rook_moves (uint64_t b) {
  char rook_file;
  int rook_rank;

  for (int i=0; i<64; i++)
    if (b & (1ULL << i)) {
      rook_file = 'a' + (8 - i%8 - 1);
      rook_rank = 1 + (i / 8);
    }

  return (get_file(rook_file) | get_rank(rook_rank)) & ~b;
}

uint64_t bishop_moves (uint64_t b) {
  uint64_t moves = 0x0000000000000000ULL;

  char bishop_file;
  int bishop_rank;

  for (int i=0; i<64; i++)
    if (b & (1ULL << i)) {
      bishop_file = 'a' + (8 - i%8 - 1);
      bishop_rank = 1 + (i / 8);
    }

  moves |= get_forward_diagonal(bishop_file, bishop_rank);
  moves |= get_backward_diagonal(bishop_file, bishop_rank);

  return moves & ~b;
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

uint64_t light_pawn_moves (uint64_t b) {
  uint64_t moves = 0x0000000000000000ULL;

  moves |= (b << 8);
  moves |= (b << 16) & get_rank(4);

  return moves;
}

uint64_t dark_pawn_moves (uint64_t b) {
  uint64_t moves = 0x0000000000000000ULL;

  moves |= (b >> 8);
  moves |= (b >> 16) & get_rank(5);

  return moves;
}
