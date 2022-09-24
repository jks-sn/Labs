//
// Created by User on 01.09.2022.
//

#include "BigInt.hpp"
BigInt::BigInt(): counter(1), sign(false), data(new unsigned int[this->counter])
{
    data[0] = 0;
}
BigInt::BigInt(int n) : counter (1), sign(n < 0), data(new unsigned int[this->counter])
{
    data[0] = n;
}
BigInt::BigInt(std::string s) : counter (1), sign(false), data(new unsigned int[this->counter])
{
    this->data[0] = 0;
    size_t size_string = s.size();
    bool sign_copy;
    if(size_string == 0 || size_string == 1)
        throw std::invalid_argument("Invalid argument\n"); //а он закончит или нет работу?
    if(s[0] == '+')
        sign_copy = false;
    else if(s[0] == '-')
        sign_copy = true;
    else
        throw std::invalid_argument("Invalid argument\n");
    if(std::isdigit(s[1]))
        *this += BigInt(s[1]-'0');
    for(size_t i = 2; i < size_string;++i)
    {
        if(std::isdigit(s[i]))
        {
            *this *= BigInt(10);
            *this+= BigInt(s[i]-'0');
        }
        else
            throw std::invalid_argument("Invalid argument\n");
    }
    if(sign_copy)
    {
        *this = -(*this);
    }
}
BigInt::BigInt(const BigInt& number): counter(number.counter), sign(number.sign), data(new unsigned int[this->counter])
{
    for(size_t i = 0; i < counter;++i)
    {
        data[i] = (number.data)[i];
    }
}
BigInt::~BigInt() {
    delete [] this->data;
}
BigInt& BigInt::operator=(const BigInt &number){
    if(this != &number) //чтобы делит не обнулил обе части
    {
        delete[]this->data;
        this->counter = number.counter;
        data = new unsigned int(counter);
        for(size_t i = 0; i < counter;++i)
        {
            data[i] = (number.data)[i];
        }
        this->sign = number.sign;
    }
    return (*this);
}
BigInt BigInt::operator~() const
{
    BigInt ans = *this;
    ans.sign = !(ans.sign);
    for(size_t i = 0; i < counter;++i)
    {
        ans.data[i] = ~(ans.data[i]);
    }
    return ans;
}
bool BigInt::operator==(const BigInt & number) const {
    BigInt ans = ((*this) ^ number);
    for (size_t i = 0; i < ans.counter; ++i)
        if (ans.data[i] != 0)
            return false;
    return true;
}
bool BigInt::operator!=(const BigInt & number) const {
    return (!(*this == number));
}
BigInt& BigInt::operator +=(const BigInt& number)
{
    BigInt numberCopy(number);
    if(counter > numberCopy.counter)
        numberCopy.resize(counter);
    if(numberCopy.counter > counter)
        this->resize(numberCopy.counter);
    bool isequal = true;
    if(sign != number.sign)
    {
        isequal = false;
        char isbig = this->ismore(number);
        if(isbig == 2) //определение итогового знака
        {
            this->sign = false; //обработка отсутствия отрицательного нуля
        }
        if(isbig == 0)
            this->sign = number.sign;
    }
    unsigned long long int buffer;
    bool overbuffer = false;
    for(size_t i = 0; i < counter;++i) //насколько дешёво обращение в поля класса
    {
        buffer = (unsigned long long)data[i] + number.data[i] + overbuffer;
        data[i] = buffer;
        overbuffer = (buffer > UINT_MAX);
    }
    if(isequal)
    {
        if(overbuffer) {
            this->resize(counter + 1);
            if (sign) {
                data[counter - 1] = UINT_MAX;
            } else
                data[counter - 1] = 1;
        }
    }
    return *this;
}
BigInt& BigInt::operator++(){
    return(*this += BigInt(1));
}
BigInt & BigInt::operator-=(const BigInt & number) {
    return *this += (-number);
}
BigInt BigInt::operator+() const {
    return *this;
}
BigInt BigInt::operator-() const
{
    BigInt ans = ~(*this);
    ans += BigInt(1);
    return (ans);
}
BigInt & BigInt::operator^=(const BigInt & number) {
    BigInt copyNumber = number;
    if (this->counter > copyNumber.counter)
        copyNumber.resize(this->counter);
    if (copyNumber.counter > this->counter)
        this->resize(copyNumber.counter);
    for (size_t i = 0; i < this->counter; ++i)
        this->data[i] ^= copyNumber.data[i];
    sign ^= number.sign;
    return *this;
}
BigInt & BigInt::operator&=(const BigInt & number) {
    BigInt copyNumber = number;
    sign &= number.sign;
    if (this->counter > copyNumber.counter)
        copyNumber.resize(this->counter);
    if (copyNumber.counter > this->counter)
        this->resize(copyNumber.counter);
    for (size_t i = 0; i != this->counter; ++i)
        this->data[i] &= copyNumber.data[i];
    return *this;
}
BigInt & BigInt::operator|=(const BigInt & number) {
    BigInt copyNumber = number;
    sign |= number.sign;
    if (this->counter > copyNumber.counter)
        copyNumber.resize(this->counter);
    if (copyNumber.counter > this->counter)
        this->resize(copyNumber.counter);
    for (size_t i = 0; i != this->counter; ++i)
        this->data[i] |= copyNumber.data[i];
    return *this;
}

