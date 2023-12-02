#pragma once

#define SCRIPT_HELP_HELP        4004
#define SCRIPT_EXIT_HELP        4005
#define SCRIPT_OPEN_HELP11      4006
#define SCRIPT_CLOSE_HELP       4007
#define SCRIPT_SESSION_HELP     4008
#define SCRIPT_PWD_HELP         4009
#define SCRIPT_CD_HELP          4010
#define SCRIPT_LS_HELP2         4011
#define SCRIPT_LPWD_HELP        4012
#define SCRIPT_LCD_HELP         4013
#define SCRIPT_LLS_HELP2        4014
#define SCRIPT_RM_HELP2         4015
#define SCRIPT_RMDIR_HELP       4016
#define SCRIPT_MV_HELP2         4017
#define SCRIPT_CHMOD_HELP2      4018
#define SCRIPT_LN_HELP          4019
#define SCRIPT_MKDIR_HELP       4020
#define SCRIPT_GET_HELP8        4021
#define SCRIPT_PUT_HELP8        4022
#define SCRIPT_OPTION_HELP7     4023
#define SCRIPT_SYNCHRONIZE_HELP7 4424
#define SCRIPT_KEEPUPTODATE_HELP5 4425
#define SCRIPT_CALL_HELP2       4426
#define SCRIPT_ECHO_HELP        4427
#define SCRIPT_STAT_HELP        4428
#define SCRIPT_CHECKSUM_HELP    4429
#define SCRIPT_CP_HELP          4430

