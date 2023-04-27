#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>


using namespace std;

int choosePivot(int left, int right) {
    int i1 = left + (rand() % (right - left + 1));
    int i2 = left + (rand() % (right - left + 1));
    int i3 = left + (rand() % (right - left + 1));

    return max(min(i1, i2), min(max(i1, i2), i3));
}
struct Book {
    string title;
    string author;
    float rating;
    double price;
};

class Library
{
private:
    vector<Book> books;

    void shellSortRatingHelper(vector<Book>& books, int order);
    void shellSortAuthorHelper(vector<Book>& books, int order);
    void shellSortTitleHelper(vector<Book>& books, int order);
    void shellSortPriceHelper(vector<Book>& books, int order);

    int partitionRating(vector<Book>& books, int left, int right, int order);
    int partitionAuthor(vector<Book>& books, int left, int right, int order);
    int partitionTitle(vector<Book>& books, int left, int right, int order);
    int partitionPrice(vector<Book>& books, int left, int right, int order);

    void quickSortRating(vector<Book>& books, int left, int right, int order);
    void quickSortAuthor(vector<Book>& books, int left, int right, int order);
    void quickSortTitle(vector<Book>& books, int left, int right, int order);
    void quickSortPrice(vector<Book>& books, int left, int right, int order);
public:

    Library(vector<Book> booksVec);

    void shellSortRating(int order);
    void shellSortAuthor(int order);
    void shellSortTitle(int order);
    void shellSortPrice(int order);

    void quickSortRatingHelper(int order);
    void quickSortAuthorHelper(int order);
    void quickSortTitleHelper(int order);
    void quickSortPriceHelper(int order);

    void print();
    void shuffle();

};

int Library::partitionPrice(vector<Book>& books, int left, int right, int order) {
    int pivotIndex = choosePivot(left, right);
    swap(books[right], books[pivotIndex]);
    double pivot = books.at(right).price;
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        //Orders signify ascending or descending. 
        // 1 is ascending
        // 2 is descending
        if (books.at(j).price <= pivot && order == 1) {
            swap(books[++i], books[j]);
        }
        if (books.at(j).price >= pivot && order == 2) {
            swap(books[++i], books[j]);
        }
    }
    swap(books[i + 1], books[right]);
    return (i + 1);
}
int Library::partitionRating(vector<Book>& books, int left, int right, int order) {
    int pivotIndex = choosePivot(left, right);
    swap(books[right], books[pivotIndex]);
    float pivot = books.at(right).rating;
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        //Orders signify ascending or descending. 
        // 1 is ascending
        // 2 is descending
        if (books.at(j).rating <= pivot && order == 1) {
            swap(books[++i], books[j]);
        }
        if (books.at(j).rating >= pivot && order == 2) {
            swap(books[++i], books[j]);
        }
    }
    swap(books[i + 1], books[right]);
    return (i + 1);
}
int Library::partitionAuthor(vector<Book>& books, int left, int right, int order) {
    int pivotIndex = choosePivot(left, right);
    swap(books[right], books[pivotIndex]);
    string pivot = books.at(right).author;
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        int comparison = books.at(j).author.compare(pivot);
        if (comparison <= 0 && order == 1) {
            swap(books[++i], books[j]);
        }
        if (comparison >= 0 && order == 2) {
            swap(books[++i], books[j]);
        }
    }
    swap(books[i + 1], books[right]);
    return (i + 1);
}

int Library::partitionTitle(vector<Book>& books, int left, int right, int order) {
    int pivotIndex = choosePivot(left, right);
    swap(books[right], books[pivotIndex]);
    string pivot = books.at(right).title;
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        int comparison = books.at(j).title.compare(pivot);
        if (comparison <= 0 && order == 1) {
            swap(books[++i], books[j]);
        }
        if (comparison >= 0 && order == 2) {
            swap(books[++i], books[j]);
        }
    }
    swap(books[i + 1], books[right]);
    return (i + 1);
}
void Library::quickSortAuthor(vector<Book>& books, int left, int right, int order) {
    if (left < right) {
        quickSortAuthor(books, left, partitionAuthor(books, left, right, order) - 1, order);
        quickSortAuthor(books, partitionAuthor(books, left, right, order) + 1, right, order);
    }
}


void Library::quickSortTitle(vector<Book>& books, int left, int right, int order) {
    if (left < right) {
        quickSortTitle(books, left, partitionTitle(books, left, right, order) - 1, order);
        quickSortTitle(books, partitionTitle(books, left, right, order) + 1, right, order);
    }
}

void Library::quickSortPrice(vector<Book>& books, int left, int right, int order)
{
    if (left < right) {
        quickSortPrice(books, left, partitionPrice(books, left, right, order) - 1, order);
        quickSortPrice(books, partitionPrice(books, left, right, order) + 1, right, order);
    }
}

Library::Library(vector<Book> booksVec)
{
    books = booksVec;
}

