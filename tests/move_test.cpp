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
