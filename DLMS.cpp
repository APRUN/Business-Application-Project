#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cmath>
using namespace std;

// Login/Signup Arrays
string userforloadcart[100];
string users[10] = {"jaffer", "hamid"};
string pass[10] = {"jaffer", "hamid"};
string mail[10] = {"jaffer@gmail.com", "hamidoye@gmail.com"};
string usermessage[100];
string adminmessages[100];
string availsoftware[100];
string Available_employees[10];
string Employee_Ages[10];
string Employee_Adresses[10];
string Employee_Contacts[10];
string Employee_Emails[10];
string employee_CNIC[10];
int employee_Salaries[10];
string softwarename[150];
string softwaresize[150];
string softwarecompany[150];
float softwareprice[150];
string softwarecategory[150];
string musicsoftware[30] = {"snapchat"};
float musicsoftprice[30] = {3.6};
string musicsoftsize[30] = {"159MB"};
string commerceapplication[30] = {"darwaza.pk", "octafx"};
float commercesoftprice[30] = {13, 12.5};
string commercesoftsize[30] = {"37MB", "89MB"};
string toolsoftware[30] = {"chrome", "youtube"};
float toolsoftprice[30] = {16.4, 27};
string toolsoftsize[30] = {"60MB", "123MB"};
string gamesoftware[30] = {"gta5", "snowman", "flighter"};
float gamesoftprice[30] = {79, 2, 7.0};
string gamesoftsize[30] = {
    "3.9GB",
    "79MB",
    "129MB",
};
string editingsoftware[30] = {"adobe", "capcut"};
float editingsoftprice[30] = {79, 2};
string editingsoftsize[30] = {"1.5GB", "69MB"};
float usercartprices[10];
string usercartsoftware[10] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};
string feedback_by_user[10];
int userstars[30] = {3, 4, 3};
string usercartnames[30];

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Global Variables
float Cart_price;
int starsbyuser = 0;
int usercount = 2, usercartsoftcount = 0, admin_software_count = 2, employee_count = 6,
    star_given_count = 0, usermessagecount = 0, adminmessagecount = 1, userfeedbackcounter = 0;
string suggestion, empcatsoft, empsoftname, empsoftsize;
float companyratings = 0, totalstarsbyusers = 0;
string userfeedback, tempname, user_mainmenu_choice;

// universal functions
void logo();
void clear();
int maininterface();
void newusercoming(bool);
bool signupcheck(string, string, string);
string signincheck(string, string);

// user functions
string User_MainMenu();
int User_menu_Control();
void Adding_Software_incart();
bool checkingsoftforcart(int);
string Removing_Software_incart();
bool userremovesoftfromcart(string);
string Searching_Software3();
void usersearchingsoftware(string);
void List_available_Softwares4();
void Check_mycart5();
void Rate_Us_6();
void Chat_admin7();
void See_admin_messages8();
void give_Feedback();

// admin functions
int Admin_MainMenu();
void Admin_Menu_Control();
int Admin_assigning_salaries1();
string adminviewname();
void searchempforadmin(int);
int empviewforsalary(string);
void adminassigningsalary(string, int);
int Calculation_Menu();
void Calculating_Income();
void adminseemonthlyincome(float, float, float, float);
void adminseeannualincome(float, float, float, float);
void adminseecalculation();
void Searching_info_of_software3();
string adminsearchbycat(int);
void adminsearchbyname(int);
void adminsearchgame();
void adminsearcheditor();
void adminsearchcommerce();
void adminsearchtool();
void adminsearchmusic();
void Adding_new_software4();
void addtoolbyadmin(float, float, string, string);
void addgamebyadmin(float, float, string, string);
void addmusicbyadmin(float, float, string, string);
void addcommercebyadmin(float, float, string, string);
void addeditorbyadmin(float, float, string, string);
void adminsearchbyname(int);
void See_All_available_software5();
void List_Users();
void Blacklist_User7();
string adminremovinguser(string);
//int Hire_new_employee8();
void adminaddnewemp();
string Enter_name_toremove();
void Fire_employee9();
void Updating_Software10();
int adminchoosetoupdate(string);
void adminupdatingsoftware(string,int);
void List_available_Employees11();
void Check_Company_Ratings12();
void Chat_Box13();
void Check_Insights14();
void drawgraph();
void drawinsights();
void feedback_view_byadmin();

void gotoxy(int, int);
char getcharAtxy(short int x, short int y);
void insertuserinfile(string, string, string);
void fileforsoftware(string, float, string, string, float);
void fileforemployees(string, string, string, string, int);
void cart(string, string, float);
void replacesoftdata(int);
void loadFile();
void loademployees();
void loadusers();
void savinguser();
void savingemployee();
void savingsoftware();
void savingcart();
string parseRecord(string record, int field);
void updatecartfile();
//void updateemployeefile();
string isstring(string input);
int validatinginput(int validatechoice);
main()
{
    loadFile();
    loademployees();
    // loadusers();
    system("cls");
    logo();
    maininterface();
}
int maininterface()
{
    string mainfacechoice = "56";
    while (mainfacechoice != "3")
    {
        SetConsoleTextAttribute(hConsole, 1);
        cout << "Press'1'to Signup: " << endl;
        cout << "Press'2'to Signin/Login: " << endl;
        cout << "Press'3'to Exit: " << endl;
        cout << "Please enter your choice: ";
        cin >> mainfacechoice;
        if (mainfacechoice == "1" || mainfacechoice == "2" || mainfacechoice == "3")
        {
            if (mainfacechoice == "1") // new user entering
            {
                clear();
                logo();
                SetConsoleTextAttribute(hConsole, 6);
                string newusername, newuserpassword, newuseremail;
                cout << "Enter your name: ";
                cin >> newusername;
                cout << "Enter your password: ";
                cin >> newuserpassword;
                cout << "Enter your email: ";
                cin >> newuseremail;
                bool newuserispresent = signupcheck(newusername, newuserpassword, newuseremail); // checking if user is already present or not
                if (newuserispresent == 1)                                                       // if user is not present
                {
                    SetConsoleTextAttribute(hConsole, 10);

                    cout << "Successfully Signed Up. Please Sign in now to continue." << endl; // if new user already exsist
                    clear();
                    logo();
                    savinguser();
                    maininterface();
                }
                if (newuserispresent == 0) // if user is present
                {
                    SetConsoleTextAttribute(hConsole, 4);

                    int goback = 10;
                    cout << "The user already exsist.Press '0' to go back.";
                    cin >> goback;
                    if (goback == 0)
                    {
                        maininterface();
                    }
                }
            }
            if (mainfacechoice == "2") // old user signing in
            {
                clear();
                logo();
                SetConsoleTextAttribute(hConsole, 6);

                string username, password;
                cout << "Enter your name: ";
                cin >> username;
                tempname = username;
                cout << "Enter your password: ";
                cin >> password;
                string signedinuser = signincheck(username, password);
                if (signedinuser == "user")
                {
                    User_menu_Control();
                }
                if (signedinuser == "admin")
                {
                    Admin_Menu_Control();
                }
                if (signedinuser == "0")
                {
                    maininterface();
                }
            }
            if (mainfacechoice == "3")
            {
                abort();
            }
        }
        else
        {
            clear();
            logo();
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Invalid Input" << endl;
            clear();
            logo();
            maininterface();
        }
    }
}
bool signupcheck(string newusername, string newuserpassword, string newuseremail)
{

    for (int index = 0; index <= usercount; index++)
    {

        if (users[index] == newusername && pass[index] == newuserpassword && mail[index] == newuseremail)
        {

            return 0;
        }
        else
        {
            users[usercount] = newusername;
            pass[usercount] = newuserpassword;
            mail[usercount] = newuseremail;
            usercount++;
            return 1;
        }
    }
}
string signincheck(string username, string password)
{

    for (int m = 0; m < usercount; m++)
    {
        if (username == users[m] && password == pass[m])
        {
            clear();
            logo();
            SetConsoleTextAttribute(hConsole, 10);
            cout << "        Successfully Signed In ;)" << endl
                 << endl;
            return "user";
        }
        if (password == "iamadmin1" || password == "iamadmin2")
        {
            clear();
            logo();
            return "admin";
        }
        if (password == "iamemployee")
        {
            clear();
            logo();
            return "employee";
        }
    }
    clear();
    logo();
    SetConsoleTextAttribute(hConsole, 4);
    cout << "No such user found." << endl;
    clear();
    logo();
    return "0";
}

