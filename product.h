typedef struct
{
    char name[256]; //variable to store product name
    char explanation[2048]; //variable to store product exlanation
    char weight[64]; //variable to store product weight
    int benefit; //variable to store the benefits of a product
    char origin[64]; //variable to store product origin
    int price; // variable to store product prices
    int methodDelivery; //variable to store delivery methods, If 1 is stored, it will be delivered early in the morning. If 2 is stored, it will be delivered by courier.
    int order; //variable to unique numbering of product for product management convenience
} Product;

//When functions operate normally they return 0
//When functions operate unnormally(read, delete, update, search when the data does not exist and add data when the data exist), they return -1
//The search functions returns -2 if the condition is not met
//if canceled during functions operation, they return -3
int ReadProduct(Product* product);  //It is a function that prints stored products.
int AddProduct(Product* product); //It is a function of adding a product.
int UpdateProduct(Product* product); //It is a function of modifying the product.
int DeleteProduct(Product* product); //It is a function to delete a product.
int SearchProductName(Product* product); //It is a function of searching products by name.
int SearchProductPrice(Product* product); //It is a function of searching for products by price. The price and search method(above/below) are determined in the function.
int SearchProductDelivery(Product* product); //It is a function of searching products by delivery method. The delivery method to be found is determined in the function.
int SelectMenu();
