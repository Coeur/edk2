/** @file
PPI to describe all hash digests for a given FV

Copyright (c) 2017, Microsoft Corporation
Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __PEI_FIRMWARE_VOLUME_INFO_PREHASHED_FV_H__
#define __PEI_FIRMWARE_VOLUME_INFO_PREHASHED_FV_H__

#define EDKII_PEI_FIRMWARE_VOLUME_INFO_PREHASHED_FV_PPI_GUID \
 { 0x3ce1e631, 0x7008, 0x477c, { 0xad, 0xa7, 0x5d, 0xcf, 0xc7, 0xc1, 0x49, 0x4b } }

//
// HashAlgoId is TPM_ALG_ID in Tpm20.h
//
typedef struct _HASH_INFO {
  UINT16                                     HashAlgoId;
  UINT16                                     HashSize;
  //UINT8                                    Hash[];
} HASH_INFO;

//
// This PPI carries prehashsed data for one FV.  Platform should ensure 1:1 mapping between pre-hashed PPI and corresponding FV.
// The Count field in PPI is followed by Count number of FV hash info entries, which can be extended to PCR and logged to TCG event log directly by TCG modules.
// TCG module checks TPM required hash algorithms(PcdTpm2HashMask) with each pre-hased PPIs
//   For each pre-hashed PPI
//     If PPI carries hash generated by equivalent or larger algorithm set than TPM required, directly use PPI
//     else, drops PPI data and calculate all hash again
//
typedef struct {
  UINT32                                     FvBase;
  UINT32                                     FvLength;
  UINT32                                     Count;
  //HASH_INFO                                HashInfo[];
} EDKII_PEI_FIRMWARE_VOLUME_INFO_PREHASHED_FV_PPI;

extern EFI_GUID gEdkiiPeiFirmwareVolumeInfoPrehashedFvPpiGuid;

#endif

