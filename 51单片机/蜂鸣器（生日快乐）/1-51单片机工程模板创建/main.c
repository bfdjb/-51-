#include <reg52.h>

sbit buzzer = P2^5; // ???????
unsigned int current_tone; // ????????????

// ????????????(12MHz??)
code unsigned int tone[] = {
    0xF8E6, // G4 (392Hz)
    0xF8F4, // A4 (440Hz)
    0xF9B6, // C5 (523Hz)
    0xF985, // B4 (494Hz)
    0xFA14, // D5 (587Hz)
    0xFA66, // E5 (659Hz)
    0xFB03, // G5 (784Hz)
    0xFAC8  // F5 (698Hz)
};

// ??????????
code unsigned char music_notes[] = {
    0, 0, 1, 0, 2, 3,  // ???
    0, 0, 1, 0, 4, 5,  // ???
    0, 0, 6, 5, 2, 3, 1, // ???
    7, 7, 5, 2, 4, 2    // ???
};

// ????????
code unsigned char music_beats[] = {
    1,1,2,2,2,3,
    1,1,2,2,2,3,
    1,1,2,2,2,2,2,
    2,2,2,2,2,3
};

unsigned int note_duration = 300; // ????(ms)

void timer0_init() {
    TMOD |= 0x01;   // Timer0??1
    ET0 = 1;        // ?????0??
    EA = 1;         // ?????
}

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 123; j++);
}

void main() {
    unsigned char i;
    timer0_init();
    buzzer = 0;
    
    while(1) {
        for(i = 0; i < sizeof(music_notes); i++) {
            current_tone = tone[music_notes[i]];
            TH0 = current_tone >> 8;
            TL0 = current_tone & 0xFF;
            TR0 = 1; // ?????
            delay_ms(note_duration * music_beats[i]);
            TR0 = 0; // ?????
            delay_ms(30); // ???????
        }
        delay_ms(2000); // ?????2???
    }
}

// ?????????
void timer0_isr() interrupt 1 {
    TH0 = current_tone >> 8;
    TL0 = current_tone & 0xFF;
    buzzer = ~buzzer; // ???????
}