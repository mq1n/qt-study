
find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})

qt5_add_resources(QT_RESOURCES qml.qrc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(TARGET_NAME "qml_minimal")

project(${TARGET_NAME})

if(NOT DEFINED HEADERS)
    file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
endif()

if(NOT DEFINED SOURCES)
    file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
endif()

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

add_executable(${TARGET_NAME} ${HEADERS} ${SOURCES} ${QT_RESOURCES})

target_link_libraries(${TARGET_NAME}
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick
    )

# add_custom_command(
#   TARGET ${TARGET_NAME}
#   POST_BUILD 
#   COMMAND ${Qt5BinDir}/windeployqt.exe ARGS "$<TARGET_FILE:${TARGET_NAME}>" "--qmldir" "${CMAKE_CURRENT_SOURCE_DIR}" "--no-translations"
#   VERBATIM
# )