// User Functioms
string User_MainMenu() // Viewing User Menu
{

    SetConsoleTextAttribute(hConsole, 9);
    cout << "Press'0'to Return." << endl;
    cout << "Press'1'to Add a Software to cart: " << endl;
    cout << "Press'2'to remove a Software from cart: " << endl;
    cout << "Press'3'to Search a Software: " << endl;
    cout << "Press'4'to See all available softwares: " << endl;
    cout << "Press'5'to See your cart: " << endl;
    cout << "Press'6'to Rate us: " << endl;
    cout << "Press'7'to Text admin." << endl;
    cout << "Press'8'to see admin messages." << endl;
    cout << "Press'9'to give Feedback." << endl;
    cout << "Please enter your choice...";
    cin >> user_mainmenu_choice;
    return user_mainmenu_choice;
}

int User_menu_Control() // Control user menus
{

    user_mainmenu_choice = User_MainMenu();
    clear();
    logo();
    if (user_mainmenu_choice == "0")
    {
        maininterface();
    }
    else if (user_mainmenu_choice == "1")
    {
        Adding_Software_incart();
    }
    else if (user_mainmenu_choice == "2")
    {
        clear();
        logo();
        string removeusersoft = Removing_Software_incart();
        bool isremoved = userremovesoftfromcart(removeusersoft);
        if (isremoved == 1) // if software is removed from cart
        {
            SetConsoleTextAttribute(hConsole, 10);

            clear();
            logo();
            User_menu_Control();
        }
        if (isremoved == 0) // if software is not found in cart
        {
            SetConsoleTextAttribute(hConsole, 4);

            cout << "No such software found." << endl;
            clear();
            logo();
            User_menu_Control();
        }
    }
    else if (user_mainmenu_choice == "3")
    {
        clear();
        logo();
        string usersearching = Searching_Software3();
        usersearchingsoftware(usersearching);
    }
    else if (user_mainmenu_choice == "4")
    {
        clear();
        logo();
        List_available_Softwares4();
    }
    else if (user_mainmenu_choice == "5")
    {
        Check_mycart5();
    }
    else if (user_mainmenu_choice == "6")
    {
        Rate_Us_6();
    }
    else if (user_mainmenu_choice == "7")
    {
        Chat_admin7();
    }
    else if (user_mainmenu_choice == "8")
    {
        See_admin_messages8();
    }
    else if (user_mainmenu_choice == "9")
    {
        give_Feedback();
    }
    else
    {
        clear();
        logo();
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Enter Valid Input" << endl;
        User_menu_Control();
    }
}
void Adding_Software_incart() // User adding software in its cart
{
    clear();
    logo();
    string searchsoftnameemp = "k";
    int cartadd1 = 10;
    while (searchsoftnameemp != "0")
    {
        SetConsoleTextAttribute(hConsole, 6);
        cout << "Press'0'to return" << endl;
        cout << "Enter name: ";
        cin >> searchsoftnameemp;
        if (searchsoftnameemp == "0")
        {
            clear();
            logo();
            User_menu_Control();
        }
        system("cls");
        logo();

        for (int n = 0; n < 150; n++) // searching software for cart
        {
            if (searchsoftnameemp == softwarename[n])
            {
                SetConsoleTextAttribute(hConsole, 10);

                cout << "Software Found." << endl;
                cout << "Name: " << softwarename[n] << endl;
                cout << "Size: " << softwaresize[n] << endl;
                cout << "Price: " << softwareprice[n] << endl;
                cout << "Press'0'to return." << endl;
                cout << "Press'1'to Add it in cart: " << endl;
                cin >> cartadd1;
                cart(softwarename[n], softwaresize[n], softwareprice[n]);

                clear();
                logo();
                SetConsoleTextAttribute(hConsole, 10);
                usercartsoftware[usercartsoftcount] = softwarename[usercartsoftcount];
                usercartsoftcount = usercartsoftcount + 1;
                Cart_price = Cart_price + softwareprice[n];
                cout << "Added to Cart." << endl;

                if (searchsoftnameemp == "0")
                {
                    User_menu_Control();
                }
                if (cartadd1 == 0)
                {
                    User_menu_Control();
                }
                break;
            }
        }
    }
}
bool checkingsoftforcart(int n) // User searches its software from cart to remove it
{
    for (int m = 0; m < 10; m++)
    {
        if (usercartsoftware[m] == softwarename[n])
            return true;
        else
        {
            return false;
        }
    }
}
string Removing_Software_incart() // User enters name to remove software from cart
{
    string removeusersoft = "";

        SetConsoleTextAttribute(hConsole, 6);
        cout << "Enter name of software from your cart: ";
        cin>>removeusersoft;
        clear();
        logo();
        return removeusersoft;
    
}
bool userremovesoftfromcart(string removeusersoft) // Checking wether given software is available in cart or not.
{
    int idx = 0;
    bool isremoved = false;
    for (int m = 0; m < usercartsoftcount; m++)
    {
        if (removeusersoft == usercartsoftware[m])
        {
            SetConsoleTextAttribute(hConsole, 10);
            idx = m;

            Cart_price = Cart_price - softwareprice[m];
            isremoved = true;
            break;
        }
    }
    if (isremoved == true)
    {
        for (int y = idx; y < usercartsoftcount; y++)
        {
            usercartsoftware[y] = usercartsoftware[y + 1];
        }
        savingcart();
        cout << " Removed from cart." << endl;
        usercartsoftcount--;
    }
    else
    {
        cout << "Not Present" << endl;
    }
    return isremoved;
}
string Searching_Software3() // User enters name for Searching a software
{
    string usersearching = "sjs";
    while (usersearching != "0")
    {
        SetConsoleTextAttribute(hConsole, 6);
        cout << "Press'0'to Return" << endl;
        cout << "Enter the name of software: ";
        usersearching = isstring(usersearching);
        clear();
        logo();
        return usersearching;
    }
}
void usersearchingsoftware(string usersearching) // Searching software for user
{
    for (int s = 0; s < 150; s++)
    {
        if (softwareprice[s] != 0)
        {
            if (usersearching == softwarename[s])
            {

                clear();
                logo();
                SetConsoleTextAttribute(hConsole, 10);
                cout << "Name: " << softwarename[s] << endl
                     << "Size: " << softwaresize[s] << endl
                     << "Owner: " << softwarecompany[s] << endl
                     << "Price: " << softwareprice[s] << endl;
                clear();
                logo();
                User_menu_Control();
            }
        }
    }
}
void List_available_Softwares4() // Viewing all Softwares to User
{
    SetConsoleTextAttribute(hConsole, 12);
    int x = 0, y = 16;
    gotoxy(0, 16);
    cout << "Name";
    gotoxy(x + 15, 16);
    cout << "Size";
    gotoxy(x + 30, 16);
    cout << "Price";
    gotoxy(x + 45, 16);
    cout << "Owner";
    gotoxy(60, 16);
    cout << "Category" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    y = y + 1;

    for (int z = 0; z < admin_software_count; z++)
    {
        SetConsoleTextAttribute(hConsole, 9);
        y = y + 1;
        gotoxy(0, y);
        cout << "|" << softwarename[z];
        gotoxy(x + 15, y);
        cout << softwaresize[z];
        gotoxy(x + 30, y);
        cout << softwareprice[z];
        gotoxy(x + 45, y);
        cout << softwarecompany[z];
        gotoxy(x + 60, y);
        cout << softwarecategory[z] << endl;
    }
    clear();
    logo();
    User_menu_Control();
}
void Check_mycart5() // User Viewing His cart
{
    SetConsoleTextAttribute(hConsole, 6);
    cout << "The number of softwares in your cart are: " << usercartsoftcount << endl;
    for (int i = 0; i < usercartsoftcount; i++)
    {
        if (usercartsoftware[i] == " ")
            continue;
        cout << usercartsoftware[i] << endl;
    }
    clear();
    logo();
    User_menu_Control();
}
void Rate_Us_6() // user rating company
{
    SetConsoleTextAttribute(hConsole, 6);
    cout << "How many stars u will rate us out of five: ";
    cin >> starsbyuser;
    totalstarsbyusers = starsbyuser + totalstarsbyusers;
    userstars[star_given_count] = starsbyuser;
    star_given_count = star_given_count + 1;
    clear();
    logo();
    User_menu_Control();
}
void Chat_admin7() // sending message to admin
{
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Press'0'to exit." << endl;
    cout << "Enter the message: ";
    cin.ignore();
    getline(cin, usermessage[usermessagecount]);
    if (usermessage[usermessagecount] == "0")
    {
        clear();
        logo();
        User_menu_Control();
    }
    usermessagecount = usermessagecount + 1;
    clear();
    logo();
    User_menu_Control();
}
void See_admin_messages8() // User Viewing admin messages
{
    for (int y = 0; y < adminmessagecount; y++)
    {
        SetConsoleTextAttribute(hConsole, 3);
        if (adminmessages[y] != "0")
            cout << adminmessages[y] << endl;
    }
    clear();
    logo();
    User_menu_Control();
}
void give_Feedback() // User giving Feedack to admin
{
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Enter your suggestion: ";
    getline(cin.ignore(), userfeedback);
    feedback_by_user[userfeedbackcounter] = userfeedback;
    userfeedbackcounter = userfeedbackcounter + 1;
    clear();
    logo();
    User_menu_Control();
}

