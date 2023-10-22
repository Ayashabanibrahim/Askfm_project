#include <iostream>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct user_data{
    string name,uname,pass;
    int id;
};
struct question{
    string QA;
    int idf,idt;
};
struct QR
{
    string qa,answ;
};
class one{
protected:
    vector<user_data> user;
    vector<question> Ques;
    vector<question> ans;
    vector<QR> ansQa;
    map<string,string> papl;
public:
       one()
       {
       }
    void upuser()
    {
        fstream userOut("UserData.txt",ios::out);
        for(int i=0; i<user.size(); i++){
            userOut<<user[i].name<<"\n"<<user[i].uname<<"\n";
            userOut<<user[i].pass<<"\n"<<user[i].id<<"\n";
        }
        userOut.close();
    }
    void upques()
    {
       fstream QuestionsOut ("questionData.txt",ios::out);
        for(int i=0; i<Ques.size(); i++){
            QuestionsOut<<Ques[i].QA<<"\n"<<Ques[i].idt<<"\n"<<Ques[i].idf<<"\n";
        }
        QuestionsOut.close();
    }
    void upansw()
    {
        fstream AnswerOut ("answerData.txt",ios::out);
        for(int i=0; i<ans.size(); i++){
            AnswerOut<<ans[i].QA<<"\n"<<ans[i].idt<<"\n"<<ans[i].idf<<"\n";
        }
        AnswerOut.close();
    }
    void upanswQes()
    {
        fstream ansQues("ansQues.txt",ios::out);
        for(int i=0;i<ansQa.size();i++){
            ansQues<<ansQa[i].qa<<"\n"<<ansQa[i].answ<<"\n";
        }
        ansQues.close();
    }
    void readus()
    {
        user.clear();
        fstream userIn("UserData.txt",ios::in);
        string us;
        int c=1;
        user_data Uss;
        question Questions;
        while(! userIn.fail())
        {
            if(c%4==1){
                getline(userIn,us);
                Uss.name = us;
            }
            else if(c%4==2){
                getline(userIn,us);
                Uss.uname= us;
            }
            else if(c%4==3){
                getline(userIn,us);
                Uss.pass = us;
            }
            else if(c%4==0){
                getline(userIn,us);
                string d = us;
                int Number=0;
                for(int i=0; i<d.size(); i++){
                    if(d[i]!=' ')
                    {
                       Number = Number*10 + d[i]-'0';
                    }
                }
                Uss.id=Number;
                user.push_back(Uss);
            }
            c++;
        }
        userIn.close();
    }
    void readques()
    {
        Ques.clear();
        fstream questionIn("questionData.txt",ios::in);
        string q;
        int c1=1;
        question Questions;
        while( !questionIn.fail())
        {
            if(c1%3==1){
                getline(questionIn,q);
                if(!q.empty()){
                Questions.QA = q;
                c1++;
                }
            }
            else if(c1%3==2)
            {
                getline(questionIn,q);
                if(!q.empty()){
                int Number = 0;
                string t=q;
                for(int i=0; i<t.size(); i++){
                    Number = Number*10 +  t[i]-'0';
                }
                Questions.idt = Number;
                c1++;
                }
            }
            else if(c1%3==0){
                getline(questionIn,q);
                if(!q.empty()){
                int Number = 0;
                string f=q;
                for(int i=0; i<f.size(); i++){
                    Number = Number*10 +f[i]-'0';
                }
                Questions.idf = Number;
                Ques.push_back(Questions);
                c1++;
                }
            }
        }
        questionIn.close();
    }
    void readans()
    {
        ans.clear();
        fstream answerIn("answerData.txt",ios::in);
        string anss;
        int c2=1;
        question res;
        while(!answerIn.fail())
        {
            if(c2%3==1){
                getline(answerIn,anss);
                if(!anss.empty()){
                res.QA=anss;
                 c2++;
                }
            }
            else if(c2%3==2)
            {
                getline(answerIn,anss);
                if(!anss.empty()){
                int Number = 0;
                string t=anss;
                for(int i=0; i<t.size(); i++){
                    Number = Number*10 + t[i]-'0';
                }
                res.idt = Number;
                c2++;
                }
            }
            else if(c2%3==0){
                getline(answerIn,anss);
                if(!anss.empty()){
                string f=anss;
                int Number =0;
                for(int i=0; i<f.size(); i++){
                    Number = Number*10 + f[i]-'0';
                }
                c2++;
                res.idf = Number;
                ans.push_back(res);
                }
            }
        }
        answerIn.close();
    }
    void readAnsQues()
    {
        ansQa.clear();
        fstream answerQues("ansQues.txt",ios::in);
        string ra;
        int c3=1;
        QR ansqe;
        while(!answerQues.fail()){
            if(c3%2==1){
                getline(answerQues,ra);
                if( !ra.empty()){
                ansqe.qa=ra;
                c3++;
                }
            }
            else if(c3%2==0){
                getline(answerQues,ra);
                 if( !ra.empty()){
                ansqe.answ=ra;
                c3++;
                ansQa.push_back(ansqe);
                papl[ansqe.qa]=ansqe.answ;
                 }
            }
        }
        answerQues.close();
    }

};

