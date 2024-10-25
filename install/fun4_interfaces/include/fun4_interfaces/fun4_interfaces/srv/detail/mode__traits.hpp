// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fun4_interfaces:srv/Mode.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__MODE__TRAITS_HPP_
#define FUN4_INTERFACES__SRV__DETAIL__MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fun4_interfaces/srv/detail/mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace fun4_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Mode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mode_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace fun4_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fun4_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fun4_interfaces::srv::Mode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  fun4_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fun4_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const fun4_interfaces::srv::Mode_Request & msg)
{
  return fun4_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<fun4_interfaces::srv::Mode_Request>()
{
  return "fun4_interfaces::srv::Mode_Request";
}

template<>
inline const char * name<fun4_interfaces::srv::Mode_Request>()
{
  return "fun4_interfaces/srv/Mode_Request";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::Mode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<fun4_interfaces::srv::Mode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<fun4_interfaces::srv::Mode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'state'
#include "std_msgs/msg/detail/string__traits.hpp"

namespace fun4_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Mode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    to_flow_style_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state:\n";
    to_block_style_yaml(msg.state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mode_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace fun4_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use fun4_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fun4_interfaces::srv::Mode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  fun4_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fun4_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const fun4_interfaces::srv::Mode_Response & msg)
{
  return fun4_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<fun4_interfaces::srv::Mode_Response>()
{
  return "fun4_interfaces::srv::Mode_Response";
}

template<>
inline const char * name<fun4_interfaces::srv::Mode_Response>()
{
  return "fun4_interfaces/srv/Mode_Response";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::Mode_Response>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::String>::value> {};

template<>
struct has_bounded_size<fun4_interfaces::srv::Mode_Response>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::String>::value> {};

template<>
struct is_message<fun4_interfaces::srv::Mode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fun4_interfaces::srv::Mode>()
{
  return "fun4_interfaces::srv::Mode";
}

template<>
inline const char * name<fun4_interfaces::srv::Mode>()
{
  return "fun4_interfaces/srv/Mode";
}

template<>
struct has_fixed_size<fun4_interfaces::srv::Mode>
  : std::integral_constant<
    bool,
    has_fixed_size<fun4_interfaces::srv::Mode_Request>::value &&
    has_fixed_size<fun4_interfaces::srv::Mode_Response>::value
  >
{
};

template<>
struct has_bounded_size<fun4_interfaces::srv::Mode>
  : std::integral_constant<
    bool,
    has_bounded_size<fun4_interfaces::srv::Mode_Request>::value &&
    has_bounded_size<fun4_interfaces::srv::Mode_Response>::value
  >
{
};

template<>
struct is_service<fun4_interfaces::srv::Mode>
  : std::true_type
{
};

template<>
struct is_service_request<fun4_interfaces::srv::Mode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<fun4_interfaces::srv::Mode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FUN4_INTERFACES__SRV__DETAIL__MODE__TRAITS_HPP_
