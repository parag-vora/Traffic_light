cmake_minimum_required(VERSION 3.16)

project(Traffic_light VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appTraffic_light
    main.cpp
)

qt_add_qml_module(appTraffic_light
    URI Traffic_light
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES trafficlightcontroller.h trafficlightcontroller.cpp
)

# Specify QML Import Path
# set_property(TARGET appTraffic_light PROPERTY QT_QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/qml")

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTraffic_light PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTraffic_light
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)



target_link_libraries(appTraffic_light
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appTraffic_light
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


