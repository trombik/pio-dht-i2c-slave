Import('env')
fusebits = {
        'attiny13': '-U lfuse:w:0x7a:m -U hfuse:w:0xff:m',
        'attiny85': '-U hfuse:w:0xdf:m -U lfuse:w:0xe2:m -U efuse:w:0xff:m'
        }
env.Replace(FUSESCMD="avrdude $UPLOADERFLAGS " + fusebits[env['BOARD']])
