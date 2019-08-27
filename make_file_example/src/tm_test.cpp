
#include "tm_test.h"
namespace techman_robot{
  void TestRobotMoveMock::show_robot_plan_or_move(std::string description, std::vector<float> target, bool isPlan) {
	  if (isPlan) {
		  std::cout << "robot is planing to " << description << " ";
	  }
	  else {
		  std::cout << "robot is moving to " << description << " ";
	  }
	  std::cout << description;
	  for (float joint : target) {
		  std::cout << joint;
	  }
	  std::cout << "\n";
  }
  bool TestRobotMoveMock::joint_move(std::vector<float> jointTarget, bool isPlan) {
	  show_robot_plan_or_move("joint target", jointTarget, isPlan);
	  return true;
  }
  bool TestRobotMoveMock::cartesian_move(std::vector<float> cartesianTarget, bool isPlan) {
	  show_robot_plan_or_move("cartesian target", cartesianTarget, isPlan);
	  return true;
  }
  int TestRobotMoveMock::get_joint_number() {
	  return jointNumber;
  }
}
