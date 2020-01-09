#include<bits/stdc++.h>
using namespace std;

int main(){
    int choice;
    cout << "Choices :\nTo Encrypt : 1\nTo Decrypt : 2\nYour Choice : ";
    cin >> choice;
    string blank;
    if(choice == 1){
        string input_text;
        cout << "Enter text to encrypt\n";
        getline(cin,blank);
        getline(cin, input_text);
        int input_length = input_text.length();
        bitset <8> input_text_to_bits[input_length];
        int itr;
        for(itr = 0; itr<input_length; itr++)
            input_text_to_bits[itr] = input_text[itr];
        // for(itr = 0; itr<input_length; itr++)
        //     cout << input_text_to_bits[itr] << "\n";
        string symmetric_key;
        cout << "Enter a key to encrypt your message\n";
        getline(cin, symmetric_key);
        int key_length = symmetric_key.length(), temp;
        while(key_length < input_length){
            symmetric_key = symmetric_key.append(symmetric_key);
            key_length = symmetric_key.length();
        }
        // cout << symmetric_key;
        bitset <8> input_key_to_bits[key_length];
        for(itr = 0; itr < key_length; itr++)
            input_key_to_bits[itr] = symmetric_key[itr];
        bitset <8> cipher_bits[input_length];
        for(itr = 0; itr<input_length; itr++)
            cipher_bits[itr] = input_text_to_bits[itr]^input_key_to_bits[itr];
        cout << "Save this cypher text message\n";
        for(itr = 0; itr<input_length; itr++){
            temp = (int)cipher_bits[itr].to_ulong();
            if(temp < 16) cout << 0;
            cout << hex << cipher_bits[itr].to_ulong();
        }
        cout << "\n";
    }

    else if(choice == 2){
        string cipher_text, str = "";
        cout << "Enter text to decrypt\n";
        getline(cin, blank);
        getline (cin, cipher_text);
        int cipher_length = cipher_text.length();
        int itr, temp;
        bitset <8> cipher_bits[cipher_length/2];
        for(itr = 0; itr<cipher_length; itr+=2){
            str = "";
            str.append(cipher_text.begin()+itr, cipher_text.begin()+itr+2);
            // cout << str << " ";
            temp = stoi(str, 0, 16);
            // cout << temp << " ";
            cipher_bits[itr/2] = temp;
        }
        string symmetric_key;
        cout << "Enter the key used to encrypt the message\n";
        getline(cin, symmetric_key);
        int key_length = symmetric_key.length();
        while(key_length < cipher_length/2){
            symmetric_key = symmetric_key.append(symmetric_key);
            key_length = symmetric_key.length();
        }
        // cout << symmetric_key;
        bitset <8> input_key_to_bits[key_length];
        for(itr = 0; itr < key_length; itr++)
            input_key_to_bits[itr] = symmetric_key[itr];

        bitset <8> original_bits[cipher_length/2];
        for(itr = 0; itr<cipher_length/2; itr++)
            original_bits[itr] = cipher_bits[itr]^input_key_to_bits[itr];
        cout << "The secret message for you was\n";
        for(itr = 0; itr<cipher_length/2; itr++)
            cout << char(original_bits[itr].to_ulong());
        cout << "\n";
    }
}