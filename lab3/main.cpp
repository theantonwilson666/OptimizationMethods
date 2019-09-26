#include "iostream"
#include <fstream>
#include "ZLP.h"


int main (){
  std::ifstream file;
  file.open("INPUT.txt");
  if (file.is_open() == true) {
    //std::cout << "test\n";
    ZLP task(file);
//    free(task);
  }

  std::cout << "ffff" << std::endl;
  return 0;
}