#define CORE_ERROR_STRINGS      4100
#define KEY_NOT_VERIFIED        4101
#define CONNECTION_FAILED       4102
#define USER_TERMINATED         4103
#define LOST_CONNECTION         4104
#define CANT_DETECT_RETURN_CODE 4105
#define COMMAND_FAILED2         4106
#define COMMAND_FAILED_CODEONLY 4107
#define INVALID_OUTPUT_ERROR    4108
#define READ_CURRENT_DIR_ERROR  4109
#define SKIP_STARTUP_MESSAGE_ERROR 4110
#define CHANGE_DIR_ERROR        4111
#define LIST_DIR_ERROR          4113
#define LIST_LINE_ERROR         4114
#define RIGHTS_ERROR            4115
#define CLEANUP_CONFIG_ERROR    4116
#define CLEANUP_CACHES_ERROR    4117
#define CLEANUP_SEEDFILE_ERROR  4118
#define CLEANUP_SESSIONS_ERROR  4119
#define DETECT_RETURNVAR_ERROR  4120
#define LOOKUP_GROUPS_ERROR     4121
#define FILE_NOT_EXISTS         4122
#define CANT_GET_ATTRS          4123
#define OPENFILE_ERROR          4124
#define READ_ERROR              4125
#define COPY_FATAL              4126
#define TOREMOTE_COPY_ERROR     4127
#define TOLOCAL_COPY_ERROR      4128
#define SCP_EMPTY_LINE          4129
#define SCP_ILLEGAL_TIME_FORMAT 4130
#define SCP_INVALID_CONTROL_RECORD 4131
#define COPY_ERROR              4132
#define SCP_ILLEGAL_FILE_DESCRIPTOR 4133
#define NOT_DIRECTORY_ERROR     4134
#define CREATE_DIR_ERROR        4135
#define CREATE_FILE_ERROR       4136
#define WRITE_ERROR             4137
#define CANT_SET_ATTRS          4138
#define REMOTE_ERROR            4139
#define DELETE_FILE_ERROR       4140
#define LOG_GEN_ERROR           4141
#define LOG_OPENERROR           4142
#define RENAME_FILE_ERROR       4143
#define RENAME_CREATE_FILE_EXISTS 4144
#define RENAME_CREATE_DIR_EXISTS 4145
#define CHANGE_HOMEDIR_ERROR    4146
#define UNALIAS_ALL_ERROR       4147
#define UNSET_NATIONAL_ERROR    4149
#define FIRST_LINE_EXPECTED     4150
#define CLEANUP_INIFILE_ERROR   4151
#define AUTHENTICATION_LOG      4153
#define AUTHENTICATION_FAILED   4154
#define NOT_CONNECTED           4155
#define SAVE_KEY_ERROR          4156
#define SSH_EXITCODE            4158
#define SFTP_INVALID_TYPE       4159
#define SFTP_VERSION_NOT_SUPPORTED 4160
#define SFTP_MESSAGE_NUMBER     4161
#define SFTP_STATUS_OK          4162
#define SFTP_STATUS_EOF         4163
#define SFTP_STATUS_NO_SUCH_FILE 4164
#define SFTP_STATUS_PERMISSION_DENIED 4165
#define SFTP_STATUS_FAILURE     4166
#define SFTP_STATUS_BAD_MESSAGE 4167
#define SFTP_STATUS_NO_CONNECTION 4168
#define SFTP_STATUS_CONNECTION_LOST 4169
#define SFTP_STATUS_OP_UNSUPPORTED 4170
#define SFTP_ERROR_FORMAT3      4171
#define SFTP_STATUS_UNKNOWN     4172
#define READ_SYMLINK_ERROR      4173
#define EMPTY_DIRECTORY         4174
#define SFTP_NON_ONE_FXP_NAME_PACKET 4175
#define SFTP_REALPATH_ERROR     4176
#define CHANGE_PROPERTIES_ERROR 4177
#define SFTP_INITIALIZE_ERROR   4178
#define TIMEZONE_ERROR          4179
#define SFTP_CREATE_FILE_ERROR  4180
#define SFTP_OPEN_FILE_ERROR    4181
#define SFTP_CLOSE_FILE_ERROR   4182
#define NOT_FILE_ERROR          4183
#define RENAME_AFTER_RESUME_ERROR 4184
#define CREATE_LINK_ERROR       4185
#define INVALID_SHELL_COMMAND   4186
#define SFTP_SERVER_MESSAGE_UNSUPPORTED 4187
#define INVALID_OCTAL_PERMISSIONS 4188
#define SFTP_INVALID_EOL        4189
#define SFTP_UNKNOWN_FILE_TYPE  4190
#define SFTP_STATUS_INVALID_HANDLE 4191
#define SFTP_STATUS_NO_SUCH_PATH 4192
#define SFTP_STATUS_FILE_ALREADY_EXISTS 4193
#define SFTP_STATUS_WRITE_PROTECT 4194
#define SFTP_STATUS_NO_MEDIA    4195
#define DECODE_UTF_ERROR        4196
#define CUSTOM_COMMAND_ERROR    4197
#define LOCALE_LOAD_ERROR       4198
#define SFTP_INCOMPLETE_BEFORE_EOF 4199
#define CALCULATE_SIZE_ERROR    4200
#define SFTP_PACKET_TOO_BIG     4201
#define SCP_INIT_ERROR          4202
#define DUPLICATE_BOOKMARK      4203
#define MOVE_FILE_ERROR         4204
#define SFTP_PACKET_TOO_BIG_INIT_EXPLAIN 4205
#define PRESERVE_TIME_PERM_ERROR3 4206
#define ACCESS_VIOLATION_ERROR3 4207
#define SFTP_STATUS_NO_SPACE_ON_FILESYSTEM 4208
#define SFTP_STATUS_QUOTA_EXCEEDED 4209
#define SFTP_STATUS_UNKNOWN_PRINCIPAL 4210
#define COPY_FILE_ERROR         4211
#define CUSTOM_COMMAND_UNTERMINATED 4212
#define CUSTOM_COMMAND_UNKNOWN  4213
#define CUSTOM_COMMAND_FILELIST_ERROR 4214
#define SCRIPT_COMMAND_UNKNOWN  4215
#define SCRIPT_COMMAND_AMBIGUOUS 4216
#define SCRIPT_MISSING_PARAMS   4217
#define SCRIPT_TOO_MANY_PARAMS  4218
#define SCRIPT_NO_SESSION       4223
#define SCRIPT_SESSION_INDEX_INVALID 4224
#define SCRIPT_OPTION_UNKNOWN   4225
#define SCRIPT_VALUE_UNKNOWN    4226
#define UNKNOWN_SOCKET_STATUS   4227
#define DELETE_ON_RESUME_ERROR  4228
#define SFTP_PACKET_ERROR       4229
#define ITEM_NAME_INVALID       4230
#define SFTP_STATUS_LOCK_CONFLICT 4231
#define SFTP_STATUS_DIR_NOT_EMPTY 4232
#define SFTP_STATUS_NOT_A_DIRECTORY 4233
#define SFTP_STATUS_INVALID_FILENAME 4234
#define SFTP_STATUS_LINK_LOOP   4235
#define SFTP_STATUS_CANNOT_DELETE 4236
#define SFTP_STATUS_INVALID_PARAMETER 4237
#define SFTP_STATUS_FILE_IS_A_DIRECTORY 4238
#define SFTP_STATUS_BYTE_RANGE_LOCK_CONFLICT 4239
#define SFTP_STATUS_BYTE_RANGE_LOCK_REFUSED 4240
#define SFTP_STATUS_DELETE_PENDING 4241
#define SFTP_STATUS_FILE_CORRUPT 4242
#define KEY_TYPE_UNKNOWN2       4243
#define KEY_TYPE_UNSUPPORTED2   4244
#define KEY_TYPE_SSH1           4245
#define SFTP_OVERWRITE_FILE_ERROR2 4246
#define SFTP_OVERWRITE_DELETE_BUTTON 4247
#define SPACE_AVAILABLE_ERROR   4248
#define TUNNEL_NO_FREE_PORT     4249
#define EVENT_SELECT_ERROR      4250
#define UNEXPECTED_CLOSE_ERROR  4251
#define TUNNEL_ERROR            4252
#define CHECKSUM_ERROR          4253
#define INTERNAL_ERROR          4254
#define NOTSUPPORTED            4255
#define FTP_ACCESS_DENIED       4256
#define FTP_CREDENTIAL_PROMPT   4257
#define FTP_RESPONSE_ERROR      4258
#define SCRIPT_UNKNOWN_SWITCH   4260
#define TRANSFER_ERROR          4261
#define EXECUTE_APP_ERROR       4262
#define FILE_NOT_FOUND          4263
#define DOCUMENT_WAIT_ERROR     4264
#define SPEED_INVALID           4265
#define CERT_ERR_CERT_CHAIN_TOO_LONG 4266
#define CERT_ERR_CERT_HAS_EXPIRED 4267
#define CERT_ERR_CERT_NOT_YET_VALID 4268
#define CERT_ERR_CERT_REJECTED  4269
#define CERT_ERR_CERT_SIGNATURE_FAILURE 4270
#define CERT_ERR_CERT_UNTRUSTED 4271
#define CERT_ERR_DEPTH_ZERO_SELF_SIGNED_CERT 4272
#define CERT_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD 4273
#define CERT_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD 4274
#define CERT_ERR_INVALID_CA     4275
#define CERT_ERR_INVALID_PURPOSE 4276
#define CERT_ERR_KEYUSAGE_NO_CERTSIGN 4277
#define CERT_ERR_PATH_LENGTH_EXCEEDED 4278
#define CERT_ERR_SELF_SIGNED_CERT_IN_CHAIN 4279
#define CERT_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY 4280
#define CERT_ERR_UNABLE_TO_DECRYPT_CERT_SIGNATURE 4281
#define CERT_ERR_UNABLE_TO_GET_ISSUER_CERT 4282
#define CERT_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY 4283
#define CERT_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE 4284
#define CERT_ERR_UNKNOWN        4285
#define CERT_ERRDEPTH           4286
#define MASK_ERROR              4288
#define FTP_CANNOT_OPEN_ACTIVE_CONNECTION2 4289
#define CORE_DELETE_LOCAL_FILE_ERROR 4290
#define URL_OPTION_BOOL_VALUE_ERROR 4291
#define CANNOT_OPEN_SESSION_FOLDER 4293
#define NET_TRANSL_NO_ROUTE2    4294
#define NET_TRANSL_CONN_ABORTED 4295
#define NET_TRANSL_HOST_NOT_EXIST2 4296
#define NET_TRANSL_PACKET_GARBLED 4297
#define REPORT_ERROR            4298
#define TLS_CERT_DECODE_ERROR   4299
#define FIND_FILE_ERROR         4700
#define CERT_NAME_MISMATCH      4701
#define SCRIPT_MATCH_NO_MATCH   4702
#define CERT_ERR_BAD_CHAIN      4703
#define CERT_OK                 4704
#define REQUEST_REDIRECTED      4705
#define TOO_MANY_REDIRECTS      4706
#define REDIRECT_LOOP           4707
#define INVALID_URL             4708
#define PROXY_AUTHENTICATION_FAILED 4709
#define CONFIGURED_KEY_NOT_MATCH 4710
#define SFTP_STATUS_OWNER_INVALID 4711
#define SFTP_STATUS_GROUP_INVALID 4712
#define SFTP_STATUS_NO_MATCHING_BYTE_RANGE_LOCK 4713
#define KEY_TYPE_UNOPENABLE     4714
#define UNKNOWN_CHECKSUM        4715
#define ALG_NOT_VERIFIED        4716
#define SFTP_STATUS_4           4718
#define CERTIFICATE_OPEN_ERROR  4719
#define CERTIFICATE_READ_ERROR  4720
#define CERTIFICATE_DECODE_ERROR_INFO 4721
#define CERTIFICATE_DECODE_ERROR 4722
#define CERTIFICATE_PUBLIC_KEY_NOT_FOUND 4723
#define LOCK_FILE_ERROR         4724
#define UNLOCK_FILE_ERROR       4725
#define NOT_LOCKED              4726
#define KEY_SAVE_ERROR          4727
#define NEON_INIT_FAILED2       4728
#define SCRIPT_AMBIGUOUS_SLASH_IN_PATH 4729
#define CERT_IP_CANNOT_VERIFY   4730
#define HOSTKEY_NOT_CONFIGURED  4731
#define UNENCRYPTED_REDIRECT    4732
#define HTTP_ERROR2             4733
#define FILEZILLA_SITE_MANAGER_NOT_FOUND 4734
#define FILEZILLA_NO_SITES      4735
#define FILEZILLA_SITE_NOT_EXIST 4736
#define SFTP_AS_FTP_ERROR       4737
#define LOG_FATAL_ERROR         4738
#define SIZE_INVALID            4739
#define KNOWN_HOSTS_NOT_FOUND   4740
#define KNOWN_HOSTS_NO_SITES    4741
#define HOSTKEY_NOT_MATCH_CLIPBOARD 4742
#define S3_ERROR_RESOURCE       4743
#define S3_ERROR_FURTHER_DETAILS 4744
#define S3_ERROR_EXTRA_DETAILS  4745
#define S3_STATUS_ACCESS_DENIED 4746
#define UNKNOWN_FILE_ENCRYPTION 4747
#define INVALID_ENCRYPT_KEY     4748
#define UNREQUESTED_FILE        4749
#define STORE_NEW_HOSTKEY_ERROR 4750
#define STREAM_IN_SCRIPT_ERROR  4751
#define STREAM_READ_ERROR       4752
#define S3_CONFIG_ERROR         4753
#define CREATE_TEMP_DIR_ERROR   4754
#define OPENSSH_CONFIG_NOT_FOUND 4755
#define OPENSSH_CONFIG_NO_SITES 4756
#define FTP_MALFORMED_RESPONSE  4757
#define S3_PROFILE_NOT_EXIST    4758
#define CERTIFICATE_UNOPENABLE  4759
#define CERTIFICATE_LOAD_ERROR  4760
#define PUB_KEY_UNKNOWN         4761
#define CERTIFICATE_NOT_MATCH   4762
#define CERTIFICATE_CANNOT_COMBINE 4763
#define KEYGEN_NOT_PUBLIC       4764
#define INCONSISTENT_SIZE       4765
#define CREDENTIALS_NOT_SPECIFIED 4766
#define SSH_HOST_CA_DECODE_ERROR 4767
#define SSH_HOST_CA_NO_KEY_TYPE 4768
#define SSH_HOST_CA_CERTIFICATE 4769
#define SSH_HOST_CA_INVALID     4770

