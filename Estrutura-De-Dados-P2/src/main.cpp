/*
ESTRUTURA DE DADOS - P2 - Lista Encadeada
  Grupo:
    Caio Cezar Oliveira Filardi do Carmo        |   TIA: 31891365   |
    Mayara Meneghetti Honda	                    |   TIA: 32152280   |
    Paulo Henrique Braga Cechinel               |   TIA: 32151128   |
    Ricardo Gabriel Marques dos Santos Ruiz     |   TIA: 32134908   |
*/
#include "main.h"

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
    // precisamos verificar se o valor retornado � diferente do tamanho maximo que uma string pode ter
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
        // Assim que tivermos todos os atributos armazenados, instanciar um objeto "Paciente"
        Paciente paciente = Paciente(sexo, tipoPaciente, intubado, pneumonia, idade, gravidez, diabetes,
            copd, asma, imunossupressao, hipertensao, outrasDoencas, cardiovascular, obesidade, irc,
            fumante, outroCaso, testeCovid, icu, obito);
        // Adiciona o paciente na lista
        list.Insert(paciente);
    }
    // Fecha o arquivo, para evitar problemas
    input_file.close();
}

int main(int argc, char* argv[])
{
    string documentFolder = argc > 1 ? argv[1] : ".\\";
    string documentName = "df_covid.csv";
    string finalPath = documentFolder + "\\" + documentName;

    //while (true)
    //{
        //menu(finalPath);
    //}
    testes(finalPath);
    
}


void menu(string filePath)
{
    Lista list = Lista();
    putContentIntoList(filePath, list);

    int opcao;
    cout << "Digite a opcao: ";
    cin >> opcao;
    switch(opcao)
    {
        case 1:
            cout << "Quantidade de Mortos: " << endl;
            cout << list.GetDeadQuantity() << endl;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            cout << "Opcao Invalida!";
    }
}

void testes(string filePath)
{
	Lista list = Lista();
    putContentIntoList(filePath, list);


    // Homem

    // Homem - Obeso
    cout << "GetMenObeseCovidDead: ";
	cout << list.GetMenObeseCovidDead() << endl; //  403 v
    cout << "GetMenObeseCovidNotDead: ";
	cout << list.GetMenObeseCovidNotDead() << endl; // 2353 v
    cout << "GetMenObeseNotCovidDead: ";
	cout << list.GetMenObeseNotCovidDead() << endl; // 108 v
    cout << "GetMenObeseNotCovidNotDead: ";
    cout << list.GetMenObeseNotCovidNotDead() << endl;


    // Homem - Diabetico
    cout << "GetMenDiabeticCovidDead: ";
    cout << list.GetMenDiabeticCovidDead() << endl;
    cout << "GetMenDiabeticCovidNotDead: ";
    cout << list.GetMenDiabeticCovidNotDead() << endl;
    cout << "GetMenDiabeticNotCovidDead: ";
    cout << list.GetMenDiabeticNotCovidDead() << endl;
    cout << "GetMenDiabeticNotCovidNotDead: ";
    cout << list.GetMenDiabeticNotCovidNotDead() << endl;

    // Homem - ICU
    cout << "GetMenIcuCovidDead: ";
    cout << list.GetMenIcuCovidDead() << endl;
    cout << "GetMenIcuCovidNotDead: ";
    cout << list.GetMenIcuCovidNotDead() << endl;
    cout << "GetMenIcuNotCovidDead: ";
    cout << list.GetMenIcuNotCovidDead() << endl;
    cout << "GetMenIcuNotCovidNotDead: ";
    cout << list.GetMenIcuNotCovidNotDead() << endl;

    // Mulher

    // Mulher - Obeso
    cout << "GetWomanObeseCovidDead: ";
    cout << list.GetWomanObeseCovidDead() << endl;
    cout << "GetWomanObeseCovidNotDead: ";
    cout << list.GetWomanObeseCovidNotDead() << endl;
    cout << "GetWomanObeseNotCovidDead: ";
    cout << list.GetWomanObeseNotCovidDead() << endl;
    cout << "GetWomanObeseNotCovidNotDead: ";
    cout << list.GetWomanObeseNotCovidNotDead() << endl;


    // Mulher - Diabetico
    cout << "GetWomanDiabeticCovidDead: ";
    cout << list.GetWomanDiabeticCovidDead() << endl;
    cout << "GetWomanDiabeticCovidNotDead: ";
    cout << list.GetWomanDiabeticCovidNotDead() << endl;
    cout << "GetWomanDiabeticNotCovidDead: ";
    cout << list.GetWomanDiabeticNotCovidDead() << endl;
    cout << "GetWomanDiabeticNotCovidNotDead: ";
    cout << list.GetWomanDiabeticNotCovidNotDead() << endl;

    // Mulher - ICU
    cout << "GetWomanIcuCovidDead: ";
    cout << list.GetWomanIcuCovidDead() << endl;
    cout << "GetWomanIcuCovidNotDead: ";
    cout << list.GetWomanIcuCovidNotDead() << endl;
    cout << "GetWomanIcuNotCovidDead: ";
    cout << list.GetWomanIcuNotCovidDead() << endl;
    cout << "GetWomanIcuNotCovidNotDead: ";
    cout << list.GetWomanIcuNotCovidNotDead() << endl;


}