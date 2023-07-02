#include <iostream>
#include <fstream>

class Exception {
protected:
    std::string error;
public:
    Exception() :
        error("Вызванна ошибка: "){}
    virtual std::string ShowError()
    {
        return error;
    }
};

class Dev_zero : public Exception {
    std::string D_error;
public:
    Dev_zero() :
        D_error("деление на ноль!!!") {}
    virtual std::string ShowError()
    {
        return error + D_error;
    }
};

class Memmory : public Exception {
    std::string M_error;
public:
    Memmory() :
        M_error("нехватка памяти!!!") {}
    virtual std::string ShowError()
    {
        return error + M_error;
    }
};

class OpenFile : public Exception {
    std::string Op_error;
public:
    OpenFile() :
        Op_error("невозможно открыть файл!!!") {}
    virtual std::string ShowError()
    {
        return error + Op_error;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    try {
        int str[20];
        for (int ii = 0; ii < 25; ii++) {
            if (ii >= 20) throw Memmory();
            str[ii] = ii;
        }
        char path[120] = "text.txt";
        std::ifstream in(path,std::ios::in | std::ios::binary);
        if (!in) 
            throw OpenFile();
        int a, b;
        std::cin >> a;
        std::cin >> b;
        if (a == 0 || b == 0)
            throw Dev_zero();
    }
    catch(Exception& e){
        std::cout << e.ShowError();
    }
}
