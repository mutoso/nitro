/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2008, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this program; if not, If not, 
 * see <http://www.gnu.org/licenses/>.
 *
 */

#include "cgm_Element.h"
#include "cgm_JNI.h"

CGM_JNI_DECLARE_OBJ(cgm_Element)

JNIEXPORT void JNICALL Java_cgm_Element_destructMemory
  (JNIEnv *env, jobject self)
{
    cgm_Element *element = _GetObj(env, self);
    if (element)
        cgm_Element_destruct(&element);
    _SetObj(env, self, NULL);
}

JNIEXPORT jstring JNICALL Java_cgm_Element_getName
  (JNIEnv *env, jobject self)
{
    cgm_Element *element = _GetObj(env, self);
    return (*env)->NewStringUTF(env, cgm_Element_getName(element));
}
