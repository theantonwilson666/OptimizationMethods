#ifndef ZLP_H
#define ZLP_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

struct valid{
  std::vector<float> row;
  int numb;
};

class ZLP {
  public:
    ZLP(std::ifstream &file);
    //void set_obj_func(std::string obj_func);
    void set_limitations(std::string limit); // сделать чтение из файла, чтобы не заебно было
    void show_simplex_table(); // вывести по красоте
    void show_function();
    void show_matrix_A();

  private:
    std::map<int, float> map_p; // переменная/коэф;
    std::vector<valid> vector_p; // массив векторов P(коэф в ограничениях)
    std::vector<valid> reference_plan; // массив опорных векторов
    void chr_diff(); // характеристическая разность
    int curr_row; // текущая итерация/строка в таблице ??
    void init_map_p(std::string func);
    void init_vector_p();
    void handle_string_limit(std::string limit);

};

#endif