// Admin code
int Admin_MainMenu() // View admin Main Menu Options
{
    SetConsoleTextAttribute(hConsole, 9);
    int adminmainchoice = 19;
    cout << "Press'1'to  Manage salaries of empoyees: " << endl;
    cout << "Press'2'to  Check monthly income of company: " << endl;
    cout << "Press'3'to  Search information of a software: " << endl;
    cout << "Press'4'to  Add a new software: " << endl;
    cout << "Press'5'to  See all available softwares: " << endl;
    cout << "Press'6'to  see your users: " << endl;
    cout << "Press'7'to  Remove a customer from login: " << endl;
    cout << "Press'8'to  Hire new employee: " << endl;
    cout << "Press'9'to  Fire an employee: " << endl;
    cout << "Press'10'to Update information of a software: '" << endl;
    cout << "Press'11'to See all available employees: " << endl;
    cout << "Press'12'to check your company ratings: " << endl;
    cout << "Press'13'to see and send chat: " << endl;
    cout << "Press'14'to see insights." << endl;
    cout << "Press'15'to see feedbacks by users" << endl;
    cout << "Press'0'to go back: ";
    cout << "Please enter your choice...";
    cin >> adminmainchoice;
    return adminmainchoice;
}

void Admin_Menu_Control() // Controling Which menu is to be viewed based on choice
{
    int adminmainchoice = 76;
    while (adminmainchoice != 0)
    {
        adminmainchoice = Admin_MainMenu();

        while (adminmainchoice < 16)
        {
            if (adminmainchoice == 0)
            {
                clear();
                logo();
                maininterface();
            }
            if (adminmainchoice == 1)
            {
                Admin_assigning_salaries1();
            }
            if (adminmainchoice == 2)
            {
                Calculating_Income();
            }
            if (adminmainchoice == 3)
            {
                Searching_info_of_software3();
            }
            if (adminmainchoice == 4)
            {
                Adding_new_software4();
            }
            if (adminmainchoice == 5)
            {
                See_All_available_software5();
            }
            if (adminmainchoice == 6)
            {
                List_Users();
            }
            if (adminmainchoice == 7)
            {

                Blacklist_User7();
                
            }
            if (adminmainchoice == 8)
            {
                adminaddnewemp();
            }
            if (adminmainchoice == 9)
            {
                Fire_employee9();
            }
            if (adminmainchoice == 10)
            {
                Updating_Software10();
            }
            if (adminmainchoice == 11)
            {
                List_available_Employees11();
            }
            if (adminmainchoice == 12)
            {
                clear();
                logo();
                Check_Company_Ratings12();
            }
            if (adminmainchoice == 13)
            {
                Chat_Box13();
            }
            if (adminmainchoice == 14)
            {
                Check_Insights14();
            }
            if (adminmainchoice == 15)
            {
                feedback_view_byadmin();
            }
        }
    }
}

