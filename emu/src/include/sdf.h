// Copyright (C) 2021 Institute of Data Security, HIT
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1)

#define SGD_SM4_GCM               0x02000400
#define SGD_SM4_CCM               0x04000400

/* block cipher modes */
#define SGD_ECB                   0x01
#define SGD_CBC                   0x02
#define SGD_CFB                   0x04
#define SGD_OFB                   0x08
#define SGD_MAC                   0x10
#define SGD_CTR                   0x20

/* stream cipher modes */
#define SGD_EEA3                  0x01
#define SGD_EIA3                  0x02

/* ciphers */
#define SGD_SM1                   0x00000100
#define SGD_SSF33                 0x00000200
#define SGD_SM4                   0x00000400
#define SGD_ZUC                   0x00000800
#define SGD_AES                   0x10000400
#define SGD_3DES                  0x10000800
/* ciphers with modes */
#define SGD_SM1_ECB               (SGD_SM1|SGD_ECB)
#define SGD_SM1_CBC               (SGD_SM1|SGD_CBC)
#define SGD_SM1_CFB               (SGD_SM1|SGD_CFB)
#define SGD_SM1_OFB               (SGD_SM1|SGD_OFB)
#define SGD_SM1_CTR               (SGD_SM1|SGD_CTR)
#define SGD_SM1_MAC               (SGD_SM1|SGD_MAC)
#define SGD_SSF33_ECB             (SGD_SSF33|SGD_ECB)
#define SGD_SSF33_CBC             (SGD_SSF33|SGD_CBC)
#define SGD_SSF33_CFB             (SGD_SSF33|SGD_CFB)
#define SGD_SSF33_OFB             (SGD_SSF33|SGD_OFB)
#define SGD_SSF33_MAC             (SGD_SSF33|SGD_MAC)
#define SGD_SM4_ECB               (SGD_SM4|SGD_ECB)
#define SGD_SM4_CBC               (SGD_SM4|SGD_CBC)
#define SGD_SM4_CFB               (SGD_SM4|SGD_CFB)
#define SGD_SM4_OFB               (SGD_SM4|SGD_OFB)
#define SGD_SM4_MAC               (SGD_SM4|SGD_MAC)
#define SGD_SM4_CTR               (SGD_SM4|SGD_CTR)
#define SGD_ZUC_EEA3              (SGD_ZUC|SGD_EEA3)
#define SGD_ZUC_EIA3              (SGD_ZUC|SGD_EIA3)

#define SGD_AES_ECB               (SGD_AES|SGD_ECB)
#define SGD_AES_CBC               (SGD_AES|SGD_CBC)
#define SGD_AES_CFB               (SGD_AES|SGD_CFB)
#define SGD_AES_OFB               (SGD_AES|SGD_OFB)

#define SGD_3DES_ECB              (SGD_3DES|SGD_ECB)
#define SGD_3DES_CBC              (SGD_3DES|SGD_CBC)
#define SGD_3DES_CFB              (SGD_3DES|SGD_CFB)
#define SGD_3DES_OFB              (SGD_3DES|SGD_OFB)


/* public key usage */
#define SGD_PK_SIGN               0x0100
#define SGD_PK_DH                 0x0200
#define SGD_PK_ENC                0x0400

/* public key types */
#define SGD_RSA                   0x00010000
#define SGD_RSA_SIGN              (SGD_RSA|SGD_PK_SIGN)
#define SGD_RSA_ENC               (SGD_RSA|SGD_PK_ENC)
#define SGD_SM2                   0x00020100
#define SGD_SM2_1                 0x00020200
#define SGD_SM2_2                 0x00020400
#define SGD_SM2_3                 0x00020800
#define SGD_SHA224                0x00000008 /* extended hash definition */
#define SGD_SHA384                0x00000010 /* extended hash definition */
#define SGD_SHA512                0x00000020 /* extended hash definition */
/* hash */
#define SGD_SM3                   0x00000001
#define SGD_SHA1                  0x00000002
#define SGD_SHA256                0x00000004

/* extended hmac */
#define SGD_SHA1_HMAC             0x00010012
#define SGD_SHA256_HMAC           0x00010014
#define SGD_SM3_HMAC              0x00020211


/************************************************************************/
/* error code definition                                                */
/************************************************************************/

