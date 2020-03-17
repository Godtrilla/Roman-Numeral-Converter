//Del'Juan Jackson
//Intro to C++
//Roman Numerals


#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;


//Function Prototypes
string toShortRoman(int x);
string toLongRoman(int x);
string toLower(string s);




int main()
{
    ofstream outFile;
    outFile.open("roman.txt");


    int s; //Program Power Switch
    int starter; //Starting Number
    int array1[35]; //Incrementing Array
    string array2[35][2]; //Multidimensional array for Long Form
    string array3[35][2]; //Multidimensional array for Short Form

cout << "Start?" << endl;
cout << "Enter 0 to start program OR enter 1 to exit" << endl;
cin >> s;
while (s < 1) {


    cout << "This application is used to convert numbers into Long and Short Roman numerals." << endl;
    cout << "In this program, you must enter a number between 1 and 5000.  This number will be allocated by 1." << endl;
    cout << "This process will run a total of 25 times.  Let's Begin." << endl;
    cout << endl << endl << endl << endl;
    cout << "Enter your starting number (1-5000)" << endl;
    cin >> starter;
    while (starter < 1 || starter > 5000) {
        cout << "Please try again.  (Remember, a number between 1 to 5000)" << endl;
        cin >> starter;


    }

    array1[0] = 0;
    array2[0][0] = "M";
    array2[0][1] = "B";

    array3[0][0] = "M";
    array3[0][1] = "B";

//Loops to populate arrays

    for (int index = 0; index < 35; index++)
    {
        array1[index] = starter + index;


    }
    for (int index = 0; index < 35; index++) {
        array2[index][0] = toLongRoman(array1[index]);


    }

    for (int index = 0; index < 35; index++) {
        array2[index][1] = toLower(array2[index][0]);
    }

    for (int index = 0; index < 35; index++) {
        array3[index][0] = toShortRoman(array1[index]);
    }

    for (int index = 0; index < 35; index++) {
        array3[index][1] = toLower(array3[index][0]);
    }



    //Spacer
    cout << endl << endl << endl;


    //Loop for formatting and output
    for (int counter = 0; counter < 35; counter++) {


        //Format to Text File
        outFile << left << setw(8) << array1[counter] << " " << setw(15) << array2[counter][0] << " " << setw(15)
             << array2[counter][1] << setw(15) << array3[counter][0] << setw(15) << array3[counter][1] << endl;


    }

    for (int counter = 0; counter < 20; counter++) {


        cout << left << setw(8) << array1[counter] << " " << setw(15) << array2[counter][0] << " " << setw(15)
             << array2[counter][1]
             << setw(15) << array3[counter][0] << setw(15) << array3[counter][1] << endl;
    }


//Spacer
    cout << endl << endl << endl;

    cout <<"Run again?  (enter 0 to run program again, otherwise enter 1 to exit)" << endl;
    cin >> s;

}


outFile.close();
    return 0;

}



//String Function to convert to lowercase
string toLower(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);


    return s;
}




//LONG FORM ROMAN
string toLongRoman(int x)
{
    string romanNumeral;
    int placeholder;

    if(x >= 1000)
    {
        placeholder = (x / 1000);

        for (int i = 0; i < placeholder; i++)
        {
            romanNumeral += "M";
        }
        x %= 1000;
    }
    if (x >= 100){
        placeholder = (x / 100);



        if (placeholder >= 5)
        {
            romanNumeral += "D";

            for (int i = 0; i < placeholder - 5; i++) {
                romanNumeral += "C";
            }
        }

        else if (placeholder >= 1)
        {
            for(int i = 0; i < placeholder; i++)
            {
                romanNumeral += "C";
            }
        }
        x %= 100;
    }
    if(x >= 10)
    {
        placeholder = (x / 10);


        if(placeholder >= 5)
        {
            romanNumeral += "L";

            for (int i = 0; i < placeholder - 5; i++)
            {
                romanNumeral += "X";
            }
        }

        else if (placeholder >= 1)
        {
            for (int i = 0; i < placeholder; i++)
            {
                romanNumeral += "X";
            }
        }
        x %= 10;
    }

    if(x >= 1)
    {
        placeholder = x;

        if (placeholder >= 5)
        {
            romanNumeral += "V";

            for (int i = 0; i < placeholder -5; i++)
            {
                romanNumeral += "I";
            }
        }

        else if (placeholder >= 1)
        {
            for (int i = 0; i < placeholder; i++)
            {
                romanNumeral += "I";
            }
        }
    }
    return romanNumeral;
}





//TO SHORT FORM ROMAN
//BONUS
string toShortRoman(int x)
{
    string romanNumeral;
    int placeholder;

    if(x >= 1000)
    {
        placeholder = (x / 1000);

        for (int i = 0; i < placeholder; i++) {
            romanNumeral += "M";
        }
        x %= 1000;
    }
    if (x >= 100){
        placeholder = (x / 100);

        if(placeholder == 9) {
            romanNumeral += "CM";
        }
        else if (placeholder >= 5)
        {
            romanNumeral += "D";

            for (int i = 0; i < placeholder - 5; i++) {
                romanNumeral += "C";
            }
        }
        else if (placeholder == 4)
        {
            romanNumeral += "CD";
        }
        else if (placeholder >= 1)
        {
            for(int i = 0; i < placeholder; i++)
            {
                romanNumeral += "C";
            }
        }
        x %= 100;
    }
    if(x >= 10)
    {
        placeholder = (x / 10);

        if (placeholder == 9) {
            romanNumeral += "XC";
        }
        else if(placeholder >= 5)
        {
            romanNumeral += "L";

            for (int i = 0; i < placeholder - 5; i++)
            {
                romanNumeral += "X";
            }
        }
        else if (placeholder == 4)
        {
            romanNumeral += "XL";
        }
        else if (placeholder >= 1)
        {
            for (int i = 0; i < placeholder; i++)
            {
                romanNumeral += "X";
            }
        }
        x %= 10;
    }

    if(x >= 1)
    {
        placeholder = x;
        if(placeholder == 9)
        {
            romanNumeral += "IX";
        }
        else if (placeholder >= 5)
        {
            romanNumeral += "V";

            for (int i = 0; i < placeholder -5; i++)
            {
                romanNumeral += "I";
            }
        }
        else if (placeholder == 4)
        {
            romanNumeral += "IV";
        }
        else if (placeholder >= 1)
        {
            for (int i = 0; i < placeholder; i++)
            {
                romanNumeral += "I";
            }
        }
    }
    return romanNumeral;
}



