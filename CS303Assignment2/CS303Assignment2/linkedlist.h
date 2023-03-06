#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


template <typename item_Type>
struct Node {
	item_Type data;
	Node* next;
};

template <typename item_Type>
class LinkedList 
{
	private:
		Node<item_Type>* head;
		Node<item_Type>* tail;
		int num_Items;
	public:


		void display() {
			if (empty()) {
				cout << "List is empty" << endl;
			}
			else {
				Node<item_Type>* tempNode = head;
				while (tempNode != nullptr) {
					cout << tempNode->data << " ";
					tempNode = tempNode->next;
				}
				cout << endl;
			}
		};

		item_Type ask() {
			item_Type input;
			cout << "Enter an input to be used: ";
			
			cin >> input;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			
			return input;

		};

		LinkedList() {
			head = nullptr;
			tail = nullptr;
			num_Items = 0;
		};

		~LinkedList() {
			while (head != nullptr) {
				Node<item_Type>* tempNode = head;
				head = head->next;
				delete tempNode;
			}
		};

		void push_front() {
			item_Type item = ask();
			Node<item_Type>* tempNode = new Node<item_Type>;
			tempNode->data = item;
			tempNode->next = head;
			head = tempNode;
			if (tail == nullptr) {
				tail = head;
			}
			num_Items++;
		};

		void push_back() {
			item_Type item = ask();
			Node<item_Type>* tempNode = new Node<item_Type>;
			tempNode->data = item;
			tempNode->next = nullptr;
			if (empty()) {
				head = tempNode;
			}
			else {
				tail->next = tempNode;

			}
			tail = tempNode;
			num_Items++;
		};

		void pop_front() {
			if (empty()) {
				cout << "List is empty" << endl;
			}
			else {
				Node<item_Type>* tempNode = head;
				head = head->next;
				delete tempNode;
				if (head == nullptr) {
					tail = nullptr;
				}
				num_Items--;
			}

		};

		void pop_back() {
			if (empty()) {
				cout << "List is empty" << endl;
			}
			else {
				if (head == tail) {
					delete tail;
					head = nullptr;
					tail = nullptr;
					num_Items--;
				}
				else {
					Node<item_Type>* temp = head;
					while (temp->next != tail) {
						temp = temp->next;
					}
					temp->next = nullptr;
					delete tail;
					tail = temp;
					num_Items--;
				}
			}

		};

		item_Type front() {
			if (empty()) {
				cout << "List is empty" << endl;
			}
			else
				return head->data;
		};

		
		item_Type back() {
			if (empty()) {
				cout << "List is empty" << endl;
			}
			else
				return tail->data;
		};

		
		bool empty() {
			return num_Items == 0;
		};

		void insert(const item_Type& item, size_t indexNum) {
			//item = ask();
			if (indexNum == 0) {
				
				push_front();
				
			}
			else if (indexNum > num_Items) {
				push_back();
				
			}
			else if(indexNum < num_Items && indexNum > 0) {
				item_Type item = ask();
				Node<item_Type>* temp = head;
				for (int i = 0; i < indexNum - 1; i++) {
					temp = temp->next;
				}
				Node<item_Type>* insertNode = new Node<item_Type>;
				insertNode->data = item;
				insertNode->next = temp->next;
				temp->next = insertNode;
				num_Items++;
			}
		};

		bool remove(size_t indexNum) {
			if (indexNum >= num_Items) {
				cout << "Index input is out of range" << endl;
				return false;
			}
			else {
				if (indexNum == 0) {
					pop_front();
					cout << "Index Num: " << indexNum << " Removed" << endl;
					return true;
				}
				else {
					Node<item_Type>* temp = head;
					for (int i = 0; i < indexNum - 1; i++) {
						temp = temp->next;
					}
					Node<item_Type>* temp2 = temp->next;
					temp->next = temp2->next;
					if (temp2 == tail) {
						tail = temp;
					}
					delete temp2;
					num_Items--;
					cout << "Index Num: " << indexNum << " Removed" << endl;
					return true;
				}
			}

		};

		int find(const item_Type& item) {
			
			Node<item_Type>* temp = head;
			int numIndex = 0;
			while (temp != nullptr) {
				if (temp->data == item) {
					cout << "Found at index: ";
					return numIndex;
				}
				numIndex++;
				temp = temp->next;
			}
			cout << "Unable to find the item, the size of the list is: ";
			return num_Items;

		};

};