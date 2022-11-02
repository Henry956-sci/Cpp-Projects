#include <iostream>
#include "browserhistory.h"

using namespace std;

BrowserHistory::BrowserHistory(string default_url)
{
	head = new Node;                                              //sets head as a blank node
	head->url = default_url;                                      //fills node with data
	head->next = nullptr;                                         //sets next to nullptr
	head->prev = nullptr;                                         //sets prev to nullptr

	current = head;                                               //sets current to head
	tail = nullptr;                                               //sets tail to nullptr
}

string BrowserHistory::current_url()
{
	if (current != nullptr)                                       //if current is
		return current->url;
	else
		return "";
}

void BrowserHistory::go_to_url(string url)
{
	if (head == nullptr)
	{
		head = new Node;
		head->url = url;
		head->next = nullptr;
		head->prev = nullptr;

		current = head;
	}
	else if (head->next == nullptr)
	{
		tail = new Node;
		tail->url = url;
		head->next = tail;
		tail->prev = head;
		tail->next = nullptr;

		current = tail;
	}
	else
	{
		Node* ptr;
		  if (current->next != nullptr)
		  {
			  ptr = current->next;
			  while (ptr != nullptr)
			  {
				  Node* killptr = ptr;
				  ptr = ptr->next;
				  delete killptr;
			  }
			current->next = nullptr;
			tail = current;
		}

		current->next = new Node;
		current = current->next;
		current->url = url;
		current->prev = tail;
		current->next = nullptr;

		tail = current;
	}
}


void BrowserHistory::back()
{
	if (can_go_back())
		current = current->prev;
}

bool BrowserHistory::can_go_back()
{
	return (current->prev != nullptr);
}

int BrowserHistory::past_url_count()
{
	Node* ptr = current;
	int count = 0;

	while (ptr->prev != nullptr)
	{
		ptr = ptr->prev;
		count++;
	}

	return count;
}

void BrowserHistory::forward()
{
	if (can_go_forward())
		current = current->next;
}

bool BrowserHistory::can_go_forward()
{
	return (current->next != nullptr);
}

int BrowserHistory::future_url_count()
{
	Node* ptr = current;
	int count = 0;

	while (ptr->next != nullptr)
	{
		ptr = ptr->next;
		count++;
	}

	return count;
}