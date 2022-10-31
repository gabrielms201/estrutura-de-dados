// AVL.cpp
#include "AVL.h"
#include "Utils.h"
#include <sstream>

AVL::AVL()
	: m_Root(nullptr)
{
}

AVL::~AVL()
{
	Clear();
}

NodeAVL* AVL::GetRoot() const
{
	return m_Root;
}

bool AVL::IsEmpty() const
{
	return m_Root == nullptr;
}

void AVL::Clear()
{
	Destroy(m_Root);
	m_Root = nullptr;
}

void AVL::Destroy(NodeAVL* node)
{
	if (node != nullptr)
	{
		Destroy(node->GetLeft());
		Destroy(node->GetRight());

		delete node;
		node = nullptr;
	}
}

int AVL::GetDegree() const
{
	return GetDegreeInternal(m_Root);
}

int AVL::GetDegreeInternal(const NodeAVL* node) const
{
	if (node != nullptr)
	{
		int left = GetDegreeInternal(node->GetLeft());
		int right = GetDegreeInternal(node->GetRight());
		return Utils::Max(node->GetDegree(), Utils::Max(left, right));
	}

	return 0;
}

int AVL::GetHeight() const
{
	if (m_Root == nullptr)
		return -1;

	return m_Root->GetHeight();
}

std::list<Produto> AVL::StorageAllProductsIntoAList() const
{
	std::list<Produto> productList = std::list<Produto>();
	if (m_Root != nullptr)
	{
		productList.push_back(m_Root->GetData());
	}
	StorageAllProductsIntoAListInternal(productList, m_Root);
	return productList;
}

std::string AVL::TraverseInOrder() const
{
	return TraverseInOrderInternal(m_Root);
}

const NodeAVL* AVL::StorageAllProductsIntoAListInternal(std::list<Produto>& products, const NodeAVL* node) const
{
	// pre ordem
	if (node != nullptr)
	{
		const NodeAVL* noEsquerda = StorageAllProductsIntoAListInternal(products, node->GetLeft());
		if (noEsquerda != nullptr)
			products.push_back(noEsquerda->GetData());
		const NodeAVL* noDireita = StorageAllProductsIntoAListInternal(products, node->GetRight());
		if (noDireita != nullptr)
			products.push_back(noDireita->GetData());
		return node;
	}
	return nullptr;
}

std::string AVL::TraverseInOrderInternal(const NodeAVL* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraverseInOrderInternal(node->GetLeft());
		oss << node->ToString();
		oss << TraverseInOrderInternal(node->GetRight());
		return oss.str();
	}

	//return "null ";
	return "";
}

std::string AVL::TraversePreOrder() const
{
	return TraversePreOrderInternal(m_Root);
}

std::string AVL::TraversePreOrderInternal(const NodeAVL* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << node->ToString();
		oss << TraversePreOrderInternal(node->GetLeft());
		oss << TraversePreOrderInternal(node->GetRight());
		return oss.str();
	}

	//return "null ";
	return "";
}

std::string AVL::TraversePostOrder() const
{
	return TraversePostOrderInternal(m_Root);
}

std::string AVL::TraversePostOrderInternal(const NodeAVL* node) const
{
	if (node != nullptr)
	{
		std::ostringstream oss;
		oss << TraversePostOrderInternal(node->GetLeft());
		oss << TraversePostOrderInternal(node->GetRight());
		oss << node->ToString();
		return oss.str();
	}

	//return "null ";
	return "";
}

NodeAVL* AVL::FindMin() const
{
	return FindMinInternal(m_Root);
}

NodeAVL* AVL::FindMinInternal(NodeAVL* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetLeft() == nullptr)
		return node;
	else
		return FindMinInternal(node->GetLeft());
}

NodeAVL* AVL::FindMax() const
{
	return FindMaxInternal(m_Root);
}

NodeAVL* AVL::FindMaxInternal(NodeAVL* node) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetRight() == nullptr)
		return node;
	else
		return FindMaxInternal(node->GetRight());
}

