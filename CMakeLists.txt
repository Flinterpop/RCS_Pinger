cmake_minimum_required(VERSION 3.20...4.0.2) 
#cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(BuilderTest LANGUAGES CXX)

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")


include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(wxBUILD_SHARED OFF)

#message(STATUS "Fetching wxWidgets...")

FetchContent_Declare(
   wxWidgets
   GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
   GIT_SHALLOW ON
)
FetchContent_MakeAvailable(wxWidgets)



# Fetches the version of fmt that we want
#set(FMT_VERSION 11.2.0)
#FetchContent_Declare(
#    fmt
#   URL	https://github.com/fmtlib/fmt/archive/refs/tags/${FMT_VERSION}.tar.gz
#)
#FetchContent_MakeAvailable(fmt)


# Our Project
set(SOURCE_FILES
    hasMain.cpp
)


#set(SRCS hasMain.cpp)

if(APPLE)
    # create bundle on apple compiles
    add_executable(main MACOSX_BUNDLE ${SRCS})

    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    set_target_properties(main PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    # the WIN32 is needed for Windows in order for it to look for WinMain
    # instead of the main function. This is ignored on other systems,
    # so it works on all platforms
    add_executable(main WIN32 ${SOURCE_FILES} main.exe.manifest)
endif()


set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)
target_link_libraries(main PRIVATE wxcore wxnet)


