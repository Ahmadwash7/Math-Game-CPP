#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enOperationType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};

enum enQuesLevel {Easy = 1, Med = 2, Hard = 3, Mix = 4};

string OperationTypeText(enOperationType Operation)
{
    switch (Operation)
    {
        case enOperationType::Add:
        {
            return "Addition";
        }
        case enOperationType::Sub:
        {
            return "Subtraction";
        }
        case enOperationType::Mul:
        {
            return "Multiplication";
        }
        case enOperationType::Div:
        {
            return "Division";
        }
        case enOperationType::MixOp:
        {
            return "Mix";
        }
    }
    return "";
}

string QuestionLevelText(enQuesLevel Level)
{
    switch (Level)
    {

        case enQuesLevel::Easy:
        {
            return "Easy";
        }
        case enQuesLevel::Med:
        {
            return "Medium";
        }
        case enQuesLevel::Hard:
        {
            return "Hard";
        }
        case enQuesLevel::Mix:
        { 
            return "Mix";
        }
    }

    return "";
}

struct stGameResults
{
    short RightAns = 0;
    short WrongAns = 0;
};

int NumberOfQuestions()
{
    int Number;
    do
    {
        cout << "How Many Questions Do You Want To Answer (1 to 100) : ";
        cin >> Number;

    }while (Number < 1 || Number > 100);

    return Number;
}

enQuesLevel ReadQuestionsLevel()
{
    short QuesLevel = 0;

    do
    {
        cout << "Enter Questions Level [1]Easy [2]Med [3]Hard [4]Mix : ";
        cin >> QuesLevel;

    }while (QuesLevel < 1 || QuesLevel > 4);
 
    return (enQuesLevel)QuesLevel;
}

enOperationType ReadOperationType()
{
    short OperationType = 0;

    do 
    {
        cout << "Enter Operation Type [1]Add [2]Sub [3]Mul [4]Div [5]Mix : ";
        cin >> OperationType;

    } while(OperationType < 1 || OperationType > 5);

    return (enOperationType)OperationType;
}

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum ;
}

int ChoiceLevel(enQuesLevel Level)
{
    if (Level == enQuesLevel::Easy)
    {
        return RandomNumber(1, 10);
    }
    else if(Level == enQuesLevel :: Med)
    {
        return RandomNumber(10 , 99);
    }
    else if(Level == enQuesLevel :: Hard)
    {
        return RandomNumber(100 , 999);
    }
    else 
    {
        return RandomNumber(1, 1000);
    }
}


int  ChoiceOperationType(enOperationType OperationType, enQuesLevel Level)
{
    int Num1 = ChoiceLevel(Level);
    int Num2 = ChoiceLevel(Level);

    if (OperationType == enOperationType::MixOp)
    {
        OperationType = (enOperationType)RandomNumber(1, 4);
    }

    if (OperationType == enOperationType::Div)
    {
        if (Num1 < Num2)
        {
            int Temp = Num1;
            Num1 = Num2;
            Num2 = Temp;
        }
    }
    
    if (OperationType == enOperationType::Div && Num2 == 0)
    {
        Num2 = 1;
    }

    
    cout << "\n";
    cout << "  " << Num1 << " ";

    switch (OperationType)
    {
        case enOperationType::Add:
        {
            cout << " + " << Num2 << " = ";
            return Num1 + Num2;
        }
        case enOperationType::Sub:
        {
            cout << " - " << Num2 << " = ";
            return Num1 - Num2;
        }
        case enOperationType::Mul:
        {
            cout << " * " << Num2 << " = ";
            return Num1 * Num2;
        }
        case enOperationType::Div:
        {
            cout << " / " << Num2 << " = ";
            return Num1 / Num2;
        }
    }

    return 0;
}

string Tabs(short NumberOfTabs)
{
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++)
    {
        t += "\t";
        cout << t;
    }
    return t;
}

bool CheckAnswer(float PlayerAnswer, float CorrectAnswer)
{
    return PlayerAnswer == CorrectAnswer;
}

void CheckPlayerAns(stGameResults& Results, int PlayerAnswer, int CorrectAnswer)
{

    if (CheckAnswer(PlayerAnswer, CorrectAnswer))
    {
        cout << "\tRight Answer :-)\n";
        Results.RightAns++;
    }
    else
    {
        cout << " Wrong Answer :-(\n";
        cout << " The Right Answer is: " << CorrectAnswer << endl;
        Results.WrongAns++;
    }
}

string CheckPass(stGameResults Results)
{
    
    if(Results.RightAns > Results.WrongAns || Results.RightAns == Results.WrongAns)
    {
        return "Pass";
    }
    else 
    {
        return "Fail";
    }
    
}

void FinalResults(stGameResults Results, enQuesLevel QuesLevel, enOperationType OperationType, int  NumberOfQuestions)
{
    cout << Tabs (3) <<  "==================================" << endl;
    cout << Tabs (3) <<"        Final Results: " << CheckPass(Results) << endl;
    cout << Tabs (3) <<  "==================================" << endl;
    cout << "\n";
    cout << Tabs (3) <<  "Number Of Questions: " << NumberOfQuestions << endl;
    cout << Tabs (3) << "Questions Level: " << QuestionLevelText(QuesLevel) << endl;
    cout << Tabs (3) << "Operation Type: " << OperationTypeText(OperationType) << endl;
    cout << Tabs (3) << "Number Of Right Answers: " << Results.RightAns << endl;
    cout << Tabs (3)<< "Number Of Wrong Answers: " << Results.WrongAns << endl;
    cout << Tabs (3) <<  "__________________________________" << endl;
    cout << "\n";
}

void PlayGame()
{
    
    char again;
    do
    {
        stGameResults Results;

        system("clear"); 
        int NumberOfQuestion = NumberOfQuestions();

        cout << endl;
        
        enQuesLevel Level = ReadQuestionsLevel();

        cout << endl;

        enOperationType Operation = ReadOperationType();
        cout << "\n";

        for (int i = 0; i < NumberOfQuestion; i++)
        {
        
            cout << "\n";
            cout << "------------------" <<endl;
            cout << "Question [" << i + 1  << " / " << NumberOfQuestion << "]" << endl;
            cout << "------------------" <<endl;

            int CorrectAnswer = ChoiceOperationType(Operation, Level);
        
            int PlayerAnswer;
            cin >> PlayerAnswer;

            cout << "__________________________________"<< endl;
            cout << "\n";

            CheckPlayerAns(Results, PlayerAnswer, CorrectAnswer);

            cout << "__________________________________"<< endl;
        }
        
        cout << "\n";

        FinalResults(Results, Level, Operation, NumberOfQuestion);

        cout << Tabs(3) << "Do You want to play agian? Y/N?\t";
        cin >> again;

    } while(again == 'Y' || again == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    PlayGame();

    return 0;
}
