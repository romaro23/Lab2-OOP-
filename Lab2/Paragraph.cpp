#include "Paragraph.h"
#include "Word.h"
Paragraph::Paragraph(string _words) {
	string temp;
	for (int i = 0; i < _words.size(); i++) {	
		if (_words[i] == ' ') {
			Word* word = new Word(temp);
			words.push_back(word);
			temp.clear();
			while (_words[i] == ' ') {
				i++;
			}
		}
		temp.push_back(_words[i]);
	}
	Word* word = new Word(temp);
	words.push_back(word);
}
Paragraph::Paragraph(const Paragraph& object) {
	for (int i = 0; i < object.words.size(); i++) {
		Word* newWord = new Word(*(object.words[i]));
		words.push_back(newWord);
	}
}
Paragraph::Paragraph() {}
Paragraph::~Paragraph() {
	for (Word* word : words) {
		if (!words.empty()) {
			delete word;
		}
	}
	words.clear();
}
void Paragraph::print() {
	for (int i = 0; i < words.size(); i++) {
		words[i]->print();
	}
}