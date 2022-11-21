#include "str_easy.h"

string itc_hello_str(const string &name) {
    return "Hello, " + name;
}

long long itc_len(const string &str) {
    long long i = 0;
    for (const auto &item: str)
        i++;
    return i;
}

void itc_print_copy_str(const string &str, int number) {
    for (int i = 0; i < number; ++i) {
        cout << str << endl;
    }
}

void itc_first_end_three(string str) {
    int length = (int) itc_len(str);
    if (length > 5) {
        cout
                << str[0]
                << str[1]
                << str[2]
                << str[length - 3]
                << str[length - 2]
                << str[length - 1];
    } else {
        for (int i = 0; i < length; ++i)
            cout << str[0];
        cout << endl;
    }
}

int itc_count_char_in_str(char ch, const string &str) {
    long long i = 0;
    for (const auto &item: str)
        if (ch == item)
            i++;
    return (int) i;
}

string itc_even_place(const string &str) {
    long long i = 0;
    string result;
    for (const auto &item: str) {
        if (i % 2 == 0)
            result += item;
        i++;
    }
    return result;
}

bool isLowerCase(char a) {
    return a >= 97 && a <= 122;
}

bool isUpperCase(char a) {
    return a >= 65 && a <= 90;
}

double itc_percent_lower_uppercase(const string &str) {
    double lower = 0, upper = 0;
    for (const auto &item: str)
        if (isLowerCase(item))
            lower++;
        else if (isUpperCase(item))
            upper++;

    return upper / lower * 100;
}

string itc_reverse_str(const string &str) {
    string result;
    for (const auto &item: str)
        result = item + result;
    return result;
}

string itc_slice_str(const string &str, int start, int end) {
    long long int length = itc_len(str);
    if (end > length)
        end = (int) length;
    long long counter = 0;
    string result;
    for (const auto &item: str) {
        if (counter >= start && counter <= end)
            result += item;
        counter++;
    }
    return result;
}

bool itc_equal_reverse(const string &str) {
    string reversed = itc_reverse_str(str);
    return reversed == str;
}

string itc_cmp_str(const string &str1, const string &str2, int num) {
    string first = itc_slice_str(str1, 0, num - 1);
    string third = itc_slice_str(str1, num, (int) itc_len(str1) - 1);
    return first + str2 + third;
}

int itc_find_str(string str1, string str2) {
    long long str1Length = itc_len(str1);
    long long str2Length = itc_len(str2);
    if (str2Length > str1Length)
        return -1;
    int startIndex = -1;
    int consecutive = 0;
    for (int i = 0; i < str1Length; i++) {
        if (consecutive >= str2Length)
            break;
        if (str1[i] == str2[consecutive]) {
            if (consecutive == 0)
                startIndex = i;
            consecutive++;
        }
        else {
            startIndex = -1;
            consecutive = 0;
        }
    }
    return startIndex;
}

string itc_three_str(string str1, string str2, string str3) {
    int index = itc_find_str(str1, str2);
    long long len = itc_len(str2);
    long long replacerLen = itc_len(str1);
    while (index != -1) {
        string a = itc_slice_str(str1, 0, index - 1);
        string b = itc_slice_str(str1, index + len, replacerLen);
        str1 = a + str3 + b;
        index = itc_find_str(str1, str2);
    }
    return str1;
}

long long max(long long a, long long b) {
    return a > b ? a : b;
}

bool is(string a, char b) {
    for (const auto &item: a)
        if (item == b)
            return true;
    return false;
}

long long max_repeating(const string &str, string repeater) {
    long long counter = 0;
    long long maxRepeating = 0;
    long long lastRepeating = 0;
    for (const auto &item: str) {
        if (is(repeater, item)) {
            lastRepeating++;
        } else {
            maxRepeating = max(maxRepeating, lastRepeating);
            lastRepeating = 0;
        }
        counter++;
    }
    return max(maxRepeating, lastRepeating);
}

int itc_max_char_on_end(const string& str) {
    return (int) max_repeating(str, "1234567890");
}
