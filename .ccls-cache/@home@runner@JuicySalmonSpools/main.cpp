/*
 * Desarrollar un programa en C++ que permita insertar los elementos:
 * 10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, y 2
 * en un heap de mínimo (es decir, el heap permite encontrar el mínimo de forma
 * eficiente) inicialmente vacío. En cada paso, mostrar tanto la representación
 * de árbol como la de arreglo. Luego, elimine el elemento minimo del heap y
 * muestre el árbol resultante.
 */
// Jose Agelvis 28440544
// https://www.cplusplus.com/reference/queue/priority_queue/priority_queue/
// https://www.geeksforgeeks.org/implement-min-heap-using-stl/

//#include <algorithm> // std::make_heap, std::pop_heap, std::push_heap,
// std::sort_heap
#include <functional> // std::greater
#include <iostream>   // std::cout
#include <math.h>     /* ilogb */
#include <queue>      // std::priority_queue
#include <string>
#include <vector> // std::vector

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
  std::cout << "\n";
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

std::vector<int> vector_from_prioq(std::priority_queue<int, std::vector<int>, std::greater<int>> prio_queue)
{
  std::vector<int> out_vec;
  while (prio_queue.size())
  {
    int num = prio_queue.top();
    out_vec.push_back(num);
    prio_queue.pop();
  }
  return out_vec;
}

int main()
{
  std::cout << "init" << std::endl;

  // std::vector<int> v = {1,13,4,10,6,9,15};
  std::vector<int> v;
  std::priority_queue<int, std::vector<int>, std::greater<int>> prio_queue;
  // print_vector(v);

  prio_queue = std::priority_queue<int, std::vector<int>, std::greater<int>>(v.begin(), v.end());

  bool do_loop = true;
  do
  {
    // for (int s = 0; s < 100; s++)
    // {
    //   std::cout << "\n";
    // } // fake clear screen
    char in = 'f';
    try
    {
      std::cout << "Choose Option: \n a)Insert Number \n b)End and Pop Element"
                << std::endl;
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
        std::cout << "Insert Number: ";
        std::cin >> num_in;
      }
      catch (const std::exception &e)
      {
        // std::cerr << e.what() << '\n';
        std::cout << "Invalid Number";
      }
      v.push_back(num_in);

      prio_queue = std::priority_queue<int, std::vector<int>, std::greater<int>>(v.begin(), v.end());
      v = vector_from_prioq(prio_queue);
      print_vector(v);
      print_heap("    ", v);
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
  final_vector = vector_from_prioq(prio_queue);
  print_vector(final_vector);

  // Print queue
  prio_queue = std::priority_queue<int, std::vector<int>, std::greater<int>>(final_vector.begin(), final_vector.end());
  final_vector = vector_from_prioq(prio_queue);
  print_heap("    ", final_vector);
  std::cout << "Finished" << std::endl;
  return 0;
}