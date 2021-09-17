/**
 * Simplest decoder library for H.265
 */
#ifndef __MI_H265DECODER_LIB__
#define __MI_H265DECODER_LIB__

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
    typedef int(*pfn_mi_decoder_decodeframe)(MI_DEC_HANDLE hDecoder, ST_MI_DEC_INARGS *pstInArgs, ST_MI_DEC_OUTARGS *pstOutArgs);
    
    //add by luo 20170410
    typedef struct stDecodePARAM
    {
        ST_MI_DEC_INIT_PARAM stH265InitParam;
        MI_DEC_HANDLE hH265Handle;
        MI_DEC_HANDLE hDecHandle;
        ST_MI_DEC_INARGS stInArgs;
        ST_MI_DEC_OUTARGS stOutArgs;
        EM_MI_DECODER_TYPE eDecoderType;
        pfn_mi_decoder_decodeframe pFunDecodeFrame;
    } ST_MI_DECODE_PARAM, *PST_MI_DECODE_PARAM;
    //end add by luo 20170410
/******************************************************************************
* API
*******************************************************************************/
MIDEC_EXPORT int mi_h265decoder_create(MI_DEC_HANDLE *phDecoder, ST_MI_DEC_INIT_PARAM *pstInitParam);
MIDEC_EXPORT int mi_h265decoder_decodeframe(MI_DEC_HANDLE hDecoder, ST_MI_DEC_INARGS *pstInArgs, ST_MI_DEC_OUTARGS *pstOutArgs);
MIDEC_EXPORT int mi_h265decoder_delete(MI_DEC_HANDLE hDecoder);
MIDEC_EXPORT int mi_h265decoder_getversion(ST_MI_DEC_LIB_VERSION *psVersion);

#ifdef _WIN32
//Windows
};
#else
//Linux...
#ifdef __cplusplus
};
#endif
#endif

#endif //__MI_H265DECODER_LIB__
