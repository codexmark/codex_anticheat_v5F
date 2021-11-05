// Video tutorial: http://www.youtube.com/user/vertexbrasil
#pragma once
typedef struct {
	unsigned long dwAddress;
	unsigned char pBytes[8];
} MDump;
bool MCheckDump(void);