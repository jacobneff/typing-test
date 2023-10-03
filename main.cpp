#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <unistd.h>

std::string typingTest(std::string, std::chrono::duration<double>&);
void results(std::chrono::duration<double>);
void countdown();

int main() {
  using namespace std::chrono;
  
  std::string passage =
      "If I am walking with two other men, each of them will serve as my "
      "teacher. I will pick out the good points of the one and imitate them, "
      "and the bad points of the other and correct them in myself.";

  duration<double> time_span;
  
  countdown();
  std::string input = typingTest(passage, time_span);
  results(time_span);

  return 0;
}

std::string typingTest(std::string passage, std::chrono::duration<double>& time_span) {
  using namespace std::chrono;
  std::string input;
  
  steady_clock::time_point t1 = steady_clock::now();

  std::cout << passage << std::endl << std::endl;
  std::getline(std::cin, input);

  steady_clock::time_point t2 = steady_clock::now();
  time_span = duration_cast<duration<double>>(t2-t1);

  return input;
}

void results(std::chrono::duration<double> time_span) {
  std::cout << std::endl;
  
  std::cout << "It took you " << time_span.count() << " seconds to type the passage.";
  std::cout << std::endl;
}

void countdown() {
  for (int i = 3; i > 0; i--) {
    std::cout << "Begin typing in " << i << std::endl;
    sleep(1);
  }

  std::cout << std::endl << std::endl;
}
