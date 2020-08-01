#include "stm32f10x.h"
#include "pid.h"

extern 	float pid_feedback;


struct pid pid_class={0,0,pid_standard,0,0,0,pid_nom};

float pid_calculate(float p,float i,float d,float fd)
{
//	float pid_p,pid_i,pid_d;
  float out;
	pid_class.standard=pid_standard;
  pid_class.now =fd;
	pid_class.n_f=pid_class.now-pid_class.before;   //前后两次的差值
	pid_class.standard_n=pid_class.standard-pid_class.now;  //当前次距离标准值的差值
  pid_class.sum=pid_class.sum+pid_class.standard_n;        // 历史总量
//  pid_p=p*pid_class.standard_n;
//	pid_i=i*pid_class.sum*0.003;
//  pid_d=d*pid_class.n_f*(-1.0)/0.003 ;
	out=p*(pid_class.standard_n+(1/i)*(pid_class.sum*0.003)+(pid_class.n_f*(-1.0)/0.003)*d);
  pid_class.before=pid_class.now;
	//这里应该加一些延时
	
//	return (pid_p+pid_i+pid_d+pid_class.nom);
	return out;  
}



