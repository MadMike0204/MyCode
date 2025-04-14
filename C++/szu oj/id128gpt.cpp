#include <iostream>
#include <iomanip> // For std::setfill, std::setw
#include <cstring> // For strlen, strcpy, strncpy, isdigit, toupper
#include <string>  // For std::stoi, std::string substring constructor
#include <vector>  // Used implicitly by string conversions or can be used for checksum weights
#include <numeric> // Can be used for checksum calculation if preferred
#include <stdexcept> // For std::invalid_argument, std::out_of_range in stoi

// --- CDate Class Definition and Implementation ---

class CDate {
private:
    int year, month, day;

public:
    // Constructor with default values
    CDate(int y = 1970, int m = 1, int d = 1);

    // Check for leap year
    bool isLeap() const;

    // Validate the date
    bool check() const;

    // Print the date
    void print() const;

    // Getters for CStudentID to access date parts
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
};

// CDate Constructor Implementation
CDate::CDate(int y, int m, int d) : year(y), month(m), day(d) {}

// CDate isLeap Implementation
bool CDate::isLeap() const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// CDate check Implementation
bool CDate::check() const {
    if (year <= 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }
    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            daysInMonth = isLeap() ? 29 : 28;
            break;
        default:
            return false; // Invalid month
    }
    return day <= daysInMonth;
}

// CDate print Implementation
void CDate::print() const {
    std::cout << std::setfill('0') << std::setw(4) << year << "/"
              << std::setfill('0') << std::setw(2) << month << "/"
              << std::setfill('0') << std::setw(2) << day;
}


// --- CStudentID Class Definition and Implementation ---

class CStudentID {
private:
    char *p_id;   // Dynamically allocated C-string for ID
    char *p_name; // Dynamically allocated C-string for Name
    CDate birthday;
    int registered; // 0 for illegal, 1 for legal

    // Helper for checksum calculation
    static char calculateChecksum(const char* id_prefix17);

public:
    // Primary Constructor
    CStudentID(const char *p_idval, const char *p_nameval, const CDate &day);

    // Copy Constructor
    CStudentID(const CStudentID &r);

    // Destructor
    ~CStudentID();

    // Check registration status
    bool checked() const { return registered == 1; }

    // Print method
    void print() const;

    // Assignment operator (optional but good practice)
    CStudentID& operator=(const CStudentID& other);
};

