/**@mainpage Отчёт к Лабораторной работе №5 
 * @brief Методы программирования. Лабораторная работа №5. Недомолкин И. Э. СКБ201
 * @section intro Введение
 * Отчёт к лабораторной работе №5 по методам программирования. Включающий в себя документацию по коду сгенерированную doxygen, ссылку на репозиторий с кодом программы. 
 * @section description Описание 
 * Создал интерфейс управления классом std::list с помощью шаблона структуры. 
 * @section Link Исходный код программы
 * Ссылка на репозиторий Github с кодов, данными и результатами https://github.com/Nedomolkin-Ilya/Programming-Techniques-lab-5.
 */
#include <iostream> 
#include <list>

using namespace std;

template<class Type> 
struct Stack{ 
    list<Type> data; 
public: 
    
    void push(Type a){
        data.push_back(a); 
    }
    

    void pop() {
        if(empty()) 
            throw out_of_range("Stack is empty");
        data.pop_back();
    }

    Type last_el(){ 
        return data.back();
    }

    bool empty(){ 
        return data.empty();
    }
};

int main(){ 
    Stack<int> stack; 

    for(int i = 0; i < 10000; i++) stack.push(i);

    while(!stack.empty()){
        stack.pop();
        cout << stack.last_el() << endl;
    }

    try{
        stack.pop();
    }
    catch (out_of_range ex){
        cout << ex.what() << endl;
    }
    

    return 0;
}