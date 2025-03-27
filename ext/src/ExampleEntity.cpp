#include "ExampleEntity.h"

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void ExampleEntity::_bind_methods() {

  // First, we bind our method. We say that there's one argument. And finally,
  // we bind it to a direct reference to the c++ method here in this file. Types
  // etc will be inferred when passing to Godot.
  ClassDB::bind_method(D_METHOD("get_opposite", "val"),
                       &ExampleEntity::get_opposite);

  // This is how we bind a property. Note that we explicitly need to define a
  // getter and setter, and link them in this line!
  ADD_PROPERTY(PropertyInfo(Variant::STRING, "entity_name"), "set_entity_name",
               "get_entity_name");

  // This is how you bind a signal (see get_opposite below for how to emit it)
  ADD_SIGNAL(MethodInfo("did_check_opposite",
                        PropertyInfo(Variant::BOOL, "prev_val")));

  // This is how we bind enums, so that they are useable from the Godot side:
  BIND_ENUM_CONSTANT(DARK);
  BIND_ENUM_CONSTANT(LIGHT);
}

bool ExampleEntity::get_opposite(bool val) {

  // This is how we emit a signal (must be defined above) from a C++ entity
  emit_signal(
      "did_check_opposite",
      val); // aka, prev_val on the signal will be val before we flip it, below

  return !val;
}

// Explicit getter and setter for property
String ExampleEntity::get_entity_name() const { return entity_name; }
void ExampleEntity::set_entity_name(String new_name) { entity_name = new_name; }
