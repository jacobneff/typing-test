#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

int main() {
  using namespace std::chrono;
  
  std::string passage =
      "If I am walking with two other men, each of them will serve as my "
      "teacher. I will pick out the good points of the one and imitate them, "
      "and the bad points of the other and correct them in myself.";

  std::string test;
  
  steady_clock::time_point t1 = steady_clock::now();

  std::cout << passage << std::endl << std::endl;
  std::cin >> test;

  steady_clock::time_point t2 = steady_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(t2-t1);

  std::cout << "It took you " << time_span.count() << " seconds to type the passage.";
  std::cout << std::endl;

  return 0;
}
