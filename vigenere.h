#ifndef VIGENERE_H
#define VIGENERE_H

#include <QString>

class Vigenere
{
private:
    QString key;
    QString expand_key(int size);

public:
    Vigenere(QString key_value);
    QString encrypt(QString message, int mode = 0);
    QString decrypt(QString message, int mode = 0);
    QString encrypt(QString message, QString alphabet, int mode = 0);
    QString decrypt(QString message, QString alphabet, int mode = 0);
};

#endif // VIGENERE_H
