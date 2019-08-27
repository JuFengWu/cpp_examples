#pragma once

#include"tm_move_api.h"
#include<string>
#include<iostream>
namespace techman_robot{
  class TestRobotMoveMock : public RobotMove {
  private:
	  const int jointNumber = 6;
	  void show_robot_plan_or_move(std::string description, std::vector<float> jointTarget, bool isPlan);
  public:
	  TestRobotMoveMock(std::string robotName) : RobotMove(robotName) {};
	  bool joint_move(std::vector<float> jointTarget, bool isPlan) override;
	  bool cartesian_move(std::vector<float> cartesianTarget, bool isPlan) override;

	  int get_joint_number() override;
  };
  
}