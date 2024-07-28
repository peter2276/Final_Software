cmake_minimum_required(VERSION 3.5)

project(Widgets VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/casa.rc")
    qt_add_executable(Widgets
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/alarm.h src/alarm.cpp
        src/heater.h src/heater.cpp
        src/light.h src/light.cpp
        src/controller.h
        src/systemmanager.h src/systemmanager.cpp
        src/port.h src/port.cpp

        src/utility.h src/utility.cpp





        src/dialogonetext.h src/dialogonetext.cpp src/dialogonetext.ui
        src/dialogtwotexts.h src/dialogtwotexts.cpp src/dialogtwotexts.ui
        src/arduinouno.h src/arduinouno.cpp
        src/alarm.cpp src/alarm.h src/arduinouno.cpp src/arduinouno.h src/controller.h src/dialogonetext.cpp src/dialogonetext.h src/dialogonetext.ui src/dialogtwotexts.cpp src/dialogtwotexts.h src/dialogtwotexts.ui src/heater.cpp src/heater.h src/light.cpp src/light.h src/main.cpp src/mainwindow.cpp src/mainwindow.h src/mainwindow.ui src/port.cpp src/port.h src/systemmanager.cpp src/systemmanager.h src/utility.cpp src/utility.h
        favicon.rc

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Widgets APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Widgets SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Widgets
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Widgets PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Widgets)
endif()
set_target_properties(Widgets PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Widgets
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Widgets)
endif()
