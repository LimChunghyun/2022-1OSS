typedef struct
{
    char name[256];
    char explanation[2048];
    char weight[64];
    int benefit;
    char origin[64];
    int price;
    int methodDelivery; // If 1 is stored, it will be delivered early in the morning. If 2 is stored, it will be delivered by courier.
    int order;          // variable to unique numbering of product for product management convenience
} Product;

// When functions operate normally they return 0
// When functions operate unnormally(read, delete, update, search when the data does not exist and add data when the data exist), they return -1
// The search functions returns -2 if the condition is not met
// if canceled during functions operation, they return -3
int ReadProductDetail(Product *product, int size);
int ReadProductSummary(Product *product, int size);
int AddProduct(Product *product, int size);
int UpdateProduct(Product *product, int selectNum); // The number of the product to be modified is determined within the function.
int DeleteProduct(Product *product, int selectNum); // The number of the product to be deleted is determined within the function.
int SearchProductName(Product *product, int size);
int SearchProductPrice(Product *product, int size);
int SearchProductDelivery(Product *product, int size);
int SelectMenu();
int isProductNull(Product *product, int size);
int SaveFile(Product* product, int size);
int ReadFile(Product product[], int size);
