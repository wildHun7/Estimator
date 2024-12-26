cmake_minimum_required(VERSION 3.16)

project(Estimator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

# Adding a new subfolder Items
set(ITEMS_SOURCES
        items/item.cpp
        items/item.h
        items/itemtype1.h
        items/itemtype1.cpp
        items/itemtype2.h
        items/itemtype2.cpp
)

# Adding a new subfolder Sections
set(SECTIONS_SOURCES
        sections/section.cpp
        sections/section.h
        sections/sectiontype1.h
        sections/sectiontype1.cpp
        sections/sectiontype2.h
        sections/sectiontype2.cpp
)

# Adding a new subfolder Manager
set(MANAGER_SOURCES
        manager/sectionmanager.cpp
        manager/sectionmanager.h
)

# Łączymy wszystkie źródła
list(APPEND PROJECT_SOURCES
    ${ITEMS_SOURCES}
    ${SECTIONS_SOURCES}
    ${MANAGER_SOURCES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Estimator
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

target_include_directories(Estimator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Items
    ${CMAKE_CURRENT_SOURCE_DIR}/Sections
    ${CMAKE_CURRENT_SOURCE_DIR}/Manager
)

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Estimator APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Estimator SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Estimator
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Estimator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Estimator)
endif()
set_target_properties(Estimator PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Estimator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Estimator)
endif()
