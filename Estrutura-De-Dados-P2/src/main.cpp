#include <iostream>
#include "rapidcsv.h"
#include "Paciente.h"
#include "Fila.h"
#include "Lista.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


void putContentIntoList(std::string filePath, Lista& list)
{
    std::ifstream input_file(filePath);
    if (!input_file.is_open())
    {
        std::cerr << "Nao foi possivel abrir o arquivo. Caminho: " << filePath << std::endl;
        abort();
    }
    std::stringstream ss;
    ss << input_file.rdbuf();

    std::string str;
    std::getline(ss, str);
    char delimiter = str.find(',') ? ',' : ';';

    while (std::getline(ss, str))
    {
        std::istringstream line(str);
        Fila stack = Fila();

        while (std::getline(line, str, delimiter))
        {
            int value = std::stoul(str);
            stack.enqueue(value);
        }

        unsigned short sexo = stack.dequeue();
        unsigned short tipoPaciente = stack.dequeue();
        unsigned short intubado = stack.dequeue();
        unsigned short pneumonia = stack.dequeue();
        unsigned short idade = stack.dequeue();
        unsigned short gravidez = stack.dequeue();
        unsigned short diabetes = stack.dequeue();
        unsigned short copd = stack.dequeue();
        unsigned short asma = stack.dequeue();
        unsigned short imunossupressao = stack.dequeue();
        unsigned short hipertensao = stack.dequeue();
        unsigned short outrasDoencas = stack.dequeue();
        unsigned short cardiovascular = stack.dequeue();
        unsigned short obesidade = stack.dequeue();
        unsigned short irc = stack.dequeue();
        unsigned short fumante = stack.dequeue();
        unsigned short outroCaso = stack.dequeue();
        unsigned short testeCovid = stack.dequeue();
        unsigned short icu = stack.dequeue();
        unsigned short obito = stack.dequeue();

        Paciente paciente = Paciente(sexo, tipoPaciente, intubado, pneumonia, idade, gravidez, diabetes,
            copd, asma, imunossupressao, hipertensao, outrasDoencas, cardiovascular, obesidade, irc,
            fumante, outroCaso, testeCovid, icu, obito);
        
        list.Insert(paciente);
    }
}



int main()
{
    std::string documentFolder = "C:\\temp\\estrutura-de-dados-p1\\Estrutura-De-Dados-P2\\data";
    std::string documentName = "df_covid.csv";
    std::string finalPath = documentFolder + "\\" + documentName;
    
    
    Lista list = Lista();
    putContentIntoList(finalPath, list);

    std::cout << "Hello, World!" << std::endl;


    //delete list;
    return 0;
}
