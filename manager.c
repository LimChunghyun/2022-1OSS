#include <stdio.h>
#include <string.h>
#include "manager.h"

int ReadFile(Product product[], int size)
{
    FILE *stream;
    if ((stream = fopen("product.txt", "r")) == NULL)
    {
        return -1;
    }

    else
    {
        while (1)
        {
            if (fscanf(stream, "%[^,], %[^,], %[^,], %d, %[^,], %d, %d\n", product[size].name, product[size].explanation, product[size].weight, &product[size].benefit, product[size].origin, &product[size].price, &product[size].methodDelivery) != -1)
            {
                product[size].order = size + 1;
                size++;
            }
            else
            {
                break;
            }
        }
        fclose(stream);
    }
    return size;
}

int ReadProduct(Product *product, int size)
{
    if (isProductNull(product, size) == 1)
    {
        return -1;
    }

    int readMethod = 0;
    printf("어떤 방식으로 조회하시겠습니까? (1. 요약 2. 상세), 그외: 취소");
    scanf("%d", &readMethod);

    switch (readMethod)
    {
    case 1:
        for (int i = 0; i < size; i++)
        {
            if (product[i].order == -1)
            {
                continue;
            }

            printf("[%d]번:\n", product[i].order);
            printf("[%s] %s %s\n", product[i].origin, product[i].name, product[i].weight);
            printf("%s\n", product[i].explanation);
            printf("%d원\n", product[i].price);
            if (product[i].methodDelivery == 1)
            {
                printf("새벽배송\n");
            }
            else
            {
                printf("택배배송\n");
            }
            printf("----------------------------------------------------------\n\n");
        }
        break;
        
    case 2:
        for (int i = 0; i < size; i++)
        {
            if (product[i].order == -1)
            {
                continue;
            }

            printf("[%d]번:\n", product[i].order);
            printf("\n상세 내용 화면 >>\n");
            printf("[%s] %s %s\n", product[i].origin, product[i].name, product[i].weight);
            printf("%s\n\n", product[i].explanation);
            printf("%d원\n", product[i].price);
            printf("구매혜택 회원 적립금:     +%d원\n", product[i].benefit);
            printf("원산지 %25s\n", product[i].origin);
            printf("판매단위%25s\n", product[i].weight);

            if (product[i].methodDelivery == 1)
            {
                printf("배송방법                새벽배송\n");
            }
            else
            {
                printf("배송방법                택배배송\n");
            }
            printf("----------------------------------------------------------\n\n");
        }
        break;
    default:
        return -3;
    }

    return 0;
}

int ReadProductDetail(Product *product, int size)
{
    if (isProductNull(product, size) == 1)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        if (product[i].order == -1)
        {
#ifdef DEBUG
            printf("DEBUG)삭제되어 비어있는 번호: array[%d]: %d번\n", i, i + 1);

#endif
            continue;
        }

        printf("[%d]번:\n", product[i].order);
        printf("\n상세 내용 화면 >>\n");
        printf("[%s] %s %s\n", product[i].origin, product[i].name, product[i].weight);
        printf("%s\n\n", product[i].explanation);
        printf("%d원\n", product[i].price);
        printf("구매혜택 회원 적립금:     +%d원\n", product[i].benefit);
        printf("원산지 %25s\n", product[i].origin);
        printf("판매단위%25s\n", product[i].weight);

        if (product[i].methodDelivery == 1)
        {
            printf("배송방법                새벽배송\n");
        }
        else
        {
            printf("배송방법                택배배송\n");
        }
        printf("--------------------------------------\n\n");
    }
    return 0;
}

int ReadProductSummary(Product *product, int size)
{
    if (isProductNull(product, size) == 1)
    {
        return -1;
    }

    return 0;
}

int AddProduct(Product *product, int size)
{
    if (size > 19)
    {
        return -1;
    }

    getchar();
    printf("제품명: ");
    scanf("%[^\n]s", product[size].name);
    printf("제품설명: ");
    getchar();
    scanf("%[^\n]s", product[size].explanation);
    printf("제품무게(판매 단위): ");
    getchar();
    scanf("%[^\n]s", product[size].weight);
    printf("회원 적립금: ");
    scanf("%d", &product[size].benefit);
    getchar();
    printf("원산지: ");
    scanf("%[^\n]s", product[size].origin);
    getchar();
    printf("제품가격: ");
    scanf("%d", &product[size].price);
    getchar();
    printf("배송방법(1: 새벽배송 2:택배배송): ");
    scanf("%d", &product[size].methodDelivery);
    product[size].order = size + 1;
#ifdef DEBUG
    printf("DEBUG)array[%d]에 %d번 상품으로 등록되었습니다.\n", size, product[size].order);

#endif
    return 0;
}

