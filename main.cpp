/*
 * Desarrollar un programa en C++ que permita insertar los elementos:
 * 10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, y 2 
 * en un heap de mínimo (es decir, el heap permite encontrar el mínimo de forma eficiente) inicialmente vacío. 
 * En cada paso, mostrar tanto la representación de árbol como la de arreglo.
 * Luego, elimine el elemento minimo del heap y muestre el árbol resultante.
*/
// Jose Agelvis 28440544
#include <algorithm> // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <iostream> // std::cout
#include <math.h>   /* ilogb */
#include <string>
#include <vector> // std::vector
void print_spaces(std::string s,int curr_lvl,int max_lvl){
    for (int tab = 0; tab <= (max_lvl - curr_lvl); tab++) {
      std::cout << "     ";
    }
}
void print_lines(int curr_lvl,int max_lvl){
    print_spaces("    ",curr_lvl,max_lvl);
    for(int l=0;l<curr_lvl;l++){
     if(l!=0){
        print_spaces("    ",curr_lvl-1,max_lvl);
     }
        std::cout << "/";
        print_spaces("    ",curr_lvl,max_lvl);
        std::cout << "\\";
    }
    std::cout << "\n";

}

void print_heap(std::string msg, std::vector<int> vec) {

  std::cout << "\t" << msg << std::endl;
  int max_lvl = ilogb(vec.size());
  int prev_lvl = 0;

  for (int i = 0; i < vec.size(); i++) {
    bool do_write_lines;
    int num = vec[i];
    int curr_lvl = ilogb(i + 1);
    // std::cout << curr_lvl;
      if(i!= 0 && (ilogb(i) - curr_lvl)!=0){
          std::cout<<"\n";
        print_lines(curr_lvl,max_lvl);
      }
    for (int tab = 0; tab <= (max_lvl - curr_lvl); tab++) {
      std::cout << "    ";
    }
    std::cout << " " << num << " ";
  }
}


void print_vector(std::vector<int> vec) {
    std::cout<< "[";
  for (int a : vec) {
    std::cout << a << ", ";
  }
    std::cout<< "]";
  std::cout << "\n";
}

void print_piramid_TEST(void) {
  std::vector<int> vec = {1, 20, 33, 40, 50, 60, 70, 8};
  int vsize = vec.size();
  for (int i = 0; i < vsize; i++) {
    for (int j = 0; j < vsize - i; j++) {
      std::cout << "\t";
    }
    std::cout << vec.at(i) << std::endl;
  }
}

int main() {
  std::cout << "init" << std::endl;
  // print_piramid_TEST();

  // std::vector<int> v(myints, myints + 5);
  std::vector<int> v = {1, 3,22,4,6,7,8,9,10,11,12,13,116};
  // print_heap("Initial Heap Vector: ", v);
  std::make_heap(v.begin(), v.end());
  print_vector(v);
  // std::cout << "initial max heap   : " << v.front() << '\n';
  print_heap("Initial max heap Vector: ", v);
  std::cout << '\n';
  std::cout << "Finished" << std::endl;
  return 0;
}