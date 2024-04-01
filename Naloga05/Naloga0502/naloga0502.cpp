//
// Created by danijel on 4/1/2024.
//
#include <iostream>
#include "Bank.h"

using namespace std;

void initPeople(Person* people){
    people[0].setFirstName("Alice");
    people[0].setLastName("Smith");

    people[1].setFirstName("Bob");
    people[1].setLastName("Johnson");

    people[2].setFirstName("Charlie");
    people[2].setLastName("Williams");

    people[3].setFirstName("Diana");
    people[3].setLastName("Jones");
}

int main(){
    Bank bank;

    Person people[4];
    for(int i = 0; i<4; i++){
        if(i%2 == 0){
            auto acc = new Account(i+1, (i+1)*100, &people[i]);
            bank.addAccount(acc);
        }else{
            auto acc = new SavingsAccount(i+1, (i+1)*100, &people[i], double(i+1)/100);
            bank.addAccount(acc);
        }
    }

    bank.applyInterestRates();

    bank.makeWithdrawlOnAccount(15, 4);

    cout << bank.toString() << endl;
}