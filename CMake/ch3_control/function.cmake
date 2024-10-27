cmake_minimum_required(VERSION 3.30.0)

function(MyFunc FirstArg )
    message("MyFunc Name: ${CMAKE_CURRENT_FUNCTION}")
    message("FirstArg: ${FirstArg}")
    set(FirstArg "New value")
    message("FirstArg again: ${FirstArg}")
    message("ARGV0 ${ARGV0}")
    message("ARGV1 ${ARGV1}")
    message("ARGV2 ${ARGV2}")
endfunction()

set(Var "first value")
MyFunc(${Var} "value" "JOJO")   