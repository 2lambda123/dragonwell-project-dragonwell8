/*
 * Copyright (c) 2014, 2017, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_VM_PRIMS_CDSOFFSETS_HPP
#define SHARE_VM_PRIMS_CDSOFFSETS_HPP
class CDSOffsets: public CHeapObj<mtInternal> {
 private:
  char* _name;
  int   _offset;
  CDSOffsets* _next;
  static CDSOffsets* _all;  // sole list for cds
 public:
  CDSOffsets(const char* name, int offset, CDSOffsets* next) {
     _name = NEW_C_HEAP_ARRAY(char, strlen(name) + 1, mtInternal);
     strcpy(_name, name);
     _offset = offset;
     _next = next;
  }

  char* get_name() const { return _name; }
  int   get_offset() const { return _offset; }
  CDSOffsets* next() const { return _next; }
  void add_end(CDSOffsets* n);

  static int find_offset(const char* name);
};
#endif // VM_PRIMS_CDSOFFSETS_HPP
