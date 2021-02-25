#include <string>
#include <iostream>

class Date
{
	public:
          std::string year = "0000";
          std::string month = "00";
          std::string day = "00";

          Date(std::string month, std::string year, std::string day){
                this->month = month;
                this->day = day;
                this->year = year;

          }
          Date(int month, int year, int day){
                this->month = std::to_string(month);
                this->day = std::to_string(day);
                this->year = std::to_string(year);

          }
          Date(std::string date){
                this->month = date.substr(0,2);
                this->day = date.substr(3,2);
                this->year = date.substr(6);
          }
	
	  Date(){
                this->month = "00";
                this->day = "00";;
                this->year = "0000";
	  }
	
	friend std::ostream& operator <<(std::ostream& out,const Date& d){
		out << d.month << "/" << d.day << "/" << d.year ;
		return out;
	}
};
