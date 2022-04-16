#include <stdio.h>
#include <string.h>
#include "product.h"

int ReadProduct(Product *product)
{

    if (product->order != 1)
    {
        return -1;
    }

    printf("[%s] %s %s\n", product->origin, product->name, product->weight);
    printf("%s\n", product->explanation);
    printf("%d원\n", product->price);
    printf("--------------------------------------\n");
    printf("\n상세 내용 화면 >>\n");
    printf("[%s] %s %s\n", product->origin, product->name, product->weight);
    printf("%s\n\n", product->explanation);
    printf("%d원\n", product->price);
    printf("구매혜택 회원 적립금:     +%d원\n", product->benefit);
    printf("원산지 %25s\n", product->origin);
    printf("판매단위%25s\n", product->weight);

    if (product->methodDelivery == 1)
    {
        printf("배송방법                새벽배송\n");
    }
    else
    {
        printf("배송방법                택배배송\n");
    }
    return 0;
}

int AddProduct(Product *product)
{
    if (product->order == 1)
    {
        return -1;
    }

    getchar();
    printf("제품명: ");
    scanf("%[^\n]s", product->name);
    printf("제품설명: ");
    getchar();
    scanf("%[^\n]s", product->explanation);
    printf("제품무게(판매 단위): ");
    getchar();
    scanf("%[^\n]s", product->weight);
    printf("회원 적립금: ");
    scanf("%d", &product->benefit);
    getchar();
    printf("원산지: ");
    scanf("%[^\n]s", product->origin);
    getchar();
    printf("제품가격: ");
    scanf("%d", &product->price);
    getchar();
    printf("배송방법(1: 새벽배송 2:택배배송): ");
    scanf("%d", &product->methodDelivery);
    product->order = 1;
    return 0;
}

int UpdateProduct(Product *product)
{
    if (product->order != 1)
    {
        return -1;
    }

    getchar();
    printf("제품명: ");
    scanf("%[^\n]s", product->name);
    printf("제품설명: ");
    getchar();
    scanf("%[^\n]s", product->explanation);
    printf("제품무게(판매 단위): ");
    getchar();
    scanf("%[^\n]s", product->origin);
    printf("회원 적립금: ");
    scanf("%d", &product->benefit);
    getchar();
    printf("원산지: ");
    scanf("%[^\n]s", product->origin);
    getchar();
    printf("제품가격: ");
    scanf("%d", &product->price);
    getchar();
    printf("배송방법(1: 새벽배송 2:택배배송): ");
    scanf("%d", &product->methodDelivery);
    return 0;
}

int DeleteProduct(Product *product)
{
    if (product->order != 1)
    {
        return -1;
    }

    product->order = -0;
    return 0;
}

int SearchProductName(Product *product)
{
    if (product->order != 1)
    {
        return -1;
    }

    char searchedName[256];
    printf("검색할 제품명을 입력해주십시오: ");
    getchar();
    scanf("%[^\n]s", searchedName);
    if (strstr(product->name, searchedName) == NULL)
    {
        return -2;
    }

    ReadProduct(product);
    return 0;
}

int SearchProductPrice(Product *product)
{
    if (product->order != 1)
    {
        return -1;
    }

    int select;
    int standardPrice;

    printf("어떤 설정으로 검색하시겠습니까? (1. 이상 2. 이하), 그외: 취소");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
        printf("검색 금액을 입력해주십시오: ");
        scanf("%d", &standardPrice);

        if (product->price >= standardPrice)
        {
            ReadProduct(product);
        }

        else
        {
            return -2;
        }

        break;

    case 2:
        printf("검색 금액을 입력해주십시오: ");
        scanf("%d", &standardPrice);

        if (product->price <= standardPrice)
        {
            ReadProduct(product);
        }

        else
        {
            return -2;
        }

        break;

    default:
        return -3;
    }

    return 0;
}

int SearchProductDelivery(Product *product)
{
    if (product->order != 1)
    {
        return -1;
    }

    int select;
    printf("어떤 설정으로 검색하시겠습니까? (1. 새벽배송 2. 택배배송), 그외: 취소");
    scanf("%d", &select);

    if (select != 1 && select != 2)
    {
        return -3;
    }

    if (product->methodDelivery == select)
    {
        ReadProduct(product);
    }

    else
    {
        return -2;
    }

    return 0;
}

int SelectMenu()
{
    int menu;
    printf("\n\n1. 제품조회\n");
    printf("2. 제품추가\n");
    printf("3. 제품수정\n");
    printf("4. 제품삭제\n");
    printf("5. 제품 이름으로 검색\n");
    printf("6. 제품 가격으로 검색\n");
    printf("7. 제품 배송 방법으로 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
