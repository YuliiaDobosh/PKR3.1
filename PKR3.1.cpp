#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "Комп'ютернi науки", "Iнформатика", "Математика та економiка", "Фiзика та iнформатика", "Трудове навчання" };

struct Student {
    string prizv;
    int kurs;
    Spec spec;
    int physics;
    int math;
    union {
        int progr;
        int numb;
        int ped;
    };
};

void create(Student* s, int N) {
    int sp;
    for (int i = 0; i < N; i++) {
        cout << "Прiзвище: ";
        cin >> s[i].prizv;
        cout << "Курс: ";
        cin >> s[i].kurs;
        cout << "Спецiальнiсть (0 - Комп'ютернi науки, 1 - Iнформатика, 2 - Математика та економiка, 3 - Фiзика та iнформатика, Трудове навчання) ";
        cin >> sp;
        s[i].spec = (Spec)sp;
        cout << "Оцiнка з фiзики: ";
        cin >> s[i].physics;
        cout << "Оцiнка з математики: ";
        cin >> s[i].math;
        if (s[i].spec == 0) {
            cout << "Оцiнка з програмування: ";
            cin >> s[i].progr;
        }
        else if (s[i].spec == 1) {
            cout << "Оцiнка з чисельних методiв: ";
            cin >> s[i].numb;
        }
        else {
            cout << "Оцiнка з педагогiки: ";
            cin >> s[i].ped;
        }
    }
}
void print(Student* s, int amSt)
{
    cout << "=========================================================================================================================="
        << endl;
    cout << "| № |    Прiзвище   | Курс |      Спецiальнiсть     | Фiзика | Математика | Програмування | Чисельнi методи | Педагогiка |"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < amSt; i++) {

        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s[i].prizv
            << "| " << setw(5) << right << s[i].kurs
            << "| " << setw(23) << left << strSpec[s[i].spec]
            << "| " << setw(7) << s[i].physics
            << "| " << setw(11) << right << s[i].math;
        if (s[i].spec == 0) {
            cout << "| " << setw(14) << right << s[i].progr
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << " " << "| ";
        }
        else if (s[i].spec == 1) {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << s[i].numb
                << "| " << setw(11) << right << " " << "| ";
        }
        else {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << s[i].ped << "| ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
}
/*int physicsFive(Student* s, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].physics == 5) {
            count += 1;
        }
    }
    return count;
};

int mathFive(Student* s, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].math == 5) {
            count += 1;
        }
    }
    return count;
}

int progrFive(Student* s, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].progr == 5) {
            count += 1;
        }
    }
    return count;
}

int numbFive(Student* s, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].numb == 5) {
            count += 1;
        }
    }
    return count;
}

int pedFive(Student* s, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].ped == 5) {
            count += 1;
        }
    }
    return count;
}*/
double ProsPhysik(Student* s, int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
            if (s[i].physics == 5)
            {
                k++;
            }
    }
    return 100.0 * k / N*1.;
    
}
int AllFive(Student* s, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].physics == 5 && s[i].math == 5 && s[i].numb == 5 && s[i].ped == 5 && s[i].progr==5)
        {
            count += 1;
        }
    }
    return count;
}


int main() {
    setlocale(LC_ALL, "Ukrainian");
    int N;
    cout << "Кiлькiсть студентiв: ";
    cin >> N;
    Student* s = new Student[N];
    create(s, N);
    print(s, N);

    cout << "Kiлькiсть студентiв, якi вчаться на <5>: " << AllFive(s, N) << endl;
    cout << "Вiдсоток студентiв , в яких з фiзики  <5>: " <<ProsPhysik (s, N) << endl;

    return 0;

}
