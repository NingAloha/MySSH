# CMake generated Testfile for 
# Source directory: D:/Repo/Project/MySSH/deps/notcurses
# Build directory: D:/Repo/Project/MySSH/build/deps/notcurses
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[notcurses-info]=] "D:/Repo/Project/MySSH/build/deps/notcurses/notcurses-info.exe")
set_tests_properties([=[notcurses-info]=] PROPERTIES  RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;904;add_test;D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;0;")
add_test([=[ncpp_build]=] "D:/Repo/Project/MySSH/build/deps/notcurses/ncpp_build.exe")
set_tests_properties([=[ncpp_build]=] PROPERTIES  RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;909;add_test;D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;0;")
add_test([=[ncpp_build_exceptions]=] "D:/Repo/Project/MySSH/build/deps/notcurses/ncpp_build_exceptions.exe")
set_tests_properties([=[ncpp_build_exceptions]=] PROPERTIES  RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;913;add_test;D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;0;")
add_test([=[input-devnull]=] "sh" "-c" "./notcurses-input -v < /dev/null")
set_tests_properties([=[input-devnull]=] PROPERTIES  RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;918;add_test;D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;0;")
add_test([=[input-text]=] "sh" "-c" "./notcurses-input < D:/Repo/Project/MySSH/COPYRIGHT")
set_tests_properties([=[input-text]=] PROPERTIES  RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;923;add_test;D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;0;")
add_test([=[sgr-direct]=] "D:/Repo/Project/MySSH/build/deps/notcurses/sgr-direct.exe")
set_tests_properties([=[sgr-direct]=] PROPERTIES  RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;930;add_test;D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;0;")
add_test([=[sgr-full]=] "D:/Repo/Project/MySSH/build/deps/notcurses/sgr-full.exe")
set_tests_properties([=[sgr-full]=] PROPERTIES  RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;934;add_test;D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;0;")
add_test([=[rgb]=] "D:/Repo/Project/MySSH/build/deps/notcurses/rgb.exe")
set_tests_properties([=[rgb]=] PROPERTIES  RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;938;add_test;D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;0;")
add_test([=[rgbbg]=] "D:/Repo/Project/MySSH/build/deps/notcurses/rgbbg.exe")
set_tests_properties([=[rgbbg]=] PROPERTIES  RUN_SERIAL "TRUE" _BACKTRACE_TRIPLES "D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;944;add_test;D:/Repo/Project/MySSH/deps/notcurses/CMakeLists.txt;0;")
