add_library(items
  bite.cpp
        big_sword.cpp
        knife.cpp
        spiked_club.cpp
        healing_potion.cpp
        splash_potion.cpp
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
