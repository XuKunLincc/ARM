SECTIONS { 
  firtst  	0x00000000 : { start.o init.o nand.o}
  second 	0x30000000 : AT(4096) { main.o }
} 
 
