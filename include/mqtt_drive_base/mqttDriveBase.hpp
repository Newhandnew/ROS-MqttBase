
#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
#include <stdio.h>
#include <diagnostic_msgs/KeyValue.h>

// #define KEYCODE_I 0x73 
// #define KEYCODE_Comma 0x188
// #define KEYCODE_J 0x74
// #define KEYCODE_L 0x76
// #define KEYCODE_K 0x75
#define KEYCODE_I 0x69
#define KEYCODE_J 0x6a
#define KEYCODE_K 0x6b
#define KEYCODE_L 0x6c
#define KEYCODE_Q 0x71
#define KEYCODE_Z 0x7a
#define KEYCODE_W 0x77
#define KEYCODE_X 0x78
#define KEYCODE_E 0x65
#define KEYCODE_C 0x63
#define KEYCODE_U 0x75
#define KEYCODE_O 0x6F
#define KEYCODE_M 0x6d
#define KEYCODE_R 0x72
#define KEYCODE_V 0x76
#define KEYCODE_T 0x74
#define KEYCODE_B 0x62

#define KEYCODE_COMMA 0x2c
#define KEYCODE_PERIOD 0x2e
#define KEYCODE_ESC 0x1B

class MqttBase {
public:
	MqttBase(int argc, char** argv);
	void keyDetect();
	void quit();



private:
	void sendCommand(const std::string &message);
  	ros::Publisher commandSender;
  	ros::Publisher chatterpublisher;
  	ros::Subscriber openhabSubscriber;
  	void openhabCB(const diagnostic_msgs::KeyValue& msg);
};