int Admin_assigning_salaries1() // Admin Salary Management Control
{
    clear();
    logo();
    clear();
    logo();

    string empname = adminviewname();      // asking for employee name
    int index = empviewforsalary(empname); // gives us the index of employee in array and view details of employee
    clear();
    logo();
    Admin_Menu_Control();
}
string adminviewname() // Admin Entering Name to edit salary
{
    string empname;
    clear();
    logo();
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Enter the name of employee: ";
    empname=isstring(empname);
    return empname;
}
int empviewforsalary(string empname) // Giving Output of Employee to edit his salary
{
    for (int empno = 0; empno < 10; empno++)
    {
        if (empname == Available_employees[empno])
        {
            system("cls");
            logo();
            SetConsoleTextAttribute(hConsole, 10);
            cout << "Name: " << empname << "\t\t"
                 << "Age: " << Employee_Ages[empno] << "\t\t" << endl;
            cout << "Adress: " << Employee_Adresses[empno] << "\t\t"
                 << "Contact no. " << Employee_Contacts[empno] << "\t\t";
            cout << "E-Mail: " << Employee_Emails[empno] << endl;
        }

        int index = empno;
        adminassigningsalary(empname, index);
    }
}
void adminassigningsalary(string empname, int index) // assigning salary to employee
{
    int salaryassigning;
    SetConsoleTextAttribute(hConsole, 6);
    cout << "How much salary you want to assign to " << empname << " : ";
    cin >> salaryassigning;
    employee_Salaries[index] = salaryassigning;
    SetConsoleTextAttribute(hConsole, 15);
    if (salaryassigning == 0)
    {
        User_menu_Control();
    }
    cout << empname << "'s salary is: " << salaryassigning << endl;
}

int Calculation_Menu()
{
    int choiceismy = 10;
    cout << "Press'0'to return." << endl;
    cout << "Press'1'to see monthly daily earning: " << endl;
    cout << "Press'2'to see annual daily earning: " << endl;
    cout << "Press'3'to see calculations: " << endl;
    cout << "Please enter your choice...";
    cin >> choiceismy;
    return choiceismy;
}
void Calculating_Income() // Asking admin wether he wants to calculate income for month or year
{
    clear();
    logo();
    int choiceismy = Calculation_Menu();
    SetConsoleTextAttribute(hConsole, 6);
    while (choiceismy < 4)
    {

        if (choiceismy == 1)
        {
            clear();
            logo();
            SetConsoleTextAttribute(hConsole, 6);
            float selling, tax, salar, expenses;
            cout << "Enter total selling of softwares(monthly): ";
            cin >> selling;
            cout << "Enter percentage of tax: ";
            cin >> tax;
            cout << "Enter total salaries of employees: ";
            cin >> salar;
            cout << "Enter other expenses: ";
            cin >> expenses;
            adminseemonthlyincome(tax, salar, expenses, selling);
        }
        if (choiceismy == 2)
        {
            clear();
            logo();
            SetConsoleTextAttribute(hConsole, 6);
            float annualselling;
            float selling, tax, salar, expenses;
            cout << "Enter the annual income: ";
            cin >> annualselling;
            cout << "Enter tax percentage per year: ";
            cin >> tax;
            cout << "Enter total salaries of employee: ";
            cin >> salar;
            cout << "Enter other annual expenses: ";
            cin >> expenses;
            adminseeannualincome(tax, salar, expenses, annualselling);
        }
        if (choiceismy == 3)
        {
            clear();
            logo();
            adminseecalculation();
        }
        if (choiceismy == 0)
        {
            clear();
            logo();
            Admin_Menu_Control();
        }

        clear();
        logo();
    }
}
void adminseemonthlyincome(float tax, float salar, float expenses, float selling) // Admin calculating Monthly Income
{
    float tempog, exp, final, choice, month, annu, annualselling;
    string annincome;

    clear();
    logo();
    tempog = (tax * 100) / selling;
    exp = tempog + salar + expenses;
    final = selling - exp;
    month = final / 30;
    cout << "The total monthly earning is: " << final << endl;
    cout << "The daily monthly income including expenses is: " << month << endl;
}
void adminseeannualincome(float tax, float salar, float expenses, float annualselling) // Admin calculating annaual income
{
    clear();
    logo();
    float tempog, exp, final, choice, month, annu;
    string annincome;
    tempog = (tax * 100) / annualselling;
    exp = tempog + salar + expenses;
    final = annualselling - exp;
    cout << "The total daily income: " << final / 365 << endl;
    cout << "The yearly income is: " << final;
}
void adminseecalculation() // If admin wants to see calculations for income
{

    clear();
    logo();
    float selling, tax, salar, expenses, tempog, exp, final, choice, month, annu, annualselling;
    string annincome;

    SetConsoleTextAttribute(hConsole, 10);
    cout << "The total amount of tax is: " << tempog << endl;
    cout << "The amount after tax is: " << selling << endl;
    cout << "The total expenses of company are: " << exp << endl;
}

