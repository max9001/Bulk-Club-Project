# Bulk Club has two types of members: Regular and Executive  
### Member information includes: 
- Member name 
- Membership number 
- Membership type 
- Membership expiration date 
- Total amount spent (running total) 
- Rebate amount (Executive members only) 

### A membership information file (warehouse shoppers) is provided with 
the following format: 
 
- Customer name   
- Customer membership number   
- Type of customer – Regular or Executive 
- Membership expiration date 

### Seven sales files are provided with the following format: 

- Purchase date 
- Customer membership number   
- Item purchased 
- Sales price quantity purchased  





---
---
---

# Bulk Club Project	
Your team is to write a program that supports the Bulk Club.   At least one class must contain a pointer (a copy constructor needs to be written and tested).   Highlight the above.  Your team is to write at least 10 agile stories (including description, tasks, test scenarios, and story points) before software is developed).  Your team must use an agile management tool (e.g. GITHUB, Twilio, etc), Graphical User Interface (GUI) such as QT, DOXYGEN, and GITHUB.    Only team members should have access to their repository.

<br>

The team must follow the Scrum process (the Scrum master must log all team meetings and the product owner must document the backlog).

<br>

**Sprint schedule:**
*Schedule:* 
First checkpoint – April 12th   
Second checkpoint – April 26th   
Final checkpoint – May 17th

<br>

**Bulk Club has two types of members: Regular and Executive**  
*Member information includes:* 
- Member name 
- Membership number 
- Membership type 
- Membership expiration date 
- Total amount spent (running total) 
- Rebate amount (Executive members only) 

<br>

A rebate of 2% of the total amount spent (not to include sales tax) is paid at the close of the year to the Executive members. Regular members pay annual dues of $65.00 and Executive members pay annual dues of $120.00. Your program will use the following files that will be provided:
- A membership information file (warehouse shoppers) is provided with the following format:
	+ Customer name   
	+ Customer membership number   
	+ Type of customer – Regular or Executive
	+ Membership expiration date 
- Seven sales files are provided with the following format: 
	+ Purchase date 
	+ Customer membership number   
	+ Item purchased 
	+ Sales price quantity purchased  

<br>

Your program should read from the daily sales file and update the members’ information accordingly. As the sales are processed the total amount spent and rebate data for each member should be updated. Use a sales tax rate of 7 3/4% for all revenue totals.

<br>

Generate the following displays at any time:
1. A store manager should be able to display a sales report for any given day. It should include a list of items and quantities sold on that day as well names of the members who shopped that day.  Display the total revenue (including tax) for the given day.  It should also include number of unique Executive members and Regular members who shopped during the given day.   
2. Your team should provide an option to generate the sales report (including tax) for any given day by membership type. 
3. A store manager should be able to display the total purchases for each member including tax sorted by membership number. The display should also include a grand total including tax of all the purchases for all the members.  
4. A store manager should be able to display the quantity of each item sold sorted by item name and the total revenue (without tax) for each item. 
5. A store manager should be able to display the rebate of all the Executive members sorted by membership number. Rebates are based on purchases before tax. 
6. A store manager should be able to enter a month and obtain a display of all members whose memberships expire that month as well as the cost to renew their memberships. 
7. An administrator should be able to add/delete Bulk Club members. When a Bulk Club member is deleted, their purchases remain.
8. Your team should provide the capability to create purchases of my choice for the new members to validate your software.
9. An administrator should be able to add (with a corresponding price), delete items, and change prices from the inventory list. When an item is deleted, the corresponding purchases remain. 
10.  A store manager should be able to enter an item name and only display the quantity of that item sold as well as the total revenue (without tax) for the item.  No other items should be displayed. 
11.  A store manager should be able to enter a membership number or name and display the total purchases including tax for that member. 
12.  Your program should be able to determine if any Regular customer should convert their membership to Executive status using the given sales data. Display the number of recommended conversions. 
13.  An administrator should be able to determine if any Executive customer should convert their membership to Regular status using the given sales data. Display the number of recommended conversions. 
14.  Your software should require the store manager and administrator to logon to obtain access to your program. 
15.  Your software should be able to save all changes between executions. 

<br>

Please let me know your partners by March 29, 2021 (two points will be deducted from your score if you do not meet this deadline). All projects are due by May 17th.   No late projects or artifacts will be accepted.  Your team must demonstrate your project before it will be graded.   Each teammate must identify their accomplishments on the project. Not all team members will necessarily earn the same score.  The UML diagrams should be shown during the Sprint 1 checkpoint.

1.  Design a very readable, easy to use interface to demonstrate your program.   
2.  Contingency handling should include addressing invalid input.
3.  Write at least 10 agile stories (including description, tasks, test scenarios, and story points) before any software is developed. The team must follow the Scrum process (the Scrum master must document all meetings and the product owner must document the backlog). 
4.   All changes must be persistent between executions.  
5.  Submit the following: 
	a. Test Plan 
	b. UML class diagram, at least three use cases, and at least three state diagrams, and one activity diagram 
	c. Code 
	d. Agile stories, retrospective report, coding standards and team rules 
6.  Each team must use a version control system, graphical user interface tool, automated documentation tool, and an Agile management tool. (GITHUB, DOXYGEN, GITHUB, Twilio, QT, etc.) 
7.  Each individual must critique their team members via e-mail. 
8.  All artifacts are due on May 17th. 

<br>

**Grading Rubric**
| Description | Value |
| --- | --- |
| Checkpoint 1 | 6 |
| Checkpoint 2 | 6 |
| Meets all requirements | 70 |
| Use of SQLite | 1 |
| User interface | 3 |
| Test Plan | 4 |
| Adherence to Scrum | 5 |
| UML diagrams | 4 |
| DOXYGEN | 1 |
| Total | 100 |
| Continuous Integration | 2 |
| Total with Extra Credit | 102 |
