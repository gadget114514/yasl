enum opcodes {
NOP       = 0x00, // pass
ICONST_M2 = 0x01, // puss -2 onto stack
ICONST_M1 = 0x02, // push -1 onto stack
ICONST_0  = 0x03, // push 0 onto stack
ICONST_1  = 0x04, // push 1 onto stack
ICONST_2  = 0x05, // push 2 onto stack
ICONST_3  = 0x06, // push 3 onto stack
ICONST_4  = 0x07, // push 4 onto stack
ICONST_5  = 0x08, // push 5 onto stack
ICONST_6  = 0x09, // push 6 onto stack
DCONST_M1 = 0x0A, // push -1.0 onto stack
DCONST_0  = 0x0B, // push 0.0 onto stack
DCONST_1  = 0x0C, // push 1.0 onto stack
DCONST_2  = 0x0D, // push 2.0 onto stack
ICONST    = 0x0E, // push next 8 bytes onto stack as integer constant
DCONST    = 0x0F, // push next 8 bytes onto st4ack as float constant
NCONST    = 0x20, // push literal nil onto stack
ISNIL     = 0x21, // check that top of stack is nil, returns true or false
BCONST_F  = 0x28, // push literal false onto stack
BCONST_T  = 0x29, // push literal true onto stack
MLC       = 0x50, // allocate memory
MCP_8     = 0x52, // copy from memory
DUP       = 0x58, // duplicate top value of stack
SWAP      = 0x59, // swap top two elements of the stack
POP       = 0x5C, // pop top of stack
ADD       = 0x60, // add two integers
SUB       = 0x61, // subtract two integers
MUL       = 0x62, // multiply two integers
DIV       = 0x64, // divide two integers
NEG       = 0x70, // negate an integer
NOT       = 0x71, // negate a boolean
GT        = 0x74, // greater than
GE        = 0x75, // greater than or equal
EQ        = 0x76, // equality
I2D       = 0x80, // integer to double
D2I       = 0x82, // double to integer
BR_1      = 0x90, // branch unconditionally (takes next 1 byte as jump length)
BR_2      = 0x91, // branch unconditionally (takes next 2 bytes as jump length)
BR_4      = 0x92, // branch unconditionally (takes next 4 bytes as jump length)
BR_8      = 0x93, // branch unconditionally (takes next 8 bytes as jump length)
BRF_1     = 0x94, // branch if condition is falsey (takes next 1 bytes as jump length)
BRF_2     = 0x95, // branch if condition is falsey (takes next 2 bytes as jump length)
BRF_4     = 0x96, // branch if condition is falsey (takes next 4 bytes as jump length)
BRF_8     = 0x97, // branch if condition is falsey (takes next 8 bytes as jump length)
BRT_1     = 0x98, // branch if condition is truthy (takes next 1 bytes as jump length)
BRT_2     = 0x99, // branch if condition is truthy (takes next 2 bytes as jump length)
BRT_4     = 0x9A, // branch if condition is truthy (takes next 4 bytes as jump length)
BRT_8     = 0x9B, // branch if condition is truthy (takes next 8 bytes as jump length)
HALT      = 0xF0, // halt
PRINT     = 0xF2, // print top of stack (temporary to allow debugging)
GSTORE_1  = 0xF4, // store top of stack at addr provided
LSTORE_1  = 0xF5, // store top of stack as local at addr
GLOAD_1   = 0xF6, // load global from addr
LLOAD_1   = 0xF7, // load local from addr
CALL_8    = 0xF8, // function call
RET       = 0xF9, // return from function
};