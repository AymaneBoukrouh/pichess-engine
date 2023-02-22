#include <doctest/doctest.h>
#include "move.h"

TEST_CASE ("Testing king_moves") {
  // king on a1
  CHECK_EQ(king_moves(0x0000000000000080ULL), 0x000000000000c040ULL);

  // king on d8
  CHECK_EQ(king_moves(0x1000000000000000ULL), 0x2838000000000000ULL);

  // king on h5
  CHECK_EQ(king_moves(0x0000000100000000ULL), 0x0000030203000000ULL);
}

/**
  Skipping queen_moves because it's just a combination of rook_moves and bishop_moves.
  We'll test those two functions instead.
**/

TEST_CASE ("Testing rook_moves") {
  // rook on a1
  CHECK_EQ(rook_moves(0x0000000000000080ULL), 0x808080808080807fULL);

  // rook on d4
  CHECK_EQ(rook_moves(0x0000000010000000ULL), 0x10101010ef101010ULL);
}

TEST_CASE ("Testing bishop_moves") {
  // bishop on a1
  CHECK_EQ(bishop_moves(0x0000000000000080ULL), 0x0102040810204000ULL);

  // bishop on b1
  CHECK_EQ(bishop_moves(0x0000000000000040ULL), 0x000102040810a000ULL);

  // bishop on g2
  CHECK_EQ(bishop_moves(0x0000000000000200ULL), 0x8040201008050005ULL);

  // bishop on d7
  CHECK_EQ(bishop_moves(0x0010000000000000ULL), 0x2800284482010000ULL);
}

TEST_CASE ("Testing knight_moves") {
  // knight on a1
  CHECK_EQ(knight_moves(0x0000000000000080ULL), 0x0000000000402000ULL);

  // knight on b4
  CHECK_EQ(knight_moves(0x0000000040000000ULL), 0x0000a0100010a000ULL);

  // knight on f5
  CHECK_EQ(knight_moves(0x0000000400000000ULL), 0x000a1100110a0000ULL);

  // knight on h7
  CHECK_EQ(knight_moves(0x0001000000000000ULL), 0x0400040200000000ULL);
}

TEST_CASE ("Testing light_pawn_moves") {
  // light pawn on a2
  CHECK_EQ(light_pawn_moves(0x0000000000008000ULL), 0x0000000080800000ULL);
  
  // light pawn on f2
  CHECK_EQ(light_pawn_moves(0x0000000000000400ULL), 0x0000000004040000ULL);

  // light pawn on c4
  CHECK_EQ(light_pawn_moves(0x0000000020000000ULL), 0x0000002000000000ULL);

  // light pawn on g6
  CHECK_EQ(light_pawn_moves(0x0000020000000000ULL), 0x0002000000000000ULL);
}

TEST_CASE ("Testing dark_pawn_moves") {
  // dark pawn on a7
  CHECK_EQ(dark_pawn_moves(0x0080000000000000ULL), 0x0000808000000000ULL);
  
  // dark pawn on d7
  CHECK_EQ(dark_pawn_moves(0x0010000000000000ULL), 0x0000101000000000ULL);

  // dark pawn on c5
  CHECK_EQ(dark_pawn_moves(0x0000002000000000ULL), 0x0000000020000000ULL);

  // dark pawn on g3
  CHECK_EQ(dark_pawn_moves(0x0000000000020000ULL), 0x0000000000000200ULL);
}
