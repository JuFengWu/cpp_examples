
#include"tm_move_api.h"
#include <map>
namespace techman_robot{
  
  
  void RobotRecordPoint::record_position(std::string positionName,std::vector<float> position){
    if(this->is_input_number_correct(position)){
	this->positions.insert(std::pair<std::string, std::vector<float> >(positionName,position));
      }
      else{
        throw "cartesian number is not correct\n";
    }
  }
  bool RobotRecordPoint::findPosition(std::string positionName, std::vector<float> position){
    std::map<std::string, std::vector<float> >::iterator foundPosition;
    foundPosition = positions.find(positionName);
    if(foundPosition != positions.end()){
      position = foundPosition->second;
      return true;
    }
    else{
      return false;
    }
  }
  bool RobotRecordPoint::move_recorded_position(std::string positionName, bool isPlan){
    std::vector<float> position;
    if(findPosition(positionName,position)){
      _robot->cartesian_move(position,isPlan);
      return true;
    }
    else{
      return false;
    }
  }
  
  std::map<std::string,std::vector<float> > RobotRecordPoint::get_recorded_position(){
    std::map<std::string,std::vector<float> > re(positions);
    
    return re;
  }
  bool RobotRecordPoint::delete_recorded_poisitons(std::string positionName){
    std::vector<float> position;
    if(findPosition(positionName,position)){
      positions.erase(positionName);
      return true;
    }
    else{
      return false;
    }
  }
  void RobotRecordPoint::delete_all_recorded_positions(){
    positions.erase(positions.begin(),positions.end());
  }
  bool RobotRecordJoints::is_input_number_correct(std::vector<float> input){
    if(input.size()!=(unsigned int)_robot->get_joint_number()){
      return false;
    }
    return true;
  }
   bool RobotRecordCartesianPositions::is_input_number_correct(std::vector<float> input){
    if(input.size()!= (unsigned int)_robot->get_cartesian_number()){
      return false;
    }
    return true;
  }
  
  void RobotPointControl::record_position_joint(std::string positionName,std::vector<float> jointPosition){
    jointPositions.record_position(positionName,jointPosition);
    
  }
  void RobotPointControl::record_position_cartesian(std::string positionName,std::vector<float> cartesianPosition){
    cartesianPositions.record_position(positionName,cartesianPosition);
  }
    
  void RobotPointControl::move_recorded_poisiton(std::string positionName,bool isPlan){
    if(jointPositions.move_recorded_position(positionName,isPlan)){
      
    }
    else if(!cartesianPositions.move_recorded_position(positionName,isPlan)){
        
    }
    else{
      throw "the position is not exist!";
    }
  }
  void RobotPointControl::move_recorded_joint_poisiton(std::string positionName,bool isPlan){
    if(!jointPositions.move_recorded_position(positionName,isPlan)){
      throw "the position is not exist!";
    }
  }
  void RobotPointControl::move_recorded_cartesian_poisiton(std::string positionName,bool isPlan){
    if(!cartesianPositions.move_recorded_position(positionName,isPlan)){
      throw "the position is not exist!";
    }
  }
  std::map<std::string,std::vector<float> > RobotPointControl::get_two_position(RobotRecordPoint* first, RobotRecordPoint* second){
    std::map<std::string,std::vector<float> > re(first->get_recorded_position());
    re.insert(second->get_recorded_position().begin(),second->get_recorded_position().end());
    return re;
  }
  std::map<std::string,std::vector<float> > RobotPointControl::get_all_recorded_position(bool isJointShowFirst){
    
    if(isJointShowFirst){
      return get_two_position(&jointPositions,&cartesianPositions);
    }
    else{
      return get_two_position(&cartesianPositions,&jointPositions);
    }
  }
  std::map<std::string,std::vector<float> > RobotPointControl::get_recorded_joint_position(){
    return jointPositions.get_recorded_position();
  }
  std::map<std::string,std::vector<float> > RobotPointControl::get_recorded_cartesian_position(){
    return cartesianPositions.get_recorded_position();
  }

  bool RobotPointControl::delete_recorded_poisiton(std::string positionName){
    if(jointPositions.delete_recorded_poisitons(positionName)){
      return true;  
    }
    else if(cartesianPositions.delete_recorded_poisitons(positionName)){
      return true;
    }
    else{
      return false;
    }
  }
  bool RobotPointControl::delete_recorded_joint_poisiton(std::string positionName){
    return jointPositions.delete_recorded_poisitons(positionName);
  }
  bool RobotPointControl::delete_recorded_cartesian_poisiton(std::string positionName){
    return cartesianPositions.delete_recorded_poisitons(positionName);
  }

  void RobotPointControl::delete_all_recorded_position(std::string positionName){
    jointPositions.delete_all_recorded_positions();
    cartesianPositions.delete_all_recorded_positions();
  }
  void RobotPointControl::delete_all_recorded_joint_poisiton(std::string positionName){
    jointPositions.delete_all_recorded_positions();
  }
  void RobotPointControl::delete_all_recorded_cartesian_poisiton(std::string positionName){
    cartesianPositions.delete_all_recorded_positions();
  }
}