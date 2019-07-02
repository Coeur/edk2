/** @file
  Null S3 Library instance does nothing and returns unsupported status.

  This library instance is no longer used and module using this library
  class should update to directly locate EFI_PEI_S3_RESUME_PPI defined
  in PI 1.2 specification.

Copyright (c) 2006 - 2018, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/
#include <PiPei.h>
#include <Library/S3Lib.h>

/**
  This function is responsible for calling the S3 resume vector in the ACPI Tables.

  @retval EFI_SUCCESS  Success to restore config from S3.
  @retval Others       Fail to restore config from S3.
**/
EFI_STATUS
EFIAPI
AcpiS3ResumeOs (
  VOID
  )
{
  return EFI_UNSUPPORTED;
}

