#include <doctest/doctest.h>
#include "utils.h"

TEST_CASE ("Testing get_rank") {
  CHECK_EQ(get_rank(1), 0x00000000000000ffULL);
  CHECK_EQ(get_rank(5), 0x000000ff00000000ULL);
  CHECK_EQ(get_rank(8), 0xff00000000000000ULL);
}

TEST_CASE ("Testing get_file") {
  CHECK_EQ(get_file('a'), 0x8080808080808080ULL);
  CHECK_EQ(get_file('c'), 0x2020202020202020ULL);
  CHECK_EQ(get_file('h'), 0x0101010101010101ULL);
}

TEST_CASE ("Testing get_forward_diagonal") {
  // a1 -> h8
  CHECK_EQ(get_forward_diagonal('a', 1), 0x0102040810204080ULL);
  CHECK_EQ(get_forward_diagonal('h', 8), 0x0102040810204080ULL);
  CHECK_EQ(get_forward_diagonal('d', 4), 0x0102040810204080ULL);

  // a4 -> e8
  CHECK_EQ(get_forward_diagonal('a', 4), 0x0810204080000000ULL);
  CHECK_EQ(get_forward_diagonal('e', 8), 0x0810204080000000ULL);
  CHECK_EQ(get_forward_diagonal('b', 5), 0x0810204080000000ULL);
  
  // e1 -> h4
  CHECK_EQ(get_forward_diagonal('e', 1), 0x0000000001020408ULL);
  CHECK_EQ(get_forward_diagonal('h', 4), 0x0000000001020408ULL);
  CHECK_EQ(get_forward_diagonal('g', 3), 0x0000000001020408ULL);
}

TEST_CASE ("Testing get_backward_diagonal") {
  // a8 -> h1
  CHECK_EQ(get_backward_diagonal('a', 8), 0x8040201008040201ULL);
  CHECK_EQ(get_backward_diagonal('h', 1), 0x8040201008040201ULL);
  CHECK_EQ(get_backward_diagonal('d', 5), 0x8040201008040201ULL);

  // a5 -> e1
  CHECK_EQ(get_backward_diagonal('a', 5), 0x0000008040201008ULL);
  CHECK_EQ(get_backward_diagonal('e', 1), 0x0000008040201008ULL);
  CHECK_EQ(get_backward_diagonal('b', 4), 0x0000008040201008ULL);

  // c8 -> h3
  CHECK_EQ(get_backward_diagonal('c', 8), 0x2010080402010000ULL);
  CHECK_EQ(get_backward_diagonal('h', 3), 0x2010080402010000ULL);
  CHECK_EQ(get_backward_diagonal('f', 5), 0x2010080402010000ULL);
}

TEST_CASE ("Testing get_square") {
  CHECK_EQ(get_square("a1"), 0x0000000000000080ULL);
  CHECK_EQ(get_square("e5"), 0x0000000800000000ULL);
  CHECK_EQ(get_square("h7"), 0x0001000000000000ULL);
}
