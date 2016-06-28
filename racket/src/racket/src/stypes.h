
enum {

  /* Compiled bytecode elements: */
  scheme_toplevel_type,                 /* 0 */
  scheme_local_type,                    /* 1 */
  scheme_local_unbox_type,              /* 2 */
  scheme_application_type,              /* 3 */
  scheme_application2_type,             /* 4 */
  scheme_application3_type,             /* 5 */
  scheme_sequence_type,                 /* 6 */
  scheme_branch_type,                   /* 7 */
  scheme_lambda_type,                   /* 8 */
  scheme_let_value_type,                /* 9 */
  scheme_let_void_type,                 /* 10 */
  scheme_letrec_type,                   /* 11 */
  scheme_let_one_type,                  /* 12 */
  scheme_with_cont_mark_type,           /* 13 */
  scheme_quote_syntax_type,             /* 14 */

  scheme_define_values_type,            /* 15 */
  scheme_set_bang_type,                 /* 16 */
  scheme_boxenv_type,                   /* 17 */
  scheme_begin0_sequence_type,          /* 18 */
  scheme_varref_form_type,              /* 19 */
  scheme_apply_values_type,             /* 20 */
  scheme_with_immed_mark_type,          /* 21 */
  scheme_case_lambda_sequence_type,     /* 22 */
  scheme_inline_variant_type,           /* 23 */

  _scheme_values_types_,                /* 24 */
  /* All following types are values at run time */
  
  scheme_linklet_type,                  /* 25 */

  /* Replacements for some of the above as the
     compiler's intermediate representation for
     optimization: */
  scheme_ir_local_type,                 /* 26 */
  scheme_ir_lambda_type,                /* 27 */
  scheme_ir_let_value_type,             /* 28 */
  scheme_ir_let_header_type,            /* 29 */
  scheme_ir_toplevel_type,              /* 30 */

  scheme_quote_compilation_type, /* used while writing, only */

  /* Generated in the compiler front-end, but
     registered in the prefix table instead of
     used directly as an "expression": */
  scheme_variable_type,                 /* 32 */

  _scheme_ir_values_types_,             /* 33 */
  /* All of the following are literal values from the
     perspective of the compiler */

  scheme_linklet_bundle_type,           /* 34 */
  scheme_linklet_directory_type,        /* 35 */
  scheme_instance_type,                 /* 36 */

  /* procedure types */
  scheme_prim_type,                     /* 37 */
  scheme_closed_prim_type,              /* 38 */
  scheme_closure_type,                  /* 39 */
  scheme_case_closure_type,             /* 40 */
  scheme_cont_type,                     /* 41 */
  scheme_escaping_cont_type,            /* 42 */
  scheme_proc_struct_type,              /* 43 */
  scheme_native_closure_type,           /* 44 */
  scheme_proc_chaperone_type,           /* 45 */

  scheme_chaperone_type,                /* 46 */

  /* structure type (plus one above for procs) */
  scheme_structure_type,                /* 47 */

  /* number types (must be together) */
  scheme_integer_type,                  /* 48 */
  scheme_bignum_type,                   /* 49 */
  scheme_rational_type,                 /* 50 */
  scheme_float_type,                    /* 51 */
  scheme_double_type,                   /* 52 */
  scheme_complex_type,                  /* 53 */

  /* other eqv?-able values (must be with numbers) */
  scheme_char_type,                     /* 54 */

