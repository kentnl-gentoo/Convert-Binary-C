################################################################################
#
# $Project: Convert-Binary-C $
# $Author: mhx $
# $Date: 2002/11/23 18:00:36 +0100 $
# $Revision: 3 $
# $Snapshot: /Convert-Binary-C/0.04 $
# $Source: /t/include/sizeof.pl $
#
################################################################################
# 
# Copyright (c) 2002 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or
# modify it under the same terms as Perl itself.
# 
################################################################################

%size = (
  'AMT'                        => 272,
  'AMTS'                       =>  12,
  'ANY'                        =>   4,
  'ATEXIT_t'                   =>   4,
  'AV'                         =>  12,
  'BINOP'                      =>  30,
  'BLOCK'                      =>  69,
  'CHECKPOINT'                 =>   4,
  'COP'                        =>  48,
  'CURCUR'                     =>  36,
  'CV'                         =>  12,
  'DESTRUCTORFUNC_NOCONTEXT_t' =>   4,
  'DESTRUCTORFUNC_t'           =>   4,
  'FILE'                       => 148,
  'GP'                         =>  46,
  'GV'                         =>  12,
  'HE'                         =>  12,
  'HEK'                        =>   9,
  'HV'                         =>  12,
  'I16'                        =>   2,
  'I32'                        =>   4,
  'I8'                         =>   1,
  'IO'                         =>  12,
  'IV'                         =>   4,
  'JMPENV'                     => 165,
  'LISTOP'                     =>  30,
  'LOGOP'                      =>  30,
  'LOOP'                       =>  42,
  'MAGIC'                      =>  24,
  'MGVTBL'                     =>  20,
  'NV'                         =>   8,
  'OP'                         =>  22,
  'PADOFFSET'                  =>   4,
  'PADOP'                      =>  26,
  'PERL_CONTEXT'               =>  73,
  'PERL_SI'                    =>  32,
  'PMOP'                       =>  51,
  'PPADDR_t'                   =>   4,
  'PTR_TBL_ENT_t'              =>  12,
  'PTR_TBL_t'                  =>  12,
  'PVOP'                       =>  26,
  'PerlExitListEntry'          =>   8,
  'PerlInterpreter'            =>   1,
  'REGEXP'                     =>  60,
  'STRLEN'                     =>   4,
  'SUBLEXINFO'                 =>  20,
  'SV'                         =>  12,
  'SVCOMPARE_t'                =>   4,
  'SVFUNC_t'                   =>   4,
  'SVOP'                       =>  26,
  'Sighandler_t'               =>   4,
  'Sigsave_t'                  => 140,
  'Thread'                     =>   4,
  'U16'                        =>   2,
  'U32'                        =>   4,
  'U8'                         =>   1,
  'UNOP'                       =>  26,
  'UV'                         =>   4,
  'XPV'                        =>  12,
  'XPVAV'                      =>  41,
  'XPVBM'                      =>  39,
  'XPVCV'                      =>  74,
  'XPVFM'                      =>  78,
  'XPVGV'                      =>  49,
  'XPVHV'                      =>  48,
  'XPVIO'                      =>  88,
  'XPVIV'                      =>  16,
  'XPVLV'                      =>  45,
  'XPVMG'                      =>  32,
  'XPVNV'                      =>  24,
  'XPVUV'                      =>  16,
  'XRV'                        =>   4,
  'XSINIT_t'                   =>   4,
  'XSUBADDR_t'                 =>   4,
  'YYSTYPE'                    =>   4,
  '_G_fpos64_t'                =>  16,
  '_G_fpos_t'                  =>  12,
  '_G_iconv_t'                 =>  80,
  '_G_int16_t'                 =>   4,
  '_G_int32_t'                 =>   4,
  '_G_uint16_t'                =>   4,
  '_G_uint32_t'                =>   4,
  '_IO_FILE'                   => 148,
  '_IO_cookie_io_functions_t'  =>  16,
  '_IO_lock_t'                 =>   1,
  '_IO_marker'                 =>  12,
  '_LIB_VERSION_TYPE'          =>   1,
  '__FILE'                     => 148,
  '__blkcnt64_t'               =>   8,
  '__blkcnt_t'                 =>   4,
  '__blksize_t'                =>   4,
  '__caddr_t'                  =>   4,
  '__clock_t'                  =>   4,
  '__clockid_t'                =>   4,
  '__codecvt_result'           =>   1,
  '__compar_fn_t'              =>   4,
  '__convert_long_double'      =>  16,
  '__daddr_t'                  =>   4,
  '__dev_t'                    =>   8,
  '__fd_mask'                  =>   4,
  '__fsblkcnt64_t'             =>   8,
  '__fsblkcnt_t'               =>   4,
  '__fsfilcnt64_t'             =>   8,
  '__fsfilcnt_t'               =>   4,
  '__fsid_t'                   =>   8,
  '__gconv_end_fct'            =>   4,
  '__gconv_fct'                =>   4,
  '__gconv_info'               =>  44,
  '__gconv_init_fct'           =>   4,
  '__gconv_step'               =>  56,
  '__gconv_step_data'          =>  36,
  '__gconv_t'                  =>   4,
  '__gconv_trans_context_fct'  =>   4,
  '__gconv_trans_data'         =>  20,
  '__gconv_trans_end_fct'      =>   4,
  '__gconv_trans_fct'          =>   4,
  '__gconv_trans_init_fct'     =>   4,
  '__gconv_trans_query_fct'    =>   4,
  '__gid_t'                    =>   4,
  '__gnuc_va_list'             =>   4,
  '__id_t'                     =>   4,
  '__ino64_t'                  =>   8,
  '__ino_t'                    =>   4,
  '__int16_t'                  =>   2,
  '__int32_t'                  =>   4,
  '__int8_t'                   =>   1,
  '__intptr_t'                 =>   4,
  '__io_close_fn'              =>   4,
  '__io_read_fn'               =>   4,
  '__io_seek_fn'               =>   4,
  '__io_write_fn'              =>   4,
  '__ipc_pid_t'                =>   2,
  '__itimer_which'             =>   1,
  '__itimer_which_t'           =>   1,
  '__jmp_buf'                  =>  24,
  '__jmp_buf_tag'              => 156,
  '__key_t'                    =>   4,
  '__locale_struct'            =>  64,
  '__locale_t'                 =>   4,
  '__loff_t'                   =>   8,
  '__mbstate_t'                =>   8,
  '__mode_t'                   =>   4,
  '__nlink_t'                  =>   4,
  '__off64_t'                  =>   8,
  '__off_t'                    =>   4,
  '__pid_t'                    =>   4,
  '__pthread_attr_s'           =>  36,
  '__qaddr_t'                  =>   4,
  '__quad_t'                   =>   8,
  '__rlim64_t'                 =>   8,
  '__rlim_t'                   =>   4,
  '__sched_param'              =>   4,
  '__sig_atomic_t'             =>   4,
  '__sighandler_t'             =>   4,
  '__sigset_t'                 => 128,
  '__socket_type'              =>   1,
  '__socklen_t'                =>   4,
  '__ssize_t'                  =>   4,
  '__suseconds_t'              =>   4,
  '__swblk_t'                  =>   4,
  '__t_scalar_t'               =>   4,
  '__t_uscalar_t'              =>   4,
  '__time_t'                   =>   4,
  '__timer_t'                  =>   4,
  '__timezone_ptr_t'           =>   4,
  '__u_char'                   =>   1,
  '__u_int'                    =>   4,
  '__u_long'                   =>   4,
  '__u_quad_t'                 =>   8,
  '__u_short'                  =>   2,
  '__uid_t'                    =>   4,
  '__uint16_t'                 =>   2,
  '__uint32_t'                 =>   4,
  '__uint8_t'                  =>   1,
  '__useconds_t'               =>   4,
  '_fpreg'                     =>  10,
  '_fpstate'                   => 624,
  '_fpxreg'                    =>  16,
  '_libc_fpreg'                =>  10,
  '_libc_fpstate'              => 112,
  '_pthread_descr'             =>   4,
  '_pthread_fastlock'          =>   8,
  '_pthread_rwlock_t'          =>  32,
  '_sublex_info'               =>  20,
  '_xmmreg'                    =>  16,
  'addrinfo'                   =>  32,
  'am_table'                   => 272,
  'am_table_short'             =>  12,
  'any'                        =>   4,
  'av'                         =>  12,
  'binop'                      =>  30,
  'blkcnt64_t'                 =>   8,
  'blkcnt_t'                   =>   4,
  'blksize_t'                  =>   4,
  'block'                      =>  69,
  'block_eval'                 =>  20,
  'block_loop'                 =>  44,
  'block_sub'                  =>  28,
  'caddr_t'                    =>   4,
  'clock_t'                    =>   4,
  'clockid_t'                  =>   4,
  'cmsghdr'                    =>  13,
  'comparison_fn_t'            =>   4,
  'context'                    =>  73,
  'cookie_close_function_t'    =>   4,
  'cookie_io_functions_t'      =>  16,
  'cookie_read_function_t'     =>   4,
  'cookie_seek_function_t'     =>   4,
  'cookie_write_function_t'    =>   4,
  'cop'                        =>  48,
  'curcur'                     =>  36,
  'cv'                         =>  12,
  'cv_flags_t'                 =>   2,
  'daddr_t'                    =>   4,
  'dev_t'                      =>   8,
  'dirent'                     => 267,
  'dirent64'                   => 275,
  'div_t'                      =>   8,
  'double_t'                   =>  12,
  'drand48_data'               =>  24,
  'error_t'                    =>   4,
  'exception'                  =>  32,
  'exitlistentry'              =>   8,
  'expectation'                =>   1,
  'fd_mask'                    =>   4,
  'fd_set'                     => 128,
  'filter_t'                   =>   4,
  'float_t'                    =>  12,
  'flock'                      =>  16,
  'flock64'                    =>  24,
  'fpos64_t'                   =>  16,
  'fpos_t'                     =>  12,
  'fpregset_t'                 =>   4,
  'fsblkcnt64_t'               =>   8,
  'fsblkcnt_t'                 =>   4,
  'fsfilcnt64_t'               =>   8,
  'fsfilcnt_t'                 =>   4,
  'fsid_t'                     =>   8,
  'gid_t'                      =>   4,
  'gp'                         =>  46,
  'greg_t'                     =>   4,
  'gregset_t'                  =>  76,
  'gv'                         =>  12,
  'he'                         =>  12,
  'hek'                        =>   9,
  'hostent'                    =>  20,
  'hv'                         =>  12,
  'id_t'                       =>   4,
  'imaxdiv_t'                  =>  16,
  'in6_addr'                   =>  16,
  'in6_pktinfo'                =>  20,
  'in_addr'                    =>   4,
  'in_addr_t'                  =>   4,
  'in_pktinfo'                 =>  12,
  'in_port_t'                  =>   2,
  'ino64_t'                    =>   8,
  'ino_t'                      =>   4,
  'int16_t'                    =>   2,
  'int32_t'                    =>   4,
  'int8_t'                     =>   1,
  'int_fast16_t'               =>   4,
  'int_fast32_t'               =>   4,
  'int_fast64_t'               =>   8,
  'int_fast8_t'                =>   1,
  'int_least16_t'              =>   2,
  'int_least32_t'              =>   4,
  'int_least64_t'              =>   8,
  'int_least8_t'               =>   1,
  'interpreter'                =>   1,
  'intmax_t'                   =>   8,
  'intptr_t'                   =>   4,
  'io'                         =>  12,
  'iovec'                      =>   8,
  'ip_mreq'                    =>   8,
  'ip_mreqn'                   =>  12,
  'ip_opts'                    =>  44,
  'ipc_perm'                   =>  36,
  'ipv6_mreq'                  =>  20,
  'itimerspec'                 =>  16,
  'itimerval'                  =>  16,
  'jmp_buf'                    => 156,
  'jmpenv'                     => 165,
  'key_t'                      =>   4,
  'lconv'                      =>  54,
  'ldiv_t'                     =>   8,
  'line_t'                     =>   2,
  'linger'                     =>   8,
  'listop'                     =>  30,
  'lldiv_t'                    =>  16,
  'loff_t'                     =>   8,
  'logop'                      =>  30,
  'loop'                       =>  42,
  'magic'                      =>  24,
  'mcontext_t'                 =>  88,
  'mgvtbl'                     =>  20,
  'mode_t'                     =>   4,
  'msghdr'                     =>  28,
  'netent'                     =>  16,
  'nlink_t'                    =>   4,
  'off64_t'                    =>   8,
  'off_t'                      =>   4,
  'op'                         =>  22,
  'opcode'                     =>   2,
  'osockaddr'                  =>  16,
  'padop'                      =>  26,
  'perl_mstats'                =>  72,
  'pid_t'                      =>   4,
  'pmop'                       =>  51,
  'protoent'                   =>  12,
  'pthread_attr_t'             =>  36,
  'pthread_barrier_t'          =>  20,
  'pthread_barrierattr_t'      =>   4,
  'pthread_cond_t'             =>  12,
  'pthread_condattr_t'         =>   4,
  'pthread_key_t'              =>   4,
  'pthread_mutex_t'            =>  24,
  'pthread_mutexattr_t'        =>   4,
  'pthread_once_t'             =>   4,
  'pthread_rwlock_t'           =>  32,
  'pthread_rwlockattr_t'       =>   8,
  'pthread_spinlock_t'         =>   4,
  'pthread_t'                  =>   4,
  'ptr_tbl'                    =>  12,
  'ptr_tbl_ent'                =>  12,
  'ptrdiff_t'                  =>   4,
  'pvop'                       =>  26,
  'quad_t'                     =>   8,
  'random_data'                =>  28,
  're_intuit_start_t'          =>   4,
  're_intuit_string_t'         =>   4,
  'regcomp_t'                  =>   4,
  'regexec_t'                  =>   4,
  'regexp'                     =>  60,
  'regfree_t'                  =>   4,
  'register_t'                 =>   4,
  'regnode'                    =>   4,
  'rpcent'                     =>  12,
  'runops_proc_t'              =>   4,
  'sa_family_t'                =>   2,
  'sembuf'                     =>   6,
  'semid_ds'                   =>  64,
  'seminfo'                    =>  40,
  'semun'                      =>   4,
  'servent'                    =>  16,
  'sig_atomic_t'               =>   4,
  'sig_t'                      =>   4,
  'sigaction'                  => 140,
  'sigaltstack'                =>  12,
  'sigcontext'                 =>  88,
  'sigevent'                   =>  64,
  'sigevent_t'                 =>  64,
  'sighandler_t'               =>   4,
  'siginfo'                    => 128,
  'siginfo_t'                  => 128,
  'sigjmp_buf'                 => 156,
  'sigset_t'                   => 128,
  'sigstack'                   =>   8,
  'sigval'                     =>   4,
  'sigval_t'                   =>   4,
  'sigvec'                     =>  12,
  'size_t'                     =>   4,
  'sockaddr'                   =>  16,
  'sockaddr_in'                =>  16,
  'sockaddr_in6'               =>  28,
  'sockaddr_storage'           => 126,
  'socklen_t'                  =>   4,
  'ssize_t'                    =>   4,
  'stack_t'                    =>  12,
  'stackinfo'                  =>  32,
  'stat'                       =>  84,
  'stat64'                     =>  96,
  'subst'                      =>  50,
  'suseconds_t'                =>   4,
  'sv'                         =>  12,
  'svop'                       =>  26,
  'svtype'                     =>   1,
  'termio'                     =>  17,
  'time_t'                     =>   4,
  'timer_t'                    =>   4,
  'timespec'                   =>   8,
  'timeval'                    =>   8,
  'timezone'                   =>   8,
  'tm'                         =>  44,
  'tms'                        =>  16,
  'u_char'                     =>   1,
  'u_int'                      =>   4,
  'u_int16_t'                  =>   2,
  'u_int32_t'                  =>   4,
  'u_int8_t'                   =>   1,
  'u_long'                     =>   4,
  'u_quad_t'                   =>   8,
  'u_short'                    =>   2,
  'ucontext'                   => 348,
  'ucontext_t'                 => 348,
  'ucred'                      =>  12,
  'ufuncs'                     =>  12,
  'uid_t'                      =>   4,
  'uint'                       =>   4,
  'uint16_t'                   =>   2,
  'uint32_t'                   =>   4,
  'uint64_t'                   =>   8,
  'uint8_t'                    =>   1,
  'uint_fast16_t'              =>   4,
  'uint_fast32_t'              =>   4,
  'uint_fast64_t'              =>   8,
  'uint_fast8_t'               =>   1,
  'uint_least16_t'             =>   2,
  'uint_least32_t'             =>   4,
  'uint_least64_t'             =>   8,
  'uint_least8_t'              =>   1,
  'uintmax_t'                  =>   8,
  'uintptr_t'                  =>   4,
  'ulong'                      =>   4,
  'unop'                       =>  26,
  'useconds_t'                 =>   4,
  'ushort'                     =>   2,
  'va_list'                    =>   4,
  'wait'                       =>   4,
  'wchar_t'                    =>   4,
  'winsize'                    =>   8,
  'wint_t'                     =>   4,
  'xpv'                        =>  12,
  'xpvav'                      =>  41,
  'xpvbm'                      =>  39,
  'xpvcv'                      =>  74,
  'xpvfm'                      =>  78,
  'xpvgv'                      =>  49,
  'xpvhv'                      =>  48,
  'xpvio'                      =>  88,
  'xpviv'                      =>  16,
  'xpvlv'                      =>  45,
  'xpvmg'                      =>  32,
  'xpvnv'                      =>  24,
  'xpvuv'                      =>  16,
  'xrv'                        =>   4,
);
