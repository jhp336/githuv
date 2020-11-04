#include <iostream>
#include <list>
using namespace std;
class address;
class addbook{
    public:
    void show();
    void add();
    void remove();
    bool empty();
    private:
    list<address> li;
};
class address{
    friend addbook;
    private:
    string name;
    string phone;
};
void addbook::add(){
    address tmp;
    while(1){
        cout<<"Press New Name(Press -1 If You Stop): ";
        cin>>tmp.name;
        if(tmp.name=="-1") return;
        cout<<"Press New Phone Number(Press -1 If You Stop): ";
        cin>>tmp.phone;
        if(tmp.phone=="-1") return;
        li.push_back(tmp);
        cout<<"Stored Well^^\n";
    }
}
void addbook::show(){
    list<address>::iterator it;
    cout<<"Your Address List: \n";
    for(it=li.begin();it!=li.end();it++){
        cout<<it->name<<" "<<it->phone<<'\n';
    }
}
void addbook::remove(){
    string rm;
    while(1){
        if(empty()) {
            cout<<"No Address!!\n";
            return;
        }
        cout<<"Press Name You Want To Delete(Press -1 If You Stop): ";
        cin>>rm;
        if(rm=="-1") return;
        list<address>::iterator it;
        for(it=li.begin();it!=li.end();it++){
            if(it->name==rm){
                li.erase(it);
                break;
            }
        }
        if(it==li.end())
        cout<<"That Name Is Not Exist!\n";
    }
}
bool addbook::empty(){
    return li.empty();
}
int main(){
    addbook db;
    while(1){
        cout<<"1: Add new Address / 2:Showing Address Book / 3: Delete Address / 0:Exit Program\n";
        int i; cin>>i; 
        if(i==0)
        return 0;
        else if(i==1){
            db.add();
        }
        else if(i==2){
            db.show();
        }
        else if(i==3){
            db.remove();
        }
        else{
            cout<<"Wrong Instruction!!\n";
        }
    }
}