  /* other values */
  scheme_long_double_type,              /* 55 */
  scheme_char_string_type,              /* 56 */
  scheme_byte_string_type,              /* 57 */
  scheme_unix_path_type,                /* 58 */
  scheme_windows_path_type,             /* 59 */
  scheme_symbol_type,                   /* 60 */
  scheme_keyword_type,                  /* 61 */
  scheme_null_type,                     /* 62 */
  scheme_pair_type,                     /* 63 */
  scheme_mutable_pair_type,             /* 64 */
  scheme_vector_type,                   /* 65 */
  scheme_inspector_type,                /* 66 */
  scheme_input_port_type,               /* 67 */
  scheme_output_port_type,              /* 68 */
  scheme_eof_type,                      /* 69 */
  scheme_true_type,                     /* 70 */
  scheme_false_type,                    /* 71 */
  scheme_void_type,                     /* 72 */
  scheme_primitive_syntax_type,         /* 73 */
  scheme_macro_type,                    /* 74 */
  scheme_box_type,                      /* 75 */
  scheme_thread_type,                   /* 76 */
  scheme_cont_mark_set_type,            /* 77 */
  scheme_sema_type,                     /* 78 */
  scheme_hash_table_type,               /* 79 */
  scheme_hash_tree_type,                /* 80 */
  scheme_eq_hash_tree_type,             /* 81 */
  scheme_eqv_hash_tree_type,            /* 82 */
  scheme_hash_tree_subtree_type,        /* 83 */
  scheme_hash_tree_collision_type,      /* 84 */
  scheme_hash_tree_indirection_type,    /* 85 */
  scheme_cpointer_type,                 /* 86 */
  scheme_prefix_type,                   /* 87 */
  scheme_weak_box_type,                 /* 88 */
  scheme_ephemeron_type,                /* 89 */
  scheme_struct_type_type,              /* 90 */
  scheme_module_index_type,             /* 91 */
  scheme_set_macro_type,                /* 92 */
  scheme_listener_type,                 /* 93 */
  scheme_env_type,                      /* 94 */
  scheme_startup_env_type,              /* 95 */
  scheme_config_type,                   /* 96 */
  scheme_stx_type,                      /* 97 */
  scheme_will_executor_type,            /* 98 */
  scheme_custodian_type,                /* 99 */
  scheme_random_state_type,             /* 100 */
  scheme_regexp_type,                   /* 101 */
  scheme_bucket_type,                   /* 102 */
  scheme_bucket_table_type,             /* 103 */
  scheme_subprocess_type,               /* 104 */
  scheme_eval_waiting_type,             /* 105 */
  scheme_tail_call_waiting_type,        /* 106 */
  scheme_undefined_type,                /* 107 */
  scheme_struct_property_type,          /* 108 */
  scheme_chaperone_property_type,       /* 109 */
  scheme_multiple_values_type,          /* 110 */
  scheme_placeholder_type,              /* 111 */
  scheme_table_placeholder_type,        /* 112 */
  scheme_svector_type,                  /* 113 */
  scheme_resolve_prefix_type,           /* 114 */
  scheme_security_guard_type,           /* 115 */
  scheme_indent_type,                   /* 116 */
  scheme_udp_type,                      /* 117 */
  scheme_udp_evt_type,                  /* 118 */
  scheme_tcp_accept_evt_type,           /* 119 */
  scheme_id_macro_type,                 /* 120 */
  scheme_evt_set_type,                  /* 121 */
  scheme_wrap_evt_type,                 /* 122 */
  scheme_handle_evt_type,               /* 123 */
  scheme_replace_evt_type,              /* 124 */
  scheme_active_replace_evt_type,       /* 125 */
  scheme_nack_guard_evt_type,           /* 126 */
  scheme_semaphore_repost_type,         /* 127 */
  scheme_channel_type,                  /* 128 */
  scheme_channel_put_type,              /* 129 */
  scheme_thread_resume_type,            /* 130 */
  scheme_thread_suspend_type,           /* 131 */
  scheme_thread_dead_type,              /* 132 */
  scheme_poll_evt_type,                 /* 133 */
  scheme_nack_evt_type,                 /* 134 */
  scheme_thread_set_type,               /* 135 */
  scheme_string_converter_type,         /* 136 */
  scheme_alarm_type,                    /* 137 */
  scheme_thread_recv_evt_type,          /* 138 */
  scheme_thread_cell_type,              /* 139 */
  scheme_channel_syncer_type,           /* 140 */
  scheme_special_comment_type,          /* 141 */
  scheme_write_evt_type,                /* 142 */
  scheme_always_evt_type,               /* 143 */
  scheme_never_evt_type,                /* 144 */
  scheme_progress_evt_type,             /* 145 */
  scheme_place_dead_type,               /* 146 */
  scheme_already_comp_type,             /* 147 */
  scheme_readtable_type,                /* 148 */
  scheme_thread_cell_values_type,       /* 149 */
  scheme_global_ref_type,               /* 150 */
  scheme_cont_mark_chain_type,          /* 151 */
  scheme_raw_pair_type,                 /* 152 */
  scheme_prompt_type,                   /* 153 */
  scheme_prompt_tag_type,               /* 154 */
  scheme_continuation_mark_key_type,    /* 155 */
  scheme_delay_syntax_type,             /* 156 */
  scheme_cust_box_type,                 /* 157 */
  scheme_logger_type,                   /* 158 */
  scheme_log_reader_type,               /* 159 */
  scheme_noninline_proc_type,           /* 160 */
  scheme_future_type,                   /* 161 */
  scheme_flvector_type,                 /* 162 */
  scheme_extflvector_type,              /* 163 */
  scheme_fxvector_type,                 /* 164 */
  scheme_place_type,                    /* 165 */
  scheme_place_object_type,             /* 166 */
  scheme_place_async_channel_type,      /* 167 */
  scheme_place_bi_channel_type,         /* 168 */
  scheme_once_used_type,                /* 169 */
  scheme_serialized_symbol_type,        /* 170 */
  scheme_serialized_keyword_type,       /* 171 */
  scheme_serialized_structure_type,     /* 172 */
  scheme_fsemaphore_type,               /* 173 */
  scheme_serialized_tcp_fd_type,        /* 174 */
  scheme_serialized_file_fd_type,       /* 175 */
  scheme_port_closed_evt_type,          /* 176 */
  scheme_proc_shape_type,               /* 177 */
  scheme_struct_proc_shape_type,        /* 178 */
  scheme_phantom_bytes_type,            /* 179 */
  scheme_environment_variables_type,    /* 180 */
  scheme_filesystem_change_evt_type,    /* 181 */
  scheme_ctype_type,                    /* 182 */
  scheme_plumber_type,                  /* 183 */
  scheme_plumber_handle_type,           /* 184 */
  scheme_deferred_expr_type,            /* 185 */
  scheme_will_be_lambda_type,           /* 186 */
                                        
#ifdef MZTAG_REQUIRED                            
  _scheme_last_normal_type_,            /* 187 */

