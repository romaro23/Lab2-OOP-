#include "Symbol.h"
Symbol::Symbol(char _value) {
	value = _value;
}
Symbol::Symbol() {}
void Symbol::print() {
	cout << value;
}
