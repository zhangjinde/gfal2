/*
 * Copyright (c) CERN 2013-2017
 *
 * Copyright (c) Members of the EMI Collaboration. 2010-2013
 *  See  http://www.eu-emi.eu/partners for details on the copyright
 *  holders.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#define GFAL_MDS_MAX_SRM_ENDPOINT 100

#include <glib.h>
#include <gfal_api.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MDS_BDII_EXTERNAL
#define MDS_BDII_EXTERNAL 0
#endif

typedef enum { SRMv2=0, SRMv1, WebDav, UnknownEndpointType } mds_type_endpoint;

/*
 * @struct gfal_mds_endpoint
 * represente an endpoint URL and its type
 */
typedef struct _gfal_mds_endpoint{
	char url[GFAL_URL_MAX_LEN];
	mds_type_endpoint type;
} gfal_mds_endpoint;

extern const char* bdii_env_var;
extern const char* bdii_config_var;
extern const char* bdii_config_group;
extern const char* bdii_config_timeout;

//
int gfal_mds_resolve_srm_endpoint(gfal2_context_t handle, const char* base_url, gfal_mds_endpoint* endpoints, size_t s_endpoint, GError** err);

// deprecated, use gfal_mds_resolve_srm_endpoint instead
int gfal_mds_get_se_types_and_endpoints(gfal2_context_t handle, const char *host, char ***se_types, char ***se_endpoints, GError** err);

gboolean gfal_get_nobdiiG(gfal2_context_t handle);

#ifdef __cplusplus
}
#endif


