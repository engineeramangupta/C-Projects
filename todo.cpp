#include<iostream>
#include<string>
#include<list>
#include<ctime>
using namespace std;


class TodoItems{
    private:
        int id;
        string description;
        bool completed;
    public:
        TodoItems() : id(0), description(""), completed(false){}

        bool create(string new_description, int ids){
            id = ids;
            description = new_description;
            return true;
        }

        int getId(){
            return id;
        }
        string getDescription(){
            return description;
        }
        bool isCompleted(){
            return completed;
        }

        void setCompleted(bool val){
            completed = val;
        }
        void chageDes(string newstr){
            description = newstr;
        }
};

int main(){
    char input_option;
    int input_id;
    int id = 1;
    string input_description;
    list<TodoItems> todoItems;
    list<TodoItems>::iterator it;
    todoItems.clear();


    while(1){
        system("cls");
        cout<<"Todo List Maker - " <<endl<<endl;
        for(it = todoItems.begin(); it != todoItems.end(); it++){
            cout<<it->getId()<<" | "<< it->getDescription()<< " | " << (it->isCompleted() ? "Done" :"Not Done")<<endl;
        }
        if(todoItems.empty()){
            cout<<"Add your first todo!"<<endl;
        }
        cout<<endl;
        cout<<"[a]dd a new Todo"<<endl;
        cout<<"[c]omplete a Todo"<<endl;
        cout<<"[u]ncomplete a Todo"<<endl;
        cout<<"c[h]ange any Todo"<<endl;
        cout<<"[q]uit"<<endl;

        cout<<"choice: ";
        cin>> input_option;
        if(input_option == 'q'){
            cout<<"Have a great day now!"<<endl;
            break;
        }
        else if(input_option == 'a'){
            cout<<"Add a new description : ";
            cin.clear();
            cin.ignore();
            getline(cin, input_description);
            TodoItems newItem;
            newItem.create(input_description, id);
            todoItems.push_back(newItem);
            id++;
        }
        else if(input_option == 'c'){
            cout<<"Enter id to make completed : ";
            cin>>input_id;
            
            for(it = todoItems.begin(); it != todoItems.end(); it++){
                if(input_id == it->getId()){
                    it->setCompleted(true);
                    break;
                }
            }  
        }
        else if(input_option == 'u'){
            cout<<"Enter id to make completed : ";
            cin>>input_id;

            for(it = todoItems.begin(); it != todoItems.end(); it++){
                if(input_id == it->getId()){
                    it->setCompleted(false);
                    break;
                }
            }
        }
        else if(input_option == 'h'){
            cout<<"Enter id to make change : ";
            cin>>input_id;

            for(it = todoItems.begin(); it != todoItems.end(); it++){
                if(input_id == it->getId()){
                    cout<<"Add update description : ";
                    cin.clear();
                    cin.ignore();
                    getline(cin, input_description);
                    it->chageDes(input_description);
                    break;
                }
            }  
        }

    }
    return 0;
}