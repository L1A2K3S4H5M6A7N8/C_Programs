/*Snow Howler is the librarian at the central library of the city of HuskyLand. He must handle requests which come in the following forms:

1 x y : Insert a book with  pages at the end of the  shelf.

2 x y : Print the number of pages in the  book on the  shelf.

3 x : Print the number of books on the  shelf.

Snow Howler has got an assistant, Oshie, provided by the Department of Education. Although inexperienced, Oshie can handle all of the queries of types 2 and 3.

Help Snow Howler deal with all the queries of type 1.

Oshie has used two arrays:

int* total_number_of_books;
/*
 * This stores the total number of books on each shelf.
 */

//int** total_number_of_pages;
/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */

*/

#include <stdio.h>
#include <stdlib.h>

int* book; //This stores the total number of books in each shelf.

int** page;// This stores the total number of pages in each book of each shelf. The rows represent the shelves and the columns represent the books.

int main()
{
    int shelf;
    scanf("%d", &shelf);

    int query;
    scanf("%d", &query);

    book = (int*)malloc(sizeof(int)*shelf);
    page = (int**)malloc(sizeof(int*)*shelf);

    for(int i = 0; i < shelf; i++)
    {
        book[i] = 0;
        page[i] = (int*)malloc(sizeof(int));
    }

    while (query--)
    {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            book[x] += 1;
            page[x] = realloc(page[x], book[x]*sizeof(int));
            page[x][book[x] - 1] = y;

        }
        else if (type_of_query == 2)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", page[x][y]);
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", book[x]);
        }
    }

    if (book)
        free(book);
        
    for (int i = 0; i < shelf; i++)
        if (page[i])
            free(page[i]);
            
    if (page)
        free(page);

    return 0;
}
