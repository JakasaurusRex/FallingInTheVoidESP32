# Falling In The Void ESP32 🕳️🍂🎵
Art display created on the ESP32 with the theme "Fall". To learn more check out my blog post: [https://github.com/JakasaurusRex/CakeBlog](https://jakasaurusrex.github.io/CakeBlog/)

***

The ESP ino file can be found in the display folder and the header files for the images are in the headers folder!

**The final product!!**\
![compilation](https://github.com/user-attachments/assets/cff865c5-66ac-42ee-b49b-f6057763ecab)

## What is this? 🎨
As a class, we were tasked to create an art display with the ESP32 TTGO T-display with a common theme: **Fall**. The goal of my piece was to make viewers feel some peace while thinking about laying in a comfy bed closing your eyes and listening to music and letting yourself float away. 

Here are some of the tools and materials that I used to create the project and what you would need to replicate it:  
- ESP32 TTGO T-display + Lipo battery
- Envelope with cutout for display and yarn holes
- Yarn + Popsicle Stick to hang the display
- Arudino IDE
- Aespirite for the pixel art!


## How to Build!
1. Clone the repo!
```bash
git clone https://github.com/JakasaurusRex/FallingInTheVoidESP32.git
```
3. Open then .ino file in display folder in your Arudino IDE. Feel free to change out the images in the headers folder for whatever you like! 
4. Connect your ESP32 and battery up and upload the program to the ESP.
5. Put your ESP32 in your envelope and tie the yarn, envelope and posicle together
6. Display!


## How I made it! ⚙️✏️

First step in creating the piece was coming up with the design. After doing some design workshopping, I came up with my idea and started working on some pixel art for the character in my display! I recommend [AdamCYounis on YouTube](https://www.youtube.com/watch?v=59Y6OTzNrhk&t=45s&ab_channel=AdamCYounis) if you would like to learn how to use Aespirite!

After creating my pixel art I started at work on display I was drawing to the ESP screen. I used the [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI) library in order to display my sprites on the screen and move them around. In order to create the display I watched a bunch of tutorials from Volos Projects on YouTube, especially [this video](https://www.youtube.com/watch?v=U4jOFLFNZBI&ab_channel=VolosProjects) where he discusses how to have sprites with transparent backgrounds which I used to import my images I created in Aespirite. 

In order to create my funky display, first I drew the black background and the person sprite that was moving around. Then I pushed the person sprite onto itself multiple times to create the afterimages rotating around them. Then I updated the variables values that I used for rotation and movement and flash the music notes on the screen every couple seconds. 

After uploading the display onto the ESP, I then attached the battery to the device and taped them together and taped them into my envelope, which I colored black with music notes to match the display. Then I ran a piece of yarn through the envelope and tied it to a popsicle stick which we hung on the ceiling. Here is a picture of the envelope for reference!

![IMG_8525 =100x20](https://github.com/user-attachments/assets/43b45b57-20ef-4173-a7bc-2eb4713d1a58)
