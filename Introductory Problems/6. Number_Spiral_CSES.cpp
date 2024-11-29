//הוגש במקור בחשבון הקודם ב2024-11-04 13:30:41
#include <iostream>

using namespace std;

long find_in_spiral(long, long);

int main()
{
    long tests_num, row_num, col_num;
    cin >> tests_num;
    cin >> row_num;
    cin >> col_num;
    cout << find_in_spiral(row_num, col_num);
    while (tests_num > 1)
    {
        cout << "\n";
        cin >> row_num;
        cin >> col_num;
        cout << find_in_spiral(row_num, col_num);
        tests_num --;
    }
}

long find_in_spiral(long row_num, long col_num)
{
    long base_num;
    if (row_num > col_num)
    {
        if (row_num % 2 == 0)
        {
            base_num = row_num * row_num;
            return base_num - (col_num - 1);
        }
        else
        {
            base_num = ((row_num - 1) * (row_num - 1)) + 1;
            return base_num + (col_num - 1);
        }
    }
    else
    {
        if (col_num % 2 == 0)
        {
            base_num = ((col_num - 1) * (col_num - 1)) + 1;
            return base_num + (row_num - 1);
        }
        else
        {
            base_num = col_num * col_num;
            return base_num - (row_num - 1);
        }
    }
}


//הולכים לפי מי שגדול יותר וזזים ממנו (שורה/ עמודה)
//למה? כי הספירלה הולכת לעומק עד המספר שהוא עומק העמודה/ השורה.
//אם הם זהים - נלך לפי עמודות ( כדי לסדר את המקרה של 1,1)

//אם העמודה היא זוגית, אני גדול מהמספר למעלה (אי זוגי להפך)
//אם השורה היא זוגית, אני קטן מהמספר לפני (אי זוגי להפך)

//איך אדע מי העליון?

//אם העמודה היא אי-זוגית - זה מספר העמודה בריבוע
//אם העמודה היא זוגית - זה מספר העמודה שלפני בריבוע ועוד אחד

//אם השורה היא זוגית - זה מספר השורה בריבוע
//אם השורה היא אי-זוגית - זה מספר השורה שלפני בריבוע ועוד אחד