#define CORE_CONFIRMATION_STRINGS 4300
#define CONFIRM_PROLONG_TIMEOUT3 4301
#define PROMPT_KEY_PASSPHRASE   4303
#define CORE_PROMPT_FILE_OVERWRITE     4304
#define DIRECTORY_OVERWRITE     4305
#define ALG_BELOW_THRESHOLD      4306
#define CIPHER_TYPE_BOTH2       4307
#define CIPHER_TYPE_CS2         4308
#define CIPHER_TYPE_SC2         4309
#define RESUME_TRANSFER2        4310
#define PARTIAL_BIGGER_THAN_SOURCE 4311
#define APPEND_OR_RESUME2       4312
#define FILE_OVERWRITE_DETAILS  4313
#define READ_ONLY_OVERWRITE     4314
#define LOCAL_FILE_OVERWRITE2   4315
#define REMOTE_FILE_OVERWRITE2  4316
#define TIMEOUT_STILL_WAITING3  4321
#define RECONNECT_BUTTON        4323
#define RENAME_BUTTON           4324
#define TUNNEL_SESSION_NAME     4327
#define PASSWORD_TITLE          4328
#define PASSPHRASE_TITLE        4329
#define SERVER_PROMPT_TITLE     4330
#define USERNAME_TITLE          4331
#define USERNAME_PROMPT2        4332
#define SERVER_PROMPT_TITLE2    4333
#define NEW_PASSWORD_TITLE      4334
#define PROMPT_PROMPT           4335
#define TIS_INSTRUCTION         4336
#define CRYPTOCARD_INSTRUCTION  4337
#define PASSWORD_PROMPT         4338
#define KEYBINTER_INSTRUCTION   4339
#define NEW_PASSWORD_CURRENT_PROMPT 4340
#define NEW_PASSWORD_NEW_PROMPT 4341
#define NEW_PASSWORD_CONFIRM_PROMPT 4342
#define TUNNEL_INSTRUCTION2     4343
#define RENAME_TITLE            4344
#define RENAME_PROMPT2          4345
#define VERIFY_CERT_PROMPT3     4346
#define VERIFY_CERT_CONTACT     4347
#define VERIFY_CERT_CONTACT_LIST 4348
#define CERT_TEXT2              4349
#define CERTIFICATE_PASSPHRASE_PROMPT 4350
#define CERTIFICATE_PASSPHRASE_TITLE 4351
#define KEY_TYPE_CONVERT4       4352
#define MULTI_FILES_TO_ONE      4353
#define KEY_EXCHANGE_ALG        4354
#define KEYKEY_TYPE             4355
#define S3_ACCESS_KEY_ID_TITLE  4356
#define S3_ACCESS_KEY_ID_PROMPT 4357
#define S3_SECRET_ACCESS_KEY_TITLE 4358
#define S3_SECRET_ACCESS_KEY_PROMPT 4359
#define DUPLICATE_FOLDER_NOT_SUPPORTED 4360
#define MISSING_TARGET_BUCKET   4361
#define TIMEOUT_ERROR           4362
#define PROXY_AUTH_TITLE        4363
#define PROXY_AUTH_USERNAME_PROMPT 4364
#define PROXY_AUTH_PASSWORD_PROMPT 4365
#define DIRECTORY_OVERWRITE_WARNING 4366
#define HOSTKEY_UNKNOWN         4367
#define HOSTKEY_SERVER          4368
#define HOSTKEY_NOT_CACHED      4369
#define HOSTKEY_NO_GUARANTEE    4370
#define HOSTKEY_SECURITY_BREACH 4371
#define HOSTKEY_TWO_EXPLANATIONS 4372
#define HOSTKEY_ADMINISTRATOR_CHANGED 4373
#define HOSTKEY_ANOTHER_COMPUTER 4374
#define HOSTKEY_FINGERPRINT     4375
#define HOSTKEY_DOESNT_MATCH    4376
#define HOSTKEY_ACCEPT_NEW      4377
#define HOSTKEY_ACCEPT_BUTTON   4378
#define HOSTKEY_ONCE_NEW        4379
#define HOSTKEY_ONCE_BUTTON     4380
#define HOSTKEY_CANCEL_NEW      4381
#define HOSTKEY_ACCEPT_CHANGE   4382
#define HOSTKEY_ONCE_CHANGE     4383
#define HOSTKEY_CANCEL_CHANGE   4384
#define HOSTKEY_CERTIFIED1      4385
#define HOSTKEY_CERTIFIED2      4386
#define HOSTKEY_CERTIFIED_DOESNT_MATCH_ALSO 4387
#define HOSTKEY_CERTIFIED_ANOTHER 4388
#define HOSTKEY_CERTIFIED_DOESNT_MATCH 4389
#define HOSTKEY_CERTIFIED_TRUST 4390

