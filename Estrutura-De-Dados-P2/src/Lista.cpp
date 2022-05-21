/*
ESTRUTURA DE DADOS - P2 - Lista Encadeada
  Grupo:
    Caio Cezar Oliveira Filardi do Carmo        |   TIA: 31891365   |
    Mayara Meneghetti Honda	                    |   TIA: 32152280   |
    Paulo Henrique Braga Cechinel               |   TIA: 32151128   |
    Ricardo Gabriel Marques dos Santos Ruiz     |   TIA: 32134908   |
*/

#include "Lista.h"


// No
Node::Node(TYPE& data, Node *nextNode) : _data(data), _nextNode(nextNode)
{}
Node::Node()
{
    _nextNode = nullptr;
}

Node::~Node()
{
    _nextNode = nullptr;
}

// Lista
Lista::Lista()
{
    _head = nullptr;
    _size = 0;
}

Lista::~Lista()
{
    Clear();
}

bool Lista::IsEmpty() const
{
    return _size == 0;
}

bool Lista::IsFull() const
{
    Node* aux = new Node();
    if (aux == nullptr)
    {
        return true;
    }
    aux = nullptr;
    return false;
}

bool Lista::Insert(TYPE &data)
{
    if (IsFull())
    {
        cerr << "Impossivel adicionar: pilha cheia. Tamanho: " << _size << endl;
        return false;
    }
    Node* node = new Node(data, nullptr);
    if (IsEmpty())
    {
        _head = node;
        _tail = node;
        _size++;
        return true;
    }
    Node* ptr = _tail;
    ptr->SetNextNode(node);
    _tail = node;
    _size++;
    return true;
}

bool Lista::Remove(TYPE &data)
{
    if (IsEmpty())
    {
        return false;
    }
    Node* ptr = _head;
    Node* bkpPtr = nullptr;

    // Se a propria cabeca contem o conteudo que precisamos, apenas vamos remove-lo:
    if (ptr->GetNextNode() == nullptr && ptr->GetData() == data)
    {
        _head = ptr->GetNextNode();
        delete ptr;
        _size--;
        return true;
    }
    // Se aquele nao for o caso, a gente anda até encontrar (ou nao) o dado passado:
    while (ptr->GetNextNode() != nullptr && ptr->GetData() != data)
    {
        bkpPtr = ptr;
        ptr = ptr->GetNextNode();
    }

    // Caso o proximo no seja nulo, e a data eh diferente da desejada, entao nao foi possivel encontrar:
    if (ptr->GetNextNode() == nullptr && ptr->GetData() != data)
    {
        return false;
    }
    // Se encontramos, precisamos apenas apontar o antigo no para o proximo do que queremos remover
    bkpPtr->SetNextNode(ptr->GetNextNode());
    _size--;
    delete ptr;
    return true;
}

void Lista::Clear()
{
    Node *bkpPtr = _head;
    Node *ptr = _head;

    while(ptr != nullptr){
        bkpPtr = ptr;
        ptr = ptr->GetNextNode();
        bkpPtr->SetNextNode(nullptr);
        delete bkpPtr;
        bkpPtr = nullptr;
    }
    _head = nullptr;
}

bool Lista::Find(const TYPE &data) const
{
    // Se estiver vazio, nao tem o que achar
    if (IsEmpty())
    {
        return false;
    }

    Node* ptr = _head;
    // Se o conteudo for igual a cabeca, entao é igual
    if (ptr->GetData() == data)
    {
        return true;
    }

    // Se nao, vamos procurar
    while (ptr->GetNextNode() != nullptr && ptr->GetData() != data)
    {
        ptr = ptr->GetNextNode();
    }
    // Se encontrar, retornar que encontrou
    if (ptr != nullptr && ptr->GetData() == data)
    {
        return true;
    }
    // Caso o contrario, retornar que nao encontrou
    return false;
}

TYPE &Lista::FindByPosition(unsigned int position) const
{
    Node* ptr = _head;
    int count = 0;
    do
    {
        if (count == position)
        {
            return ptr->GetData();
        }
        count++;
        ptr = ptr->GetNextNode();
    } while (ptr != nullptr);
    // Dado nao encontrado
    string str = "Dado nao encontrada na posicao: " + to_string(position);
    throw range_error(str);
}

unsigned int Lista::FindPosition(TYPE &data) const
{
    Node* ptr = _head;
    int count = 0;
    do
    {
        if (ptr->GetData() == data)
        {
            return count;
        }
        count++;
        ptr = ptr->GetNextNode();
    } while (ptr != nullptr);
    // Dado nao encontrado
    string str = "Dado nao encontrado";
    throw range_error(str);
}