  /* The remaining tags exist for GC tracing (in non-conservative
     mode), but they are not needed for run-time tag tests */
                                                 
  scheme_rt_weak_array,                 /* 188 */
                                        
  scheme_rt_comp_env,                   /* 189 */
  scheme_rt_constant_binding,           /* 190 */
  scheme_rt_resolve_info,               /* 191 */
  scheme_rt_unresolve_info,             /* 192 */
  scheme_rt_optimize_info,              /* 193 */
  scheme_rt_cont_mark,                  /* 194 */
  scheme_rt_saved_stack,                /* 195 */
  scheme_rt_reply_item,                 /* 196 */
  scheme_rt_ir_lambda_info,             /* 197 */
  scheme_rt_overflow,                   /* 198 */
  scheme_rt_overflow_jmp,               /* 199 */
  scheme_rt_meta_cont,                  /* 200 */
  scheme_rt_dyn_wind_cell,              /* 201 */
  scheme_rt_dyn_wind_info,              /* 202 */
  scheme_rt_dyn_wind,                   /* 203 */
  scheme_rt_dup_check,                  /* 204 */
  scheme_rt_thread_memory,              /* 205 */
  scheme_rt_input_file,                 /* 206 */
  scheme_rt_input_fd,                   /* 207 */
  scheme_rt_oskit_console_input,        /* 208 */
  scheme_rt_tested_input_file,          /* 209 */
  scheme_rt_tested_output_file,         /* 210 */
  scheme_rt_indexed_string,             /* 211 */
  scheme_rt_output_file,                /* 212 */
  scheme_rt_pipe,                       /* 213 */
  scheme_rt_system_child,               /* 214 */
  scheme_rt_tcp,                        /* 215 */
  scheme_rt_write_data,                 /* 216 */
  scheme_rt_tcp_select_info,            /* 217 */
  scheme_rt_param_data,                 /* 218 */
  scheme_rt_will,                       /* 219 */
  scheme_rt_finalization,               /* 220 */
  scheme_rt_finalizations,              /* 221 */
  scheme_rt_cpp_object,                 /* 222 */
  scheme_rt_cpp_array_object,           /* 223 */
  scheme_rt_stack_object,               /* 224 */
  scheme_thread_hop_type,               /* 225 */
  scheme_rt_srcloc,                     /* 226 */
  scheme_rt_evt,                        /* 227 */
  scheme_rt_syncing,                    /* 228 */
  scheme_rt_comp_prefix,                /* 229 */
  scheme_rt_user_input,                 /* 230 */
  scheme_rt_user_output,                /* 231 */
  scheme_rt_compact_port,               /* 232 */
  scheme_rt_read_special_dw,            /* 233 */
  scheme_rt_regwork,                    /* 234 */
  scheme_rt_rx_lazy_string,             /* 235 */
  scheme_rt_buf_holder,                 /* 236 */
  scheme_rt_parameterization,           /* 237 */
  scheme_rt_print_params,               /* 238 */
  scheme_rt_read_params,                /* 239 */
  scheme_rt_native_code,                /* 240 */
  scheme_rt_native_code_plus_case,      /* 241 */
  scheme_rt_jitter_data,                /* 242 */
  scheme_rt_module_exports,             /* 243 */
  scheme_rt_delay_load_info,            /* 244 */
  scheme_rt_marshal_info,               /* 245 */
  scheme_rt_unmarshal_info,             /* 246 */
  scheme_rt_runstack,                   /* 247 */
  scheme_rt_sfs_info,                   /* 248 */
  scheme_rt_validate_clearing,          /* 249 */
  scheme_rt_lightweight_cont,           /* 250 */
  scheme_rt_export_info,                /* 251 */
  scheme_rt_cont_jmp,                   /* 252 */
  scheme_rt_letrec_check_frame,         /* 253 */
#endif

  _scheme_last_type_
};
