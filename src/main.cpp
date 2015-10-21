#include <ros/ros.h>
// #include <boost/thread.hpp>
#include "../include/mqtt_drive_base/mqttDriveBase.hpp"


int main(int argc, char** argv)
{
   	MqttBase mqttBase(argc, argv);
   	ros::Rate r(1);
   	ros::spin();
   	// boost::thread mthread(&mqttBase.keyDetect);
  	// while(ros::ok()) {

  	// }
  	// mthread.join();
 	return(0);
}