#include<iostream>
#include<cstring>
#define MAXLENGTH 1000
using namespace std;

class STR{
    private:
        char *s;
        int originLength;
        int length;
        int space[MAXLENGTH];// 存储每个分隔符的位置idx,用于计算每个英文单词的长度
        int spaceCount;
        void fillSpace(){
            if(s == nullptr)
                return;
            int k = 0;
            for(int i=0;i<length;i++){
                if((s[i] >= 'a' && s[i] <= 'z') 
                || (s[i] >= 'A' && s[i] <= 'Z'))
                    continue;
                
                space[k] = i;
                k++;
            }
            spaceCount = k;
        }
        // [t1,t2] 闭区间
        void backward(char *t1,char *t2){
            int wordLength = t2 - t1 + 1;
            if(wordLength < 0)
                return;
            for(int i=0;i<wordLength/2;i++){
                char c = *(t1 + i);
                *(t1 + i) = *(t2 - i);
                *(t2 - i) = c;
            }
        }
    public:
        STR(char *t){
            cout << "constructing..." << endl;
            s = new char[strlen(t)+1];
            strcpy(s,t);
            length = strlen(s);
            originLength = strlen(t);
        }
        STR(const STR& obj){
            cout << "copy constructing..." << endl;
            s = new char[strlen(obj.s)+1];
            strcpy(s,obj.s);
            length = strlen(s);
            originLength = strlen(obj.s);
        }
        ~STR(){
            cout << "delete space..." << endl;
            if(s)
                delete s;
        }
        void fun(){
            printRR();
            cout << " can be tranformed to ";

            s[length] = ' '; // 末尾加字符 最后一个单词也能用backward
            length++;
            fillSpace();
            // 双指针
            int startIndex = 0;
            int endIndex = space[0]-1;// 非英文字符的前一个在单词之内
            char *ptr1,*ptr2;

            for(int i=1;i<spaceCount;i++){
                // 更新指针
                ptr1 = s+startIndex;
                ptr2 = s+endIndex;
                backward(ptr1,ptr2);

                startIndex = endIndex+2;
                endIndex = space[i] - 1;
            }
            ptr1 = s+startIndex;
            ptr2 = s+endIndex;
            backward(ptr1,ptr2);
            s[length] = '\0';
            length--;
            printRR();
            cout << endl;
        }
        void printRR(){
            string jojo = "";
            for(int i=0;i<originLength;i++){
                jojo+=s[i];
            }
            cout << jojo;
        }
};
int main(){

    string jojo;
    getline(cin,jojo,'\n');

    char* s = new char[jojo.length() + 1];
    strcpy(s, jojo.c_str());

    STR ORI(s);
    STR sstr(ORI);
    sstr.fun();

    return 0;
}