email = input("Enter your email id: ")

at = email.find('@')

print(
    f"\nYour username is: '{email[0:at]}' and your domain is: '{email[at+1:]}'")
