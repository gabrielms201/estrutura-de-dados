project ("FCRDB (Food Csv Reader And DB)")

add_executable(${PROJECT_NAME}
    "src/main.cpp"
    "src/main.h"
    "src/ArvoreBinaria.h"
    "src/ArvoreBinaria.cpp"
    "src/Food.cpp"
    "src/Food.h"
    "src/CsvManager.cpp"
    "src/CsvManager.h"
    "src/BSTViewer.cpp"
    "src/BSTViewer.h"
)