class two:public one
{
public:
       two(){}
     void ask();
    void answer();
     void deleted();
     void que_I_ask();
     void forQuse();
     void lists();
};
class three:public two
{
protected:
         user_data user1;
public:
      three(){
          user1.id=0;
          user1.name='0';
          user1.pass='0';
          user1.uname='0';
      }
       bool checked(int t)
          {
              int bo=0;
              for(int i=0;i<user.size();i++)
              {
                  if(t==user[i].id)
                  {
                      bo=1;
                      return true;
                      break;
                  }

              }
              if(bo==0)
              return false;
          }
      void sginup()
      {
          readus();
          cout<<"Enter Your Name \n";
          cin>>user1.name;
          cout<<"Enter Your User Name \n";
          cin>>user1.uname;
          cout<<"Enter Your Password \n";
          cin>>user1.pass;
          cout<<"Enter Your ID\n";
          cin>>user1.id;
            int idd=user1.id;
          if(checked(idd))
          {
            while(checked(idd))
          {

              cout<<"This ID Has Already Been Used...Try Different ID!\n";
              cin>>idd;
          }
         }
          user1.id=idd;
          user.push_back(user1);
          upuser();
      }
      void sginin()
      {
          readus();
          cout<<"Enter Your User Name\n";
          cin>>user1.uname;
          string passw;
          cout<<"Enter Your Passwerd \n";
          cin>>user1.pass;
          for(int i=0;i<user.size();i++)
          {
              if(user1.uname==user[i].uname)
              {
                  passw=user[i].pass;
                  user1.name=user[i].name;
                  user1.id=user[i].id;
                  break;
              }
          }
          while(passw!=user1.pass)
          {
              cout<<"Incorrect,Please Enter Correct Passwerd!\n";
              cin>>user1.pass;
          }
      }
      void lists()
      {
          readus();
          for(int i=0;i<user.size();i++)
          {
              cout<<"User Name : "<<user[i].uname<<"  "<<"User's ID : "<<user[i].id<<"\n";
          }
      }

