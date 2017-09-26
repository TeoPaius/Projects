// sa verific in destructori memory leakage

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Trie;

class Node {
private:
	short counter;
	short words;
	map<char, Node*> v;
public:
	Node();
	~Node();

	friend class Trie;
};

Node::Node() {
	words   = 0;
	counter = 0;
}

Node::~Node() {
	for (auto it : v) {
		delete it.second;
	}
}

class Trie {
private:
	Node* root;

public:
	Trie();
	~Trie();

	void  add(string& s);
	void  remove(string& s);
	short search(string& s);
	short prefix(string& s);
};

Trie::Trie() {
	root = new Node();
}

Trie::~Trie() {
	delete root;
}

void Trie::add(string& s) {
	auto node = root;
	for (auto it : s) {
		auto& v  = node->v;
		if (v.find(it) == v.end())
			v[it] = new Node();
		node = v[it];
		node->counter++;
	}

	node->words++;
}

void Trie::remove(string& s) {
	auto node = root;
	for (auto it : s) {
		auto& v = node->v;
		if ( v.find(it) == v.end())
			return;
		if (--v[it]->counter == 0) {
			delete v[it];
			v.erase(it);
			return;
		}
		node = v[it];
	}
	node->words--;
}

short Trie::search(string& s) {
	auto node = root;
	for (auto it : s) {
		auto& v = node->v;
		if ( v.find(it) == v.end())
			return 0;
		node = v[it];
	}
	return node->words;
}

short Trie::prefix(string& s) {
	auto node = root;
	short result = 0;
	for (auto it : s) {
		auto& v = node->v;
		if ( v.find(it) == v.end())
			return result;
		if (v[it]->counter == 0)
			return result;
		result++;
		node = v[it];
	}
	return result;
}

int main(int argc, char const *argv[]) {

	Trie problem;

	ifstream in("trie.in");
	ofstream out("trie.out");

	char n;
	string s;

	while (in>>n) {
		in>>s;
		switch (n) {
			case '0' :
				problem.add(s);
				break;
			case '1' :
				problem.remove(s);
				break;
			case '2' :
				out<<problem.search(s)<<"\n";
				break;
			case '3' :
				out<<problem.prefix(s)<<"\n";
				break;
			default:
				break;
		}
	}

	return 0;
}