#define SDR_OK                    0x0
#define SDR_BASE                  0x01000000
#define SDR_UNKNOWERR             (SDR_BASE + 0x00000001)
#define SDR_NOTSUPPORT            (SDR_BASE + 0x00000002)
#define SDR_COMMFAIL              (SDR_BASE + 0x00000003)
#define SDR_HARDFAIL              (SDR_BASE + 0x00000004)
#define SDR_OPENDEVICE            (SDR_BASE + 0x00000005)
#define SDR_OPENSESSION           (SDR_BASE + 0x00000006)
#define SDR_PARDENY               (SDR_BASE + 0x00000007)
#define SDR_KEYNOTEXIST           (SDR_BASE + 0x00000008)
#define SDR_ALGNOTSUPPORT         (SDR_BASE + 0x00000009)
#define SDR_ALGMODNOTSUPPORT      (SDR_BASE + 0x0000000A)
#define SDR_PKOPERR               (SDR_BASE + 0x0000000B)
#define SDR_SKOPERR               (SDR_BASE + 0x0000000C)
#define SDR_SIGNERR               (SDR_BASE + 0x0000000D)
#define SDR_VERIFYERR             (SDR_BASE + 0x0000000E)
#define SDR_SYMOPERR              (SDR_BASE + 0x0000000F)
#define SDR_STEPERR               (SDR_BASE + 0x00000010)
#define SDR_FILESIZEERR           (SDR_BASE + 0x00000011)
#define SDR_FILENOEXIST           (SDR_BASE + 0x00000012)
#define SDR_FILEOFSERR            (SDR_BASE + 0x00000013)
#define SDR_KEYTYPEERR            (SDR_BASE + 0x00000014)
#define SDR_KEYERR                (SDR_BASE + 0x00000015)
#define SDR_ENCDATAERR            (SDR_BASE + 0x00000016)
#define SDR_RANDERR               (SDR_BASE + 0x00000017)
#define SDR_PRKRERR               (SDR_BASE + 0x00000018)
#define SDR_MACERR                (SDR_BASE + 0x00000019)
#define SDR_FILEEXSITS            (SDR_BASE + 0x0000001A)
#define SDR_FILEWERR              (SDR_BASE + 0x0000001B)
#define SDR_NOBUFFER              (SDR_BASE + 0x0000001C)
#define SDR_INARGERR              (SDR_BASE + 0x0000001D)
#define SDR_OUTARGERR             (SDR_BASE + 0x0000001E)

// extended error code
#define SDR_NO_CONFIG             (SDR_BASE + 0x00000200)
#define SDR_CONFIG_BAD            (SDR_BASE + 0x00000201)
#define SDR_BUFFER_TOO_SHORT      (SDR_BASE + 0x00000202)

#define RSAref_MAX_BITS           2048
#define RSAref_MAX_LEN            ((RSAref_MAX_BITS + 7) / 8)
#define RSAref_MAX_PBITS          ((RSAref_MAX_BITS + 1) / 2)
#define RSAref_MAX_PLEN           ((RSAref_MAX_PBITS + 7)/ 8)

#ifdef SGD_MAX_ECC_BITS_256
#define ECCref_MAX_BITS           256
#else
#define ECCref_MAX_BITS           512
#endif
#define ECCref_MAX_LEN            ((ECCref_MAX_BITS+7) / 8)

typedef struct DeviceInfo_st {
    unsigned char IssuerName[40];
    unsigned char DeviceName[16];
    unsigned char DeviceSerial[16];    /* 8-char date +
					 * 3-char batch num +
					 * 5-char serial num
					 */
    unsigned int DeviceVersion;
    unsigned int StandardVersion;
    unsigned int AsymAlgAbility[2];    /* AsymAlgAbility[0] = algors
					 * AsymAlgAbility[1] = modulus lens
					 */
    unsigned int SymAlgAbility;
    unsigned int HashAlgAbility;
    unsigned int BufferSize;
} DEVICEINFO;

typedef struct RSArefPublicKey_st {
    unsigned int bits;
    unsigned char m[RSAref_MAX_LEN];
    unsigned char e[RSAref_MAX_LEN];
} RSArefPublicKey;

