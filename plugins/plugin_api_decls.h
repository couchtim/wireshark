/* plugin_api_decls.h
 * Declarations of a list of "p_" names; included in various places
 * to declare them as variables or as function members.
 *
 * $Id: plugin_api_decls.h,v 1.1 2002/05/05 00:16:36 guy Exp $
 *
 * Ethereal - Network traffic analyzer
 * Copyright 2000 by Gilbert Ramirez <gram@alumni.rice.edu>
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

/*
 * If you're adding a new routine, please add it to the *end* of this
 * table, so that the ABI remains backwards-compatible if the only change
 * is that new functions are added; don't bother trying to keep related
 * routines together.  (This list is included in "plugin_table.h" to
 * declare the members of the function address table, so the order *does*
 * matter.)
 *
 * If a routine is removed or a calling sequence changed, the ABI isn't
 * going to be backwards-compatible no matter what you do; if that's
 * done, you may re-shuffle the routines to put related routines
 * together if you want.
 */

addr_check_col				p_check_col;
addr_col_clear				p_col_clear;
addr_col_add_fstr			p_col_add_fstr;
addr_col_append_fstr			p_col_append_fstr;
addr_col_prepend_fstr			p_col_prepend_fstr;
addr_col_add_str			p_col_add_str;
addr_col_append_str			p_col_append_str;
addr_col_set_str			p_col_set_str;

addr_register_init_routine		p_register_init_routine;
addr_register_postseq_cleanup_routine	p_register_postseq_cleanup_routine;

addr_match_strval			p_match_strval;
addr_val_to_str				p_val_to_str;

addr_conversation_new			p_conversation_new;
addr_find_conversation			p_find_conversation;
addr_conversation_set_dissector		p_conversation_set_dissector;

addr_proto_register_protocol		p_proto_register_protocol;
addr_proto_register_field_array		p_proto_register_field_array;
addr_proto_register_subtree_array	p_proto_register_subtree_array;

addr_dissector_add			p_dissector_add;
addr_dissector_delete			p_dissector_delete;
addr_dissector_add_handle		p_dissector_add_handle;

addr_heur_dissector_add			p_heur_dissector_add;

addr_register_dissector			p_register_dissector;
addr_find_dissector			p_find_dissector;
addr_create_dissector_handle		p_create_dissector_handle;
addr_call_dissector			p_call_dissector;

addr_proto_is_protocol_enabled		p_proto_is_protocol_enabled;

addr_proto_item_get_len			p_proto_item_get_len;
addr_proto_item_set_len			p_proto_item_set_len;
addr_proto_item_set_text		p_proto_item_set_text;
addr_proto_item_append_text		p_proto_item_append_text;
addr_proto_item_add_subtree		p_proto_item_add_subtree;
addr_proto_tree_add_item		p_proto_tree_add_item;
addr_proto_tree_add_item_hidden		p_proto_tree_add_item_hidden;
addr_proto_tree_add_protocol_format	p_proto_tree_add_protocol_format;

addr_proto_tree_add_bytes		p_proto_tree_add_bytes;
addr_proto_tree_add_bytes_hidden	p_proto_tree_add_bytes_hidden;
addr_proto_tree_add_bytes_format	p_proto_tree_add_bytes_format;

addr_proto_tree_add_time		p_proto_tree_add_time;
addr_proto_tree_add_time_hidden		p_proto_tree_add_time_hidden;
addr_proto_tree_add_time_format		p_proto_tree_add_time_format;

addr_proto_tree_add_ipxnet		p_proto_tree_add_ipxnet;
addr_proto_tree_add_ipxnet_hidden	p_proto_tree_add_ipxnet_hidden;
addr_proto_tree_add_ipxnet_format	p_proto_tree_add_ipxnet_format;

addr_proto_tree_add_ipv4		p_proto_tree_add_ipv4;
addr_proto_tree_add_ipv4_hidden		p_proto_tree_add_ipv4_hidden;
addr_proto_tree_add_ipv4_format		p_proto_tree_add_ipv4_format;

addr_proto_tree_add_ipv6		p_proto_tree_add_ipv6;
addr_proto_tree_add_ipv6_hidden		p_proto_tree_add_ipv6_hidden;
addr_proto_tree_add_ipv6_format		p_proto_tree_add_ipv6_format;

addr_proto_tree_add_ether		p_proto_tree_add_ether;
addr_proto_tree_add_ether_hidden	p_proto_tree_add_ether_hidden;
addr_proto_tree_add_ether_format	p_proto_tree_add_ether_format;

addr_proto_tree_add_string		p_proto_tree_add_string;
addr_proto_tree_add_string_hidden	p_proto_tree_add_string_hidden;
addr_proto_tree_add_string_format	p_proto_tree_add_string_format;

addr_proto_tree_add_boolean		p_proto_tree_add_boolean;
addr_proto_tree_add_boolean_hidden	p_proto_tree_add_boolean_hidden;
addr_proto_tree_add_boolean_format	p_proto_tree_add_boolean_format;

