add_executable(testing pch.cpp test.cpp)


target_link_libraries(testing math_part gtest_main)


#target_include_directories(testing PUBLIC "D:/BETA/tehn_progr/labv_2/googletest-main/googletest/include")




#target_link_directories(testing PUBLIC "D:/BETA/Tehn_progr/labv_2/googletest-main/build/lib/Debug")