typedef struct RSArefPrivateKey_st {
    unsigned int bits;
    unsigned char m[RSAref_MAX_LEN];
    unsigned char e[RSAref_MAX_LEN];
    unsigned char d[RSAref_MAX_LEN];
    unsigned char prime[2][RSAref_MAX_PLEN];
    unsigned char pexp[2][RSAref_MAX_PLEN];
    unsigned char coef[RSAref_MAX_PLEN];
} RSArefPrivateKey;

typedef struct ECCrefPublicKey_st {
    unsigned int bits;
    unsigned char x[ECCref_MAX_LEN];
    unsigned char y[ECCref_MAX_LEN];
} ECCrefPublicKey;

typedef struct ECCrefPrivateKey_st {
    unsigned int bits;
    unsigned char K[ECCref_MAX_LEN];
} ECCrefPrivateKey;

typedef struct ECCCipher_st {
    unsigned char x[ECCref_MAX_LEN];
    unsigned char y[ECCref_MAX_LEN];
    unsigned char M[32];
    unsigned int L;
    unsigned char C[1];
} ECCCipher;

typedef struct ECCSignature_st {
    unsigned char r[ECCref_MAX_LEN];
    unsigned char s[ECCref_MAX_LEN];
} ECCSignature;

typedef struct SDF_ENVELOPEDKEYBLOB {
    unsigned long Version;
    unsigned long ulSymmAlgID;
    ECCCipher ECCCipehrBlob;
    ECCrefPublicKey PubKey;
    unsigned char cbEncryptedPrivKey[64];
} EnvelopedKeyBlob, *PEnvelopedKeyBlob;

#pragma pack()

int emu_init();

int emu_fini();

int SDF_OpenDevice(void **phDeviceHandle);

int SDF_CloseDevice(void *hDeviceHandle);

int SDF_OpenSession(void *hDeviceHandle, void **phSessionHandle);

int SDF_CloseSession(void *hSessionHandle);

int SDF_GetDeviceInfo(void *hSessionHandle, DEVICEINFO *pstDeviceInfo);

int SDF_GenerateRandom(void *hSessionHandle, unsigned int uiLength, unsigned char *pucRandom);

int SDF_GetPrivateKeyAccessRight(void *hSessionHandle,
                                 unsigned int uiKeyIndex,
                                 unsigned char *pucPassword,
                                 unsigned int uiPwdLength);

int SDF_ReleasePrivateKeyAccessRight(void *hSessionHandle, unsigned int uiKeyIndex);

int SDF_ExportSignPublicKey_RSA(void *hSessionHandle, unsigned int uiKeyIndex, RSArefPublicKey *pucPublicKey);

int SDF_ExportEncPublicKey_RSA(void *hSessionHandle, unsigned int uiKeyIndex, RSArefPublicKey *pucPublicKey);

int SDF_GenerateKeyPair_RSA(void *hSessionHandle,
                            unsigned int uiKeyBits,
                            RSArefPublicKey *pucPublicKey,
                            RSArefPrivateKey *pucPrivateKey);

int SDF_GenerateKeyWithIPK_RSA(void *hSessionHandle,
                               unsigned int uiIPKIndex,
                               unsigned int uiKeyBits,
                               unsigned char *pucKey,
                               unsigned int *puiKeyLength,
                               void **phKeyHandle);

int SDF_GenerateKeyWithEPK_RSA(void *hSessionHandle,
                               unsigned int uiKeyBits,
                               RSArefPublicKey *pucPublicKey,
                               unsigned char *pucKey,
                               unsigned int *puiKeyLength,
                               void **phKeyHandle);

int SDF_ImportKeyWithISK_RSA(void *hSessionHandle,
                             unsigned int uiISKIndex,
                             unsigned char *pucKey,
                             unsigned int uiKeyLength,
                             void **phKeyHandle);

int SDF_ExchangeDigitEnvelopeBaseOnRSA(void *hSessionHandle,
                                       unsigned int uiKeyIndex,
                                       RSArefPublicKey *pucPublicKey,
                                       unsigned char *pucDEInput,
                                       unsigned int uiDELength,
                                       unsigned char *pucDEOutput,
                                       unsigned int *puiDELength);

int SDF_ExportSignPublicKey_ECC(void *hSessionHandle, unsigned int uiKeyIndex, ECCrefPublicKey *pucPublicKey);

int SDF_ExportEncPublicKey_ECC(void *hSessionHandle, unsigned int uiKeyIndex, ECCrefPublicKey *pucPublicKey);

