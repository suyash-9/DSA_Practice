def encrypt(text,s):
    result = ""
 

    for i in range(len(text)):
        char = text[i]
 
        if((ord(char)>=65 and ord(char)<=90) or (ord(char)>=97 and ord(char)<=122)):
          if (char.isupper()):
              result += chr((ord(char) + s-65) % 26 + 65)
  
        
          else:
              result += chr((ord(char) + s - 97) % 26 + 97)
        else:
          result+=text[i]
    return result
 

text = input()
s = (len(text)%20)+3
print ("Text  : " + text)
print ("Shift : " + str(s))
print ("Cipher: " + encrypt(text,26-s))