NodeAVL* AVL::Predecessor(int id) const
{
	NodeAVL* node = SearchInternal(m_Root, id);
	return node == nullptr ? nullptr : PredecessorInternal(node);
}

NodeAVL* AVL::PredecessorInternal(NodeAVL* node) const
{
	if (node->GetLeft() != nullptr)
	{
		return FindMaxInternal(node->GetLeft());
	}
	else
	{
		NodeAVL* current = node;
		NodeAVL* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetLeft())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeAVL* AVL::Successor(int id) const
{
	NodeAVL* node = SearchInternal(m_Root, id);
	return node == nullptr ? nullptr : SuccessorInternal(node);
}

NodeAVL* AVL::SuccessorInternal(NodeAVL* node) const
{
	if (node->GetRight() != nullptr)
	{
		return FindMinInternal(node->GetRight());
	}
	else
	{
		NodeAVL* current = node;
		NodeAVL* currentParent = node->GetParent();
		while (currentParent != nullptr && current == currentParent->GetRight())
		{
			current = currentParent;
			currentParent = current->GetParent();
		}

		return currentParent;
	}
}

NodeAVL* AVL::Search(int id) const
{
	return SearchInternal(m_Root, id);
}

NodeAVL* AVL::SearchInternal(NodeAVL* node, int &id) const
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetID() == id)
		return node;
	else if (node->GetID() > id)
		return SearchInternal(node->GetLeft(), id);
	else
		return SearchInternal(node->GetRight(), id);
}

NodeAVL* AVL::Insert(const Produto& data)
{
	if (IsEmpty())
	{
		m_Root = new NodeAVL(data);
		//m_Root->UpdateBalanceFactor();
		return m_Root;
	}

	return InsertInternal(m_Root, nullptr, data.codigoProduto, data);
}

NodeAVL* AVL::InsertInternal(NodeAVL* node, NodeAVL* parent, int id, const Produto& data)
{
	if (node == nullptr)
		node = new NodeAVL(data, parent);
	else if (node->GetID() == id)
		return nullptr; // Error! Cannot insert duplicate.
	else if (node->GetID() > id)
		node->SetLeft(InsertInternal(node->GetLeft(), node, id, data));
	else if (node->GetID() < id)
		node->SetRight(InsertInternal(node->GetRight(), node, id, data));

	node = Balance(node);
	return node;
}

void AVL::Remove(int id)
{
	RemoveInternal(m_Root, id);
}

NodeAVL* AVL::RemoveInternal(NodeAVL* node, int id)
{
	if (node == nullptr)
		return nullptr;
	else if (node->GetID() == id)
		node = RemoveNode(node);
	else if (node->GetID() > id)
		node->SetLeft(RemoveInternal(node->GetLeft(), id));
	else
		node->SetRight(RemoveInternal(node->GetRight(), id));
	
	node = Balance(node);
	return node;
}

