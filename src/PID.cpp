#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	this->Kp = Kp; //proportional gain
	this->Ki = Ki; //integral gain
	this->Kd = Kd; //differential gain

	//initializing errors
	p_error = 0;
	i_error = 0;
	d_error = 0;

}

void PID::UpdateError(double cte) {

	double previous_cte = p_error; //getting previous cte

	p_error = cte; //pro
	i_error += cte;
	d_error = cte - previous_cte;


}

double PID::TotalError() {
	double steer = -Kp*p_error - Ki*i_error - Kd*d_error; //
	return steer; 
}

