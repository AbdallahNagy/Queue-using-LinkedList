#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int _data) {
		data = _data;
		next = NULL;
	}

};

class Queue
{
private:
	Node *head, *tail;

public:
	Queue() {
		head = tail = NULL;
	}

	void enqueue(int _data) {
		Node* node = new Node(_data);

		if (head == NULL) {
			head = tail = node;
			return;
		}

		tail->next = node;
		tail = node;
	}

	int dequeue(int &deletedItem) {
		if (head != NULL) {
			deletedItem = head->data;
			head = head->next;
			
			return 1;
		}

		return 0;
	}

	void display() {
		Node* curr = head;

		while (curr != NULL) {
			cout << curr->data << "   ";
			curr = curr->next;
		}
	}

};


int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);

	int data;
	q.dequeue(data);

	cout << data <<endl;
	q.display();

	return 0;
}
