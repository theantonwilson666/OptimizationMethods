  //#include <string>
  #include <cstddef>
  #include "ZLP.h"

  ZLP::ZLP(std::ifstream &file){
  std::string line;
  bool first_row = true;
  if ( file.is_open()){
    //std::cout << "CHECK CONSTR\n";
    while ( getline(file, line) ){
      //std::cout << "line\n";
      if (first_row){
        //std::cout << "test\n";
        ZLP::init_map_p(line);
        ZLP::init_vector_p();

        first_row = false;
      }
      break;
    }
  }
}

  void ZLP::init_map_p(std::string func){
    const char *buf = func.data();
    std::size_t npos = 0;
    std::size_t pos = 0;
    std::size_t dig_pos = 0;
    float dig_buf;
    //valid buf_c;
    //buf_c.row.reserve(1);
    std::cout << "string:" << buf << "\n";

    while (npos != std::string::npos){
      dig_pos = func.find_first_of("1234567890", dig_pos);
      if( dig_pos <= func.size() ){
        dig_buf = atoi(func.c_str() + dig_pos);
      }

      npos = func.find("x_", pos);
      if (npos != std::string::npos){
        //std::cout << "npos:" << npos << "\n";
        pos = npos+2;
        dig_pos = npos+3;
        //std::cout << "i:" << buf[pos] << ":" << dig_buf << "\n";
        map_p.insert({int(buf[pos]) - 48, dig_buf});
      }
    }

   std::cout << std::endl;
   for (auto it = map_p.begin(); it != map_p.end(); ++it)
   {
      std::cout << it->first << " : "  << it->second << "\n";
    }
  }

void ZLP::init_vector_p(){
  valid buf;
  buf.row.reserve(1);
  buf.numb = 0;
  for (int i = 1; i <= map_p.size(); i++){

    vector_p.push_back(buf);
  }
//  std::cout << vector_p.size();
}

void ZLP::handle_string_limit(std::string limit){
  const char *buf = limits.data();
  std::std::vector<float> flt_buf;
  std::size_t npos = 0;
  std::size_t pos = 0;
  std::size_t dig_pos = 0;
  float dig_buf;

  for (int i = 0; i<map_p.size(); ++i){
    
  }

/*
  while (npos != std::string::npos){
  dig_pos = limits.find_first_of("1234567890", dig_pos);
  if( dig_pos <= limits.size() ){
    dig_buf = atoi(limits.c_str() + dig_pos);
  }

  npos = limits.find("x_", pos);
    if (npos != std::string::npos){
      std::cout << "npos:" << npos << "\n";
      pos = npos+2;
      dig_pos = npos+3;
      std::cout << "i:" << buf[pos] << ":" << dig_buf << "\n";
      flt_buf.push_back(dig_buf);
    }
  }
}
  */


/*
void ZLP::init_vector_p(std::string limits){
  const char *buf = limits.data();
  std::size_t npos = 0;
  std::size_t pos = 0;
  std::size_t dig_pos = 0;
  float dig_buf;

  while (npos != std::string::npos){
  dig_pos = limits.find_first_of("1234567890", dig_pos);
  if( dig_pos <= limits.size() ){
    dig_buf = atoi(limits.c_str() + dig_pos);
  }

  npos = limits.find("x_", pos);
    if (npos != std::string::npos){
      std::cout << "npos:" << npos << "\n";
      pos = npos+2;
      dig_pos = npos+3;
      std::cout << "i:" << buf[pos] << ":" << dig_buf << "\n";
      map_p.insert({int(buf[pos]) - 48, dig_buf});
    }
  }

  }
*/