void Searching_info_of_software3() // Admin searching about a software
{
    clear();
    logo();
    int choice = 0;

    string search2;
    while (choice < 3)
    {

        SetConsoleTextAttribute(hConsole, 6);
        cout << "Press'0'to return." << endl;
        cout << "Press'1'to Search by name: " << endl;
        cout << "Press'2'to Search by Category: " << endl;
        cin >> choice;
        if (choice == 1)
        {
            adminsearchbyname(choice);
            break;
        }
        if (choice == 0)
        {
            Admin_Menu_Control();
        }
        if (choice == 2)
        {
            string catname = adminsearchbycat(choice);
            if (catname == "games")
            {
                adminsearchgame();
                break;
            }
            if (catname == "tools")
            {
                adminsearchtool();
                break;
            }
            if (catname == "commerce")
            {
                adminsearchcommerce();
                break;
            }
            if (catname == "music")
            {
                adminsearchmusic();
                break;
            }
            if (catname == "editor")
            {
                adminsearcheditor();
                break;
            }
        }
    }
}
void adminsearchbyname(int choice) // Admin Searching software by name
{
    clear();
    logo();
    string search2;
    float var = 0; // storing count to determine the length of search2
    string temp;   // just transferring a value

    while (choice != 0)
    {

        clear();
        logo();
        SetConsoleTextAttribute(hConsole, 6);
        cout << "Press'0'to return" << endl;
        cout << "Enter the word you want to search: ";
        cin >> search2;
        if (search2 == "0")
        {
            clear();
            logo();
            Admin_Menu_Control();
        }
        for (int f = 0; f < 150; f++)
        {
            temp = softwarename[f];
            for (int m = 0; m < search2.length(); m++)
            {
                if (search2[m] == temp[m])
                {
                    var++;
                    if (var == search2.length())
                    {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "Your results are: " << endl;
                        cout << "Name: " << softwarename[f] << endl;
                        cout << "Company name:" << softwarecompany[f] << endl;
                        cout << "Price($): " << softwareprice[f] << endl;
                        clear();
                        logo();
                        Admin_Menu_Control();
                    }
                }
            }
        }
    }
}
string adminsearchbycat(int choice) // Admin Searching software by category
{
    clear();
    logo();
    string search2;
    float var = 0; // storing count to determine the length of search2
    string temp;   // just transferring a value

    clear();
    logo();
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Enter name of the category(games/tools/music/editor/commerce): ";
    cin >> search2;
    clear();
    logo();
    return search2;
}
void adminsearchgame() // Admin Searching Game
{
    int x = 23, y = 13;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "The Games are: " << endl;

    for (int f = 0; f < 30; f++)
    {
        if (gamesoftprice[f + 1] != 0)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "Name: " << gamesoftware[f];
            gotoxy(x, y);
            cout << gamesoftprice[f] << endl;
            y++;
        }
    }
}
void adminsearchcommerce() // Admin searching Commerce Application
{
    SetConsoleTextAttribute(hConsole, 10);
    int x = 23, y = 13;
    cout << "The E-commerce applications are: " << endl;
    for (int z = 0; z < 30; z++)
    {
        if (commercesoftprice[z + 1] != 0)
        {
            SetConsoleTextAttribute(hConsole, 10);

            cout << "Name: " << commerceapplication[z];
            gotoxy(x, y);
            cout << "Price: " << commercesoftprice[z] << endl;
            y++;
        }
    }
    clear();
    logo();
    Admin_Menu_Control();
}
void adminsearchtool() // Admin searching Tool software
{
    SetConsoleTextAttribute(hConsole, 10);

    int x = 23, y = 13;
    cout << "The tools are: " << endl;
    for (int f = 0; f < 30; f++)
    {
        if (toolsoftprice[f + 1] != 0)
            cout << "Name: " << toolsoftware[f];
        gotoxy(x, y);
        cout << "Price: " << toolsoftprice[f] << endl;
        y++;
    }
}
void adminsearchmusic() // Admin searching Music Software
{
    SetConsoleTextAttribute(hConsole, 10);

    int x = 23, y = 13;
    cout << "The music softwares are: " << endl;
    for (int i = 0; i < 30; i++)
    {

        if (musicsoftprice[i] != 0)
        {
            cout << "Name: " << musicsoftware[i] << endl;
            gotoxy(x, y);
            cout << "Price: " << musicsoftprice[i] << endl;
            y++;
        }
    }
    clear();
    logo();
}
void adminsearcheditor() // Adming searching Editor
{
    SetConsoleTextAttribute(hConsole, 10);

    int x = 23, y = 13;
    cout << "The softwares are: " << endl;
    for (int q = 0; q < 30; q++)
    {
        if (editingsoftprice[q] != 0)
        {
            cout << "Name: " << editingsoftware[q];
            gotoxy(x, y);
            cout << "Price: " << editingsoftprice[q] << endl;

            y++;
        }
    }
}

void Adding_new_software4() // Admin adding a new software
{
    string name = "j", compname, category;
    float size = 0, price = 0;

    clear();
    logo();

    while (name != "0")
    {
        SetConsoleTextAttribute(hConsole, 6);

        cout << "Press'0' to Return." << endl;
        cout << "Enter the name of software: ";
        cin >> name;
        admin_software_count++;
        if (name == "0")
        {
            break;
        }
        cout << "Enter size of software: ";
        cin >> size;
        cout << "Enter the Owner/Company name: ";
        cin >> compname;
        cout << "Enter the category of the software(games/tools/editor/commerce/music): ";
        cin >> category;
        cout << "Enter the price in dollars: ";
        cin >> price;
        fileforsoftware(name, size, compname, category, price);
        if (category == "games")
        {
            addgamebyadmin(price, size, name, compname);
        }
        if (category == "tools")
        {
            addtoolbyadmin(price, size, name, compname);
        }
        if (category == "editor")
        {
            addeditorbyadmin(price, size, name, compname);
        }
        if (category == "commerce")
        {
            addcommercebyadmin(price, size, name, compname);
        }
        if (category == "music")
        {
            addmusicbyadmin(price, size, name, compname);
        }
    }
    clear();
    logo();
    Admin_Menu_Control();
}
void addeditorbyadmin(float price, float size, string name, string compname) // Admin adding an editor software
{
    SetConsoleTextAttribute(hConsole, 10);
    softwarename[admin_software_count] = name;
    softwaresize[admin_software_count] = size;
    softwarecompany[admin_software_count] = compname;
    editingsoftware[admin_software_count] = name;
    softwareprice[admin_software_count] = price;
    editingsoftprice[admin_software_count] = softwareprice[admin_software_count];
    cout << "Software Added" << endl;
    clear();
    logo();
}
void addtoolbyadmin(float price, float size, string name, string compname) // Admin adding a tool Software
{
    SetConsoleTextAttribute(hConsole, 10);

    softwarename[admin_software_count] = name;
    softwaresize[admin_software_count] = size;
    softwarecompany[admin_software_count] = compname;
    toolsoftware[admin_software_count] = name;
    softwareprice[admin_software_count] = price;
    toolsoftprice[admin_software_count] = softwareprice[admin_software_count];
    cout << "Software Added" << endl;

    clear();
    logo();
}
void addmusicbyadmin(float price, float size, string name, string compname) // Admin Adding music software
{
    SetConsoleTextAttribute(hConsole, 10);

    softwarename[admin_software_count] = name;

    softwaresize[admin_software_count] = size;

    softwarecompany[admin_software_count] = compname;

    musicsoftware[admin_software_count] = name;
    softwareprice[admin_software_count] = price;
    musicsoftprice[admin_software_count] = softwareprice[admin_software_count];
    cout << "Software Added" << endl;

    clear();
    logo();
}
void addgamebyadmin(float price, float size, string name, string compname) // Admin adding game software
{
    SetConsoleTextAttribute(hConsole, 10);

    softwarename[admin_software_count] = name;
    softwaresize[admin_software_count] = size;
    softwarecompany[admin_software_count] = compname;
    gamesoftware[admin_software_count] = name;
    softwareprice[admin_software_count] = price;
    gamesoftprice[admin_software_count] = softwareprice[admin_software_count];
    cout << "Software Added" << endl;

    clear();
    logo();
}
void addcommercebyadmin(float price, float size, string name, string compname) // Admin adding commerce software
{
    SetConsoleTextAttribute(hConsole, 10);

    softwarename[admin_software_count] = name;
    softwaresize[admin_software_count] = size;
    softwarecompany[admin_software_count] = compname;
    commerceapplication[admin_software_count] = name;
    softwareprice[admin_software_count] = price;
    commercesoftprice[admin_software_count] = softwareprice[admin_software_count];
    cout << "Software Added" << endl;

    clear();
    logo();
}

