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
        std::cerr << "Impossivel adicionar: pilha cheia. Tamanho: " << _size << std::endl;
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
    } while (ptr != _head);
    // Dado não encontrado
    std::string str = "Dado nao encontrada na posicao: " + std::to_string(position);
    throw std::range_error(str);
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
    } while (ptr != _head);
    // Dado nao encontrado
    std::string str = "Dado nao encontrado";
    throw std::range_error(str);
}

std::string Lista::ToString() const
{
    if (IsEmpty())
    {
        return "null";
    }
    std::stringstream ss;
    Node* ptr = _head;
    // Se tiver mais de um elemento
    while (ptr->GetNextNode() != _head)
    {
        ss << ptr->GetData();
        ss << ";";
        ptr = ptr->GetNextNode();
    }
    // Para o ultimo no:
    ss << ptr->GetData();
    return ss.str();
}
