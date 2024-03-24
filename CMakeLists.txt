cmake_minimum_required(VERSION 3.26)
project(Programiranje2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Naloga0101 Naloga01/Naloga0101/naloga0101.cpp) #Tukaj dodas header file v oklepaj npr: add_executable(Programiranje2 main.cpp main.h)

add_executable(Naloga0102 Naloga01/Naloga0102/naloga0102.cpp)
add_executable(Naloga0201 Naloga02/Naloga0201/Event.cpp Naloga02/Naloga0201/Event.h
        Naloga02/Naloga0201/naloga0201.cpp)
add_executable(Naloga0202 Naloga02/Naloga0202/naloga0202.cpp
        Naloga02/Naloga0202/Expense.cpp
        Naloga02/Naloga0202/Expense.h)
add_executable(Naloga0301 Naloga03/Naloga0301/Date.cpp Naloga03/Naloga0301/Date.h
        Naloga03/Naloga0301/naloga0301.cpp Naloga03/Naloga0302/TextUtility.h Naloga03/Naloga0302/TextUtility.cpp)
add_executable(Naloga0302 Naloga03/Naloga0302/TextUtility.cpp Naloga03/Naloga0302/TextUtility.h
        Naloga03/Naloga0302/naloga0302.cpp)
add_executable(Naloga0401
        Naloga04/Naloga0401/Date.cpp Naloga04/Naloga0401/Date.h Naloga04/Naloga0401/Event.cpp Naloga04/Naloga0401/Event.h Naloga04/Naloga0401/Location.cpp Naloga04/Naloga0401/Location.h
        Naloga04/Naloga0401/EventOrganizer.cpp
        Naloga04/Naloga0401/EventOrganizer.h
        Naloga04/Naloga0401/naloga0401.cpp
        Naloga03/Naloga0302/TextUtility.h
        Naloga03/Naloga0302/TextUtility.cpp
)
add_executable(Naloga0402
        Naloga04/Naloga0402/Date.cpp Naloga04/Naloga0402/Date.h Naloga04/Naloga0402/Event.cpp Naloga04/Naloga0402/Event.h Naloga04/Naloga0402/Location.cpp Naloga04/Naloga0402/Location.h
        Naloga04/Naloga0402/EventOrganizer.cpp
        Naloga04/Naloga0402/EventOrganizer.h
        Naloga04/Naloga0402/naloga0402.cpp
        Naloga03/Naloga0302/TextUtility.h
        Naloga03/Naloga0302/TextUtility.cpp
        Naloga04/Naloga0402/Time.cpp
        Naloga04/Naloga0402/Time.h
        Naloga04/Naloga0402/DateTime.cpp
        Naloga04/Naloga0402/DateTime.h
)
