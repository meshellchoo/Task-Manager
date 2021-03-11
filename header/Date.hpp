#include <string>
#include <iostream>

//assuming a valid date format is in the format of 
//mm/dd/yyyy

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
		
	bool validDateFormat(std::string date){
	        if(date.length() != 10)  //valid date format has 10 chars
        	        return false;
	        std::string month = date.substr(0,2);
	        std::string day = date.substr(3,2);
        	std::string year = date.substr(6);

		//these 3 for-loops check if the month, day, or year
		//entered are digits
	        for(int i = 0; i < month.length();i++){
               	 	if(!isdigit(month[i]))		
                	        return false;
       		 }
	        for(int i = 0; i < day.length();i++){
               		 if(!isdigit(day[i]))
                	        return false;
       		 }
	        for(int i = 0; i < year.length();i++){
               	 	if(!isdigit(year[i]))
        	                return false;
	        }
	        if(stoi(month) > 12 || stoi(month) < 1) //checking month
        	        return false;
	        if(stoi(month) == 2 && stoi(day) > 28)   //checking days greater than 2/28
                	return false;
       	 	if((stoi(month) ==  1 || stoi(month) ==  3 || stoi(month) ==  5 || stoi(month) ==  7 ||
                                        stoi(month) ==  8 || stoi(month) ==  10 || stoi(month) ==  12)
                                        && stoi(day) > 31){   //checking for months with 31 days
               	 	return false;
       	 	}
	        if((stoi(month) ==  4 || stoi(month) ==  6 || stoi(month) ==  9 || stoi(month) ==  11)
                                        && stoi(day) > 30){   //checking for months with 30 days
                	return false;
        	}

	        if(stoi(day) < 1)       // false if day < 1
                	return false;
        	if(stoi(year) < 0)     //false if year < 0
        	        return false;
        	return true;

	}

	friend std::istream& operator >>(std::istream &in, Date &d){
		std::string date;
		in >> date;
		while(!d.validDateFormat(date)){ //uses helperfunction to validate date
			std::cout << "Invalid date format. Please re-enter the date (mm/dd/yyyy)." << std::endl;
			in >> date;
		}

		d.month = date.substr(0,2);
                d.day = date.substr(3,2);
                d.year = date.substr(6);
		
		return in;

	}	
	friend std::ostream& operator <<(std::ostream& out,const Date& d){
		out << d.month << "/" << d.day << "/" << d.year ;
		return out;
	}

        friend bool operator== (const Date& lhs, const Date& rhs){
		
		if (lhs.day != rhs.day)
			return false;
		else if (lhs.month != rhs.month)
			return false;
		else if (lhs.year != rhs.year)
			return false;
		else{
			return true;
		}
        }

};
