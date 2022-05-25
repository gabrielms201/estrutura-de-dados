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
    g_benchmark_mode = getchar();

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
        cout << "{ MODO BENCHMARK: Tempo para carregar a lista em memoria: " << duration << "s }" << endl;
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
        cerr << "Nao foi possivel abrir o arquivo. Caminho dado: " << filePath << endl;
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
void testes(Lista& list)
{
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
    
    cout << "Pressione digite algo para continuar: " << endl;
    char ch;
    cin >> ch;
    CLEAR_SCREAM();
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
KEY_AND_VALUE consultar(ostringstream& opcoes, Lista& lista)
{
    int consulta = stoi(opcoes.str());
    KEY_AND_VALUE kv;
    // Homem Obeso
    switch (consulta)
    {
    case 1111:
        // Homem - Obeso - Positivo - Vivo : 1111
        kv.key = "Homens Obesos com Covid e Vivos";
        kv.value = lista.GetMenObeseCovidNotDead();
        break;
    case 1121:
        // Homem - Obeso - Negativo - Vivo  : 1121
        kv.key = "Homens Obesos sem Covid e Vivos";
        kv.value = lista.GetMenObeseNotCovidNotDead();
        break;
    case 1112:
        // Homem - Obeso - Positivo - Morto : 1112
        kv.key = "Homens Obesos com Covid e Mortos";
        kv.value = lista.GetMenObeseCovidDead();
        break;
    case 1122:
        // Homem - Obeso - Negativo - Morto : 1122
        kv.key = "Homens Obesos sem covid e Mortos";
        kv.value = lista.GetMenObeseNotCovidDead();
        break;
    // Homem Diabetico
    case 1211:
        // Homem - Diabetico - Positivo - Vivo  :  1211
        kv.key = "Homens Diabeticos com Covid e Vivos";
        kv.value = lista.GetMenDiabeticCovidNotDead();
        break;
    case 1221:
        // Homem - Diabetico - Negativo - Vivo  :  1221
        kv.key = "Homens Diabeticos sem Covid e Vivos";
        kv.value = lista.GetMenDiabeticNotCovidNotDead();
        break;
    case 1212:
        // Homem - Diabetico - Positivo - Morto :  1212
        kv.key = "Homens Diabeticos com Covid e Mortos";
        kv.value = lista.GetMenDiabeticCovidDead();
        break;
    case 1222:
        // Homem - Diabetico - Negativo - Morto :  1222
        kv.key = "Homens Diabeticos sem Covid e Mortos";
        kv.value = lista.GetMenDiabeticNotCovidDead();
        break;
    // Homem ICU
    case 1311:
        // Homem - ICU - Positivo - Vivo  : 1311
        kv.key = "Homens com ICU com Covid e Vivos";
        kv.value = lista.GetMenIcuCovidNotDead();
        break;
    case 1321:
        // Homem - ICU - Negativo - Vivo  : 1321
        kv.key = "Homens com ICU sem Covid e Vivos";
        kv.value = lista.GetMenIcuNotCovidNotDead();
        break;
    case 1312:
        // Homem - ICU - Positivo - Morto : 1312
        kv.key = "Homens com ICU com Covid e Mortos";
        kv.value = lista.GetMenIcuCovidDead();
        break;
    case 1322:
        // Homem - ICU - Negativo - Morto : 1322
        kv.key = "Homens com ICU sem Covid e Mortos";
        kv.value = lista.GetMenIcuNotCovidDead();
        break;
    // Mulher Obeso
    case 2111:
        // Mulher - Obeso - Positivo - Vivo : 2111
        kv.key = "Mulheres Obesas com Covid e Vivas";
        kv.value = lista.GetWomanObeseCovidNotDead();
        break;
    case 2121:
        // Mulher - Obeso - Negativo - Vivo  : 2121
        kv.key = "Mulheres Obesas sem Covid e Vivas";
        kv.value = lista.GetWomanObeseNotCovidNotDead();
        break;
    case 2112:
        // Mulher - Obeso - Positivo - Morto : 2112
        kv.key = "Mulheres Obesas com Covid e Mortas";
        kv.value = lista.GetWomanObeseCovidDead();
        break;
    case 2122:
        // Mulher - Obeso - Negativo - Morto : 2122
        kv.key = "Mulheres Obesas sem Covid e Mortas";
        kv.value = lista.GetWomanObeseNotCovidDead();
        break;
    // Mulher Diabetico
    case 2211:
        // Mulher - Diabetico - Positivo - Vivo  :  2211
        kv.key = "Mulheres Diabeticas com Covid e Vivas";
        kv.value = lista.GetWomanDiabeticCovidNotDead();
        break;
    case 2221:
        // Mulher - Diabetico - Negativo - Vivo  :  2221
        kv.key = "Mulheres Diabeticas sem Covid e Vivas";
        kv.value = lista.GetWomanDiabeticNotCovidNotDead();
        break;
    case 2212:
        // Mulher - Diabetico - Positivo - Morto :  2212
        kv.key = "Mulheres Diabeticas com Covid e Mortas";
        kv.value = lista.GetWomanDiabeticCovidDead();
        break;
    case 2222:
        // Mulher - Diabetico - Negativo - Morto :  2222
        kv.key = "Mulheres Diabeticas sem Covid e Mortas";
        kv.value = lista.GetWomanDiabeticNotCovidDead();
        break;
    // Mulher ICU
    case 2311:
        // Mulher - ICU - Positivo - Vivo  : 2311
        kv.key = "Mulheres com ICU com Covid e Vivas";
        kv.value = lista.GetWomanIcuCovidNotDead();
        break;
    case 2321:
        // Mulher - ICU - Negativo - Vivo  : 2321
        kv.key = "Mulheres com ICU sem Covid e Vivas";
        kv.value = lista.GetWomanIcuNotCovidNotDead();
        break;
    case 2312:
        // Mulher - ICU - Positivo - Morto : 2312
        kv.key = "Mulheres com ICU com Covid e Mortas";
        kv.value = lista.GetWomanIcuCovidDead();
        break;
    case 2322:
        // Mulher - ICU - Negativo - Morto : 2322
        kv.key = "Mulheres com ICU sem Covid e Mortas";
        kv.value = lista.GetWomanIcuNotCovidDead();
        break;
    default:
        kv.key = "CONSULTA INVALIDA";
        kv.value = -1;
        break;
    }
    return kv;
    
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
    cout << "Opcao 5 - Realizar teste com todas as consultas" << endl;
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
    case 5:
        testes(list);
        return;
    default:
        cout << "Opcao Invalida!" << endl;
        cout << "Pressione digite algo para continuar: " << endl;
        char ch;
        cin >> ch;
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
    KEY_AND_VALUE consulta = consultar(opcoes, list);
    if (consulta.value >= 0)
    {
        if (g_benchmark_mode)
        {
            tp = steady_clock::now();
            milliseconds now_ms = duration_cast<milliseconds>(tp.time_since_epoch());
            long long duration = (now_ms - start_ms).count();
            cout << "{ MODO BENCHMARK: Tempo para realizar a consulta: " << duration << "ms }" << endl;
        }
        cout << "Casos de " << consulta.key << ": " << consulta.value << " casos." << endl;
    }
    else
    {
        cout << "Consulta Invalida!" << endl;
    }
    cout << "Deseja continuar? (1/0) ";
    int continuar;
    cin >> continuar;
    if (!continuar)
    {
        exit(0);
    }
    CLEAR_SCREAM();
    return;
}