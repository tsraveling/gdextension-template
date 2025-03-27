
#ifndef EXAMPLE_ENTITY_H
#define EXAMPLE_ENTITY_H

#include "godot_cpp/classes/ref.hpp"
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

#endif // EXAMPLE_ENTITY_H
