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
        push("Элемент 1");
        push("Элемент 2");
        push("Элемент 3");
        push("Элемент 4");
    }

    void push(const string& task) {
        if (count < MAX_SIZE) {
            arr[count++] = task;
        }
        else {
            cout << "Стек превысил лимит максимально возможного количества элементов" << endl;
        }
    }

    string pop() {
        if (!isEmpty()) {
            return arr[--count];
        }
        else {
            return "Стек пуст!";
        }
    }

    string last() {
        if (!isEmpty()) {
            return arr[count - 1];
        }
        else {
            return "Стек пуст!";
        }
    }

    bool isEmpty() {
        return count == 0;
    }

    void print() {
        cout << "Стек элементов: ";
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
        enqueue("Задача 1");
        enqueue("Задача 2");
        enqueue("Задача 3");
        enqueue("Задача 4");
    }

    void enqueue(const string& task) {
        if (end < MAX_SIZE) {
            arr[end++] = task;
        }
        else {
            cout << "Очередь переполнена!" << endl;
        }
    }

    string dequeue() {
        if (!isEmpty()) {
            return arr[front++];
        }
        else {
            return "Очередь пуста!";
        }
    }

    string first() {
        if (!isEmpty()) {
            return arr[front];
        }
        else {
            return "Очередь пуста!";
        }
    }

    bool isEmpty() {
        return front == end;
    }

    void print() {
        cout << "Очередь задач: ";
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
        insert("Элемент 1", 0);
        insert("Элемент 2", 1);
        insert("Элемент 3", 2);
        insert("Элемент 4", 3);

    }

    void insert(const string& task, int pos) {
        if (count >= MAX_SIZE) {
            cout << "Список переполнен" << endl;
            return;
        }

        if (pos < 0 || pos > count) {
            cout << "Неверный индекс" << endl;
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
            cout << "Неверный индекс!" << endl;
            return;
        }

        for (int i = pos; i < count - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    void print() {
        cout << "Список элементов: ";
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

        add("Задача 1");
        add("Задача 2");
        add("Задача 3");
        add("Задача 4");
    }

    void add(const string& task) {
        for (int i = 0; i < count; ++i) {
            if (arr[i] == task) {
                cout << "Задача уже существует в множестве!" << endl;
                return;
            }
        }
        if (count < MAX_SIZE) {
            arr[count] = task;
            exists[count] = true;
            count++;
        }
        else {
            cout << "Множество переполнено!" << endl;
        }
    }

    void remove(const string& task) {
        for (int i = 0; i < count; ++i) {
            if (arr[i] == task) {
                exists[i] = false;
                cout << "Задача удалена: " << task << endl;
                return;
            }
        }
        cout << "Задача не найдена в множестве!" << endl;
    }

    void print() {
        cout << "Множество задач: ";
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
        cout << "\nМеню стека:\n";
        cout << "1. Push\n2. Pop\n3. Last\n4. Print\n0. Назад\n";
        cin >> stackChoice;

        switch (stackChoice) {
        case 1: {
            string task;
            cout << "Введите элемент: ";
            cin.ignore();
            getline(cin, task);
            stack.push(task);
            break;
        }
        case 2:
            cout << "Удаленный элемент: " << stack.pop() << endl;
            break;
        case 3:
            cout << "Последний элемент: " << stack.last() << endl;
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
        cout << "\nМеню очереди:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. First\n4. Print\n0. Назад\n";
        cin >> queueChoice;

        switch (queueChoice) {
        case 1: {
            string task;
            cout << "Введите задачу: ";
            cin.ignore();
            getline(cin, task);
            queue.enqueue(task);
            break;
        }
        case 2:
            cout << "Удаленная задача: " << queue.dequeue() << endl;
            break;
        case 3:
            cout << "Первая задача: " << queue.first() << endl;
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
        cout << "\nМеню списка:\n";
        cout << "1. Add\n2. Remove\n3. Print\n0. Назад\n";
        cin >> listChoice;

        switch (listChoice) {
        case 1: {
            string task;
            int pos;
            cout << "Введите элемент: ";
            cin.ignore();
            getline(cin, task);
            cout << "Введите позицию, в которую необходимо вставить элемент: ";
            cin >> pos;
            list.insert(task, pos);
            break;
        }
        case 2: {
            int index;
            cout << "Введите индекс для удаления: ";
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
        cout << "\nМеню множества:\n";
        cout << "1. Add\n2. Print\n0. Назад\n";
        cin >> setChoice;

        switch (setChoice) {
        case 1: {
            string task;
            cout << "Введите задачу: ";
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
        cout << "\nМеню:\n";
        cout << "1. Стек\n";
        cout << "2. Очередь\n";
        cout << "3. Список\n";
        cout << "4. Множество\n";
        cout << "0. Выход\n";
        cout << "Выберите АТД: ";
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