#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  // using twiddel in lecture's robot simulation
  //self.Kp_ = 2.9331227688652457;
  //self.Ki_ = 10.326589894591526;
  //self.Kd_ = 0.49316041639454505;
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;
  
  this->p_error = 0.0;
  this->i_error = 0.0;
  this->d_error = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  this->d_error = cte - this->p_error; // differential gain
  this->p_error = cte; //Previous cte for propotional gain
  this->i_error += cte; // sum of cte for integral gain
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double totalError = - (this->Kp * this->p_error - this->Ki * this->i_error - this->Kd * this->d_error);
  if(totalError > 1) return 1;
  else if (totalError < -1) return -1;
  return totalError;  // TODO: Add your total error calc here!
}