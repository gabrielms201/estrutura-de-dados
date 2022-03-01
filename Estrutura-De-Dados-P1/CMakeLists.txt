# Project Specs
cmake_minimum_required(VERSION 3.17.0)
project("Estrutura-De-Dados-P1")
message("Building: ${PROJECT_NAME} Solution")

# Platform Specifications
if(WIN32)
    message("\t ${PROJECT_NAME}: I do provide Windows support")
elseif(UNIX)
    message("\t ${PROJECT_NAME}: I do provide Unix support")
else()
    message(FATAL_ERROR"\t ${PROJECT_NAME}: Unfortunately I can't support your system. Windows and Unix Support Only")
endif()

#set(PROJECT_FOLDER "Estrutura-De-Dados-P1")

add_executable("${PROJECT_NAME}")
target_sources("${PROJECT_NAME}" PRIVATE
    "src/Programa.cpp"
    "src/Programa.h"
    "src/Pilha.cpp"
    "src/Pilha.h"
    "src/Errors.h"
    "src/Calculadora.cpp"
    "src/Calculadora.h"
)
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)



