# The Flutter tooling requires that developers have CMake 3.10 or later
# installed. You should not increase this version, as doing so will cause
# the plugin to fail to compile for some customers of the plugin.
cmake_minimum_required(VERSION 3.10)

project(lab_sound_flutter_library VERSION 0.0.1 LANGUAGES C)

add_library(lab_sound_flutter SHARED
  "lab_sound_flutter.c"
)

set_target_properties(lab_sound_flutter PROPERTIES
  PUBLIC_HEADER lab_sound_flutter.h
  OUTPUT_NAME "lab_sound_flutter"
)

target_compile_definitions(lab_sound_flutter PUBLIC DART_SHARED_LIB)