addr_proto_tree_add_double		p_proto_tree_add_double;
addr_proto_tree_add_double_hidden	p_proto_tree_add_double_hidden;
addr_proto_tree_add_double_format	p_proto_tree_add_double_format;

addr_proto_tree_add_uint		p_proto_tree_add_uint;
addr_proto_tree_add_uint_hidden		p_proto_tree_add_uint_hidden;
addr_proto_tree_add_uint_format		p_proto_tree_add_uint_format;

addr_proto_tree_add_int			p_proto_tree_add_int;
addr_proto_tree_add_int_hidden		p_proto_tree_add_int_hidden;
addr_proto_tree_add_int_format		p_proto_tree_add_int_format;

addr_proto_tree_add_text		p_proto_tree_add_text;

addr_tvb_new_subset			p_tvb_new_subset;

addr_tvb_set_free_cb			p_tvb_set_free_cb;
addr_tvb_set_child_real_data_tvbuff	p_tvb_set_child_real_data_tvbuff;
addr_tvb_new_real_data			p_tvb_new_real_data;

addr_tvb_length				p_tvb_length;
addr_tvb_length_remaining		p_tvb_length_remaining;
addr_tvb_bytes_exist			p_tvb_bytes_exist;
addr_tvb_offset_exists			p_tvb_offset_exists;
addr_tvb_reported_length		p_tvb_reported_length;
addr_tvb_reported_length_remaining	p_tvb_reported_length_remaining;

addr_tvb_get_guint8			p_tvb_get_guint8;

addr_tvb_get_ntohs			p_tvb_get_ntohs;
addr_tvb_get_ntoh24			p_tvb_get_ntoh24;
addr_tvb_get_ntohl			p_tvb_get_ntohl;

addr_tvb_get_letohs			p_tvb_get_letohs;
addr_tvb_get_letoh24			p_tvb_get_letoh24;
addr_tvb_get_letohl			p_tvb_get_letohl;

addr_tvb_memcpy				p_tvb_memcpy;
addr_tvb_memdup				p_tvb_memdup;

addr_tvb_get_ptr			p_tvb_get_ptr;

addr_tvb_find_guint8			p_tvb_find_guint8;
addr_tvb_pbrk_guint8			p_tvb_pbrk_guint8;

addr_tvb_strnlen			p_tvb_strnlen;

addr_tvb_format_text			p_tvb_format_text;

addr_tvb_get_nstringz			p_tvb_get_nstringz;
addr_tvb_get_nstringz0			p_tvb_get_nstringz0;

addr_tvb_find_line_end			p_tvb_find_line_end;
addr_tvb_find_line_end_unquoted		p_tvb_find_line_end_unquoted;

addr_tvb_strneql			p_tvb_strneql;
addr_tvb_strncaseeql			p_tvb_strncaseeql;

addr_tvb_bytes_to_str			p_tvb_bytes_to_str;

addr_prefs_register_protocol		p_prefs_register_protocol;
addr_prefs_register_uint_preference	p_prefs_register_uint_preference;
addr_prefs_register_bool_preference	p_prefs_register_bool_preference;
addr_prefs_register_enum_preference	p_prefs_register_enum_preference;
addr_prefs_register_string_preference	p_prefs_register_string_preference;

addr_register_giop_user			p_register_giop_user;
addr_is_big_endian			p_is_big_endian;
addr_get_CDR_encap_info			p_get_CDR_encap_info;
addr_get_CDR_any			p_get_CDR_any;
addr_get_CDR_boolean			p_get_CDR_boolean;
addr_get_CDR_char			p_get_CDR_char;
addr_get_CDR_double			p_get_CDR_double;
addr_get_CDR_enum			p_get_CDR_enum;
addr_get_CDR_fixed			p_get_CDR_fixed;
addr_get_CDR_float			p_get_CDR_float;
addr_get_CDR_interface			p_get_CDR_interface;
addr_get_CDR_long			p_get_CDR_long;
addr_get_CDR_object			p_get_CDR_object;
addr_get_CDR_octet			p_get_CDR_octet;
addr_get_CDR_octet_seq			p_get_CDR_octet_seq;
addr_get_CDR_short			p_get_CDR_short;
addr_get_CDR_string			p_get_CDR_string;
addr_get_CDR_typeCode			p_get_CDR_typeCode;
addr_get_CDR_ulong			p_get_CDR_ulong;
addr_get_CDR_ushort			p_get_CDR_ushort;
addr_get_CDR_wchar			p_get_CDR_wchar;
addr_get_CDR_wstring			p_get_CDR_wstring;

addr_is_tpkt				p_is_tpkt;
addr_dissect_tpkt_encap			p_dissect_tpkt_encap;

addr_set_actual_length			p_set_actual_length;
addr_tcp_dissect_pdus			p_tcp_dissect_pdus;
addr_decode_boolean_bitfield		p_decode_boolean_bitfield;
addr_decode_numeric_bitfield		p_decode_numeric_bitfield;
addr_decode_enumerated_bitfield		p_decode_enumerated_bitfield;
