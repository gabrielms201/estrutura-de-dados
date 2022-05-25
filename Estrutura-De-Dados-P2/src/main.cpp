/*
ESTRUTURA DE DADOS - P2 - Lista Encadeada
  Grupo:
    Caio Cezar Oliveira Filardi do Carmo        |   TIA: 31891365   |
    Mayara Meneghetti Honda	                    |   TIA: 32152280   |
    Paulo Henrique Braga Cechinel               |   TIA: 32151128   |
    Ricardo Gabriel Marques dos Santos Ruiz     |   TIA: 32134908   |
*/
#include "main.h"

bool g_benchmark_mode;

int main(int argc, char* argv[])
{

    string documentFolder = argc > 1 ? argv[1] : ".\\";
    string documentName = "df_covid.csv";
    string finalPath = documentFolder + "\\" + documentName;
    Lista list = Lista();

    cout << "Deseja ativar o modo benchmark? (1/0) ";
    cin >> g_benchmark_mode;

    steady_clock::time_point tp = steady_clock::now();
    milliseconds start_ms = duration_cast<milliseconds>(tp.time_since_epoch());
    cout << "Carregando..." << endl;
    putContentIntoList(finalPath, list);
    CLEAR_SCREAM();
    if (g_benchmark_mode)
    {
        tp = steady_clock::now();
        milliseconds now_ms = duration_cast<milliseconds>(tp.time_since_epoch());
        double duration = (now_ms - start_ms).count() / 1000.0f; // milliseconds - seconds 
        cout << "Tempo para carregar a lista em memoria: " << duration << "s" << endl;
    }
    while (true)
        menu(list);

}

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
void submenuComorbidade(ostringstream& opcoes)
{
    unsigned short opcao;
    cout << "Selecione a comorbidade que devera servir como filtro para seus relatorios:" << endl;
    cout << "1 - Obesidade" << endl;
    cout << "2 - Diabetes" << endl;
    cout << "3 - Insuficiencia Renal (ICU)" << endl;
    cout << endl << "Digite a opcao desejada: ";
    cin >> opcao;
    opcoes << opcao;
    CLEAR_SCREAM();
}
void submenuCovid(ostringstream& opcoes)
{
    unsigned short opcao;
    cout << "Selecione se voce quer saber se o paciente testou positivo ou negativo para covid" << endl;
    cout << "1 - Positivo" << endl;
    cout << "2 - Negativo" << endl;
    cout << endl << "Digite a opcao desejada: ";
    cin >> opcao;
    opcoes << opcao;
    CLEAR_SCREAM();
}
void submenuMorte(ostringstream& opcoes)
{
    unsigned short opcao;
    cout << "Selecione se voce quer saber se o paciente morreu ou nao" << endl;
    cout << "1 - Vivo" << endl;
    cout << "2 - Morto" << endl;
    cout << endl << "Digite a opcao desejada: ";
    cin >> opcao;
    opcoes << opcao;
    CLEAR_SCREAM();
}
long consultar(ostringstream& opcoes, Lista& lista)
{
    int consulta = stoi(opcoes.str());

    // Homem Obeso
    switch (consulta)
    {
    case 1111: 
        // Homem - Obeso - Positivo - Vivo : 1111
        return lista.GetMenObeseCovidNotDead();
    case 1121:
        // Homem - Obeso - Negativo - Vivo  : 1121
        return lista.GetMenObeseNotCovidNotDead();
    case 1112:
        // Homem - Obeso - Positivo - Morto : 1112
        return lista.GetMenObeseCovidDead();
    case 1122:
        // Homem - Obeso - Negativo - Morto : 1122
        return lista.GetMenObeseNotCovidDead();
    // Homem Diabetico
    case 1211:
        // Homem - Diabetico - Positivo - Vivo  :  1211
        return lista.GetMenDiabeticCovidNotDead();
    case 1221:
        // Homem - Diabetico - Negativo - Vivo  :  1221
        return lista.GetMenDiabeticNotCovidNotDead();
    case 1212:
        // Homem - Diabetico - Positivo - Morto :  1212
        return lista.GetMenDiabeticCovidDead();
    case 1222:
        // Homem - Diabetico - Negativo - Morto :  1222
        return lista.GetMenDiabeticNotCovidDead();
    // Homem ICU
    case 1311:
        // Homem - ICU - Positivo - Vivo  : 1311
        return lista.GetMenIcuCovidNotDead();
    case 1321:
        // Homem - ICU - Negativo - Vivo  : 1321
        return lista.GetMenIcuNotCovidNotDead();
    case 1312:
        // Homem - ICU - Positivo - Morto : 1312
        return lista.GetMenIcuCovidDead();
    case 1322:
        // Homem - ICU - Negativo - Morto : 1322
        return lista.GetMenIcuNotCovidDead();
    // Mulher Obeso
    case 2111:
        // Mulher - Obeso - Positivo - Vivo : 2111
        return lista.GetWomanObeseCovidNotDead();
    case 2121:
        // Mulher - Obeso - Negativo - Vivo  : 2121
        return lista.GetWomanObeseNotCovidNotDead();
    case 2112:
        // Mulher - Obeso - Positivo - Morto : 2112
        return lista.GetWomanObeseCovidDead();
    case 2122:
        // Mulher - Obeso - Negativo - Morto : 2122
        return lista.GetWomanObeseNotCovidDead();
    // Mulher Diabetico
    case 2211:
        // Mulher - Diabetico - Positivo - Vivo  :  2211
        return lista.GetWomanDiabeticCovidNotDead();
    case 2221:
        // Mulher - Diabetico - Negativo - Vivo  :  2221
        return lista.GetWomanDiabeticNotCovidNotDead();
    case 2212:
        // Mulher - Diabetico - Positivo - Morto :  2212
        return lista.GetWomanDiabeticCovidDead();
    case 2222:
        // Mulher - Diabetico - Negativo - Morto :  2222
        return lista.GetWomanDiabeticNotCovidDead();
    // Mulher ICU
    case 2311:
        // Mulher - ICU - Positivo - Vivo  : 2311
        return lista.GetWomanIcuCovidNotDead();
    case 2321:
        // Mulher - ICU - Negativo - Vivo  : 2321
        return lista.GetWomanIcuNotCovidNotDead();
    case 2312:
        // Mulher - ICU - Positivo - Morto : 2312
        return lista.GetWomanIcuCovidDead();
    case 2322:
        // Mulher - ICU - Negativo - Morto : 2322
        return lista.GetWomanIcuNotCovidDead();
    default:
        return -1;
    }
    
}
void menu(Lista& list)
{
    int opcao;
    cout << "BEM VINDO AO ARGS" << endl;
    cout << "ARGS - Automated Report Generation System" << endl;
    
    cout << endl << "Por favor, selecione o sexo que devera servir como filtro para seus relatorios" << endl;
    cout << "Opcao 1 - Homens" << endl;
    cout << "Opcao 2 - Mulheres" << endl;
    cout << "Opcao 3 - Curiosidades Morbidas" << endl;
    cout << "Opcao 4 - Sair do Programa" << endl;
    cout << endl << "Digite a opcao desejada: ";
    cin >> opcao;
    CLEAR_SCREAM();
    switch (opcao)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        // TODO
        return;
    case 4:
        exit(0);
        break;
    default:
        cout << "Opcao Invalida!" << endl;
        system("pause");
        break;
    }
    // Caso a opcao seja de uma consulta personalizada, chamar os demais menus e realizar a consulta
    ostringstream opcoes;
    opcoes << opcao;
    submenuComorbidade(opcoes);
    submenuCovid(opcoes);
    submenuMorte(opcoes);
    steady_clock::time_point tp = steady_clock::now();
    milliseconds start_ms = duration_cast<milliseconds>(tp.time_since_epoch());
    long consulta = consultar(opcoes, list);
    if (consulta >= 0)
    {
        if (g_benchmark_mode)
        {
            tp = steady_clock::now();
            milliseconds now_ms = duration_cast<milliseconds>(tp.time_since_epoch());
            long long duration = (now_ms - start_ms).count();
            cout << "MODO BENCHMARK: Tempo para realizar a consulta: " << duration << "ms" << endl;
        }
        cout << "Resultado da consulta: " << consulta << " casos." << endl;
    }
    else
    {
        cout << "Consulta Invalida!" << endl;
    }
    cout << "Deseja continuar? (1/0) ";
    bool continuar;
    cin >> continuar;
    if (!continuar)
    {
        exit(0);
    }
    CLEAR_SCREAM();
    return;
}