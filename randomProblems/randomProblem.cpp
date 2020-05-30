// mango basket ball auspicious kangaroo

// precaution misbehavior battery cup screen

// parasite hello good come education

// invitation squeeze paper ant multiplication

// COOPERATION DEMOCRACY CONGRATULATIONS YOU BYE


#include<iostream>
using namespace std;

class vowelCount
{
    public:
            string sentence[4];
            int points, perWordCount = 0, countArray[4], max, maxString;

    void getData()
    {
        sentence[0] = {"mango basket ball auspicious kangaroo"};
        sentence[1] = {"precaution misbehavior battery cup screen"};
        sentence[2] = {"parasite hello good come education"};
        sentence[3] = {"invitation squeeze paper ant multiplication"};
        // sentence[4] = {"COOPERATION DEMOCRACY CONGRATULATIONS YOU BYE"};

        for(int i = 0; i<4; i++)
        {
            cout<<endl;
            points = 0;
            cout<<"\nstring "<<i+1<<" :\t";
            splitStrings(sentence[i]);
            countArray[i] = points;
        }
    }

    void splitStrings(string tempSentence)
    {
        tempSentence = tempSentence + " ";
        string word = "";
        for(int i = 0; i<tempSentence.length(); i++)
        {
            
            if(tempSentence[i] != 32)
            {
                word = word + tempSentence[i];
            }
            
            else
            {
                countVowels(word);
                word = "";
            }
            
        }
    }


    void countVowels(string tempword)
    {
        // cout<<"\ntemp word : "<<tempword;
        for(int i = 0; i<tempword.length(); i++)
        {
            if( tempword[i] == 'a' || tempword[i] == 'e' || tempword[i] == 'i' || tempword[i] == 'o' || tempword[i] == 'u')
            {
                perWordCount++;
            }
        }
        
        printPoints(perWordCount);
        pointsAllocation(perWordCount);
        perWordCount = 0;
        
    }

    void printPoints(int perWordCount)
    {
       if(perWordCount == 1)
        {
            cout<<" 0"<<"\t";
        }
        else if(perWordCount == 2)
        {
            cout<<" 1"<<"\t";
        }
        else if(perWordCount == 3)
        {
            cout<<" 3"<<"\t";
        }
        else if(perWordCount == 4)
        {
            cout<<" 4"<<"\t";
        }
        else if(perWordCount == 5)
        {
            cout<<" 6"<<"\t";
        }
        else if(perWordCount > 5)
        {
            cout<<" 8"<<"\t";
        } 
    }

    void pointsAllocation(int perWordCount)
    {
        if(perWordCount == 1)
        {
            points = points + 0;
        }
        else if(perWordCount == 2)
        {
            points = points + 1;
        }
        else if(perWordCount == 3)
        {
            points = points + 3;
        }
        else if(perWordCount == 4)
        {
            points = points + 4;
        }
        else if(perWordCount == 5)
        {
            points = points + 6;
        }
        else if(perWordCount > 5)
        {
            points = points + 8;
        }
    }

    void displayCount()
    {
        cout<<endl;
        for(int i = 0; i<4; i++)
        {
            cout<<"\nstring "<<i+1<<" : "<<countArray[i];
        }
        cout<<endl;
    }

    void displayHighest()
    {
        for(int i = 0; i<4; i++)
        {
            for(int j = i+1; j<4; j++)
            {
                if(countArray[i] > countArray[j])
                {
                    max = countArray[i];
                    maxString = i;

                }
                else
                {
                    max = countArray[j];
                    maxString = j;
                }
                
            }
        }

        cout<<"\nStudent with highest points : \nstudent"<<maxString <<" : "<<max;
        cout<<endl;
    }
};

int main()
{
    vowelCount vc;
    vc.getData();
    vc.displayCount();
    vc.displayHighest();

    return 0;
}