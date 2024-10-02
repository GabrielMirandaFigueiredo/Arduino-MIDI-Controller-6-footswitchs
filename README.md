# Arduino-MIDI-Controller-6-footswitchs
##English

I built an Arduino MIDI controller with 6 footswitchs for my Line 6 HX Stomp. I used an arduino uno fot this project, but a smaller arduino is better for fitting into the enclosure. 

*VERSION 1*
The version 1 send the following MIDICC informations: Button1 - MIDICC69 Value:0; Button2- MIDICC69 Value:1; Button3 - MIDICC69 Value:2; Button4 - MIDICC52 Value:0-127; Button5 - MIDICC53 Value:0-127; button6 - MIDICC16 Value:0-127. The buttons 1, 2 and 3 controls the hx stomp snapshots. The buttons 4 and 5 simulate FS4 and FS5. The button 6 send the MIDICC16 information.

*VERSION 2* (With two pages)
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

*VERSION 2.1*
A bug that caused the display to not work if the Arduino was left without power for hours has been fixed. The code, for the messages shown on the display, have been updated from string to char.

##Português

Construí um controlador Arduino MIDI com 6 footswitchs para minha Line 6 HX Stomp. Usei um arduino uno para este projeto, porém, troquei por um arduino nano posteriormente.

*VERSÃO 1* 
A versão 1 envia as seguintes informações MIDICC: Button1 - MIDICC69 Valor:0; Botão2- MIDICC69 Valor:1; Botão3 - MIDICC69 Valor:2; Botão4 - MIDICC52 Valores:0-127; Botão5 - MIDICC53 Valores:0-127; botão6 - MIDICC16 Valores: 0-127. Os botões 1, 2 e 3 controlam os snapshots da hx stomp. Os botões 4 e 5 simulam FS4 e FS5. O botão 6 envia a informação MIDICC16.

*VERSÃO 2* (Com duas páginas) 
A versão 2 possui duas páginas.
Página 1
Botão1 - MIDICC69 Value:0; 
Botão2- MIDICC69 Value:1; 
Botão3 - MIDICC69 Value:2; 
Botão4 - MIDICC52 Value:0-127; 
Botão5 - MIDICC53 Value:0-127;  
Os botões 1, 2 e 3 controlam os snapshots. Os botões 4 e 5 simulam FS4 e FS5.

Página 2 
Botão1 - MIDICC82 Value:0-127; 
Botão2- MIDICC83 Value:0-127; 
Botão3 - MIDICC84 Value:0-127;
Botão4 - MIDICC85 Value:0-127; 
Botão5 - MIDICC86 Value:0-127.
Nesta versão você pode usar a página 1 como snapshots e atribuir o fs4 e o fs5 para controlar o preset down e o preset up. Na página 2, você pode atribuir os blocos de efeitos a cada botão e usá-los como modo stomp.

*VERSÃO 2.1* 
Foi corrigido um bug que fazia com que o display não funcionasse se o Arduino ficasse sem energia por horas. O código das mensagens mostradas no display foi atualizado de string para char.

Peças/Parts:

Display: https://pt.aliexpress.com/item/1005006018109299.html?spm=a2g0o.order_list.order_list_main.5.47aecaa4fplrT8&gatewayAdapt=glo2bra

Arduino: https://pt.aliexpress.com/item/32647196840.html?spm=a2g0o.order_list.order_list_main.10.47aecaa4fplrT8&gatewayAdapt=glo2bra

Box/caixa: https://pt.aliexpress.com/item/1005005612909691.html?spm=a2g0o.detail.pcDetailTopMoreOtherSeller.2.16b9FQAQFQAQMJ&gps-id=pcDetailTopMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=3c7cd42f-e045-445f-b999-fd52377ea08c&_t=gps-id:pcDetailTopMoreOtherSeller,scm-url:1007.40050.354490.0,pvid:3c7cd42f-e045-445f-b999-fd52377ea08c,tpp_buckets:668%232846%238115%232000&utparam-url=scene%3ApcDetailTopMoreOtherSeller%7Cquery_from%3A

Wires/Fios: https://pt.aliexpress.com/item/1005004167126040.html?spm=a2g0o.order_list.order_list_main.55.47aecaa4fplrT8&gatewayAdapt=glo2bra

Jack MIDI: https://pt.aliexpress.com/item/4000583940302.html?spm=a2g0o.order_list.order_list_main.80.47aecaa4fplrT8&gatewayAdapt=glo2bra

Footswitchs: https://pt.aliexpress.com/item/1005006163316744.html?spm=a2g0o.order_list.order_list_main.100.47aecaa4fplrT8&gatewayAdapt=glo2bra

DC Jack: https://pt.aliexpress.com/item/1005003688672124.html?spm=a2g0o.productlist.main.1.54a25e19Bfviuw&algo_pvid=fb2543c1-4ce1-4a58-8e75-69ea1c39653e&utparam-url=scene%3Asearch%7Cquery_from%3A

![IMG_0562](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/25f25815-e665-4705-a992-d5f77de4dd66)
![IMG_0556](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/d6535ae7-4707-4a1d-868b-f393bae023ca)
![IMG_0547](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/7ccceae0-3547-43ce-92f4-9839a68f4740)
![WhatsApp Image 2024-06-29 at 21 36 36](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/6dcd9282-fbfe-49fe-a2bf-5e716088e672)
![WhatsApp Image 2024-06-29 at 21 36 36 (1)](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/ed175674-bd6c-4ddc-9098-25d5f7571f75)
![WhatsApp Image 2024-06-29 at 21 36 38 (1)](https://github.com/GabrielMirandaFigueiredo/Arduino-MIDI-Controller-6-footswitchs/assets/174227068/416a504c-92a3-4651-8b04-15f86d02cdf4)
![image](https://github.com/user-attachments/assets/254efe5c-ea7f-4722-9eca-11557674c76c)