BigInt& BigInt::operator*=(const BigInt&number)
{
    BigInt this_copy = this->sign?-(*this):*this;
    BigInt number_copy = number.sign?-(number):number;
    BigInt ans(0);
    ans.resize(counter+number.counter);
    unsigned long long buffer;
    BigInt buffer1;
    buffer1.resize(ans.counter);
    for(int i = 0; i < (counter);++i) {
        for (int j = 0; j < (number.counter); ++j)
        {
               buffer = static_cast<unsigned long long int>(this_copy.data[i])*number_copy.data[j];
               buffer1.data[i+j] = static_cast<unsigned int>(buffer);
               buffer1.data[i+j+1] = static_cast<unsigned int>(buffer>>(sizeof(unsigned int)* numberBitonBite));
               ans += buffer1;
               buffer1.data[i+j] = 0;
               buffer1.data[i+j+1] = 0;
        }
    }
    ans.sign = sign^number.sign;
    ans.clean();
    return(*this = ans);
}
BigInt &BigInt::operator/=(const BigInt & number)
{
    BigInt this_mod = this->sign?-(*this):*this;
    BigInt number_mod = number.sign?-(number):number;
    BigInt ans(0);
    BigInt buffer(0);
    if(number_mod == ans)
    {
        throw std::invalid_argument("Invalid argument of divide\n");
    }
    while(buffer + number_mod <= this_mod)
    {
        buffer += number_mod;
        ++ans;
    }
    ans.sign = (number.sign) ^ (this->sign);
    ans.clean();
    return (*this = ans);
}
BigInt &BigInt::operator%=(const BigInt & number) {
    return (*this -= ((*this/number)*number));
}
bool BigInt::operator<(const BigInt & number) const {
    if (sign && !number.sign)
        return true;
    if (!sign && number.sign)
        return false;
    char more = this->ismore(number);
    if((more == 1) && sign)
        return true;
    if((more == 0) && (!sign))
        return true;
    return false;
}
bool BigInt::operator<=(const BigInt & number) const {
    return ((*this == number) || (*this < number));
}
bool BigInt::operator>=(const BigInt & number) const {
    return (!(*this < number));
}
bool BigInt::operator>(const BigInt & number) const
{
    return (!(*this <= number));
}

void BigInt::clean()
{
    while(counter != 1 && data[counter-1] == 0)
    {
        --counter;
        this->resize(counter);
    }
}
void BigInt::resize(size_t size)
{
    if(size < 2)
    {
        return;
    }
    auto *newData = new unsigned int[size];
    size_t newLength = (counter > size) ? size : counter;
    for (size_t i = 0; i < newLength; ++i)
        newData[i] = data[i];
    for (size_t i = newLength; i != size; ++i)
        newData[i] = sign?UINT_MAX:0;
    delete [] data;
    this->data = newData;
    this->counter = size;
}
char BigInt::ismore (const BigInt& number) const {
    if(counter > number.counter)
        return 1;
    if(number.counter > counter)
        return 0;
    BigInt copy_this(*this);
    BigInt copy_number(number);
    if(copy_this.sign)
    {
        for(size_t i = 0; i < counter;++i)
        {
            copy_this.data[i] = ~(copy_this.data[i])+1;
        }
    }
    if(copy_number.sign)
    {
        for(int i = number.counter-1; i >=0;--i)
        {
            copy_number.data[i] = ~(copy_number.data[i])+1;
            if(copy_this.data[i] == copy_number.data[i])
                continue;
            if(copy_this.data[i] > copy_number.data[i])
                return 1;
            else
                return 0;
        }
        return 2;
    }
    for(int i = number.counter-1;i>=0;--i)
    {
        if(copy_this.data[i] == copy_number.data[i])
            continue;
        if(copy_this.data[i] > copy_number.data[i])
            return 1;
        else
            return 0;
    }
    return 2;
}
BigInt operator+(const BigInt & number1, const BigInt & number2) {
    BigInt ans = number1;
    ans += number2;
    return ans;
}
BigInt operator*(const BigInt & number1, const BigInt & number2) {
    BigInt ans = number1;
    ans *= number2;
    return ans;
}
BigInt operator/(const BigInt & number1, const BigInt & number2)
{
    BigInt ans = number1;
    ans /= number2;
    return ans;
}
BigInt operator%(const BigInt & number1, const BigInt & number2)
{
    BigInt ans = number1;
    ans %= number2;
    return ans;
}
BigInt operator-(const BigInt & number1, const BigInt & number2) {
    BigInt ans = number1;
    ans -= number2;
    return ans;
}

BigInt operator^(const BigInt & number1, const BigInt & number2) {
    BigInt ans = number1;
    ans ^= number2;
    return ans;
}

BigInt operator&(const BigInt & number1, const BigInt & number2) {
    BigInt ans = number1;
    ans &= number2;
    return ans;
}

BigInt operator|(const BigInt & number1, const BigInt & number2) {
    BigInt ans = number1;
    ans |= number2;
    return ans;
}
std::ostream & operator<<(std::ostream & out, const BigInt & n)
{
    BigInt n_copy = n;
    BigInt zero(0);
    out << (n.sign?'-':'+');
    std::vector<char> ans;
    BigInt base(10);
    while(n_copy != zero)
    {
        ans.push_back((n_copy%base).data[0]);
        n_copy /= base;
    }
    while(!ans.empty())
    {
        out<<(static_cast<char>('0'+ans[ans.size()-1]));
        ans.pop_back();
    }
    return out;
}
