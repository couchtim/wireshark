/* packet-sctp.h
 *
 * Defintion of SCTP specific structures used by tap listeners.
 *
 * $Id$
 * Copyright 2004 Michael Tuexen <tuexen [AT] fh-muenster.de>

 * Ethereal - Network traffic analyzer
 * By Gerald Combs <gerald@ethereal.com>
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

#ifndef __PACKET_SCTP_H__
#define __PACKET_SCTP_H__

#define MAXIMUM_NUMBER_OF_TVBS 2048

struct _sctp_info {
  gboolean incomplete;
  gboolean adler32_calculated;
  gboolean adler32_correct;
  gboolean crc32c_calculated;
  gboolean crc32c_correct;
  gboolean checksum_zero;
  /* FIXME: do we need the ports and addresses to be here? */
  guint32 sport;
  guint32 dport;
  address ip_src;
  address ip_dst;
  guint32 verification_tag;
  guint32 number_of_tvbs;
  tvbuff_t *tvb[MAXIMUM_NUMBER_OF_TVBS];
};

#endif
