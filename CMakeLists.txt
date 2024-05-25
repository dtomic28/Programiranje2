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
add_executable(Naloga0501
        Naloga05/Naloga0501/Concert.cpp
        Naloga05/Naloga0501/Concert.h
        Naloga05/Naloga0501/Date.cpp
        Naloga05/Naloga0501/Date.h
        Naloga05/Naloga0501/Event.cpp
        Naloga05/Naloga0501/Event.h
        Naloga05/Naloga0501/EventOrganizer.cpp
        Naloga05/Naloga0501/EventOrganizer.h
        Naloga05/Naloga0501/Location.cpp
        Naloga05/Naloga0501/Location.h
        Naloga05/Naloga0501/naloga0501.cpp
        Naloga03/Naloga0302/TextUtility.cpp
        Naloga03/Naloga0302/TextUtility.h)
add_executable(Naloga0502
        Naloga05/Naloga0502/Bank.cpp
        Naloga05/Naloga0502/Bank.h
        Naloga05/Naloga0502/Account.cpp
        Naloga05/Naloga0502/Account.h
        Naloga05/Naloga0502/SavingsAccount.cpp
        Naloga05/Naloga0502/SavingsAccount.h
        Naloga05/Naloga0502/Person.cpp
        Naloga05/Naloga0502/Person.h
        Naloga05/Naloga0502/Date.cpp
        Naloga05/Naloga0502/Date.h
        Naloga05/Naloga0502/naloga0502.cpp
        Naloga03/Naloga0302/TextUtility.cpp
        Naloga03/Naloga0302/TextUtility.h)

add_executable(Naloga0601
        Naloga06/Naloga0601/Concert.cpp
        Naloga06/Naloga0601/Concert.h
        Naloga06/Naloga0601/Date.cpp
        Naloga06/Naloga0601/Date.h
        Naloga06/Naloga0601/Event.cpp
        Naloga06/Naloga0601/Event.h
        Naloga06/Naloga0601/EventOrganizer.cpp
        Naloga06/Naloga0601/EventOrganizer.h
        Naloga06/Naloga0601/Location.cpp
        Naloga06/Naloga0601/Location.h
        Naloga06/Naloga0601/naloga0601.cpp
        Naloga03/Naloga0302/TextUtility.cpp
        Naloga03/Naloga0302/TextUtility.h
        Naloga06/Naloga0601/Sponsor.cpp
        Naloga06/Naloga0601/FinancialSponsor.cpp
        Naloga06/Naloga0601/SlowFoodExpirience.cpp
        Naloga06/Naloga0601/SlowFoodExpirience.h
)
add_executable(Naloga0602 Naloga06/Naloga0602/Graph.cpp Naloga06/Naloga0602/Graph.h
        Naloga06/Naloga0602/PrintUtility.cpp
        Naloga06/Naloga0602/Histogram.cpp
        Naloga06/Naloga0602/Histogram.h
        Naloga06/Naloga0602/naloga0602.cpp)
add_executable(Naloga0701 Naloga07/Naloga0701/Point.cpp Naloga07/Naloga0701/Point.h Naloga07/Naloga0701/naloga0701.cpp
        Naloga07/Naloga0701/VectorUtil.h
)
add_executable(Naloga0702 Naloga07/Naloga0702/naloga0702.cpp Naloga07/Naloga0702/Point.cpp Naloga07/Naloga0702/Point.h Naloga07/Naloga0702/VectorUtil.h)
add_executable(Naloga0801 Naloga08/Naloga0801/naloga0801.cpp Naloga08/Naloga0801/Time.cpp Naloga08/Naloga0801/Time.h
        Naloga08/Naloga0801/PriorityQueue.h)
add_executable(Naloga0802 Naloga08/Naloga0802/naloga0802.cpp
        Naloga08/Naloga0802/CircularLinkedList.h
        Naloga08/Naloga0802/Node.h
)
add_executable(Naloga0901 Naloga09/Naloga0901/naloga0901.cpp
        Naloga09/Naloga0901/Matrix.h)
add_executable(Naloga0902 Naloga09/Naloga0902/naloga0902.cpp
        Naloga09/Naloga0902/ReferenceCounter.cpp
        Naloga09/Naloga0902/ReferenceCounter.h
        Naloga09/Naloga0902/SmartPointer.h
        Naloga09/Naloga0902/Date.cpp
        Naloga09/Naloga0902/Date.h
        Naloga03/Naloga0302/TextUtility.cpp
        Naloga03/Naloga0302/TextUtility.h
)
add_executable(Naloga1001 Naloga10/Naloga1001/naloga1001.cpp
        Naloga10/Naloga1001/Concert.cpp
        Naloga10/Naloga1001/Concert.h
        Naloga10/Naloga1001/Date.cpp
        Naloga10/Naloga1001/Date.h
        Naloga10/Naloga1001/Event.cpp
        Naloga10/Naloga1001/Event.h
        Naloga10/Naloga1001/EventOrganizer.cpp
        Naloga10/Naloga1001/EventOrganizer.h
        Naloga10/Naloga1001/Location.cpp
        Naloga10/Naloga1001/Location.h
        Naloga03/Naloga0302/TextUtility.cpp
        Naloga03/Naloga0302/TextUtility.h)
add_executable(Naloga1101 Naloga11/Naloga1101/naloga1101.cpp
        Naloga11/Naloga1101/Sensor.cpp
        Naloga11/Naloga1101/Sensor.h
        Naloga11/Naloga1101/DuplicatedSensorIdException.cpp
        Naloga11/Naloga1101/DuplicatedSensorIdException.h
        Naloga11/Naloga1101/TemperatureSensor.cpp
        Naloga11/Naloga1101/TemperatureSensor.h
        Naloga11/Naloga1101/TemperatureSensorGPS.cpp
        Naloga11/Naloga1101/TemperatureSensorGPS.h
        Naloga11/Naloga1101/SensorHub.cpp
        Naloga11/Naloga1101/SensorHub.h)
