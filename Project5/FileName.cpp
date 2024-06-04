#include <iostream> 
#include <filesystem> 
#include <cstring> 
using namespace std;
/*1) Написати програму, яка дозволяє користувачеві ввести 5 прізвищ студентів,
а потім знаходить серед них найдовше прізвище.*/
/*int main() {
    const int N = 5;
    const int size = 50;
    int index = 0;
    char surnames[N][size];
    const char* PATH_TO_FILE = "surnames.txt";
    FILE* file;
    if (fopen_s(&file, PATH_TO_FILE, "w") == 0)\
    {
        for (int i = 0; i < N; ++i)
        {
            cout << "Enter the " << (i + 1) << " name: ";
            cin.getline(surnames[i], size);
            fprintf(file, "%s\n", surnames[i]);
        }
        fclose(file);
    }
    if (fopen_s(&file, PATH_TO_FILE, "r") == 0)
    {

        for (int i = 1; i < N; ++i) {
            if (strlen(surnames[i]) > strlen(surnames[index])) {
                index = i;
            }
        }
        fclose(file);
    }

    cout << "Longest name: " << surnames[index] << endl;

    return 0;
}*/
/*2) Створіть додаток для підрахунку кількості входжень
підрядка в рядок. Користувач вводить вихідний рядок і
слово для пошуку. Додаток відображає результат пошуку.
Наприклад:
користувач ввів: Why she had to go. I don't know, she
wouldn't say;
підрядок для пошуку: she;
результат пошуку: 2.*/
int count_similar(const char* str, const char* str2) 
{
    int count = 0;
    int length1 = strlen(str);
    int length2 = strlen(str2);

    for (int i = 0; i <= length1 - length2; i++)
    {
        bool match = true;
        for (int j = 0; j < length2; j++)
        {
            if (str[i + j] != str2[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            ++count;
            i += length2 - 1;
        }
    }
    return count;
}

int main() 

{
   // int count = 0;
    const int size = 1000;
    char str[size];
    char str2[size];

    cout << "Enter your text: ";
    cin.getline(str, size);

    cout << "Enter the text to search for: ";
    cin.getline(str2, size);

    int similar = count_similar(str, str2);
    cout << "The part '" << str2 << "' occurs " << count_similar << " times in the main text" << endl;

    return 0;
}
