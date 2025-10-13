add_executable(Tests_run PersonTest.cpp CommandTest.cpp
        BigCommandTest.cpp
)
target_link_libraries(Tests_run DMSimLib)
