#pragma once
#include "Symbol.h"
#include <vector>
using namespace std;
class Word : public Symbol {

public:
	vector<Symbol*> symbols;
	Word(string _word);
	Word(const Word& object);
	Word();
	~Word();
	void print();
	void clear();
};

