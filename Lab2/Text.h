#pragma once
#include "Paragraph.h"
#include <vector>
#include <iostream>
class Text : public Paragraph
{
private:
	vector<Paragraph*> paragraphs;
public:
	Paragraph* operator[](int index) {
		if (index >= 0 && index < paragraphs.size()) {
			return paragraphs[index];
		}
		else {
			return nullptr;
		}
	}
	Text& operator=(const Text& other) {
		if (this == &other) {
			return *this;
		}
		for (Paragraph* paragraph : paragraphs) {
			delete paragraph;
		}
		paragraphs.clear();
		for (int i = 0; i < other.paragraphs.size(); i++) {
			Paragraph* newParagraph = new Paragraph(*(other.paragraphs[i]));
			paragraphs.push_back(newParagraph);
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Text& text);
	friend istream& operator>>(istream& in, Text& text);
	Text(string _text);
	Text(const Text& object);
	Text();
	~Text();
	void addParagraph(string _paragraph);
	void alignParagraph();
	void print();
	void clear();
	vector<Word*> copy(int firstWord, int numberOfWords, int paragraph);
	vector<Word*> cut(int firstWord, int numberOfWords, int paragraph);
	void paste(vector<Word*> words, int position, int paragraph);
	int size() {
		return paragraphs.size();
	}
};

