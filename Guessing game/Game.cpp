#include<iostream>
#include<ctime>

using namespace std;

int main(){
    cout<<"\n\t\t----------------Welcom to the number guessing game----------------\n"<<endl;
    cout<<"\n\t\t---->>You will have to guess a number between 1 to 100.";
    cout<<"\n\t\t---->>Let's Start, All the best!"<<endl;

    srand(time(0));
    int randNumber=(rand()%100) +1;

    cout<<"\n**You will have total 5 chnace to guess the number.**\n";
    int chanceLeft=5;
    int playerInput;

    for(int i=1;i<=5;i++){
        cout<<"\n---->Enter the number: "<<endl;
        cin>>playerInput;
        
        if(playerInput==randNumber){
            cout<<"\nCongrats!! You have successfully guess the right number.\n"<<endl;
            cout<<"\nThanks for playing. Have a nice day!\n"<<endl;
            break;
        }
        else{
            if(playerInput>randNumber){
                cout<<"\n""Insert a smaller number, Try Again!"""<<endl;
            }
            else{
                cout<<"\n""Insert a larger number, Try Again!"""<<endl;

            }
        }
        chanceLeft--;
        cout<<"\nChances left to get the random number: "<<chanceLeft<<endl;

        if(chanceLeft==0){
            cout<<"\nSorry you have finished the chance o get the random number\n"<<endl;
            cout<<"Random number was: "<<randNumber<<endl;
            cout<<"Thanks for playing!!"<<endl;
        }
    }
    cout<<"\n";
    return 0;
}
