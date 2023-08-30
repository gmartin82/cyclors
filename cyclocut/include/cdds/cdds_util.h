//
// Copyright (c) 2022 ZettaScale Technology
//
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// http://www.eclipse.org/legal/epl-2.0, or the Apache License, Version 2.0
// which is available at https://www.apache.org/licenses/LICENSE-2.0.
//
// SPDX-License-Identifier: EPL-2.0 OR Apache-2.0
//
// Contributors:
//   ZettaScale Zenoh Team, <zenoh@zettascale.tech>
//
#ifndef ATOLAB_CDDS_UTIL_H_
#define ATOLAB_CDDS_UTIL_H_

#include "dds/dds.h"

//#define CY_DEBUG_ON 1
#ifdef CY_DEBUG_ON
#define CY_DEBUG(msg) printf(msg)
#define CY_DEBUG_WA(fmt, ...) printf(fmt, __VA_ARGS__)
#else
#define CY_DEBUG(msg)
#define CY_DEBUG_WA(fmt, ...)
#endif

dds_entity_t cdds_create_blob_topic(dds_entity_t dp, char *topic_name, char *type_name, bool is_keyless);

/**
 * @brief Gets the sertype of an entity
 *
 * The provided entity must be a topic or endpoint. This function returns a pointer to
 * the sertype of the entity. The refcount of the sertype is not incremented. The lifetime
 * of the returned sertype pointer is at least that of the lifetime of the entity on which
 * it was invoked.
 *
 * @param[in] entity A topic, reader or writer entity
 * @param[out] sertype A pointer to the entity's sertype is stored in this parameter (see note above on lifetime of this pointer)
 *
 * @returns A dds_return_t indicating success or failure.
 * @retval DDS_RETCODE_OK
 *             The operation was successful.
 * @retval DDS_RETCODE_BAD_PARAMETER
 *             The sertype parameter is NULL
 * @retval DDS_RETCODE_ILLEGAL_OPERATION
 *             Not a topic, reader or writer entity
 */
DDS_EXPORT dds_return_t
dds_get_entity_sertype (
  dds_entity_t entity,
  const struct ddsi_sertype **sertype);

#endif /* ATOLAB_CDDS_UTIL_H_ */
