#include "Word.h"
#include "Paragraph.h"
#include "Text.h"
#include <iostream>
#include <fstream>
int main()
{
    Text text;
    ifstream inFile(R"(C:\Users\Romaro\Desktop\Studying\OOP\Lab2(input).txt)");
    ofstream outFile(R"(C:\Users\Romaro\Desktop\Studying\OOP\Lab2(output).txt)");
    inFile >> text;
    text.alignParagraph();
    vector<Word*> copy = text.cut(0, 4, 0);
    text.paste(copy, 0, 4);
    outFile << text;
    inFile.close();
    outFile.close();
    Text textCopy(text);
    text.addParagraph("!!!!!!!!!!!!!!!!");
    cout << "Original text" << endl;
    text.print();
    cout << "Copied text" << endl;
    textCopy.print();
    textCopy = text;
    cout << "Original text" << endl;
    text.print();
    cout << "Copied text" << endl;
    textCopy.print();
    
}
//Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.Enim facilisis gravida neque convallis a.Sociis natoque penatibus et magnis dis parturient.Congue mauris rhoncus aenean vel.
//
//In hac habitasse platea dictumst quisque sagittis purus sit amet.Praesent tristique magna sit amet purus gravida quis.In metus vulputate eu scelerisque felis imperdiet.Nisi scelerisque eu ultrices vitae auctor.Enim nulla aliquet porttitor lacus luctus accumsan tortor posuere.Tincidunt nunc pulvinar sapien et ligula ullamcorper malesuada.
//
//Tristique risus nec feugiat in fermentum posuere urna.Aliquet eget sit amet tellus cras.Massa sapien faucibus et molestie ac feugiat sed.Bibendum at varius vel pharetra vel turpis.Consectetur libero id faucibus nisl tincidunt eget nullam non nisi.Dui sapien eget mi proin.Et leo duis ut diam quam nulla porttitor massa id.Sollicitudin tempor id eu nisl nunc mi ipsum.Arcu ac tortor dignissim convallis aenean et tortor at risus.
//
//Porttitor eget dolor morbi non arcu.Eget arcu dictum varius duis at consectetur lorem donec massa.Nisi scelerisque eu ultrices vitae.Porttitor rhoncus dolor purus non.Sagittis id consectetur purus ut faucibus.Aliquet bibendum enim facilisis gravida neque convallis a cras.Dictumst vestibulum rhoncus est pellentesque.Non tellus orci ac auctor augue.Eget gravida cum sociis natoque penatibus et.
//
//Dolor purus non enim praesent elementum facilisis.Pharetra diam sit amet nisl suscipit adipiscing bibendum est.Elementum tempus egestas sed sed risus pretium quam vulputate.Ut sem nulla pharetra diam sit amet nisl suscipit.Sed viverra ipsum nunc aliquet bibendum enim.Volutpat diam ut venenatis tellus in.Sed egestas egestas fringilla phasellus faucibus scelerisque eleifend.
