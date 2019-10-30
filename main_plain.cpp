
#include <xss.hpp>

int main(int argc, char const* argv[]) {
  std::cout << "Hello MWE plain!" << std::endl;
  std::string teststr = "$northamerica$";
  auto strptr = teststr.data();
  std::cout << teststr << " --- Length: " << teststr.size() << std::endl;
  auto p = xss::pss_array(strptr, teststr.size());
  std::cout << "PSS Array: ";
  for (auto val : p) {
    std::cout << val << ", ";
  }
  std::cout << std::endl;
  return 0;
}