int UpdateProduct(Product *product, int selectNum)
{
    if (product[selectNum - 1].order == -1)
    {
        return -1;
    }

    getchar();
    printf("제품명: ");
    scanf("%[^\n]s", product[selectNum - 1].name);
    printf("제품설명: ");
    getchar();
    scanf("%[^\n]s", product[selectNum - 1].explanation);
    printf("제품무게(판매 단위): ");
    getchar();
    scanf("%[^\n]s", product[selectNum - 1].origin);
    printf("회원 적립금: ");
    scanf("%d", &product[selectNum - 1].benefit);
    getchar();
    printf("원산지: ");
    scanf("%[^\n]s", product[selectNum - 1].origin);
    getchar();
    printf("제품가격: ");
    scanf("%d", &product[selectNum - 1].price);
    getchar();
    printf("배송방법(1: 새벽배송 2:택배배송): ");
    scanf("%d", &product[selectNum - 1].methodDelivery);
    return 0;
}

int DeleteProduct(Product *product, int selectNum)
{
    if (product[selectNum - 1].order == -1)
    {
        return -1;
    }

    product[selectNum - 1].order = -1;
    return 0;
}

int SearchProductName(Product *product, int size)
{
    if (isProductNull(product, size) == 1)
    {
        return -1;
    }

    char searchedName[256];
    int searchedCount = 0;
    printf("검색할 제품명을 입력해주십시오: ");
    getchar();
    scanf("%[^\n]s", searchedName);

    for (int i = 0; i < size; i++)
    {
        if (strstr(product[i].name, searchedName) == NULL)
        {
            continue;
        }

        printf("[%d]번:\n", product[i].order);
        printf("[%s] %s %s\n", product[i].origin, product[i].name, product[i].weight);
        printf("%s\n", product[i].explanation);
        printf("%d원\n\n", product[i].price);
        searchedCount++;
    }

    if (searchedCount == 0)
    {
        return -2;
    }
    printf("총 %d개의 검색 데이터를 찾았습니다\n", searchedCount);

    return 0;
}

int SearchProductPrice(Product *product, int size)
{
    if (isProductNull(product, size) == 1)
    {
        return -1;
    }

    int select;
    int standardPrice;
    int searchedCount = 0;

    printf("어떤 설정으로 검색하시겠습니까? (1. 이상 2. 이하), 그외: 취소");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
        printf("검색 금액을 입력해주십시오: ");
        scanf("%d", &standardPrice);

        for (int i = 0; i < size; i++)
        {
            if (product[i].price >= standardPrice)
            {
                printf("[%d]번:\n", product[i].order);
                printf("[%s] %s %s\n", product[i].origin, product[i].name, product[i].weight);
                printf("%s\n", product[i].explanation);
                printf("%d원\n\n", product[i].price);
                searchedCount++;
            }
        }

        if (searchedCount == 0)
        {
            return -2;
        }
        printf("총 %d개의 검색 데이터를 찾았습니다\n", searchedCount);

        break;

    case 2:
        printf("검색 금액을 입력해주십시오: ");
        scanf("%d", &standardPrice);

        for (int i = 0; i < 20; i++)
        {
            if (product[i].price <= standardPrice)
            {
                printf("[%d]번:\n", product[i].order);
                printf("[%s] %s %s\n", product[i].origin, product[i].name, product[i].weight);
                printf("%s\n", product[i].explanation);
                printf("%d원\n\n", product[i].price);
                searchedCount++;
            }
        }

        if (searchedCount == 0)
        {
            return -2;
        }
        printf("총 %d개의 검색 데이터를 찾았습니다\n", searchedCount);

        break;

    default:
        return -3;
    }

    return 0;
}

int SearchProductDelivery(Product *product, int size)
{
    if (isProductNull(product, size) == 1)
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

    int searchedCount = 0;
    for (int i = 0; i < 20; i++)
    {
        if (product[i].methodDelivery == select)
        {
            printf("[%d]번:\n", product[i].order);
            printf("[%s] %s %s\n", product[i].origin, product[i].name, product[i].weight);
            printf("%s\n", product[i].explanation);
            printf("%d원\n\n", product[i].price);
            searchedCount++;
        }
    }

    if (searchedCount == 0)
    {
        return -2;
    }
    printf("총 %d개의 검색 데이터를 찾았습니다\n", searchedCount);

    return 0;
}

int SaveFile(Product *product, int size)
{
    int returnValue =0;
    if (isProductNull(product, size) == 1)
    {
        returnValue = -1;
    }
    FILE *stream;

    stream = fopen("product.txt", "w");

    for (int i = 0; i < size; i++)
    {
        if (product[i].order == -1)
        {
            continue;
        }

        fprintf(stream, "%s, %s, %s, %d, %s, %d, %d\n", product[i].name, product[i].explanation, product[i].weight, product[i].benefit, product[i].origin, product[i].price, product[i].methodDelivery);
    }

    fclose(stream);
    return returnValue;
}

int isProductNull(Product *product, int size)
{
    int nullCount = 0;
    if (size == 0)
    {
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        if (product[i].order == -1)
        {
            nullCount++;
        }
    }

    if (nullCount == size)
    {
        return 1;
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
    printf("8. 파일 저장\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
