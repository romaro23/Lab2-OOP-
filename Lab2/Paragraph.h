#pragma once
#include "Word.h"
#include <vector>
class Paragraph: public Word
{

public:
	vector<Word*> words;
	Paragraph(string _words);
	Paragraph(const Paragraph& object);
	Paragraph();
	~Paragraph();
	void print();
};

