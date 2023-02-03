//Infix to Postfix Conversion
#include<iostream>
//#include<stack>
#include<string.h>
using namespace std;

class stack1{
    //stack array declaration
    char ar[10];
    int top,size=10;
public:
    stack1(){
        top=-1;
    }
    //pushing element into stack
    void push(char val){
        if(top>=size-1){
            cout<<"Stack overflow!!"<<endl;
        }
        else{
            ar[++top]=val;
            cout<<val<<" inserted in stack."<<endl;
        }
    }
    //popping element from stack
    char pop(){
        if(top<0){
            cout<<"Stack underflow!!"<<endl;
            //exit(0);
        }
        else{
            return (ar[top--]);
        }
    }
    char retop(){
        return ar[top];
    }
    bool stk_empty(){
        if(top<0){
            return 1;
            //exit(0);
        }
        else{
            return 0;
        }
    }
    //displaying the stack
    //void display(){
     //   if(top<0)
       //     cout<<"Stack is empty."<<endl;
        //else
         //   cout<<"The stack is::"<<endl;
         //   for(int i=0;i<=top;i++){
          //      cout<<ar[i]<<endl;
           // }
    //}
};
// class for convert infix string to postfix
class intopost{
    string inf,postf;
    stack1 stkop;
    char ch;
public:
    intopost(){
        cout<<"Enter infix expression:";
        cin>>inf;
        //sending one character to convert function to convert it into postfix
        for(int i=0;inf[i]!='\0';i++){
            ch=inf[i];
            convert(ch);
        }
        while(!stkop.stk_empty()){
            postf+=stkop.pop();//insert all operator after infix string gets over
        }
    }
    void display(){
        cout<<"Postfix expression::"<<postf<<endl;
    }
    void convert(char );
    bool isempty(char );
    bool ischar(char );
    bool isop(char );
    int prec(char );
};
void intopost::convert(char ch1)
{
    if(isempty(ch1)){
    }
    else{
        if(ischar(ch1)){
            postf+=ch1;
        }
        else if(isop(ch1)){
            if(stkop.stk_empty()){
                stkop.push(ch1);
            }
            else if(prec(ch1)>prec(stkop.retop())){
                stkop.push(ch1);
            }
            else if(prec(ch1)<=prec(stkop.retop())){
                postf+=stkop.pop();
                stkop.push(ch1);
            }
        }
    }
}
//checks that current character is not empty
bool intopost::isempty(char ch2){
    if(ch2=='\0'){
        return 1;
    }
    else{
        return 0;
    }
}
// checks that current character is alphabet
bool intopost::ischar(char ch3){
    if((ch3>='a' && ch3<='z') || (ch3>='A' && ch3<='Z')){
        return 1;
    }
    else{
        return 0;
    }
}
// checks that current character is opeator
bool intopost::isop(char ch4){
    if(ch4=='+' || ch4=='-' || ch4=='*' || ch4=='/'){
        return 1;
    }
    else{
        return 0;
    }
}
//it returns operator precedance
int intopost::prec(char ch){
    switch(ch){
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
}
int main(){
    intopost ob;
    ob.display();
    return 0;
}
