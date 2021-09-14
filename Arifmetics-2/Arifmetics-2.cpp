#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

class Calculate
{
public:
    vector<int> bigA, bigB, bigC, bigQ, bigR;
    int i;
    void Menu(int key)
    {
        bool again = false;
        do {
            again = false;
            switch (key)
            {
            case 1:
                WriteNumbers();
                
                break;
            case 2:
                Suma();
                break;
            case 3:
                Difference();
                break;
            case 4:
                Multiplication();
                break;
            case 5:
                DivMod();
                break;
            case 6:
                MultiDigitDegree();
                break;
            case 7:
                ConvertToSymbol();
                ConvertFromSymbol();
                break;
            default:
                cout << "Error menu key\n";
                again = true;
                cout << "->";
                cin >> key;
                break;
            }
        } while (again == true);
    }

    void WriteNumbers()
    {
        int A, B;
        cout << "Введіть число A: ";
        cin >> A;
        bigA = ConvertToBinary(A);

        //вивести у 2 системі A
        for (int i = 0; i < bigA.size(); i++)
            cout << bigA[i];

        cout << "\nВведіть число B: ";
        cin >> B;
        bigB = ConvertToBinary(B);

        //вивести у 2 системі B
        for (int i = 0; i < bigB.size(); i++)
            cout << bigB[i];
        cout << endl;
        system("pause");
    }

    vector<int> ConvertToBinary(int num)
    {
        vector<int>reverseVec, Vec;
        reverseVec.reserve(2048);
        Vec.reserve(2048);
        int k, p = 0, number = num;
        bool end = false;
        while (end == false)
        {
            k = number / 2;
            k *= 2;
            if (k == 0)
            {
                p = 1;
                end = true;
            }
            else if (k == number)
                p = 0;

            else if (k != number)
                p = 1;
            reverseVec.push_back(p);
            number = k/2;         
        }
        for (int i = reverseVec.size(); i > 0; i--)
            Vec.push_back(reverseVec.at(i - 1));

        return Vec;
    }

    void Suma()
    {
        int i, k = 0, p = 0;
        int const arrSize = max(bigA.size(), bigB.size()) + 1;
        vector<int> reverseR;
        reverseR.reserve(2049);
        
        for (i = 0; i <arrSize; i++)
        {
            if (i = arrSize - 1)
                k = p;

            if(i <= bigA.size() - 1 && i <= bigB.size() - 1)
                k = bigA.at(bigA.size() - i - 1) + bigB.at(bigB.size() - i - 1) + p;
            
            else if(i > bigA.size() - 1)
                k = bigB.at(bigB.size() - i - 1) + p;

            else if(i > bigB.size() - 1)
                k = bigA.at(bigA.size() - i - 1) + p;

            if (k <= 1)
                p = 0;

            if (k > 1)
            {
                k -= 2;
                p = 1;
            }

            reverseR.at(i) = k;
        }
        cout << "rverseR\n";
        for (i = 0; i < reverseR.size(); i++)
            cout << reverseR.at(i);

        cout << endl << "bigR = ";
        for (i = reverseR.size(); i > 0; i--)
        {
            bigR.push_back(reverseR.at(i-1));
        }

        for (i = 0; i < bigR.size(); i++)
            cout << bigR.at(i);

        cout << endl;
        system("pause");
    }

    void Difference()
    {
        int KeyMinus;
        cout << "\n1)A - B\n2)B - A\n->";
        cin >> KeyMinus;

        switch (KeyMinus)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        default:
            cout << "Error difference menu key";
        }
    }

    void Multiplication()
    {
        int KeyMultipli;
        cout << "\n1)A*B\n2)A^2\n3)B^2\n->";
        cin >> KeyMultipli;
        switch (KeyMultipli)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        default:
            cout << "Error multiplication menu key";
        }
    }

    void DivMod()
    {
        int KeyDiv;
        cout << "\n1)A / B\n2)B / A\n->";
        cin >> KeyDiv;
        switch (KeyDiv)
        {
        case 1:

            //cout << bigA << " / " << bigB << " = " << bigC << "(ост. " << bigR << ")" << endl;
            break;

        case 2:

            //cout << bigB << " / " << bigA << " = " << bigC << "(ост. " << bigR << ")" << endl;
            break;
        default:
            cout << "Error particle menu key";
        }
    }

    void MultiDigitDegree()
    {

    }

    void ConvertToSymbol()
    {

    }

    void ConvertFromSymbol()
    {

    }
};

void set2048(Calculate c)
{
    c.bigA.reserve(2048);
    c.bigB.reserve(2048);
    c.bigR.reserve(2049);
    c.bigQ.reserve(2049);
    c.bigC.reserve(2049);
}

int main()
{
    setlocale(LC_ALL, "ru");
    int Key;
    bool entered = false;
    Calculate c;
    set2048(c);
    while (1)
    {
        system("cls");
        cout << "Виберіть дію\n";
        cout << "1) Переведення у формат великого числа\n";
        if (entered == true)
        {
            cout << "2) Додавання чисел\n";
            cout << "3) Віднімання чисел\n";
            cout << "4) Множення, піднесення до квадрату\n";
            cout << "5) Ділення чисел, знаходження остачі\n";
            cout << "6) Піднесення числа до багаторозрядного степеня\n";
            cout << "7) Конвертування числа в символьну строку та обернене перетворення\n";
            cout << "0) Вихід\n";
        }
        cout << "->";
        cin >> Key;
        if (Key = 0)
            break;

        system("cls");
        c.Menu(Key);

        entered = true;
    }
    return 0;
}
