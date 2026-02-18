# Age-Calculator
## Age Calculator using C Language
# 📅 Age Calculator in C

This is a simple **Age Calculator** written in the C programming language.
It calculates a person's exact age in **years, months, and days** based on their birth date and the current date entered by the user.

---

## 🚀 Features

* Accepts **Birth Date** and **Current Date** from the user.
* Correctly handles:

  * Leap years
  * Month borrowing when current day is smaller than birth day
  * Year adjustment when current month is smaller than birth month
* Displays accurate age in:

  ```
  X years Y months Z days
  ```
* Uses modular functions for better readability and reusability.

---

## 🧠 Program Logic

The program works using the following steps:

### 1️⃣ Leap Year Detection

A function `fnIsLeapYear(int year)` determines whether a year is a leap year.

#### Logic:

A year is a leap year if:

* It is divisible by **4 AND not divisible by 100**, OR
* It is divisible by **400**

```c
return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
```

This ensures February has **29 days** in leap years.

---

### 2️⃣ Days in Each Month

An array stores the number of days in each month:

```c
int fnMonthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
```

If the current year is a leap year, February is updated to 29:

```c
if (fnIsLeapYear(iCurrent_year))
{
    fnMonthDays[1] = 29;
}
```

---

### 3️⃣ Handling Day Borrowing (When Birth Day > Current Day)

If the birth day is greater than the current day, the program **borrows days from the previous month**.

#### Example:

Birth Date → 25
Current Date → 10
We borrow days from the previous month before subtracting.

```c
iCurrent_day += fnMonthDays[(iCurrent_month - 2 + 12) % 12];
iCurrent_month--;
```

This ensures proper day calculation across months.

---

### 4️⃣ Calculating Days Difference

```c
iDay = iCurrent_day - iBirth_day;
```

---

### 5️⃣ Handling Month Borrowing (When Birth Month > Current Month)

If the birth month hasn't occurred yet in the current year, we borrow **1 year (12 months)**.

```c
if (iBirth_month > iCurrent_month)
{
    iCurrent_year--;
    iCurrent_month += 12;
}
```

---

### 6️⃣ Calculating Final Age

```c
iMonth = iCurrent_month - iBirth_month;
iYear  = iCurrent_year - iBirth_year;
```

The final result is printed as:

```
Your Age is: X years Y months Z days
```

---

## 🏗️ Functions Used

| Function Name      | Purpose                       |
| ------------------ | ----------------------------- |
| `fnIsLeapYear()`   | Checks if a year is leap year |
| `fnCalculateAge()` | Performs full age calculation |
| `main()`           | Takes input and calls logic   |

---

## ▶️ How to Compile and Run

### 🔧 Compile

```bash
gcc age_calculator.c -o age
```

### ▶️ Run

```bash
./age
```

---

## 📌 Example Run

```
Enter your birth date (DD MM YYYY): 15 08 2002
Enter current date (DD MM YYYY): 10 02 2026

Your Age is: 23 years 5 months 26 days
```

---

## ⚠️ Limitations

* Does not validate invalid dates (e.g., 31/02/2020).
* Assumes user enters dates correctly.
* Does not automatically fetch system date.
* Global array `fnMonthDays` is modified for leap year (can be improved).

---

## 🔮 Future Improvements

* Add **date validation**.
* Automatically fetch **current system date**.
* Support different date formats.
* Convert into a reusable **library module**.
* Add unit tests.
* Remove global variable dependency.

---

## 📚 Learning Concepts Covered

This project demonstrates:

* Functions in C
* Arrays
* Conditional logic
* Modular arithmetic
* Date calculation logic
* Leap year handling
* Real-world problem solving in C

---

## 👨‍💻 Author

Developed as a practice project to understand **C programming fundamentals and date-based logic building**.

---

⭐ If you found this helpful, consider giving it a star!
