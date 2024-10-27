.data
    info:    .asciiz "Hello world!!"

    CONTROL: .word32 0x10000
    DATA:    .word32 0x10008

.text
    main:
        lwu r8,DATA(r0)
        lwu r9,CONTROL(r0)

        daddi r10,r0,4
        daddi r11,r0,info
        sd r11,0(r8)
        sd r10,0(r9)

    halt