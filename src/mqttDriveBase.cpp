
#include "../include/mqtt_drive_base/mqttDriveBase.hpp"
#include <termios.h>  

MqttBase::MqttBase(int argc, char** argv) {
  ros::init(argc, argv, "mqtt_drive_base");
  if ( ! ros::master::check() ) {
    ROS_DEBUG("ROS master is not ready!");
    quit();
  }
  //ros::start(); // explicitly needed since our nodehandle is going out of scope.
  ros::NodeHandle n;
  // Add your ros communications here.
  commandSender = n.advertise<std_msgs::String>("/test", 10);
  chatterpublisher = n.advertise<std_msgs::String>("chatter", 1000);
  openhabSubscriber = n.subscribe("openhab_updates", 10, &MqttBase::openhabCB, this);
}

void MqttBase::keyDetect() {
  static struct termios oldt, newt;
  tcgetattr( STDIN_FILENO, &oldt);           // save old settings
  newt = oldt;
  newt.c_lflag &= ~(ICANON);                 // disable buffering      
  tcsetattr( STDIN_FILENO, TCSANOW, &newt);  // apply new settings

  int c = getchar();  // read character (non-blocking)

  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
  ROS_INFO("get a key %d", c);
  switch(c) {
    case KEYCODE_I:
      sendCommand("a");
      break;
    case KEYCODE_COMMA:
      sendCommand("b");
      break;
    case KEYCODE_J:
      sendCommand("c");
      break;
    case KEYCODE_L:
      sendCommand("d");
      break;
    case KEYCODE_K:
      sendCommand("e");
      break;
    case KEYCODE_ESC:
      quit();
      break;
  }
}

void MqttBase::quit() {
  ros::shutdown();
  exit(0);
}

void MqttBase::sendCommand(const std::string &message) {
  std_msgs::String msg;
  msg.data = message;//ss.str();
  commandSender.publish(msg);
}


void MqttBase::openhabCB(const diagnostic_msgs::KeyValue& msg) {
  // ROS_DEBUG(msg.key);
  // ROS_DEBUG(msg.value);
  if(msg.key == "Robot_Command") {
    if(msg.value == "1") {
      sendCommand("a");
      ROS_INFO("forward");
    }
    else if(msg.value == "2") {
      sendCommand("b");
      ROS_INFO("backward");
    }
    else if(msg.value == "3") {
      sendCommand("c");
      ROS_INFO("left");
    }
    else if(msg.value == "4") {
      sendCommand("d");
      ROS_INFO("right");
    }
    else if(msg.value == "5") {
      sendCommand("e");
      ROS_INFO("stop");
    }
    else {
      ROS_INFO("get others");
    }
  } 
}
