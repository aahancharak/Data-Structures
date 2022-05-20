#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        orderNo = 0;    
        for(int i=0; i< products.size(); i++){
            mappah[products[i]] = prices[i];
        }
       this->discount = discount;
        num = n;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double total = 0;
        orderNo++;
        for(int i=0; i<product.size(); i++){
            total+=(double)(mappah[product[i]]*amount[i]);
        }
        if(orderNo%num==0){
            total*=((double)(100-discount)/100);
        }
        return total;
    }
    int orderNo;
    unordered_map<int, int> mappah;
    int discount;
    int num;
    
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
