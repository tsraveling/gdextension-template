
#ifndef EXAMPLE_ENTITY_H
#define EXAMPLE_ENTITY_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/ref_counted.hpp>

using namespace godot;

class ExampleEntity : public RefCounted {
  // In Godot's context, this says that this class will be called
  // "ExampleEntity" and will descent from Godot's "RefCounted" (aka, not a
  // node, but still garbage collected) type.
  GDCLASS(ExampleEntity, RefCounted)

protected:
  static void _bind_methods(); // This is the method that will set up the
                               // interface between this class and Godot's code

public:
  // This is a useful C++ enum. You can use it like normal within c++, but if
  // you want to expose it to Godot's interface, use VARIANT_ENUM_CAST as seen
  // at the bottom of this file, and then bind each enum as seen in
  // _bind_methods in ExampleEntity.cpp.
  enum ExampleEnum {
    LIGHT = 0,
    DARK = 1,
  };

  String entity_name; // We will make this accessible from Godot

  bool get_opposite(bool val); // This will be callable from Godot

  // Getter and setter for entity_name
  String get_entity_name() const;
  void set_entity_name(String new_name);

  // Constructor and destructor
  ExampleEntity();
  ~ExampleEntity();
};

// You must do this in order to communicate a C++ enum to standard ints that you
// can then use within Godot.
VARIANT_ENUM_CAST(ExampleEntity::ExampleEnum);

#endif // EXAMPLE_ENTITY_H
