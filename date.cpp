const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;


int extractYear(const string& dueDate, int i) {
    return (dueDate[i] - '0') * 1000 +
           (dueDate[i + 1] - '0') * 100 +
           (dueDate[i + 2] - '0') * 10 +
           (dueDate[i + 3] - '0');
}


int extractDayMonth(const string& dueDate, int i) {
    return (dueDate[i] - '0') * 10 +
           (dueDate[i + 1] - '0');
}


bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


bool isValid(int d, int m, int y) {
    if (y < MIN_VALID_YR || y > MAX_VALID_YR) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > 31) return false;

    if (m == 2)
        return isLeap(y) ? (d <= 29) : (d <= 28);

    if (m == 4 || m == 6 || m == 9 || m == 11)
        return (d <= 30);

    return true;
}


bool validDate(const string& date) {
    if (date.length() != 10) {
        cout << "Date format is wrong.\n";
        return false;
    }
    if (date[4] != '-' || date[7] != '-') {
        cout << "Date format is wrong.\n";
        return false;
    }

    int y = extractYear(date, 0);
    int m = extractDayMonth(date, 5);
    int d = extractDayMonth(date, 8);

    if (!isValid(d, m, y)) {
        cout << "Invalid date.\n";
        return false;
    }

    return true;
}