NodeAVL* AVL::RemoveNode(NodeAVL* node)
{
	NodeAVL* parent = node->GetParent();

	// Case 1: The node to be removed is a leaf.
	if (node->IsLeaf())
	{
		UpdateParentChild(parent, node, nullptr);

		delete node;
		node = nullptr;
	}
	// Case 2: The node to be removed has no left child/subtree.
	else if (node->GetLeft() == nullptr)
	{
		NodeAVL* newChild = node->GetRight();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 3: The node to be removed has no right child/subtree.
	else if (node->GetRight() == nullptr)
	{
		NodeAVL* newChild = node->GetLeft();
		UpdateParentChild(parent, node, newChild);

		delete node;
		node = newChild;
	}
	// Case 4: The node to be removed has both left and right children/subtrees.
	else
	{
		// To remove the node, we are reducing the problem to Case 3.
		// In this case, predecessor is located in the node's left child/subtree and
		// is the node that has no right child/subtree.
		NodeAVL* predecessor = Predecessor(node->GetID());

		// Instead of only updating pointers, we are copying the data from the
		// predecessor to the node pointer and then we remove the predecessor node.
		node->CopyDataFrom(predecessor);
		node->SetLeft(RemoveInternal(node->GetLeft(), predecessor->GetID()));
	}

	return node;
}

void AVL::UpdateParentChild(NodeAVL* parent, const NodeAVL* child, NodeAVL* newChild)
{
	if (parent != nullptr)
	{
		if (parent->GetLeft() == child)
			parent->SetLeft(newChild);
		else
			parent->SetRight(newChild);
	}
	else
	{
		m_Root = newChild;
	}

	if (newChild != nullptr)
		newChild->SetParent(parent);
}

// Also known as LL Rotation (or RR tree, right-right tree).
NodeAVL* AVL::RotateLeft(NodeAVL* node)
{
	if (node == nullptr) return nullptr;

	// The current node must have a right child/subtree.	
	NodeAVL* newRoot = node->GetRight();
	if (newRoot == nullptr) return nullptr;

	// Swap parent links.
	NodeAVL* parent = node->GetParent();
	UpdateParentChild(parent, node, newRoot);
	node->SetParent(newRoot);

	// Since newRoot is this subtree's new root,
	// its left child becomes the right child of
	// the current node.
	NodeAVL* left = newRoot->GetLeft();
	node->SetRight(left);

	// Update the parent of newRoot's left child
	// if there is a left child.
	if (left != nullptr)
		left->SetParent(node);

	// The new left child of newRoot is the current node.
	newRoot->SetLeft(node);

	node->UpdateBalanceFactor();
	newRoot->UpdateBalanceFactor();

	return newRoot;
}

// Also known as RR Rotation (or LL tree, left-left tree).
NodeAVL* AVL::RotateRight(NodeAVL* node)
{
	if (node == nullptr) return nullptr;

	// The current node must have a left child/subtree.	
	NodeAVL* newRoot = node->GetLeft();
	if (newRoot == nullptr) return nullptr;

	// Swap parent links.
	NodeAVL* parent = node->GetParent();
	UpdateParentChild(parent, node, newRoot);
	node->SetParent(newRoot);

	// Since newRoot is this subtree's new root,
	// its right child becomes the left child of
	// the current node.
	NodeAVL* right = newRoot->GetRight();
	node->SetLeft(right);

	// Update the parent of newRoot's right child
	// if there is a right child.
	if (right != nullptr)
		right->SetParent(node);

	// The new right child of newRoot is the current node.
	newRoot->SetRight(node);

	node->UpdateBalanceFactor();
	newRoot->UpdateBalanceFactor();

	return newRoot;
}

// Also known as Left-Right Rotation (LR Rotation).
NodeAVL* AVL::RotateLeftRight(NodeAVL* node)
{
	node->SetLeft(RotateLeft(node->GetLeft()));
	return RotateRight(node);
}

// Also known as Right-Left Rotation (RL Rotation).
NodeAVL* AVL::RotateRightLeft(NodeAVL* node)
{
	node->SetRight(RotateRight(node->GetRight()));
	return RotateLeft(node);
}

NodeAVL* AVL::Balance(NodeAVL* node)
{
	if (node != nullptr)
	{
		node->UpdateBalanceFactor();
		int nodeBF = node->GetBalanceFactor();

		// Tree is left heavy.
		//if (nodeBF == 2) // --> Use this if BF=HL-HR.
		if (nodeBF == -2)
		{
			// Get left subtree's height.
			NodeAVL* left = node->GetLeft();
			left->UpdateBalanceFactor();
			int leftChildBF = left->GetBalanceFactor();

			//if (leftChildBF == 1) // --> Use this if BF=HL-HR.
			if (leftChildBF == -1)
				node = RotateRight(node);
			else
				node = RotateLeftRight(node);
		}
		// Tree is right heavy.
		//else if (nodeBF == -2) // --> Use this if BF=HL-HR.
		else if (nodeBF == 2)
		{
			// Get right subtree's height.
			NodeAVL* right = node->GetRight();
			right->UpdateBalanceFactor();
			int rightChildBF = right->GetBalanceFactor();

			//if (rightChildBF == -1) // --> Use this if BF=HL-HR.
			if (rightChildBF == 1)
				node = RotateLeft(node);
			else
				node = RotateRightLeft(node);
		}
	}

	return node;
}