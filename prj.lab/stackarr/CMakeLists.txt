add_library(stackarr stackarr.cpp stackarr.hpp)

set_property(TARGET stackarr PROPERTY CXX_STANDARD 20)

target_include_directories(stackarr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(stackarr complex)
install(TARGETS stackarr)