int SDF_GenerateKeyPair_ECC(void *hSessionHandle,
                            unsigned int uiAlgID,
                            unsigned int uiKeyBits,
                            ECCrefPublicKey *pucPublicKey,
                            ECCrefPrivateKey *pucPrivateKey);

int SDF_GenerateKeyWithIPK_ECC(void *hSessionHandle,
                               unsigned int uiIPKIndex,
                               unsigned int uiKeyBits,
                               ECCCipher *pucKey,
                               void **phKeyHandle);

int SDF_GenerateKeyWithEPK_ECC(void *hSessionHandle,
                               unsigned int uiKeyBits,
                               unsigned int uiAlgID,
                               ECCrefPublicKey *pucPublicKey,
                               ECCCipher *pucKey,
                               void **phKeyHandle);

int SDF_ImportKeyWithISK_ECC(void *hSessionHandle,
                             unsigned int uiISKIndex,
                             ECCCipher *pucKey,
                             void **phKeyHandle);

int SDF_GenerateAgreementDataWithECC(void *hSessionHandle,
                                     unsigned int uiISKIndex,
                                     unsigned int uiKeyBits,
                                     unsigned char *pucSponsorID,
                                     unsigned int uiSponsorIDLength,
                                     ECCrefPublicKey *pucSponsorPublicKey,
                                     ECCrefPublicKey *pucSponsorTmpPublicKey,
                                     void **phAgreementHandle);

int SDF_GenerateKeyWithECC(void *hSessionHandle,
                           unsigned char *pucResponseID,
                           unsigned int uiResponseIDLength,
                           ECCrefPublicKey *pucResponsePublicKey,
                           ECCrefPublicKey *pucResponseTmpPublicKey,
                           void *hAgreementHandle,
                           void **phKeyHandle);

int SDF_GenerateAgreementDataAndKeyWithECC(void *hSessionHandle,
                                           unsigned int uiISKIndex,
                                           unsigned int uiKeyBits,
                                           unsigned char *pucResponseID,
                                           unsigned int uiResponseIDLength,
                                           unsigned char *pucSponsorID,
                                           unsigned int uiSponsorIDLength,
                                           ECCrefPublicKey *pucSponsorPublicKey,
                                           ECCrefPublicKey *pucSponsorTmpPublicKey,
                                           ECCrefPublicKey *pucResponsePublicKey,
                                           ECCrefPublicKey *pucResponseTmpPublicKey,
                                           void **phKeyHandle);

int SDF_ExchangeDigitEnvelopeBaseOnECC(void *hSessionHandle,
                                       unsigned int uiKeyIndex,
                                       unsigned int uiAlgID,
                                       ECCrefPublicKey *pucPublicKey,
                                       ECCCipher *pucEncDataIn,
                                       ECCCipher *pucEncDataOut);

int SDF_GenerateKeyWithKEK(void *hSessionHandle,
                           unsigned int uiKeyBits,
                           unsigned int uiAlgID,
                           unsigned int uiKEKIndex,
                           unsigned char *pucKey,
                           unsigned int *puiKeyLength,
                           void **phKeyHandle);

int SDF_ImportKeyWithKEK(void *hSessionHandle,
                         unsigned int uiAlgID,
                         unsigned int uiKEKIndex,
                         unsigned char *pucKey,
                         unsigned int uiKeyLength,
                         void **phKeyHandle);

int SDF_ImportKey(void *hSessionHandle,
                  unsigned char *pucKey,
                  unsigned int uiKeyLength,
                  void **phKeyHandle);

int SDF_DestroyKey(void *hSessionHandle, void *hKeyHandle);

int SDF_ExternalPublicKeyOperation_RSA(void *hSessionHandle,
                                       RSArefPublicKey *pucPublicKey,
                                       unsigned char *pucDataInput,
                                       unsigned int uiInputLength,
                                       unsigned char *pucDataOutput,
                                       unsigned int *puiOutputLength);

int SDF_InternalPublicKeyOperation_RSA(void *hSessionHandle,
                                       unsigned int uiKeyIndex,
                                       unsigned char *pucDataInput,
                                       unsigned int uiInputLength,
                                       unsigned char *pucDataOutput,
                                       unsigned int *puiOutputLength);

