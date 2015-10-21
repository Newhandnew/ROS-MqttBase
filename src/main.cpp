#include <ros/ros.h>
#include <boost/thread.hpp>
#include "../include/mqtt_drive_base/mqttDriveBase.hpp"

void rosSpin(void) {
	ros::spin();
}


int main(int argc, char** argv)
{
   	MqttBase mqttBase(argc, argv);
   	ros::Rate r(10);
   	boost::thread mthread(&rosSpin);
  	while(ros::ok()) {
  		mqttBase.keyDetect();
  	}
  	mthread.join();
 	return(0);
}