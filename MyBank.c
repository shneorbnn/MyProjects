#include <stdio.h>
#include <stdlib.h>


static int currentNewAccount=0;
static const int maxAccounts= 50;
static int accountName= 901;
static int ab= 0;
//static int nameKey= 901;



void createNewAccount(int *p) {
    if(currentNewAccount==maxAccounts){
        printf("No more places to create a new account, sorry\n");
    }else{
    int *pC=p;
    int amount;    
    printf("amount:\t");
    scanf("%d",&amount);
    pC[currentNewAccount]=amount;    
    pC[currentNewAccount+1]=1;
printf("your bank account created successfully: %d\n",accountName);
currentNewAccount=currentNewAccount+2;
accountName++;
ab++;

    }
}

void balansOndersoek(int *p) {
    int *pB=p;
    int accountNumber;    
    printf("Account number? (901-950):\t");
    scanf("%d",&accountNumber);
    
    if(pB[((accountNumber-901)*2+1)]==1){
        printf("you have %d$ on your account\n",pB[((accountNumber-901)*2)]);
        
    }else printf("There is no access because the account is close.\n");
    
}

void deposit(int *p) {
int *pD=p;
    int amount;
    int accountNumber;    
    printf("Account number? (901-950):  ");
    scanf("%d",&accountNumber);

        if(pD[((accountNumber-901)*2+1)]==1){//if ligal
            printf("amount?:\t");
              scanf("%d",&amount);
        pD[((accountNumber-901)*2)]=pD[((accountNumber-901)*2)]+amount;
        printf("you have %d$ on your account\n",pD[((accountNumber-901)*2)]);
    }else printf("There is no access because the account is close.\n");
}

void taking(int *p) {
int *pT=p;
    int amount;
    int accountNumber;    
    printf("Account number? (901-950):  ");
    scanf("%d",&accountNumber);

            if(pT[((accountNumber-901)*2+1)]==1){//if ligal
                    printf("amount?:\t");
                    scanf("%d",&amount);
            if(pT[((accountNumber-901)*2)]>amount){
            pT[((accountNumber-901)*2)]=pT[((accountNumber-901)*2)]-amount;
            printf("you have %d$ on your account\n",pT[((accountNumber-901)*2)]);
          }
        }else printf("There is no access because the account is close.\n");

}

void closeAccount(int *p) {
    int *pClose=p;
    int accountNumber;    
    printf("Account number? (901-950):  ");
    scanf("%d",&accountNumber);
    
    pClose[((accountNumber-901)*2+1)]=0;
        printf("your account %d closed.\n",accountNumber);
        
}

void addPrime(int *p) {
int *pPrime=p;
    int interestRate;   
    int valueIndexA=0;
    printf("what your interest rate?:  ");
    scanf("%d",&interestRate);
      for(int i=0;i<ab;i++){
       pPrime[valueIndexA]=pPrime[valueIndexA]*interestRate;
       valueIndexA=valueIndexA+2;
    }

}

void printOlAccounts(int *p, int a) {
int *pP=p;
int valueIndexA=0;
int valueIndexB=1;
    printf("aN:   ");
    for(int i =901;i<accountName;i++){   //names
        printf(" %d",i);
    }
    printf("\namount ");
            for(int i=0;i<ab;i++){
                printf(" %d  ",pP[valueIndexA]);
                valueIndexA=valueIndexA+2;
    }
    printf("\n o/c:  ");
                for(int i=0;i<ab;i++){
                    printf(" %d  ",pP[valueIndexB]);
                    valueIndexB=valueIndexB+2;
    }
    printf("\n\n");

}


char upperChar(char x){
    char b=(char)x;
    if(b>='a' && b<='z'){
        b = ('A' + b -'a');
        return b;
    }else return b;
}



int main()//                                                            main
{
         int a = 100;//define the matrix of the accounts
   int *pArray = (int*)malloc(a*sizeof(int));
    
    
            for(int i=0;i<a;i++){       //Defines "amount"
    pArray[i]=0;
    }  
            for(int i=1;i<a;i++){       //Defines "open or close" 1==open and 0=close
            pArray[i]=1;i++;
    }
    
    
//                                                                              keyType
    printf("\nPlease type one these options: O,B,D,W,C,I,P,E\n");
    char yourCommand;


int stop=1;
    while (stop==1){
        
    printf("Transaction type?: ");
   scanf(" %c", &yourCommand);
   yourCommand=upperChar(yourCommand);//define the char as upper
   
   
        if(yourCommand=='O'){
            createNewAccount(pArray);
        }else if(yourCommand=='B'){
            balansOndersoek(pArray);
        }else if(yourCommand=='D'){
            deposit(pArray);
        }else if(yourCommand=='W'){
            taking(pArray);
        }else if(yourCommand=='C'){
            closeAccount(pArray);
        }else if(yourCommand=='I'){
            addPrime(pArray);
        }else if(yourCommand=='P'){
            printOlAccounts(pArray,a);
        }else if(yourCommand=='E'){
            free(pArray);
            stop=0;
        }else printf("You typed '%c' and this invalid operation please try again one these options: O,B,D,W,C,I,P,E\n",yourCommand);
    }
    
    
    
    return 0;
}