int SDF_InternalPrivateKeyOperation_RSA(void *hSessionHandle,
                                        unsigned int uiKeyIndex,
                                        unsigned char *pucDataInput,
                                        unsigned int uiInputLength,
                                        unsigned char *pucDataOutput,
                                        unsigned int *puiOutputLength);

int SDF_ExternalPrivateKeyOperation_RSA(void *hSessionHandle,
                                        RSArefPrivateKey *pucPrivateKey,
                                        unsigned char *pucDataInput,
                                        unsigned int uiInputLength,
                                        unsigned char *pucDataOutput,
                                        unsigned int *puiOutputLength);

int SDF_ExternalSign_ECC(void *hSessionHandle,
                         unsigned int uiAlgID,
                         ECCrefPrivateKey *pucPrivateKey,
                         unsigned char *pucData,
                         unsigned int uiDataLength,
                         ECCSignature *pucSignature);

int SDF_ExternalVerify_ECC(void *hSessionHandle,
                           unsigned int uiAlgID,
                           ECCrefPublicKey *pucPublicKey,
                           unsigned char *pucDataInput,
                           unsigned int uiInputLength,
                           ECCSignature *pucSignature);

int SDF_InternalSign_ECC(void *hSessionHandle,
                         unsigned int uiISKIndex,
                         unsigned char *pucData,
                         unsigned int uiDataLength,
                         ECCSignature *pucSignature);

int SDF_InternalVerify_ECC(void *hSessionHandle,
                           unsigned int uiIPKIndex,
                           unsigned char *pucData,
                           unsigned int uiDataLength,
                           ECCSignature *pucSignature);

int SDF_ExternalEncrypt_ECC(void *hSessionHandle,
                            unsigned int uiAlgID,
                            ECCrefPublicKey *pucPublicKey,
                            unsigned char *pucData,
                            unsigned int uiDataLength,
                            ECCCipher *pucEncData);

int SDF_ExternalDecrypt_ECC(void *hSessionHandle,
                            unsigned int uiAlgID,
                            ECCrefPrivateKey *pucPrivateKey,
                            ECCCipher *pucEncData,
                            unsigned char *pucData,
                            unsigned int *puiDataLength);

int SDF_Encrypt(void *hSessionHandle,
                void *hKeyHandle,
                unsigned int uiAlgID,
                unsigned char *pucIV,
                unsigned char *pucData,
                unsigned int uiDataLength,
                unsigned char *pucEncData,
                unsigned int *puiEncDataLength);

int SDF_Decrypt(void *hSessionHandle,
                void *hKeyHandle,
                unsigned int uiAlgID,
                unsigned char *pucIV,
                unsigned char *pucEncData,
                unsigned int uiEncDataLength,
                unsigned char *pucData,
                unsigned int *puiDataLength);

int SDF_CalculateMAC(void *hSessionHandle,
                     void *hKeyHandle,
                     unsigned int uiAlgID,
                     unsigned char *pucIV,
                     unsigned char *pucData,
                     unsigned int uiDataLength,
                     unsigned char *pucMAC,
                     unsigned int *puiMACLength);

int SDF_HashInit(void *hSessionHandle,
                 unsigned int uiAlgID,
                 ECCrefPublicKey *pucPublicKey,
                 unsigned char *pucID,
                 unsigned int uiIDLength);

int SDF_HashUpdate(void *hSessionHandle, unsigned char *pucData, unsigned int uiDataLength);
int SDF_HashFinal(void *hSessionHandle, unsigned char *pucHash, unsigned int *puiHashLength);

int SDF_CreateFile(void *hSessionHandle,
                   unsigned char *pucFileName,
                   unsigned int uiNameLen,/* max 128-byte */
                   unsigned int uiFileSize);

int SDF_ReadFile(void *hSessionHandle, unsigned char *pucFileName, unsigned int uiNameLen, unsigned int uiOffset,
                 unsigned int *puiFileLength, unsigned char *pucBuffer);
int SDF_WriteFile(void *hSessionHandle, unsigned char *pucFileName, unsigned int uiNameLen,
                  unsigned int uiOffset, unsigned int uiFileLength, unsigned char *pucBuffer);
int SDF_DeleteFile(void *hSessionHandle, unsigned char *pucFileName, unsigned int uiNameLen);

#ifdef __cplusplus
}
#endif
