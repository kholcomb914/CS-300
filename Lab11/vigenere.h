/**
 * @file vigenere.h
 * @author Kaustubh Holcomb (holcombk@uab.edu)
 * @brief Prototype for the Vignere class.
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef vigenere_h
#define vigenere_h

#include <iostream>
#include <string> 

/**
 * @brief Class is used to encrypt and decrypt messages.
 * 
 */
class Vigenere 
{
public:
    /**
     * @brief Construct a new Vigenere object.
     * 
     * @param key Contains the three-character key used to encrypt and decrypt messages (assumed to be uppercase).
     */
    Vigenere(std::string key);
    
    /**
     * @brief Destroy the Vigenere object.
     * 
     */
    ~Vigenere();

    /**
     * @brief Array of uppercase letters used for decryption and encryption.
     * 
     */
    const std::vector<char> letters = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    /**
     * @brief Uses the key to return an encrypted message.
     * 
     * @param msg Message to encrypt.
     * @return std::string
     */
    std::string encrypt(std::string msg);

    /**
     * @brief Uses the key to decrypt an encoded message.
     * 
     * @param msg Message to decrypt.
     * @return std::string 
     */
    std::string decrypt(std::string msg);

    /**
     * @brief Checks if a message is properly encrypted/decrypted, by decrypting the encrypted message and comparing to the decrypted message in the parameters.
     * 
     * @param encryptedMsg Given encrypted message.
     * @param decryptedMsg Given decrypted message.
     * @return true 
     * @return false 
     */
    bool isEncrypted(std::string encryptedMsg, std::string decryptedMsg);

    /**
     * @brief Set the Key used to decrypt/encrypt messages.
     * 
     * @param cKey String object that is used to set the key.
     */
    void setKey(std::string cKey);

    /**
     * @brief Get the Key object
     * 
     * @return std::string 
     */
    std::string getKey();
private:
    /**
     * @brief Key that the class uses to decrypt messages.
     * 
     */
    std::string key;
};

#endif /* vigenere_h */