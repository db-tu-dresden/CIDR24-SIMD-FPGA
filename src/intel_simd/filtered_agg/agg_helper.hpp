#ifndef TEST_CIDR_AGG_AGG_HELPER_HPP
#define TEST_CIDR_AGG_AGG_HELPER_HPP

namespace tuddbs {
  enum class SCALAR_MASKED_AGGREGATE_STRATEGY {
    TERNARY
    // ,    BITWISE
  };
  enum class HORIZONTAL_AGGREGATION_STRATEGY {
    ACCUM,
    ARRAY_ADDER_TREE,
    TUPL_ADDER_TREE
  };
}

#endif //TEST_CIDR_AGG_AGG_HELPER_HPP