#include "vigenere.h"

Vigenere::Vigenere(QString key_value)
{
    key = key_value.toLower();
}

QString Vigenere::expand_key(int size)
{
    QString temp_key = key;
    int fullstring_c = (size / key.size()) - 1;
    int remstring_c = size % key.size();
    for(int i = 0; i < fullstring_c; i++)
    {
        temp_key.append(key);
    }
    temp_key.append(key.left(remstring_c));
    return temp_key;

}

QString Vigenere::encrypt(QString message, int mode)
{
    QString temp_key = expand_key(message.size());
    QString result;
    for(int i = 0; i < temp_key.size(); i++)
    {
        if (message.toLower().at(i) >= 'a' && message.toLower().at(i) <= 'z')
        {
            int code1 = message.toLower().at(i).unicode() - 97 + mode;
            int code2 = temp_key.at(i).unicode() - 97 + mode;
            result.append(QChar(((code1 + code2 - mode) % 26) + 97));
        }
        else
        {
            result.append(message.toLower().at(i));
        }
    }
    return result;
}

QString Vigenere::decrypt(QString message, int mode)
{
    QString temp_key = expand_key(message.size());
    QString result;
    for(int i = 0; i < temp_key.size(); i++)
    {
       if (message.toLower().at(i) >= 'a' && message.toLower().at(i) <= 'z')
       {
           int code1 = message.toLower().at(i).unicode() - 97 + mode;
           int code2 = temp_key.at(i).unicode() - 97 + mode;
           result.append(QChar(((code1 - code2 + 26 - mode) % 26) + 97));
       }
       else
       {
           result.append(message.toLower().at(i));
       }
    }
    return result;
}
QString Vigenere::encrypt(QString message, QString alphabet, int mode)
{
    QString temp_key = expand_key(message.size());
    QString result;
    for(int i = 0; i < temp_key.size(); i++)
    {
       if (alphabet.toLower().contains(message.toLower().at(i)))
       {
           int code1 = alphabet.indexOf(message.toLower().at(i));
           int code2 = alphabet.indexOf(temp_key.at(i));
           int new_code = (code1 + code2 + mode) % alphabet.size();
           result.append(alphabet.at(new_code));
       }
       else
       {
           result.append(message.toLower().at(i));
       }
    }
    return result;
}
QString Vigenere::decrypt(QString message, QString alphabet, int mode)
{
    QString temp_key = expand_key(message.size());
    QString result;
    for(int i = 0; i < temp_key.size(); i++)
    {
       if (alphabet.toLower().contains(message.toLower().at(i)))
       {
           int code1 = alphabet.indexOf(message.toLower().at(i));
           int code2 = alphabet.indexOf(temp_key.at(i));
           int new_code = (code1 - code2 - mode + alphabet.size()) % alphabet.size();
           result.append(alphabet.at(new_code));
       }
       else
       {
           result.append(message.toLower().at(i));
       }
    }
    return result;
}
