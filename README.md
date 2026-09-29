# Bank Management System using C++

A console-based Bank Management System developed in C++ to practice and demonstrate important Object-Oriented Programming concepts.

## Project Overview

This project simulates basic banking operations for two types of accounts:

- Savings Account
- Current Account

The program allows users to create accounts, deposit and withdraw money, check balances, calculate reward points, compare account balances, and view the total number of accounts created.

## Features

- Create Savings and Current Accounts
- Deposit money
- Withdraw money
- Overdraft facility for Current Account
- Display account balance
- Calculate reward points
- Compare account balances
- Track total accounts created
- Exception handling for invalid deposits
- Menu-driven console interface

## C++ Concepts Used

This project demonstrates several Object-Oriented Programming concepts:

- Classes and Objects
- Encapsulation
- Abstraction
- Inheritance
- Multiple Inheritance
- Runtime Polymorphism
- Virtual Functions
- Pure Virtual Functions
- Virtual Destructor
- Function Overloading
- Operator Overloading
- Static Data Members
- Static Member Functions
- Friend Functions
- Exception Handling
- Dynamic Memory Allocation
- Base Class Pointers
- Method Overriding

## Account Types

### Savings Account

The Savings Account supports:

- Depositing money
- Withdrawing money when sufficient balance is available
- Calculating reward points based on balance

### Current Account

The Current Account supports:

- Depositing money
- Withdrawing money
- Overdraft facility up to ₹5,000
- Calculating reward points

## Reward System

Reward points are calculated based on the account balance.

```text
1 Reward Point = Every ₹100 of positive balance
