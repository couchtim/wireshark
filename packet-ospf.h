/* packet-ospf.h
 *
 * $Id: packet-ospf.h,v 1.10 2000/09/13 07:47:10 guy Exp $
 * 
 * (c) 1998 Hannes Boehm
 *
 * Ethereal - Network traffic analyzer
 * By Gerald Combs <gerald@zing.org>
 * Copyright 1998 Gerald Combs
 *
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

#ifndef __PACKET_OSPF_H__
#define __PACKET_OSPF_H__

#define OSPF_HEADER_LENGTH	24

#define OSPF_HELLO	1
#define OSPF_DB_DESC	2
#define OSPF_LS_REQ	3
#define OSPF_LS_UPD	4
#define OSPF_LS_ACK	5

#define OSPF_AUTH_NONE		0
#define OSPF_AUTH_SIMPLE	1
#define OSPF_AUTH_CRYPT		2

#define OSPF_OPTIONS_E		2
#define OSPF_OPTIONS_MC		4
#define OSPF_OPTIONS_NP		8
#define OSPF_OPTIONS_EA		16
#define OSPF_OPTIONS_DC		32

#define OSPF_DBD_FLAG_MS	1
#define OSPF_DBD_FLAG_M		2
#define OSPF_DBD_FLAG_I		4

#define OSPF_LS_REQ_LENGTH	12

#define OSPF_LSTYPE_ROUTER	1
#define OSPF_LSTYPE_NETWORK	2
#define OSPF_LSTYPE_SUMMERY	3
#define OSPF_LSTYPE_ASBR	4
#define OSPF_LSTYPE_ASEXT	5
#define OSPF_LSTYPE_ASEXT7	7

/* Opaque LSA types */
#define OSPF_LSTYPE_OP_LINKLOCAL 9
#define OSPF_LSTYPE_OP_AREALOCAL 10
#define OSPF_LSTYPE_OP_ASWIDE    11

#define OSPF_LINK_PTP		1
#define OSPF_LINK_TRANSIT	2
#define OSPF_LINK_STUB		3
#define OSPF_LINK_VIRTUAL	4

#define OSPF_LSA_HEADER_LENGTH	20

/* Known opaque LSAs */
#define OSPF_LSA_MPLS_TE        1

typedef struct _e_ospfhdr {
    guint8  version;
    guint8  packet_type;
    guint16 length;
    guint32 routerid;
    guint32 area;
    guint16 checksum;
    guint16 auth_type;
    char auth_data[8];
} e_ospfhdr;

typedef struct _e_ospf_hello {
    guint32 network_mask;
    guint16 hellointervall;
    guint8  options;
    guint8  priority;
    guint32 dead_interval;
    guint32 drouter;
    guint32 bdrouter;
} e_ospf_hello ;

typedef struct _e_ospf_dbd {
   guint16 interface_mtu;
   guint8  options;
   guint8  flags;
   guint32 dd_sequence;
} e_ospf_dbd;

typedef struct _e_ospf_ls_req {
    guint32	ls_type;
    guint32	ls_id;
    guint32	adv_router;
} e_ospf_ls_req;

typedef struct _e_ospf_lsa_hdr {
    guint16	ls_age;
    guint8	options;
    guint8	ls_type;
    guint32	ls_id;
    guint32	adv_router;
    guint32	ls_seq;
    guint16	ls_checksum;
    guint16	length;
} e_ospf_lsa_hdr;

typedef struct _e_ospf_router_lsa {
    guint8 flags;
    guint8 empfty;
    guint16 nr_links;
} e_ospf_router_lsa;

typedef struct _e_ospf_router_data {
    guint32 link_id;
    guint32 link_data;
    guint8 link_type;
    guint8 nr_tos;
    guint16 tos0_metric;
} e_ospf_router_data;

typedef struct _e_ospf_router_metric {
    guint8	tos;
    guint8	empty;
    guint16	metric;
} e_ospf_router_metric;

typedef struct  _e_ospf_network_lsa {
    guint32	network_mask;
} e_ospf_network_lsa;

typedef struct _e_ospf_lsa_upd_hdr {
    guint32	lsa_nr;
} e_ospf_lsa_upd_hdr;

typedef struct _e_ospf_summary_lsa {
    guint32	network_mask;
} e_ospf_summary_lsa;

typedef struct _e_ospf_asexternal_lsa {
    guint8	options;
    guint8      metric[3];
    guint32	gateway;
    guint32 	external_tag;
} e_ospf_asexternal_lsa;

typedef struct _e_ospf_crypto {
    guint16   mbz;
    guint8      key_id;
    guint8      length;
    guint32   sequence_num;
} e_ospf_crypto;

#endif
