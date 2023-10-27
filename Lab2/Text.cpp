#include "Text.h"
#include "Word.h"
#include "Symbol.h"
#include <iostream>

Text::Text(string _text) {
	paragraphs.push_back(new Paragraph(_text));
}
Text::Text(const Text& object) {
	for (int i = 0; i < object.paragraphs.size(); i++) {
		Paragraph* newParagraph = new Paragraph(*(object.paragraphs[i]));
		paragraphs.push_back(newParagraph);
	}
}
Text::Text() {}
Text::~Text() {
	for (Paragraph* paragraph : paragraphs) {
		if (!paragraphs.empty()) {
			delete paragraph;
		}
	}
	paragraphs.clear();
}
ostream& operator<<(ostream& out, const Text& text)
{
	for (Paragraph* paragraph : text.paragraphs) {
		for (Word* word : paragraph->words) {
			for (Symbol* symbol : word->symbols) {
				out << symbol->value;
			}
			out << " ";
		}
		out << "\n";
	}
	return out;
}
istream& operator>>(istream& in, Text& text) {
	string input;
	while (getline(in, input) && input != "stop") {
		if (input != "") {
			text.addParagraph(input);
		}
	}
	return in;
}
void Text::clear() {
	for (Paragraph* paragraph : paragraphs) {
		if (!paragraphs.empty()) {
			delete paragraph;
		}
	}
	paragraphs.clear();
}
void Text::print() {
	for (int i = 0; i < paragraphs.size(); i++) {
		paragraphs[i]->print();
		cout << endl;
	}
}
void Text::addParagraph(string _paragraph) {
	paragraphs.push_back(new Paragraph(_paragraph));
}
void Text::alignParagraph() {
	for (int i = 0; i < paragraphs.size(); i++) {
		for (int j = 0; j < 4; j++) {
			if (paragraphs[i]->words[0]->symbols[j]->value != ' ') {
				paragraphs[i]->words[0]->symbols.insert(paragraphs[i]->words[0]->symbols.begin(), new Symbol(' '));
			}
		}
	}
}
vector<Word*> Text::copy(int firstWord, int numberOfWords, int paragraph) {
	vector<Word*> copy;
	for (int i = firstWord; i <= numberOfWords; i++) {
		copy.push_back(new Word(*(paragraphs[paragraph]->words[i])));
	}
	return copy;
}
vector<Word*> Text::cut(int firstWord, int numberOfWords, int paragraph) {
		vector<Word*> copy;
		for (int i = firstWord; i < numberOfWords + firstWord; i++) {
			copy.push_back(new Word(*(paragraphs[paragraph]->words[i])));
			paragraphs[paragraph]->words[i]->clear();
		}
		return copy;
}
void Text::paste(vector<Word*> _words, int position, int paragraph) {
	paragraphs[paragraph]->words.insert(paragraphs[paragraph]->words.begin() + position, _words.begin(), _words.end());
}


