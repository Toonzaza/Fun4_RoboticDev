// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fun4_interfaces:srv/Mode.idl
// generated code does not contain a copyright notice

#ifndef FUN4_INTERFACES__SRV__DETAIL__MODE__STRUCT_HPP_
#define FUN4_INTERFACES__SRV__DETAIL__MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__fun4_interfaces__srv__Mode_Request __attribute__((deprecated))
#else
# define DEPRECATED__fun4_interfaces__srv__Mode_Request __declspec(deprecated)
#endif

namespace fun4_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Mode_Request_
{
  using Type = Mode_Request_<ContainerAllocator>;

  explicit Mode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0ll;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  explicit Mode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0ll;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  // field types and members
  using _mode_type =
    int64_t;
  _mode_type mode;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;

  // setters for named parameter idiom
  Type & set__mode(
    const int64_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fun4_interfaces::srv::Mode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const fun4_interfaces::srv::Mode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fun4_interfaces::srv::Mode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fun4_interfaces::srv::Mode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::Mode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::Mode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::Mode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::Mode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fun4_interfaces::srv::Mode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fun4_interfaces::srv::Mode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fun4_interfaces__srv__Mode_Request
    std::shared_ptr<fun4_interfaces::srv::Mode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fun4_interfaces__srv__Mode_Request
    std::shared_ptr<fun4_interfaces::srv::Mode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Mode_Request_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Mode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Mode_Request_

// alias to use template instance with default allocator
using Mode_Request =
  fun4_interfaces::srv::Mode_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fun4_interfaces


// Include directives for member types
// Member 'state'
#include "std_msgs/msg/detail/string__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fun4_interfaces__srv__Mode_Response __attribute__((deprecated))
#else
# define DEPRECATED__fun4_interfaces__srv__Mode_Response __declspec(deprecated)
#endif

namespace fun4_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Mode_Response_
{
  using Type = Mode_Response_<ContainerAllocator>;

  explicit Mode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state(_init)
  {
    (void)_init;
  }

  explicit Mode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _state_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _state_type state;

  // setters for named parameter idiom
  Type & set__state(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fun4_interfaces::srv::Mode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const fun4_interfaces::srv::Mode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fun4_interfaces::srv::Mode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fun4_interfaces::srv::Mode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::Mode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::Mode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fun4_interfaces::srv::Mode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fun4_interfaces::srv::Mode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fun4_interfaces::srv::Mode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fun4_interfaces::srv::Mode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fun4_interfaces__srv__Mode_Response
    std::shared_ptr<fun4_interfaces::srv::Mode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fun4_interfaces__srv__Mode_Response
    std::shared_ptr<fun4_interfaces::srv::Mode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Mode_Response_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const Mode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Mode_Response_

// alias to use template instance with default allocator
using Mode_Response =
  fun4_interfaces::srv::Mode_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace fun4_interfaces

namespace fun4_interfaces
{

namespace srv
{

struct Mode
{
  using Request = fun4_interfaces::srv::Mode_Request;
  using Response = fun4_interfaces::srv::Mode_Response;
};

}  // namespace srv

}  // namespace fun4_interfaces

#endif  // FUN4_INTERFACES__SRV__DETAIL__MODE__STRUCT_HPP_
