/**
 * Simplest decoder library for H.264
 */
#ifndef __MI_H264DECODER_LIB__
#define __MI_H264DECODER_LIB__

#ifdef _WIN32
//Windows
extern "C"
{
#else
//Linux...
#ifdef __cplusplus
extern "C"
{
#endif
#endif

#include "libmi_dec_common.h"

/******************************************************************************
* API
*******************************************************************************/
MIDEC_EXPORT int mi_h264decoder_create(MI_DEC_HANDLE *phDecoder, ST_MI_DEC_INIT_PARAM *pstInitParam);
MIDEC_EXPORT int mi_h264decoder_decodeframe(MI_DEC_HANDLE hDecoder, ST_MI_DEC_INARGS *pstInArgs, ST_MI_DEC_OUTARGS *pstOutArgs);
MIDEC_EXPORT int mi_h264decoder_delete(MI_DEC_HANDLE hDecoder);
MIDEC_EXPORT int mi_h264decoder_getversion(ST_MI_DEC_LIB_VERSION *psVersion);

#ifdef _WIN32
//Windows
};
#else
//Linux...
#ifdef __cplusplus
};
#endif
#endif

#endif //__MI_H264DECODER_LIB__