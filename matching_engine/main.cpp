#include <iostream>
#include "order_book.h"
#include <ctime>
#include <chrono>
#include <thread>
#include "matching_engine.h"
int main() {
    order_book* a=new order_book();
    time_t now=time(0);
    order* a_buy=new order(1,5,4000.00,now);
    order* a_sell=new order(2,5,4000.00,now);
    a->insert_order(a_buy);
    a->insert_order(a_sell);




    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    time_t now2=time(0);
    order* b_buy=new order(1,10,4000.00,now2);
    order* b_sell=new order(2,10,4000.00,now2);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    time_t now3=time(0);
    order* c_buy=new order(1,15,3000.00,now3);
    order* c_sell=new order(2,15,3000.00,now3);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    time_t now4=time(0);
    order* d_buy=new order(1,20,1000.00,now4);
    order* d_sell=new order(2,20,1000.00,now4);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    time_t now5=time(0);
    order* e_buy=new order(1,20,3000.00,now5);
    order* e_sell=new order(2,20,3000.00,now5);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    time_t now6=time(0);
    order* f_buy=new order(1,20,2500.00,now6);
    order* f_sell=new order(2,20,2500.00,now6);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    time_t now7=time(0);
    order* g_buy=new order(1,20,1000.00,now7);
    order* g_sell=new order(2,20,1000.00,now7);

    a->insert_order(b_buy);
    a->insert_order(b_sell);
    a->insert_order(c_buy);
    a->insert_order(c_sell);
    a->insert_order(d_buy);
    a->insert_order(d_sell);
    a->insert_order(e_buy);
    a->insert_order(e_sell);
    a->insert_order(f_buy);
    a->insert_order(f_sell);
    a->insert_order(g_buy);
    a->insert_order(g_sell);
    a->print_buy_list();
    a->print_sell_list();
    std::cout<<"trade time \n";
    trade_list t;
    t=match(a);
    t.print_trade_list();
    a->print_buy_list();
    a->print_sell_list();
    return 0;
}