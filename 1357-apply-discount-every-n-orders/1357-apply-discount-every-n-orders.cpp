class Cashier {
public:
    int count = 0;
    unordered_map<int,double>mp;
    int num;
    double dis;

    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        num = n;
        dis = (double)discount;

        int nn = products.size();

        for(int i = 0; i < nn; i++){
            mp[products[i]] = (double)prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double subtotal = 0.0; 
        for(int i = 0; i < product.size(); i++){
            subtotal += mp[product[i]] * amount[i];
        }

        if(count % num == 0){
            double temp = (100 - dis)/100;
            subtotal = subtotal * temp;
        }

        return subtotal;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */