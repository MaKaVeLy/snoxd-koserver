#pragma once

#include "crc32.h"

class CJvCryption
{
private:
	uint64 m_public_key, m_tkey;

public:
	CJvCryption() : m_public_key(0) {}

	__forceinline uint64 GetPublicKey() { return m_public_key; }
	uint64 GenerateKey();

	void Init();

	void JvEncryptionFast(int len, uint8 *datain, uint8 *dataout);
	__forceinline void JvDecryptionFast(int len, uint8 *datain, uint8 *dataout) { JvEncryptionFast(len, datain, dataout); };
	
	int JvDecryptionWithCRC32(int len, uint8 *datain, uint8 *dataout);
};