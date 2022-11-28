#include <iostream>
using namespace std;
class DoubleArray
{
  public:
    DoubleArray();
    DoubleArray(int length, double *array);
    ~DoubleArray();
    DoubleArray operator+(double member);
    DoubleArray operator-(double member);
    DoubleArray operator*(double member);
    DoubleArray operator/(double member);
    bool Empty();
    int Length();
    double *At(const int index);
    double *Front();
    double *Back();
    double &operator[](const int index);
    void Clear();
    void Insert(int n, double data);
    void Erase(int n, int m = 0);
    void Push_back(double data);
    void Resize(int length);

  private:
    int length;
    double *array;
    friend istream &operator>>(istream &is, DoubleArray &array);
    friend ostream &operator<<(ostream &out, const DoubleArray &array);
};
DoubleArray::DoubleArray()
{
    array = NULL;
    length = 0;
}
DoubleArray::DoubleArray(int length, double *array)
{
    this->length = length;
    this->array = new double[length];
    for (int i = 0; i < length; i++)
    {
        this->array[i] = array[i];
    }
}
DoubleArray::~DoubleArray()
{
    delete[] array;
}
DoubleArray DoubleArray::operator+(double member)
{
    DoubleArray temp;
    temp.length = this->length;
    temp.array = new double[length];
    for (int i = 0; i < temp.length; i++)
    {
        temp.array[i] = this->array[i] + member;
    }
    return temp;
}
DoubleArray DoubleArray::operator-(double member)
{
    DoubleArray temp;
    temp.length = this->length;
    temp.array = new double[length];
    for (int i = 0; i < temp.length; i++)
    {
        temp.array[i] = this->array[i] - member;
    }
    return temp;
}
DoubleArray DoubleArray::operator*(double member)
{
    DoubleArray temp;
    temp.length = this->length;
    temp.array = new double[length];
    for (int i = 0; i < temp.length; i++)
    {
        temp.array[i] = this->array[i] * member;
    }
    return temp;
}
DoubleArray DoubleArray::operator/(double member)
{
    DoubleArray temp;
    temp.length = this->length;
    temp.array = new double[length];
    for (int i = 0; i < temp.length; i++)
    {
        temp.array[i] = this->array[i] / member;
    }
    return temp;
}
bool DoubleArray::Empty()
{
    if (length == 0)
        return true;
    else
        return false;
}
int DoubleArray::Length()
{
    return length;
}
double *DoubleArray::At(const int index)
{
    for (int i = 0; i < this->length; i++)
    {
        if (i == index - 1)
            return this->array + i;
    }
}
double *DoubleArray::Front()
{
    return array;
}
double *DoubleArray::Back()
{
    return array + this->length - 1;
}
double &DoubleArray::operator[](const int index)
{
    for (int i = 0; i < this->length; i++)
    {
        if (i == index)
            return this->array[i];
    }
}
void DoubleArray::Clear()
{
    delete[] this->array;
}
void DoubleArray::Insert(int n, double data)
{
    if (n < this->length + 2)
    {
        double *temp = new double[this->length + 1];
        for (int i = 0; i < n - 1; i++)
        {
            temp[i] = this->array[i];
        }
        temp[n - 1] = data;
        for (int i = n; i < this->length + 1; i++)
        {
            temp[i] = this->array[i - 1];
        }
        delete[] this->array;
        this->length++;
        this->array = new double[this->length];
        for (int i = 0; i < this->length; i++)
        {
            this->array[i] = temp[i];
        }
    }
   
}
void DoubleArray::Erase(int n, int m)
{
    if (m == 0)
    {
        if (n <= this->length)
        {
            double *temp = new double[this->length - 1];
            for (int i = 0; i < n - 1; i++)
            {
                temp[i] = this->array[i];
            }
            for (int i = n - 1; i < this->length - 1; i++)
            {
                temp[i] = this->array[i + 1];
            }
            delete[] this->array;
            this->length--;
            this->array = new double[this->length];
            for (int i = 0; i < this->length; i++)
            {
                this->array[i] = temp[i];
            }
        }
    }
    else
    {
        if (n < m && m <= this->length)
        {
            double *temp = new double[this->length - m + n - 1];
            for (int i = 0; i < n - 1; i++)
            {
                temp[i] = this->array[i];
            }
            for (int i = n - 1; i < this->length - m + n - 1; i++)
            {
                temp[i] = this->array[i + m - n + 1];
            }
            delete[] this->array;
            this->length = this->length - m + n - 1;
            this->array = new double[this->length];
            for (int i = 0; i < this->length; i++)
            {
                this->array[i] = temp[i];
            }
        }
    }
}
void DoubleArray::Push_back(double data)
{
    Insert(this->length + 1, data);
}
void DoubleArray::Resize(int length)
{
    if (this->length > length)
    {
        double *temp = new double[length];
        for (int i = 0; i < length; i++)
        {
            temp[i] = this->array[i];
        }
        delete[] this->array;
        this->length = length;
        this->array = new double[this->length];
        for (int i = 0; i < length; i++)
        {
            this->array[i] = temp[i];
        }
    }
    else
    {
        double *temp = new double[this->length];
        for (int i = 0; i < this->length; i++)
        {
            temp[i] = this->array[i];
        }
        delete[] this->array;
        this->array = new double[this->length];
        for (int i = 0; i < this->length; i++)
        {
            this->array[i] = temp[i];
        }
        int i = this->length;
        this->length = length;
        for (i; i < this->length; i++)
        {
            this->array[i] = 0;
        }
    }
}
istream &operator>>(istream &in, DoubleArray &array)
{
    cout << "enter the length of the array: ";
    in >> array.length;
    array.array = new double[array.length];
    cout << endl
         << "enter the array elements: ";
    for (int i = 0; i < array.length; i++)
    {
        in >> array.array[i];
    }
    cout << endl;
    return in;
}
ostream &operator<<(ostream &out, const DoubleArray &array)
{
    cout << "array elements: ";
    for (int i = 0; i < array.length; i++)
    {
        out << array.array[i] << " ";
    }
    return out;
}
int main()
{
}
