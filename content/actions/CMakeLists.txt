add_library(actions
  rest.cpp
  move.cpp
        opendoor.cpp
        closedoor.cpp
        wander.cpp
        attack.cpp
        use_item.cpp
)

target_include_directories(actions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(actions PUBLIC engine events)