void Library::shellSortRating(int order) {
    shellSortRatingHelper(books, order);
}

void Library::shellSortAuthor(int order) {
    shellSortAuthorHelper(books, order);
}

void Library::shellSortTitle(int order) {
    shellSortTitleHelper(books, order);
}

void Library::shellSortPrice(int order) {
    shellSortPriceHelper(books, order);
}
void Library::quickSortRatingHelper(int order)
{
    quickSortRating(books, 0, books.size() - 1, order);
}

void Library::quickSortAuthorHelper(int order)
{
    quickSortAuthor(books, 0, books.size() - 1, order);
}

void Library::quickSortTitleHelper(int order)
{
    quickSortTitle(books, 0, books.size() - 1, order);
}

void Library::quickSortPriceHelper(int order)
{
    quickSortPrice(books, 0, books.size() - 1, order);
}


// Private helper method to do the shell sorting of the specified books by genre
// References: Slide 57 of Sorting Discussion PPT
void Library::shellSortRatingHelper(vector<Book>& books, int order)
{
    int n = books.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            Book temp = books[i];
            if (order == 1) {
                int j;
                for (j = i; j >= gap && books[j - gap].rating > temp.rating; j -= gap) {
                    books[j] = books[j - gap];
                }
                books[j] = temp;
            }
            if (order == 2) {
                int j;
                for (j = i; j >= gap && books[j - gap].rating < temp.rating; j -= gap) {
                    books[j] = books[j - gap];
                }
                books[j] = temp;
            }
        }
    }
}

void Library::shellSortAuthorHelper(vector<Book>& books, int order)
{
    int n = books.size();

    // Starting with a large gap, then decreasing the size of the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Performing insertion sort for this gap size
        for (int i = gap; i < n; i++)
        {
            // Ascending Order
            if (order == 1)
            {
                for (int j = i - gap; j >= 0 && books[j].author > books[j + gap].author; j -= gap)
                {
                    swap(books[j], books[j + gap]);
                }
            }
            // Descending Order
            else if (order == 2)
            {
                for (int j = i - gap; j >= 0 && books[j].author < books[j + gap].author; j -= gap)
                {
                    swap(books[j], books[j + gap]);
                }
            }
        }
    }
}

void Library::shellSortTitleHelper(vector<Book>& books, int order)
{
    int n = books.size();

    // Starting with a large gap, then decreasing the size of the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Performing insertion sort for this gap size
        for (int i = gap; i < n; i++)
        {
            // Ascending Order
            if (order == 1)
            {
                for (int j = i - gap; j >= 0 && books[j].title > books[j + gap].title; j -= gap)
                {
                    swap(books[j], books[j + gap]);
                }
            }
            // Descending Order
            else if (order == 2)
            {
                for (int j = i - gap; j >= 0 && books[j].title < books[j + gap].title; j -= gap)
                {
                    swap(books[j], books[j + gap]);
                }
            }
        }
    }
}

void Library::shellSortPriceHelper(vector<Book>& books, int order)
{
    int n = books.size();

    // Starting with a large gap, then decreasing the size of the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Performing insertion sort for this gap size
        for (int i = gap; i < n; i++)
        {
            // Ascending Order
            if (order == 1)
            {
                for (int j = i - gap; j >= 0 && books[j].price > books[j + gap].price; j -= gap)
                {
                    swap(books[j], books[j + gap]);
                }
            }
            // Descending Order
            else if (order == 2)
            {
                for (int j = i - gap; j >= 0 && books[j].price < books[j + gap].price; j -= gap)
                {
                    swap(books[j], books[j + gap]);
                }
            }
        }
    }
}


void Library::quickSortRating(vector<Book>& books, int left, int right, int order) {
    if (left < right) {
        int pivot = partitionRating(books, left, right, order);
        quickSortRating(books, left, pivot-1, order);
        quickSortRating(books, pivot + 1, right, order);
    }
}

void Library::shuffle() {
    std::random_shuffle(books.begin(), books.end());
}

void Library::print()
{
    for (Book novel : books)
    {
        cout << "Book Title: " << novel.author << "\t Author: " << novel.author << "\t Rating: " << novel.rating << "\t Price: " << novel.price << endl;
    }
}