string Lista::ToString() const
{
    if (IsEmpty())
    {
        return "null";
    }
    stringstream ss;
    Node* ptr = _head;
    // Se tiver mais de um elemento
    while (ptr->GetNextNode() != nullptr)
    {
        ss << ptr->GetData();
        ss << ";";
        ptr = ptr->GetNextNode();
    }
    // Para o ultimo no:
    ss << ptr->GetData();
    return ss.str();
}
unsigned int Lista::GetDeadQuantity() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}

// Homem 
// Diabete
// Homem - Obesidade - Covid - Morreu
unsigned int Lista::GetMenObeseCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getObesidade() == 1 && data.getTesteCovid() == 1 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Homem - Obesidade - Covid - N morreu
unsigned int Lista::GetMenObeseCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getObesidade() == 1 && data.getTesteCovid() == 1 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Homem - Obesidade - N Covid - Morreu
unsigned int Lista::GetMenObeseNotCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getObesidade() == 1 && data.getTesteCovid() == 2 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Homem - Obesidade - N Covid - N morreu 
unsigned int Lista::GetMenObeseNotCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getObesidade() == 1 && data.getTesteCovid() == 2 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Diabete
// Homem - Diabetico - Covid - Morreu
unsigned int Lista::GetMenDiabeticCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getDiabetes() == 1 && data.getTesteCovid() == 1 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Homem - Diabetico - Covid - N morreu
unsigned int Lista::GetMenDiabeticCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getDiabetes() == 1 && data.getTesteCovid() == 1 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Homem - Diabetico - N Covid - N morreu
unsigned int Lista::GetMenDiabeticNotCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getDiabetes() == 1 && data.getTesteCovid() == 2 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
} 
// Homem - Diabetico - N Covid - Morreu
unsigned int Lista::GetMenDiabeticNotCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getDiabetes() == 1 && data.getTesteCovid() == 2 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}


// ICU 
// Homem - ICU - Covid - Morreu
unsigned int Lista::GetMenIcuCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getIcu() == 1 && data.getTesteCovid() == 1 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Homem - ICU - Covid - N morreu
unsigned int Lista::GetMenIcuCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getIcu() == 1 && data.getTesteCovid() == 1 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Homem - ICU - N Covid - N morreu
unsigned int Lista::GetMenIcuNotCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getIcu() == 1 && data.getTesteCovid() == 2 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
} 
// Homem - ICU - N Covid - Morreu
unsigned int Lista::GetMenIcuNotCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if(data.getSexo() == 2 && data.getIcu() == 1 && data.getTesteCovid() == 2 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}


// Mulher 
// Diabete
// Mulher - Obesidade - Covid - Morreu
unsigned int Lista::GetWomanObeseCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getObesidade() == 1 && data.getTesteCovid() == 1 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Mulher - Obesidade - Covid - N morreu
unsigned int Lista::GetWomanObeseCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getObesidade() == 1 && data.getTesteCovid() == 1 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Mulher - Obesidade - N Covid - Morreu
unsigned int Lista::GetWomanObeseNotCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getObesidade() == 1 && data.getTesteCovid() == 2 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Mulher - Obesidade - N Covid - N morreu 
unsigned int Lista::GetWomanObeseNotCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getObesidade() == 1 && data.getTesteCovid() == 2 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Diabete
// Mulher - Diabetico - Covid - Morreu
unsigned int Lista::GetWomanDiabeticCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getDiabetes() == 1 && data.getTesteCovid() == 1 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Mulher - Diabetico - Covid - N morreu
unsigned int Lista::GetWomanDiabeticCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getDiabetes() == 1 && data.getTesteCovid() == 1 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Mulher - Diabetico - N Covid - N morreu
unsigned int Lista::GetWomanDiabeticNotCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getDiabetes() == 1 && data.getTesteCovid() == 2 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Mulher - Diabetico - N Covid - Morreu
unsigned int Lista::GetWomanDiabeticNotCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getDiabetes() == 1 && data.getTesteCovid() == 2 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}


// ICU 
// Mulher - ICU - Covid - Morreu
unsigned int Lista::GetWomanIcuCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getIcu() == 1 && data.getTesteCovid() == 1 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Mulher - ICU - Covid - N morreu
unsigned int Lista::GetWomanIcuCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getIcu() == 1 && data.getTesteCovid() == 1 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Mulher - ICU - N Covid - N morreu
unsigned int Lista::GetWomanIcuNotCovidNotDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getIcu() == 1 && data.getTesteCovid() == 2 && data.getObito() == 0)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
// Mulher - ICU - N Covid - Morreu
unsigned int Lista::GetWomanIcuNotCovidDead() const
{
    Node* ptr = _head;
    int count = 0;
    while (ptr != nullptr) // Encontro o ponteiro que anda for diferente de nulo (ou seja, nao acabou a lista)
    {
        TYPE data = ptr->GetData();
        if (data.getSexo() == 1 && data.getIcu() == 1 && data.getTesteCovid() == 2 && data.getObito() == 1)
            count++;
        ptr = ptr->GetNextNode();
    }
    return count;
}
