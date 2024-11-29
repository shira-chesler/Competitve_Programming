//אם הסכום הוא אי זוגי - לא אפשרי
//(מספר זוגי של מספרים שהוא שארית 2 במוד 4 תמיד יתן סכום אי זוגי - זוגות אי זוגיים יאזנו זה את זה, ונשאר עם עוד אחד)
//(גם מספר אי זוגי של מספרים שהוא שארית 1 במוד 4 תמיד יתן סכום אי זוגי - זוגות אי זוגיים יאזנו זה את זה, ונשאר עם עוד אחד)

//ואם הסכום זוגי?
//מספר זוגי של מספרים שהוא שארית 0 במוד 4 תמיד ניתן לחלוקה (זוגות של מספרים באופן מותאם לפי ציר סימטריה באמצע יתן מספר זוגי של זוגות בעלי אותו סכום)
// במספר זוגי של מספרים שהוא שארית 3 במוד 4 ישנו הכלל n + (n+3) = (n+1) + (n+2) שניתן לראות שעובד - החל מ n=0
// למעשה מספר המספרים במקרה האחרון הוא זוגי, פשוט שאחד מן המספרים האלה הוא אפס

# include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    cin >> num;
    if (num % 4 == 2 || num % 4 == 1)
    {
        cout << "NO";
    }
    else if (num % 4 == 0)
    {
        cout << "YES" << endl;
        int mid = num / 2;
        string first_group = "1";
        string second_group = "2";
        for (int i = 3; i < mid; i+=2)
        {
            first_group.append(" ").append(to_string(i));
            second_group.append(" ").append(to_string(i+1)); 
        }
        for (int i = mid + 1; i < num; i+=2)
        {
            first_group.append(" ").append(to_string(i+1));
            second_group.append(" ").append(to_string(i));
        }
        cout << mid << endl;
        cout << first_group << endl;
        cout << mid << endl;
        cout << second_group;
    }
    else // num % 4 == 3
    {
        cout << "YES" << endl;
        int mid = num / 2;
        string first_group = "1 2";
        string second_group = "3";
        bool cons_to_first = false;
        for (int i = 4; i < num; i = i + 4)
        {
            if (cons_to_first)
            {
                first_group.append(" ").append(to_string(i+1)).append(" ").append(to_string(i+2));
                second_group.append(" ").append(to_string(i)).append(" ").append(to_string(i+3));
                cons_to_first = false;
            }
            else
            {
                second_group.append(" ").append(to_string(i+1)).append(" ").append(to_string(i+2));
                first_group.append(" ").append(to_string(i)).append(" ").append(to_string(i+3));
                cons_to_first = true;
            }
        }
        if (first_group.length() > second_group.length())
        {
            cout << (mid + 1) << endl;
            cout << first_group << endl;
            cout << mid << endl;
            cout << second_group;
        }
        else
        {
            cout << mid << endl;
            cout << first_group << endl;
            cout << (mid + 1) << endl;
            cout << second_group;
        }
    }
}