int main()
{
    srand(time(NULL));
    vector<Book> books;

    for (int i = 0; i < 100000; i++) {
        Book book;
        string title;
        string author;
        for (int j = 0; j < 10; j++) {
            char c = rand() % 26 + 'A';
            title += c;
        }
        book.title = title;
        for (int j = 0; j < 10; j++) {
            char c = rand() % 26 + 'A';
            author += c;
        }
        book.author = author;
        book.rating = (rand() / static_cast<float>(RAND_MAX)) * 9 + 1;
        book.price = (rand() / static_cast<double>(RAND_MAX)) * 99 + 1;
        books.push_back(book);
    }

    Library library(books);

    clock_t start, end;
    double exeTime;
    cout << "Welcome to the Online Book Ranker!" << endl;
    cout << "Our library collection contains a variety of books and processes the time it took to sort them!" << endl;

    int menuOption = 0;
    while (true)
    {

        cout << "\n************Menu Options************" << endl;
        cout << "1. Rank books by rating using quickSort" << endl;
        cout << "2. Rank books by author name using quickSort" << endl;
        cout << "3. Rank books by title using quickSort" << endl;
        cout << "4. Rank books by price using quickSort" << endl;
        cout << "5. Rank books by rating using shellSort" << endl;
        cout << "6. Rank books by author name using shellSort" << endl;
        cout << "7. Rank books by title using shellSort" << endl;
        cout << "8. Rank books by price using shellSort" << endl;
        cout << "9. Shuffle the vector" << endl;
        cout << "10. Print the vector" << endl;
        cout << "11. Quit" << endl;
        cout << "Please choose a menu option: ";
        cin >> menuOption;
        if (menuOption == 1) {
            std::cout << "Type 1 for descending order; 2 for ascending order." << std::endl;
            int order;
            cin >> order;
            start = clock();
            library.quickSortRatingHelper(order);
            end = clock();
            exeTime = double(end - start) / double(CLOCKS_PER_SEC);

            std::cout << "Time taken is: " << fixed << exeTime * 1000 << setprecision(5);
            std::cout << " milliseconds " << std::endl;
            std::cout << std::endl;
        }
        if (menuOption == 2) {
            std::cout << "Type 1 for descending order; 2 for ascending order." << std::endl;
            int order;
            cin >> order;
            start = clock();
            library.quickSortAuthorHelper(order);
            end = clock();
            exeTime = double(end - start) / double(CLOCKS_PER_SEC);

            std::cout << "Time taken is: " << fixed << exeTime * 1000 << setprecision(5);
            std::cout << " milliseconds " << std::endl;
            std::cout << std::endl;
        }
        if (menuOption == 3) {
            std::cout << "Type 1 for descending order; 2 for ascending order." << std::endl;
            int order;
            cin >> order;
            start = clock();

            library.quickSortTitleHelper(order);
            end = clock();
            exeTime = double(end - start) / double(CLOCKS_PER_SEC);

            std::cout << "Time taken is: " << fixed << exeTime * 1000 << setprecision(5);
            std::cout << " milliseconds " << std::endl;
            std::cout << std::endl;
        }
        if (menuOption == 5) {
            std::cout << "Type 1 for descending order; 2 for ascending order." << std::endl;
            int order;
            cin >> order;
            start = clock();

            library.shellSortRating(order);
            end = clock();
            exeTime = double(end - start) / double(CLOCKS_PER_SEC);

            std::cout << "Time taken is: " << fixed << exeTime * 1000 << setprecision(5);
            std::cout << " milliseconds " << std::endl;
            std::cout << std::endl;
        }
        if (menuOption == 6) {
            std::cout << "Type 1 for descending order; 2 for ascending order." << std::endl;
            int order;
            cin >> order;
            start = clock();

            library.shellSortAuthor(order);
            end = clock();
            exeTime = double(end - start) / double(CLOCKS_PER_SEC);

            std::cout << "Time taken is: " << fixed << exeTime * 1000 << setprecision(5);
            std::cout << " milliseconds " << std::endl;
            std::cout << std::endl;
        }
        if (menuOption == 7) {
            std::cout << "Type 1 for descending order; 2 for ascending order." << std::endl;
            int order;
            cin >> order;
            start = clock();

            library.shellSortTitle(order);
            end = clock();
            exeTime = double(end - start) / double(CLOCKS_PER_SEC);

            std::cout << "Time taken is: " << fixed << exeTime * 1000 << setprecision(5);
            std::cout << " milliseconds " << std::endl;
            std::cout << std::endl;
        }
        if (menuOption == 4) {
            std::cout << "Type 1 for descending order; 2 for ascending order." << std::endl;
            int order;
            cin >> order;
            start = clock();

            library.quickSortPriceHelper(order);
            end = clock();
            exeTime = double(end - start) / double(CLOCKS_PER_SEC);

            std::cout << "Time taken is: " << fixed << exeTime * 1000 << setprecision(5);
            std::cout << " milliseconds " << std::endl;
            std::cout << std::endl;
        }
        if (menuOption == 8) {
            std::cout << "Type 1 for descending order; 2 for ascending order." << std::endl;
            int order;
            cin >> order;
            start = clock();

            library.shellSortPrice(order);
            end = clock();
            exeTime = double(end - start) / double(CLOCKS_PER_SEC);

            std::cout << "Time taken is: " << fixed << exeTime * 1000 << setprecision(5);
            std::cout << " milliseconds " << std::endl;
            std::cout << std::endl;
        }
        if (menuOption == 9) {

            library.shuffle();

        }
        if (menuOption == 10) {
            library.print();
        }
        if (menuOption == 11) {
            cout << "Quitting!" << endl;
            break;
        }
    }
}
