#ifndef __PID_H
#define	__PID_H


#define pid_standard    5 
#define pid_cycle      55     //ms
#define pid_nom        0 


struct pid 
{
	float n_f;
	float standard_n;
	float standard;
  float now;
	float before;
  float sum;
	float nom;
};
	
float pid_calculate(float p,float i,float d,float fd);


#endif /* __PID_H */




