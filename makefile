all: test.exe

student_record_system.obj: student_record_system.cpp
	cl /EHsc /c student_record_system.cpp

test.obj: test.cpp
	cl /EHsc /c test.cpp

test.exe: student_record_system.obj test.obj
    cl /EHsc student_record_system.obj test.obj /Fe:test.exe

clean:
	del *.obj
	del *.exe