#include <iostream>
#include <yaml-cpp/yaml.h>

int main(){
  YAML::Node yamlConfig;     
  try{
    yamlConfig= YAML::LoadFile("robot.yaml");
    auto xLimit = yamlConfig["robot_x_limit"].as<double>();
    auto yLimit = yamlConfig["robot_y_limit"].as<double>();
    auto zLimit = yamlConfig["robot_z_limit"].as<double>();
    std::cout<<"xLimit is " << xLimit;
    std::cout<<"yLimit is " << yLimit;
    std::cout<<"zLimit is " << zLimit<<std::endl;
  }
  catch(std::exception &e){
    std::cout<<"Failed to load yaml file"<<std::endl;
  }
}