void See_All_available_software5() // Admin Viewing all softwares
{
    SetConsoleTextAttribute(hConsole, 12);
    clear();
    logo();
    int x = 0, y = 16;
    gotoxy(x, y);
    cout << "Name";
    gotoxy(x + 17, y);
    cout << "Size";
    gotoxy(x + 34, y);
    cout << "Owner";
    gotoxy(x + 51, y);
    cout << "Price" << endl;
    cout << "------------------------------------------------------" << endl;
    y = y + 1;
    for (int m = 0; m < admin_software_count + 1; m++)
    {

        if (softwareprice[m] != 0)
        {
            SetConsoleTextAttribute(hConsole, 9);

            if (softwareprice[m] == ' ')
                continue;
            y = y + 1;
            gotoxy(x, y);
            cout << softwarename[m];
            gotoxy(x + 17, y);
            cout << softwaresize[m];
            gotoxy(x + 34, y);
            cout << softwarecompany[m];
            gotoxy(x + 51, y);
            cout << softwareprice[m] << endl;
        }
    }
    clear();
    logo();
    Admin_Menu_Control();
}

void List_Users() // Admin viewing all Users on Application
{
    clear();
    logo();
    SetConsoleTextAttribute(hConsole, 12);

    int x = 0, y = 12;
    gotoxy(x, y);
    cout << "Name";
    gotoxy(x + 13, y);
    cout << "Password";
    gotoxy(x + 34, y);
    cout << "E-mail" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    y = y + 1;

    for (int m = 0; m < 10; m++)
    {

        if (users[m] != "")
        {
            SetConsoleTextAttribute(hConsole, 9);
            y = y + 1;
            gotoxy(x, y);
            cout << users[m];
            gotoxy(x + 13, y);
            cout << pass[m];
            gotoxy(x + 47, y);
            cout << mail[m] << endl;
        }
    }
    clear();
    logo();
    Admin_Menu_Control();
}

void Blacklist_User7() // Admin entering name for Blacklisting a User
{
    clear();
    logo();
    string check = "10";
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Press'0'to return." << endl;
    cout << "Enter user name of customer that you want to remove: ";
    cin >> check;
    check = adminremovinguser(check);
    savinguser();
    if (check == "")
    {
        Admin_Menu_Control();
    }
}
string adminremovinguser(string check) // Admin removing User
{

    for (int g = 0; g < usercount; g++)
    {
        if (check == users[g])
        {
            for(int f=g;f<usercount;f++)
            {
                users[g]=users[g+1];
                pass[g]=pass[g+1];
                mail[g]=mail[g+1];
            }
            SetConsoleTextAttribute(hConsole, 4);
            cout << "User removed" << endl;
            break;
        }
    }

    clear();
    logo();
    return "";
}

void adminaddnewemp() // Admin Entering info of new employee
{
    int salari;
    string empname, contact, cnic, age;

        clear();
        logo();

        employee_count++;
        SetConsoleTextAttribute(hConsole, 6);
        cout << "Press'0'to return." << endl;
        cout << "Enter name of new employee: ";
        cin >> empname;
        if(empname != "0")
        {
        cout << "Enter the age of employee: ";
        cin >> age;
        cout << "Enter the phone number of employee: ";
        cin >> contact;
        cout << "Enter the CNIC of employee: ";
        cin >> cnic;
        cout << "Enter the salaray: ";
        cin >> salari;
        fileforemployees(empname, age, contact, cnic, salari);
        // Available_employees[employee_count] = empname;
        // Employee_Ages[employee_count] = age;
        // Employee_Contacts[employee_count] = contact;
        // employee_CNIC[employee_count] = cnic;
        // employee_Salaries[employee_count] = salari;
        //updateemployeefile();
        savingemployee();
        SetConsoleTextAttribute(hConsole, 10);
        cout << "Employee added." << endl;
        }
    

    clear();
    logo();
    Admin_Menu_Control();
}

string Enter_name_toremove() // Admin Entering name to fire Employee
{
    string name = "10";

    clear();
    logo();
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Press'0'to return." << endl;
    cout << "Enter the name of the employee: ";
    cin >> name;
    return name;
}
void Fire_employee9() // Admin Firing Employee
{
    SetConsoleTextAttribute(hConsole, 6);
    string name = Enter_name_toremove();
    employee_count--;
    if (name == "0")
    {
        clear();
        logo();
        Admin_Menu_Control();
    }
    for (int m = 0; m < 10; m++)
    {
        if (name == Available_employees[m])
        {

            SetConsoleTextAttribute(hConsole, 4);
            Available_employees[m] = "";
            Employee_Ages[m] = "";
            Employee_Contacts[m] = "";
            Employee_Adresses[m] = "";
            Employee_Emails[m] = "";
            employee_CNIC[m] = "";
            
            for (int q = 0; q < employee_count; q++)
            {
                Available_employees[m] = Available_employees[m + 1];
                Employee_Ages[m] = Employee_Ages[m + 1];
                Employee_Contacts[m] = Employee_Contacts[m + 1];
                Employee_Adresses[m] = Employee_Adresses[m + 1];
                Employee_Emails[m] = Employee_Emails[m + 1];
                employee_CNIC[m] = employee_CNIC[m + 1];
            }
            savingemployee();
            cout << endl
                 << "-----------Employee Fired.---------" << endl;

                    break;
        }
    }
    clear();
    logo();
}

