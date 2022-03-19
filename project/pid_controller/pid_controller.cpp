/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   kpi_i = Kpi;
   kii_i = Kii;
   kdi_i = Kdi;
   output_lim_max_i= output_lim_maxi;
   output_lim_min_i= output_lim_mini;
   p_error=0;
   i_error=0;
   d_error=0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
   double pre_perror=perror;
   perror=cte;
   d_error= (cte-pre_perror)/ new_delta_time_i;
   i_error=i_error+(cte)*new_delta_time_i;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control;
	
	control= perror*kpi_i + d_error*kdi_i+ i_error*kii_i;
	
	control = max(output_lim_max_i,control);
	control = min (output_lim_min_i,control);
	
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
    new_delta_time_i=new_delta_time;
   
   return new_delta_time_i;
}