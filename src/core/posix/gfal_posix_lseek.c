/* 
* Copyright @ Members of the EMI Collaboration, 2010.
* See www.eu-emi.eu for details on the copyright holders.
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


/*
 * @file gfal_posix_lseek.c
 * @brief file for the internal function of the POSIX lseek function
 * @author Devresse Adrien
 * @date 18/07/2011
 * 
 **/
 
#include <stdio.h>
#include <errno.h>
#include <glib.h>


#include <common/gfal_prototypes.h>
#include <common/gfal_types.h>
#include <common/gfal_common_plugin.h>
#include <common/gfal_common_filedescriptor.h>
#include <common/gfal_common_errverbose.h>
#include <common/gfal_common_file_handle.h>


#include "gfal_posix_internal.h"

 
 
 /*
  * 
  * Implementation of the posix lseek
  */
 int gfal_posix_internal_lseek(int fd, off_t offset, int whence){
	 GError* tmp_err=NULL;
	 gfal_handle handle;
	 int res= -1;

	if((handle = gfal_posix_instance()) == NULL){
		errno = EIO;
		return -1;
	}
	

    res = gfal2_lseek(handle, fd, offset, whence, &tmp_err);
	if(tmp_err){
		gfal_posix_register_internal_error(handle, "[gfal_lseek]", tmp_err);
		errno = tmp_err->code;	
	}
	return res; 
	 
 }
 
 
 