#define CORE_INFORMATION_STRINGS 4400
#define YES_STR                 4401
#define NO_STR                  4402
#define SESSION_INFO_TIP2       4403
#define VERSION2                4404
#define CLOSED_ON_COMPLETION    4405
#define SFTP_PROTOCOL_NAME2     4406
#define FS_RENAME_NOT_SUPPORTED 4407
#define SFTP_NO_EXTENSION_INFO  4408
#define SFTP_EXTENSION_INFO     4409
#define APPEND_BUTTON           4412
#define YES_TO_NEWER_BUTTON     4413
#define SCRIPT_HELP_DESC        4414
#define SCRIPT_EXIT_DESC        4415
#define SCRIPT_OPEN_DESC        4416
#define SCRIPT_CLOSE_DESC       4417
#define SCRIPT_SESSION_DESC     4418
#define SCRIPT_PWD_DESC         4419
#define SCRIPT_CD_DESC          4420
#define SCRIPT_LS_DESC          4421
#define SCRIPT_LPWD_DESC        4422
#define SCRIPT_LCD_DESC         4423
#define SCRIPT_LLS_DESC         4424
#define SCRIPT_RM_DESC          4425
#define SCRIPT_RMDIR_DESC       4426
#define SCRIPT_MV_DESC          4427
#define SCRIPT_CHMOD_DESC       4428
#define SCRIPT_LN_DESC          4429
#define SCRIPT_MKDIR_DESC       4430
#define SCRIPT_GET_DESC         4431
#define SCRIPT_PUT_DESC         4432
#define SCRIPT_OPTION_DESC      4433
#define SCRIPT_SYNCHRONIZE_DESC 4434
#define SCRIPT_KEEPUPTODATE_DESC 4435
#define SCRIPT_HOST_PROMPT      4436
#define SCRIPT_ACTIVE_SESSION   4438
#define SCRIPT_SESSION_CLOSED   4439
#define SCRIPT_SYNCHRONIZE      4440
#define SCRIPT_SYNCHRONIZE_DELETED 4441
#define SCRIPT_KEEPING_UP_TO_DATE 4442
#define SKIP_ALL_BUTTON         4443
#define SCRIPT_CALL_DESC2       4444
#define COPY_PARAM_PRESET_ASCII 4445
#define COPY_PARAM_PRESET_BINARY 4446
#define COPY_INFO_TRANSFER_TYPE2 4448
#define COPY_INFO_FILENAME      4449
#define COPY_INFO_PERMISSIONS   4450
#define COPY_INFO_ADD_X_TO_DIRS 4451
#define COPY_INFO_TIMESTAMP     4452
#define COPY_INFO_FILE_MASK     4454
#define COPY_INFO_CLEAR_ARCHIVE 4455
#define COPY_INFO_DONT_REPLACE_INV_CHARS 4456
#define COPY_INFO_DONT_PRESERVE_TIME 4458
#define COPY_INFO_DONT_CALCULATE_SIZE 4459
#define COPY_INFO_DEFAULT       4460
#define COPY_RULE_HOSTNAME      4461
#define COPY_RULE_USERNAME      4462
#define COPY_RULE_REMOTE_DIR    4463
#define COPY_RULE_LOCAL_DIR     4464
#define SYNCHRONIZE_SCAN        4465
#define SYNCHRONIZE_START       4466
#define SYNCHRONIZE_CHANGE      4467
#define SYNCHRONIZE_UPLOADED    4468
#define SYNCHRONIZE_DELETED     4469
#define COPY_INFO_NOT_USABLE    4470
#define COPY_INFO_IGNORE_PERM_ERRORS 4472
#define AUTH_TRANSL_USERNAME    4473
#define AUTH_TRANSL_KEYB_INTER  4474
#define AUTH_TRANSL_PUBLIC_KEY  4475
#define AUTH_TRANSL_WRONG_PASSPHRASE 4476
#define AUTH_TRANSL_ACCESS_DENIED 4477
#define AUTH_TRANSL_PUBLIC_KEY_AGENT 4478
#define AUTH_TRANSL_TRY_PUBLIC_KEY 4479
#define AUTH_PASSWORD           4480
#define OPEN_TUNNEL             4481
#define STATUS_CLOSED           4482
#define STATUS_LOOKUPHOST       4484
#define STATUS_CONNECT          4485
#define STATUS_AUTHENTICATE     4486
#define STATUS_AUTHENTICATED    4487
#define STATUS_STARTUP          4488
#define STATUS_OPEN_DIRECTORY   4489
#define STATUS_READY            4490
#define USING_TUNNEL            4491
#define AUTH_TRANSL_KEY_REFUSED 4492
#define PFWD_TRANSL_ADMIN       4493
#define PFWD_TRANSL_CONNECT     4494
#define NET_TRANSL_REFUSED2     4495
#define NET_TRANSL_RESET        4496
#define NET_TRANSL_TIMEOUT2     4497
#define SESSION_INFO_TIP_NO_SSH 4498
#define RESUME_BUTTON           4499
#define FTP_NO_FEATURE_INFO     4500
#define FTP_FEATURE_INFO        4501
#define COPY_INFO_CPS_LIMIT2    4502
#define COPY_KEY_BUTTON         4503
#define UPDATE_KEY_BUTTON       4504
#define ADD_KEY_BUTTON          4505
#define COPY_INFO_PRESERVE_READONLY 4506
#define SCRIPT_SYNCHRONIZE_COLLECTING 4507
#define SCRIPT_SYNCHRONIZE_SYNCHRONIZING 4508
#define SCRIPT_SYNCHRONIZE_NODIFFERENCE 4509
#define SPEED_UNLIMITED         4510
#define FTPS_IMPLICIT           4511
#define FTPS_EXPLICIT           4513
#define SCRIPT_ECHO_DESC        4514
#define SCRIPT_STAT_DESC        4515
#define HOSTKEY                 4516
#define SCRIPT_FILEMASK_INCLUDE_EXCLUDE 4517
#define COPY_PARAM_NEWER_ONLY    4518
#define FTP_SUGGESTION          4519
#define SCRIPT_CMDLINE_SESSION  4520
#define ANY_HOSTKEY      4521
#define ANY_CERTIFICATE  4522
#define SCRIPT_SYNC_UPLOAD_NEW  4523
#define SCRIPT_SYNC_DOWNLOAD_NEW 4524
#define SCRIPT_SYNC_UPLOAD_UPDATE 4525
#define SCRIPT_SYNC_DOWNLOAD_UPDATE 4526
#define SCRIPT_SYNC_DELETE_REMOTE 4527
#define SCRIPT_SYNC_DELETE_LOCAL 4528
#define SCRIPT_SYNCHRONIZE_CHECKLIST 4529
#define COPY_INFO_REMOVE_CTRLZ  4530
#define COPY_INFO_REMOVE_BOM    4531
#define SCRIPT_NON_DEFAULT_COPY_PARAM 4532
#define SCRIPT_NON_DEFAULT_SYNC_PARAM 4533
#define VERSION_BUILD                     4535
#define VERSION_DEV_BUILD                 4536
#define VERSION_DEBUG_BUILD               4537
#define VERSION_DONT_DISTRIBUTE           4538
#define WEBDAV_EXTENSION_INFO             4539
#define COPY_PARAM_PRESET_EXCLUDE_ALL_DIR 4540
#define SCRIPT_CHECKSUM_DESC              4541
#define CLIENT_CERTIFICATE_LOADING        4543
#define NEED_CLIENT_CERTIFICATE           4544
#define LOCKED                            4545
#define EXECUTABLE                        4546
#define SCRIPT_CMDLINE_PARAMETERS         4547
#define SCRIPTING_USE_HOSTKEY             4548
#define SCRIPT_SITE_WARNING               4549
#define CODE_SESSION_OPTIONS              4550
#define CODE_CONNECT                      4551
#define CODE_PS_ADD_TYPE                  4553
#define COPY_INFO_PRESERVE_TIME_DIRS      4554
#define TEXT_FILE_ENCODING                4555
#define AND_STR                           4556
#define AUTH_CHANGING_PASSWORD            4557
#define PASTE_KEY_BUTTON                  4558
#define SCRIPT_CP_DESC                    4559
#define TIME_UNKNOWN                      4560
#define COPY_KEY_ACTION                   4562
#define COPY_CERTIFICATE_ACTION           4563
#define COPY_INFO_DONT_ENCRYPT_NEW_FILES  4564
#define COPY_INFO_EXCLUDE_HIDDEN_FILES    4565
#define COPY_INFO_EXCLUDE_EMPTY_DIRS      4566
#define PUBLIC_KEY_UPLOADED               4567
#define PUBLIC_KEY_PERMISSIONS            4568
#define TIME_RELATIVE                     4569
#define DAYS_SPAN                         4570

