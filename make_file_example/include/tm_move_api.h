#pragma once
#include<vector>
#include<string>
#include <map>
#include<iostream>
namespace techman_robot{
  class RobotMove{

  private:

  protected:
    std::string _robotName;
  public:
    RobotMove(std::string robotName): _robotName(robotName){};
    int get_cartesian_number(){return 6;}
    virtual bool joint_move(std::vector<float> jointTarget, bool isPlan)=0;
    virtual bool cartesian_move(std::vector<float> cartesianTarget, bool isPlan)=0;

    virtual int get_joint_number()=0;
  };
  
  class RobotRecordPoint{
  private:
    std::map<std::string,std::vector<float> > positions;
    bool findPosition(std::string positionName, std::vector<float> position);
  protected:
    virtual bool is_input_number_correct(std::vector<float> input)=0;
    RobotMove* _robot;
  public:
    RobotRecordPoint(RobotMove* robot):_robot(robot){};
    void record_position(std::string positionName,std::vector<float> position);
    bool move_recorded_position(std::string positionName,bool isPlan);
    std::map<std::string,std::vector<float> >get_recorded_position();
    bool delete_recorded_poisitons(std::string positionName);
    void delete_all_recorded_positions();
  };
  
  class RobotRecordJoints : public RobotRecordPoint{
  protected:
    bool is_input_number_correct(std::vector<float> input) override;
  public:
    RobotRecordJoints(RobotMove* robot):RobotRecordPoint(robot){};
  };
  
  class RobotRecordCartesianPositions : public RobotRecordPoint{
  protected:
    bool is_input_number_correct(std::vector<float> input) override;
  public:
    RobotRecordCartesianPositions(RobotMove* robot):RobotRecordPoint(robot){};
  };
  
  class RobotPointControl{
  private:
    RobotMove* _robot;
    RobotRecordJoints jointPositions;
    RobotRecordCartesianPositions cartesianPositions;
    
    std::map<std::string,std::vector<float> > get_two_position(RobotRecordPoint* first, RobotRecordPoint* second);
  public:
    RobotPointControl(RobotMove* robot):_robot(robot),jointPositions(robot),cartesianPositions(robot){};
    void record_position_joint(std::string positionName,std::vector<float> jointPosition);
    void record_position_cartesian(std::string positionName,std::vector<float> cartesianPosition);
    
    void move_recorded_poisiton(std::string positionName,bool isPlan);
    void move_recorded_joint_poisiton(std::string positionName,bool isPlan);
    void move_recorded_cartesian_poisiton(std::string positionName,bool isPlan);

    std::map<std::string,std::vector<float> > get_all_recorded_position(bool isJointShowFirst);
    std::map<std::string,std::vector<float> > get_recorded_joint_position();
    std::map<std::string,std::vector<float> > get_recorded_cartesian_position();

    bool delete_recorded_poisiton(std::string positionName);
    bool delete_recorded_joint_poisiton(std::string positionName);
    bool delete_recorded_cartesian_poisiton(std::string positionName);

    void delete_all_recorded_position(std::string positionName);
    void delete_all_recorded_joint_poisiton(std::string positionName);
    void delete_all_recorded_cartesian_poisiton(std::string positionName);   
  };
}
