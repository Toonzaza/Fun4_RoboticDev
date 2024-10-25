// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fun4_interfaces:srv/Mode.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__MODE__BUILDER_HPP_
#define FUN4_INTERFACES__SRV__DETAIL__MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fun4_interfaces/srv/detail/mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fun4_interfaces
{

namespace srv
{

namespace builder
{

class Init_Mode_Request_z
{
public:
  explicit Init_Mode_Request_z(::fun4_interfaces::srv::Mode_Request & msg)
  : msg_(msg)
  {}
  ::fun4_interfaces::srv::Mode_Request z(::fun4_interfaces::srv::Mode_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fun4_interfaces::srv::Mode_Request msg_;
};

class Init_Mode_Request_y
{
public:
  explicit Init_Mode_Request_y(::fun4_interfaces::srv::Mode_Request & msg)
  : msg_(msg)
  {}
  Init_Mode_Request_z y(::fun4_interfaces::srv::Mode_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Mode_Request_z(msg_);
  }

private:
  ::fun4_interfaces::srv::Mode_Request msg_;
};

class Init_Mode_Request_x
{
public:
  explicit Init_Mode_Request_x(::fun4_interfaces::srv::Mode_Request & msg)
  : msg_(msg)
  {}
  Init_Mode_Request_y x(::fun4_interfaces::srv::Mode_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Mode_Request_y(msg_);
  }

private:
  ::fun4_interfaces::srv::Mode_Request msg_;
};

class Init_Mode_Request_mode
{
public:
  Init_Mode_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mode_Request_x mode(::fun4_interfaces::srv::Mode_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_Mode_Request_x(msg_);
  }

private:
  ::fun4_interfaces::srv::Mode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fun4_interfaces::srv::Mode_Request>()
{
  return fun4_interfaces::srv::builder::Init_Mode_Request_mode();
}

}  // namespace fun4_interfaces


namespace fun4_interfaces
{

namespace srv
{

namespace builder
{

class Init_Mode_Response_state
{
public:
  Init_Mode_Response_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::fun4_interfaces::srv::Mode_Response state(::fun4_interfaces::srv::Mode_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fun4_interfaces::srv::Mode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::fun4_interfaces::srv::Mode_Response>()
{
  return fun4_interfaces::srv::builder::Init_Mode_Response_state();
}

}  // namespace fun4_interfaces

#endif  // FUN4_INTERFACES__SRV__DETAIL__MODE__BUILDER_HPP_
