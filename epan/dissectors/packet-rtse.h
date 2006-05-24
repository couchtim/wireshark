/* Do not modify this file.                                                   */
/* It is created automatically by the ASN.1 to Wireshark dissector compiler   */
/* .\packet-rtse.h                                                            */
/* ../../tools/asn2wrs.py -b -e -p rtse -c rtse.cnf -s packet-rtse-template rtse.asn */

/* Input file: packet-rtse-template.h */

#line 1 "packet-rtse-template.h"
/* packet-rtse.h
 * Routines for RTSE packet dissection
 * Graeme Lunt 2005
 *
 * $Id$
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef PACKET_RTSE_H
#define PACKET_RTSE_H


/*--- Included file: packet-rtse-exp.h ---*/
#line 1 "packet-rtse-exp.h"
int dissect_rtse_RTORQapdu(gboolean implicit_tag, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, int hf_index);
int dissect_rtse_RTOACapdu(gboolean implicit_tag, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, int hf_index);
int dissect_rtse_RTORJapdu(gboolean implicit_tag, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, int hf_index);
int dissect_rtse_RTABapdu(gboolean implicit_tag, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, int hf_index);
int dissect_rtse_EXTERNAL(gboolean implicit_tag, tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, int hf_index);

/*--- End of included file: packet-rtse-exp.h ---*/
#line 30 "packet-rtse-template.h"

void register_rtse_oid_dissector_handle(const char *oid, dissector_handle_t dissector, int proto _U_, const char *name, gboolean uses_ros);

#endif  /* PACKET_RTSE_H */
