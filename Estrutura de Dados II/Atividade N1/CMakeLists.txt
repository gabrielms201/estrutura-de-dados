project ("FCRDB (Food Csv Reader And DB)")

add_executable(${PROJECT_NAME}
    "src/main.cpp"
    "src/main.h"
    "src/ArvoreBinaria.h"
    "src/ArvoreBinaria.cpp"
    "src/Food.cpp"
    "src/Food.h"
    "src/CsvReader.cpp"
    "src/CsvReader.h"
)