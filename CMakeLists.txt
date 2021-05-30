cmake_minimum_required(VERSION 3.18 )

set(VCPKG_FEATURE_FLAGS "versions")

project(test CXX)

file(GLOB IMGUI_HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "imgui/*.h")
file(GLOB IMGUI_HPP_HEADERS_HPP RELATIVE "${CMAKE_SOURCE_DIR}" "imgui/*.hpp")
list(APPEND IMGUI_HEADERS ${IMGUI_HPP_HEADERS})
list(APPEND IMGUI_HEADERS_FOR_GLFW ${IMGUI_HEADERS} "imgui/backends/imgui_impl_glfw.h" "imgui/backends/imgui_impl_opengl3.h")

file(GLOB IMGUI_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "imgui/*.cpp")
list(APPEND IMGUI_SOURCES_FOR_GLFW ${IMGUI_SOURCES} "imgui/backends/imgui_impl_glfw.cpp" "imgui/backends/imgui_impl_opengl3.cpp")


message(${CMAKE_SOURCE_DIR})
foreach(TEMPITEM ${IMGUI_HEADERS_FOR_GLFW})
	message(STATUS ${TEMPITEM})
endforeach()
foreach(TEMPITEM ${IMGUI_SOURCES_FOR_GLFW})
	message(STATUS ${TEMPITEM})
endforeach()

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

add_executable(testexe
	${IMGUI_HEADERS_FOR_GLFW}
	${IMGUI_SOURCES_FOR_GLFW}
	main.cpp
)

target_include_directories(testexe PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/imgui")
target_include_directories(testexe PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_sources(testexe
PUBLIC 
	"include/ydb/Application.h"
)

target_sources(testexe
PRIVATE
	Application.cpp
)

target_link_libraries(testexe PRIVATE glfw)
target_link_libraries(testexe PRIVATE glad::glad)



