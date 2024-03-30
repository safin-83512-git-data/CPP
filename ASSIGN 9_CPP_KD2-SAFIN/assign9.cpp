#include <iostream>
#include <vector>
using namespace std;
enum enumType
{
    Zero,
    createAccount,
    Deposit,
    withdraw,
    balance
};

enum EAccountType
{
    saving = 1,
    current,
    Dmat
};
class insuficientFundException
{
private:
    int accNo;
    double currBalance;
    double withAmount;

public:
    insuficientFundException()
    {
        this->accNo = 0;
        this->currBalance = 0;
        this->withAmount = 0;
    }

    insuficientFundException(int accNo, double currBalance, double withAmount)
    {
        this->accNo = accNo;
        this->currBalance = currBalance;
        this->withAmount = withAmount;
    }
    void display()
    {
        cout << "Acc no " << accNo << endl;
        cout << "curr balance" << currBalance << endl;
        cout << "withdraw balance " << withAmount << endl;
    }
};
class Account
{
private:
    int accNo;
    EAccountType accounType;
    double bal;
    double cntw = 0;

public:
    Account()
    {
    }
    Account(int Accno, int accType, double bal)
    {
        this->accNo = Accno;
        this->accounType = EAccountType(accType);
        this->bal = bal;
    }
    void deposit()
    {
        cout << "Enter deposit ";
        int d;
        cin >> d;
        bal += d;
    }
    void withraw()
    {
        cout << "Enter amount withdraw ";
        int w;
        cin >> w;
        if (bal < w)
        {
            throw insuficientFundException(accNo, bal, w);
        }
        bal -= w;
    }
    int getAccno()
    {
        return accounType;
    }
    void accept()
    {
        int choice;
        cout << "Enter account no for new Account" << endl;
        cin >> accNo;
        cout << "1. Savings" << endl;
        cout << "2. current " << endl;
        cout << "3. Dmat " << endl;
        cin >> choice;
        accounType = EAccountType(choice);
        cout << "Enter account bal" << endl;
        cin >> bal;
    }
    void display()
    {
        cout << "Enter account no 43987 like " << accNo << endl;
        cout << "Account no from EAccountType  " << accounType << endl;
        cout << "Enter account bal " << bal << endl;
    }
};
int main()
{
    // Account *arr[5];
    vector<Account *> accountList;
    Account *aptr;

    //    enumType  ch = Saving;
    int index = 0;
    int ch;
   
    
      do
       {
         cout << "0 Exit " << endl;
         cout << "1 Create Account" << endl;
         cout << "2 Deposit bal" << endl;
         cout << "3 Withdraw bal" << endl;
         cout << "4 Display total balance " << endl;
         cout << " *** Enter a choice *** " << endl;
         cin >> ch;

          switch (ch)
          {
          case Zero:
            cout << "Exit ** EXIT";
            break;
          case createAccount:
         {
          
            aptr = new Account();
            aptr->accept();
            accountList.push_back(aptr);
         }
            break;
          case Deposit:
         {
            cout << "enter account no ";
            int no;
            cin >> no;
            for (int i = 0; i < accountList.size(); i++)
            {
                if (no == accountList[i]->getAccno())
                {
                    accountList[i]->deposit();
                }
            }
          }
          break;
          case withdraw:
            try
            {
                cout << "saving = 1 , current = 2 dmart = 3 enter value ";
                int no;
                cin >> no;
                for (int i = 0; i < accountList.size(); i++)
                {
                    if (no == accountList[i]->getAccno())
                    {
                        accountList[i]->withraw();
                    }
                }
            }
            catch (insuficientFundException e)
            {
                cout << "insuficient  Fund Exception ";
                e.display();
            }
            break;
          case balance:
         {
            cout << "enter account no ";
            int no;
            cin >> no;
            for (int i = 0; i < accountList.size(); i++)
            {
                if (no == accountList[i]->getAccno())
                {
                    accountList[i]->display();
                }
            }
          }  

          break;
          default:
            break;
         }
        }while (ch != 0);

        for (int i = 0; i < accountList.size(); i++)
        {
            accountList.erase(accountList.begin() + i);
            delete aptr;
        }
        for (int i = 0; i < accountList.size(); i++)
        {
            delete accountList[i];
        }
        return 0;
}