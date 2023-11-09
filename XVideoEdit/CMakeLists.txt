cmake_minimum_required(VERSION 3.5)

project(XVideoEdit VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#opencv
set(OpenCV_DIR /usr/lib/opencv4)
include_directories(${OpenCV_INCLUDE_DIRS})
find_package(OpenCV REQUIRED)
#end


find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets OpenGLWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets)

set(PROJECT_SOURCES
        XVideoUI.qrc
        src/main.cpp
        src/xvideoui.cpp
        src/xvideoui.h
        src/xvideoui.ui
        src/xvideowidget.h
        src/xvideowidget.cpp
        src/xvideothread.h
        src/xvideothread.cpp
        src/XImagePro.h
        src/XImagePro.cpp
        src/XFilter.h
        src/XFilter.cpp
        src/XAudio.h
        src/XAudio.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(XVideoEdit
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET XVideoEdit APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(XVideoEdit SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(XVideoEdit
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# opencv
link_directories(${OpenCV_LIBRARY_DIRS})
#

target_link_libraries(XVideoEdit PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGLWidgets ${OpenCV_LIBS})

set_target_properties(XVideoEdit PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS XVideoEdit
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(XVideoEdit)
endif()
