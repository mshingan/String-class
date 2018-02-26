
#include "String.h"
#include "OutOfBoundsException.h"
#include <iostream>

String::String() noexcept(false)
{
    len = 0;
    letters = new char[1];
    letters[0] = '\0';
    
}

String ::String(const char* chars)noexcept(false)
{
    int n =0;
    while(chars[n] != '\0'){
        n++;
    }
    letters = new char[n+1];
    len = n;
    for(int i =0; i<n; i++){
        letters [i] = chars[i];
    }
    letters[len] = '\0';
    
}

String::String(const String& s) noexcept(false)
{
    len= s.length();
    //std::cout<<len<<std::endl;
    letters = new char[len+1];
    for(int i = 0; i<len; i++){
        letters[i] = s.letters[i];
    }
    letters[len] = '\0';
}

String::~String() noexcept
{
    delete[] letters;
}


String& String:: operator=(const String& s) noexcept(false)
{
    if(this != &s){
        delete[] letters;
        this ->letters = new char[s.length()+1];
        len = s.length();
        //delete[] letters;
        //letters = newLetters;
        for(int i = 0; i<len; i++){
            this ->letters[i] = s.letters[i];
        }
        this ->letters[len] = '\0';
        //delete[] letters;
        //letters=newLetters;
        //letters[len] = '\0';
    }
    //letters[len] = '\0';
    
    return *this;
}

void String::append(const String& s){
    int newSize = len+s.length();
    char* temp = new char[newSize+1];
    int count =0;
    
    
    for(int i =0 ; i< len; i++,count++){
        temp[i]  = letters[i];
    }
    
    //std::cout<<temp<<std::endl;
    for(int i= 0; i< s.length(); i++){
        temp[count] = s.letters[i];
        //std::cout<<s.letters[i]<<std::endl;
        count++;
        
    }
    //std::cout<<temp<<std::endl;
    temp[newSize] = '\0';
    
    //std::cout << temp <<std::endl;
    
    delete[] letters;
    
    //letters = new char[newSize];
    letters = temp;
    //std::cout<<letters<<std::endl;
    len = newSize;
    
}

char String::at(unsigned int index) const
{
    if(index>len-1){
        throw OutOfBoundsException{};
    }
    //else{
    //len = len-1;
    return letters[index];
    //}
}

char& String::at(unsigned int index){
    if(index>len-1){
        throw OutOfBoundsException{};
    }
    
    return letters[index];
    //   }
}


void String::clear(){
    len = 0;
    letters = new char[1];
    letters[0] = '\0';
    
}

int String::compareTo(const String& s) const noexcept
{
    /*  int val =0;
     //if(s.length() == len){
     for(int i = 0; i<len; i++){
     if(letters[i] == s.letters[i]){
     val =0;
     }
     else{
     val=1;
     }*/
    
    int i =0 ;
    int value =0;
    if(letters == nullptr){
        return 0;
    }
    while(letters[i] != '\0' && s.letters[i] != '\0'){
        if(letters[i]- s.letters[i] ==0){
            value = 0;
        }
        else if(letters[i]<s.letters[i]){
            return -1;
        }
        else if(letters[i]> s.letters[i]){
            return 1;
        }
        i++;
        
    }
    return value;
}

String String::concatenate(const String &s) const{
    String my_string;
    int newSize =len+s.length();
    my_string.len = len + s.length();
    my_string.letters = new char[newSize+1];
    for(int i =0; i<len; i++){
        my_string.letters[i] = letters[i];
    }
    //delete[] letters;
    for(int i =0; i< s.length(); i++){
        my_string.letters[i+len] = s.letters[i];
    }
    //delete[] letters;
    my_string.letters[my_string.len] = '\0';
    //len = newSize;
    
    return my_string;
}

bool String::contains(const String& substring) const noexcept{
    //his -> letters;
    if(this ->find(substring) >=0){
        return true;
    }
    return false;
    
}

bool String::equals(const String& s) const noexcept
{
    if( s.length() != len ){
        return false;
    }
    else{
        for(int i=0; i<s.length(); i++){
            if(s.letters[i] != letters[i]){
                return false;
            }
        }
        
    }
    return true;
}

int String::find(const String& substring) const noexcept{
    if(substring.length()> len){
        return -1;
    }
    for(int i=0; i<len; i++){
        for(int j =0; j<substring.length();j++){
            std::cout<<letters[i+j]<<' '<<i+j<<' '<<substring.letters[j]<<' '<<j<<std::endl;
            if(letters[i +j]!= substring.letters[j]){
                break;
            }
            else if(substring.length()-1 == j){
                return i;
            }
            }
            
            }
            return -1;
            
            }
            
            bool String::isEmpty() const noexcept{
                if(len == 0){
                    return true;
                }
                
                return false;
            }
            
            unsigned int String:: length() const noexcept
            {
                return len;
            }
            
            
            String String::substring(unsigned int startIndex, unsigned int endIndex) const
            {
                if((endIndex > len) || (startIndex > endIndex)){
                    throw OutOfBoundsException{};
                }
                else{
                    String s;
                    s.letters = new char[endIndex- startIndex +1];
                    s.len = endIndex-startIndex;
                    for(int i= startIndex; i<=endIndex; i++){
                        s.letters[i-startIndex] = letters[i];
                    }
                    s.letters[s.len] = '\0';
                    //delete[] letters;
                    return s;
                }
            }
            
            const char* String:: toChars() const noexcept{
                //std::cout<<"Return letters using to char"<<letters[10]<<std::endl;
                if(letters == nullptr){
                    return "";
                }
                //std::cout<<letters<<std::endl;
                return letters;
            }
            
            
            