// CStudentID Helper: Calculate Checksum
char CStudentID::calculateChecksum(const char* id_prefix17) {
    const int weights[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    const char checkCodes[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int sum = 0;
    for (int i = 0; i < 17; ++i) {
        if (!isdigit(id_prefix17[i])) return '?'; // Invalid char in prefix
        sum += (id_prefix17[i] - '0') * weights[i];
    }
    return checkCodes[sum % 11];
}

// CStudentID Primary Constructor Implementation
CStudentID::CStudentID(const char *p_idval, const char *p_nameval, const CDate &day)
    : birthday(day), p_id(nullptr), p_name(nullptr), registered(0)
{
    bool valid = true;

    // 1. Check Date Validity provided
    if (!birthday.check()) {
        valid = false;
    }

    int len = 0;
    if (valid && p_idval) { // Proceed only if date is valid and ID pointer is not null
       len = strlen(p_idval);
    } else {
       valid = false; // Date invalid or ID pointer is null
    }

    // 2. Check ID Length
    if (valid && !(len == 15 || len == 18)) {
        valid = false;
    }

    // 3. Check ID Characters and Date Consistency
    int id_year = 0, id_month = 0, id_day = 0;
    if (valid) {
        for (int i = 0; i < len - (len == 18 ? 1 : 0) ; ++i) { // Check all digits except maybe the last one if 18
            if (!isdigit(p_idval[i])) {
                valid = false;
                break;
            }
        }
        // Check last character explicitly
        if (valid && len == 18 && !isdigit(p_idval[17]) && toupper(p_idval[17]) != 'X') {
             valid = false;
        } else if (valid && len == 15 && !isdigit(p_idval[14])) { // 15-digit ID must end with a digit
             valid = false;
        }

        // Extract date parts from ID if characters are valid so far
        if (valid) {
            try {
                 std::string id_str(p_idval); // Use std::string for easier manipulation
                 if (len == 18) {
                    id_year = std::stoi(id_str.substr(6, 4));
                    id_month = std::stoi(id_str.substr(10, 2));
                    id_day = std::stoi(id_str.substr(12, 2));
                } else { // len == 15
                    id_year = 1900 + std::stoi(id_str.substr(6, 2));
                    id_month = std::stoi(id_str.substr(8, 2));
                    id_day = std::stoi(id_str.substr(10, 2));
                }

                 // Compare extracted date with provided CDate object
                 if (id_year != birthday.getYear() || id_month != birthday.getMonth() || id_day != birthday.getDay()) {
                    valid = false;
                }
            } catch (const std::invalid_argument& e) {
                 valid = false; // stoi failed - non-digits where expected
            } catch (const std::out_of_range& e) {
                 valid = false; // stoi failed - value out of range
            }
        }
    }

    // 4. Check 18-digit Checksum
    if (valid && len == 18) {
        char expected_checksum = calculateChecksum(p_idval);
        if (expected_checksum == '?' || expected_checksum != toupper(p_idval[17])) { // Checksum calculation failed or mismatch
             valid = false;
        }
    }

    // Final decision and resource allocation
    if (!valid) {
        std::cout << "illegal id" << std::endl;
        registered = 0;
        // Ensure dynamic members are null if construction fails partially
        delete[] p_id; p_id = nullptr;
        delete[] p_name; p_name = nullptr;
    } else {
        registered = 1;
        // Allocate memory and copy data (deep copy)
        p_id = new char[len + 1];
        strcpy(p_id, p_idval);

        if (p_nameval) {
             p_name = new char[strlen(p_nameval) + 1];
             strcpy(p_name, p_nameval);
        } else { // Handle null name input gracefully
             p_name = new char[1];
             p_name[0] = '\0';
        }
        // Print attributes upon successful construction
        print();
    }
}

// CStudentID Copy Constructor Implementation
CStudentID::CStudentID(const CStudentID &r)
    : birthday(r.birthday), registered(r.registered), p_id(nullptr), p_name(nullptr)
{
    // Deep copy name
    if (r.p_name) {
        p_name = new char[strlen(r.p_name) + 1];
        strcpy(p_name, r.p_name);
    } else {
         p_name = new char[1];
         p_name[0] = '\0';
    }

    // Deep copy ID, handling 15-to-18 digit conversion if necessary
    if (r.p_id && r.registered) { // Only copy/upgrade if the source was valid and had an ID
        int len = strlen(r.p_id);
        if (len == 15) {
            // Convert 15-digit to 18-digit
            p_id = new char[19]; // 18 digits + null terminator
            strncpy(p_id, r.p_id, 6);   // Region code
            p_id[6] = '1';              // Century '19'
            p_id[7] = '9';
            strncpy(p_id + 8, r.p_id + 6, 6); // YYMMDD
            strncpy(p_id + 14, r.p_id + 12, 3);// Sequence
            p_id[17] = calculateChecksum(p_id); // Calculate new checksum
            p_id[18] = '\0';            // Null-terminate
            // Registration status remains copied from 'r' (which was 1)
        } else if (len == 18) { // Source is already 18-digits
            p_id = new char[19]; // Allocate space
            strcpy(p_id, r.p_id); // Copy directly
        } else {
            // Should not happen if source 'r' was constructed correctly with registered=1
            // Handle potential error case: allocate minimal empty string
             p_id = new char[1];
             p_id[0] = '\0';
             registered = 0; // Mark the copy as invalid if source ID was weird
        }
    } else {
       // Source was invalid or had no ID
       p_id = new char[1];
       p_id[0] = '\0';
       // 'registered' is already copied from r (which would be 0)
    }
     // The copy constructor does not print anything itself.
}

// CStudentID Destructor Implementation
CStudentID::~CStudentID() {
    delete[] p_id;
    delete[] p_name;
    // Setting to nullptr is good practice but less critical in destructor
    // p_id = nullptr;
    // p_name = nullptr;
}

// CStudentID Print Method Implementation
void CStudentID::print() const {
    // Only print if the object is considered registered and pointers are valid
    if (registered == 1 && p_id && p_name) {
        std::cout << p_id << " " << p_name << " ";
        birthday.print();
        std::cout << std::endl;
    }
    // Otherwise, the primary constructor already printed "illegal id" or nothing should be printed.
}

// CStudentID Assignment Operator Implementation
CStudentID& CStudentID::operator=(const CStudentID& other) {
    if (this == &other) { // Check for self-assignment
        return *this;
    }

    // Free existing resources
    delete[] p_id;
    delete[] p_name;
    p_id = nullptr; // Set to null before potential re-allocation
    p_name = nullptr;

    // Copy scalar members and CDate object
    birthday = other.birthday;
    registered = other.registered;

    // Deep copy dynamic resources (name)
    if (other.p_name) {
        p_name = new char[strlen(other.p_name) + 1];
        strcpy(p_name, other.p_name);
    } else {
         p_name = new char[1];
         p_name[0] = '\0';
    }

    // Deep copy dynamic resources (ID) - Assignment does NOT upgrade 15-digit ID
    if (other.p_id) {
        p_id = new char[strlen(other.p_id) + 1];
        strcpy(p_id, other.p_id);
    } else {
         p_id = new char[1];
         p_id[0] = '\0';
    }

    return *this;
}


// --- Main Function ---

int main() {
    int t;
    // Disable synchronization with C stdio for potentially faster I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> t; // Read number of test cases

    while (t--) {
        int y, m, d;
        std::cin >> y >> m >> d;
        CDate birth_date(y, m, d);

        // Use std::string to read name safely, handling potential spaces if needed later
        // For now, assume name has no spaces as per typical competitive programming input
        char name_buf[100]; // Buffer for name
        char id_buf[20];   // Buffer for ID (max 18 + null terminator)

        std::cin >> name_buf >> id_buf;

        // Create the primary CStudentID object
        // The constructor handles validation and prints "illegal id" or the object details
        CStudentID s(id_buf, name_buf, birth_date);

        // If the primary object was created successfully (is registered),
        // create a copy and print the copy's details.
        if (s.checked()) {
            CStudentID s_copy = s; // Invokes the copy constructor
            s_copy.print();        // Print the state of the copied/upgraded object
        }
         // Optional separator for clarity between test case outputs
         // std::cout << "---" << std::endl;
    }

    return 0;
}
