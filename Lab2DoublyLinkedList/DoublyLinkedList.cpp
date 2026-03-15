#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
	head_ = nullptr;
	tail_ = nullptr;
	size_ = 0;
}


DoublyLinkedList::~DoublyLinkedList() {
	Node* current_node = head_;

	while (current_node != nullptr) {
		DeleteNode(current_node);
	}
}


const Node* DoublyLinkedList::GetHead() {
	return head_;
}


const Node* DoublyLinkedList::GetTail() {
	return tail_;
}


const int DoublyLinkedList::GetSize() {
	return size_;
}


const void DoublyLinkedList::PrintList() {
	Node* current_node = head_;
	
	cout << "Элементы списка: " << endl;

	while (current_node != nullptr) {
		cout << current_node->data_<< " ";
		current_node = current_node->next_;
	}

	cout << endl;
}


void DoublyLinkedList::CheckRange(int size, int index, std::function<bool(int, int)> compare_mode) {
	
	if (index < 0) {
		throw std::out_of_range("Индекс должен быть больше 0. ");
	}
	else if (compare_mode(size, index)) {
		throw std::out_of_range("Слишком большой индекс. ");
	}
}


bool DoublyLinkedList::CompareForCheckIndex(int size, int index) {
	return size <= index;
}


bool DoublyLinkedList::CompareForAddElement(int size, int index) {
	return size < index;
}


void DoublyLinkedList::AddElement(int index, int value) {
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
			new_node->next_ = nullptr;
			new_node->prev_ = nullptr;

			head_ = new_node;
			tail_ = new_node;

			size_ = size_ + 1;
			return;
		}
		
		head_->prev_ = new_node;
		new_node->next_ = head_;
		new_node->prev_ = nullptr;

		head_ = new_node;

	}
	// Вставка в середину списка
	else if (index != size_){
		Node* node_to_move = GetElementByIndex(index);

		new_node->next_ = node_to_move;
		new_node->prev_ = node_to_move->prev_;
		new_node->prev_->next_ = new_node;
		node_to_move->prev_ = new_node;

	}
	// Вставка в конец списка
	else {
		tail_->next_ = new_node;
		new_node->prev_ = tail_;
		new_node->next_ = nullptr;

		tail_ = new_node;

	}

	size_ = size_ + 1;
	return;
}


void DoublyLinkedList::SetElement(int index, int value) {
	Node* node = GetElementByIndex(index);

	node->data_ = value;
}


Node* DoublyLinkedList::GetElementByIndex(int index) {
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


void DoublyLinkedList::RemoveByIndex(int index) {
	// GetElementByIndex сам проверит индекс
	Node* node_to_delete = GetElementByIndex(index);

	if (node_to_delete != nullptr) {
		DeleteNode(node_to_delete);

	}
}


void DoublyLinkedList::RemoveByValue(int value) {
	Node* current_node = head_;

	while (current_node != nullptr) {
		if (current_node->data_ == value) {
			DeleteNode(current_node);
			return;
		}
		current_node = current_node->next_;
	}
}


void DoublyLinkedList::DeleteNode(Node* node_to_delete) {

	// Удаление head
	if (node_to_delete == head_) {
		head_ = node_to_delete->next_;

		// Если после удаления узла head стал пустым
		// Значит в списке больше нет узлов
		if (head_ != nullptr) {
			head_->prev_ = nullptr;
		}
		else {
			tail_ = nullptr;
		}
	}
	else if (node_to_delete == tail_) {
		tail_ = node_to_delete->prev_;

		// Если после удаления узла tail стал пустым
		// Значит в списке больше нет узлов
		if (tail_ != nullptr) {
			tail_->next_ = nullptr;
		}
		else {
			head_ = nullptr;
		}
	}

	// Удаление элемента в середине
	else {
		node_to_delete->prev_->next_ = node_to_delete->next_;
		node_to_delete->next_->prev_ = node_to_delete->prev_;
	}

	delete node_to_delete;
	size_ = size_ - 1;
}


int DoublyLinkedList::LinearSearch(int value) {
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


void DoublyLinkedList::Sort() {
	// Если в списке один элемент, то он уже отсортирован.
	// Если нет элементов, то сортировка тоже не требуется. 
	if (size_ < 2) {
		return; 
	}

	Node* current = head_;

	while (current->next_ != nullptr) {
		
		if (current->data_ > current->next_->data_) {

			// current это указатель на большее число, а не на его индекс
			// После того, как current и current->next обменяются
			// большее число съедет вправо, а current->next - влево
			// Чтобы сохранить место в списке нужно отдельно сохранить current->next
			Node* future_left_node = current->next_;
			SwapNeighborNodes(current, future_left_node);

			// Если текущий узел не head, делает шаг назад
			if (future_left_node->prev_ != nullptr) {
				current = future_left_node->prev_;
				continue;
			}
			// current теперь будет на том же месте в списке.
			current = future_left_node;
		}
		current = current->next_;
	}
}


void DoublyLinkedList::SwapNeighborNodes(Node* left, Node* right) {
	
	Node* p = left->prev_;
	Node* n = right->next_;

	// Если left это head
	if (p == nullptr) {
		head_ = right;
	}
	else {
		p->next_ = right;
	}
	// Если right это tail
	if (n == nullptr) {
		tail_ = left;
	}
	else {
		n->prev_ = left;
	}

	right->prev_ = p;
	right->next_ = left;
	left ->prev_ = right;
	left ->next_ = n;
}

