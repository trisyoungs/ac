project(Aten)


set(DESCRIPTION "AtenCalc - Command-line calculator")
set(AUTHOR "Tristan Youngs")
set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_PATCH "1")

set(CMAKE_BUILD_TYPE "Release")

if(APPLE)
  cmake_minimum_required(VERSION 2.6.0)
  set(CMAKE_OSX_ARCHITECTURES "ppc;i386")
else(APPLE)
  cmake_minimum_required(VERSION 2.4.8)
endif(APPLE)

if(COMMAND cmake_policy)
  cmake_policy(VERSION 2.6)
endif(COMMAND cmake_policy)

set (target_name Aten)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
find_package(READLINE REQUIRED)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(SRCS src/)

# tell cmake to process CMakeLists.txt in that subdirectory
add_subdirectory(${SRCS})

If(APPLE)
  set(MACOSX_BUNDLE_GUI_IDENTIFIER  "AtenCalc")
  set(MACOSX_BUNDLE_LONG_VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
  set(MACOSX_BUNDLE_BUNDLE_NAME  "AtenCalc" )
  set(MACOSX_BUNDLE_SHORT_VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}")
  set(MACOSX_BUNDLE_BUNDLE_VERSION  "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
  set(MACOSX_BUNDLE_COPYRIGHT "${AUTHOR}")
endif(APPLE)

include_directories(
${CMAKE_SOURCE_DIR} 
${CMAKE_BINARY_DIR}
${CMAKE_BINARY_DIR}/src
${SRCS}/templates/
${SRCS}/
${QT_INCLUDE_DIR}
${READLINE_INCLUDE_DIR}
)

add_executable(${target_name}  MACOSX_BUNDLE
${SRCS}/main.cpp 
)

link_directories (${LIBRARY_OUTPUT_PATH})
IF(WIN32 OR APPLE)
target_link_libraries(${target_name} 
main command parser base classes
${READLINE_LIBRARY}
)
ELSE(WIN32 OR APPLE)
target_link_libraries(${target_name} 
main command parser base classes
${READLINE_LIBRARY}
)
ENDIF(WIN32 OR APPLE)
####################
####install target
####################

if(NOT ${PREFIX})
  MESSAGE("Install folder ${PREFIX}")
  set(CMAKE_INSTALL_PREFIX "${PREFIX}")
endif(NOT ${PREFIX})

if (APPLE)
  install(TARGETS ${target_name}
  BUNDLE DESTINATION .
  )
else(APPLE)
  install(TARGETS ${target_name}
      RUNTIME DESTINATION bin
   )
endif(APPLE)

if(WIN32)
  FIND_FILE(Rline readline5.dll ENV PATH)
  FIND_FILE(HRline history5.dll ENV PATH)
  install(FILES ${Rline} ${HRline} ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/icons/ac.ico
   DESTINATION bin
  )
  install(FILES ${qsvg} 
    DESTINATION bin/iconengines
  )
  install(FILES ${qsvgie} 
    DESTINATION bin/imageformats
  )
ENDIF(WIN32)

