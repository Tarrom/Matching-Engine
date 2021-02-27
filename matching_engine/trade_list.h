//
// Created by Jon on 1/22/2021.
//

#ifndef MATCHING_ENGINE_TRADE_LIST_H
#define MATCHING_ENGINE_TRADE_LIST_H
#include "order.h"
#include <iostream>
class trade_list{
private:
    order* head;

public:
    trade_list(){
        head=nullptr;
    }
    // add new trade to end of list
    void add_trade(order* new_trade){

        if (head==nullptr){
            head=new_trade;
        }
        else{
            order* p=head;
            for (;p->next!=nullptr;p=p->next){

            }
            p->next=new_trade;
        }
    }

    void print_trade_list(){
        for (order* p=this->head;p!=nullptr;p=p->next) {
            std::cout << "Trade" << '\n';
            std::cout << "Price is " <<p->price<< '\n';
            std::cout << "Quantity is " <<p->quantity<< '\n';
            std::cout << "Time is " <<p->time<< '\n';
        }
    }

};
#endif //MATCHING_ENGINE_TRADE_LIST_H
