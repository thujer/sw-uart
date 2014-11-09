// +----------------------------------------------------------------+ //
// |                 Ovladac softwarove komunikace                  | //
// |     (c)2003-2006 ELITRONIC s.r.o. by K.L.soft & Thomas Hudger  | //
// |  SW_UART_DRV.H. Zapocato 12.01.05 Posledni aktualizace 08.08.06   | //
// +----------------------------------------------------------------+ //

#ifndef __SW_UART__
    #define __SW_UART__

    #define uchar unsigned char

    void sw_uart_init();            // init bufferu, pinu a priznaku komunikace
    char sw_uart(char ch);          // vystup znaku na sw_uart, funkce kompaktibilni s putch, lze pouzit v presmerovani vystupu stdout_printf(sw_uart,"xxx");
    char sw_uart_getchar();         // nacte z bufferu znak, pokud je buffer prazdny, vraci 0
    void sw_uart_proc();            // odesila znaky z vysilaciho bufferu
    void sw_uart_rxbit();
    void sw_uart_txbit();

    extern char sw_uart_rec_in;     // pocet znaku v prijimacim bufferu
    extern char sw_uart_snd_in;     // pocet znaku ve vysilacim bufferu

#endif

// +----------------------------------------------------------------+ //
