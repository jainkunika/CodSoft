#include<iostream>
using namespace std;

int main(){
    typedef enum{END,ADD,SUB,MUL,DIV} choice_t;
    while(true){
        float op1,op2;
        cout<<"Enter 1st operand: ";
        cin>>op1;
        cout<<"Enter 2nd operand: ";
        cin>>op2;

        cout<<
        "Choice:\n"
        "   Enter "<<ADD<<" to ADD\n"
        "   Enter "<<SUB<<" to SUBTRACT\n"
        "   Enter "<<MUL<<" to MULTIPLY\n"
        "   Enter "<<DIV<<" to DIVISION\n"
        "   Enter "<<END<<" to EXIT\n"
        "Enter your choices: ";

        choice_t choice=(choice_t) ({int ch; cin>>ch; ch;});
        float res=0;
        switch(choice){
            case ADD: res=op1+op2; break;
            case SUB: res=op1-op2; break;
            case MUL: res=op1*op2; break;
            case DIV: res=op1/op2; break;
            case END: exit(0);
            default: cout<<"Invalid Input! Try again...\n";
        }
        cout<<"Result= "<<res<<endl;
    }
    return 0;
}