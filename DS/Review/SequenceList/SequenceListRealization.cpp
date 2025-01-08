#include<iostream>
using namespace std;
#define MAXLENGTH 1000

class SL{
private:
    int length;
    int* data;
public:
    SL()
    {
        data = new int[MAXLENGTH];
        length = 0;
    }
    void initialList(int length)
    {
        this->length = length;
        for(int i=0;i<length;i++)
        {
            cin >> data[i];
        }
    }
    int searchLocation(int loc)
    {
        if(loc < 1 || loc > length)
        {
            cout << "error" << endl;
            return -999;
        }
        int index = loc-1;
        return data[index];
    }
    int insertData(int loc,int num)
    {
        if(loc > length+1 || loc < 1){
            cout << "error" << endl;
            return 0;
        }

        int index = loc-1;
        for(int i=length-1;i>=index;i--)
        {
            data[i+1] = data[i];
        }
        length++;
        data[index] = num;
        return 1;
    }
    int multiInsert(int loc,int n,int item[]){
        int p = 0;
        int index = loc -1;
        for(int i=length+n-1;i>=index;i--){
            data[i] = data[i-n];
        }
        for(int i=index;i<index+n;i++){
            data[i] = item[p];
            p++;
        }
        length += n;
        return 1;
    }
    int deleteLocation(int loc)
    {
        if(loc > length || loc < 1 || length == 0){
            return 0;
        }
        int index = loc-1;
        for(int i=index;i<length-1;i++)
        {
            data[i] = data[i+1]; 
        }
        length--;
        return 1;
    }
    int multiDelete(int loc,int n)
    {
        int index = loc-1;
        for(int i=index;i<index+n;i++){
            data[i] = data[i+n];
        }
        length -= n;
        return 1;
    }
    void print()
    {
        cout << length << " ";
        for(int i=0;i<length;i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void loop(bool dir,int shift){
        shift %= length;
        if(!shift)
            return;

        if(dir){

        }
        else{

        }
    }
};

void id78();
void id84();

int main(){

    id84();

    return 0;
}
void id84(){
    int n;
    cin >> n;
    SL list;
    list.initialList(n);
    list.print();

    int k,num[MAXLENGTH],location,rt;
    cin >> location >> k;
    for(int i=0;i<k;i++){
        cin >> num[i];
    }
    rt = list.multiInsert(location,k,num);
 
        list.print();

    cin >> location >> k;
    rt = list.multiDelete(location,k);

        list.print();
}


void id78(){
    int n;
    cin >> n;
    SL list;
    // 初始化n个
    list.initialList(n);
    list.print();

    // 插入
    int location,num,result;
    cin >> location >> num;
    result = list.insertData(location,num);
    if(result)
        list.print();

    cin >> location >> num;
    result = list.insertData(location,num);
    if(result)
        list.print();
    
    // 删除
    cin >> location;
    result = list.deleteLocation(location);
    if(result)
        list.print();

    cin >> location;
    result = list.deleteLocation(location);
    if(result)
        list.print();

    // 搜寻
    cin >> location;
    result = list.searchLocation(location);
    if(result!=-999)
        cout << result << endl;

    cin >> location;
    result = list.searchLocation(location);
    if(result!=-999)
        cout << result << endl;
}