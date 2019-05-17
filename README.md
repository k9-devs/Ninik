# Ninik

<p align="center">
  <img src="https://raw.githubusercontent.com/k9-devs/Ninik/master/graphics/exported_logo_3.png" height="250" width="200" alt="Ninik logo">
</p>
<br/>
<p>
  <h2 align="center">Ninik is a CLI based password manager</h2>
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/k9-devs/Ninik/master/graphics/main_UI_update.PNG" alt="Screenshot">
</p>
  
## Technologies used
* C Language
* Batch scripting language

## How To Set Up Everything
* The main.c file is being developed in Dev-C++ using compilers TDM-GCC and MinGW.
<br>Here are some links: Dev-C++ (https://sourceforge.net/projects/orwelldevcpp/) , TDM-GCC (http://tdm-gcc.tdragon.net/) and MinGW (http://www.mingw.org/).
* The file en_pass.txt is mandatory to have and needs to be in the same directory as of main.c
* If en_pass.txt is not there, write_pass_to_file() can be called from main. It'll create the file with the default master password.
* DEFAULT MASTER PASSWORD IS: Ninik
* Master Password can be changed once there is a successful entry in the main menu.

## About encryption/decryption algos
* Plain .txt files stores the entry name along with passwords in manipulated form. Manipulation algorithm can be changed.
* Keep in mind, all the passwords must be manipulated with the same algo in order to retrieve them again.

## How To Contribute
Open a pull request with proper comments. For any discussion or query, open an issue. You can also message me through Twitter to get in touch twitter.com/mbhups
