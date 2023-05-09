//Подключаем заголовок с декларациями.
#include "include/list.h"
#include "include/database.h"
//Главная функция -z 
int main(int arg_count, char *args[])
{
//создаем объект simpleList класса List
    List simpleList;
    //creating 'dada' obj from Database class
    Database data;
    //Проверяем наличие записей (пока хз зачем)
    if (arg_count > 1)
        {
        //пихаем аргумет поданный на вход программы в 'item' 
        simpleList.name = string(args[1]);
        simpleList.mainList = data.read();
        simpleList.find_user();
        //and into первую запись (пока хз зачем пушит, поэтому закомменчено)
        //list.push_back(item);
        //Печатаем меню
        simpleList.print_menu();
        //write data from 'list' vector to file using 'write' function
        data.write(simpleList.mainList);
        //data.read();
        }
    //Если записей нет - пишем и ничего не делаем 
    else
        {
        cout << "There's no data. Exit" << endl;
        } 
    //Конец программы, возвращаем 23 - просто так, чтобы было ясно, что мэйн вернула то, что нужно.
return 23;
}