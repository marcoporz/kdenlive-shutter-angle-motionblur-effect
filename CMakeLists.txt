cmake_minimum_required(VERSION 3.16)
project(mlt-shutterblur LANGUAGES C CXX VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
find_package(PkgConfig REQUIRED)
pkg_check_modules(MLT REQUIRED IMPORTED_TARGET mlt-framework-7)
find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

add_library(mltshutterblur MODULE
    src/factory.c src/common.cpp src/common.h src/filter_transformblur.cpp)
target_link_libraries(mltshutterblur PRIVATE PkgConfig::MLT Qt6::Gui Qt6::Widgets)

pkg_get_variable(_moddir mlt-framework-7 moduledir)
pkg_get_variable(_datadir mlt-framework-7 mltdatadir)
set(MLT_MODULE_DIR "${_moddir}" CACHE PATH "MLT module directory")
set(MLT_DATA_DIR "${_datadir}" CACHE PATH "MLT data directory")
install(TARGETS mltshutterblur LIBRARY DESTINATION "${MLT_MODULE_DIR}")
install(FILES src/filter_transformblur.yml
        DESTINATION "${MLT_DATA_DIR}/shutterblur")
