#include "Word.h"
using namespace std;
Word::Word(string _word) {
	for (int i = 0; i < _word.size(); i++) {
		symbols.push_back(new Symbol(_word[i]));
	}
}
Word::Word(const Word& object) {
	for (int i = 0; i < object.symbols.size(); i++) {
		Symbol* newSymbol = new Symbol(*(object.symbols[i]));
		symbols.push_back(newSymbol);
	}
}
Word::Word() {}
Word::~Word() {
	for (Symbol* symbol : symbols) {
		if (!symbols.empty()) {
			delete symbol;
		}
	}
	symbols.clear();
}
void Word::print() {
	for (int i = 0; i < symbols.size(); i++) {
		symbols[i]->print();
	}
	cout << " ";
}
void Word::clear() {
	for (Symbol* symbol : symbols) {
		if (!symbols.empty()) {
			delete symbol;
		}
	}
	symbols.clear();
}