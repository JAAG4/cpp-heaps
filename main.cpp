// range heap example
#include <algorithm> // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <iostream> // std::cout
#include <math.h>   /* ilogb */
#include <string>
#include <vector> // std::vector
void print_heap(std::string msg, std::vector<int> vec) {

  std::cout << "\t" << msg << std::endl;
  int max_lvl = ilogb(vec.size() + 1);
  int prev_lvl = 0;
  for (int i = 0; i < vec.size(); i++) {
    bool do_write_lines;
    int num = vec[i];
    int curr_lvl = ilogb(i + 1);
    for (int k = 0; k < (max_lvl + 1 - curr_lvl); k++) {
      std::cout << "    ";
    }
    std::cout << " " << num << " ";
    if (curr_lvl != prev_lvl) {
      std::cout << "\n";
      prev_lvl = curr_lvl;
      do_write_lines = true;
    } else {
      do_write_lines = false;
    }
    // std::cout << " Level: " << curr_lvl << "  " << std::endl;
    if (do_write_lines) {
      for (int j = 0; j <= curr_lvl; j++) {
        for (int i = 0; i <= (max_lvl + 1 - curr_lvl); i++) {
          std::cout << "    ";
        }
        std::cout << "/";
        for (int i = 0; i <= (max_lvl + 1 - curr_lvl); i++) {
          std::cout << "    ";
        }
        std::cout << "\\";
      }
    }
  }

  std::cout << "" << std::endl;
}

void print_vector(std::vector<int> vec) {
  for (int a : vec) {
    std::cout << "|" << a << "|";
  }
  std::cout << "\n";
}

void print_piramid_TEST(void) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
  int vsize = vec.size();
  for (int i = 0; i < vsize; i++) {
    for (int j = 0; j < vsize - i; j++) {
      std::cout << "\t";
    }
    std::cout << vec.at(i) << std::endl;
  }
}

int main() {

  // print_piramid_TEST();

  // std::vector<int> v(myints, myints + 5);
  std::vector<int> v = {1, 3, 5, 6, 8, 10};
  // print_heap("Initial Heap Vector: ", v);
  std::make_heap(v.begin(), v.end());
  print_vector(v);
  // std::cout << "initial max heap   : " << v.front() << '\n';
  print_heap("Initial max heap Vector: ", v);
  std::cout << '\n';
  return 0;
}