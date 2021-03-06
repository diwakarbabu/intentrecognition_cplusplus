#include "header.h"

//Init - Set of regular expression variables
//To check weather - keywords include Weather, Climate, Temperature, Rain, Sunny, Snowy,
regex weather("[wW]eather|[tT]emperature|[rR]ain|[Ss]unny|[cC]limate|[sS]nowy");

//To check city - only after checking weather - keyword include in, city
regex city("in|[cC]ity");

//To check the presence of date dd./-mm./-yyyy - Only dates from year 2021
regex date("((0[1-9]|[12][0-9]|3[0-1])|([1-9]|[12][0-9]|3[0-1]))[./-]((0[1-9]|1[012])|([1-9]|1[012]))[./-](2021)");

//To check the presence of time - any format
//regex time("([0-2][0-9]:[0-5][0-9]|[0-2][0-9]am|[0-2][0-9]pm|[0-2][0-9]AM|[0-2][0-9]PM|[0-2][0-9]Am|[0-2][0-9]Pm|[0-2][0-9] am|[0-2][0-9] pm|[0-2][0-9] AM|[0-2][0-9] PM|[0-2][0-9] Am|[0-2][0-9] Pm)");

//To check calander - keywords include Busy, Free, Appointment
regex check("[bB]usy|[fF]ree|[aA]ppointment");

//To present a fact - keyword include Fact
regex fact("[fF]act");

int checkintent(string intent)
{
  if(regex_search(intent, weather))
    {
        if(regex_search(intent,city))
        {
            cout<<"Intent: Get Weather in City \n";
            return 2;
        }
        else
        cout<<"Intent: Get Weather \n";
        return 1;
    }
    else if(regex_search(intent,fact))
    {
        cout<<"Intent: Get fact \n";
        return 4;
    }
    else if(regex_search(intent,check) || regex_search(intent,date))
    {
        cout<<"Intent: Checks Calander \n";
        return 3;
    }
    else
    {
        cout<<"Sorry wrong input \n";
        return 5;
    }
}

