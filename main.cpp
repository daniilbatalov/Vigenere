#include <QCoreApplication>
#include "vigenere.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (argc == 5)
    {
        if (a.arguments().at(1) == "-encrypt" && (a.arguments().at(4) == "rot1" || a.arguments().at(4) == "rot0"))
        {
            Vigenere v = Vigenere(a.arguments().at(3));
            std::cout << "Original message: " << a.arguments().at(2).toStdString() << std::endl;
            std::cout << "Used password: " << a.arguments().at(3).toStdString() << std::endl;
            std::cout << "Encrypted message: " << v.encrypt(a.arguments().at(2), a.arguments().at(4).right(1).toInt()).toStdString() << std::endl;
        }
        else if (a.arguments().at(1) == "-decrypt" && (a.arguments().at(4) == "rot1" || a.arguments().at(4) == "rot0"))
        {
            Vigenere v = Vigenere(a.arguments().at(3));
            std::cout << "Encrypted message: " << a.arguments().at(2).toStdString() << std::endl;
            std::cout << "Used password: " << a.arguments().at(3).toStdString() << std::endl;
            std::cout << "Decrypted message: " << v.decrypt(a.arguments().at(2), a.arguments().at(4).right(1).toInt()).toStdString() << std::endl;
        }
        else
        {
            std::cout << "Incorrect usage!" << std::endl;
            std::cout << "Usage: vigenere {-encrypt|-decrypt} <message> <password> {rot1|rot0} [alphabet]" << std::endl;
        }
    }
    else if (argc == 6)
    {
        if (a.arguments().at(1) == "-encrypt" && (a.arguments().at(4) == "rot1" || a.arguments().at(4) == "rot0"))
        {
            Vigenere v = Vigenere(a.arguments().at(3));
            std::cout << "Original message: " << a.arguments().at(2).toStdString() << std::endl;
            std::cout << "Used password: " << a.arguments().at(3).toStdString() << std::endl;
            std::cout << "Encrypted message: " << v.encrypt(a.arguments().at(2), a.arguments().at(5), a.arguments().at(4).right(1).toInt()).toStdString() << std::endl;
        }
        else if (a.arguments().at(1) == "-decrypt" && (a.arguments().at(4) == "rot1" || a.arguments().at(4) == "rot0"))
        {
            Vigenere v = Vigenere(a.arguments().at(3));
            std::cout << "Encrypted message: " << a.arguments().at(2).toStdString() << std::endl;
            std::cout << "Used password: " << a.arguments().at(3).toStdString() << std::endl;
            std::cout << "Decrypted message: " << v.decrypt(a.arguments().at(2), a.arguments().at(5), a.arguments().at(4).right(1).toInt()).toStdString() << std::endl;
        }
        else
        {
            std::cout << "Incorrect usage!" << std::endl;
            std::cout << "Usage: vigenere {-encrypt|-decrypt} <message> <password> {rot1|rot0} [alphabet]" << std::endl;
        }
    }
    else
    {
        std::cout << "Incorrect usage!" << std::endl;
        std::cout << "Usage: vigenere {-encrypt|-decrypt} <message> <password> {rot1|rot0} [alphabet]" << std::endl;
    }
    QCoreApplication::exit(0);
    return 0;
}
