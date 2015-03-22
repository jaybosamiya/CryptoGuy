cmake_minimum_required(VERSION 2.8)
project ( CryptoGuy )
add_custom_command ( OUTPUT ${CMAKE_SOURCE_DIR}/generated_algos.cpp ${CMAKE_SOURCE_DIR}/generated_algos.h COMMAND ${CMAKE_SOURCE_DIR}/generate_algos.sh WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} DEPENDS decrypt_algos/ keyed_decrypt_algos/  )
add_executable ( cryptoguy cryptoguy.cpp util.cpp decrypter.cpp generated_algos.cpp )
