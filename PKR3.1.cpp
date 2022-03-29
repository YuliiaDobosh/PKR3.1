#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "����'�����i �����", "I����������", "���������� �� ������i��", "�i���� �� i����������", "������� ��������" };

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
        cout << "��i�����: ";
        cin >> s[i].prizv;
        cout << "����: ";
        cin >> s[i].kurs;
        cout << "����i����i��� (0 - ����'�����i �����, 1 - I����������, 2 - ���������� �� ������i��, 3 - �i���� �� i����������, ������� ��������) ";
        cin >> sp;
        s[i].spec = (Spec)sp;
        cout << "��i��� � �i����: ";
        cin >> s[i].physics;
        cout << "��i��� � ����������: ";
        cin >> s[i].math;
        if (s[i].spec == 0) {
            cout << "��i��� � �������������: ";
            cin >> s[i].progr;
        }
        else if (s[i].spec == 1) {
            cout << "��i��� � ��������� �����i�: ";
            cin >> s[i].numb;
        }
        else {
            cout << "��i��� � �������i��: ";
            cin >> s[i].ped;
        }
    }
}
void print(Student* s, int amSt)
{
    cout << "=========================================================================================================================="
        << endl;
    cout << "| � |    ��i�����   | ���� |      ����i����i���     | �i���� | ���������� | ������������� | �������i ������ | �������i�� |"
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
    cout << "�i���i��� �������i�: ";
    cin >> N;
    Student* s = new Student[N];
    create(s, N);
    print(s, N);

    cout << "Ki���i��� �������i�, ��i ������� �� <5>: " << AllFive(s, N) << endl;
    cout << "�i������ �������i� , � ���� � �i����  <5>: " <<ProsPhysik (s, N) << endl;

    return 0;

}
