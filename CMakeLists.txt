cmake_minimum_required(VERSION 3.20)

SET(PROJECT "ImageAnnotation")
SET(CMAKE_VERBOSE_MAKEFILE ON)

project(${PROJECT} LANGUAGES CXX)


SET( QT_ROOT "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/" )
SET( QTROOTS "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/bin" )
SET( QT5_DIR "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/lib/cmake/Qt5" )

SET(Qt5Core_DIR "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/lib/cmake/Qt5Core")
SET(QT_QMAKE_EXECUTABLE "T:/p4/depot/LoL/__MAIN__/code/External/Qt/5.9.1/msvc2017_64/bin/qmake.exe")

SET(ENV(CMAKE_PREFIX_PATH) ${QTROOTS} )
SET(CMAKE_PREFIX_PATH "$ENV{QT_ROOT}")

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



install(TARGETS ${PROJECT})
