#include<bits/stdc++.h>
using namespace std;

class Blogs {
    public:
    void enter() {
    cout << "Welcome you in Personal Blog Application" << endl;
    cout << "Who you are?" << endl;
    cout << "1.Admin" << endl;
    cout << "2.Users" << endl;
    cout << "3.Exit" << endl;
    int option;
    cout << "Choose Option : ";
    cin >> option;

    while (option != 1 && option != 2 && option != 3) {
        cout << "Choose valid Option!" << endl;
        cout << "Choose Option : ";
        cin >> option;
    }

    if (option == 1 || option == 2) {
        switch (option) {
        case 1:
            adminLogin();
            break;
        case 2:
            Account();
            break;
        }
    } else if (option == 3) {
        // Exit the program
        cout << "Exiting the program. Goodbye!" << endl;
        exit(0);
    }
}

    string adminId, adminPass;
    void adminLogin() {
        string adminLoginId, adminLoginPass;
        // cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"-------Welcome to Admin page-------"<<endl;
        cout<<"----------Verify yourself----------"<<endl;
        cout<<"Admin Id : ";
        cin>>adminLoginId;
        cout<<"Password : ";
        cin>>adminLoginPass;
        cout<<"-------Welcome to Admin Dashboard-------"<<endl;
    }

    string firstName, lastName, emailId, userName, password, confirmPassword;
    void Account() {
        int options;
        cout<<"-------Account Section-------"<<endl;
        cout<<"1.CreateAccount"<<endl;
        cout<<"2.Login"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Choose option : ";
        cin>>options;
        while(options!=1 || options!=2 || options!=3) {
            if(options==1 || options==2) {
                switch (options) {
                    case 1: CreateAccount();
                        break;
                    case 2: Login();
                        break;
                }
            } else if(options==3){
                enter();
            } else {
                cout<<"Choose valid Option!"<<endl;
                cout<<"Choose Option : ";
                cin>>options;
            }
        }
        
    }
    void CreateAccount() {
        cout<<"First Name       : ";
        cin>>firstName;
        cout<<"Last Name        : ";
        cin>>lastName;
        cout<<"Email Id         : ";
        cin>>emailId;
        cout<<"Username         : ";
        cin>>userName;
        cout<<"Password must contain 8 character including Capital letter, Small letter, Digits and Special Character!"<<endl;
        cout<<"Password         : ";
        cin>>password;
        while(true) {
            if(checkPass(password)) {
                break;
            } else {
                cout<<"Invalid pas"<<endl;
                cout<<"Password         : ";
                cin>>password;
            }
        }
        cout<<"Confirm Password : ";
        cin>>confirmPassword;
        while (true) {
            if(password==confirmPassword) {
                break;
            } else {
                cout<<"Confirm Password must be same as Password!"<<endl;
                cout<<"Confirm Password : ";
                cin>>confirmPassword;
            }
        }
        cout<<">>>Congratulations! your account successfully created."<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"-------Now, You can log in-------"<<endl;
        cout<<"1.Login"<<endl;
        cout<<"2.Back"<<endl;
        int option;
        cout<<"choose option : ";
        cin>>option;
            switch (option) {
            case 1: Login();
                break;
            case 2: Account();
                break;
            }
    }
    
    int checkPass(string password) {
        bool lower=false;
        bool upper=false;
        bool special=false;
        bool digit=false;
        for(char ch : password) {
            if(isupper(ch)) {
                upper=true;
            } else if(islower(ch)) {
                lower=true;
            } else if(isdigit(ch)) {
                digit=true;
            } else {
                special=true;
            } 
        }
        if(lower&&upper&&digit&&special) {
            // cout<<"Correct Password!"<<endl;
            return true;
        } else {
            return false;
        }
    }

    void Login() {
        string user, pass;
        cout<<"Login by Username and Password!"<<endl;
        cout<<"Username : ";
        cin>>user;
        cout<<"Password : ";
        cin>>pass;
        while(true) {
            if(user==userName && pass==password) {
                selectOption();
            } else {
                cout<<"Invalid Username and Password!"<<endl;
                cout<<"Username : ";
                cin>>user;
                cout<<"Password : ";
                cin>>pass;
            }
        }
    }

    string writeBlog;
    void selectOption() {
        int option;
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<">>>Select what you want to do!"<<endl;
        cout<<"1.Create New Blogs"<<endl;
        cout<<"2.Edit Blogs"<<endl;
        cout<<"3.Published New Blogs"<<endl;
        cout<<"4.Draft"<<endl;
        cout<<"5.See Blogs"<<endl;
        cout<<"6.Log Out"<<endl;
        cout<<"Choose Option : ";
        cin>>option;

            switch(option) {
            case 1: create();
                break;
            case 2: edit();
                break;
            case 3: published();
                break;
            case 4: draft();
                break;
            case 5: otherBlogs();
                break;
            case 6: logOut();
                break;
            }
    }
    void create() {
        cout<<">>>Write What you want?"<<endl;
        cout<<">";
        cin>>writeBlog;
        cout<<"Next Step!"<<endl;
        cout<<"1.Publish this blog"<<endl;
        cout<<"2.Save as Draft"<<endl;
        int option;
        cout<<"Choose Option : ";
        cin>>option;
        while (true) {
            if(option==1 || option==2) {
                switch (option) {
                case 1: published();
                    break;
                case 2: draft();
                    break;
                }
            } else {
                cout<<"Choose valid Option!"<<endl;
                cout<<"Choose Option : ";
                cin>>option;
            }
        }
    }
    void edit() {
        cout<<">>>You can edit your blogs!"<<endl;
        cout<<writeBlog<<endl;
        string modify;
        cout<<">>>You can add more according to yourself!"<<endl;
        cout<<">";
        cout<<"Enter Text : ";
        cin>>modify;
        cout<<"This is your updated Blog"<<endl;
        writeBlog.append(modify);
        selectOption();
    }
    void published() {
        cout<<">>>Successful published your Blog!"<<endl;
        cout<<">"<<writeBlog<<endl;
        // writeBlog = "";
        selectOption();
    }
    void draft() {
        cout<<">>>Your Saved Blogs!"<<endl;
        cout<<">"<<writeBlog<<endl;
        // writeBlog = "";
        cout<<"Would you want to Publish it!"<<endl;
        string choose;
        cout<<"yes or no? : ";
        cin>>choose;
        if(choose=="yes") {
            published();
        } else {
            selectOption();
        }
    }
    void otherBlogs() {
        cout<<">>>Welcome to Personal blogs"<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<">"<<writeBlog<<endl;
        cout<<endl;
        cout<<"Comments : ";
        selectOption();
    }
    void logOut() {
        Account();
    }
};

int main() {
    Blogs b;
    b.enter();
    //cout<<"-----------------------------------------------------------------------"<<endl;
    
    return 0;
}
//Error-how to retrieve the first interface from Account.