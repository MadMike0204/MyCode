#include <iostream>
#include <vector>
using namespace std;

struct Birthday
{
    int year,month,day;
};

void swap(Birthday &d1,Birthday &d2){
    Birthday temp = d1;
    d1 = d2;
    d2 = temp;
}

void sortBirthdays(vector<Birthday> &dates){
    int length = dates.size();
    for(int i=0;i<length-1;i++){ 
        int k = i;
        for(int j = i+1;j<length;j++){
            if(dates[k].year > dates[j].year){
                k = j;
            }
            else if(dates[k].year == dates[j].year){
                if(dates[k].month > dates[j].month){
                    k = j;
                }
                else if(dates[k].month == dates[j].month){
                    if(dates[k].day > dates[j].day){
                        k = j;
                    }
                }
            }
        }
        swap(dates[i],dates[k]);
    }
}

void printBirthdays(vector<Birthday> dates){
    int length = dates.size();
    for(int i=0;i<length;i++){
        cout << (i+1) << ":"
             << dates[i].year << "-"
             << dates[i].month << "-"
             << dates[i].day << endl;
    }
}


int main(){

    int t;
    cin >> t;
    vector<Birthday> dates;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        dates.push_back({a,b,c});
    }
    sortBirthdays(dates);
    printBirthdays(dates);
    return 0;
}