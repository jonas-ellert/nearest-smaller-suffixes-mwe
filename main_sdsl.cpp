
#include <xss_sdsl.hpp>

int main(int argc, char const* argv[]) {
  std::cout << "Hello MWE plain!" << std::endl;
  std::string teststr = "$northamerica$";
  auto strptr = teststr.data();
  std::cout << teststr << " --- Length: " << teststr.size() << std::endl;
  sdsl::bit_vector bv(teststr.size() * 2 + 2);
  xss::pss_tree(strptr, teststr.size(), bv.data());
  xss::pss_tree_support_sdsl support(bv);
  std::cout << "PSS Array: " << teststr.size() << ", ";
  for (uint64_t i = 1; i < teststr.size() - 1; ++i) {
    std::cout << support.pss(i) << ", ";
  }
  std::cout << teststr.size() << ", " << std::endl;
  return 0;
}
