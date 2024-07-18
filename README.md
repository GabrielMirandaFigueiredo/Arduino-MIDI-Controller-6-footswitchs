# Arduino-MIDI-Controller-6-footswitchs
I built an Arduino MIDI controller with 6 footswitchs for my Line 6 HX Stomp. I used an arduino uno fot this project, but a smaller arduino is better for fitting into the enclosure. 

VERSION 1
The version 1 send the following MIDICC informations: Button1 - MIDICC69 Value:0; Button2- MIDICC69 Value:1; Button3 - MIDICC69 Value:2; Button4 - MIDICC52 Value:0-127; Button5 - MIDICC53 Value:0-127; button6 - MIDICC16 Value:0-127. The buttons 1, 2 and 3 controls the hx stomp snapshots. The buttons 4 and 5 simulate FS4 and FS5. The button 6 send the MIDICC16 information.

VERSION 2 (With two pages)
The version 2 have two pages. The button 6 alternate between the 2 pages.
Page 1
Button1 - MIDICC69 Value:0; 
Button2- MIDICC69 Value:1; 
Button3 - MIDICC69 Value:2; 
Button4 - MIDICC52 Value:0-127; 
Button5 - MIDICC53 Value:0-127;  
The buttons 1, 2 and 3 controls the hx stomp snapshots. The buttons 4 and 5 simulate FS4 and FS5.

Page 2
Button1 - MIDICC82 Value:0-127; 
Button2- MIDICC83 Value:0-127; 
Button3 - MIDICC84 Value:0-127;
Button4 - MIDICC85 Value:0-127; 
Button5 - MIDICC86 Value:0-127.
In this version you can use the page 1 as snapshots and assign the fs4 and fs5 to control preset down and preset up. On page 2, you can assign the effects blocks to each buttons and use as a stomp mode.

VERSION 2.1
A bug that caused the display to not work if the Arduino was left without power for hours has been fixed. The code, for the messages shown on the display, have been updated from string to char.
![IMG_0562](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/25f25815-e665-4705-a992-d5f77de4dd66)
![IMG_0556](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/d6535ae7-4707-4a1d-868b-f393bae023ca)
![IMG_0547](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/7ccceae0-3547-43ce-92f4-9839a68f4740)
![WhatsApp Image 2024-06-29 at 21 36 36](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/6dcd9282-fbfe-49fe-a2bf-5e716088e672)
![WhatsApp Image 2024-06-29 at 21 36 36 (1)](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/ed175674-bd6c-4ddc-9098-25d5f7571f75)
![WhatsApp Image 2024-06-29 at 21 36 38 (1)](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/416a504c-92a3-4651-8b04-15f86d02cdf4)
![image](https://github.com/user-attachments/assets/254efe5c-ea7f-4722-9eca-11557674c76c)