      void ask()
      {
          readus();
          readques();
          readAnsQues();
          readans();
          if(user.size()==1)
          {
              cout<<"Not Found Another Person TO Ask Him\n";
          }
          else{
          lists();
          int toId;
          string p;
          cout<<"Enter User's ID You Want Ask Him.\n";
          cin>>toId;
          if(toId==user1.id)
          {
              cout<<"You Can't Ask Yourself...!!\n";
          }
          else{
         if(checked(toId)){
          cout<<"Please,Enter Your Question!\n";
          cin.ignore();
          getline(cin,p);
          question Q;
          Q.QA=p;
          Q.idf=user1.id;
          Q.idt=toId;
          Ques.push_back(Q);
          upques();
          }
          else
          {
              cout<<"Error,Not Found This User's ID..!!\n";
          }
          }
          }
      }
      void que_I_ask()
      {
          readus();
          readques();
          readAnsQues();
          readans();
            bool b;
        for(int i=0;i<Ques.size();i++)
          {
              if(Ques[i].idf==user1.id)
              {
                  b=1;
                  break;
              }
          }
          if(b)
          {
          for(int i=0;i<Ques.size();i++)
          {
              if(Ques[i].idf==user1.id)
              {
                  string l=Ques[i].QA;
                  cout<<"Question :"<<Ques[i].QA<<" To User's ID "<<Ques[i].idt<<"\n";
                  if(papl.find(l)!=papl.end())
                  {
                      cout<<"Answer : "<<papl[l]<<"\n";
                  }
                  else cout<<"Not Answerd Yet.\n";
              }
          }

          }
          else cout<<"Not Found Question From You!\n";

      }
      void forQuse()
      {
          readus();
          readques();
          readAnsQues();
          readans();
          bool b;
        for(int i=0;i<Ques.size();i++)
          {
              if(Ques[i].idt==user1.id)
              {
                  b=1;
                  break;
              }
          }
          if(b)
          {
              string y;
            for(int i=0;i<Ques.size();i++)
            {
              if(Ques[i].idt==user1.id)
              {
                  cout<<"Question :"<<Ques[i].QA<<" From User's ID "<<Ques[i].idf<<"\n";
                  y=Ques[i].QA;
                  if(papl.find(y)!=papl.end())
                  {
                      cout<<"Answer :"<<papl[y]<<"\n";
                  }
                  else cout<<"Not Answered Yet.\n";
              }
            }
          }
          else cout<<"Not Found Questions For You!\n";

      }
      void answer()
      {
          readus();
          readques();
          readans();
          readAnsQues();
          int p=0;
          for(int i=0;i<Ques.size();i++)
          {
              if(Ques[i].idt==user1.id)
              {
                  p++;

              }
          }
          if(p)
          {
              int numQues=0,num=0;
              map<int,int> mp;
              for(int i=0;i<Ques.size();i++)
          {
              if(Ques[i].idt==user1.id)
                {
                    num++;
              cout<<"Question Number "<<num<<":"<<Ques[i].QA<<"?"<<"From user's ID "<<Ques[i].idf<<"\n";
              mp[num]=i;
              if(papl.find(Ques[i].QA)!=papl.end())
                cout<<"Answer:"<<papl[Ques[i].QA]<<"\n";
              else
                cout<<"Not Answerd\n";
              }
          }

       cout<<"Enter Number Question You Want To Answer.\n";
          cin>>numQues;
         if(mp.find(numQues)==mp.end())
          {
              cout<<"Error This Number Of Question Not Found..!!\n";
              return;
          }
          int indx=numQues;
          numQues=mp[indx];
          if(papl.find(Ques[numQues].QA)!=papl.end())
          {
              cout<<"Note That This Question Has Been Answered..Do You Want To Change The Answer?!\n";
              cout<<"Enter One To Change Answer or Zero To Not Change\n";
              bool pp;
              cin>>pp;
              if(pp)
              {
                  QR q_r;
                 q_r.qa=Ques[numQues].QA;
                 string r;
                 cout<<"Enter your New answer \n";
                 getline(cin,r,'.');
                 q_r.answ=r;
                  question R;
                  R.idt=Ques[numQues].idf;
                  R.idf=user1.id;
                   R.QA=r;
                   papl[Ques[numQues].QA]=r;
                   ans.push_back(R);
                 upansw();
                 ansQa.push_back(q_r);
                 upanswQes();
              }
              return;
          }

          QR q_r;
          q_r.qa=Ques[numQues].QA;
          string r;
          cout<<"Enter your answer \n";
          getline(cin,r,'.');
          q_r.answ=r;
          question R;
          R.idt=Ques[numQues].idf;
          R.idf=user1.id;
          R.QA=r;
          papl[Ques[numQues].QA]=r;
          ans.push_back(R);
          upansw();
          ansQa.push_back(q_r);
          upanswQes();
          }
          else{
            cout<<"Not Found Question For You To Answer\n";
          }
      }
      void deleted()
      {
          readus();
          readques();
          readAnsQues();
          readans();
          int n=0,nums=0;
          map<int,int> m;
          bool b;
        for(int i=0;i<Ques.size();i++)
          {
              if(Ques[i].idf==user1.id)
              {
                  b=1;
                  break;
              }
          }
          if(b)
          {
          for(int i=0;i<Ques.size();i++)
          {
              if(Ques[i].idf==user1.id)
                {
                    nums++;
              cout<<"Question Number "<<nums<<":"<<Ques[i].QA<<"?\n";
              m[nums]=i;
              if(papl.find(Ques[i].QA)!=papl.end())
                cout<<"Answer:"<<papl[Ques[i].QA]<<"\n";
              else
                cout<<"Not AnswerEd Yet.\n";
              }
          }
          cout<<"Enter Number Of Question You Want To Delete\n";
          cin>>n;
          if(m.find(n)==m.end())
          {
              cout<<"Error This Number Of Question Not Found..!!\n";
              return;
          }
          n=m[n];
          string Qe=Ques[n].QA;
          for(int i=0;i<ansQa.size();i++)
          {
              if(ansQa[i].qa==Qe)
                ansQa.erase(ansQa.begin()+i);
          }
          papl.erase(Qe);
          Ques.erase(Ques.begin()+n);
          cout<<"Delete Successfully..\n";
          upques();
          upansw();
          upanswQes();
          }
          else
          {
              cout<<"Not Found Questions To Delete Them\n";
          }
      }

};
int main()
{
    cout<<"\n==============================================='Welcome To Ask Program'===============================================\n\n";
    three person;
    int op;
    cout<<"Menu:\n";
    cout<<"1: Login\n2: Sign Up\n\n";
    cout<<"Enter number in range 1 - 2:";
    cin>>op;
    if(op==1)
    {
        person.sginin();
    }
    else if(op==2)
    {
        person.sginup();
    }
    else
    {
        while(!(op>=1&&op<=2))
        {
        cout<<"Invalid Number Try Again..!!\n";
        cin>>op;
                if(op==1)
    {
        person.sginin();
    }
    else if(op==2)
    {
        person.sginup();
    }
        }
    }

     cout<<"Menu:\n";
        cout<<"1: Print Questions To Me\n"<<
        "2: Print Qurstions From Me\n"<<
        "3: Answer Question\n"<<
        "4: Delet Question\n"<<
        "5: Ask Question \n"<<
        "6: List System Users\n"<<
        "7: Logout\n"<<
        "8: Exit From Program\n";
        cout<<"Enter number in range 1 - 8:";
        int option;

        while(true)
        {
            cin>>option;
       if(option==1)
        person.forQuse();

       else  if(option==2)
               person.que_I_ask();

        else if(option==3)
               person.answer();

        else if(option==4)
               person.deleted();

        else if(option==5)
               person.ask();

        else if(option==6)
              person.lists();

        else if(option==7)
        {
               cout<<"Logout successfully\n";
               cout<<" \n\n";
               system("cls");
               cout<<"\n==============================================='Welcome To Ask Program'===============================================\n\n";
               cout<<"Menu:\n";
    cout<<"1: Login\n2: Sign Up\n\n";
    cout<<"Enter number in range 1 - 2:";
    cin>>op;
    if(op==1)
        person.sginin();
    else if(op==2)
        person.sginup();
    else
    {
    while(!(op>=1&&op<=2))
    {
    cout<<"Invalid Number Try Again..!!\n";
    cin>>op;
    if(op==1)
    {
        person.sginin();
    }
    else if(op==2)
    {
        person.sginup();
    }
    }
    }
    cout<<"Menu:\n";
        cout<<"1: Print Questions To Me\n"<<
        "2: Print Qurstions From Me\n"<<
        "3: Answer Question\n"<<
        "4: Delet Question\n"<<
        "5: Ask Question \n"<<
        "6: List System Users\n"<<
        "7: Logout\n"<<
        "8: Exit From Program\n";

        cout<<"Enter number in range 1 - 8\n";
        }
        else if(option==8)
        {
            cout<<"SEE YOU SOON...!\n";
            break;
        }
        else
        {
            cout<<"ERROR:Invalid Number....Try Again\n";
        }

        }

    return 0;
}
