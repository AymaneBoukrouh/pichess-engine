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

TEST_CASE ("Testing get_square") {
  CHECK_EQ(get_square("a1"), 0x0000000000000080ULL);
  CHECK_EQ(get_square("e5"), 0x0000000800000000ULL);
  CHECK_EQ(get_square("h7"), 0x0001000000000000ULL);
}
