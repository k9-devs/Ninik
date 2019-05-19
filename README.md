# Ninik

<p align="center">
  <img src="https://raw.githubusercontent.com/k9-devs/Ninik/master/graphics/exported_logo_3.png" height="250" width="200" alt="Ninik logo">
</p>
<br/>
<p>
  <h2 align="center">Ninik is a CLI based password manager</h2>
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/k9-devs/Ninik/master/graphics/uiUpdate3.PNG" alt="Screenshot">
</p>
  
## Download the Latest Release here: https://github.com/k9-devs/Ninik/releases

## Technologies used
* C Language
* Batch scripting language

## Setting up stuff
* The main.c file is being developed in Dev-C++ using compilers TDM-GCC and MinGW.
<br>Here are some of the links: Dev-C++ (https://sourceforge.net/projects/orwelldevcpp/) , TDM-GCC (http://tdm-gcc.tdragon.net/) and MinGW (http://www.mingw.org/).
* The file en_pass.txt is mandatory to have and needs to be in the same directory as of main.c
* If en_pass.txt is not there, write_pass_to_file() can be called from main. It'll create the file with the default master password.
* DEFAULT MASTER PASSWORD IS: Ninik
* Master Password can be changed once there is a successful entry in the main menu.

## About encryption/decryption algos
* Plain .txt files store the entry name along with passwords in encrypted form. Encryption algorithm can be changed as well (Recommended).
* All the passwords must be encrypted with the same algo in order to retrieve them again.

## Terminologies and Other Notes:
* Master Password: Master password grants access to the Main Menu. 
* Passwords are stored in a different form after going through an algo.
* Passwords are stored as
      <br>TitleName Pass(\n)
      <br>TitleName Pass(\n)
      <br>EOF
  <br> See here https://raw.githubusercontent.com/k9-devs/Ninik/master/graphics/pass_txt.PNG
* Algorithm encrypting and decrypting any password is pretty simple right now. One can implement its own algo to change the storage form of passwords.

## How To Contribute
Open a pull request with proper comments. For any discussion or query, open an issue. You can also message me through Twitter to get in touch twitter.com/mbhups
