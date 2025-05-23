#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using std::cout;
using std::cin;
using std::string;

struct Product{
    string name;
    string id;
    string categoryId;
    int quantity;
};

struct ProductCategory{
    string name;
    string id;
};

// Function prototypes
void inputProduct(Product p[], int n);
void inputProductCategory(ProductCategory pc[], int n);
void outputProduct(Product p[], int n);
void outputProductCategory(ProductCategory pc[], int n);
Product findProductId(Product p[], int n, string id);
ProductCategory findProductCategoryId(ProductCategory pc[], int n, string categoryid);
int totalProduct(Product p[], int n);
Product MaxQuantity(Product p[], int n);
ProductCategory MaxProductInCategory(Product p[], ProductCategory pc[], int n);
Product FindProductName(Product p[], int n, string name);
void ClientProductFinder(Product p[], int n);
void SortProductOnName(Product p[], int n);

void inputProduct(Product p[], int n){
    for (int i = 0; i < n; i++){
        cout << "Nhap ten san pham: ";
        getline(cin >> std::ws, p[i].name);
        std::transform(p[i].name.begin(), p[i].name.end(), p[i].name.begin(), ::tolower);
        
        cout << "Nhap ma san pham: ";
        cin >> p[i].id;
        
        cout << "Nhap ma danh muc: ";
        cin >> p[i].categoryId;
        
        cout << "Nhap so luong san pham: ";
        cin >> p[i].quantity;

        cout << "\n";
    }
}

void inputProductCategory(ProductCategory pc[], int n){
    for (int i = 0; i < n; i++){
        cout << "Nhap ten danh muc: ";
        cin >> pc[i].name;
        cout << "Nhap ma danh muc: ";
        cin >> pc[i].id;

        cout << "\n";
    }
}

void outputProduct(Product p[], int n){
    for (int i = 0; i < n; i++){
        cout << "Ten san pham: " << p[i].name << '\n';
        cout << "Ma san pham: " << p[i].id << '\n';
        cout << "So luong san pham: " << p[i].quantity << '\n';
        cout << "Ma danh muc: " << p[i].categoryId << '\n';

        cout << "\n";
    }
}

void outputProductCategory(ProductCategory pc[], int n){
    for (int i = 0; i < n; i++){
        cout << "Ten danh muc: " << pc[i].name << '\n';
        cout << "Ma danh muc: " << pc[i].id << '\n';

        cout << "\n";
    }
}

Product findProductId(Product p[], int n, string id){
    for (int i = 0; i < n; i++){
        if (p[i].id == id){
            return p[i];
        }
    }
    return p[0];
}

ProductCategory findProductCategoryId(ProductCategory pc[], int n, string categoryid){
    for (int i = 0; i < n; i++){
        if (pc[i].id == categoryid){
            return pc[i];
        }
    }
    return pc[0];
}

int totalProduct(Product p[], int n){
    int total = 0;
    for (int i = 0; i < n; i++){
        total += p[i].quantity;
    }
    return total;
}

Product MaxQuantity(Product p[], int n){
    Product max;
    int maxQuantity = p[0].quantity;
    for (int i = 0; i < n; i++){
        if (p[i].quantity > maxQuantity){
            maxQuantity = p[i].quantity;
            max = findProductId(p, n, p[i].id);
        }
    }

    return max;
}


ProductCategory MaxProductInCategory(Product p[], ProductCategory pc[], int n){
    ProductCategory max;
    int maxQuantity = p[0].quantity;
    for (int i = 0; i < n; i++){
        if (p[i].quantity > maxQuantity){
            maxQuantity = p[i].quantity;
            max = findProductCategoryId(pc, n, p[i].categoryId);
        }
    }

    return max;
}


Product FindProductName(Product p[], int n, string name){
    for (int i = 0; i < n; i++){
        if (p[i].name == name){
            return p[i];
        }
    }
    return p[0];
}

void ClientProductFinder(Product p[], int n){
    string name;
    cout << "Nhap ten san pham: ";
    cin.ignore();
    getline(cin, name);
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    Product product = FindProductName(p, n, name);
    cout << "San pham tim thay: " << product.name << '\n';
    cout << "Ma san pham: " << product.id << '\n';
    cout << "So luong san pham: " << product.quantity << '\n';
    cout << "Ma danh muc: " << product.categoryId << '\n';
}

void SortProductOnName(Product p[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (p[i].name > p[j].name){
                std::swap(p[i], p[j]);
            }
        }
    }
}

int main(){
    Product p[2];
    ProductCategory pc[2];
    int n = 2;
    
    cout << "\nNhap thong tin san pham va danh muc san pham:\n";
    inputProduct(p, n);
    inputProductCategory(pc, n);
    
    cout << "\n\n";
    cout << "Thong tin san pham va danh muc san pham:\n";
    outputProduct(p, n);
    outputProductCategory(pc, n);
    
    cout << "\n\n";
    string searchId = p[0].id;
    Product foundProduct = findProductId(p, n, searchId);
    cout << "Tìm thấy hàng hóa với ID: " << searchId << ": " << foundProduct.name << "\n";
    
    cout << "\n\n";
    string searchCategoryId = pc[0].id;
    ProductCategory foundCategory = findProductCategoryId(pc, n, searchCategoryId);
    cout << "Tìm thấy danh mục hàng hóa với ID: " << searchCategoryId << ": " << foundCategory.name << "\n";
    
    cout << "\n\n";
    cout << "Tổng số lượng hàng hóa: " << totalProduct(p, n) << "\n";
    
    cout << "\n\n";
    Product maxProduct = MaxQuantity(p, n);
    cout << "Hàng hóa có số lượng lớn nhất: " << maxProduct.name << " (" << maxProduct.quantity << ")\n";
    
    cout << "\n\n";
    ProductCategory maxCategory = MaxProductInCategory(p, pc, n);
    cout << "Danh mục hàng hóa có số lượng lớn nhất: " << maxCategory.name << "\n";
    
    cout << "\n\n";
    ClientProductFinder(p, n);
    
    cout << "\n\n";
    cout << "Trước khi sắp xếp:\n";
    outputProduct(p, n);
    SortProductOnName(p, n);
    cout << "\nSau khi sắp xếp:\n";
    outputProduct(p, n);

    return 0;
}
