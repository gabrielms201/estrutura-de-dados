#include <iostream>
#include "rapidcsv.h"
#include "Paciente.h"
#include "Fila.h"
#include "Lista.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


using namespace std;

void putContentIntoList(string filePath, Lista& list)
{
    // Tenta abrir o arquivo
    ifstream input_file(filePath);
    if (!input_file.is_open())
    {
        cerr << "Nao foi possivel abrir o arquivo. Caminho: " << filePath << endl;
        abort();
    }
    // Adiciona o conteudo do buffer em uma stringstream (nao podemos utilizar string, pois estamos trabalhando com streaming)
    stringstream ss;
    ss << input_file.rdbuf();
    // Cria uma string que vai armazenar a primeira linha do stream (descartavel)
    string str;
    getline(ss, str);
    // Define o delimitador com base se encontrou "," ou ";"
    // Como o C++ nao retorna um valor bool no metodo "find", e sim a posicao da string passada,
    // precisamos verificar se o valor retornado é diferente do tamanho maximo que uma string pode ter
    char delimiter = str.find(',') != string::npos ? ',' : ';';
    // Para cada linha, ele vai seguir a logica e adicionar um paciente na lista
    while (getline(ss, str))
    {
        istringstream line(str);
        Fila queue = Fila();
        // Para cada linha, enfileirar o atributo, separado por ","
        while (getline(line, str, delimiter))
        {
            int value = stoul(str);
            queue.enqueue(value);
        }
        // Para cada atributo, desenfileirar o conteudo
        unsigned short sexo = queue.dequeue();
        unsigned short tipoPaciente = queue.dequeue();
        unsigned short intubado = queue.dequeue();
        unsigned short pneumonia = queue.dequeue();
        unsigned short idade = queue.dequeue();
        unsigned short gravidez = queue.dequeue();
        unsigned short diabetes = queue.dequeue();
        unsigned short copd = queue.dequeue();
        unsigned short asma = queue.dequeue();
        unsigned short imunossupressao = queue.dequeue();
        unsigned short hipertensao = queue.dequeue();
        unsigned short outrasDoencas = queue.dequeue();
        unsigned short cardiovascular = queue.dequeue();
        unsigned short obesidade = queue.dequeue();
        unsigned short irc = queue.dequeue();
        unsigned short fumante = queue.dequeue();
        unsigned short outroCaso = queue.dequeue();
        unsigned short testeCovid = queue.dequeue();
        unsigned short icu = queue.dequeue();
        unsigned short obito = queue.dequeue();

        Paciente paciente = Paciente(sexo, tipoPaciente, intubado, pneumonia, idade, gravidez, diabetes,
            copd, asma, imunossupressao, hipertensao, outrasDoencas, cardiovascular, obesidade, irc,
            fumante, outroCaso, testeCovid, icu, obito);

        list.Insert(paciente);
    }
    input_file.close();
}

int main()
{
    string documentFolder = "C:\\temp\\estrutura-de-dados-p1\\Estrutura-De-Dados-P2\\data";
    string documentName = "df_covid.csv";
    string finalPath = documentFolder + "\\" + documentName;

    Lista list = Lista();
    putContentIntoList(finalPath, list);

    cout << "Hello, World!" << endl;

    cout << list;
    
    return 0;
}
