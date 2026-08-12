#include "SinglyLinkedList.h"


using namespace std;

SinglyLinkedList::SinglyLinkedList() {
	head_ = nullptr;
    tail_ = nullptr;
	size_ = 0;
}


SinglyLinkedList::~SinglyLinkedList() {
	while (head_ != nullptr) {
		DeleteHead(head_);
	}
}


Node* SinglyLinkedList::GetHead() const {
	return head_;
}

Node* SinglyLinkedList::GetTail() const {
	return tail_;
}



int SinglyLinkedList::GetSize() const {
	return size_;
}


void SinglyLinkedList::PrintList() const {
	Node* current_node = head_;

	cout << "Элементы списка: " << endl;

	while (current_node != nullptr) {
		cout << current_node->data_ << " ";
		current_node = current_node->next_;
	}

	cout << endl;
}


void SinglyLinkedList::CheckRange(int size, int index, std::function<bool(int, int)> compare_mode) {

	if (index < 0) {
		throw std::out_of_range("Индекс должен быть больше 0. ");
	}
	else if (compare_mode(size, index)) {
		throw std::out_of_range("Слишком большой индекс. ");
	}
}


bool SinglyLinkedList::CompareForCheckIndex(int size, int index) {
	return size <= index;
}


bool SinglyLinkedList::CompareForAddElement(int size, int index) {
	return size < index;
}


void SinglyLinkedList::AddElement(int index, std::string value) {
	
	// Проверка корректности индекса
	std::function<bool(int, int)> func;
	func = [&](int a, int b) { return CompareForAddElement(a, b); };
	CheckRange(size_, index, func);

	Node* new_node = new Node(value);

	// Вставка в начало списка
	if (index == 0) {

		// Если при этом список пустой
		// Тогда новый узел будет и head и tail одновременно
		if (head_ == nullptr) {

			head_ = new_node;
			tail_ = new_node;

			size_ = size_ + 1;
			return;
		}

		
		new_node->next_ = head_;
		head_ = new_node;

	}
	// Вставка в середину списка
	else if (index != size_) {
		Node* left_node = GetElementByIndex(index-1);
		//Node* right_node = left_node->next_;

        new_node->next_ = left_node->next_;
		left_node->next_ = new_node;

	}
	// Вставка в конец списка
	else {
		tail_->next_ = new_node;
		new_node->next_ = nullptr;

		tail_ = new_node;

	}
	size_ = size_ + 1;
	return;
}


void SinglyLinkedList::SetElement(int index, std::string value) {
	Node* node = GetElementByIndex(index);

	node->data_ = value;
}


Node* SinglyLinkedList::GetElementByIndex(int index) {
	// Проверка корректности индекса
	std::function<bool(int, int)> func;
	func = [&](int a, int b) { return CompareForCheckIndex(a, b); };
	CheckRange(size_, index, func);

	Node* current_node = head_;
	int current_index = 0;

	while (current_node != nullptr) {

		if (current_index == index) {
			return current_node;
		}

		current_index = current_index + 1;
		current_node = current_node->next_;
	}

	return nullptr;
}


void SinglyLinkedList::RemoveByIndex(int index) {

	// Проверка корректности индекса
	std::function<bool(int, int)> func;
	func = [&](int a, int b) { return CompareForCheckIndex(a, b); };
	CheckRange(size_, index, func);

	if (index == 0) {
        Node* node_to_delete = head_;
		DeleteHead(node_to_delete);
        return;
	}
	// Если удаление происходит из середины, то
	// Поскольку нельзя из одного узла получить предыдущий
	// Нужно в функцию передавать передыдущий.
	Node* prev_node = GetElementByIndex(index-1);

	if (prev_node != nullptr) {
		DeleteNextNode(prev_node);

	}
}


void SinglyLinkedList::RemoveByValue(std::string value) {
	
	if (size_ == 0) {
		return;
	}

	if (head_->data_ == value) {
		DeleteHead (head_);

		return;
	}

	Node* prev_node = head_;
	Node* current_node = head_->next_;


	while (current_node != nullptr) {
		if (current_node->data_ == value) {
			DeleteNextNode(prev_node);
			return;
		}

		prev_node = current_node;
		current_node = current_node->next_;
	}
}



void SinglyLinkedList::DeleteHead(Node* node_to_delete) {

	head_ = node_to_delete->next_;

	// Если после удаления узла head стал пустым
	// Значит в списке больше нет узлов
	if (head_ == nullptr) {
		tail_ = nullptr;
	}
	delete node_to_delete;
	size_ = size_ - 1;
	return;
}


void SinglyLinkedList::DeleteNextNode(Node* prev_node) {

	Node* left = prev_node;
	Node* node_to_delete = left->next_;
    Node* right = node_to_delete->next_;

	if (node_to_delete == tail_) {
		tail_ = left;
		tail_->next_ = nullptr;
		
	}
	// Удаление элемента в середине
	else {
		left->next_ = right;
	}

	delete node_to_delete;
	size_ = size_ - 1;
}


int SinglyLinkedList::LinearSearch(std::string value) {
	Node* current_node = head_;
	int current_index = 0;

	while (current_node != nullptr) {
		if (current_node->data_ == value) {

			return current_index;

		}
		current_node = current_node->next_;
		current_index = current_index + 1;
	}
	return -1;
}

