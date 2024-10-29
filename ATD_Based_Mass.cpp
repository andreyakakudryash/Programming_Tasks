#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
const int MAX_SIZE = 100;

class Stack {
private:
    string arr[MAX_SIZE];
    int count;

public:
    Stack() {
        count = 0;
        push("������� 1");
        push("������� 2");
        push("������� 3");
        push("������� 4");
    }

    void push(const string& task) {
        if (count < MAX_SIZE) {
            arr[count++] = task;
        }
        else {
            cout << "���� �������� ����� ����������� ���������� ���������� ���������" << endl;
        }
    }

    string pop() {
        if (!isEmpty()) {
            return arr[--count];
        }
        else {
            return "���� ����!";
        }
    }

    string last() {
        if (!isEmpty()) {
            return arr[count - 1];
        }
        else {
            return "���� ����!";
        }
    }

    bool isEmpty() {
        return count == 0;
    }

    void print() {
        cout << "���� ���������: ";
        for (int i = 0; i < count; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


class Queue {
private:

    string arr[MAX_SIZE];
    int front, end;

public:
    Queue() {
        front = 0;
        end = 0;
        enqueue("������ 1");
        enqueue("������ 2");
        enqueue("������ 3");
        enqueue("������ 4");
    }

    void enqueue(const string& task) {
        if (end < MAX_SIZE) {
            arr[end++] = task;
        }
        else {
            cout << "������� �����������!" << endl;
        }
    }

    string dequeue() {
        if (!isEmpty()) {
            return arr[front++];
        }
        else {
            return "������� �����!";
        }
    }

    string first() {
        if (!isEmpty()) {
            return arr[front];
        }
        else {
            return "������� �����!";
        }
    }

    bool isEmpty() {
        return front == end;
    }

    void print() {
        cout << "������� �����: ";
        for (int i = front; i < end; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


class List {
private:

    string arr[MAX_SIZE];
    int count;

public:
    List() {
        count = 0;
        insert("������� 1", 0);
        insert("������� 2", 1);
        insert("������� 3", 2);
        insert("������� 4", 3);

    }

    void insert(const string& task, int pos) {
        if (count >= MAX_SIZE) {
            cout << "������ ����������" << endl;
            return;
        }

        if (pos < 0 || pos > count) {
            cout << "�������� ������" << endl;
            return;
        }

        for (int i = count - 1; i >= pos; i--) {
            arr[i + 1] = arr[i];
        }
        arr[pos] = task;
        count++;
    }

    void remove(int pos) {
        if (pos < 0 || pos >= count) {
            cout << "�������� ������!" << endl;
            return;
        }

        for (int i = pos; i < count - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    void print() {
        cout << "������ ���������: ";
        for (int i = 0; i < count; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


class Set {
private:

    string arr[MAX_SIZE];
    bool exists[MAX_SIZE]; 
    int count;

public:
    Set() {
        count = 0;

        for (int i = 0; i < MAX_SIZE; i++) {
            exists[i] = false; 
        }

        add("������ 1");
        add("������ 2");
        add("������ 3");
        add("������ 4");
    }

    void add(const string& task) {
        for (int i = 0; i < count; ++i) {
            if (arr[i] == task) {
                cout << "������ ��� ���������� � ���������!" << endl;
                return;
            }
        }
        if (count < MAX_SIZE) {
            arr[count] = task;
            exists[count] = true;
            count++;
        }
        else {
            cout << "��������� �����������!" << endl;
        }
    }

    void remove(const string& task) {
        for (int i = 0; i < count; ++i) {
            if (arr[i] == task) {
                exists[i] = false;
                cout << "������ �������: " << task << endl;
                return;
            }
        }
        cout << "������ �� ������� � ���������!" << endl;
    }

    void print() {
        cout << "��������� �����: ";
        for (int i = 0; i < count; ++i) {
            if (exists[i]) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

void stackMenu(Stack& stack) {
    int stackChoice;
    do {
        cout << "\n���� �����:\n";
        cout << "1. Push\n2. Pop\n3. Last\n4. Print\n0. �����\n";
        cin >> stackChoice;

        switch (stackChoice) {
        case 1: {
            string task;
            cout << "������� �������: ";
            cin.ignore();
            getline(cin, task);
            stack.push(task);
            break;
        }
        case 2:
            cout << "��������� �������: " << stack.pop() << endl;
            break;
        case 3:
            cout << "��������� �������: " << stack.last() << endl;
            break;
        case 4:
            stack.print();
            break;
        }
    } while (stackChoice != 0);
}


void queueMenu(Queue& queue) {
    int queueChoice;
    do {
        cout << "\n���� �������:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. First\n4. Print\n0. �����\n";
        cin >> queueChoice;

        switch (queueChoice) {
        case 1: {
            string task;
            cout << "������� ������: ";
            cin.ignore();
            getline(cin, task);
            queue.enqueue(task);
            break;
        }
        case 2:
            cout << "��������� ������: " << queue.dequeue() << endl;
            break;
        case 3:
            cout << "������ ������: " << queue.first() << endl;
            break;
        case 4:
            queue.print();
            break;
        }
    } while (queueChoice != 0);
}


void listMenu(List& list) {
    int listChoice;
    do {
        cout << "\n���� ������:\n";
        cout << "1. Add\n2. Remove\n3. Print\n0. �����\n";
        cin >> listChoice;

        switch (listChoice) {
        case 1: {
            string task;
            int pos;
            cout << "������� �������: ";
            cin.ignore();
            getline(cin, task);
            cout << "������� �������, � ������� ���������� �������� �������: ";
            cin >> pos;
            list.insert(task, pos);
            break;
        }
        case 2: {
            int index;
            cout << "������� ������ ��� ��������: ";
            cin >> index;
            list.remove(index);
            break;
        }
        case 3:
            list.print();
            break;
        }
    } while (listChoice != 0);
}

void setMenu(Set& set) {
    int setChoice;
    do {
        cout << "\n���� ���������:\n";
        cout << "1. Add\n2. Print\n0. �����\n";
        cin >> setChoice;

        switch (setChoice) {
        case 1: {
            string task;
            cout << "������� ������: ";
            cin.ignore();
            getline(cin, task);
            set.add(task);
            break;
        }
        case 2:
            set.print();
            break;
        }
    } while (setChoice != 0);
}


void mainMenu() {
    Stack stack;
    Queue queue;
    List list;
    Set set;
    int choice;

    do {
        cout << "\n����:\n";
        cout << "1. ����\n";
        cout << "2. �������\n";
        cout << "3. ������\n";
        cout << "4. ���������\n";
        cout << "0. �����\n";
        cout << "�������� ���: ";
        cin >> choice;

        switch (choice) {
        case 1:
            stackMenu(stack);
            break;
        case 2:
            queueMenu(queue);
            break;
        case 3:
            listMenu(list);
            break;
        case 4:
            setMenu(set);
            break;
        }
    } while (choice != 0);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    mainMenu();
    return 0;
}