#define CORE_VARIABLE_STRINGS   4600
#define PUTTY_BASED_ON          4601
#define PUTTY_VERSION           4602
#define PUTTY_COPYRIGHT         4603
#define PUTTY_URL               4604
#define FILEZILLA_BASED_ON2     4605
#define FILEZILLA_VERSION       4606
#define FILEZILLA_COPYRIGHT2    4607
#define FILEZILLA_URL           4608
#define OPENSSL_BASED_ON        4609
#define OPENSSL_COPYRIGHT2      4610
#define OPENSSL_VERSION2        4611
#define OPENSSL_URL             4612
#define NEON_BASED_ON2          4613
#define NEON_COPYRIGHT          4614
#define NEON_URL                4615
#define EXPAT_BASED_ON          4616
#define EXPAT_URL               4618
#define PUTTY_LICENSE_URL       4625
#define MAIN_MSG_TAG            4631
#define INTERACTIVE_MSG_TAG     4632
#define S3_BASED_ON             4633
#define S3_COPYRIGHT            4634
#define S3_URL                  4635
#define S3_LICENSE_URL          4636

// 7xxx used by errors as secondary sequence

#define WINSCPFAR_NAME              4740
#define WINSCP_VERSION              4741
#define WINSCPFAR_VERSION           4742
#define WINSCPFAR_BASED_ON          4743
#define WINSCPFAR_BASED_VERSION     4744
#define WINSCPFAR_BASED_COPYRIGHT   4745

// #define CONVERTKEY_SAVE_TITLE   5945
// #define CONVERTKEY_SAVE_FILTER  5946
// #define CONVERTKEY_SAVED        5947

