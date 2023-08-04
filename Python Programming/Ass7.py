contacts = {}


def menu():
    print("Operations: ")
    print("0. Menu")
    print("1. Add Contact")
    print("2. Add to existing Contact")
    print("3. Delete Contact")
    print("4. Update Contact")
    print("5. List Contacts")
    print("6. Exit Application\n")


def addContact(name, type, no):
    contact = {}
    contact[type] = no
    contacts[name] = contact


def delContact(name):
    contacts.pop(name)


def srcContact(name):
    if(contacts.get(name) == None):
        return 0
    else:
        return 1


def validNum(no):
    if len(no) == 10:
        return True
    return False


def listContacts():
    for i in contacts:
        print(f"{i} -> {contacts[i]}")


def getType(name):
    type = []
    for i in contacts[name]:
        type.append(i)
    return type


menu()
while(1):
    name = ""
    no = 0
    ch = int(input("Enter the operation: "))
    if(ch == 0):
        menu()
    elif(ch == 1):
        name = input("Enter the name of the contact: ")
        if(srcContact(name) != None):
            no = input("Enter the contact number: ")
            type = input("Enter category: ")
            if(validNum(no)):
                addContact(name, type, no)
                print("Contact Added successfully")
                print("\n")
            else:
                print("Invalid Number!")
                print("\n")
        else:
            print(
                f"A contact with name - '{name}', already exists. Try updating it.")
    elif(ch == 2):
        name = input("Enter the name of the contact: ")
        if(srcContact(name)):
            type = getType(name)
            no = input(f"Enter the contact number: ")
            t = input("Enter the category: ")
            contacts[name][t] = no
            print("Contact Updated!")
            print("\n")
        else:
            print("Contact not found!")
            print("\n")
    elif(ch == 3):
        name = input("Enter the name of the contact: ")
        if(srcContact(name)):
            delContact(name)
            print("Contact Deleted successfully")
            print("\n")
        else:
            print("Contact not found!")
            print("\n")
    elif(ch == 4):
        name = input("Enter the name of the contact: ")
        if(srcContact(name)):
            type = getType(name)
            no = input(f"Enter the contact number: ")
            t = input("Enter the category: ")
            contacts[name][t] = no
            print("Contact Updated!")
            print("\n")
        else:
            print("Contact not found!")
            print("\n")
    elif(ch == 5):
        print("Contacts:")
        listContacts()
        print("\n")
    elif(ch == 6):
        exit()
    else:
        print("Invalid Input!")
