#include <iostream>

using namespace std;

int main(){
    int day, month, year;
    int lastDay, lastMonth, lastYear;
    int nextDay, nextMonth, nextYear;
    cout<<"Nhap ngay thang (ngay/thang/nam): ";
    cin>>day>>month>>year;
    int dayMax;
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dayMax = 31;
            break;
        case 2:
            if (year%100 != 0 && year%4==0 || year%400==0)
                dayMax = 29;
            else
                dayMax = 28;
            break;
        case 4: case 6: case 9: case 11: 
            dayMax = 30;
            break;
        default:
            cout<<"Thang nay khong ton tai!"<<endl;
            return 0;
    }
    if (day <= 0 || day > dayMax){
        cout<<"Ngay nay khong ton tai!"<<endl;
        return 0 ;
    } else {
        lastDay = day - 1;
        nextDay = day + 1;
        lastMonth = month;
        lastYear = year;
        nextMonth = month;
        nextYear = year;
        if(nextDay > dayMax ){
            nextDay = 1;
            nextMonth++;
            if(nextMonth > 12){
                nextMonth = 1;
                nextYear++;
            }
        }
        if(lastDay < 1 ){
            lastMonth--;
            switch (lastMonth){
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    dayMax = 31;
                    break;
                case 2:
                    if (year%100 != 0 && year%4==0 || year%400==0)
                        dayMax = 29;
                    break;
                case 4: case 6: case 9: case 11: 
                    dayMax = 30;
                    break;
                default:
                    if(lastMonth < 1){
                        lastYear--;
                        lastMonth = 12;
                        dayMax = 31;
                    }
                    break;
            }
            lastDay = dayMax;
        }
        cout<<"Ngay hom truoc: "<<lastDay<<" / "<<lastMonth<<" / "<<lastYear<<endl;
        cout<<"Ngay hom nay: "<<day<<" / "<<month<<" / "<<year<<endl;
        cout<<"Ngay hom sau: "<<nextDay<<" / "<<nextMonth<<" / "<<nextYear<<endl; 
    }
        

}