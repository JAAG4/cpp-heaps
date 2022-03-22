/*
 * Desarrollar un programa en C++ que permita insertar los elementos:
 * 10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, y 2
 * en un heap de mínimo (es decir, el heap permite encontrar el mínimo de forma eficiente) inicialmente vacío.
 * En cada paso, mostrar tanto la representación de árbol como la de arreglo.
 * Luego, elimine el elemento minimo del heap y muestre el árbol resultante.
 */
// Jose Agelvis 28440544
// https://www.cplusplus.com/reference/queue/priority_queue/priority_queue/
// https://www.geeksforgeeks.org/implement-min-heap-using-stl/

//#include <algorithm> // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <math.h>   /* ilogb */
#include <iostream> // std::cout
#include <string>
#include <vector>     // std::vector
#include <queue>      // std::priority_queue
#include <functional> // std::greater

void print_spaces(std::string s, int curr_lvl, int max_lvl)
{
  for (int tab = 0; tab <= (max_lvl - curr_lvl); tab++)
  {
    std::cout << "     ";
  }
}

void print_lines(int curr_lvl, int max_lvl)
{
  print_spaces("    ", curr_lvl, max_lvl);
  for (int l = 0; l < curr_lvl; l++)
  {
    if (l != 0)
    {
      print_spaces("    ", curr_lvl - 1, max_lvl);
    }
    std::cout << "/";
    print_spaces("    ", curr_lvl, max_lvl);
    std::cout << "\\";
  }
  std::cout << "\n";
}

void print_heap(std::string msg, std::vector<int> vec)
{

  std::cout << "\t" << msg << std::endl;
  int max_lvl = ilogb(vec.size());
  int prev_lvl = 0;

  for (int i = 0; i < vec.size(); i++)
  {
    bool do_write_lines;
    int num = vec[i];
    int curr_lvl = ilogb(i + 1);
    // std::cout << curr_lvl;
    if (i != 0 && (ilogb(i) - curr_lvl) != 0)
    {
      std::cout << "\n";
      print_lines(curr_lvl, max_lvl);
    }
    for (int tab = 0; tab <= (max_lvl - curr_lvl); tab++)
    {
      std::cout << "    ";
    }
    std::cout << " " << num << " ";
  }
}

void print_vector(std::vector<int> vec)
{
  std::cout << "[";
  for (int a : vec)
  {
    std::cout << a << ", ";
  }
  std::cout << "]";
  std::cout << "\n";
}

void print_minheap(std::priority_queue<int, std::vector<int>, std::greater<int>> prio_queue) {}

int main()
{
  std::cout << "init" << std::endl;

  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  print_vector(v);

  std::priority_queue<int, std::vector<int>, std::greater<int>> prio_queue(v.begin(), v.end());

  bool do_loop = false;

  char in;
  do
  {
    try
    {
      std::cout << "Choose Option: \n a)Insert Number \n b)End and Pop Element" << std::endl;
      std::cin >> in;
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }
    if (in == 'a')
    {
      int num_in;
      try
      {
        std::cin >> num_in;
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
      }
      v.push_back(num_in);
      print_vector(v);

      std::priority_queue<int, std::vector<int>, std::greater<int>> prio_queue(v.begin(), v.end());
      print_minheap(prio_queue);
    }
    if (in == 'b')
    {
      do_loop = false;
    }
  } while (do_loop);

  // Pop Element
  prio_queue.pop();
  std::cout << "Popped Element" << std::endl;

  // Print Vector
  std::vector<int> final_vector;
  while (prio_queue.size())
  {
    prio_queue.pop();
    int num = prio_queue.top();
    final_vector.push_back(num);
  }
  print_vector(final_vector);

  // Print queue
  std::priority_queue<int, std::vector<int>, std::greater<int>> prio_queue(final_vector.begin(), final_vector.end());
  print_minheap(prio_queue);
  std::cout << "Finished" << std::endl;
  return 0;
}