void Updating_Software10() // Admin entering name to update a software info
{
    string soft = "10";

    clear();
    logo();
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Press'0'to return." << endl;
    cout << "Enter the name of software: ";
    cin >> soft;
    int idx = adminchoosetoupdate(soft);
                    clear();
                logo();
    string choosetoupdate;
                SetConsoleTextAttribute(hConsole, 6);
                cout << "What you want to edit(name/price/owner): ";
                cin >> choosetoupdate;
    adminupdatingsoftware(choosetoupdate,idx);
}
int adminchoosetoupdate(string soft) // Searching software to Update
{
    if (soft != "0")
    {
        for (int r = 0; r < admin_software_count; r++)
        {

            if (soft == softwarename[r])
            {
                cout << softwarename[r] << endl;
                cout << softwaresize[r] << endl;
                cout << softwarecompany[r] << endl;
                cout << softwareprice[r] << endl;
                 return r;

            }
        }
    }
}
void adminupdatingsoftware(string choosetoupdate,int idx) // Updating Software according to admin requirment
{

    string choose, nname, nowner;
    float nprice;


        if (choosetoupdate == "name")
        {
            SetConsoleTextAttribute(hConsole, 6);
            cout << "Enter new name: ";
            cin >> nname;
            SetConsoleTextAttribute(hConsole, 10);
           softwarename[idx] = nname;
            cout << "Edited" << endl;
              savingsoftware();
 
    
            clear();
            logo();
            Admin_Menu_Control();
        }
        if (choosetoupdate == "price")
        {
            SetConsoleTextAttribute(hConsole, 6);

            cout << "Enter the new price: ";
            cin >> nprice;
            softwareprice[idx]=nprice;
    
            SetConsoleTextAttribute(hConsole, 10);
              savingsoftware();

            cout << "Edited" << endl;
            clear();
            logo();
            Admin_Menu_Control();
        }
        if (choosetoupdate == "owner")
        {
            SetConsoleTextAttribute(hConsole, 6);


            cout << "Enter name of new owner: ";
            cin >> nowner;
            softwarecompany[idx]=nowner;
              savingsoftware();
    
            SetConsoleTextAttribute(hConsole, 10);

            cout << "Edited" << endl;
            clear();
            logo();
            Admin_Menu_Control();
        }
    
    clear();
    logo();
}

void List_available_Employees11() // Admin Listing all Available Employees
{
    clear();
    logo();
    int x = 0, y = 14;
    SetConsoleTextAttribute(hConsole, 12);
    gotoxy(x, y);
    cout << "Name";
    gotoxy(x + 18, y);
    cout << "Contact no.";
    gotoxy(x + 51, y);
    cout << "CNIC";
    gotoxy(x + 68, y);
    cout << "Age" << endl;
    y = y + 1;
    // cout << Available_employees[0];
    // cout << Available_employees[1];
    for (int s = 0; s < employee_count + 1; s++)
    {
        if (Employee_Ages != 0)
        {
            if (Available_employees[s] == " ")
                continue;
            SetConsoleTextAttribute(hConsole, 9);
            y = y + 1;
            gotoxy(x, y);
            cout << Available_employees[s];
            gotoxy(x + 17, y);
            cout << Employee_Contacts[s];
            gotoxy(x + 51, y);
            cout << employee_CNIC[s];
            gotoxy(x + 68, y);
            cout << Employee_Ages[s];
        }
    }
    gotoxy(0, y + 1);
    clear();
    logo();
    Admin_Menu_Control();
}

void Check_Company_Ratings12() // Calculating and checking company
{
    int newstar_given_count = star_given_count * 5;
    companyratings = totalstarsbyusers / newstar_given_count;
    companyratings = companyratings * 10;
    ceil(companyratings);
    cout << "Your rating is " << companyratings << "out of 10." << endl;
    float examine_rating;
    examine_rating = totalstarsbyusers / companyratings;
    examine_rating = examine_rating * 100;
    if (examine_rating > 50)
    {
        SetConsoleTextAttribute(hConsole, 10);
        cout << "" << endl;
    }
    if (examine_rating < 50)
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout << ":(" << endl;
    }

    clear();
    logo();
    Admin_Menu_Control();
}

void Chat_Box13() // Chatting and viewing messages of User
{
    clear();
    logo();
    int messagechoice;
    SetConsoleTextAttribute(hConsole, 6);
    cout << "Press'0'to return." << endl;
    cout << "Press'1'to see all messages of user." << endl;
    cout << "Press'2'to send message to user." << endl;
    cout << "Enter your choice...";
    cin >> messagechoice;
    if (messagechoice == 0)
    {
        Admin_Menu_Control();
    }
    if (messagechoice == 1)
    {
        for (int u = 0; u < usermessagecount; u++)
        {
            SetConsoleTextAttribute(hConsole, 6);
            cout << usermessage[u] << endl;
        }
    }
    if (messagechoice == 2)
    {

        for (int y = 0; y < adminmessagecount; y++)
        {
            SetConsoleTextAttribute(hConsole, 6);

            cout << "Press'0'to exit." << endl;
            cout << "Enter the message: ";
            SetConsoleTextAttribute(hConsole, 3);

            cin.ignore();
            getline(cin, adminmessages[y]);
            if (adminmessages[y] == "0")
            {
                clear();
                logo();
                Admin_Menu_Control();
            }
        }
    }
    clear();
    logo();
}

void Check_Insights14() // Draing Graph Axis for Insights
{
    clear();
    logo();
    drawgraph();
    int hor = 6, ver = 26;
    int graph = totalstarsbyusers * 3;
    drawinsights();
     getch();
     system("cls");
    logo();
    Admin_Menu_Control();
}
void drawgraph() // Drawing Graph Axis
{

    int y = 12;
    for (int i = 0; i < 15; i++)
    {
        SetConsoleTextAttribute(hConsole, 10);

        gotoxy(6, y);
        cout << "]";
        y++;
    }
    gotoxy(6, 27);

    for (int u = 0; u < 30; u++)
    {
        cout << "_";
    }
}
void drawinsights()
{
    int index = 0;
    char m = 223;
    int row = 9;
    int col = 14;
    SetConsoleTextAttribute(hConsole, 4);
    for (int q = 0; q < star_given_count; q++)
    {
        for (int u = 0; u < userstars[index]; u++)
        {
            if (userstars[index] < 100)
            {
                gotoxy(row, col);
                cout << m;
                row = row + 1;
            }
        }
        index = index + 1;
        col = col + 1;
    }
}

void feedback_view_byadmin() // Admin Viewing Feedback of users
{
    clear();
    logo();
    SetConsoleTextAttribute(hConsole, 10);
    for (int i = 0; i < userfeedbackcounter; i++)
    {
        cout << feedback_by_user[i] << endl;
    }
    clear();
    logo();
    Admin_Menu_Control();
}

