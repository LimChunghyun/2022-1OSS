#include <stdio.h>
#include <string.h>
#include "manager.h"

int main(void)
{
    Product product[20];
    for (int i = 0; i < 20; i++)
    {
        product[i].order = -1;
    }

    int menu;
    int count = 0;
    while (1)
    {
        menu = SelectMenu();
        if (menu == 0)
        {
            break;
        }
        if (menu == 1)
        {
            int returnValue = ReadProduct(product, count);
            if (returnValue == -1)
            {
                printf("등록된 제품이 없으므로 제품을 확인하실 수 없습니다.\n");
            }
        }

        else if (menu == 2)
        {
            int returnValue = AddProduct(product, count);
            if (returnValue == -1)
            {
                printf("목록에 제품이 가득 차있으므로 제품을 등록하실 수 없습니다.\n");
            }
            else if (returnValue == 0)
            {
                printf("->등록됨\n");
                count++;
            }
        }

        else if (menu == 3)
        {
            if (isProductNull(product, count) == 1)
            {
                printf("등록된 제품이 없으므로 수정하실 수 없습니다.\n");
                continue;
            }
            int selectNum = 0;
            printf("수정하실 제품의 번호를 입력해 주십시오:");
            scanf("%d", &selectNum);
            int returnValue = UpdateProduct(product, selectNum);
            if (returnValue == -1)
            {
                printf("해당 번호에 제품이 등록되어있지 않으므로 수정하실 수 없습니다.\n");
            }
            else if (returnValue == 0)
            {
                printf("->수정됨\n");
            }
        }
        else if (menu == 4)
        {
            if (isProductNull(product, count) == 1)
            {
                printf("등록된 제품이 없으므로 삭제하실 수 없습니다.\n");
                continue;
            }

            int selectNum = 0;
            printf("삭제하실 제품의 번호를 입력해 주십시오:");
            scanf("%d", &selectNum);
            int returnValue = DeleteProduct(product, selectNum);
            if (returnValue == -1)
            {
                printf("해당 번호에 제품이 등록되어있지 않으므로 삭제하실 수 없습니다.\n");
            }

            else if (returnValue == 0)
            {
                printf("->삭제됨\n");
            }
        }

        else if (menu == 5)
        {
            int returnValue = SearchProductName(product, count);
            if (returnValue == -1)
            {
                printf("등록된 제품이 없으므로 제품을 검색하실 수 없습니다.\n");
            }

            else if (returnValue == -2)
            {
                printf("해당 조건에 맞는 제품이 없습니다.\n");
            }

            else if (returnValue == 0)
            {
                printf("->검색됨\n");
            }
        }

        else if (menu == 6)
        {
            int returnValue = SearchProductPrice(product, count);
            if (returnValue == -1)
            {
                printf("등록된 제품이 없으므로 제품을 검색하실 수 없습니다.\n");
            }

            else if (returnValue == -2)
            {
                printf("해당 조건에 맞는 제품이 없습니다.\n");
            }

            else if (returnValue == -3)
            {
                printf("검색 도중 취소 되었습니다.\n");
            }

            else if (returnValue == 0)
            {
                printf("->검색됨\n");
            }
        }

        else if (menu == 7)
        {
            int returnValue = SearchProductDelivery(product, count);
            if (returnValue == -1)
            {
                printf("등록된 제품이 없으므로 제품을 검색하실 수 없습니다.\n");
            }

            else if (returnValue == -2)
            {
                printf("해당 조건에 맞는 제품이 없습니다.\n");
            }

            else if (returnValue == -3)
            {
                printf("검색 도중 취소 되었습니다.\n");
            }

            else if (returnValue == 0)
            {
                printf("->검색됨\n");
            }
        }
    }

    printf("종료됨!\n");
    return 0;
}
