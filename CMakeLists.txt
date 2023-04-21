cmake_minimum_required(VERSION 3.20)

SET(PROJECT "ImageAnnotation")
SET(CMAKE_VERBOSE_MAKEFILE ON)

PROJECT(${PROJECT} LANGUAGES CXX)


SET( QT_ROOT "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/" )
SET( QTROOTS "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/bin" )
SET( QT5_DIR "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/lib/cmake/Qt5" )

SET(Qt5Core_DIR "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/lib/cmake/Qt5Core")
SET(QT_QMAKE_EXECUTABLE "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/bin/qmake.exe")

SET(ENV(CMAKE_PREFIX_PATH) ${QTROOTS} )
SET(CMAKE_PREFIX_PATH "$ENV{QT_ROOT}")

SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

FIND_PACKAGE (Qt5
   COMPONENTS
       Widgets Core Gui
   HINTS
       "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/lib/cmake/Qt5"
   REQUIRED
)

FIND_PACKAGE(OpenCV 
   HINTS
       "C:/Users/arathi/Downloads/opencv/build"
	REQUIRED )

INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )

FIND_PACKAGE (Qt5
   COMPONENTS
       Widgets Core Gui
   HINTS
       "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/lib/cmake/Qt5"
   REQUIRED
)

SET( NAME_SRC
    ${PROJECT_SOURCE_DIR}/src/App.cpp
    ${PROJECT_SOURCE_DIR}/src/ImageAnnotationYolo.cpp
    ${PROJECT_SOURCE_DIR}/src/MainWindow.cpp
	${PROJECT_SOURCE_DIR}/src/ImageHandler.cpp
)

SET( NAME_INCUDE
    ${PROJECT_SOURCE_DIR}/src/App.h
    ${PROJECT_SOURCE_DIR}/src/ImageAnnotationYolo.h
    ${PROJECT_SOURCE_DIR}/src/MainWindow.cpp
	${PROJECT_SOURCE_DIR}/src/ImageHandler.h
)

# QT MOC
#SET(CMAKE_AUTOMOC True)
#SET_TARGET_PROPERTIES(${PROJECT} PROPERTIES AUTOMOC TRUE)

SET(HEADERS_TO_MOC ${PROJECT_SOURCE_DIR}/src/App.h )
QT5_WRAP_CPP(PROCESSED_MOCS ${HEADERS_TO_MOC})


INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}
   ${PROJECT_SOURCE_DIR}/src/
   ${PROJECT_SOURCE_DIR}/extern/spdlog/include
)

INCLUDE_DIRECTORIES("T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/include")

ADD_EXECUTABLE(${PROJECT} ${NAME_SRC} ${PROCESSED_MOCS})

TARGET_LINK_LIBRARIES(${PROJECT} Qt5::Core )

TARGET_LINK_LIBRARIES(${PROJECT} Qt5::Widgets )

TARGET_COMPILE_FEATURES(${PROJECT} PUBLIC cxx_std_17)

TARGET_LINK_LIBRARIES( ${PROJECT} ${OpenCV_LIBS} )

SET_PROPERTY(TARGET ${PROJECT} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

SET(QPATH 
"PATH=%PATH%;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/lib;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/bin" 
"QT_PLUGIN_PATH=T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/plugins/;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/plugins/platforms/"
"QT_QPA_PLATFORM_PLUGIN_PATH=T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/plugins/platforms/;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/plugins/")

#SET(QT_PLUGIN_PATH "QT_PLUGIN_PATH=T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/plugins/platforms/" "PATH=%PATH%;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/lib;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/bin" )
#SET(ENV_PATH "QT_PLUGIN_PATH=T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/plugins/platforms/qwindows.dll" "PATH=%PATH%;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/lib;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/bin" )

SET_TARGET_PROPERTIES(${PROJECT} PROPERTIES VS_DEBUGGER_ENVIRONMENT "${QPATH}" )
SET_PROPERTY(TARGET ${PROJECT} PROPERTY VS_DEBUGGER_ENVIRONMENT 
"\nPATH=%PATH%;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/lib;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/bin"
"\nQT_PLUGIN_PATH=T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/plugins/;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/plugins/platforms/"
"\nQT_QPA_PLATFORM_PLUGIN_PATH=T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/plugins/platforms/;T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/plugins/")

install(TARGETS ${PROJECT})

#if (WIN32)
#  ADD_CUSTOM_COMMAND(
#    TARGET qcpp POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/include/external/c.dll" "${CMAKE_BINARY_DIR}"
#    COMMAND_EXPAND_LISTS
#  )
#endif()