void insertuserinfile(string usernameforfile, string userpasswordforfile, string useremailforfile) // Inserting Usernames,Passwords and E-mails in TXT file
{
    users[usercount] = usernameforfile;
    pass[usercount] = userpasswordforfile;
        usercount++;
}
void savinguser()
{
    fstream userfile;
    userfile.open("usernames.txt", ios::out);
    for (int i = 0; i < usercount; i++)
    {
        if(users[i]=="")
        continue;
        userfile << users[i] << "," << pass[i] << "," << endl;
    }
    userfile.close();  
}
void fileforsoftware(string softnameforfile, float softsizeforfile, string compnameforfile, string softcatforfile, float softpriceforfile)
{
    // Storing all data about a software in txt file
softwarename[admin_software_count]=softnameforfile;
softwaresize[admin_software_count]=softsizeforfile;
softwarecategory[admin_software_count]=softcatforfile;
softwaresize[admin_software_count]=softsizeforfile;
softwarecompany[admin_software_count]=compnameforfile;
admin_software_count++;

}

void savingsoftware()
{
    fstream softfile;
    softfile.open("softwares.txt", ios::out);
    for(int y=0;y<admin_software_count;y++)
    {
        if(softwarename[y]=="")
        continue;
    softfile << softwarename[y] << "," << softwaresize[y] << "MB," << softwarecategory[y] << "," << softwareprice[y] << "," << softwarecompany[y] << endl;
    }
    softfile.close();
}

void fileforemployees(string empnameforfile, string empageforfile, string empcontactforfile, string employee_CNICforfile, int empsalaryforfile)
{
    // Storing all data of employees in txt file
    Available_employees[employee_count]=empnameforfile;
    Employee_Ages[employee_count]=empageforfile;
    Employee_Contacts[employee_count]=empcontactforfile;
    employee_CNIC[employee_count]=employee_CNICforfile;
    employee_Salaries[employee_count]=empsalaryforfile;
    employee_count++;

}

void savingemployee()
{
    cout << endl;
    fstream empfile;
    empfile.open("employeedata.txt", ios::out);
    for(int u=0;u<employee_count;u++)
    {
        if(Available_employees[u]=="")
        continue;
    empfile << Available_employees[u]<< "," << Employee_Ages[u] << "," << Employee_Contacts[u] << "," << employee_CNIC[u] << "," << employee_Salaries[u] << endl;
    }
    empfile.close();
}

void cart(string name, string price, float size)
{
    usercartsoftware[usercartsoftcount]=name;
    usercartnames[usercartsoftcount]=tempname;
    usercartsoftcount++;

}

void savingcart()
{
    cout << endl;
    fstream cartfile;
    cartfile.open("cart.txt", ios::out);
    for(int u=0;u<usercartsoftcount;u++)
    {
                if (usercartnames[u] == "")
            continue;
    cartfile << usercartnames[u] << "," <<usercartsoftware[u] << endl;
    }
    cartfile.close();
}


void logo()
{
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\t******************************************************" << endl;
    cout << "\t** oooooooooo.   ooooo ooo        ooooo  .oooooo..o **" << endl;
    cout << "\t** `888'   `Y8b  `888  `88.       .888' d8P'    `Y8 **" << endl;
    cout << "\t**  888      888  888   888b     d'888  Y88bo.      **" << endl;
    cout << "\t**  888      888  888   8 Y88. .P  888   ` Y8888o.  **" << endl;
    cout << "\t**  888      888  888   8  `888`   888       ` Y88b **" << endl;
    cout << "\t**  888     d88'  888   8    Y     888  oo     .d8P **" << endl;
    cout << "\t** o888bood8P'   o888o o8o        o888o 88888888P'  **" << endl;
    cout << "\t******************************************************" << endl;
    cout << "__________________________________________________________________________" << endl
         << endl
         << endl;
}
void clear() // For clearing Screen and getchch()
{
    cout << "Press any key to continue: ";
    getch();
    system("cls");
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getcharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void loadFile() // loading Software data from Software's Txt File
{
    fstream file;
    string line;
    file.open("softwares.txt", ios::in);
    admin_software_count = 0;
    while (!file.eof())
    {
        getline(file, line);
        if (line == "")
            continue;
        softwarename[admin_software_count] = parseRecord(line, 1);
        softwaresize[admin_software_count] = parseRecord(line, 2);
        softwarecategory[admin_software_count] = parseRecord(line, 3);
        softwareprice[admin_software_count] = stof(parseRecord(line, 4));
        softwarecompany[admin_software_count] = parseRecord(line, 5);
        admin_software_count += 1;
    }
    file.close();
}

void loadcart() //picking data from crt
{
    string line;
    fstream usercart;
    usercart.open("cart.txt", ios::in);
    while (!usercart.eof())
    {
        getline(usercart, line);
        if (line == "")
            continue;
        usercartsoftware[usercartsoftcount] = parseRecord(line, 1);
        usercartprices[usercartsoftcount] = stof(parseRecord(line, 2));
        usercartsoftcount++;
    }
    usercart.close();
}

void loademployees() // Loading Employees data from Employee txt file
{
    fstream file;
    string line;
    while (getline(file, line))
    {
        if (line == "")
            break;
        Available_employees[employee_count] = parseRecord(line, 1);
        Employee_Ages[employee_count] = parseRecord(line, 2);
        Employee_Contacts[employee_count] = parseRecord(line, 3);
        employee_CNIC[employee_count] = parseRecord(line, 4);
        employee_Salaries[employee_count] = stoi(parseRecord(line, 5));

        employee_count = employee_count + 1;
    }
    file.close();
}

string parseRecord(string record, int field) // Making function comma seprated
{
    int commaCount = 1;
    string item;
    fstream userload;

    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}


string isstring(string givingtocheck) //checkig if input is string else take input again
{
    cin.clear();
    cin.sync();
    getline(cin >> ws, givingtocheck);
    bool checking;
    int check;
    while (true)
    {
        int size = givingtocheck.length();
        for (int i = 0; i < size; i++)
        {
            check = givingtocheck[i];
            if ((check >= 65 && check <= 90) || (check >= 97 && check <= 122) || givingtocheck[i] == ' ')
            {
                checking = true;
            }
            else
            {
                checking = false;
                break;
            }
        }
        if (checking == 1)
        {
            return givingtocheck;
        }
        else
        {
            if(givingtocheck=="0")
            {
                return "";
            }
            cout << "Enter correct input: ";
            cin.clear();
            cin.sync();
            getline(cin >> ws, givingtocheck);
        }
    }
}
