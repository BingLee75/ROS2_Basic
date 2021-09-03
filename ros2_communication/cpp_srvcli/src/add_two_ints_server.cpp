#include "rclcpp/rclcpp.hpp"
#include "my_interfaces/srv/add_two_ints.hpp"     // CHANGE

#include <memory>

void add(const std::shared_ptr<my_interfaces::srv::AddTwoInts::Request> request,     // CHANGE
          std::shared_ptr<my_interfaces::srv::AddTwoInts::Response>       response)  // CHANGE
{
  response->sum = request->a + request->b;                                       // CHANGE
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",   // CHANGE
                request->a, request->b);                                          // CHANGE
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_server");  // CHANGE

  rclcpp::Service<my_interfaces::srv::AddTwoInts>::SharedPtr service =                 // CHANGE
    node->create_service<my_interfaces::srv::AddTwoInts>("add_two_ints",  &add);     // CHANGE

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");      // CHANGE

  rclcpp::spin(node);
  rclcpp::shutdown();
}