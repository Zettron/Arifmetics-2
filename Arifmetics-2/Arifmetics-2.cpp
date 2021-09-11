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
                Suma(bigA, bigB);
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
        cout << "--------------------------\n";
        cout << "Введіть число A: ";
        cin >> A;
        bigA = ConvertToBinary(A);
        cout << "\nВведіть число B: ";
        cin >> B;
        cout << "--------------------------\n";
        bigB = ConvertToBinary(B);
    }

    vector<int> ConvertToBinary(int num)
    {
        vector<int> vec;
        string str;
        int i;
        if (num == numeric_limits<int>::min())
        {
            str = "-1" + string(numeric_limits<int>::digits, '0');
            for (i = 0; i < str.size(); i++)
                vec.push_back((int)str[i] - 48);
            return vec;
        }
        string buffer;
        buffer.reserve(numeric_limits<int>::digits + 1); // +1 для минуса

        bool negative = (num < 0);
        if (negative)
            num = -num;
        do
        {
            buffer += char('0' + num % 2);
            num = num / 2;
        } while (num > 0);

        if (negative)
            buffer += '-';

        str = string(buffer.crbegin(), buffer.crend());

        for (i = 0; i < str.size(); i++)
            vec.push_back((int)str[i] - 48);
        
        //показати число в бінарному вигляді 
        
        //через рядок
        //cout << string(buffer.crbegin(), buffer.crend());
        
        //через вектор
        /*for (i = 0; i < bigA.size(); i++)
            cout << bigA[i];*/
        return vec;
    }

    void Suma(vector<int>& A, vector<int>& B)
    {
        int i, k=0, p;
        int arrSize = max(A.size(), B.size());
        vector<int> R(arrSize + 1);
        p = 0;

        for (i = arrSize - 1; i >= 0; i--)
        {
            k = A[i] + B[i] + p;
            R[i + 1] = k % 2;
            p = k / 2;
        }
        if (p > 0) R[0] = p;
        {
            for (i = 0; i < R.size(); i++)
                bigR[i] = R[i];
        }
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

int main()
{
    setlocale(LC_ALL, "ru");
    int Key, j = 0;
    bool i = false;
    Calculate* c = new Calculate[1000];

    while (1)
    {
        cout << "Виберіть дію\n";
        cout << "1) Переведення у формат великого числа\n";
        if (i == true)
        {
            cout << "2) Додавання чисел\n";
            cout << "3) Віднімання чисел\n";
            cout << "4) Множення, піднесення до квадрату\n";
            cout << "5) Ділення чисел, знаходження остачі\n";
            cout << "6) Піднесення числа до багаторозрядного степеня\n";
            cout << "7) Конвертування числа в символьну строку та обернене перетворення\n";
        }
        cout << "->";
        cin >> Key;
        c[j].Menu(Key);

        i = true;
        j++;
    }
    return 0;
}
