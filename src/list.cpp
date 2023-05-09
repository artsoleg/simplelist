//Подключаем заголовок с декларациями
#include "include/list.h"
#include "include/database.h"
//Описываем метод печати меню
void List::print_menu () {
    //Выводим меню на экран
    cout << "**************************\n";
    cout << "Make your choice:\n";
    cout << "1 - Print list\n";
    cout << "2 - Add new\n";
    cout << "3 - Delete\n";;
    cout << "s - Save changes and quit\n";
    cout << "q - Quit\n";
    cout << "What to do? (Print a number  then press Enter): ";
    //Считываем ИД выбора с клавиатуры
    char choice;
    cin >> choice;
    //В зависимости от ИД выбора вызываем нужный метод (методы описаны в include/list.h)
    switch (choice)
    {
        case '1':
            List::print_list();
            break;
        case '2':
            List::add_item();
            break;
        case '3':
            List::delete_item();
            break;
        case 's':
            SaveList();
        case 'q':
        case 'Q':
            cout << "Quitting...\n";
            return;
            break;
        default:
            List::print_menu();
        break;
    }
}
//Описываем метод печати списка
void List::print_list()
{
    //Выводим на экран инфо о методе
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "*** Print list ***\n";
    //Пробегаемся циклом по вектору списка и выводим записи построчно
    for (int list_index = 0; list_index < (int)list.size(); list_index++)
    {
    cout << list_index << " - " << list[list_index] << "\n";
    }
    //Предлагаем выбор вернуться в меню
    cout << "Print 'm' for Menu or q for Quit without saving";
    //Считываем 
    char choice;
    cin >> choice;
    //Выходим в меню или из программы:
    switch (choice)
    {
        case 'm':
            List::print_menu();
            break;
        case 'q':
        case 'Q':
            cout << "Quitting...\n";
            exit(0);
            break;
        default:
            List::print_list();
        break;
    }
}
//Описываем метод добавления
void List::add_item()
{
    //Переменная для занесения записей в список
    string item;
    //Выводим на экран инфо о методе
    cout << "\n\n\n\n\n\n\n";
    cout << "*** Add Item ***\n";
    cout << "Print an item and press Enter: ";
    //Считываем имя записи
    cin >> item;
    /*cout << "(DBG): " << item << "\n";*/
    //добавляем имя записи в конец вектора
    list.push_back(item);
    //пишем что все ок
    cout << "Item added!\n";
    //чистим син
    cin.clear();
    //Печатаем меню, чтобы было видно изменение
    List::print_menu();
}
//Описываем метод удалления
void List::delete_item()
{
    //Выводим на экран инфо о методе
    cout << "*** Delete item\n";
    //Проверяем, есть ли записи в списке
    if (list.size())
        {
        /*print_list();*/
        //Выводим список с пронумерованными записями
        for (int list_index = 0; list_index < (int)list.size(); list_index++)
        {
        cout << list_index << " - " << list[list_index] << "\n";
        }
        //запоминаем начало списка
        //auto iter = list.cbegin();
        //Предлагаем выбрать запись для удаления
        cout << "Select an item to delete: \n";
        //Считываем номер записи
        int choiceNum;
        cin >> choiceNum;
        /*cout << "(DBG): " << item << "\n";*/
        //Удаляем запись по номеру (начало + номер записи)
        list.erase(list.cbegin() + choiceNum);
        //Пишем юзеру, что все ок
        cout << "Item erased!\n";
        //Очищаемся от греха (чистим син)
        cin.clear();
        }
    //Когда записей нет - удалять нечего, сообщаем, что список пуст    
    else
        {
            cout << "List empty.\n";
        }
    //Печатаем меню для выбора дальнейших действий
    List::print_menu();   
}

bool List::find_user() {
    bool userFound  = false;
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "*** Welcome, " << name << " ***\n";
    for ( int user_index = 0; user_index < (int)mainList.size(); user_index++) {
        cout << mainList[user_index][0] << "\n";
        if (mainList[user_index][0] == name) {
            cout << "User " << name << " has been found!\n";
            list = mainList[user_index];
            curUserID = user_index;
            userFound = true;
            break;
        }      
    }
    if ( userFound == false )
    {
        list.push_back(name);
        mainList.push_back(list);
        curUserID = (int)mainList.size()-1;
    }
    return userFound;
}

void List::SaveList() {
    cout << "Saving the list...\n";
    mainList[curUserID] = list;
    print_menu();
}
