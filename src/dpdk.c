// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/


/**
	* This file is a small equivalent to the GNU readline library, but it
	* was originally designed for small systems, like Atmel AVR
	* microcontrollers (8 bits). Indeed, we don't use any malloc that is
	* sometimes not implemented (or just not recommended) on such
	* systems.
	* Obviously, it does not support as many things as the GNU readline,
	* but at least it supports some interesting features like a kill
	* buffer and a command history.
	* It also have a feature that does not have the GNU readline (as far
	* as I know): we can have several instances of it running at the same
	* time, even on a monothread program, since it works with callbacks.
	* The lib is designed for a client-side or a server-side use:
	* - server-side: the server receives all data from a socket, including
	* - client-side: the client receives its data through its stdin for
	*/


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/


/**
	* This structure is the header of a cirbuf type.
	*/
struct cirbuf
{
	unsigned int maxlen; 


	unsigned int start; 


	unsigned int end; 


	unsigned int len; 


	char *buf;
};


/**
	* Init the circular buffer
	*/
int cirbuf_init(struct cirbuf *cbuf, char *buf, unsigned int start, unsigned int maxlen);


/**
	* Return 1 if the circular buffer is full
	*/


/**
	* Return 1 if the circular buffer is empty
	*/


/**
	* return current size of the circular buffer (number of used elements)
	*/


/**
	* return size of the circular buffer (used + free elements)
	*/


/**
	* return the number of free elts
	*/


/**
	* Iterator for a circular buffer
	*/


/**
	* Add a character at head of the circular buffer. Return 0 on success, or
	* a negative value on error.
	*/
int cirbuf_add_head_safe(struct cirbuf *cbuf, char c);


/**
	* Add a character at head of the circular buffer. You _must_ check that you
	* have enough free space in the buffer before calling this func.
	*/
void cirbuf_add_head(struct cirbuf *cbuf, char c);


/**
	* Add a character at tail of the circular buffer. Return 0 on success, or
	* a negative value on error.
	*/
int cirbuf_add_tail_safe(struct cirbuf *cbuf, char c);


/**
	* Add a character at tail of the circular buffer. You _must_ check that you
	* have enough free space in the buffer before calling this func.
	*/
void cirbuf_add_tail(struct cirbuf *cbuf, char c);


/**
	* Remove a char at the head of the circular buffer. Return 0 on
	* success, or a negative value on error.
	*/
int cirbuf_del_head_safe(struct cirbuf *cbuf);


/**
	* Remove a char at the head of the circular buffer. You _must_ check
	* that buffer is not empty before calling the function.
	*/
void cirbuf_del_head(struct cirbuf *cbuf);


/**
	* Remove a char at the tail of the circular buffer. Return 0 on
	* success, or a negative value on error.
	*/
int cirbuf_del_tail_safe(struct cirbuf *cbuf);


/**
	* Remove a char at the tail of the circular buffer. You _must_ check
	* that buffer is not empty before calling the function.
	*/
void cirbuf_del_tail(struct cirbuf *cbuf);


/**
	* Return the head of the circular buffer. You _must_ check that
	* buffer is not empty before calling the function.
	*/
char cirbuf_get_head(struct cirbuf *cbuf);


/**
	* Return the tail of the circular buffer. You _must_ check that
	* buffer is not empty before calling the function.
	*/
char cirbuf_get_tail(struct cirbuf *cbuf);


/**
	* Add a buffer at head of the circular buffer. 'c' is a pointer to a
	* buffer, and n is the number of char to add. Return the number of
	* copied bytes on success, or a negative value on error.
	*/
int cirbuf_add_buf_head(struct cirbuf *cbuf, const char *c, unsigned int n);


/**
	* Add a buffer at tail of the circular buffer. 'c' is a pointer to a
	* buffer, and n is the number of char to add. Return the number of
	* copied bytes on success, or a negative value on error.
	*/
int cirbuf_add_buf_tail(struct cirbuf *cbuf, const char *c, unsigned int n);


/**
	* Remove chars at the head of the circular buffer. Return 0 on
	* success, or a negative value on error.
	*/
int cirbuf_del_buf_head(struct cirbuf *cbuf, unsigned int size);


/**
	* Remove chars at the tail of the circular buffer. Return 0 on
	* success, or a negative value on error.
	*/
int cirbuf_del_buf_tail(struct cirbuf *cbuf, unsigned int size);


/**
	* Copy a maximum of 'size' characters from the head of the circular
	* buffer to a flat one pointed by 'c'. Return the number of copied
	* chars.
	*/
int cirbuf_get_buf_head(struct cirbuf *cbuf, char *c, unsigned int size);


/**
	* Copy a maximum of 'size' characters from the tail of the circular
	* buffer to a flat one pointed by 'c'. Return the number of copied
	* chars.
	*/
int cirbuf_get_buf_tail(struct cirbuf *cbuf, char *c, unsigned int size);


/**
	* Set the start of the data to the index 0 of the internal buffer.
	*/
int cirbuf_align_left(struct cirbuf *cbuf);


/**
	* Set the end of the data to the last index of the internal buffer.
	*/
int cirbuf_align_right(struct cirbuf *cbuf);


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/


/* Result of parsing : it must be synchronized with
	* cmdline_vt100_commands[] in vt100.c */
enum cmdline_vt100_parser_state
{
	CMDLINE_VT100_INIT,
	CMDLINE_VT100_ESCAPE,
	CMDLINE_VT100_ESCAPE_CSI
};
struct cmdline_vt100
{
	uint8_t bufpos;
	char buf[8];
	enum cmdline_vt100_parser_state state;
};


/**
	* Init
	*/
void vt100_init(struct cmdline_vt100 *vt);


/**
	* Input a new character.
	* Return -1 if the character is not part of a control sequence
	* Return -2 if c is not the last char of a control sequence
	* Else return the index in vt100_commands[]
	*/
int vt100_parser(struct cmdline_vt100 *vt, char c);



enum rdline_status
{
	RDLINE_INIT,
	RDLINE_RUNNING,
	RDLINE_EXITED
};
struct rdline;
typedef int (rdline_write_char_t)(struct rdline *rdl, char);
typedef void (rdline_validate_t)(struct rdline *rdl,
					const char *buf, unsigned int size);
typedef int (rdline_complete_t)(struct rdline *rdl, const char *buf,
				char *dstbuf, unsigned int dstsize,
				int *state);
struct rdline
{
	enum rdline_status status;


	struct cirbuf left;
	struct cirbuf right;
	char left_buf[512 +2]; 


	char right_buf[512];
	char prompt[32];
	unsigned int prompt_size;
	char kill_buf[512];
	unsigned int kill_size;


	struct cirbuf history;
	char history_buf[BUFSIZ];
	int history_cur_line;


	rdline_write_char_t *write_char;
	rdline_validate_t *validate;
	rdline_complete_t *complete;


	struct cmdline_vt100 vt100;


	void *opaque;
};


/**
	* Init fields for a struct rdline. Call this only once at the beginning
	* of your program.
	* \param rdl A pointer to an uninitialized struct rdline
	* \param write_char The function used by the function to write a character
	* \param validate A pointer to the function to execute when the
	* \param complete A pointer to the function to execute when the
	*/
int rdline_init(struct rdline *rdl,
			rdline_write_char_t *write_char,
			rdline_validate_t *validate,
			rdline_complete_t *complete);


/**
	* Init the current buffer, and display a prompt.
	* \param rdl A pointer to a struct rdline
	* \param prompt A string containing the prompt
	*/
void rdline_newline(struct rdline *rdl, const char *prompt);


/**
	* Call it and all received chars will be ignored.
	* \param rdl A pointer to a struct rdline
	*/
void rdline_stop(struct rdline *rdl);


/**
	* Same than rdline_stop() except that next calls to rdline_char_in()
	* will return RDLINE_RES_EXITED.
	* \param rdl A pointer to a struct rdline
	*/
void rdline_quit(struct rdline *rdl);


/**
	* Restart after a call to rdline_stop() or rdline_quit()
	* \param rdl A pointer to a struct rdline
	*/
void rdline_restart(struct rdline *rdl);


/**
	* Redisplay the current buffer
	* \param rdl A pointer to a struct rdline
	*/
void rdline_redisplay(struct rdline *rdl);


/**
	* Reset the current buffer and setup for a new line.
	*  \param rdl A pointer to a struct rdline
	*/
void rdline_reset(struct rdline *rdl);





/**
	* append a char to the readline buffer.
	* Return RDLINE_RES_VALIDATE when the line has been validated.
	* Return RDLINE_RES_COMPLETE when the user asked to complete the buffer.
	* Return RDLINE_RES_NOT_RUNNING if it is not running.
	* Return RDLINE_RES_EOF if EOF (ctrl-d on an empty line).
	* Else return RDLINE_RES_SUCCESS.
	* XXX error case when the buffer is full ?
	* \param rdl A pointer to a struct rdline
	* \param c The character to append
	*/
int rdline_char_in(struct rdline *rdl, char c);


/**
	* Return the current buffer, terminated by '\0'.
	* \param rdl A pointer to a struct rdline
	*/
const char *rdline_get_buffer(struct rdline *rdl);


/**
	* Add the buffer to history.
	* return < 0 on error.
	* \param rdl A pointer to a struct rdline
	* \param buf A buffer that is terminated by '\0'
	*/
int rdline_add_history(struct rdline *rdl, const char *buf);


/**
	* Clear current history
	* \param rdl A pointer to a struct rdline
	*/
void rdline_clear_history(struct rdline *rdl);


/**
	* Get the i-th history item
	*/
char *rdline_get_history_item(struct rdline *rdl, unsigned int i);


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/











/**
	* Stores a pointer to the ops struct, and the offset: the place to
	* write the parsed result in the destination structure.
	*/
struct cmdline_token_hdr
{
	struct cmdline_token_ops *ops;
	unsigned int offset;
};
typedef struct cmdline_token_hdr cmdline_parse_token_hdr_t;


/**
	* A token is defined by this structure.
	* parse() takes the token as first argument, then the source buffer
	* starting at the token we want to parse. The 3rd arg is a pointer
	* where we store the parsed data (as binary). It returns the number of
	* parsed chars on success and a negative value on error.
	* complete_get_nb() returns the number of possible values for this
	* token if completion is possible. If it is NULL or if it returns 0,
	* no completion is possible.
	* complete_get_elt() copy in dstbuf (the size is specified in the
	* parameter) the i-th possible completion for this token.  returns 0
	* on success or and a negative value on error.
	* get_help() fills the dstbuf with the help for the token. It returns
	* -1 on error and 0 on success.
	*/
struct cmdline_token_ops
{


	int (*parse)(cmdline_parse_token_hdr_t *, const char *, void *,
		unsigned int);


	int (*complete_get_nb)(cmdline_parse_token_hdr_t *);


	int (*complete_get_elt)(cmdline_parse_token_hdr_t *, int, char *,
		unsigned int);


	int (*get_help)(cmdline_parse_token_hdr_t *, char *, unsigned int);
};
struct cmdline;


/**
	* Store a instruction, which is a pointer to a callback function and
	* its parameter that is called when the instruction is parsed, a help
	* string, and a list of token composing this instruction.
	*/
struct cmdline_inst
{


	void (*f)(void *, struct cmdline *, void *);
	void *data;
	const char *help_str;
	cmdline_parse_token_hdr_t *tokens[];
};
typedef struct cmdline_inst cmdline_parse_inst_t;


/**
	* A context is identified by its name, and contains a list of
	* instruction
	*/
typedef cmdline_parse_inst_t *cmdline_parse_ctx_t;


/**
	* Try to parse a buffer according to the specified context. The
	* argument buf must ends with "\n\0". The function returns
	* CMDLINE_PARSE_AMBIGUOUS, CMDLINE_PARSE_NOMATCH or
	* CMDLINE_PARSE_BAD_ARGS on error. Else it calls the associated
	* function (defined in the context) and returns 0
	* (CMDLINE_PARSE_SUCCESS).
	*/
int cmdline_parse(struct cmdline *cl, const char *buf);


/**
	* complete() must be called with *state==0 (try to complete) or
	* with *state==-1 (just display choices), then called without
	* modifying *state until it returns CMDLINE_PARSE_COMPLETED_BUFFER or
	* CMDLINE_PARSE_COMPLETED_BUFFER.
	* It returns < 0 on error.
	* Else it returns:
	* The returned dst buf ends with \0.
	*/
int cmdline_complete(struct cmdline *cl, const char *buf, int *state,
						 char *dst, unsigned int size);


/* return true if(!c || iscomment(c) || isblank(c) ||
	* isendofline(c)) */
int cmdline_isendoftoken(char c);



int cmdline_isendofcommand(char c);


/**
	* @file
	* Command line API
	*/
struct cmdline
{
	int s_in;
	int s_out;
	cmdline_parse_ctx_t *ctx;
	struct rdline rdl;
	char prompt[32];
	struct termios oldterm;
};
struct cmdline *cmdline_new(cmdline_parse_ctx_t *ctx, const char *prompt, int s_in, int s_out);
void cmdline_set_prompt(struct cmdline *cl, const char *prompt);
void cmdline_free(struct cmdline *cl);
void cmdline_printf(const struct cmdline *cl, const char *fmt, ...)
	__attribute__((format(printf,2,3)));
int cmdline_in(struct cmdline *cl, const char *buf, int size);
int cmdline_write_char(struct rdline *rdl, char c);


/**
	* This function is nonblocking equivalent of ``cmdline_interact()``. It polls
	* *cl* for one character and interpret it. If return value is *RDLINE_EXITED*
	* it mean that ``cmdline_quit()`` was invoked.
	* @param cl
	* @return
	*/
int cmdline_poll(struct cmdline *cl);
void cmdline_interact(struct cmdline *cl);
void cmdline_quit(struct cmdline *cl);


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/
struct cmdline_token_etheraddr
{
	struct cmdline_token_hdr hdr;
};
typedef struct cmdline_token_etheraddr cmdline_parse_token_etheraddr_t;
int cmdline_parse_etheraddr(cmdline_parse_token_hdr_t *tk, const char *srcbuf,
	void *res, unsigned ressize);
int cmdline_get_help_etheraddr(cmdline_parse_token_hdr_t *tk, char *dstbuf,
	unsigned int size);


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/
struct cmdline_ipaddr
{
	uint8_t family;
	union
{
		struct in_addr ipv4;
		struct in6_addr ipv6;
	} addr;
	unsigned int prefixlen; 


};
typedef struct cmdline_ipaddr cmdline_ipaddr_t;
struct cmdline_token_ipaddr_data
{
	uint8_t flags;
};
struct cmdline_token_ipaddr
{
	struct cmdline_token_hdr hdr;
	struct cmdline_token_ipaddr_data ipaddr_data;
};
typedef struct cmdline_token_ipaddr cmdline_parse_token_ipaddr_t;
int cmdline_parse_ipaddr(cmdline_parse_token_hdr_t *tk, const char *srcbuf,
	void *res, unsigned ressize);
int cmdline_get_help_ipaddr(cmdline_parse_token_hdr_t *tk, char *dstbuf,
	unsigned int size);


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/
enum cmdline_numtype
{
	UINT8 = 0,
	UINT16,
	UINT32,
	UINT64,
	INT8,
	INT16,
	INT32,
	INT64
};
struct cmdline_token_num_data
{
	enum cmdline_numtype type;
};
struct cmdline_token_num
{
	struct cmdline_token_hdr hdr;
	struct cmdline_token_num_data num_data;
};
typedef struct cmdline_token_num cmdline_parse_token_num_t;
int cmdline_parse_num(cmdline_parse_token_hdr_t *tk,
	const char *srcbuf, void *res, unsigned ressize);
int cmdline_get_help_num(cmdline_parse_token_hdr_t *tk,
	char *dstbuf, unsigned int size);


/*-
	*/


/*
	* Copyright (c) 2010, Keith Wiles <keith.wiles@windriver.com>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/



typedef struct cmdline_portlist
{
	uint32_t map;
} cmdline_portlist_t;
struct cmdline_token_portlist
{
	struct cmdline_token_hdr hdr;
};
typedef struct cmdline_token_portlist cmdline_parse_token_portlist_t;
int cmdline_parse_portlist(cmdline_parse_token_hdr_t *tk,
	const char *srcbuf, void *res, unsigned ressize);
int cmdline_get_help_portlist(cmdline_parse_token_hdr_t *tk,
	char *dstbuf, unsigned int size);


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/






typedef char cmdline_fixed_string_t[128];
typedef char cmdline_multi_string_t[4096];
struct cmdline_token_string_data
{
	const char *str;
};
struct cmdline_token_string
{
	struct cmdline_token_hdr hdr;
	struct cmdline_token_string_data string_data;
};
typedef struct cmdline_token_string cmdline_parse_token_string_t;
int cmdline_parse_string(cmdline_parse_token_hdr_t *tk, const char *srcbuf,
	void *res, unsigned ressize);
int cmdline_complete_get_nb_string(cmdline_parse_token_hdr_t *tk);
int cmdline_complete_get_elt_string(cmdline_parse_token_hdr_t *tk, int idx,
						  char *dstbuf, unsigned int size);
int cmdline_get_help_string(cmdline_parse_token_hdr_t *tk, char *dstbuf,
						 unsigned int size);


/**
* Token marked as TOKEN_STRING_MULTI takes entire parsing string
* until “#” sign appear. Everything after “#” sign is treated as a comment.
*
* Note:
* In this case second parameter of TOKEN_STRING_INITIALIZER must be a type of
* cmdline_multi_string_t.
*/


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/


/*-
	*/


/*
	* Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
	* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
	* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/
struct cmdline *cmdline_file_new(cmdline_parse_ctx_t *ctx, const char *prompt, const char *path);
struct cmdline *cmdline_stdin_new(cmdline_parse_ctx_t *ctx, const char *prompt);
void cmdline_stdin_exit(struct cmdline *cl);
// #include <rte_acl.h>   error: unknown type name '__m128i' (rte_vect.h)


/*-
	*/


/**
	* @file
	* Alarm functions
	* Simple alarm-clock functionality supplied by eal.
	* Does not require hpet support.
	*/


/**
	* Signature of callback back function called when an alarm goes off.
	*/
typedef void (*rte_eal_alarm_callback)(void *arg);


/**
	* Function to set a callback to be triggered when us microseconds
	* have expired. Accuracy of timing to the microsecond is not guaranteed. The
	* alarm function will not be called *before* the requested time, but may
	* be called a short period of time afterwards.
	* The alarm handler will be called only once. There is no need to call
	* "rte_eal_alarm_cancel" from within the callback function.
	* @param us
	* @param cb
	* @param cb_arg
	* @return
	*/
int rte_eal_alarm_set(uint64_t us, rte_eal_alarm_callback cb, void *cb_arg);


/**
	* Function to cancel an alarm callback which has been registered before. If
	* used outside alarm callback it wait for all callbacks to finish execution.
	* @param cb_fn
	*  alarm callback
	* @param cb_arg
	*  Pointer parameter to be passed to the callback function. To remove all
	*  copies of a given callback function, irrespective of parameter, (void *)-1
	*  can be used here.
	* @return
	*/
int rte_eal_alarm_cancel(rte_eal_alarm_callback cb_fn, void *cb_arg);


/*-
	*/


/**
	* @file
	* RTE Rational Approximation
	* Given a rational number alpha with 0 < alpha < 1 and a precision d, the goal
	* is to find positive integers p, q such that alpha - d < p/q < alpha + d, and
	* q is minimal.
	***/


/**
	* Find best rational approximation
	* @param alpha
	* @param d
	* @param p
	* @param q
	* @return
	*/
int rte_approx(double alpha, double d, uint32_t *p, uint32_t *q);


/*   BSD LICENSE
	*/


/**
	* @file
	* ARP-related defines
	*/


/*-
	*/


/**
	* @file
	* Ethernet Helpers in RTE
	*/


/*-
	*/


/**
	* @file
	* Functions for SSE/AVX/AVX2/AVX512 implementation of memcpy().
	*/


/*-
	*/


/**
	* @file
	* RTE SSE/AVX related header.
	*/
typedef __m128i xmm_t;
typedef union rte_xmm
{
	xmm_t x;
	uint8_t u8[(sizeof(xmm_t)) / sizeof(uint8_t)];
	uint16_t u16[(sizeof(xmm_t)) / sizeof(uint16_t)];
	uint32_t u32[(sizeof(xmm_t)) / sizeof(uint32_t)];
	uint64_t u64[(sizeof(xmm_t)) / sizeof(uint64_t)];
	double pd[(sizeof(xmm_t)) / sizeof(double)];
} rte_xmm_t;


/*
	* Prior to version 12.1 icc doesn't support _mm_set_epi64x.
	*/


/**
	* Copy bytes from one location to another. The locations must not overlap.
	* @note This is implemented as a macro, so it's address should not be taken
	* and care is needed as parameter expressions may be evaluated multiple times.
	* @param dst
	* @param src
	* @param n
	* @return
	*/
static inline void *
rte_memcpy(void *dst, const void *src, size_t n) __attribute__((always_inline));


/**
	* SSE & AVX implementation below
	*/


/**
	* Copy 16 bytes from one location to another,
	* locations should not overlap.
	*/
static inline void
rte_mov16(uint8_t *dst, const uint8_t *src)
{
	__m128i xmm0;
	xmm0 = _mm_loadu_si128((const __m128i *)(const __m128i *)src);
	_mm_storeu_si128((__m128i *)dst, xmm0);
}


/**
	* Copy 32 bytes from one location to another,
	* locations should not overlap.
	*/
static inline void
rte_mov32(uint8_t *dst, const uint8_t *src)
{
	rte_mov16((uint8_t *)dst + 0 * 16, (const uint8_t *)src + 0 * 16);
	rte_mov16((uint8_t *)dst + 1 * 16, (const uint8_t *)src + 1 * 16);
}


/**
	* Copy 64 bytes from one location to another,
	* locations should not overlap.
	*/
static inline void
rte_mov64(uint8_t *dst, const uint8_t *src)
{
	rte_mov16((uint8_t *)dst + 0 * 16, (const uint8_t *)src + 0 * 16);
	rte_mov16((uint8_t *)dst + 1 * 16, (const uint8_t *)src + 1 * 16);
	rte_mov16((uint8_t *)dst + 2 * 16, (const uint8_t *)src + 2 * 16);
	rte_mov16((uint8_t *)dst + 3 * 16, (const uint8_t *)src + 3 * 16);
}


/**
	* Copy 128 bytes from one location to another,
	* locations should not overlap.
	*/
static inline void
rte_mov128(uint8_t *dst, const uint8_t *src)
{
	rte_mov16((uint8_t *)dst + 0 * 16, (const uint8_t *)src + 0 * 16);
	rte_mov16((uint8_t *)dst + 1 * 16, (const uint8_t *)src + 1 * 16);
	rte_mov16((uint8_t *)dst + 2 * 16, (const uint8_t *)src + 2 * 16);
	rte_mov16((uint8_t *)dst + 3 * 16, (const uint8_t *)src + 3 * 16);
	rte_mov16((uint8_t *)dst + 4 * 16, (const uint8_t *)src + 4 * 16);
	rte_mov16((uint8_t *)dst + 5 * 16, (const uint8_t *)src + 5 * 16);
	rte_mov16((uint8_t *)dst + 6 * 16, (const uint8_t *)src + 6 * 16);
	rte_mov16((uint8_t *)dst + 7 * 16, (const uint8_t *)src + 7 * 16);
}


/**
	* Copy 256 bytes from one location to another,
	* locations should not overlap.
	*/
static inline void
rte_mov256(uint8_t *dst, const uint8_t *src)
{
	rte_mov16((uint8_t *)dst + 0 * 16, (const uint8_t *)src + 0 * 16);
	rte_mov16((uint8_t *)dst + 1 * 16, (const uint8_t *)src + 1 * 16);
	rte_mov16((uint8_t *)dst + 2 * 16, (const uint8_t *)src + 2 * 16);
	rte_mov16((uint8_t *)dst + 3 * 16, (const uint8_t *)src + 3 * 16);
	rte_mov16((uint8_t *)dst + 4 * 16, (const uint8_t *)src + 4 * 16);
	rte_mov16((uint8_t *)dst + 5 * 16, (const uint8_t *)src + 5 * 16);
	rte_mov16((uint8_t *)dst + 6 * 16, (const uint8_t *)src + 6 * 16);
	rte_mov16((uint8_t *)dst + 7 * 16, (const uint8_t *)src + 7 * 16);
	rte_mov16((uint8_t *)dst + 8 * 16, (const uint8_t *)src + 8 * 16);
	rte_mov16((uint8_t *)dst + 9 * 16, (const uint8_t *)src + 9 * 16);
	rte_mov16((uint8_t *)dst + 10 * 16, (const uint8_t *)src + 10 * 16);
	rte_mov16((uint8_t *)dst + 11 * 16, (const uint8_t *)src + 11 * 16);
	rte_mov16((uint8_t *)dst + 12 * 16, (const uint8_t *)src + 12 * 16);
	rte_mov16((uint8_t *)dst + 13 * 16, (const uint8_t *)src + 13 * 16);
	rte_mov16((uint8_t *)dst + 14 * 16, (const uint8_t *)src + 14 * 16);
	rte_mov16((uint8_t *)dst + 15 * 16, (const uint8_t *)src + 15 * 16);
}


/**
	* Macro for copying unaligned block from one location to another with constant load offset,
	* 47 bytes leftover maximum,
	* locations should not overlap.
	* Requirements:
	* - Store is aligned
	* - Load offset is <offset>, which must be immediate value within [1, 15]
	* - For <src>, make sure <offset> bit backwards & <16 - offset> bit forwards are available for loading
	* - <dst>, <src>, <len> must be variables
	* - __m128i <xmm0> ~ <xmm8> must be pre-defined
	*/


/**
	* Macro for copying unaligned block from one location to another,
	* 47 bytes leftover maximum,
	* locations should not overlap.
	* Use switch here because the aligning instruction requires immediate value for shift count.
	* Requirements:
	* - Store is aligned
	* - Load offset is <offset>, which must be within [1, 15]
	* - For <src>, make sure <offset> bit backwards & <16 - offset> bit forwards are available for loading
	* - <dst>, <src>, <len> must be variables
	* - __m128i <xmm0> ~ <xmm8> used in MOVEUNALIGNED_LEFT47_IMM must be pre-defined
	*/
static inline void *
rte_memcpy(void *dst, const void *src, size_t n)
{
	__m128i xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xmm8;
	uintptr_t dstu = (uintptr_t)dst;
	uintptr_t srcu = (uintptr_t)src;
	void *ret = dst;
	size_t dstofss;
	size_t srcofs;

/**
	 * Copy less than 16 bytes
	 */
	if (n < 16)
{
		if (n & 0x01)
{
			*(uint8_t *)dstu = *(const uint8_t *)srcu;
			srcu = (uintptr_t)((const uint8_t *)srcu + 1);
			dstu = (uintptr_t)((uint8_t *)dstu + 1);
		}
		if (n & 0x02)
{
			*(uint16_t *)dstu = *(const uint16_t *)srcu;
			srcu = (uintptr_t)((const uint16_t *)srcu + 1);
			dstu = (uintptr_t)((uint16_t *)dstu + 1);
		}
		if (n & 0x04)
{
			*(uint32_t *)dstu = *(const uint32_t *)srcu;
			srcu = (uintptr_t)((const uint32_t *)srcu + 1);
			dstu = (uintptr_t)((uint32_t *)dstu + 1);
		}
		if (n & 0x08)
{
			*(uint64_t *)dstu = *(const uint64_t *)srcu;
		}
		return ret;
	}

/**
	 * Fast way when copy size doesn't exceed 512 bytes
	 */
	if (n <= 32)
{
		rte_mov16((uint8_t *)dst, (const uint8_t *)src);
		rte_mov16((uint8_t *)dst - 16 + n, (const uint8_t *)src - 16 + n);
		return ret;
	}
	if (n <= 48)
{
		rte_mov32((uint8_t *)dst, (const uint8_t *)src);
		rte_mov16((uint8_t *)dst - 16 + n, (const uint8_t *)src - 16 + n);
		return ret;
	}
	if (n <= 64)
{
		rte_mov32((uint8_t *)dst, (const uint8_t *)src);
		rte_mov16((uint8_t *)dst + 32, (const uint8_t *)src + 32);
		rte_mov16((uint8_t *)dst - 16 + n, (const uint8_t *)src - 16 + n);
		return ret;
	}
	if (n <= 128)
{
		goto COPY_BLOCK_128_BACK15;
	}
	if (n <= 512)
{
		if (n >= 256)
{
			n -= 256;
			rte_mov128((uint8_t *)dst, (const uint8_t *)src);
			rte_mov128((uint8_t *)dst + 128, (const uint8_t *)src + 128);
			src = (const uint8_t *)src + 256;
			dst = (uint8_t *)dst + 256;
		}
COPY_BLOCK_255_BACK15:
		if (n >= 128)
{
			n -= 128;
			rte_mov128((uint8_t *)dst, (const uint8_t *)src);
			src = (const uint8_t *)src + 128;
			dst = (uint8_t *)dst + 128;
		}
COPY_BLOCK_128_BACK15:
		if (n >= 64)
{
			n -= 64;
			rte_mov64((uint8_t *)dst, (const uint8_t *)src);
			src = (const uint8_t *)src + 64;
			dst = (uint8_t *)dst + 64;
		}
COPY_BLOCK_64_BACK15:
		if (n >= 32)
{
			n -= 32;
			rte_mov32((uint8_t *)dst, (const uint8_t *)src);
			src = (const uint8_t *)src + 32;
			dst = (uint8_t *)dst + 32;
		}
		if (n > 16)
{
			rte_mov16((uint8_t *)dst, (const uint8_t *)src);
			rte_mov16((uint8_t *)dst - 16 + n, (const uint8_t *)src - 16 + n);
			return ret;
		}
		if (n > 0)
{
			rte_mov16((uint8_t *)dst - 16 + n, (const uint8_t *)src - 16 + n);
		}
		return ret;
	}

/**
	 * Make store aligned when copy size exceeds 512 bytes,
	 * and make sure the first 15 bytes are copied, because
	 * unaligned copy functions require up to 15 bytes
	 * backwards access.
	 */
	dstofss = (uintptr_t)dst & 0x0F;
	if (dstofss > 0)
{
		dstofss = 16 - dstofss + 16;
		n -= dstofss;
		rte_mov32((uint8_t *)dst, (const uint8_t *)src);
		src = (const uint8_t *)src + dstofss;
		dst = (uint8_t *)dst + dstofss;
	}
	srcofs = ((uintptr_t)src & 0x0F);

/**
	 * For aligned copy
	 */
	if (srcofs == 0)
{

/**
		 * Copy 256-byte blocks
		 */
		for (; n >= 256; n -= 256)
{
			rte_mov256((uint8_t *)dst, (const uint8_t *)src);
			dst = (uint8_t *)dst + 256;
			src = (const uint8_t *)src + 256;
		}

/**
		 * Copy whatever left
		 */
		goto COPY_BLOCK_255_BACK15;
	}

/**
	 * For copy with unaligned load
	 */
	__extension__ ({ switch (srcofs) { case 0x01: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x01) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x01)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x01)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x01)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x01)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x01)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x01)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x01)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x01)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x01) & 127) + 16 - 0x01; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x01) { while (n >= 32 + 16 - 0x01) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x01 + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x01)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x01)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x01) & 31) + 16 - 0x01; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x02: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x02) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x02)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x02)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x02)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x02)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x02)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x02)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x02)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x02)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x02) & 127) + 16 - 0x02; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x02) { while (n >= 32 + 16 - 0x02) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x02 + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x02)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x02)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x02) & 31) + 16 - 0x02; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x03: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x03) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x03)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x03)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x03)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x03)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x03)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x03)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x03)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x03)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x03) & 127) + 16 - 0x03; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x03) { while (n >= 32 + 16 - 0x03) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x03 + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x03)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x03)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x03) & 31) + 16 - 0x03; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x04: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x04) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x04)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x04)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x04)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x04)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x04)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x04)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x04)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x04)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x04) & 127) + 16 - 0x04; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x04) { while (n >= 32 + 16 - 0x04) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x04 + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x04)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x04)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x04) & 31) + 16 - 0x04; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x05: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x05) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x05)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x05)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x05)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x05)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x05)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x05)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x05)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x05)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x05) & 127) + 16 - 0x05; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x05) { while (n >= 32 + 16 - 0x05) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x05 + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x05)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x05)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x05) & 31) + 16 - 0x05; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x06: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x06) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x06)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x06)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x06)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x06)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x06)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x06)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x06)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x06)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x06) & 127) + 16 - 0x06; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x06) { while (n >= 32 + 16 - 0x06) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x06 + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x06)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x06)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x06) & 31) + 16 - 0x06; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x07: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x07) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x07)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x07)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x07)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x07)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x07)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x07)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x07)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x07)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x07) & 127) + 16 - 0x07; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x07) { while (n >= 32 + 16 - 0x07) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x07 + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x07)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x07)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x07) & 31) + 16 - 0x07; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x08: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x08) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x08)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x08)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x08)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x08)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x08)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x08)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x08)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x08)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x08) & 127) + 16 - 0x08; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x08) { while (n >= 32 + 16 - 0x08) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x08 + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x08)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x08)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x08) & 31) + 16 - 0x08; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x09: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x09) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x09)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x09)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x09)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x09)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x09)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x09)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x09)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x09)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x09) & 127) + 16 - 0x09; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x09) { while (n >= 32 + 16 - 0x09) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x09 + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x09)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x09)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x09) & 31) + 16 - 0x09; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x0A: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x0A) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0A)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0A)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x0A)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x0A)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x0A)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x0A)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x0A)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x0A)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x0A) & 127) + 16 - 0x0A; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x0A) { while (n >= 32 + 16 - 0x0A) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0A + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0A)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0A)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x0A) & 31) + 16 - 0x0A; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x0B: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x0B) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0B)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0B)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x0B)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x0B)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x0B)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x0B)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x0B)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x0B)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x0B) & 127) + 16 - 0x0B; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x0B) { while (n >= 32 + 16 - 0x0B) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0B + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0B)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0B)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x0B) & 31) + 16 - 0x0B; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x0C: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x0C) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0C)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0C)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x0C)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x0C)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x0C)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x0C)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x0C)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x0C)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x0C) & 127) + 16 - 0x0C; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x0C) { while (n >= 32 + 16 - 0x0C) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0C + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0C)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0C)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x0C) & 31) + 16 - 0x0C; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x0D: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x0D) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0D)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0D)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x0D)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x0D)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x0D)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x0D)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x0D)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x0D)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x0D) & 127) + 16 - 0x0D; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x0D) { while (n >= 32 + 16 - 0x0D) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0D + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0D)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0D)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x0D) & 31) + 16 - 0x0D; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x0E: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x0E) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0E)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0E)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x0E)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x0E)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x0E)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x0E)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x0E)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x0E)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x0E) & 127) + 16 - 0x0E; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x0E) { while (n >= 32 + 16 - 0x0E) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0E + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0E)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0E)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x0E) & 31) + 16 - 0x0E; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; case 0x0F: __extension__ ({ int tmp; while (n >= 128 + 16 - 0x0F) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 0 * 16)); n -= 128; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 2 * 16)); xmm3 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 3 * 16)); xmm4 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 4 * 16)); xmm5 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 5 * 16)); xmm6 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 6 * 16)); xmm7 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 7 * 16)); xmm8 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 8 * 16)); src = (const uint8_t *)src + 128; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0F)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0F)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 2 * 16), _mm_alignr_epi8(xmm3, xmm2, 0x0F)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 3 * 16), _mm_alignr_epi8(xmm4, xmm3, 0x0F)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 4 * 16), _mm_alignr_epi8(xmm5, xmm4, 0x0F)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 5 * 16), _mm_alignr_epi8(xmm6, xmm5, 0x0F)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 6 * 16), _mm_alignr_epi8(xmm7, xmm6, 0x0F)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 7 * 16), _mm_alignr_epi8(xmm8, xmm7, 0x0F)); dst = (uint8_t *)dst + 128; } tmp = n; n = ((n - 16 + 0x0F) & 127) + 16 - 0x0F; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; if (n >= 32 + 16 - 0x0F) { while (n >= 32 + 16 - 0x0F) { xmm0 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 0 * 16)); n -= 32; xmm1 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 1 * 16)); xmm2 = _mm_loadu_si128((const __m128i *)((const uint8_t *)src - 0x0F + 2 * 16)); src = (const uint8_t *)src + 32; _mm_storeu_si128((__m128i *)((uint8_t *)dst + 0 * 16), _mm_alignr_epi8(xmm1, xmm0, 0x0F)); _mm_storeu_si128((__m128i *)((uint8_t *)dst + 1 * 16), _mm_alignr_epi8(xmm2, xmm1, 0x0F)); dst = (uint8_t *)dst + 32; } tmp = n; n = ((n - 16 + 0x0F) & 31) + 16 - 0x0F; tmp -= n; src = (const uint8_t *)src + tmp; dst = (uint8_t *)dst + tmp; } }); break; default:; } });

/**
	 * Copy whatever left
	 */
	goto COPY_BLOCK_64_BACK15;
}


/*-
	*/


/**
	* @file
	* Pseudo-random Generators in RTE
	*/


/**
	* Seed the pseudo-random generator.
	* The generator is automatically seeded by the EAL init with a timer
	* value. It may need to be re-seeded by the user with a real random
	* value.
	* @param seedval
	*/
static inline void
rte_srand(uint64_t seedval)
{
	srand48((long unsigned int)seedval);
}


/**
	* Get a pseudo-random value.
	* This function generates pseudo-random numbers using the linear
	* congruential algorithm and 48-bit integer arithmetic, called twice
	* to generate a 64-bit value.
	* @return
	*/
static inline uint64_t
rte_rand(void)
{
	uint64_t val;
	val = lrand48();
	val <<= 32;
	val += lrand48();
	return val;
}


/*-
	*/


/**
	* @file
	* RTE Mbuf
	* The mbuf library provides the ability to create and destroy buffers
	* that may be used by the RTE application to store message
	* buffers. The message buffers are stored in a mempool, using the
	* RTE mempool library.
	* This library provide an API to allocate/free packet mbufs, which are
	* used to carry network packets.
	* To understand the concepts of packet buffers or mbufs, you
	* should read "TCP/IP Illustrated, Volume 2: The Implementation,
	* Addison-Wesley, 1995, ISBN 0-201-63354-X from Richard Stevens"
	* http://www.kohala.com/start/tcpipiv2.html
	*/


/*-
	*/


/**
	* @file
	* Generic, commonly-used macro and inline function definitions
	* for DPDK.
	*/



typedef uint64_t unaligned_uint64_t;
typedef uint32_t unaligned_uint32_t;
typedef uint16_t unaligned_uint16_t;


/**
	* Force alignment
	*/


/**
	* Force a structure to be packed
	*/








/**
	* short definition to mark a function parameter unused
	*/


/**
	* definition to mark a variable or function parameter as used so
	* as to avoid a compiler warning
	*/





/**
	* add a byte-value offset from a pointer
	*/


/**
	* subtract a byte-value offset from a pointer
	*/


/**
	* get the difference between two pointer values, i.e. how far apart
	* in bytes are the locations they point two. It is assumed that
	* ptr1 is greater than ptr2.
	*/





/**
	* Macro to align a pointer to a given power-of-two. The resultant
	* pointer will be a pointer of the same type as the first parameter, and
	* point to an address no higher than the first parameter. Second parameter
	* must be a power-of-two value.
	*/


/**
	* Macro to align a value to a given power-of-two. The resultant value
	* will be of the same type as the first parameter, and will be no
	* bigger than the first parameter. Second parameter must be a
	* power-of-two value.
	*/


/**
	* Macro to align a pointer to a given power-of-two. The resultant
	* pointer will be a pointer of the same type as the first parameter, and
	* point to an address no lower than the first parameter. Second parameter
	* must be a power-of-two value.
	*/


/**
	* Macro to align a value to a given power-of-two. The resultant value
	* will be of the same type as the first parameter, and will be no lower
	* than the first parameter. Second parameter must be a power-of-two
	* value.
	*/


/**
	* Macro to align a pointer to a given power-of-two. The resultant
	* pointer will be a pointer of the same type as the first parameter, and
	* point to an address no lower than the first parameter. Second parameter
	* must be a power-of-two value.
	* This function is the same as RTE_PTR_ALIGN_CEIL
	*/


/**
	* Macro to align a value to a given power-of-two. The resultant
	* value will be of the same type as the first parameter, and
	* will be no lower than the first parameter. Second parameter
	* must be a power-of-two value.
	* This function is the same as RTE_ALIGN_CEIL
	*/


/**
	* Checks if a pointer is aligned to a given power-of-two value
	* @param ptr
	* @param align
	* @return
	*/
static inline int
rte_is_aligned(void *ptr, unsigned align)
{
	return ((__typeof__((__typeof__(ptr))((void*)((uintptr_t)(ptr) + ((align) - 1)))))(__typeof__((uintptr_t)(__typeof__(ptr))((void*)((uintptr_t)(ptr) + ((align) - 1)))))(((uintptr_t)(__typeof__(ptr))((void*)((uintptr_t)(ptr) + ((align) - 1)))) & (~((__typeof__((uintptr_t)(__typeof__(ptr))((void*)((uintptr_t)(ptr) + ((align) - 1)))))((align) - 1))))) == ptr;
}





/**
	* Triggers an error at compilation time if the condition is true.
	*/





/**
	* Returns true if n is a power of 2
	* @param n
	* @return 1 if true, 0 otherwise
	*/
static inline int
rte_is_power_of_2(uint32_t n)
{
	return n && !(n & (n - 1));
}


/**
	* Aligns input parameter to the next power of 2
	* @param x
	* @return
	*/
static inline uint32_t
rte_align32pow2(uint32_t x)
{
	x--;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return x + 1;
}


/**
	* Aligns 64b input parameter to the next power of 2
	* @param v
	* @return
	*/
static inline uint64_t
rte_align64pow2(uint64_t v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v |= v >> 32;
	return v + 1;
}





/**
	* Macro to return the minimum of two numbers
	*/


/**
	* Macro to return the maximum of two numbers
	*/



static inline void
rte_pause(void) {}


/**
	* Searches the input parameter for the least significant set bit
	* (starting from zero).
	* If a least significant 1 bit is found, its bit index is returned.
	* If the content of the input parameter is zero, then the content of the return
	* value is undefined.
	* @param v
	* @return
	*/
static inline uint32_t
rte_bsf32(uint32_t v)
{
	return __builtin_ctz(v);
}





/**
	* ISO C helpers to modify format strings using variadic macros.
	* This is a replacement for the ", ## __VA_ARGS__" GNU extension.
	* An empty %s argument is appended to avoid a dangling comma.
	*/








/**
	* Converts a numeric string to the equivalent uint64_t value.
	* As well as straight number conversion, also recognises the suffixes
	* k, m and g for kilobytes, megabytes and gigabytes respectively.
	* If a negative number is passed in  i.e. a string with the first non-black
	* character being "-", zero is returned. Zero is also returned in the case of
	* an error with the strtoull call in the function.
	* @param str
	* @return
	*/
static inline uint64_t
rte_str_to_size(const char *str)
{
	char *endptr;
	unsigned long long size;
	while (isspace((int)*str))
		str++;
	if (*str == '-')
		return 0;
	errno = 0;
	size = strtoull(str, &endptr, 0);
	if (errno)
		return 0;
	if (*endptr == ' ')
		endptr++; 


	switch (*endptr){
	case 'G': case 'g': size *= 1024; 


	case 'M': case 'm': size *= 1024; 


	case 'K': case 'k': size *= 1024; 


	default:
		break;
	}
	return size;
}


/**
	* Function to terminate the application immediately, printing an error
	* message and returning the exit_code back to the shell.
	* This function never returns
	* @param exit_code
	* @param format
	*/
void
rte_exit(int exit_code, const char *format, ...)
	__attribute__((noreturn))
	__attribute__((format(printf, 2, 3)));


/*-
	*/


/**
	* @file
	* RTE Mempool.
	* A memory pool is an allocator of fixed-size object. It is
	* identified by its name, and uses a ring to store free objects. It
	* provides some other optional services, like a per-core object
	* cache, and an alignment helper to ensure that objects are padded
	* to spread them equally on all RAM channels, ranks, and so on.
	* Objects owned by a mempool should never be added in another
	* mempool. When an object is freed using rte_mempool_put() or
	* equivalent, the object data is not modified; the user can save some
	* meta-data in the object data and retrieve them when allocating a
	* new object.
	* Note: the mempool implementation is not preemptable. A lcore must
	* not be interrupted by another task that uses the same mempool
	* (because it uses a ring which is not preemptable). Also, mempool
	* functions must not be used outside the DPDK environment: for
	* example, in linuxapp environment, a thread that is not created by
	* the EAL must not use mempools. This is due to the per-lcore cache
	* that won't work as rte_lcore_id() will not return a correct value.
	*/


/*
	* Copyright (c) 1991, 1993
	*	The Regents of the University of California.  All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	*	@(#)queue.h	8.5 (Berkeley) 8/20/94
	*/


/*
	* This file defines five types of data structures: singly-linked lists,
	* lists, simple queues, tail queues, and circular queues.
	* A singly-linked list is headed by a single forward pointer. The
	* elements are singly linked for minimum space and pointer manipulation
	* overhead at the expense of O(n) removal for arbitrary elements. New
	* elements can be added to the list after an existing element or at the
	* head of the list.  Elements being removed from the head of the list
	* should use the explicit macro for this purpose for optimum
	* efficiency. A singly-linked list may only be traversed in the forward
	* direction.  Singly-linked lists are ideal for applications with large
	* datasets and few or no removals or for implementing a LIFO queue.
	* A list is headed by a single forward pointer (or an array of forward
	* pointers for a hash table header). The elements are doubly linked
	* so that an arbitrary element can be removed without a need to
	* traverse the list. New elements can be added to the list before
	* or after an existing element or at the head of the list. A list
	* may only be traversed in the forward direction.
	* A simple queue is headed by a pair of pointers, one the head of the
	* list and the other to the tail of the list. The elements are singly
	* linked to save space, so elements can only be removed from the
	* head of the list. New elements can be added to the list after
	* an existing element, at the head of the list, or at the end of the
	* list. A simple queue may only be traversed in the forward direction.
	* A tail queue is headed by a pair of pointers, one to the head of the
	* list and the other to the tail of the list. The elements are doubly
	* linked so that an arbitrary element can be removed without a need to
	* traverse the list. New elements can be added to the list before or
	* after an existing element, at the head of the list, or at the end of
	* the list. A tail queue may be traversed in either direction.
	* A circle queue is headed by a pair of pointers, one to the head of the
	* list and the other to the tail of the list. The elements are doubly
	* linked so that an arbitrary element can be removed without a need to
	* traverse the list. New elements can be added to the list before or after
	* an existing element, at the head of the list, or at the end of the list.
	* A circle queue may be traversed in either direction, but has a more
	* complex end of list detection.
	* For details on the use of these macros, see the queue(3) manual page.
	*/


/*
	* List definitions.
	*/


/*
	* List functions.
	*/


/*
	* List access methods.
	*/


/*
	* Singly-linked List definitions.
	*/


/*
	* Singly-linked List functions.
	*/


/*
	* Singly-linked List access methods.
	*/


/*
	* Singly-linked Tail queue declarations.
	*/


/*
	* Singly-linked Tail queue functions.
	*/


/*
	* Singly-linked Tail queue access methods.
	*/


/*
	* Simple queue definitions.
	*/


/*
	* Simple queue functions.
	*/


/*
	* Simple queue access methods.
	*/


/*
	* Tail queue definitions.
	*/


/*
	* Tail queue functions.
	*/


/*
	* Tail queue access methods.
	*/


/*
	* Circular queue definitions.
	*/


/*
	* Circular queue functions.
	*/


/*
	* Circular queue access methods.
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* RTE Spinlocks
	* This file defines an API for read-write locks, which are implemented
	* in an architecture-specific way. This kind of lock simply waits in
	* a loop repeatedly checking until the lock becomes available.
	* All locks must be initialised before use, and only initialised once.
	*/


/*-
	*/


/**
	* @file
	* API for lcore and socket manipulation
	*/


/*-
	*/


/**
	* @file
	* Per-lcore variables in RTE
	* This file defines an API for instantiating per-lcore "global
	* variables" that are environment-specific. Note that in all
	* environments, a "shared variable" is the default when you use a
	* global variable.
	* Parts of this are execution environment specific.
	*/


/**
	* Macro to define a per lcore variable "var" of type "type", don't
	* use keywords like "static" or "volatile" in type, just prefix the
	* whole macro.
	*/


/**
	* Macro to declare an extern per lcore variable "var" of type "type"
	*/


/**
	* Read/write the per-lcore variable value
	*/


/*-
	*/


/**
	* @file
	* EAL Configuration API
	*/


/*-
	*/





/**
	* The lcore role (used in RTE or not).
	*/
enum rte_lcore_role_t
{
	ROLE_RTE,
	ROLE_OFF,
};


/**
	* The type of process in a linuxapp, multi-process setup
	*/
enum rte_proc_type_t
{
	RTE_PROC_AUTO = -1, 


	RTE_PROC_PRIMARY = 0, 


	RTE_PROC_SECONDARY,
	RTE_PROC_INVALID
};


/**
	* The global RTE configuration structure.
	*/
struct rte_config
{
	uint32_t master_lcore; 


	uint32_t lcore_count; 


	enum rte_lcore_role_t lcore_role[128]; 




	enum rte_proc_type_t process_type;

/**
	 * Pointer to memory configuration, which may be shared across multiple
	 * DPDK instances
	 */
	struct rte_mem_config *mem_config;
} __attribute__((__packed__));


/**
	* Get the global configuration structure.
	* @return
	*/
struct rte_config *rte_eal_get_configuration(void);


/**
	* Get a lcore's role.
	* @param lcore_id
	* @return
	*/
enum rte_lcore_role_t rte_eal_lcore_role(unsigned lcore_id);


/**
	* Get the process type in a multi-process setup
	* @return
	*/
enum rte_proc_type_t rte_eal_process_type(void);


/**
	* Request iopl privilege for all RPL.
	* This function should be called by pmds which need access to ioports.

	* @return
	*/
int rte_eal_iopl_init(void);


/**
	* Initialize the Environment Abstraction Layer (EAL).
	* This function is to be executed on the MASTER lcore only, as soon
	* as possible in the application's main() function.
	* The function finishes the initialization process before main() is called.
	* It puts the SLAVE lcores in the WAIT state.
	* When the multi-partition feature is supported, depending on the
	* configuration (if CONFIG_RTE_EAL_MAIN_PARTITION is disabled), this
	* function waits to ensure that the magic number is set before
	* returning. See also the rte_eal_get_configuration() function. Note:
	* This behavior may change in the future.
	* @param argc
	* @param argv
	* @return
	*/
int rte_eal_init(int argc, char **argv);


/**
	* Check if a primary process is currently alive
	* This function returns true when a primary process is currently
	* active.
	* @param config_file_path
	* @return
	*  - If alive, returns 1.
	*  - If dead, returns 0.
	*/
int rte_eal_primary_proc_alive(const char *config_file_path);


/**
	* Usage function typedef used by the application usage function.
	* Use this function typedef to define and call rte_set_applcation_usage_hook()
	* routine.
	*/
typedef void (*rte_usage_hook_t)(const char * prgname);


/**
	* Add application usage routine callout from the eal_usage() routine.
	* This function allows the application to include its usage message
	* in the EAL system usage message. The routine rte_set_application_usage_hook()
	* needs to be called before the rte_eal_init() routine in the application.
	* This routine is optional for the application and will behave as if the set
	* routine was never called as the default behavior.
	* @param usage_func
	* @return
	*/
rte_usage_hook_t
rte_set_application_usage_hook(rte_usage_hook_t usage_func);


/**
	* macro to get the lock of tailq in mem_config
	*/


/**
	* macro to get the multiple lock of mempool shared by mutiple-instance
	*/


/**
	* Whether EAL is using huge pages (disabled by --no-huge option).
	* The no-huge mode cannot be used with UIO poll-mode drivers like igb/ixgbe.
	* It is useful for NIC drivers (e.g. librte_pmd_mlx4, librte_pmd_vmxnet3) or
	* crypto drivers (e.g. librte_crypto_nitrox) provided by third-parties such
	* as 6WIND.
	* @return
	*/
int rte_eal_has_hugepages(void);


/**
	* A wrap API for syscall gettid.
	* @return
	*/
int rte_sys_gettid(void);


/**
	* Get system unique thread id.
	* @return
	*/
static inline int rte_gettid(void)
{
	static __thread __typeof__(int) per_lcore__thread_id = -1;
	if ((per_lcore__thread_id) == -1)
		(per_lcore__thread_id) = rte_sys_gettid();
	return (per_lcore__thread_id);
}


/*-
	*/


/**
	* @file
	* Launch tasks on other lcores
	*/


/**
	* State of an lcore.
	*/
enum rte_lcore_state_t
{
	WAIT, 


	RUNNING, 


	FINISHED, 


};


/**
	* Definition of a remote launch function.
	*/
typedef int (lcore_function_t)(void *);


/**
	* Launch a function on another lcore.
	* To be executed on the MASTER lcore only.
	* Sends a message to a slave lcore (identified by the slave_id) that
	* is in the WAIT state (this is true after the first call to
	* rte_eal_init()). This can be checked by first calling
	* rte_eal_wait_lcore(slave_id).
	* When the remote lcore receives the message, it switches to
	* the RUNNING state, then calls the function f with argument arg. Once the
	* execution is done, the remote lcore switches to a FINISHED state and
	* the return value of f is stored in a local variable to be read using
	* rte_eal_wait_lcore().
	* The MASTER lcore returns as soon as the message is sent and knows
	* nothing about the completion of f.
	* Note: This function is not designed to offer optimum
	* performance. It is just a practical way to launch a function on
	* another lcore at initialization time.
	* @param f
	* @param arg
	* @param slave_id
	* @return
	*/
int rte_eal_remote_launch(lcore_function_t *f, void *arg, unsigned slave_id);


/**
	* This enum indicates whether the master core must execute the handler
	* launched on all logical cores.
	*/
enum rte_rmt_call_master_t
{
	SKIP_MASTER = 0, 


	CALL_MASTER, 


};


/**
	* Launch a function on all lcores.
	* Check that each SLAVE lcore is in a WAIT state, then call
	* rte_eal_remote_launch() for each lcore.
	* @param f
	* @param arg
	* @param call_master
	* @return
	*/
int rte_eal_mp_remote_launch(lcore_function_t *f, void *arg,
						  enum rte_rmt_call_master_t call_master);


/**
	* Get the state of the lcore identified by slave_id.
	* To be executed on the MASTER lcore only.
	* @param slave_id
	* @return
	*/
enum rte_lcore_state_t rte_eal_get_lcore_state(unsigned slave_id);


/**
	* Wait until an lcore finishes its job.
	* To be executed on the MASTER lcore only.
	* If the slave lcore identified by the slave_id is in a FINISHED state,
	* switch to the WAIT state. If the lcore is in RUNNING state, wait until
	* the lcore finishes its job and moves to the FINISHED state.
	* @param slave_id
	* @return
	*/
int rte_eal_wait_lcore(unsigned slave_id);


/**
	* Wait until all lcores finish their jobs.
	* To be executed on the MASTER lcore only. Issue an
	* rte_eal_wait_lcore() for every lcore. The return values are
	* ignored.
	* After a call to rte_eal_mp_wait_lcore(), the caller can assume
	* that all slave lcores are in a WAIT state.
	*/
void rte_eal_mp_wait_lcore(void);
	typedef cpu_set_t rte_cpuset_t;


/**
	* Structure storing internal configuration (per-lcore)
	*/
struct lcore_config
{
	unsigned detected; 


	pthread_t thread_id; 


	int pipe_master2slave[2]; 


	int pipe_slave2master[2]; 


	lcore_function_t * volatile f; 


	void * volatile arg; 


	volatile int ret; 


	volatile enum rte_lcore_state_t state; 


	unsigned socket_id; 


	unsigned core_id; 


	int core_index; 


	rte_cpuset_t cpuset; 


};


/**
	* Internal configuration (per-lcore)
	*/
extern __thread __typeof__(unsigned) per_lcore__lcore_id; 


extern __thread __typeof__(rte_cpuset_t) per_lcore__cpuset; 




/**
	* Return the ID of the execution unit we are running on.
	* @return
	*  Logical core ID (in EAL thread) or LCORE_ID_ANY (in non-EAL thread)
	*/
static inline unsigned
rte_lcore_id(void)
{
	return (per_lcore__lcore_id);
}


/**
	* Get the id of the master lcore
	* @return
	*/
static inline unsigned
rte_get_master_lcore(void)
{
	return rte_eal_get_configuration()->master_lcore;
}


/**
	* Return the number of execution units (lcores) on the system.
	* @return
	*/
static inline unsigned
rte_lcore_count(void)
{
	const struct rte_config *cfg = rte_eal_get_configuration();
	return cfg->lcore_count;
}


/**
	* Return the index of the lcore starting from zero.
	* The order is physical or given by command line (-l option).
	* @param lcore_id
	* @return
	*/
static inline int
rte_lcore_index(int lcore_id)
{
	if (lcore_id >= 128)
		return -1;
	if (lcore_id < 0)
		lcore_id = rte_lcore_id();
	return lcore_config[lcore_id].core_index;
}


/**
	* Return the ID of the physical socket of the logical core we are
	* running on.
	* @return
	*/
unsigned rte_socket_id(void);


/**
	* Get the ID of the physical socket of the specified lcore
	* @param lcore_id
	* @return
	*/
static inline unsigned
rte_lcore_to_socket_id(unsigned lcore_id)
{
	return lcore_config[lcore_id].socket_id;
}


/**
	* Test if an lcore is enabled.
	* @param lcore_id
	* @return
	*/
static inline int
rte_lcore_is_enabled(unsigned lcore_id)
{
	struct rte_config *cfg = rte_eal_get_configuration();
	if (lcore_id >= 128)
		return 0;
	return cfg->lcore_role[lcore_id] != ROLE_OFF;
}


/**
	* Get the next enabled lcore ID.
	* @param i
	* @param skip_master
	* @param wrap
	* @return
	*/
static inline unsigned
rte_get_next_lcore(unsigned i, int skip_master, int wrap)
{
	i++;
	if (wrap)
		i %= 128;
	while (i < 128)
{
		if (!rte_lcore_is_enabled(i) ||
						(skip_master && (i == rte_get_master_lcore())))
{
			i++;
			if (wrap)
				i %= 128;
			continue;
		}
		break;
	}
	return i;
}


/**
	* Macro to browse all running lcores.
	*/


/**
	* Macro to browse all running lcores except the master lcore.
	*/


/**
	* Set core affinity of the current thread.
	* Support both EAL and non-EAL thread and update TLS.
	* @param cpusetp
	* @return
	*/
int rte_thread_set_affinity(rte_cpuset_t *cpusetp);


/**
	* Get core affinity of the current thread.
	* @param cpusetp
	*/
void rte_thread_get_affinity(rte_cpuset_t *cpusetp);


/**
	* Set thread names.
	* @note It fails with glibc < 2.12.
	* @param id
	* @param name
	* @return
	*/
int rte_thread_setname(pthread_t id, const char *name);


/**
	* The rte_spinlock_t type.
	*/
typedef struct
{
	volatile int locked; 


} rte_spinlock_t;


/**
	* A static spinlock initializer.
	*/


/**
	* Initialize the spinlock to an unlocked state.
	* @param sl
	*/
static inline void
rte_spinlock_init(rte_spinlock_t *sl)
{
	sl->locked = 0;
}


/**
	* Take the spinlock.
	* @param sl
	*/
static inline void
rte_spinlock_lock(rte_spinlock_t *sl);


/**
	* Release the spinlock.
	* @param sl
	*/
static inline void
rte_spinlock_unlock (rte_spinlock_t *sl);


/**
	* Try to take the lock.
	* @param sl
	* @return
	*/
static inline int
rte_spinlock_trylock (rte_spinlock_t *sl);


/**
	* Test if the lock is taken.
	* @param sl
	* @return
	*/
static inline int rte_spinlock_is_locked (rte_spinlock_t *sl)
{
	return sl->locked;
}


/**
	* Test if hardware transactional memory (lock elision) is supported
	* @return
	*/
static inline int rte_tm_supported(void);


/**
	* Try to execute critical section in a hardware memory transaction,
	* if it fails or not available take the spinlock.
	* NOTE: An attempt to perform a HW I/O operation inside a hardware memory
	* transaction always aborts the transaction since the CPU is not able to
	* roll-back should the transaction fail. Therefore, hardware transactional
	* locks are not advised to be used around rte_eth_rx_burst() and
	* rte_eth_tx_burst() calls.
	* @param sl
	*/
static inline void
rte_spinlock_lock_tm(rte_spinlock_t *sl);


/**
	* Commit hardware memory transaction or release the spinlock if
	* the spinlock is used as a fall-back
	* @param sl
	*/
static inline void
rte_spinlock_unlock_tm(rte_spinlock_t *sl);


/**
	* Try to execute critical section in a hardware memory transaction,
	* if it fails or not available try to take the lock.
	* NOTE: An attempt to perform a HW I/O operation inside a hardware memory
	* transaction always aborts the transaction since the CPU is not able to
	* roll-back should the transaction fail. Therefore, hardware transactional
	* locks are not advised to be used around rte_eth_rx_burst() and
	* rte_eth_tx_burst() calls.
	* @param sl
	* @return
	*/
static inline int
rte_spinlock_trylock_tm(rte_spinlock_t *sl);


/**
	* The rte_spinlock_recursive_t type.
	*/
typedef struct
{
	rte_spinlock_t sl; 


	volatile int user; 


	volatile int count; 


} rte_spinlock_recursive_t;


/**
	* A static recursive spinlock initializer.
	*/


/**
	* Initialize the recursive spinlock to an unlocked state.
	* @param slr
	*/
static inline void rte_spinlock_recursive_init(rte_spinlock_recursive_t *slr)
{
	rte_spinlock_init(&slr->sl);
	slr->user = -1;
	slr->count = 0;
}


/**
	* Take the recursive spinlock.
	* @param slr
	*/
static inline void rte_spinlock_recursive_lock(rte_spinlock_recursive_t *slr)
{
	int id = rte_gettid();
	if (slr->user != id)
{
		rte_spinlock_lock(&slr->sl);
		slr->user = id;
	}
	slr->count++;
}


/**
	* Release the recursive spinlock.
	* @param slr
	*/
static inline void rte_spinlock_recursive_unlock(rte_spinlock_recursive_t *slr)
{
	if (--(slr->count) == 0)
{
		slr->user = -1;
		rte_spinlock_unlock(&slr->sl);
	}
}


/**
	* Try to take the recursive lock.
	* @param slr
	* @return
	*/
static inline int rte_spinlock_recursive_trylock(rte_spinlock_recursive_t *slr)
{
	int id = rte_gettid();
	if (slr->user != id)
{
		if (rte_spinlock_trylock(&slr->sl) == 0)
			return 0;
		slr->user = id;
	}
	slr->count++;
	return 1;
}


/**
	* Try to execute critical section in a hardware memory transaction,
	* if it fails or not available take the recursive spinlocks
	* NOTE: An attempt to perform a HW I/O operation inside a hardware memory
	* transaction always aborts the transaction since the CPU is not able to
	* roll-back should the transaction fail. Therefore, hardware transactional
	* locks are not advised to be used around rte_eth_rx_burst() and
	* rte_eth_tx_burst() calls.
	* @param slr
	*/
static inline void rte_spinlock_recursive_lock_tm(
	rte_spinlock_recursive_t *slr);


/**
	* Commit hardware memory transaction or release the recursive spinlock
	* if the recursive spinlock is used as a fall-back
	* @param slr
	*/
static inline void rte_spinlock_recursive_unlock_tm(
	rte_spinlock_recursive_t *slr);


/**
	* Try to execute critical section in a hardware memory transaction,
	* if it fails or not available try to take the recursive lock
	* NOTE: An attempt to perform a HW I/O operation inside a hardware memory
	* transaction always aborts the transaction since the CPU is not able to
	* roll-back should the transaction fail. Therefore, hardware transactional
	* locks are not advised to be used around rte_eth_rx_burst() and
	* rte_eth_tx_burst() calls.
	* @param slr
	* @return
	*/
static inline int rte_spinlock_recursive_trylock_tm(
	rte_spinlock_recursive_t *slr);


/*
	* Copyright (c) 2012,2013 Intel Corporation
	* Author: Andi Kleen
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that: (1) source code distributions
	* retain the above copyright notice and this paragraph in its entirety, (2)
	* distributions including binary code include the above copyright notice and
	* this paragraph in its entirety in the documentation or other materials
	* provided with the distribution
	* THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
	* WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
	* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
	*/


/* Official RTM intrinsics interface matching gcc/icc, but works
			on older gcc compatible compilers and binutils. */


/*-
	*/
static __attribute__((__always_inline__)) inline
unsigned int rte_xbegin(void)
{
	unsigned int ret = (~0u);
	__asm__ volatile(".byte 0xc7,0xf8 ; .long 0" : "+a" (ret) :: "memory");
	return ret;
}
static __attribute__((__always_inline__)) inline
void rte_xend(void)
{
		__asm__ volatile(".byte 0x0f,0x01,0xd5" ::: "memory");
}



static __attribute__((__always_inline__)) inline
int rte_xtest(void)
{
	unsigned char out;
	__asm__ volatile(".byte 0x0f,0x01,0xd6 ; setnz %0" :
		"=r" (out) :: "memory");
	return out;
}


/*-
	*/
enum rte_cpu_flag_t
{


	RTE_CPUFLAG_SSE3 = 0, 


	RTE_CPUFLAG_PCLMULQDQ, 


	RTE_CPUFLAG_DTES64, 


	RTE_CPUFLAG_MONITOR, 


	RTE_CPUFLAG_DS_CPL, 


	RTE_CPUFLAG_VMX, 


	RTE_CPUFLAG_SMX, 


	RTE_CPUFLAG_EIST, 


	RTE_CPUFLAG_TM2, 


	RTE_CPUFLAG_SSSE3, 


	RTE_CPUFLAG_CNXT_ID, 


	RTE_CPUFLAG_FMA, 


	RTE_CPUFLAG_CMPXCHG16B, 


	RTE_CPUFLAG_XTPR, 


	RTE_CPUFLAG_PDCM, 


	RTE_CPUFLAG_PCID, 


	RTE_CPUFLAG_DCA, 


	RTE_CPUFLAG_SSE4_1, 


	RTE_CPUFLAG_SSE4_2, 


	RTE_CPUFLAG_X2APIC, 


	RTE_CPUFLAG_MOVBE, 


	RTE_CPUFLAG_POPCNT, 


	RTE_CPUFLAG_TSC_DEADLINE, 


	RTE_CPUFLAG_AES, 


	RTE_CPUFLAG_XSAVE, 


	RTE_CPUFLAG_OSXSAVE, 


	RTE_CPUFLAG_AVX, 


	RTE_CPUFLAG_F16C, 


	RTE_CPUFLAG_RDRAND, 




	RTE_CPUFLAG_FPU, 


	RTE_CPUFLAG_VME, 


	RTE_CPUFLAG_DE, 


	RTE_CPUFLAG_PSE, 


	RTE_CPUFLAG_TSC, 


	RTE_CPUFLAG_MSR, 


	RTE_CPUFLAG_PAE, 


	RTE_CPUFLAG_MCE, 


	RTE_CPUFLAG_CX8, 


	RTE_CPUFLAG_APIC, 


	RTE_CPUFLAG_SEP, 


	RTE_CPUFLAG_MTRR, 


	RTE_CPUFLAG_PGE, 


	RTE_CPUFLAG_MCA, 


	RTE_CPUFLAG_CMOV, 


	RTE_CPUFLAG_PAT, 


	RTE_CPUFLAG_PSE36, 


	RTE_CPUFLAG_PSN, 


	RTE_CPUFLAG_CLFSH, 


	RTE_CPUFLAG_DS, 


	RTE_CPUFLAG_ACPI, 


	RTE_CPUFLAG_MMX, 


	RTE_CPUFLAG_FXSR, 


	RTE_CPUFLAG_SSE, 


	RTE_CPUFLAG_SSE2, 


	RTE_CPUFLAG_SS, 


	RTE_CPUFLAG_HTT, 


	RTE_CPUFLAG_TM, 


	RTE_CPUFLAG_PBE, 




	RTE_CPUFLAG_DIGTEMP, 


	RTE_CPUFLAG_TRBOBST, 


	RTE_CPUFLAG_ARAT, 


	RTE_CPUFLAG_PLN, 


	RTE_CPUFLAG_ECMD, 


	RTE_CPUFLAG_PTM, 




	RTE_CPUFLAG_MPERF_APERF_MSR, 


	RTE_CPUFLAG_ACNT2, 


	RTE_CPUFLAG_ENERGY_EFF, 




	RTE_CPUFLAG_FSGSBASE, 


	RTE_CPUFLAG_BMI1, 


	RTE_CPUFLAG_HLE, 


	RTE_CPUFLAG_AVX2, 


	RTE_CPUFLAG_SMEP, 


	RTE_CPUFLAG_BMI2, 


	RTE_CPUFLAG_ERMS, 


	RTE_CPUFLAG_INVPCID, 


	RTE_CPUFLAG_RTM, 


	RTE_CPUFLAG_AVX512F, 




	RTE_CPUFLAG_LAHF_SAHF, 


	RTE_CPUFLAG_LZCNT, 




	RTE_CPUFLAG_SYSCALL, 


	RTE_CPUFLAG_XD, 


	RTE_CPUFLAG_1GB_PG, 


	RTE_CPUFLAG_RDTSCP, 


	RTE_CPUFLAG_EM64T, 




	RTE_CPUFLAG_INVTSC, 




	RTE_CPUFLAG_NUMFLAGS, 


};


/*-
	*/


/**
	* @file
	* Architecture specific API to determine available CPU features at runtime.
	*/


/**
	* Enumeration of all CPU features supported
	*/
__extension__
enum rte_cpu_flag_t;


/**
	* Get name of CPU flag
	* @param feature
	* @return
	*/
__extension__
const char *
rte_cpu_get_flag_name(enum rte_cpu_flag_t feature);


/**
	* Function for checking a CPU flag availability
	* @param feature
	* @return
	*/
__extension__
int
rte_cpu_get_flag_enabled(enum rte_cpu_flag_t feature);


/**
	* This function checks that the currently used CPU supports the CPU features
	* that were specified at compile time. It is called automatically within the
	* EAL, so does not need to be used by applications.
	*/
void
rte_cpu_check_supported(void);


/*-
	*/


/**
	* @file
	* Branch Prediction Helpers in RTE
	*/


/**
	* Check if a branch is likely to be taken.
	* This compiler builtin allows the developer to indicate if a branch is
	* likely to be taken. Example:
	*/


/**
	* Check if a branch is unlikely to be taken.
	* This compiler builtin allows the developer to indicate if a branch is
	* unlikely to be taken. Example:
	*/


/*-
	*/
static inline void
rte_spinlock_lock(rte_spinlock_t *sl)
{
	int lock_val = 1;
	__asm__ volatile (
			"1:\n"
			"xchg %[locked], %[lv]\n"
			"test %[lv], %[lv]\n"
			"jz 3f\n"
			"2:\n"
			"pause\n"
			"cmpl $0, %[locked]\n"
			"jnz 2b\n"
			"jmp 1b\n"
			"3:\n"
			: [locked] "=m" (sl->locked), [lv] "=q" (lock_val)
			: "[lv]" (lock_val)
			: "memory");
}
static inline void
rte_spinlock_unlock (rte_spinlock_t *sl)
{
	int unlock_val = 0;
	__asm__ volatile (
			"xchg %[locked], %[ulv]\n"
			: [locked] "=m" (sl->locked), [ulv] "=q" (unlock_val)
			: "[ulv]" (unlock_val)
			: "memory");
}
static inline int
rte_spinlock_trylock (rte_spinlock_t *sl)
{
	int lockval = 1;
	__asm__ volatile (
			"xchg %[locked], %[lockval]"
			: [locked] "=m" (sl->locked), [lockval] "=q" (lockval)
			: "[lockval]" (lockval)
			: "memory");
	return lockval == 0;
}
static inline int rte_tm_supported(void)
{
	return rte_rtm_supported;
}
static inline int
rte_try_tm(volatile int *lock)
{
	if (!rte_rtm_supported)
		return 0;
	int retries = (10);
	while (__builtin_expect((retries--),1))
{
		unsigned int status = rte_xbegin();
		if (__builtin_expect(((~0u) == status),1))
{
			if (__builtin_expect((*lock),0))
				do { __asm__ volatile(".byte 0xc6,0xf8,%P0" :: "i" ((0xff)) : "memory"); } while (0);
			else
				return 1;
		}
		while (*lock)
			rte_pause();
		if ((status & (1 << 0)) &&
			((((status) >> 24) & 0xff) == (0xff)))
			continue;
		if ((status & (1 << 1)) == 0) 


			break;
	}
	return 0;
}
static inline void
rte_spinlock_lock_tm(rte_spinlock_t *sl)
{
	if (__builtin_expect((rte_try_tm(&sl->locked)),1))
		return;
	rte_spinlock_lock(sl); 


}
static inline int
rte_spinlock_trylock_tm(rte_spinlock_t *sl)
{
	if (__builtin_expect((rte_try_tm(&sl->locked)),1))
		return 1;
	return rte_spinlock_trylock(sl);
}
static inline void
rte_spinlock_unlock_tm(rte_spinlock_t *sl)
{
	if (__builtin_expect((sl->locked),0))
		rte_spinlock_unlock(sl);
	else
		rte_xend();
}
static inline void
rte_spinlock_recursive_lock_tm(rte_spinlock_recursive_t *slr)
{
	if (__builtin_expect((rte_try_tm(&slr->sl.locked)),1))
		return;
	rte_spinlock_recursive_lock(slr); 


}
static inline void
rte_spinlock_recursive_unlock_tm(rte_spinlock_recursive_t *slr)
{
	if (__builtin_expect((slr->sl.locked),0))
		rte_spinlock_recursive_unlock(slr);
	else
		rte_xend();
}
static inline int
rte_spinlock_recursive_trylock_tm(rte_spinlock_recursive_t *slr)
{
	if (__builtin_expect((rte_try_tm(&slr->sl.locked)),1))
		return 1;
	return rte_spinlock_recursive_trylock(slr);
}


/*-
	*/


/**
	* @file
	* RTE Logs API
	* This file provides a log API to RTE applications.
	*/



struct rte_logs
{
	uint32_t type; 


	uint32_t level; 


	FILE *file; 


};

















/**
	* Change the stream that will be used by the logging system.
	* This can be done at any time. The f argument represents the stream
	* to be used to send the logs. If f is NULL, the default output is
	* used (stderr).
	* @param f
	* @return
	*/
int rte_openlog_stream(FILE *f);


/**
	* Set the global log level.
	* After this call, all logs that are lower or equal than level and
	* lower or equal than the RTE_LOG_LEVEL configuration option will be
	* displayed.
	* @param level
	*/
void rte_set_log_level(uint32_t level);


/**
	* Get the global log level.
	*/
uint32_t rte_get_log_level(void);


/**
	* Enable or disable the log type.
	* @param type
	* @param enable
	*/
void rte_set_log_type(uint32_t type, int enable);


/**
	* Get the global log type.
	*/
uint32_t rte_get_log_type(void);


/**
	* Get the current loglevel for the message being processed.
	* Before calling the user-defined stream for logging, the log
	* subsystem sets a per-lcore variable containing the loglevel and the
	* logtype of the message being processed. This information can be
	* accessed by the user-defined log output function through this
	* function.
	* @return
	*/
int rte_log_cur_msg_loglevel(void);


/**
	* Get the current logtype for the message being processed.
	* Before calling the user-defined stream for logging, the log
	* subsystem sets a per-lcore variable containing the loglevel and the
	* logtype of the message being processed. This information can be
	* accessed by the user-defined log output function through this
	* function.
	* @return
	*/
int rte_log_cur_msg_logtype(void);


/**
	* Generates a log message.
	* The message will be sent in the stream defined by the previous call
	* to rte_openlog_stream().
	* The level argument determines if the log should be displayed or
	* not, depending on the global rte_logs variable.
	* The preferred alternative is the RTE_LOG() function because debug logs may
	* be removed at compilation time if optimization is enabled. Moreover,
	* logs are automatically prefixed by type when using the macro.
	* @param level
	* @param logtype
	* @param format
	* @return
	*/
int rte_log(uint32_t level, uint32_t logtype, const char *format, ...)
	__attribute__((cold))
	__attribute__((format(printf, 3, 4)));


/**
	* Generates a log message.
	* The message will be sent in the stream defined by the previous call
	* to rte_openlog_stream().
	* The level argument determines if the log should be displayed or
	* not, depending on the global rte_logs variable. A trailing
	* newline may be added if needed.
	* The preferred alternative is the RTE_LOG() because debug logs may be
	* removed at compilation time.
	* @param level
	* @param logtype
	* @param format
	* @param ap
	* @return
	*/
int rte_vlog(uint32_t level, uint32_t logtype, const char *format, va_list ap)
	__attribute__((format(printf,3,0)));


/**
	* Generates a log message.
	* The RTE_LOG() is equivalent to rte_log() with two differences:

	* - RTE_LOG() can be used to remove debug logs at compilation time,
	* - The log level and log type names are smaller, for example:
	* @param l
	* @param t
	* @param ...
	* @return
	*/


/*-
	*/


/**
	* @file
	* Debug Functions in RTE
	* This file defines a generic API for debug operations. Part of
	* the implementation is architecture-specific.
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* Branch Prediction Helpers in RTE
	*/


/**
	* Dump the stack of the calling core to the console.
	*/
void rte_dump_stack(void);


/**
	* Dump the registers of the calling core to the console.
	* Note: Not implemented in a userapp environment; use gdb instead.
	*/
void rte_dump_registers(void);


/**
	* Provide notification of a critical non-recoverable error and terminate
	* execution abnormally.
	* Display the format string and its expanded arguments (printf-like).
	* In a linuxapp environment, this function dumps the stack and calls
	* abort() resulting in a core dump if enabled.
	* The function never returns.
	* @param ...
	*/


/*
	* Provide notification of a critical non-recoverable error and stop.
	* This function should not be called directly. Refer to rte_panic() macro
	* documentation.
	*/
void __rte_panic(const char *funcname , const char *format, ...)
	__attribute__((cold))
	__attribute__((noreturn))
	__attribute__((format(printf, 2, 3)));


/*-
	*/


/*-
	*/


/**
	* @file
	* Memory-related RTE API.
	*/


/*-
	*/


/**
	* A structure used to store memory information.
	*/
struct memory_info
{
	char name[256];
	uint64_t size;
};


/**
	* A structure used to store memory segment information.
	*/
struct memseg_info
{
	uint32_t idx;
	uint64_t pfn;
	uint64_t size;
	uint64_t mfn[(4096 / 2)];
};


/**
	* A structure used to store memory block information.
	*/
struct memblock_info
{
	uint8_t exchange_flag;
	uint8_t used;
	uint64_t vir_addr;
	uint64_t pfn;
	uint64_t mfn;
};


/*-
	*/
__extension__
enum rte_page_sizes
{
	RTE_PGSIZE_4K = 1ULL << 12,
	RTE_PGSIZE_64K = 1ULL << 16,
	RTE_PGSIZE_256K = 1ULL << 18,
	RTE_PGSIZE_2M = 1ULL << 21,
	RTE_PGSIZE_16M = 1ULL << 24,
	RTE_PGSIZE_256M = 1ULL << 28,
	RTE_PGSIZE_512M = 1ULL << 29,
	RTE_PGSIZE_1G = 1ULL << 30,
	RTE_PGSIZE_4G = 1ULL << 32,
	RTE_PGSIZE_16G = 1ULL << 34,
};








/**
	* Force alignment to cache line.
	*/


/**
	* Force minimum cache line alignment.
	*/
typedef uint64_t phys_addr_t; 




/**
	* Physical memory segment descriptor.
	*/
struct rte_memseg
{
	phys_addr_t phys_addr; 



	union
{
		void *addr; 


		uint64_t addr_64; 


	};
	size_t len; 


	uint64_t hugepage_sz; 


	int32_t socket_id; 


	uint32_t nchannel; 


	uint32_t nrank; 


} __attribute__((__packed__));


/**
	* Lock page in physical memory and prevent from swapping.
	* @param virt
	* @return
	*/
int rte_mem_lock_page(const void *virt);


/**
	* Get physical address of any mapped virtual address in the current process.
	* It is found by browsing the /proc/self/pagemap special file.
	* The page must be locked.
	* @param virt
	* @return
	*/
phys_addr_t rte_mem_virt2phy(const void *virt);


/**
	* Get the layout of the available physical memory.
	* It can be useful for an application to have the full physical
	* memory layout to decide the size of a memory zone to reserve. This
	* table is stored in rte_config (see rte_eal_get_configuration()).
	* @return
	*  - On success, return a pointer to a read-only table of struct
	*  - On error, return NULL. This should not happen since it is a fatal
	*/
const struct rte_memseg *rte_eal_get_physmem_layout(void);


/**
	* Dump the physical memory layout to the console.
	* @param f
	*/
void rte_dump_physmem_layout(FILE *f);


/**
	* Get the total amount of available physical memory.
	* @return
	*/
uint64_t rte_eal_get_physmem_size(void);


/**
	* Get the number of memory channels.
	* @return
	*/
unsigned rte_memory_get_nchannel(void);


/**
	* Get the number of memory ranks.
	* @return
	*/
unsigned rte_memory_get_nrank(void);
static inline int rte_xen_dom0_supported(void)
{
	return 0;
}
static inline phys_addr_t
rte_mem_phy2mch(int32_t memseg_id __attribute__((__unused__)), const phys_addr_t phy_addr)
{
	return phy_addr;
}


/*-
	*/


/**
	* @file
	* Branch Prediction Helpers in RTE
	*/


/*-
	*/


/*
	* Derived from FreeBSD's bufring.h
	**************************************************************************
	* Copyright (c) 2007-2009 Kip Macy kmacy@freebsd.org
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* 1. Redistributions of source code must retain the above copyright notice,
	* 2. The name of Kip Macy nor the names of other
	* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
	* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	* POSSIBILITY OF SUCH DAMAGE.
	***************************************************************************/


/**
	* @file
	* RTE Ring
	* The Ring Manager is a fixed-size queue, implemented as a table of
	* pointers. Head and tail pointers are modified atomically, allowing
	* concurrent access to it. It has the following features:
	* - FIFO (First In First Out)
	* - Maximum size is fixed; the pointers are stored in a table.
	* - Lockless implementation.
	* - Multi- or single-consumer dequeue.
	* - Multi- or single-producer enqueue.
	* - Bulk dequeue.
	* - Bulk enqueue.
	* Note: the ring implementation is not preemptable. A lcore must not
	* be interrupted by another task that uses the same ring.
	*/


/*
	* Copyright (c) 1991, 1993
	*	The Regents of the University of California.  All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	*	@(#)queue.h	8.5 (Berkeley) 8/20/94
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* Atomic Operations
	* This file defines a generic API for atomic operations.
	*/


/*-
	*/


/**
	* Compiler barrier.
	* Guarantees that operation reordering does not occur at compile time
	* for operations directly before and after the barrier.
	*/





/**
	* Atomic compare and set.
	* (atomic) equivalent to:
	* @param dst
	* @param exp
	* @param src
	* @return
	*/
static inline int
rte_atomic16_cmpset(volatile uint16_t *dst, uint16_t exp, uint16_t src);


/**
	* The atomic counter structure.
	*/
typedef struct
{
	volatile int16_t cnt; 


} rte_atomic16_t;


/**
	* Static initializer for an atomic counter.
	*/


/**
	* Initialize an atomic counter.
	* @param v
	*/
static inline void
rte_atomic16_init(rte_atomic16_t *v)
{
	v->cnt = 0;
}


/**
	* Atomically read a 16-bit value from a counter.
	* @param v
	* @return
	*/
static inline int16_t
rte_atomic16_read(const rte_atomic16_t *v)
{
	return v->cnt;
}


/**
	* Atomically set a counter to a 16-bit value.
	* @param v
	* @param new_value
	*/
static inline void
rte_atomic16_set(rte_atomic16_t *v, int16_t new_value)
{
	v->cnt = new_value;
}


/**
	* Atomically add a 16-bit value to an atomic counter.
	* @param v
	* @param inc
	*/
static inline void
rte_atomic16_add(rte_atomic16_t *v, int16_t inc)
{
	__sync_fetch_and_add(&v->cnt, inc);
}


/**
	* Atomically subtract a 16-bit value from an atomic counter.
	* @param v
	* @param dec
	*/
static inline void
rte_atomic16_sub(rte_atomic16_t *v, int16_t dec)
{
	__sync_fetch_and_sub(&v->cnt, dec);
}


/**
	* Atomically increment a counter by one.
	* @param v
	*/
static inline void
rte_atomic16_inc(rte_atomic16_t *v);


/**
	* Atomically decrement a counter by one.
	* @param v
	*/
static inline void
rte_atomic16_dec(rte_atomic16_t *v);


/**
	* Atomically add a 16-bit value to a counter and return the result.
	* Atomically adds the 16-bits value (inc) to the atomic counter (v) and
	* returns the value of v after addition.
	* @param v
	* @param inc
	* @return
	*/
static inline int16_t
rte_atomic16_add_return(rte_atomic16_t *v, int16_t inc)
{
	return __sync_add_and_fetch(&v->cnt, inc);
}


/**
	* Atomically subtract a 16-bit value from a counter and return
	* the result.
	* Atomically subtracts the 16-bit value (inc) from the atomic counter
	* (v) and returns the value of v after the subtraction.
	* @param v
	* @param dec
	* @return
	*/
static inline int16_t
rte_atomic16_sub_return(rte_atomic16_t *v, int16_t dec)
{
	return __sync_sub_and_fetch(&v->cnt, dec);
}


/**
	* Atomically increment a 16-bit counter by one and test.
	* Atomically increments the atomic counter (v) by one and returns true if
	* the result is 0, or false in all other cases.
	* @param v
	* @return
	*/
static inline int rte_atomic16_inc_and_test(rte_atomic16_t *v);


/**
	* Atomically decrement a 16-bit counter by one and test.
	* Atomically decrements the atomic counter (v) by one and returns true if
	* the result is 0, or false in all other cases.
	* @param v
	* @return
	*/
static inline int rte_atomic16_dec_and_test(rte_atomic16_t *v);


/**
	* Atomically test and set a 16-bit atomic counter.
	* If the counter value is already set, return 0 (failed). Otherwise, set
	* the counter value to 1 and return 1 (success).
	* @param v
	* @return
	*/
static inline int rte_atomic16_test_and_set(rte_atomic16_t *v);


/**
	* Atomically set a 16-bit counter to 0.
	* @param v
	*/
static inline void rte_atomic16_clear(rte_atomic16_t *v)
{
	v->cnt = 0;
}





/**
	* Atomic compare and set.
	* (atomic) equivalent to:
	* @param dst
	* @param exp
	* @param src
	* @return
	*/
static inline int
rte_atomic32_cmpset(volatile uint32_t *dst, uint32_t exp, uint32_t src);


/**
	* The atomic counter structure.
	*/
typedef struct
{
	volatile int32_t cnt; 


} rte_atomic32_t;


/**
	* Static initializer for an atomic counter.
	*/


/**
	* Initialize an atomic counter.
	* @param v
	*/
static inline void
rte_atomic32_init(rte_atomic32_t *v)
{
	v->cnt = 0;
}


/**
	* Atomically read a 32-bit value from a counter.
	* @param v
	* @return
	*/
static inline int32_t
rte_atomic32_read(const rte_atomic32_t *v)
{
	return v->cnt;
}


/**
	* Atomically set a counter to a 32-bit value.
	* @param v
	* @param new_value
	*/
static inline void
rte_atomic32_set(rte_atomic32_t *v, int32_t new_value)
{
	v->cnt = new_value;
}


/**
	* Atomically add a 32-bit value to an atomic counter.
	* @param v
	* @param inc
	*/
static inline void
rte_atomic32_add(rte_atomic32_t *v, int32_t inc)
{
	__sync_fetch_and_add(&v->cnt, inc);
}


/**
	* Atomically subtract a 32-bit value from an atomic counter.
	* @param v
	* @param dec
	*/
static inline void
rte_atomic32_sub(rte_atomic32_t *v, int32_t dec)
{
	__sync_fetch_and_sub(&v->cnt, dec);
}


/**
	* Atomically increment a counter by one.
	* @param v
	*/
static inline void
rte_atomic32_inc(rte_atomic32_t *v);


/**
	* Atomically decrement a counter by one.
	* @param v
	*/
static inline void
rte_atomic32_dec(rte_atomic32_t *v);


/**
	* Atomically add a 32-bit value to a counter and return the result.
	* Atomically adds the 32-bits value (inc) to the atomic counter (v) and
	* returns the value of v after addition.
	* @param v
	* @param inc
	* @return
	*/
static inline int32_t
rte_atomic32_add_return(rte_atomic32_t *v, int32_t inc)
{
	return __sync_add_and_fetch(&v->cnt, inc);
}


/**
	* Atomically subtract a 32-bit value from a counter and return
	* the result.
	* Atomically subtracts the 32-bit value (inc) from the atomic counter
	* (v) and returns the value of v after the subtraction.
	* @param v
	* @param dec
	* @return
	*/
static inline int32_t
rte_atomic32_sub_return(rte_atomic32_t *v, int32_t dec)
{
	return __sync_sub_and_fetch(&v->cnt, dec);
}


/**
	* Atomically increment a 32-bit counter by one and test.
	* Atomically increments the atomic counter (v) by one and returns true if
	* the result is 0, or false in all other cases.
	* @param v
	* @return
	*/
static inline int rte_atomic32_inc_and_test(rte_atomic32_t *v);


/**
	* Atomically decrement a 32-bit counter by one and test.
	* Atomically decrements the atomic counter (v) by one and returns true if
	* the result is 0, or false in all other cases.
	* @param v
	* @return
	*/
static inline int rte_atomic32_dec_and_test(rte_atomic32_t *v);


/**
	* Atomically test and set a 32-bit atomic counter.
	* If the counter value is already set, return 0 (failed). Otherwise, set
	* the counter value to 1 and return 1 (success).
	* @param v
	* @return
	*/
static inline int rte_atomic32_test_and_set(rte_atomic32_t *v);


/**
	* Atomically set a 32-bit counter to 0.
	* @param v
	*/
static inline void rte_atomic32_clear(rte_atomic32_t *v)
{
	v->cnt = 0;
}





/**
	* An atomic compare and set function used by the mutex functions.
	* (atomic) equivalent to:
	* @param dst
	* @param exp
	* @param src
	* @return
	*/
static inline int
rte_atomic64_cmpset(volatile uint64_t *dst, uint64_t exp, uint64_t src);


/**
	* The atomic counter structure.
	*/
typedef struct
{
	volatile int64_t cnt; 


} rte_atomic64_t;


/**
	* Static initializer for an atomic counter.
	*/


/**
	* Initialize the atomic counter.
	* @param v
	*/
static inline void
rte_atomic64_init(rte_atomic64_t *v);


/**
	* Atomically read a 64-bit counter.
	* @param v
	* @return
	*/
static inline int64_t
rte_atomic64_read(rte_atomic64_t *v);


/**
	* Atomically set a 64-bit counter.
	* @param v
	* @param new_value
	*/
static inline void
rte_atomic64_set(rte_atomic64_t *v, int64_t new_value);


/**
	* Atomically add a 64-bit value to a counter.
	* @param v
	* @param inc
	*/
static inline void
rte_atomic64_add(rte_atomic64_t *v, int64_t inc);


/**
	* Atomically subtract a 64-bit value from a counter.
	* @param v
	* @param dec
	*/
static inline void
rte_atomic64_sub(rte_atomic64_t *v, int64_t dec);


/**
	* Atomically increment a 64-bit counter by one and test.
	* @param v
	*/
static inline void
rte_atomic64_inc(rte_atomic64_t *v);


/**
	* Atomically decrement a 64-bit counter by one and test.
	* @param v
	*/
static inline void
rte_atomic64_dec(rte_atomic64_t *v);


/**
	* Add a 64-bit value to an atomic counter and return the result.
	* Atomically adds the 64-bit value (inc) to the atomic counter (v) and
	* returns the value of v after the addition.
	* @param v
	* @param inc
	* @return
	*/
static inline int64_t
rte_atomic64_add_return(rte_atomic64_t *v, int64_t inc);


/**
	* Subtract a 64-bit value from an atomic counter and return the result.
	* Atomically subtracts the 64-bit value (dec) from the atomic counter (v)
	* and returns the value of v after the subtraction.
	* @param v
	* @param dec
	* @return
	*/
static inline int64_t
rte_atomic64_sub_return(rte_atomic64_t *v, int64_t dec);


/**
	* Atomically increment a 64-bit counter by one and test.
	* Atomically increments the atomic counter (v) by one and returns
	* true if the result is 0, or false in all other cases.
	* @param v
	* @return
	*/
static inline int rte_atomic64_inc_and_test(rte_atomic64_t *v);


/**
	* Atomically decrement a 64-bit counter by one and test.
	* Atomically decrements the atomic counter (v) by one and returns true if
	* the result is 0, or false in all other cases.
	* @param v
	* @return
	*/
static inline int rte_atomic64_dec_and_test(rte_atomic64_t *v);


/**
	* Atomically test and set a 64-bit atomic counter.
	* If the counter value is already set, return 0 (failed). Otherwise, set
	* the counter value to 1 and return 1 (success).
	* @param v
	* @return
	*/
static inline int rte_atomic64_test_and_set(rte_atomic64_t *v);


/**
	* Atomically set a 64-bit counter to 0.
	* @param v
	*/
static inline void rte_atomic64_clear(rte_atomic64_t *v);



static inline int
rte_atomic16_cmpset(volatile uint16_t *dst, uint16_t exp, uint16_t src)
{
	uint8_t res;
	__asm__ volatile(
			"lock ; "
			"cmpxchgw %[src], %[dst];"
			"sete %[res];"
			: [res] "=a" (res), 


					[dst] "=m" (*dst)
			: [src] "r" (src), 


					"a" (exp),
					"m" (*dst)
			: "memory"); 


	return res;
}
static inline int rte_atomic16_test_and_set(rte_atomic16_t *v)
{
	return rte_atomic16_cmpset((volatile uint16_t *)&v->cnt, 0, 1);
}
static inline void
rte_atomic16_inc(rte_atomic16_t *v)
{
	__asm__ volatile(
			"lock ; "
			"incw %[cnt]"
			: [cnt] "=m" (v->cnt) 


			: "m" (v->cnt) 


			);
}
static inline void
rte_atomic16_dec(rte_atomic16_t *v)
{
	__asm__ volatile(
			"lock ; "
			"decw %[cnt]"
			: [cnt] "=m" (v->cnt) 


			: "m" (v->cnt) 


			);
}
static inline int rte_atomic16_inc_and_test(rte_atomic16_t *v)
{
	uint8_t ret;
	__asm__ volatile(
			"lock ; "
			"incw %[cnt] ; "
			"sete %[ret]"
			: [cnt] "+m" (v->cnt), 


					[ret] "=qm" (ret)
			);
	return ret != 0;
}
static inline int rte_atomic16_dec_and_test(rte_atomic16_t *v)
{
	uint8_t ret;
	__asm__ volatile("lock ; "
			"decw %[cnt] ; "
			"sete %[ret]"
			: [cnt] "+m" (v->cnt), 


					[ret] "=qm" (ret)
			);
	return ret != 0;
}



static inline int
rte_atomic32_cmpset(volatile uint32_t *dst, uint32_t exp, uint32_t src)
{
	uint8_t res;
	__asm__ volatile(
			"lock ; "
			"cmpxchgl %[src], %[dst];"
			"sete %[res];"
			: [res] "=a" (res), 


					[dst] "=m" (*dst)
			: [src] "r" (src), 


					"a" (exp),
					"m" (*dst)
			: "memory"); 


	return res;
}
static inline int rte_atomic32_test_and_set(rte_atomic32_t *v)
{
	return rte_atomic32_cmpset((volatile uint32_t *)&v->cnt, 0, 1);
}
static inline void
rte_atomic32_inc(rte_atomic32_t *v)
{
	__asm__ volatile(
			"lock ; "
			"incl %[cnt]"
			: [cnt] "=m" (v->cnt) 


			: "m" (v->cnt) 


			);
}
static inline void
rte_atomic32_dec(rte_atomic32_t *v)
{
	__asm__ volatile(
			"lock ; "
			"decl %[cnt]"
			: [cnt] "=m" (v->cnt) 


			: "m" (v->cnt) 


			);
}
static inline int rte_atomic32_inc_and_test(rte_atomic32_t *v)
{
	uint8_t ret;
	__asm__ volatile(
			"lock ; "
			"incl %[cnt] ; "
			"sete %[ret]"
			: [cnt] "+m" (v->cnt), 


					[ret] "=qm" (ret)
			);
	return ret != 0;
}
static inline int rte_atomic32_dec_and_test(rte_atomic32_t *v)
{
	uint8_t ret;
	__asm__ volatile("lock ; "
			"decl %[cnt] ; "
			"sete %[ret]"
			: [cnt] "+m" (v->cnt), 


					[ret] "=qm" (ret)
			);
	return ret != 0;
}


/*-
	*/


/*
	* Inspired from FreeBSD src/sys/amd64/include/atomic.h
	* Copyright (c) 1998 Doug Rabson
	* All rights reserved.
	*/


/*-
	*/


/*-
	*/



static inline int
rte_atomic64_cmpset(volatile uint64_t *dst, uint64_t exp, uint64_t src)
{
	uint8_t res;
	__asm__ volatile(
			"lock ; "
			"cmpxchgq %[src], %[dst];"
			"sete %[res];"
			: [res] "=a" (res), 


					[dst] "=m" (*dst)
			: [src] "r" (src), 


					"a" (exp),
					"m" (*dst)
			: "memory"); 


	return res;
}
static inline void
rte_atomic64_init(rte_atomic64_t *v)
{
	v->cnt = 0;
}
static inline int64_t
rte_atomic64_read(rte_atomic64_t *v)
{
	return v->cnt;
}
static inline void
rte_atomic64_set(rte_atomic64_t *v, int64_t new_value)
{
	v->cnt = new_value;
}
static inline void
rte_atomic64_add(rte_atomic64_t *v, int64_t inc)
{
	__asm__ volatile(
			"lock ; "
			"addq %[inc], %[cnt]"
			: [cnt] "=m" (v->cnt) 


			: [inc] "ir" (inc), 


					"m" (v->cnt)
			);
}
static inline void
rte_atomic64_sub(rte_atomic64_t *v, int64_t dec)
{
	__asm__ volatile(
			"lock ; "
			"subq %[dec], %[cnt]"
			: [cnt] "=m" (v->cnt) 


			: [dec] "ir" (dec), 


					"m" (v->cnt)
			);
}
static inline void
rte_atomic64_inc(rte_atomic64_t *v)
{
	__asm__ volatile(
			"lock ; "
			"incq %[cnt]"
			: [cnt] "=m" (v->cnt) 


			: "m" (v->cnt) 


			);
}
static inline void
rte_atomic64_dec(rte_atomic64_t *v)
{
	__asm__ volatile(
			"lock ; "
			"decq %[cnt]"
			: [cnt] "=m" (v->cnt) 


			: "m" (v->cnt) 


			);
}
static inline int64_t
rte_atomic64_add_return(rte_atomic64_t *v, int64_t inc)
{
	int64_t prev = inc;
	__asm__ volatile(
			"lock ; "
			"xaddq %[prev], %[cnt]"
			: [prev] "+r" (prev), 


					[cnt] "=m" (v->cnt)
			: "m" (v->cnt) 


			);
	return prev + inc;
}
static inline int64_t
rte_atomic64_sub_return(rte_atomic64_t *v, int64_t dec)
{
	return rte_atomic64_add_return(v, -dec);
}
static inline int rte_atomic64_inc_and_test(rte_atomic64_t *v)
{
	uint8_t ret;
	__asm__ volatile(
			"lock ; "
			"incq %[cnt] ; "
			"sete %[ret]"
			: [cnt] "+m" (v->cnt), 


					[ret] "=qm" (ret)
			);
	return ret != 0;
}
static inline int rte_atomic64_dec_and_test(rte_atomic64_t *v)
{
	uint8_t ret;
	__asm__ volatile(
			"lock ; "
			"decq %[cnt] ; "
			"sete %[ret]"
			: [cnt] "+m" (v->cnt), 


					[ret] "=qm" (ret)
			);
	return ret != 0;
}
static inline int rte_atomic64_test_and_set(rte_atomic64_t *v)
{
	return rte_atomic64_cmpset((volatile uint64_t *)&v->cnt, 0, 1);
}
static inline void rte_atomic64_clear(rte_atomic64_t *v)
{
	v->cnt = 0;
}


/*-
	*/


/**
	* @file
	* Branch Prediction Helpers in RTE
	*/


/*-
	*/


/**
	* @file
	* RTE Memzone
	* The goal of the memzone allocator is to reserve contiguous
	* portions of physical memory. These zones are identified by a name.
	* The memzone descriptors are shared by all partitions and are
	* located in a known place of physical memory. This zone is accessed
	* using rte_eal_get_configuration(). The lookup (by name) of a
	* memory zone can be done in any partition and returns the same
	* physical address.
	* A reserved memory zone cannot be unreserved. The reservation shall
	* be done at initialization time only.
	*/


/*-
	*/


/*-
	*/


/**
	* A structure describing a memzone, which is a contiguous portion of
	* physical memory identified by a name.
	*/
struct rte_memzone
{
	char name[32]; 


	phys_addr_t phys_addr; 



	union
{
		void *addr; 


		uint64_t addr_64; 


	};
	size_t len; 


	uint64_t hugepage_sz; 


	int32_t socket_id; 


	uint32_t flags; 


	uint32_t memseg_id; 


} __attribute__((__packed__));


/**
	* Reserve a portion of physical memory.
	* This function reserves some memory and returns a pointer to a
	* correctly filled memzone descriptor. If the allocation cannot be
	* done, return NULL.
	* @param name
	* @param len
	* @param socket_id
	* @param flags
	* @return
	*/
const struct rte_memzone *rte_memzone_reserve(const char *name,
						     size_t len, int socket_id,
						     unsigned flags);


/**
	* Reserve a portion of physical memory with alignment on a specified
	* boundary.
	* This function reserves some memory with alignment on a specified
	* boundary, and returns a pointer to a correctly filled memzone
	* descriptor. If the allocation cannot be done or if the alignment
	* is not a power of 2, returns NULL.
	* @param name
	* @param len
	* @param socket_id
	* @param flags
	* @param align
	* @return
	*/
const struct rte_memzone *rte_memzone_reserve_aligned(const char *name,
			size_t len, int socket_id,
			unsigned flags, unsigned align);


/**
	* Reserve a portion of physical memory with specified alignment and
	* boundary.
	* This function reserves some memory with specified alignment and
	* boundary, and returns a pointer to a correctly filled memzone
	* descriptor. If the allocation cannot be done or if the alignment
	* or boundary are not a power of 2, returns NULL.
	* Memory buffer is reserved in a way, that it wouldn't cross specified
	* boundary. That implies that requested length should be less or equal
	* then boundary.
	* @param name
	* @param len
	* @param socket_id
	* @param flags
	* @param align
	* @param bound
	* @return
	*/
const struct rte_memzone *rte_memzone_reserve_bounded(const char *name,
			size_t len, int socket_id,
			unsigned flags, unsigned align, unsigned bound);


/**
	* Free a memzone.
	* @param mz
	* @return
	*  -EINVAL - invalid parameter.
	*  0 - success
	*/
int rte_memzone_free(const struct rte_memzone *mz);


/**
	* Lookup for a memzone.
	* Get a pointer to a descriptor of an already reserved memory
	* zone identified by the name given as an argument.
	* @param name
	* @return
	*/
const struct rte_memzone *rte_memzone_lookup(const char *name);


/**
	* Dump all reserved memzones to the console.
	* @param f
	*/
void rte_memzone_dump(FILE *f);


/**
	* Walk list of all memzones
	* @param func
	* @param arg
	*/
void rte_memzone_walk(void (*func)(const struct rte_memzone *, void *arg),
						  void *arg);
enum rte_ring_queue_behavior
{
	RTE_RING_QUEUE_FIXED = 0, 


	RTE_RING_QUEUE_VARIABLE 


};



struct rte_memzone; 




/**
	* An RTE ring structure.
	* The producer and the consumer have a head and a tail index. The particularity
	* of these index is that they are not between 0 and size(ring). These indexes
	* are between 0 and 2^32, and we mask their value when we access the ring[]
	* field. Thanks to this assumption, we can do subtractions between 2 index
	* values in a modulo-32bit base: that's why the overflow of the indexes is not
	* a problem.
	*/
struct rte_ring
{

/*
	 * Note: this field kept the RTE_MEMZONE_NAMESIZE size due to ABI
	 * compatibility requirements, it could be changed to RTE_RING_NAMESIZE
	 * next time the ABI changes
	 */
	char name[32]; 


	int flags; 


	const struct rte_memzone *memzone;




	struct prod
{
		uint32_t watermark; 


		uint32_t sp_enqueue; 


		uint32_t size; 


		uint32_t mask; 


		volatile uint32_t head; 


		volatile uint32_t tail; 


	} prod __attribute__((__aligned__(64)));


	struct cons
{
		uint32_t sc_dequeue; 


		uint32_t size; 


		uint32_t mask; 


		volatile uint32_t head; 


		volatile uint32_t tail; 


	} cons;
	void *ring[] __attribute__((__aligned__(64))); 

/**< Memory space of ring starts here.
	                                     * not volatile so need to be careful
	                                     * about compiler re-ordering */
};


/**
	* @internal When debug is enabled, store ring statistics.
	* @param r
	* @param name
	* @param n
	*/


/**
	* Calculate the memory size needed for a ring
	* This function returns the number of bytes needed for a ring, given
	* the number of elements in it. This value is the sum of the size of
	* the structure rte_ring and the size of the memory needed by the
	* objects pointers. The value is aligned to a cache line size.
	* @param count
	* @return
	*/
ssize_t rte_ring_get_memsize(unsigned count);


/**
	* Initialize a ring structure.
	* Initialize a ring structure in memory pointed by "r". The size of the
	* memory area must be large enough to store the ring structure and the
	* object table. It is advised to use rte_ring_get_memsize() to get the
	* appropriate size.
	* The ring size is set to *count*, which must be a power of two. Water
	* marking is disabled by default. The real usable ring size is
	* *count-1* instead of *count* to differentiate a free ring from an
	* empty ring.
	* The ring is not added in RTE_TAILQ_RING global list. Indeed, the
	* memory given by the caller may not be shareable among dpdk
	* processes.
	* @param r
	* @param name
	* @param count
	* @param flags
	* @return
	*/
int rte_ring_init(struct rte_ring *r, const char *name, unsigned count,
	unsigned flags);


/**
	* Create a new ring named *name* in memory.
	* This function uses ``memzone_reserve()`` to allocate memory. Then it
	* calls rte_ring_init() to initialize an empty ring.
	* The new ring size is set to *count*, which must be a power of
	* two. Water marking is disabled by default. The real usable ring size
	* is *count-1* instead of *count* to differentiate a free ring from an
	* empty ring.
	* The ring is added in RTE_TAILQ_RING list.
	* @param name
	* @param count
	* @param socket_id
	* @param flags
	* @return
	*/
struct rte_ring *rte_ring_create(const char *name, unsigned count,
					int socket_id, unsigned flags);


/**
	* De-allocate all memory used by the ring.
	* @param r
	*/
void rte_ring_free(struct rte_ring *r);


/**
	* Change the high water mark.
	* If *count* is 0, water marking is disabled. Otherwise, it is set to the
	* *count* value. The *count* value must be greater than 0 and less
	* than the ring size.
	* This function can be called at any time (not necessarily at
	* initialization).
	* @param r
	* @param count
	* @return
	*/
int rte_ring_set_water_mark(struct rte_ring *r, unsigned count);


/**
	* Dump the status of the ring to the console.
	* @param f
	* @param r
	*/
void rte_ring_dump(FILE *f, const struct rte_ring *r);


/* the actual enqueue of pointers on the ring.
	* Placed here since identical code needed in both
	* single and multi producer enqueue functions */


/* the actual copy of pointers on the ring to obj_table.
	* Placed here since identical code needed in both
	* single and multi consumer dequeue functions */


/**
	* @internal Enqueue several objects on the ring (multi-producers safe).
	* This function uses a "compare and set" instruction to move the
	* producer index atomically.
	* @param r
	* @param obj_table
	* @param n
	* @param behavior
	* @return
	*/
static inline int __attribute__((always_inline))
__rte_ring_mp_do_enqueue(struct rte_ring *r, void * const *obj_table,
				unsigned n, enum rte_ring_queue_behavior behavior)
{
	uint32_t prod_head, prod_next;
	uint32_t cons_tail, free_entries;
	const unsigned max = n;
	int success;
	unsigned i, rep = 0;
	uint32_t mask = r->prod.mask;
	int ret;

/* Avoid the unnecessary cmpset operation below, which is also
	 * potentially harmful when n equals 0. */
	if (n == 0)
		return 0;


	do
{


		n = max;
		prod_head = r->prod.head;
		cons_tail = r->cons.tail;

/* The subtraction is done between two unsigned 32bits value
		 * (the result is always modulo 32 bits even if we have
		 * prod_head > cons_tail). So 'free_entries' is always between 0
		 * and size(ring)-1. */
		free_entries = (mask + cons_tail - prod_head);


		if (__builtin_expect((n > free_entries),0))
{
			if (behavior == RTE_RING_QUEUE_FIXED)
{
				do {} while(0);
				return -ENOBUFS;
			}
			else
{


				if (__builtin_expect((free_entries == 0),0))
{
					do {} while(0);
					return 0;
				}
				n = free_entries;
			}
		}
		prod_next = prod_head + n;
		success = rte_atomic32_cmpset(&r->prod.head, prod_head,
						     prod_next);
	} while (__builtin_expect((success == 0),0));


	do { const uint32_t size = r->prod.size; uint32_t idx = prod_head & mask; if (__builtin_expect((idx + n < size),1)) { for (i = 0; i < (n & ((~(unsigned)0x3))); i+=4, idx+=4) { r->ring[idx] = obj_table[i]; r->ring[idx+1] = obj_table[i+1]; r->ring[idx+2] = obj_table[i+2]; r->ring[idx+3] = obj_table[i+3]; } switch (n & 0x3) { case 3: r->ring[idx++] = obj_table[i++]; case 2: r->ring[idx++] = obj_table[i++]; case 1: r->ring[idx++] = obj_table[i++]; } } else { for (i = 0; idx < size; i++, idx++) r->ring[idx] = obj_table[i]; for (idx = 0; i < n; i++, idx++) r->ring[idx] = obj_table[i]; } } while(0);
	do { __asm__ volatile ("" : : : "memory"); } while(0);


	if (__builtin_expect((((mask + 1) - free_entries + n) > r->prod.watermark),0))
{
		ret = (behavior == RTE_RING_QUEUE_FIXED) ? -EDQUOT :
				(int)(n | (1 << 31));
		do {} while(0);
	}
	else
{
		ret = (behavior == RTE_RING_QUEUE_FIXED) ? 0 : n;
		do {} while(0);
	}

/*
	 * If there are other enqueues in progress that preceded us,
	 * we need to wait for them to complete
	 */
	while (__builtin_expect((r->prod.tail != prod_head),0))
{
		rte_pause();

/* Set RTE_RING_PAUSE_REP_COUNT to avoid spin too long waiting
		 * for other thread finish. It gives pre-empted thread a chance
		 * to proceed and finish with ring dequeue operation. */
		if (0 &&
						++rep == 0)
{
			rep = 0;
			sched_yield();
		}
	}
	r->prod.tail = prod_next;
	return ret;
}


/**
	* @internal Enqueue several objects on a ring (NOT multi-producers safe).
	* @param r
	* @param obj_table
	* @param n
	* @param behavior
	* @return
	*/
static inline int __attribute__((always_inline))
__rte_ring_sp_do_enqueue(struct rte_ring *r, void * const *obj_table,
				unsigned n, enum rte_ring_queue_behavior behavior)
{
	uint32_t prod_head, cons_tail;
	uint32_t prod_next, free_entries;
	unsigned i;
	uint32_t mask = r->prod.mask;
	int ret;
	prod_head = r->prod.head;
	cons_tail = r->cons.tail;

/* The subtraction is done between two unsigned 32bits value
	 * (the result is always modulo 32 bits even if we have
	 * prod_head > cons_tail). So 'free_entries' is always between 0
	 * and size(ring)-1. */
	free_entries = mask + cons_tail - prod_head;


	if (__builtin_expect((n > free_entries),0))
{
		if (behavior == RTE_RING_QUEUE_FIXED)
{
			do {} while(0);
			return -ENOBUFS;
		}
		else
{


			if (__builtin_expect((free_entries == 0),0))
{
				do {} while(0);
				return 0;
			}
			n = free_entries;
		}
	}
	prod_next = prod_head + n;
	r->prod.head = prod_next;


	do { const uint32_t size = r->prod.size; uint32_t idx = prod_head & mask; if (__builtin_expect((idx + n < size),1)) { for (i = 0; i < (n & ((~(unsigned)0x3))); i+=4, idx+=4) { r->ring[idx] = obj_table[i]; r->ring[idx+1] = obj_table[i+1]; r->ring[idx+2] = obj_table[i+2]; r->ring[idx+3] = obj_table[i+3]; } switch (n & 0x3) { case 3: r->ring[idx++] = obj_table[i++]; case 2: r->ring[idx++] = obj_table[i++]; case 1: r->ring[idx++] = obj_table[i++]; } } else { for (i = 0; idx < size; i++, idx++) r->ring[idx] = obj_table[i]; for (idx = 0; i < n; i++, idx++) r->ring[idx] = obj_table[i]; } } while(0);
	do { __asm__ volatile ("" : : : "memory"); } while(0);


	if (__builtin_expect((((mask + 1) - free_entries + n) > r->prod.watermark),0))
{
		ret = (behavior == RTE_RING_QUEUE_FIXED) ? -EDQUOT :
			(int)(n | (1 << 31));
		do {} while(0);
	}
	else
{
		ret = (behavior == RTE_RING_QUEUE_FIXED) ? 0 : n;
		do {} while(0);
	}
	r->prod.tail = prod_next;
	return ret;
}


/**
	* @internal Dequeue several objects from a ring (multi-consumers safe). When
	* the request objects are more than the available objects, only dequeue the
	* actual number of objects
	* This function uses a "compare and set" instruction to move the
	* consumer index atomically.
	* @param r
	* @param obj_table
	* @param n
	* @param behavior
	* @return
	*/
static inline int __attribute__((always_inline))
__rte_ring_mc_do_dequeue(struct rte_ring *r, void **obj_table,
			unsigned n, enum rte_ring_queue_behavior behavior)
{
	uint32_t cons_head, prod_tail;
	uint32_t cons_next, entries;
	const unsigned max = n;
	int success;
	unsigned i, rep = 0;
	uint32_t mask = r->prod.mask;

/* Avoid the unnecessary cmpset operation below, which is also
	 * potentially harmful when n equals 0. */
	if (n == 0)
		return 0;


	do
{


		n = max;
		cons_head = r->cons.head;
		prod_tail = r->prod.tail;

/* The subtraction is done between two unsigned 32bits value
		 * (the result is always modulo 32 bits even if we have
		 * cons_head > prod_tail). So 'entries' is always between 0
		 * and size(ring)-1. */
		entries = (prod_tail - cons_head);


		if (n > entries)
{
			if (behavior == RTE_RING_QUEUE_FIXED)
{
				do {} while(0);
				return -ENOENT;
			}
			else
{
				if (__builtin_expect((entries == 0),0)){
					do {} while(0);
					return 0;
				}
				n = entries;
			}
		}
		cons_next = cons_head + n;
		success = rte_atomic32_cmpset(&r->cons.head, cons_head,
						     cons_next);
	} while (__builtin_expect((success == 0),0));


	do { uint32_t idx = cons_head & mask; const uint32_t size = r->cons.size; if (__builtin_expect((idx + n < size),1)) { for (i = 0; i < (n & (~(unsigned)0x3)); i+=4, idx+=4) { obj_table[i] = r->ring[idx]; obj_table[i+1] = r->ring[idx+1]; obj_table[i+2] = r->ring[idx+2]; obj_table[i+3] = r->ring[idx+3]; } switch (n & 0x3) { case 3: obj_table[i++] = r->ring[idx++]; case 2: obj_table[i++] = r->ring[idx++]; case 1: obj_table[i++] = r->ring[idx++]; } } else { for (i = 0; idx < size; i++, idx++) obj_table[i] = r->ring[idx]; for (idx = 0; i < n; i++, idx++) obj_table[i] = r->ring[idx]; } } while (0);
	do { __asm__ volatile ("" : : : "memory"); } while(0);

/*
	 * If there are other dequeues in progress that preceded us,
	 * we need to wait for them to complete
	 */
	while (__builtin_expect((r->cons.tail != cons_head),0))
{
		rte_pause();

/* Set RTE_RING_PAUSE_REP_COUNT to avoid spin too long waiting
		 * for other thread finish. It gives pre-empted thread a chance
		 * to proceed and finish with ring dequeue operation. */
		if (0 &&
						++rep == 0)
{
			rep = 0;
			sched_yield();
		}
	}
	do {} while(0);
	r->cons.tail = cons_next;
	return behavior == RTE_RING_QUEUE_FIXED ? 0 : n;
}


/**
	* @internal Dequeue several objects from a ring (NOT multi-consumers safe).
	* When the request objects are more than the available objects, only dequeue
	* the actual number of objects
	* @param r
	* @param obj_table
	* @param n
	* @param behavior
	* @return
	*/
static inline int __attribute__((always_inline))
__rte_ring_sc_do_dequeue(struct rte_ring *r, void **obj_table,
			unsigned n, enum rte_ring_queue_behavior behavior)
{
	uint32_t cons_head, prod_tail;
	uint32_t cons_next, entries;
	unsigned i;
	uint32_t mask = r->prod.mask;
	cons_head = r->cons.head;
	prod_tail = r->prod.tail;

/* The subtraction is done between two unsigned 32bits value
	 * (the result is always modulo 32 bits even if we have
	 * cons_head > prod_tail). So 'entries' is always between 0
	 * and size(ring)-1. */
	entries = prod_tail - cons_head;
	if (n > entries)
{
		if (behavior == RTE_RING_QUEUE_FIXED)
{
			do {} while(0);
			return -ENOENT;
		}
		else
{
			if (__builtin_expect((entries == 0),0)){
				do {} while(0);
				return 0;
			}
			n = entries;
		}
	}
	cons_next = cons_head + n;
	r->cons.head = cons_next;


	do { uint32_t idx = cons_head & mask; const uint32_t size = r->cons.size; if (__builtin_expect((idx + n < size),1)) { for (i = 0; i < (n & (~(unsigned)0x3)); i+=4, idx+=4) { obj_table[i] = r->ring[idx]; obj_table[i+1] = r->ring[idx+1]; obj_table[i+2] = r->ring[idx+2]; obj_table[i+3] = r->ring[idx+3]; } switch (n & 0x3) { case 3: obj_table[i++] = r->ring[idx++]; case 2: obj_table[i++] = r->ring[idx++]; case 1: obj_table[i++] = r->ring[idx++]; } } else { for (i = 0; idx < size; i++, idx++) obj_table[i] = r->ring[idx]; for (idx = 0; i < n; i++, idx++) obj_table[i] = r->ring[idx]; } } while (0);
	do { __asm__ volatile ("" : : : "memory"); } while(0);
	do {} while(0);
	r->cons.tail = cons_next;
	return behavior == RTE_RING_QUEUE_FIXED ? 0 : n;
}


/**
	* Enqueue several objects on the ring (multi-producers safe).
	* This function uses a "compare and set" instruction to move the
	* producer index atomically.
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_mp_enqueue_bulk(struct rte_ring *r, void * const *obj_table,
				unsigned n)
{
	return __rte_ring_mp_do_enqueue(r, obj_table, n, RTE_RING_QUEUE_FIXED);
}


/**
	* Enqueue several objects on a ring (NOT multi-producers safe).
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_sp_enqueue_bulk(struct rte_ring *r, void * const *obj_table,
				unsigned n)
{
	return __rte_ring_sp_do_enqueue(r, obj_table, n, RTE_RING_QUEUE_FIXED);
}


/**
	* Enqueue several objects on a ring.
	* This function calls the multi-producer or the single-producer
	* version depending on the default behavior that was specified at
	* ring creation time (see flags).
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_enqueue_bulk(struct rte_ring *r, void * const *obj_table,
						  unsigned n)
{
	if (r->prod.sp_enqueue)
		return rte_ring_sp_enqueue_bulk(r, obj_table, n);
	else
		return rte_ring_mp_enqueue_bulk(r, obj_table, n);
}


/**
	* Enqueue one object on a ring (multi-producers safe).
	* This function uses a "compare and set" instruction to move the
	* producer index atomically.
	* @param r
	* @param obj
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_mp_enqueue(struct rte_ring *r, void *obj)
{
	return rte_ring_mp_enqueue_bulk(r, &obj, 1);
}


/**
	* Enqueue one object on a ring (NOT multi-producers safe).
	* @param r
	* @param obj
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_sp_enqueue(struct rte_ring *r, void *obj)
{
	return rte_ring_sp_enqueue_bulk(r, &obj, 1);
}


/**
	* Enqueue one object on a ring.
	* This function calls the multi-producer or the single-producer
	* version, depending on the default behaviour that was specified at
	* ring creation time (see flags).
	* @param r
	* @param obj
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_enqueue(struct rte_ring *r, void *obj)
{
	if (r->prod.sp_enqueue)
		return rte_ring_sp_enqueue(r, obj);
	else
		return rte_ring_mp_enqueue(r, obj);
}


/**
	* Dequeue several objects from a ring (multi-consumers safe).
	* This function uses a "compare and set" instruction to move the
	* consumer index atomically.
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_mc_dequeue_bulk(struct rte_ring *r, void **obj_table, unsigned n)
{
	return __rte_ring_mc_do_dequeue(r, obj_table, n, RTE_RING_QUEUE_FIXED);
}


/**
	* Dequeue several objects from a ring (NOT multi-consumers safe).
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_sc_dequeue_bulk(struct rte_ring *r, void **obj_table, unsigned n)
{
	return __rte_ring_sc_do_dequeue(r, obj_table, n, RTE_RING_QUEUE_FIXED);
}


/**
	* Dequeue several objects from a ring.
	* This function calls the multi-consumers or the single-consumer
	* version, depending on the default behaviour that was specified at
	* ring creation time (see flags).
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_dequeue_bulk(struct rte_ring *r, void **obj_table, unsigned n)
{
	if (r->cons.sc_dequeue)
		return rte_ring_sc_dequeue_bulk(r, obj_table, n);
	else
		return rte_ring_mc_dequeue_bulk(r, obj_table, n);
}


/**
	* Dequeue one object from a ring (multi-consumers safe).
	* This function uses a "compare and set" instruction to move the
	* consumer index atomically.
	* @param r
	* @param obj_p
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_mc_dequeue(struct rte_ring *r, void **obj_p)
{
	return rte_ring_mc_dequeue_bulk(r, obj_p, 1);
}


/**
	* Dequeue one object from a ring (NOT multi-consumers safe).
	* @param r
	* @param obj_p
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_sc_dequeue(struct rte_ring *r, void **obj_p)
{
	return rte_ring_sc_dequeue_bulk(r, obj_p, 1);
}


/**
	* Dequeue one object from a ring.
	* This function calls the multi-consumers or the single-consumer
	* version depending on the default behaviour that was specified at
	* ring creation time (see flags).
	* @param r
	* @param obj_p
	* @return
	*/
static inline int __attribute__((always_inline))
rte_ring_dequeue(struct rte_ring *r, void **obj_p)
{
	if (r->cons.sc_dequeue)
		return rte_ring_sc_dequeue(r, obj_p);
	else
		return rte_ring_mc_dequeue(r, obj_p);
}


/**
	* Test if a ring is full.
	* @param r
	* @return
	*/
static inline int
rte_ring_full(const struct rte_ring *r)
{
	uint32_t prod_tail = r->prod.tail;
	uint32_t cons_tail = r->cons.tail;
	return ((cons_tail - prod_tail - 1) & r->prod.mask) == 0;
}


/**
	* Test if a ring is empty.
	* @param r
	* @return
	*/
static inline int
rte_ring_empty(const struct rte_ring *r)
{
	uint32_t prod_tail = r->prod.tail;
	uint32_t cons_tail = r->cons.tail;
	return !!(cons_tail == prod_tail);
}


/**
	* Return the number of entries in a ring.
	* @param r
	* @return
	*/
static inline unsigned
rte_ring_count(const struct rte_ring *r)
{
	uint32_t prod_tail = r->prod.tail;
	uint32_t cons_tail = r->cons.tail;
	return (prod_tail - cons_tail) & r->prod.mask;
}


/**
	* Return the number of free entries in a ring.
	* @param r
	* @return
	*/
static inline unsigned
rte_ring_free_count(const struct rte_ring *r)
{
	uint32_t prod_tail = r->prod.tail;
	uint32_t cons_tail = r->cons.tail;
	return (cons_tail - prod_tail - 1) & r->prod.mask;
}


/**
	* Dump the status of all rings on the console
	* @param f
	*/
void rte_ring_list_dump(FILE *f);


/**
	* Search a ring from its name
	* @param name
	* @return
	*/
struct rte_ring *rte_ring_lookup(const char *name);


/**
	* Enqueue several objects on the ring (multi-producers safe).
	* This function uses a "compare and set" instruction to move the
	* producer index atomically.
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline unsigned __attribute__((always_inline))
rte_ring_mp_enqueue_burst(struct rte_ring *r, void * const *obj_table,
				unsigned n)
{
	return __rte_ring_mp_do_enqueue(r, obj_table, n, RTE_RING_QUEUE_VARIABLE);
}


/**
	* Enqueue several objects on a ring (NOT multi-producers safe).
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline unsigned __attribute__((always_inline))
rte_ring_sp_enqueue_burst(struct rte_ring *r, void * const *obj_table,
				unsigned n)
{
	return __rte_ring_sp_do_enqueue(r, obj_table, n, RTE_RING_QUEUE_VARIABLE);
}


/**
	* Enqueue several objects on a ring.
	* This function calls the multi-producer or the single-producer
	* version depending on the default behavior that was specified at
	* ring creation time (see flags).
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline unsigned __attribute__((always_inline))
rte_ring_enqueue_burst(struct rte_ring *r, void * const *obj_table,
						  unsigned n)
{
	if (r->prod.sp_enqueue)
		return rte_ring_sp_enqueue_burst(r, obj_table, n);
	else
		return rte_ring_mp_enqueue_burst(r, obj_table, n);
}


/**
	* Dequeue several objects from a ring (multi-consumers safe). When the request
	* objects are more than the available objects, only dequeue the actual number
	* of objects
	* This function uses a "compare and set" instruction to move the
	* consumer index atomically.
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline unsigned __attribute__((always_inline))
rte_ring_mc_dequeue_burst(struct rte_ring *r, void **obj_table, unsigned n)
{
	return __rte_ring_mc_do_dequeue(r, obj_table, n, RTE_RING_QUEUE_VARIABLE);
}


/**
	* Dequeue several objects from a ring (NOT multi-consumers safe).When the
	* request objects are more than the available objects, only dequeue the
	* actual number of objects
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline unsigned __attribute__((always_inline))
rte_ring_sc_dequeue_burst(struct rte_ring *r, void **obj_table, unsigned n)
{
	return __rte_ring_sc_do_dequeue(r, obj_table, n, RTE_RING_QUEUE_VARIABLE);
}


/**
	* Dequeue multiple objects from a ring up to a maximum number.
	* This function calls the multi-consumers or the single-consumer
	* version, depending on the default behaviour that was specified at
	* ring creation time (see flags).
	* @param r
	* @param obj_table
	* @param n
	* @return
	*/
static inline unsigned __attribute__((always_inline))
rte_ring_dequeue_burst(struct rte_ring *r, void **obj_table, unsigned n)
{
	if (r->cons.sc_dequeue)
		return rte_ring_sc_dequeue_burst(r, obj_table, n);
	else
		return rte_ring_mc_dequeue_burst(r, obj_table, n);
}


/*-
	*/


/*-
	*/


/**
	* A structure that stores a per-core object cache.
	*/
struct rte_mempool_cache
{
	uint32_t size; 


	uint32_t flushthresh; 


	uint32_t len; 



/*
	 * Cache is allocated to this size to allow it to overflow in certain
	 * cases to avoid needless emptying of cache.
	 */
	void *objs[512 * 3]; 


} __attribute__((__aligned__(64)));


/**
	* A structure that stores the size of mempool elements.
	*/
struct rte_mempool_objsz
{
	uint32_t elt_size; 


	uint32_t header_size; 


	uint32_t trailer_size; 


	uint32_t total_size;


};











/**
	* Mempool object header structure
	* Each object stored in mempools are prefixed by this header structure,
	* it allows to retrieve the mempool pointer from the object and to
	* iterate on all objects attached to a mempool. When debug is enabled,
	* a cookie is also added in this structure preventing corruptions and
	* double-frees.
	*/
struct rte_mempool_objhdr
{
	struct { struct rte_mempool_objhdr *stqe_next; } next; 


	struct rte_mempool *mp; 


	phys_addr_t physaddr; 


};


/**
	* A list of object headers type
	*/
struct rte_mempool_objhdr_list { struct rte_mempool_objhdr *stqh_first; struct rte_mempool_objhdr **stqh_last; };


/**
	* A list of memory where objects are stored
	*/
struct rte_mempool_memhdr_list { struct rte_mempool_memhdr *stqh_first; struct rte_mempool_memhdr **stqh_last; };


/**
	* Callback used to free a memory chunk
	*/
typedef void (rte_mempool_memchunk_free_cb_t)(struct rte_mempool_memhdr *memhdr,
	void *opaque);


/**
	* Mempool objects memory header structure
	* The memory chunks where objects are stored. Each chunk is virtually
	* and physically contiguous.
	*/
struct rte_mempool_memhdr
{
	struct { struct rte_mempool_memhdr *stqe_next; } next; 


	struct rte_mempool *mp; 


	void *addr; 


	phys_addr_t phys_addr; 


	size_t len; 


	rte_mempool_memchunk_free_cb_t *free_cb; 


	void *opaque; 


};


/**
	* The RTE mempool structure.
	*/
struct rte_mempool
{

/*
	 * Note: this field kept the RTE_MEMZONE_NAMESIZE size due to ABI
	 * compatibility requirements, it could be changed to
	 * RTE_MEMPOOL_NAMESIZE next time the ABI changes
	 */
	char name[32]; 



	union
{
		void *pool_data; 


		uint64_t pool_id; 


	};
	void *pool_config; 


	const struct rte_memzone *mz; 


	int flags; 


	int socket_id; 


	uint32_t size; 


	uint32_t cache_size;


	uint32_t elt_size; 


	uint32_t header_size; 


	uint32_t trailer_size; 


	unsigned private_data_size; 



/**
	 * Index into rte_mempool_ops_table array of mempool ops
	 * structs, which contain callback function pointers.
	 * We're using an index here rather than pointers to the callbacks
	 * to facilitate any secondary processes that may want to use
	 * this mempool.
	 */
	int32_t ops_index;
	struct rte_mempool_cache *local_cache; 


	uint32_t populated_size; 


	struct rte_mempool_objhdr_list elt_list; 


	uint32_t nb_mem_chunks; 


	struct rte_mempool_memhdr_list mem_list; 


} __attribute__((__aligned__(64)));


/**
	* @internal When debug is enabled, store some statistics.
	* @param mp
	* @param name
	* @param n
	*/


/**
	* Calculate the size of the mempool header.
	* @param mp
	* @param cs
	*/



static inline struct rte_mempool_objhdr *__mempool_get_header(void *obj)
{
	return (struct rte_mempool_objhdr *)((void*)((uintptr_t)obj - (sizeof(struct rte_mempool_objhdr))));
}


/**
	* Return a pointer to the mempool owning this object.
	* @param obj
	* @return
	*/
static inline struct rte_mempool *rte_mempool_from_obj(void *obj)
{
	struct rte_mempool_objhdr *hdr = __mempool_get_header(obj);
	return hdr->mp;
}



static inline struct rte_mempool_objtlr *__mempool_get_trailer(void *obj)
{
	struct rte_mempool *mp = rte_mempool_from_obj(obj);
	return (struct rte_mempool_objtlr *)((void*)((uintptr_t)(obj) + (mp->elt_size)));
}


/**
	* @internal Check and update cookies or panic.
	* @param mp
	* @param obj_table_const
	* @param n
	* @param free
	*/
void rte_mempool_check_cookies(const struct rte_mempool *mp,
	void * const *obj_table_const, unsigned n, int free);


/**
	* Prototype for implementation specific data provisioning function.
	* The function should provide the implementation specific memory for
	* for use by the other mempool ops functions in a given mempool ops struct.
	* E.g. the default ops provides an instance of the rte_ring for this purpose.
	* it will most likely point to a different type of data structure, and
	* will be transparent to the application programmer.
	* This function should set mp->pool_data.
	*/
typedef int (*rte_mempool_alloc_t)(struct rte_mempool *mp);


/**
	* Free the opaque private data pointed to by mp->pool_data pointer.
	*/
typedef void (*rte_mempool_free_t)(struct rte_mempool *mp);


/**
	* Enqueue an object into the external pool.
	*/
typedef int (*rte_mempool_enqueue_t)(struct rte_mempool *mp,
		void * const *obj_table, unsigned int n);


/**
	* Dequeue an object from the external pool.
	*/
typedef int (*rte_mempool_dequeue_t)(struct rte_mempool *mp,
		void **obj_table, unsigned int n);


/**
	* Return the number of available objects in the external pool.
	*/
typedef unsigned (*rte_mempool_get_count)(const struct rte_mempool *mp);



struct rte_mempool_ops
{
	char name[32]; 


	rte_mempool_alloc_t alloc; 


	rte_mempool_free_t free; 


	rte_mempool_enqueue_t enqueue; 


	rte_mempool_dequeue_t dequeue; 


	rte_mempool_get_count get_count; 


} __attribute__((__aligned__(64)));


/**
	* Structure storing the table of registered ops structs, each of which contain
	* the function pointers for the mempool ops functions.
	* Each process has its own storage for this ops struct array so that
	* the mempools can be shared across primary and secondary processes.
	* The indices used to access the array are valid across processes, whereas
	* any function pointers stored directly in the mempool struct would not be.
	* This results in us simply having "ops_index" in the mempool struct.
	*/
struct rte_mempool_ops_table
{
	rte_spinlock_t sl; 


	uint32_t num_ops; 



/**
	 * Storage for all possible ops structs.
	 */
	struct rte_mempool_ops ops[16];
} __attribute__((__aligned__(64)));





/**
	* @internal Get the mempool ops struct from its index.
	* @param ops_index
	* @return
	*/
static inline struct rte_mempool_ops *
rte_mempool_get_ops(int ops_index)
{
	do { if (__builtin_expect((!((ops_index >= 0) && (ops_index < 16))),0)) __rte_panic(__func__, "line %d\tassert \"" "(ops_index >= 0) && (ops_index < RTE_MEMPOOL_MAX_OPS_IDX)" "\" failed\n" "%.0s", 435, "dummy"); } while (0);
	return &rte_mempool_ops_table.ops[ops_index];
}


/**
	* @internal Wrapper for mempool_ops alloc callback.
	* @param mp
	* @return
	*/
int
rte_mempool_ops_alloc(struct rte_mempool *mp);


/**
	* @internal Wrapper for mempool_ops dequeue callback.
	* @param mp
	* @param obj_table
	* @param n
	* @return
	*/
static inline int
rte_mempool_ops_dequeue_bulk(struct rte_mempool *mp,
		void **obj_table, unsigned n)
{
	struct rte_mempool_ops *ops;
	ops = rte_mempool_get_ops(mp->ops_index);
	return ops->dequeue(mp, obj_table, n);
}


/**
	* @internal wrapper for mempool_ops enqueue callback.
	* @param mp
	* @param obj_table
	* @param n
	* @return
	*/
static inline int
rte_mempool_ops_enqueue_bulk(struct rte_mempool *mp, void * const *obj_table,
		unsigned n)
{
	struct rte_mempool_ops *ops;
	ops = rte_mempool_get_ops(mp->ops_index);
	return ops->enqueue(mp, obj_table, n);
}


/**
	* @internal wrapper for mempool_ops get_count callback.
	* @param mp
	* @return
	*/
unsigned
rte_mempool_ops_get_count(const struct rte_mempool *mp);


/**
	* @internal wrapper for mempool_ops free callback.
	* @param mp
	*/
void
rte_mempool_ops_free(struct rte_mempool *mp);


/**
	* Set the ops of a mempool.
	* This can only be done on a mempool that is not populated, i.e. just after
	* a call to rte_mempool_create_empty().
	* @param mp
	* @param name
	* @param pool_config
	* @return
	*/
int
rte_mempool_set_ops_byname(struct rte_mempool *mp, const char *name,
		void *pool_config);


/**
	* Register mempool operations.
	* @param ops
	* @return
	*/
int rte_mempool_register_ops(const struct rte_mempool_ops *ops);


/**
	* Macro to statically register the ops of a mempool handler.
	* Note that the rte_mempool_register_ops fails silently here when
	* more then RTE_MEMPOOL_MAX_OPS_IDX is registered.
	*/


/**
	* An object callback function for mempool.
	* Used by rte_mempool_create() and rte_mempool_obj_iter().
	*/
typedef void (rte_mempool_obj_cb_t)(struct rte_mempool *mp,
		void *opaque, void *obj, unsigned obj_idx);
typedef rte_mempool_obj_cb_t rte_mempool_obj_ctor_t; 




/**
	* A memory callback function for mempool.
	* Used by rte_mempool_mem_iter().
	*/
typedef void (rte_mempool_mem_cb_t)(struct rte_mempool *mp,
		void *opaque, struct rte_mempool_memhdr *memhdr,
		unsigned mem_idx);


/**
	* A mempool constructor callback function.
	* Arguments are the mempool and the opaque pointer given by the user in
	* rte_mempool_create().
	*/
typedef void (rte_mempool_ctor_t)(struct rte_mempool *, void *);


/**
	* Create a new mempool named *name* in memory.
	* This function uses ``memzone_reserve()`` to allocate memory. The
	* pool contains n elements of elt_size. Its size is set to n.
	* All elements of the mempool are allocated together with the mempool header,
	* in one physically continuous chunk of memory.
	* @param name
	* @param n
	* @param elt_size
	* @param cache_size
	* @param private_data_size
	* @param mp_init
	* @param mp_init_arg
	* @param obj_init
	* @param obj_init_arg
	* @param socket_id
	* @param flags
	* @return
	*/
struct rte_mempool *
rte_mempool_create(const char *name, unsigned n, unsigned elt_size,
					unsigned cache_size, unsigned private_data_size,
					rte_mempool_ctor_t *mp_init, void *mp_init_arg,
					rte_mempool_obj_cb_t *obj_init, void *obj_init_arg,
					int socket_id, unsigned flags);


/**
	* Create a new mempool named *name* in memory.
	* The pool contains n elements of elt_size. Its size is set to n.
	* This function uses ``memzone_reserve()`` to allocate the mempool header
	* (and the objects if vaddr is NULL).
	* Depending on the input parameters, mempool elements can be either allocated
	* together with the mempool header, or an externally provided memory buffer
	* could be used to store mempool objects. In later case, that external
	* memory buffer can consist of set of disjoint physical pages.
	* @param name
	* @param n
	* @param elt_size
	* @param cache_size
	* @param private_data_size
	* @param mp_init
	* @param mp_init_arg
	* @param obj_init
	* @param obj_init_arg
	* @param socket_id
	* @param flags
	* @param vaddr
	* @param paddr
	* @param pg_num
	* @param pg_shift
	* @return
	*/
struct rte_mempool *
rte_mempool_xmem_create(const char *name, unsigned n, unsigned elt_size,
		unsigned cache_size, unsigned private_data_size,
		rte_mempool_ctor_t *mp_init, void *mp_init_arg,
		rte_mempool_obj_cb_t *obj_init, void *obj_init_arg,
		int socket_id, unsigned flags, void *vaddr,
		const phys_addr_t paddr[], uint32_t pg_num, uint32_t pg_shift);


/**
	* Create an empty mempool
	* The mempool is allocated and initialized, but it is not populated: no
	* memory is allocated for the mempool elements. The user has to call
	* rte_mempool_populate_*() or to add memory chunks to the pool. Once
	* populated, the user may also want to initialize each object with
	* rte_mempool_obj_iter().
	* @param name
	* @param n
	* @param elt_size
	* @param cache_size
	* @param private_data_size
	* @param socket_id
	* @param flags
	* @return
	*/
struct rte_mempool *
rte_mempool_create_empty(const char *name, unsigned n, unsigned elt_size,
	unsigned cache_size, unsigned private_data_size,
	int socket_id, unsigned flags);


/**
	* Free a mempool
	* Unlink the mempool from global list, free the memory chunks, and all
	* memory referenced by the mempool. The objects must not be used by
	* other cores as they will be freed.
	* @param mp
	*/
void
rte_mempool_free(struct rte_mempool *mp);


/**
	* Add physically contiguous memory for objects in the pool at init
	* Add a virtually and physically contiguous memory chunk in the pool
	* where objects can be instanciated.
	* @param mp
	* @param vaddr
	* @param paddr
	* @param len
	* @param free_cb
	* @param opaque
	* @return
	*/
int rte_mempool_populate_phys(struct rte_mempool *mp, char *vaddr,
	phys_addr_t paddr, size_t len, rte_mempool_memchunk_free_cb_t *free_cb,
	void *opaque);


/**
	* Add physical memory for objects in the pool at init
	* Add a virtually contiguous memory chunk in the pool where objects can
	* be instanciated. The physical addresses corresponding to the virtual
	* area are described in paddr[], pg_num, pg_shift.
	* @param mp
	* @param vaddr
	* @param paddr
	* @param pg_num
	* @param pg_shift
	* @param free_cb
	* @param opaque
	* @return
	*/
int rte_mempool_populate_phys_tab(struct rte_mempool *mp, char *vaddr,
	const phys_addr_t paddr[], uint32_t pg_num, uint32_t pg_shift,
	rte_mempool_memchunk_free_cb_t *free_cb, void *opaque);


/**
	* Add virtually contiguous memory for objects in the pool at init
	* Add a virtually contiguous memory chunk in the pool where objects can
	* be instanciated.
	* @param mp
	* @param addr
	* @param len
	* @param pg_sz
	* @param free_cb
	* @param opaque
	* @return
	*/
int
rte_mempool_populate_virt(struct rte_mempool *mp, char *addr,
	size_t len, size_t pg_sz, rte_mempool_memchunk_free_cb_t *free_cb,
	void *opaque);


/**
	* Add memory for objects in the pool at init
	* This is the default function used by rte_mempool_create() to populate
	* the mempool. It adds memory allocated using rte_memzone_reserve().
	* @param mp
	* @return
	*/
int rte_mempool_populate_default(struct rte_mempool *mp);


/**
	* Add memory from anonymous mapping for objects in the pool at init
	* This function mmap an anonymous memory zone that is locked in
	* memory to store the objects of the mempool.
	* @param mp
	* @return
	*/
int rte_mempool_populate_anon(struct rte_mempool *mp);


/**
	* Call a function for each mempool element
	* Iterate across all objects attached to a rte_mempool and call the
	* callback function on it.
	* @param mp
	* @param obj_cb
	* @param obj_cb_arg
	* @return
	*/
uint32_t rte_mempool_obj_iter(struct rte_mempool *mp,
	rte_mempool_obj_cb_t *obj_cb, void *obj_cb_arg);


/**
	* Call a function for each mempool memory chunk
	* Iterate across all memory chunks attached to a rte_mempool and call
	* the callback function on it.
	* @param mp
	* @param mem_cb
	* @param mem_cb_arg
	* @return
	*/
uint32_t rte_mempool_mem_iter(struct rte_mempool *mp,
	rte_mempool_mem_cb_t *mem_cb, void *mem_cb_arg);


/**
	* Dump the status of the mempool to the console.
	* @param f
	* @param mp
	*/
void rte_mempool_dump(FILE *f, struct rte_mempool *mp);


/**
	* Create a user-owned mempool cache.
	* This can be used by non-EAL threads to enable caching when they
	* interact with a mempool.
	* @param size
	* @param socket_id
	*/
struct rte_mempool_cache *
rte_mempool_cache_create(uint32_t size, int socket_id);


/**
	* Free a user-owned mempool cache.
	* @param cache
	*/
void
rte_mempool_cache_free(struct rte_mempool_cache *cache);


/**
	* Flush a user-owned mempool cache to the specified mempool.
	* @param cache
	* @param mp
	*/
static inline void __attribute__((always_inline))
rte_mempool_cache_flush(struct rte_mempool_cache *cache,
			struct rte_mempool *mp)
{
	rte_mempool_ops_enqueue_bulk(mp, cache->objs, cache->len);
	cache->len = 0;
}


/**
	* Get a pointer to the per-lcore default mempool cache.
	* @param mp
	* @param lcore_id
	* @return
	*/
static inline struct rte_mempool_cache *__attribute__((always_inline))
rte_mempool_default_cache(struct rte_mempool *mp, unsigned lcore_id)
{
	if (mp->cache_size == 0)
		return NULL;
	if (lcore_id >= 128)
		return NULL;
	return &mp->local_cache[lcore_id];
}


/**
	* @internal Put several objects back in the mempool; used internally.
	* @param mp
	* @param obj_table
	* @param n
	* @param cache
	* @param flags
	*/
static inline void __attribute__((always_inline))
__mempool_generic_put(struct rte_mempool *mp, void * const *obj_table,
						  unsigned n, struct rte_mempool_cache *cache, int flags)
{
	void **cache_objs;


	do {} while(0);


	if (__builtin_expect((cache == NULL || flags & 0x0004),0))
		goto ring_enqueue;


	if (__builtin_expect((n > 512),0))
		goto ring_enqueue;
	cache_objs = &cache->objs[cache->len];

/*
	 * The cache follows the following algorithm
	 */


	rte_memcpy(&cache_objs[0], obj_table, sizeof(void *) * n);
	cache->len += n;
	if (cache->len >= cache->flushthresh)
{
		rte_mempool_ops_enqueue_bulk(mp, &cache->objs[cache->size],
				cache->len - cache->size);
		cache->len = cache->size;
	}
	return;
ring_enqueue:


	rte_mempool_ops_enqueue_bulk(mp, obj_table, n);
}


/**
	* Put several objects back in the mempool.
	* @param mp
	* @param obj_table
	* @param n
	* @param cache
	* @param flags
	*/
static inline void __attribute__((always_inline))
rte_mempool_generic_put(struct rte_mempool *mp, void * const *obj_table,
			unsigned n, struct rte_mempool_cache *cache, int flags)
{
	do {} while(0);
	__mempool_generic_put(mp, obj_table, n, cache, flags);
}


/**
	* @deprecated
	* Put several objects back in the mempool (multi-producers safe).
	* @param mp
	* @param obj_table
	* @param n
	*/
__attribute__((__deprecated__))
static inline void __attribute__((always_inline))
rte_mempool_mp_put_bulk(struct rte_mempool *mp, void * const *obj_table,
			unsigned n)
{
	struct rte_mempool_cache *cache;
	cache = rte_mempool_default_cache(mp, rte_lcore_id());
	rte_mempool_generic_put(mp, obj_table, n, cache, 0);
}


/**
	* @deprecated
	* Put several objects back in the mempool (NOT multi-producers safe).
	* @param mp
	* @param obj_table
	* @param n
	*/
__attribute__((__deprecated__))
static inline void __attribute__((always_inline))
rte_mempool_sp_put_bulk(struct rte_mempool *mp, void * const *obj_table,
			unsigned n)
{
	rte_mempool_generic_put(mp, obj_table, n, NULL, 0x0004);
}


/**
	* Put several objects back in the mempool.
	* This function calls the multi-producer or the single-producer
	* version depending on the default behavior that was specified at
	* mempool creation time (see flags).
	* @param mp
	* @param obj_table
	* @param n
	*/
static inline void __attribute__((always_inline))
rte_mempool_put_bulk(struct rte_mempool *mp, void * const *obj_table,
						 unsigned n)
{
	struct rte_mempool_cache *cache;
	cache = rte_mempool_default_cache(mp, rte_lcore_id());
	rte_mempool_generic_put(mp, obj_table, n, cache, mp->flags);
}


/**
	* @deprecated
	* Put one object in the mempool (multi-producers safe).
	* @param mp
	* @param obj
	*/
__attribute__((__deprecated__))
static inline void __attribute__((always_inline))
rte_mempool_mp_put(struct rte_mempool *mp, void *obj)
{
	struct rte_mempool_cache *cache;
	cache = rte_mempool_default_cache(mp, rte_lcore_id());
	rte_mempool_generic_put(mp, &obj, 1, cache, 0);
}


/**
	* @deprecated
	* Put one object back in the mempool (NOT multi-producers safe).
	* @param mp
	* @param obj
	*/
__attribute__((__deprecated__))
static inline void __attribute__((always_inline))
rte_mempool_sp_put(struct rte_mempool *mp, void *obj)
{
	rte_mempool_generic_put(mp, &obj, 1, NULL, 0x0004);
}


/**
	* Put one object back in the mempool.
	* This function calls the multi-producer or the single-producer
	* version depending on the default behavior that was specified at
	* mempool creation time (see flags).
	* @param mp
	* @param obj
	*/
static inline void __attribute__((always_inline))
rte_mempool_put(struct rte_mempool *mp, void *obj)
{
	rte_mempool_put_bulk(mp, &obj, 1);
}


/**
	* @internal Get several objects from the mempool; used internally.
	* @param mp
	* @param obj_table
	* @param n
	* @param cache
	* @param flags
	* @return
	*/
static inline int __attribute__((always_inline))
__mempool_generic_get(struct rte_mempool *mp, void **obj_table,
						  unsigned n, struct rte_mempool_cache *cache, int flags)
{
	int ret;
	uint32_t index, len;
	void **cache_objs;


	if (__builtin_expect((cache == NULL || flags & 0x0008 || n >= cache->size),0))
		goto ring_dequeue;
	cache_objs = cache->objs;


	if (cache->len < n)
{


		uint32_t req = n + (cache->size - cache->len);


		ret = rte_mempool_ops_dequeue_bulk(mp,
			&cache->objs[cache->len], req);
		if (__builtin_expect((ret < 0),0))
{

/*
			 * In the offchance that we are buffer constrained,
			 * where we are not able to allocate cache + n, go to
			 * the ring directly. If that fails, we are truly out of
			 * buffers.
			 */
			goto ring_dequeue;
		}
		cache->len += req;
	}


	for (index = 0, len = cache->len - 1; index < n; ++index, len--, obj_table++)
		*obj_table = cache_objs[len];
	cache->len -= n;
	do {} while(0);
	return 0;
ring_dequeue:


	ret = rte_mempool_ops_dequeue_bulk(mp, obj_table, n);
	if (ret < 0)
		do {} while(0);
	else
		do {} while(0);
	return ret;
}


/**
	* Get several objects from the mempool.
	* If cache is enabled, objects will be retrieved first from cache,
	* subsequently from the common pool. Note that it can return -ENOENT when
	* the local cache and common pool are empty, even if cache from other
	* lcores are full.
	* @param mp
	* @param obj_table
	* @param n
	* @param cache
	* @param flags
	* @return
	*/
static inline int __attribute__((always_inline))
rte_mempool_generic_get(struct rte_mempool *mp, void **obj_table, unsigned n,
			struct rte_mempool_cache *cache, int flags)
{
	int ret;
	ret = __mempool_generic_get(mp, obj_table, n, cache, flags);
	if (ret == 0)
		do {} while(0);
	return ret;
}


/**
	* @deprecated
	* Get several objects from the mempool (multi-consumers safe).
	* If cache is enabled, objects will be retrieved first from cache,
	* subsequently from the common pool. Note that it can return -ENOENT when
	* the local cache and common pool are empty, even if cache from other
	* lcores are full.
	* @param mp
	* @param obj_table
	* @param n
	* @return
	*/
__attribute__((__deprecated__))
static inline int __attribute__((always_inline))
rte_mempool_mc_get_bulk(struct rte_mempool *mp, void **obj_table, unsigned n)
{
	struct rte_mempool_cache *cache;
	cache = rte_mempool_default_cache(mp, rte_lcore_id());
	return rte_mempool_generic_get(mp, obj_table, n, cache, 0);
}


/**
	* @deprecated
	* Get several objects from the mempool (NOT multi-consumers safe).
	* If cache is enabled, objects will be retrieved first from cache,
	* subsequently from the common pool. Note that it can return -ENOENT when
	* the local cache and common pool are empty, even if cache from other
	* lcores are full.
	* @param mp
	* @param obj_table
	* @param n
	* @return
	*/
__attribute__((__deprecated__))
static inline int __attribute__((always_inline))
rte_mempool_sc_get_bulk(struct rte_mempool *mp, void **obj_table, unsigned n)
{
	return rte_mempool_generic_get(mp, obj_table, n, NULL,
						     0x0008);
}


/**
	* Get several objects from the mempool.
	* This function calls the multi-consumers or the single-consumer
	* version, depending on the default behaviour that was specified at
	* mempool creation time (see flags).
	* If cache is enabled, objects will be retrieved first from cache,
	* subsequently from the common pool. Note that it can return -ENOENT when
	* the local cache and common pool are empty, even if cache from other
	* lcores are full.
	* @param mp
	* @param obj_table
	* @param n
	* @return
	*/
static inline int __attribute__((always_inline))
rte_mempool_get_bulk(struct rte_mempool *mp, void **obj_table, unsigned n)
{
	struct rte_mempool_cache *cache;
	cache = rte_mempool_default_cache(mp, rte_lcore_id());
	return rte_mempool_generic_get(mp, obj_table, n, cache, mp->flags);
}


/**
	* @deprecated
	* Get one object from the mempool (multi-consumers safe).
	* If cache is enabled, objects will be retrieved first from cache,
	* subsequently from the common pool. Note that it can return -ENOENT when
	* the local cache and common pool are empty, even if cache from other
	* lcores are full.
	* @param mp
	* @param obj_p
	* @return
	*/
__attribute__((__deprecated__))
static inline int __attribute__((always_inline))
rte_mempool_mc_get(struct rte_mempool *mp, void **obj_p)
{
	struct rte_mempool_cache *cache;
	cache = rte_mempool_default_cache(mp, rte_lcore_id());
	return rte_mempool_generic_get(mp, obj_p, 1, cache, 0);
}


/**
	* @deprecated
	* Get one object from the mempool (NOT multi-consumers safe).
	* If cache is enabled, objects will be retrieved first from cache,
	* subsequently from the common pool. Note that it can return -ENOENT when
	* the local cache and common pool are empty, even if cache from other
	* lcores are full.
	* @param mp
	* @param obj_p
	* @return
	*/
__attribute__((__deprecated__))
static inline int __attribute__((always_inline))
rte_mempool_sc_get(struct rte_mempool *mp, void **obj_p)
{
	return rte_mempool_generic_get(mp, obj_p, 1, NULL, 0x0008);
}


/**
	* Get one object from the mempool.
	* This function calls the multi-consumers or the single-consumer
	* version, depending on the default behavior that was specified at
	* mempool creation (see flags).
	* If cache is enabled, objects will be retrieved first from cache,
	* subsequently from the common pool. Note that it can return -ENOENT when
	* the local cache and common pool are empty, even if cache from other
	* lcores are full.
	* @param mp
	* @param obj_p
	* @return
	*/
static inline int __attribute__((always_inline))
rte_mempool_get(struct rte_mempool *mp, void **obj_p)
{
	return rte_mempool_get_bulk(mp, obj_p, 1);
}


/**
	* Return the number of entries in the mempool.
	* When cache is enabled, this function has to browse the length of
	* all lcores, so it should not be used in a data path, but only for
	* debug purposes. User-owned mempool caches are not accounted for.
	* @param mp
	* @return
	*/
unsigned int rte_mempool_avail_count(const struct rte_mempool *mp);


/**
	* @deprecated
	* Return the number of entries in the mempool.
	* When cache is enabled, this function has to browse the length of
	* all lcores, so it should not be used in a data path, but only for
	* debug purposes.
	* @param mp
	* @return
	*/
__attribute__((__deprecated__))
unsigned rte_mempool_count(const struct rte_mempool *mp);


/**
	* Return the number of elements which have been allocated from the mempool
	* When cache is enabled, this function has to browse the length of
	* all lcores, so it should not be used in a data path, but only for
	* debug purposes.
	* @param mp
	* @return
	*/
unsigned int
rte_mempool_in_use_count(const struct rte_mempool *mp);


/**
	* @deprecated
	* Return the number of free entries in the mempool ring.
	* i.e. how many entries can be freed back to the mempool.
	* NOTE: This corresponds to the number of elements *allocated* from the
	* memory pool, not the number of elements in the pool itself. To count
	* the number elements currently available in the pool, use "rte_mempool_count"
	* When cache is enabled, this function has to browse the length of
	* all lcores, so it should not be used in a data path, but only for
	* debug purposes. User-owned mempool caches are not accounted for.
	* @param mp
	* @return
	*/
__attribute__((__deprecated__))
static inline unsigned
rte_mempool_free_count(const struct rte_mempool *mp)
{
	return rte_mempool_in_use_count(mp);
}


/**
	* Test if the mempool is full.
	* When cache is enabled, this function has to browse the length of all
	* lcores, so it should not be used in a data path, but only for debug
	* purposes. User-owned mempool caches are not accounted for.
	* @param mp
	* @return
	*/
static inline int
rte_mempool_full(const struct rte_mempool *mp)
{
	return !!(rte_mempool_avail_count(mp) == mp->size);
}


/**
	* Test if the mempool is empty.
	* When cache is enabled, this function has to browse the length of all
	* lcores, so it should not be used in a data path, but only for debug
	* purposes. User-owned mempool caches are not accounted for.
	* @param mp
	* @return
	*/
static inline int
rte_mempool_empty(const struct rte_mempool *mp)
{
	return !!(rte_mempool_avail_count(mp) == 0);
}


/**
	* Return the physical address of elt, which is an element of the pool mp.
	* @param mp
	* @param elt
	* @return
	*/
static inline phys_addr_t
rte_mempool_virt2phy(__attribute__((__unused__)) const struct rte_mempool *mp, const void *elt)
{
	const struct rte_mempool_objhdr *hdr;
	hdr = (const struct rte_mempool_objhdr *)((void*)((uintptr_t)elt - (sizeof(*hdr))));
	return hdr->physaddr;
}


/**
	* Check the consistency of mempool objects.
	* Verify the coherency of fields in the mempool structure. Also check
	* that the cookies of mempool objects (even the ones that are not
	* present in pool) have a correct value. If not, a panic will occur.
	* @param mp
	*/
void rte_mempool_audit(struct rte_mempool *mp);


/**
	* Return a pointer to the private data in an mempool structure.
	* @param mp
	* @return
	*/
static inline void *rte_mempool_get_priv(struct rte_mempool *mp)
{
	return (char *)mp +
		(sizeof(*(mp)) + (((mp->cache_size) == 0) ? 0 : (sizeof(struct rte_mempool_cache) * 128)));
}


/**
	* Dump the status of all mempools on the console
	* @param f
	*/
void rte_mempool_list_dump(FILE *f);


/**
	* Search a mempool from its name
	* @param name
	* @return
	*/
struct rte_mempool *rte_mempool_lookup(const char *name);


/**
	* Get the header, trailer and total size of a mempool element.
	* Given a desired size of the mempool element and mempool flags,
	* calculates header, trailer, body and total sizes of the mempool object.
	* @param elt_size
	* @param flags
	* @param sz
	* @return
	*/
uint32_t rte_mempool_calc_obj_size(uint32_t elt_size, uint32_t flags,
	struct rte_mempool_objsz *sz);


/**
	* Get the size of memory required to store mempool elements.
	* Calculate the maximum amount of memory required to store given number
	* of objects. Assume that the memory buffer will be aligned at page
	* boundary.
	* Note that if object size is bigger then page size, then it assumes
	* that pages are grouped in subsets of physically continuous pages big
	* enough to store at least one object.
	* @param elt_num
	* @param total_elt_sz
	* @param pg_shift
	* @return
	*/
size_t rte_mempool_xmem_size(uint32_t elt_num, size_t total_elt_sz,
	uint32_t pg_shift);


/**
	* Get the size of memory required to store mempool elements.
	* Calculate how much memory would be actually required with the given
	* memory footprint to store required number of objects.
	* @param vaddr
	* @param elt_num
	* @param total_elt_sz
	* @param paddr
	* @param pg_num
	* @param pg_shift
	* @return
	*/
ssize_t rte_mempool_xmem_usage(void *vaddr, uint32_t elt_num,
	size_t total_elt_sz, const phys_addr_t paddr[], uint32_t pg_num,
	uint32_t pg_shift);


/**
	* Walk list of all memory pools
	* @param func
	* @param arg
	*/
void rte_mempool_walk(void (*func)(struct rte_mempool *, void *arg),
						  void *arg);


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* Prefetch operations.
	* This file defines an API for prefetch macros / inline-functions,
	* which are architecture-dependent. Prefetching occurs when a
	* processor requests an instruction or data from memory to cache
	* before it is actually needed, potentially speeding up the execution of the
	* program.
	*/


/**
	* Prefetch a cache line into all cache levels.
	* @param p
	*/
static inline void rte_prefetch0(const volatile void *p);


/**
	* Prefetch a cache line into all cache levels except the 0th cache level.
	* @param p
	*/
static inline void rte_prefetch1(const volatile void *p);


/**
	* Prefetch a cache line into all cache levels except the 0th and 1th cache
	* levels.
	* @param p
	*/
static inline void rte_prefetch2(const volatile void *p);


/**
	* Prefetch a cache line into all cache levels (non-temporal/transient version)
	* The non-temporal prefetch is intended as a prefetch hint that processor will
	* use the prefetched data only once or short period, unlike the
	* rte_prefetch0() function which imply that prefetched data to use repeatedly.
	* @param p
	*/
static inline void rte_prefetch_non_temporal(const volatile void *p);
static inline void rte_prefetch0(const volatile void *p)
{
	__asm__ volatile ("prefetcht0 %[p]" : : [p] "m" (*(const volatile char *)p));
}
static inline void rte_prefetch1(const volatile void *p)
{
	__asm__ volatile ("prefetcht1 %[p]" : : [p] "m" (*(const volatile char *)p));
}
static inline void rte_prefetch2(const volatile void *p)
{
	__asm__ volatile ("prefetcht2 %[p]" : : [p] "m" (*(const volatile char *)p));
}
static inline void rte_prefetch_non_temporal(const volatile void *p)
{
	__asm__ volatile ("prefetchnta %[p]" : : [p] "m" (*(const volatile char *)p));
}


/*-
	*/


/**
	* @file
	* Branch Prediction Helpers in RTE
	*/


/*
	* Packet Offload Features Flags. It also carry packet type information.
	* Critical resources. Both rx/tx shared these bits. Be cautious on any change
	* - RX flags start at bit position zero, and get added to the left of previous
	* - The most-significant 3 bits are reserved for generic mbuf flags
	* - TX flags therefore start at bit position 60 (i.e. 63-3), and new flags get
	* Keep these flags synchronized with rte_get_rx_ol_flag_name() and
	* rte_get_tx_ol_flag_name().
	*/


/**
	* RX packet is a 802.1q VLAN packet. This flag was set by PMDs when
	* the packet is recognized as a VLAN, but the behavior between PMDs
	* was not the same. This flag is kept for some time to avoid breaking
	* applications and should be replaced by PKT_RX_VLAN_STRIPPED.
	*/


/**
	* A vlan has been stripped by the hardware and its tci is saved in
	* mbuf->vlan_tci. This can only happen if vlan stripping is enabled
	* in the RX configuration of the PMD.
	*/





/**
	* The 2 vlans have been stripped by the hardware and their tci are
	* saved in mbuf->vlan_tci (inner) and mbuf->vlan_tci_outer (outer).
	* This can only happen if vlan stripping is enabled in the RX
	* configuration of the PMD. If this flag is set, PKT_RX_VLAN_STRIPPED
	* must also be set.
	*/


/**
	* Deprecated.
	* RX packet with double VLAN stripped.
	* This flag is replaced by PKT_RX_QINQ_STRIPPED.
	*/








/**
	* Second VLAN insertion (QinQ) flag.
	*/


/**
	* TCP segmentation offload. To enable this offload feature for a
	* packet to be transmitted on hardware supporting TSO:
	*  - set the PKT_TX_TCP_SEG flag in mbuf->ol_flags (this flag implies
	*  - set the flag PKT_TX_IPV4 or PKT_TX_IPV6
	*  - if it's IPv4, set the PKT_TX_IP_CKSUM flag and write the IP checksum
	*  - fill the mbuf offload information: l2_len, l3_len, l4_len, tso_segsz
	*  - calculate the pseudo header checksum without taking ip_len in account,
	*/


/**
	* Bits 52+53 used for L4 packet type with checksum enabled: 00: Reserved,
	* 01: TCP checksum, 10: SCTP checksum, 11: UDP checksum. To use hardware
	* L4 checksum offload, the user needs to:
	*  - fill l2_len and l3_len in mbuf
	*  - set the flags PKT_TX_TCP_CKSUM, PKT_TX_SCTP_CKSUM or PKT_TX_UDP_CKSUM
	*  - set the flag PKT_TX_IPV4 or PKT_TX_IPV6
	*  - calculate the pseudo header checksum and set it in the L4 header (only
	*/


/**
	* Offload the IP checksum in the hardware. The flag PKT_TX_IPV4 should
	* also be set by the application, although a PMD will only check
	* PKT_TX_IP_CKSUM.
	*  - set the IP checksum field in the packet to 0
	*  - fill the mbuf offload information: l2_len, l3_len
	*/


/**
	* Packet is IPv4. This flag must be set when using any offload feature
	* (TSO, L3 or L4 checksum) to tell the NIC that the packet is an IPv4
	* packet. If the packet is a tunneled packet, this flag is related to
	* the inner headers.
	*/


/**
	* Packet is IPv6. This flag must be set when using an offload feature
	* (TSO or L4 checksum) to tell the NIC that the packet is an IPv6
	* packet. If the packet is a tunneled packet, this flag is related to
	* the inner headers.
	*/


/**
	* Offload the IP checksum of an external header in the hardware. The
	* flag PKT_TX_OUTER_IPV4 should also be set by the application, alto ugh
	* a PMD will only check PKT_TX_IP_CKSUM.  The IP checksum field in the
	* packet must be set to 0.
	*  - set the outer IP checksum field in the packet to 0
	*  - fill the mbuf offload information: outer_l2_len, outer_l3_len
	*/


/**
	* Packet outer header is IPv4. This flag must be set when using any
	* outer offload feature (L3 or L4 checksum) to tell the NIC that the
	* outer header of the tunneled packet is an IPv4 packet.
	*/


/**
	* Packet outer header is IPv6. This flag must be set when using any
	* outer offload feature (L4 checksum) to tell the NIC that the outer
	* header of the tunneled packet is an IPv6 packet.
	*/





/*
	* 32 bits are divided into several fields to mark packet types. Note that
	* each field is indexical.
	* - Bit 3:0 is for L2 types.
	* - Bit 7:4 is for L3 or outer L3 (for tunneling case) types.
	* - Bit 11:8 is for L4 or outer L4 (for tunneling case) types.
	* - Bit 15:12 is for tunnel types.
	* - Bit 19:16 is for inner L2 types.
	* - Bit 23:20 is for inner L3 types.
	* - Bit 27:24 is for inner L4 types.
	* - Bit 31:28 is reserved.
	* To be compatible with Vector PMD, RTE_PTYPE_L3_IPV4, RTE_PTYPE_L3_IPV4_EXT,
	* RTE_PTYPE_L3_IPV6, RTE_PTYPE_L3_IPV6_EXT, RTE_PTYPE_L4_TCP, RTE_PTYPE_L4_UDP
	* and RTE_PTYPE_L4_SCTP should be kept as below in a contiguous 7 bits.
	* Note that L3 types values are selected for checking IPV4/IPV6 header from
	* performance point of view. Reading annotations of RTE_ETH_IS_IPV4_HDR and
	* RTE_ETH_IS_IPV6_HDR is needed for any future changes of L3 type values.
	* Note that the packet types of the same packet recognized by different
	* hardware may be different, as different hardware may have different
	* capability of packet type recognition.
	* examples:
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=0x29
	* | 'version'=6, 'next header'=0x3A
	* | 'ICMPv6 header'>
	* will be recognized on i40e hardware as packet type combination of,
	* RTE_PTYPE_L2_ETHER |
	* RTE_PTYPE_L3_IPV4_EXT_UNKNOWN |
	* RTE_PTYPE_TUNNEL_IP |
	* RTE_PTYPE_INNER_L3_IPV6_EXT_UNKNOWN |
	* RTE_PTYPE_INNER_L4_ICMP.
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=0x2F
	* | 'GRE header'
	* | 'version'=6, 'next header'=0x11
	* | 'UDP header'>
	* will be recognized on i40e hardware as packet type combination of,
	* RTE_PTYPE_L2_ETHER |
	* RTE_PTYPE_L3_IPV6_EXT_UNKNOWN |
	* RTE_PTYPE_TUNNEL_GRENAT |
	* RTE_PTYPE_INNER_L3_IPV6_EXT_UNKNOWN |
	* RTE_PTYPE_INNER_L4_UDP.
	*/


/**
	* Ethernet packet type.
	* It is used for outer packet for tunneling cases.
	* Packet format:
	* <'ether type'=[0x0800|0x86DD]>
	*/


/**
	* Ethernet packet type for time sync.
	* Packet format:
	* <'ether type'=0x88F7>
	*/


/**
	* ARP (Address Resolution Protocol) packet type.
	* Packet format:
	* <'ether type'=0x0806>
	*/


/**
	* LLDP (Link Layer Discovery Protocol) packet type.
	* Packet format:
	* <'ether type'=0x88CC>
	*/


/**
	* NSH (Network Service Header) packet type.
	* Packet format:
	* <'ether type'=0x894F>
	*/


/**
	* Mask of layer 2 packet types.
	* It is used for outer packet for tunneling cases.
	*/


/**
	* IP (Internet Protocol) version 4 packet type.
	* It is used for outer packet for tunneling cases, and does not contain any
	* header option.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'ihl'=5>
	*/


/**
	* IP (Internet Protocol) version 4 packet type.
	* It is used for outer packet for tunneling cases, and contains header
	* options.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'ihl'=[6-15], 'options'>
	*/


/**
	* IP (Internet Protocol) version 6 packet type.
	* It is used for outer packet for tunneling cases, and does not contain any
	* extension header.
	* Packet format:
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=0x3B>
	*/


/**
	* IP (Internet Protocol) version 4 packet type.
	* It is used for outer packet for tunneling cases, and may or maynot contain
	* header options.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'ihl'=[5-15], <'options'>>
	*/


/**
	* IP (Internet Protocol) version 6 packet type.
	* It is used for outer packet for tunneling cases, and contains extension
	* headers.
	* Packet format:
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=[0x0|0x2B|0x2C|0x32|0x33|0x3C|0x87],
	*/


/**
	* IP (Internet Protocol) version 6 packet type.
	* It is used for outer packet for tunneling cases, and may or maynot contain
	* extension headers.
	* Packet format:
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=[0x3B|0x0|0x2B|0x2C|0x32|0x33|0x3C|0x87],
	*/


/**
	* Mask of layer 3 packet types.
	* It is used for outer packet for tunneling cases.
	*/


/**
	* TCP (Transmission Control Protocol) packet type.
	* It is used for outer packet for tunneling cases.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=6, 'MF'=0>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=6>
	*/


/**
	* UDP (User Datagram Protocol) packet type.
	* It is used for outer packet for tunneling cases.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=17, 'MF'=0>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=17>
	*/


/**
	* Fragmented IP (Internet Protocol) packet type.
	* It is used for outer packet for tunneling cases.
	* It refers to those packets of any IP types, which can be recognized as
	* fragmented. A fragmented packet cannot be recognized as any other L4 types
	* (RTE_PTYPE_L4_TCP, RTE_PTYPE_L4_UDP, RTE_PTYPE_L4_SCTP, RTE_PTYPE_L4_ICMP,
	* RTE_PTYPE_L4_NONFRAG).
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'MF'=1>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=44>
	*/


/**
	* SCTP (Stream Control Transmission Protocol) packet type.
	* It is used for outer packet for tunneling cases.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=132, 'MF'=0>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=132>
	*/


/**
	* ICMP (Internet Control Message Protocol) packet type.
	* It is used for outer packet for tunneling cases.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=1, 'MF'=0>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=1>
	*/


/**
	* Non-fragmented IP (Internet Protocol) packet type.
	* It is used for outer packet for tunneling cases.
	* It refers to those packets of any IP types, while cannot be recognized as
	* any of above L4 types (RTE_PTYPE_L4_TCP, RTE_PTYPE_L4_UDP,
	* RTE_PTYPE_L4_FRAG, RTE_PTYPE_L4_SCTP, RTE_PTYPE_L4_ICMP).
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'!=[6|17|132|1], 'MF'=0>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'!=[6|17|44|132|1]>
	*/


/**
	* Mask of layer 4 packet types.
	* It is used for outer packet for tunneling cases.
	*/


/**
	* IP (Internet Protocol) in IP (Internet Protocol) tunneling packet type.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=[4|41]>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=[4|41]>
	*/


/**
	* GRE (Generic Routing Encapsulation) tunneling packet type.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=47>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=47>
	*/


/**
	* VXLAN (Virtual eXtensible Local Area Network) tunneling packet type.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=17
	* | 'destination port'=4798>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=17
	* | 'destination port'=4798>
	*/


/**
	* NVGRE (Network Virtualization using Generic Routing Encapsulation) tunneling
	* packet type.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=47
	* | 'protocol type'=0x6558>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=47
	* | 'protocol type'=0x6558'>
	*/


/**
	* GENEVE (Generic Network Virtualization Encapsulation) tunneling packet type.
	* Packet format:
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=17
	* | 'destination port'=6081>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=17
	* | 'destination port'=6081>
	*/


/**
	* Tunneling packet type of Teredo, VXLAN (Virtual eXtensible Local Area
	* Network) or GRE (Generic Routing Encapsulation) could be recognized as this
	* packet type, if they can not be recognized independently as of hardware
	* capability.
	*/


/**
	* Mask of tunneling packet types.
	*/


/**
	* Ethernet packet type.
	* It is used for inner packet type only.
	* Packet format (inner only):
	* <'ether type'=[0x800|0x86DD]>
	*/


/**
	* Ethernet packet type with VLAN (Virtual Local Area Network) tag.
	* Packet format (inner only):
	* <'ether type'=[0x800|0x86DD], vlan=[1-4095]>
	*/


/**
	* Mask of inner layer 2 packet types.
	*/


/**
	* IP (Internet Protocol) version 4 packet type.
	* It is used for inner packet only, and does not contain any header option.
	* Packet format (inner only):
	* <'ether type'=0x0800
	* | 'version'=4, 'ihl'=5>
	*/


/**
	* IP (Internet Protocol) version 4 packet type.
	* It is used for inner packet only, and contains header options.
	* Packet format (inner only):
	* <'ether type'=0x0800
	* | 'version'=4, 'ihl'=[6-15], 'options'>
	*/


/**
	* IP (Internet Protocol) version 6 packet type.
	* It is used for inner packet only, and does not contain any extension header.
	* Packet format (inner only):
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=0x3B>
	*/


/**
	* IP (Internet Protocol) version 4 packet type.
	* It is used for inner packet only, and may or maynot contain header options.
	* Packet format (inner only):
	* <'ether type'=0x0800
	* | 'version'=4, 'ihl'=[5-15], <'options'>>
	*/


/**
	* IP (Internet Protocol) version 6 packet type.
	* It is used for inner packet only, and contains extension headers.
	* Packet format (inner only):
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=[0x0|0x2B|0x2C|0x32|0x33|0x3C|0x87],
	*/


/**
	* IP (Internet Protocol) version 6 packet type.
	* It is used for inner packet only, and may or maynot contain extension
	* headers.
	* Packet format (inner only):
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=[0x3B|0x0|0x2B|0x2C|0x32|0x33|0x3C|0x87],
	*/


/**
	* Mask of inner layer 3 packet types.
	*/


/**
	* TCP (Transmission Control Protocol) packet type.
	* It is used for inner packet only.
	* Packet format (inner only):
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=6, 'MF'=0>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=6>
	*/


/**
	* UDP (User Datagram Protocol) packet type.
	* It is used for inner packet only.
	* Packet format (inner only):
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=17, 'MF'=0>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=17>
	*/


/**
	* Fragmented IP (Internet Protocol) packet type.
	* It is used for inner packet only, and may or maynot have layer 4 packet.
	* Packet format (inner only):
	* <'ether type'=0x0800
	* | 'version'=4, 'MF'=1>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=44>
	*/


/**
	* SCTP (Stream Control Transmission Protocol) packet type.
	* It is used for inner packet only.
	* Packet format (inner only):
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=132, 'MF'=0>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=132>
	*/


/**
	* ICMP (Internet Control Message Protocol) packet type.
	* It is used for inner packet only.
	* Packet format (inner only):
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'=1, 'MF'=0>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'=1>
	*/


/**
	* Non-fragmented IP (Internet Protocol) packet type.
	* It is used for inner packet only, and may or maynot have other unknown layer
	* 4 packet types.
	* Packet format (inner only):
	* <'ether type'=0x0800
	* | 'version'=4, 'protocol'!=[6|17|132|1], 'MF'=0>
	* or,
	* <'ether type'=0x86DD
	* | 'version'=6, 'next header'!=[6|17|44|132|1]>
	*/


/**
	* Mask of inner layer 4 packet types.
	*/


/**
	* Check if the (outer) L3 header is IPv4. To avoid comparing IPv4 types one by
	* one, bit 4 is selected to be used for IPv4 only. Then checking bit 4 can
	* determine if it is an IPV4 packet.
	*/


/**
	* Check if the (outer) L3 header is IPv4. To avoid comparing IPv4 types one by
	* one, bit 6 is selected to be used for IPv4 only. Then checking bit 6 can
	* determine if it is an IPV4 packet.
	*/








/**
	* Get the name of a RX offload flag
	* @param mask
	* @return
	*/
const char *rte_get_rx_ol_flag_name(uint64_t mask);


/**
	* Get the name of a TX offload flag
	* @param mask
	* @return
	*/
const char *rte_get_tx_ol_flag_name(uint64_t mask);


/**
	* Some NICs need at least 2KB buffer to RX standard Ethernet frame without
	* splitting it into multiple segments.
	* So, for mbufs that planned to be involved into RX/TX, the recommended
	* minimal buffer length is 2KB + RTE_PKTMBUF_HEADROOM.
	*/


/* define a set of marker types that can be used to refer to set points in the
	* mbuf */
__extension__
typedef void *MARKER[0]; 


__extension__
typedef uint8_t MARKER8[0]; 


__extension__
typedef uint64_t MARKER64[0]; 

/**< marker that allows us to overwrite 8 bytes
						                         * with a single assignment */


/**
	* The generic rte_mbuf, containing a packet mbuf.
	*/
struct rte_mbuf
{
	MARKER cacheline0;
	void *buf_addr; 


	phys_addr_t buf_physaddr; 


	uint16_t buf_len; 




	MARKER8 rearm_data;
	uint16_t data_off;

/**
	 * 16-bit Reference counter.
	 * It should only be accessed using the following functions:
	 * rte_mbuf_refcnt_update(), rte_mbuf_refcnt_read(), and
	 * rte_mbuf_refcnt_set(). The functionality of these functions (atomic,
	 * or non-atomic) is controlled by the CONFIG_RTE_MBUF_REFCNT_ATOMIC
	 * config option.
	 */

	union
{
		rte_atomic16_t refcnt_atomic; 


		uint16_t refcnt; 


	};
	uint8_t nb_segs; 


	uint8_t port; 


	uint64_t ol_flags; 




	MARKER rx_descriptor_fields1;

/*
	 * The packet type, which is the combination of outer/inner L2, L3, L4
	 * and tunnel types. The packet_type is about data really present in the
	 * mbuf. Example: if vlan stripping is enabled, a received vlan packet
	 * would have RTE_PTYPE_L2_ETHER and not RTE_PTYPE_L2_VLAN because the
	 * vlan is stripped from the data.
	 */

	union
{
		uint32_t packet_type; 


		struct
{
			uint32_t l2_type:4; 


			uint32_t l3_type:4; 


			uint32_t l4_type:4; 


			uint32_t tun_type:4; 


			uint32_t inner_l2_type:4; 


			uint32_t inner_l3_type:4; 


			uint32_t inner_l4_type:4; 


		};
	};
	uint32_t pkt_len; 


	uint16_t data_len; 




	uint16_t vlan_tci;
	union
{
		uint32_t rss; 


		struct
{
			union
{
				struct
{
					uint16_t hash;
					uint16_t id;
				};
				uint32_t lo;


			};
			uint32_t hi;

/**< First 4 flexible bytes or FD ID, dependent on
			     PKT_RX_FDIR_* flag in ol_flags. */
		} fdir; 


		struct
{
			uint32_t lo;
			uint32_t hi;
		} sched; 


		uint32_t usr; 


	} hash; 


	uint32_t seqn; 




	uint16_t vlan_tci_outer;


	MARKER cacheline1 __attribute__((__aligned__(64)));

	union
{
		void *userdata; 


		uint64_t udata64; 


	};
	struct rte_mempool *pool; 


	struct rte_mbuf *next; 





	union
{
		uint64_t tx_offload; 


		__extension__
		struct
{
			uint64_t l2_len:7; 


			uint64_t l3_len:9; 


			uint64_t l4_len:8; 


			uint64_t tso_segsz:16; 




			uint64_t outer_l3_len:9; 


			uint64_t outer_l2_len:7; 




		};
	};

/** Size of the application private data. In case of an indirect
	 * mbuf, it stores the direct mbuf private data size. */
	uint16_t priv_size;


	uint16_t timesync;
} __attribute__((__aligned__(64)));


/**
	* Prefetch the first part of the mbuf
	* The first 64 bytes of the mbuf corresponds to fields that are used early
	* in the receive path. If the cache line of the architecture is higher than
	* 64B, the second part will also be prefetched.
	* @param m
	*/
static inline void
rte_mbuf_prefetch_part1(struct rte_mbuf *m)
{
	rte_prefetch0(&m->cacheline0);
}


/**
	* Prefetch the second part of the mbuf
	* The next 64 bytes of the mbuf corresponds to fields that are used in the
	* transmit path. If the cache line of the architecture is higher than 64B,
	* this function does nothing as it is expected that the full mbuf is
	* already in cache.
	* @param m
	*/
static inline void
rte_mbuf_prefetch_part2(struct rte_mbuf *m)
{
	rte_prefetch0(&m->cacheline1);
}
static inline uint16_t rte_pktmbuf_priv_size(struct rte_mempool *mp);


/**
	* Return the DMA address of the beginning of the mbuf data
	* @param mb
	* @return
	*/
static inline phys_addr_t
rte_mbuf_data_dma_addr(const struct rte_mbuf *mb)
{
	return mb->buf_physaddr + mb->data_off;
}


/**
	* Return the default DMA address of the beginning of the mbuf data
	* This function is used by drivers in their receive function, as it
	* returns the location where data should be written by the NIC, taking
	* the default headroom in account.
	* @param mb
	* @return
	*/
static inline phys_addr_t
rte_mbuf_data_dma_addr_default(const struct rte_mbuf *mb)
{
	return mb->buf_physaddr + 128;
}


/**
	* Return the mbuf owning the data buffer address of an indirect mbuf.
	* @param mi
	* @return
	*/
static inline struct rte_mbuf *
rte_mbuf_from_indirect(struct rte_mbuf *mi)
{
	return (struct rte_mbuf *)((void*)((uintptr_t)mi->buf_addr - (sizeof(*mi) + mi->priv_size)));
}


/**
	* Return the buffer address embedded in the given mbuf.
	* @param md
	* @return
	*/
static inline char *
rte_mbuf_to_baddr(struct rte_mbuf *md)
{
	char *buffer_addr;
	buffer_addr = (char *)md + sizeof(*md) + rte_pktmbuf_priv_size(md->pool);
	return buffer_addr;
}


/**
	* Returns TRUE if given mbuf is indirect, or FALSE otherwise.
	*/


/**
	* Returns TRUE if given mbuf is direct, or FALSE otherwise.
	*/


/**
	* Private data in case of pktmbuf pool.
	* A structure that contains some pktmbuf_pool-specific data that are
	* appended after the mempool structure (in private data).
	*/
struct rte_pktmbuf_pool_private
{
	uint16_t mbuf_data_room_size; 


	uint16_t mbuf_priv_size; 


};





/**
	* Reads the value of an mbuf's refcnt.
	* @param m
	* @return
	*/
static inline uint16_t
rte_mbuf_refcnt_read(const struct rte_mbuf *m)
{
	return (uint16_t)(rte_atomic16_read(&m->refcnt_atomic));
}


/**
	* Sets an mbuf's refcnt to a defined value.
	* @param m
	* @param new_value
	*/
static inline void
rte_mbuf_refcnt_set(struct rte_mbuf *m, uint16_t new_value)
{
	rte_atomic16_set(&m->refcnt_atomic, new_value);
}


/**
	* Adds given value to an mbuf's refcnt and returns its new value.
	* @param m
	* @param value
	* @return
	*/
static inline uint16_t
rte_mbuf_refcnt_update(struct rte_mbuf *m, int16_t value)
{

/*
	 * The atomic_add is an expensive operation, so we don't want to
	 * call it in the case where we know we are the uniq holder of
	 * this mbuf (i.e. ref_cnt == 1). Otherwise, an atomic
	 * operation has to be used because concurrent accesses on the
	 * reference counter can occur.
	 */
	if (__builtin_expect((rte_mbuf_refcnt_read(m) == 1),1))
{
		rte_mbuf_refcnt_set(m, 1 + value);
		return 1 + value;
	}
	return (uint16_t)(rte_atomic16_add_return(&m->refcnt_atomic, value));
}





/**
	* Sanity checks on an mbuf.
	* Check the consistency of the given mbuf. The function will cause a
	* panic if corruption is detected.
	* @param m
	* @param is_header
	*/
void
rte_mbuf_sanity_check(const struct rte_mbuf *m, int is_header);


/**
	* Allocate an unitialized mbuf from mempool *mp*.
	* This function can be used by PMDs (especially in RX functions) to
	* allocate an unitialized mbuf. The driver is responsible of
	* initializing all the required fields. See rte_pktmbuf_reset().
	* For standard needs, prefer rte_pktmbuf_alloc().
	* @param mp
	* @return
	*/
static inline struct rte_mbuf *rte_mbuf_raw_alloc(struct rte_mempool *mp)
{
	struct rte_mbuf *m;
	void *mb = NULL;
	if (rte_mempool_get(mp, &mb) < 0)
		return NULL;
	m = (struct rte_mbuf *)mb;
	do {} while (0);
	rte_mbuf_refcnt_set(m, 1);
	do { } while (0);
	return m;
}


/**
	* @internal Put mbuf back into its original mempool.
	* The use of that function is reserved for RTE internal needs.
	* Please use rte_pktmbuf_free().
	* @param m
	*/
static inline void __attribute__((always_inline))
__rte_mbuf_raw_free(struct rte_mbuf *m)
{
	do {} while (0);
	rte_mempool_put(m->pool, m);
}





/**
	* The control mbuf constructor.
	* This function initializes some fields in an mbuf structure that are
	* not modified by the user once created (mbuf type, origin pool, buffer
	* start address, and so on). This function is given as a callback function
	* to rte_mempool_create() at pool creation time.
	* @param mp
	* @param opaque_arg
	* @param m
	* @param i
	*/
void rte_ctrlmbuf_init(struct rte_mempool *mp, void *opaque_arg,
		void *m, unsigned i);


/**
	* Allocate a new mbuf (type is ctrl) from mempool *mp*.
	* This new mbuf is initialized with data pointing to the beginning of
	* buffer, and with a length of zero.
	* @param mp
	* @return
	*/


/**
	* Free a control mbuf back into its original mempool.
	* @param m
	*/


/**
	* A macro that returns the pointer to the carried data.
	* The value that can be read or assigned.
	* @param m
	*/


/**
	* A macro that returns the length of the carried data.
	* The value that can be read or assigned.
	* @param m
	*/


/**
	* Tests if an mbuf is a control mbuf
	* @param m
	* @return
	*/
static inline int
rte_is_ctrlmbuf(struct rte_mbuf *m)
{
	return !!(m->ol_flags & (1ULL << 63));
}





/**
	* The packet mbuf constructor.
	* This function initializes some fields in the mbuf structure that are
	* not modified by the user once created (origin pool, buffer start
	* address, and so on). This function is given as a callback function to
	* rte_mempool_create() at pool creation time.
	* @param mp
	* @param opaque_arg
	* @param m
	* @param i
	*/
void rte_pktmbuf_init(struct rte_mempool *mp, void *opaque_arg,
						  void *m, unsigned i);


/**
	* A  packet mbuf pool constructor.
	* This function initializes the mempool private data in the case of a
	* pktmbuf pool. This private data is needed by the driver. The
	* function is given as a callback function to rte_mempool_create() at
	* pool creation. It can be extended by the user, for example, to
	* provide another packet size.
	* @param mp
	* @param opaque_arg
	*/
void rte_pktmbuf_pool_init(struct rte_mempool *mp, void *opaque_arg);


/**
	* Create a mbuf pool.
	* This function creates and initializes a packet mbuf pool. It is
	* a wrapper to rte_mempool_create() with the proper packet constructor
	* and mempool constructor.
	* @param name
	* @param n
	* @param cache_size
	* @param priv_size
	* @param data_room_size
	* @param socket_id
	* @return
	*/
struct rte_mempool *
rte_pktmbuf_pool_create(const char *name, unsigned n,
	unsigned cache_size, uint16_t priv_size, uint16_t data_room_size,
	int socket_id);


/**
	* Get the data room size of mbufs stored in a pktmbuf_pool
	* The data room size is the amount of data that can be stored in a
	* mbuf including the headroom (RTE_PKTMBUF_HEADROOM).
	* @param mp
	* @return
	*/
static inline uint16_t
rte_pktmbuf_data_room_size(struct rte_mempool *mp)
{
	struct rte_pktmbuf_pool_private *mbp_priv;
	mbp_priv = (struct rte_pktmbuf_pool_private *)rte_mempool_get_priv(mp);
	return mbp_priv->mbuf_data_room_size;
}


/**
	* Get the application private size of mbufs stored in a pktmbuf_pool
	* The private size of mbuf is a zone located between the rte_mbuf
	* structure and the data buffer where an application can store data
	* associated to a packet.
	* @param mp
	* @return
	*/
static inline uint16_t
rte_pktmbuf_priv_size(struct rte_mempool *mp)
{
	struct rte_pktmbuf_pool_private *mbp_priv;
	mbp_priv = (struct rte_pktmbuf_pool_private *)rte_mempool_get_priv(mp);
	return mbp_priv->mbuf_priv_size;
}


/**
	* Reset the fields of a packet mbuf to their default values.
	* The given mbuf must have only one segment.
	* @param m
	*/
static inline void rte_pktmbuf_reset(struct rte_mbuf *m)
{
	m->next = NULL;
	m->pkt_len = 0;
	m->tx_offload = 0;
	m->vlan_tci = 0;
	m->vlan_tci_outer = 0;
	m->nb_segs = 1;
	m->port = 0xff;
	m->ol_flags = 0;
	m->packet_type = 0;
	m->data_off = (128 <= m->buf_len) ?
			128 : m->buf_len;
	m->data_len = 0;
	do { } while (0);
}


/**
	* Allocate a new mbuf from a mempool.
	* This new mbuf contains one segment, which has a length of 0. The pointer
	* to data is initialized to have some bytes of headroom in the buffer
	* (if buffer size allows).
	* @param mp
	* @return
	*/
static inline struct rte_mbuf *rte_pktmbuf_alloc(struct rte_mempool *mp)
{
	struct rte_mbuf *m;
	if ((m = rte_mbuf_raw_alloc(mp)) != NULL)
		rte_pktmbuf_reset(m);
	return m;
}


/**
	* Allocate a bulk of mbufs, initialize refcnt and reset the fields to default
	* values.
	*  @param pool
	*  @param mbufs
	*  @param count
	*  @return
	*/
static inline int rte_pktmbuf_alloc_bulk(struct rte_mempool *pool,
		struct rte_mbuf **mbufs, unsigned count)
{
	unsigned idx = 0;
	int rc;
	rc = rte_mempool_get_bulk(pool, (void **)mbufs, count);
	if (__builtin_expect((rc),0))
		return rc;

/* To understand duff's device on loop unwinding optimization, see
	 * https://en.wikipedia.org/wiki/Duff's_device.
	 * Here while() loop is used rather than do() while{} to avoid extra
	 * check if count is zero.
	 */
	switch (count % 4)
{
	case 0:
		while (idx != count)
{
			do {} while (0);
			rte_mbuf_refcnt_set(mbufs[idx], 1);
			rte_pktmbuf_reset(mbufs[idx]);
			idx++;
	case 3:
			do {} while (0);
			rte_mbuf_refcnt_set(mbufs[idx], 1);
			rte_pktmbuf_reset(mbufs[idx]);
			idx++;
	case 2:
			do {} while (0);
			rte_mbuf_refcnt_set(mbufs[idx], 1);
			rte_pktmbuf_reset(mbufs[idx]);
			idx++;
	case 1:
			do {} while (0);
			rte_mbuf_refcnt_set(mbufs[idx], 1);
			rte_pktmbuf_reset(mbufs[idx]);
			idx++;
		}
	}
	return 0;
}


/**
	* Attach packet mbuf to another packet mbuf.
	* After attachment we refer the mbuf we attached as 'indirect',
	* while mbuf we attached to as 'direct'.
	* The direct mbuf's reference counter is incremented.
	* Right now, not supported:
	*  - attachment for already indirect mbuf (e.g. - mi has to be direct).
	*  - mbuf we trying to attach (mi) is used by someone else
	* @param mi
	* @param m
	*/
static inline void rte_pktmbuf_attach(struct rte_mbuf *mi, struct rte_mbuf *m)
{
	struct rte_mbuf *md;
	do {} while (0);


	if ((!((m)->ol_flags & (1ULL << 62))))
		md = m;
	else
		md = rte_mbuf_from_indirect(m);
	rte_mbuf_refcnt_update(md, 1);
	mi->priv_size = m->priv_size;
	mi->buf_physaddr = m->buf_physaddr;
	mi->buf_addr = m->buf_addr;
	mi->buf_len = m->buf_len;
	mi->next = m->next;
	mi->data_off = m->data_off;
	mi->data_len = m->data_len;
	mi->port = m->port;
	mi->vlan_tci = m->vlan_tci;
	mi->vlan_tci_outer = m->vlan_tci_outer;
	mi->tx_offload = m->tx_offload;
	mi->hash = m->hash;
	mi->next = NULL;
	mi->pkt_len = mi->data_len;
	mi->nb_segs = 1;
	mi->ol_flags = m->ol_flags | (1ULL << 62);
	mi->packet_type = m->packet_type;
	do { } while (0);
	do { } while (0);
}


/**
	* Detach an indirect packet mbuf.
	*  - restore original mbuf address and length values.
	*  - reset pktmbuf data and data_len to their default values.
	*  - decrement the direct mbuf's reference counter. When the
	*  reference counter becomes 0, the direct mbuf is freed.
	* All other fields of the given packet mbuf will be left intact.
	* @param m
	*/
static inline void rte_pktmbuf_detach(struct rte_mbuf *m)
{
	struct rte_mbuf *md = rte_mbuf_from_indirect(m);
	struct rte_mempool *mp = m->pool;
	uint32_t mbuf_size, buf_len, priv_size;
	priv_size = rte_pktmbuf_priv_size(mp);
	mbuf_size = sizeof(struct rte_mbuf) + priv_size;
	buf_len = rte_pktmbuf_data_room_size(mp);
	m->priv_size = priv_size;
	m->buf_addr = (char *)m + mbuf_size;
	m->buf_physaddr = rte_mempool_virt2phy(mp, m) + mbuf_size;
	m->buf_len = (uint16_t)buf_len;
	m->data_off = __extension__ ({ __typeof__ (128) _a = (128); __typeof__ ((uint16_t)m->buf_len) _b = ((uint16_t)m->buf_len); _a < _b ? _a : _b; });
	m->data_len = 0;
	m->ol_flags = 0;
	if (rte_mbuf_refcnt_update(md, -1) == 0)
		__rte_mbuf_raw_free(md);
}
static inline struct rte_mbuf* __attribute__((always_inline))
__rte_pktmbuf_prefree_seg(struct rte_mbuf *m)
{
	do { } while (0);
	if (__builtin_expect((rte_mbuf_refcnt_update(m, -1) == 0),1))
{


		if (((m)->ol_flags & (1ULL << 62)))
			rte_pktmbuf_detach(m);
		return m;
	}
	return NULL;
}


/**
	* Free a segment of a packet mbuf into its original mempool.
	* Free an mbuf, without parsing other segments in case of chained
	* buffers.
	* @param m
	*/
static inline void __attribute__((always_inline))
rte_pktmbuf_free_seg(struct rte_mbuf *m)
{
	if (__builtin_expect((NULL != (m = __rte_pktmbuf_prefree_seg(m))),1))
{
		m->next = NULL;
		__rte_mbuf_raw_free(m);
	}
}


/**
	* Free a packet mbuf back into its original mempool.
	* Free an mbuf, and all its segments in case of chained buffers. Each
	* segment is added back into its original mempool.
	* @param m
	*/
static inline void rte_pktmbuf_free(struct rte_mbuf *m)
{
	struct rte_mbuf *m_next;
	do { } while (0);
	while (m != NULL)
{
		m_next = m->next;
		rte_pktmbuf_free_seg(m);
		m = m_next;
	}
}


/**
	* Creates a "clone" of the given packet mbuf.
	* Walks through all segments of the given packet mbuf, and for each of them:
	*  - Creates a new packet mbuf from the given pool.
	*  - Attaches newly created mbuf to the segment.
	* Then updates pkt_len and nb_segs of the "clone" packet mbuf to match values
	* from the original packet mbuf.
	* @param md
	* @param mp
	* @return
	*/
static inline struct rte_mbuf *rte_pktmbuf_clone(struct rte_mbuf *md,
		struct rte_mempool *mp)
{
	struct rte_mbuf *mc, *mi, **prev;
	uint32_t pktlen;
	uint8_t nseg;
	if (__builtin_expect(((mc = rte_pktmbuf_alloc(mp)) == NULL),0))
		return NULL;
	mi = mc;
	prev = &mi->next;
	pktlen = md->pkt_len;
	nseg = 0;
	do
{
		nseg++;
		rte_pktmbuf_attach(mi, md);
		*prev = mi;
		prev = &mi->next;
	} while ((md = md->next) != NULL &&
					(mi = rte_pktmbuf_alloc(mp)) != NULL);
	*prev = NULL;
	mc->nb_segs = nseg;
	mc->pkt_len = pktlen;


	if (__builtin_expect((mi == NULL),0))
{
		rte_pktmbuf_free(mc);
		return NULL;
	}
	do { } while (0);
	return mc;
}


/**
	* Adds given value to the refcnt of all packet mbuf segments.
	* Walks through all segments of given packet mbuf and for each of them
	* invokes rte_mbuf_refcnt_update().
	* @param m
	* @param v
	*/
static inline void rte_pktmbuf_refcnt_update(struct rte_mbuf *m, int16_t v)
{
	do { } while (0);
	do
{
		rte_mbuf_refcnt_update(m, v);
	} while ((m = m->next) != NULL);
}


/**
	* Get the headroom in a packet mbuf.
	* @param m
	* @return
	*/
static inline uint16_t rte_pktmbuf_headroom(const struct rte_mbuf *m)
{
	do { } while (0);
	return m->data_off;
}


/**
	* Get the tailroom of a packet mbuf.
	* @param m
	* @return
	*/
static inline uint16_t rte_pktmbuf_tailroom(const struct rte_mbuf *m)
{
	do { } while (0);
	return (uint16_t)(m->buf_len - rte_pktmbuf_headroom(m) -
					m->data_len);
}


/**
	* Get the last segment of the packet.
	* @param m
	* @return
	*/
static inline struct rte_mbuf *rte_pktmbuf_lastseg(struct rte_mbuf *m)
{
	struct rte_mbuf *m2 = (struct rte_mbuf *)m;
	do { } while (0);
	while (m2->next != NULL)
		m2 = m2->next;
	return m2;
}


/**
	* A macro that points to an offset into the data in the mbuf.
	* The returned pointer is cast to type t. Before using this
	* function, the user must ensure that the first segment is large
	* enough to accommodate its data.
	* @param m
	* @param o
	* @param t
	*/


/**
	* A macro that points to the start of the data in the mbuf.
	* The returned pointer is cast to type t. Before using this
	* function, the user must ensure that the first segment is large
	* enough to accommodate its data.
	* @param m
	* @param t
	*/


/**
	* A macro that returns the physical address that points to an offset of the
	* start of the data in the mbuf
	* @param m
	* @param o
	*/


/**
	* A macro that returns the physical address that points to the start of the
	* data in the mbuf
	* @param m
	*/


/**
	* A macro that returns the length of the packet.
	* The value can be read or assigned.
	* @param m
	*/


/**
	* A macro that returns the length of the segment.
	* The value can be read or assigned.
	* @param m
	*/


/**
	* Prepend len bytes to an mbuf data area.
	* Returns a pointer to the new
	* data start address. If there is not enough headroom in the first
	* segment, the function will return NULL, without modifying the mbuf.
	* @param m
	* @param len
	* @return
	*/
static inline char *rte_pktmbuf_prepend(struct rte_mbuf *m,
					uint16_t len)
{
	do { } while (0);
	if (__builtin_expect((len > rte_pktmbuf_headroom(m)),0))
		return NULL;
	m->data_off -= len;
	m->data_len = (uint16_t)(m->data_len + len);
	m->pkt_len = (m->pkt_len + len);
	return (char *)m->buf_addr + m->data_off;
}


/**
	* Append len bytes to an mbuf.
	* Append len bytes to an mbuf and return a pointer to the start address
	* of the added data. If there is not enough tailroom in the last
	* segment, the function will return NULL, without modifying the mbuf.
	* @param m
	* @param len
	* @return
	*/
static inline char *rte_pktmbuf_append(struct rte_mbuf *m, uint16_t len)
{
	void *tail;
	struct rte_mbuf *m_last;
	do { } while (0);
	m_last = rte_pktmbuf_lastseg(m);
	if (__builtin_expect((len > rte_pktmbuf_tailroom(m_last)),0))
		return NULL;
	tail = (char *)m_last->buf_addr + m_last->data_off + m_last->data_len;
	m_last->data_len = (uint16_t)(m_last->data_len + len);
	m->pkt_len = (m->pkt_len + len);
	return (char*) tail;
}


/**
	* Remove len bytes at the beginning of an mbuf.
	* Returns a pointer to the start address of the new data area. If the
	* length is greater than the length of the first segment, then the
	* function will fail and return NULL, without modifying the mbuf.
	* @param m
	* @param len
	* @return
	*/
static inline char *rte_pktmbuf_adj(struct rte_mbuf *m, uint16_t len)
{
	do { } while (0);
	if (__builtin_expect((len > m->data_len),0))
		return NULL;
	m->data_len = (uint16_t)(m->data_len - len);
	m->data_off += len;
	m->pkt_len = (m->pkt_len - len);
	return (char *)m->buf_addr + m->data_off;
}


/**
	* Remove len bytes of data at the end of the mbuf.
	* If the length is greater than the length of the last segment, the
	* function will fail and return -1 without modifying the mbuf.
	* @param m
	* @param len
	* @return
	*/
static inline int rte_pktmbuf_trim(struct rte_mbuf *m, uint16_t len)
{
	struct rte_mbuf *m_last;
	do { } while (0);
	m_last = rte_pktmbuf_lastseg(m);
	if (__builtin_expect((len > m_last->data_len),0))
		return -1;
	m_last->data_len = (uint16_t)(m_last->data_len - len);
	m->pkt_len = (m->pkt_len - len);
	return 0;
}


/**
	* Test if mbuf data is contiguous.
	* @param m
	* @return
	*/
static inline int rte_pktmbuf_is_contiguous(const struct rte_mbuf *m)
{
	do { } while (0);
	return !!(m->nb_segs == 1);
}


/**
	* Chain an mbuf to another, thereby creating a segmented packet.
	* Note: The implementation will do a linear walk over the segments to find
	* the tail entry. For cases when there are many segments, it's better to
	* chain the entries manually.
	* @param head
	* @param tail
	* @return
	*/
static inline int rte_pktmbuf_chain(struct rte_mbuf *head, struct rte_mbuf *tail)
{
	struct rte_mbuf *cur_tail;


	if (head->nb_segs + tail->nb_segs >= 1 << (sizeof(head->nb_segs) * 8))
		return -EOVERFLOW;


	cur_tail = rte_pktmbuf_lastseg(head);
	cur_tail->next = tail;


	head->nb_segs = (uint8_t)(head->nb_segs + tail->nb_segs);
	head->pkt_len += tail->pkt_len;


	tail->pkt_len = tail->data_len;
	return 0;
}


/**
	* Dump an mbuf structure to the console.
	* Dump all fields for the given packet mbuf and all its associated
	* segments (in the case of a chained buffer).
	* @param f
	* @param m
	* @param dump_len
	*/
void rte_pktmbuf_dump(FILE *f, const struct rte_mbuf *m, unsigned dump_len);


/*-
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* Byte Swap Operations
	* This file defines a generic API for byte swap operations. Part of
	* the implementation is architecture-specific.
	*/


/*-
	*/


/*
	* Compile-time endianness detection
	*/


/*
	* An internal function to swap bytes in a 16-bit value.
	* It is used by rte_bswap16() when the value is constant. Do not use
	* this function directly; rte_bswap16() is preferred.
	*/
static inline uint16_t
rte_constant_bswap16(uint16_t x)
{
	return (uint16_t)(((x & 0x00ffU) << 8) |
		((x & 0xff00U) >> 8));
}


/*
	* An internal function to swap bytes in a 32-bit value.
	* It is used by rte_bswap32() when the value is constant. Do not use
	* this function directly; rte_bswap32() is preferred.
	*/
static inline uint32_t
rte_constant_bswap32(uint32_t x)
{
	return ((x & 0x000000ffUL) << 24) |
		((x & 0x0000ff00UL) << 8) |
		((x & 0x00ff0000UL) >> 8) |
		((x & 0xff000000UL) >> 24);
}


/*
	* An internal function to swap bytes of a 64-bit value.
	* It is used by rte_bswap64() when the value is constant. Do not use
	* this function directly; rte_bswap64() is preferred.
	*/
static inline uint64_t
rte_constant_bswap64(uint64_t x)
{
	return ((x & 0x00000000000000ffULL) << 56) |
		((x & 0x000000000000ff00ULL) << 40) |
		((x & 0x0000000000ff0000ULL) << 24) |
		((x & 0x00000000ff000000ULL) << 8) |
		((x & 0x000000ff00000000ULL) >> 8) |
		((x & 0x0000ff0000000000ULL) >> 24) |
		((x & 0x00ff000000000000ULL) >> 40) |
		((x & 0xff00000000000000ULL) >> 56);
}


/*
	* An architecture-optimized byte swap for a 16-bit value.
	* Do not use this function directly. The preferred function is rte_bswap16().
	*/
static inline uint16_t rte_arch_bswap16(uint16_t _x)
{
	register uint16_t x = _x;
	__asm__ volatile ("xchgb %b[x1],%h[x2]"
						  : [x1] "=Q" (x)
						  : [x2] "0" (x)
						  );
	return x;
}


/*
	* An architecture-optimized byte swap for a 32-bit value.
	* Do not use this function directly. The preferred function is rte_bswap32().
	*/
static inline uint32_t rte_arch_bswap32(uint32_t _x)
{
	register uint32_t x = _x;
	__asm__ volatile ("bswap %[x]"
						  : [x] "+r" (x)
						  );
	return x;
}


/*-
	*/


/*-
	*/


/*
	* An architecture-optimized byte swap for a 64-bit value.
		* Do not use this function directly. The preferred function is rte_bswap64().
	*/



static inline uint64_t rte_arch_bswap64(uint64_t _x)
{
	register uint64_t x = _x;
	__asm__ volatile ("bswap %[x]"
						  : [x] "+r" (x)
						  );
	return x;
}


/**
	* Ethernet address:
	* A universally administered address is uniquely assigned to a device by its
	* manufacturer. The first three octets (in transmission order) contain the
	* Organizationally Unique Identifier (OUI). The following three (MAC-48 and
	* EUI-48) octets are assigned by that organization with the only constraint
	* of uniqueness.
	* A locally administered address is assigned to a device by a network
	* administrator and does not contain OUIs.
	* See http://standards.ieee.org/regauth/groupmac/tutorial.html
	*/
struct ether_addr
{
	uint8_t addr_bytes[6]; 


} __attribute__((__packed__));


/**
	* Check if two Ethernet addresses are the same.
	* @param ea1
	*  A pointer to the first ether_addr structure containing
	*  the ethernet address.
	* @param ea2
	*  A pointer to the second ether_addr structure containing
	*  the ethernet address.
	* @return
	*  True  (1) if the given two ethernet address are the same;
	*  False (0) otherwise.
	*/
static inline int is_same_ether_addr(const struct ether_addr *ea1,
						   const struct ether_addr *ea2)
{
	int i;
	for (i = 0; i < 6; i++)
		if (ea1->addr_bytes[i] != ea2->addr_bytes[i])
			return 0;
	return 1;
}


/**
	* Check if an Ethernet address is filled with zeros.
	* @param ea
	* @return
	*/
static inline int is_zero_ether_addr(const struct ether_addr *ea)
{
	int i;
	for (i = 0; i < 6; i++)
		if (ea->addr_bytes[i] != 0x00)
			return 0;
	return 1;
}


/**
	* Check if an Ethernet address is a unicast address.
	* @param ea
	* @return
	*/
static inline int is_unicast_ether_addr(const struct ether_addr *ea)
{
	return (ea->addr_bytes[0] & 0x01) == 0;
}


/**
	* Check if an Ethernet address is a multicast address.
	* @param ea
	* @return
	*/
static inline int is_multicast_ether_addr(const struct ether_addr *ea)
{
	return ea->addr_bytes[0] & 0x01;
}


/**
	* Check if an Ethernet address is a broadcast address.
	* @param ea
	* @return
	*/
static inline int is_broadcast_ether_addr(const struct ether_addr *ea)
{
	const unaligned_uint16_t *ea_words = (const unaligned_uint16_t *)ea;
	return (ea_words[0] == 0xFFFF && ea_words[1] == 0xFFFF &&
		ea_words[2] == 0xFFFF);
}


/**
	* Check if an Ethernet address is a universally assigned address.
	* @param ea
	* @return
	*/
static inline int is_universal_ether_addr(const struct ether_addr *ea)
{
	return (ea->addr_bytes[0] & 0x02) == 0;
}


/**
	* Check if an Ethernet address is a locally assigned address.
	* @param ea
	* @return
	*/
static inline int is_local_admin_ether_addr(const struct ether_addr *ea)
{
	return (ea->addr_bytes[0] & 0x02) != 0;
}


/**
	* Check if an Ethernet address is a valid address. Checks that the address is a
	* unicast address and is not filled with zeros.
	* @param ea
	* @return
	*/
static inline int is_valid_assigned_ether_addr(const struct ether_addr *ea)
{
	return is_unicast_ether_addr(ea) && (! is_zero_ether_addr(ea));
}


/**
	* Generate a random Ethernet address that is locally administered
	* and not multicast.
	* @param addr
	*/
static inline void eth_random_addr(uint8_t *addr)
{
	uint64_t rand = rte_rand();
	uint8_t *p = (uint8_t*)&rand;
	rte_memcpy(addr, p, 6);
	addr[0] &= ~0x01; 


	addr[0] |= 0x02; 


}


/**
	* Fast copy an Ethernet address.
	* @param ea_from
	* @param ea_to
	*/
static inline void ether_addr_copy(const struct ether_addr *ea_from,
						 struct ether_addr *ea_to)
{

/*
	 * Use the common way, because of a strange gcc warning.
	 */
	*ea_to = *ea_from;
}


/**
	* Format 48bits Ethernet address in pattern xx:xx:xx:xx:xx:xx.
	* @param buf
	* @param size
	* @param eth_addr
	*/
static inline void
ether_format_addr(char *buf, uint16_t size,
				const struct ether_addr *eth_addr)
{
	snprintf(buf, size, "%02X:%02X:%02X:%02X:%02X:%02X",
			eth_addr->addr_bytes[0],
			eth_addr->addr_bytes[1],
			eth_addr->addr_bytes[2],
			eth_addr->addr_bytes[3],
			eth_addr->addr_bytes[4],
			eth_addr->addr_bytes[5]);
}


/**
	* Ethernet header: Contains the destination address, source address
	* and frame type.
	*/
struct ether_hdr
{
	struct ether_addr d_addr; 


	struct ether_addr s_addr; 


	uint16_t ether_type; 


} __attribute__((__packed__));


/**
	* Ethernet VLAN Header.
	* Contains the 16-bit VLAN Tag Control Identifier and the Ethernet type
	* of the encapsulated frame.
	*/
struct vlan_hdr
{
	uint16_t vlan_tci; 


	uint16_t eth_proto;


} __attribute__((__packed__));


/**
	* VXLAN protocol header.
	* Contains the 8-bit flag, 24-bit VXLAN Network Identifier and
	* Reserved fields (24 bits and 8 bits)
	*/
struct vxlan_hdr
{
	uint32_t vx_flags; 


	uint32_t vx_vni; 


} __attribute__((__packed__));








/**
	* Extract VLAN tag information into mbuf
	* Software version of VLAN stripping
	* @param m
	* @return
	*/
static inline int rte_vlan_strip(struct rte_mbuf *m)
{
	struct ether_hdr *eh
			= ((struct ether_hdr *)((char *)(m)->buf_addr + (m)->data_off + (0)));
	if (eh->ether_type != ((uint16_t)(__builtin_constant_p(0x8100) ? rte_constant_bswap16(0x8100) : rte_arch_bswap16(0x8100))))
		return -1;
	struct vlan_hdr *vh = (struct vlan_hdr *)(eh + 1);
	m->ol_flags |= (1ULL << 0);
	m->vlan_tci = ((uint16_t)(__builtin_constant_p(vh->vlan_tci) ? rte_constant_bswap16(vh->vlan_tci) : rte_arch_bswap16(vh->vlan_tci)));


	memmove(rte_pktmbuf_adj(m, sizeof(struct vlan_hdr)),
		eh, 2 * 6);
	return 0;
}


/**
	* Insert VLAN tag into mbuf.
	* Software version of VLAN unstripping
	* @param m
	* @return
	*/
static inline int rte_vlan_insert(struct rte_mbuf **m)
{
	struct ether_hdr *oh, *nh;
	struct vlan_hdr *vh;


	if (rte_mbuf_refcnt_read(*m) > 1)
{
		struct rte_mbuf *copy;
		copy = rte_pktmbuf_clone(*m, (*m)->pool);
		if (__builtin_expect((copy == NULL),0))
			return -ENOMEM;
		rte_pktmbuf_free(*m);
		*m = copy;
	}
	oh = ((struct ether_hdr *)((char *)(*m)->buf_addr + (*m)->data_off + (0)));
	nh = (struct ether_hdr *)
		rte_pktmbuf_prepend(*m, sizeof(struct vlan_hdr));
	if (nh == NULL)
		return -ENOSPC;
	memmove(nh, oh, 2 * 6);
	nh->ether_type = ((uint16_t)(__builtin_constant_p(0x8100) ? rte_constant_bswap16(0x8100) : rte_arch_bswap16(0x8100)));
	vh = (struct vlan_hdr *) (nh + 1);
	vh->vlan_tci = ((uint16_t)(__builtin_constant_p((*m)->vlan_tci) ? rte_constant_bswap16((*m)->vlan_tci) : rte_arch_bswap16((*m)->vlan_tci)));
	return 0;
}


/**
	* ARP header IPv4 payload.
	*/
struct arp_ipv4
{
	struct ether_addr arp_sha; 


	uint32_t arp_sip; 


	struct ether_addr arp_tha; 


	uint32_t arp_tip; 


} __attribute__((__packed__));


/**
	* ARP header.
	*/
struct arp_hdr
{
	uint16_t arp_hrd; 


	uint16_t arp_pro; 


	uint8_t arp_hln; 


	uint8_t arp_pln; 


	uint16_t arp_op; 


	struct arp_ipv4 arp_data;
} __attribute__((__packed__));


/*-
	*/
//#include <rte_bitmap.h>  All static inline methods


/*-
	*/


/*-
	*/


/**
* @file
* RTE Configuration File
*
* This library allows reading application defined parameters from standard
* format configuration file.
*
***/



struct rte_cfgfile;



struct rte_cfgfile_entry
{
	char name[64]; 


	char value[256]; 


};


/**
* Open config file
*
* @param filename
*   Config file name
* @param flags
*   Config file flags, Reserved for future use. Must be set to 0.
* @return
*   Handle to configuration file on success, NULL otherwise
*/
struct rte_cfgfile *rte_cfgfile_load(const char *filename, int flags);


/**
* Get number of sections in config file
*
* @param cfg
*   Config file
* @param sec_name
*   Section name
* @param length
*   Maximum section name length
* @return
*   0 on success, error code otherwise
*/
int rte_cfgfile_num_sections(struct rte_cfgfile *cfg, const char *sec_name,
	size_t length);


/**
* Get name of all config file sections.
*
* Fills in the array sections with the name of all the sections in the file
* (up to the number of max_sections sections).
*
* @param cfg
*   Config file
* @param sections
*   Array containing section names after successful invocation. Each elemen
*   of this array should be preallocated by the user with at least
*   CFG_NAME_LEN characters.
* @param max_sections
*   Maximum number of section names to be stored in sections array
* @return
*   0 on success, error code otherwise
*/
int rte_cfgfile_sections(struct rte_cfgfile *cfg, char *sections[],
	int max_sections);


/**
* Check if given section exists in config file
*
* @param cfg
*   Config file
* @param sectionname
*   Section name
* @return
*   TRUE (value different than 0) if section exists, FALSE (value 0) otherwise
*/
int rte_cfgfile_has_section(struct rte_cfgfile *cfg, const char *sectionname);


/**
* Get number of entries in given config file section
*
* If multiple sections have the given name this function operates on the
* first one.
*
* @param cfg
*   Config file
* @param sectionname
*   Section name
* @return
*   Number of entries in section
*/
int rte_cfgfile_section_num_entries(struct rte_cfgfile *cfg,
	const char *sectionname);


/** Get section entries as key-value pairs
*
* If multiple sections have the given name this function operates on the
* first one.
*
* @param cfg
*   Config file
* @param sectionname
*   Section name
* @param entries
*   Pre-allocated array of at least max_entries entries where the section
*   entries are stored as key-value pair after successful invocation
* @param max_entries
*   Maximum number of section entries to be stored in entries array
* @return
*   0 on success, error code otherwise
*/
int rte_cfgfile_section_entries(struct rte_cfgfile *cfg,
	const char *sectionname,
	struct rte_cfgfile_entry *entries,
	int max_entries);


/** Get section entries as key-value pairs
*
* The index of a section is the same as the index of its name in the
* result of rte_cfgfile_sections. This API can be used when there are
* multiple sections with the same name.
*
* @param cfg
*   Config file
* @param index
*   Section index
* @param sectionname
*   Pre-allocated string of at least CFG_NAME_LEN characters where the
*   section name is stored after successful invocation.
* @param entries
*   Pre-allocated array of at least max_entries entries where the section
*   entries are stored as key-value pair after successful invocation
* @param max_entries
*   Maximum number of section entries to be stored in entries array
* @return
*   Number of entries populated on success, negative error code otherwise
*/
int rte_cfgfile_section_entries_by_index(struct rte_cfgfile *cfg,
	int index,
	char *sectionname,
	struct rte_cfgfile_entry *entries,
	int max_entries);


/** Get value of the named entry in named config file section
*
* If multiple sections have the given name this function operates on the
* first one.
*
* @param cfg
*   Config file
* @param sectionname
*   Section name
* @param entryname
*   Entry name
* @return
*   Entry value
*/
const char *rte_cfgfile_get_entry(struct rte_cfgfile *cfg,
	const char *sectionname,
	const char *entryname);


/** Check if given entry exists in named config file section
*
* If multiple sections have the given name this function operates on the
* first one.
*
* @param cfg
*   Config file
* @param sectionname
*   Section name
* @param entryname
*   Entry name
* @return
*   TRUE (value different than 0) if entry exists, FALSE (value 0) otherwise
*/
int rte_cfgfile_has_entry(struct rte_cfgfile *cfg, const char *sectionname,
	const char *entryname);


/** Close config file
*
* @param cfg
*   Config file
* @return
*   0 on success, error code otherwise
*/
int rte_cfgfile_close(struct rte_cfgfile *cfg);


/*-
	*/


/*-
	*/


/**
	* @file rte_crypto.h
	* RTE Cryptography Common Definitions
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/**
	* @file rte_crypto_sym.h
	* RTE Definitions for Symmetric Cryptography
	* Defines symmetric cipher and authentication algorithms and modes, as well
	* as supported symmetric crypto operation combinations.
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/



enum rte_crypto_cipher_algorithm
{
	RTE_CRYPTO_CIPHER_NULL = 1,


	RTE_CRYPTO_CIPHER_3DES_CBC,


	RTE_CRYPTO_CIPHER_3DES_CTR,


	RTE_CRYPTO_CIPHER_3DES_ECB,


	RTE_CRYPTO_CIPHER_AES_CBC,


	RTE_CRYPTO_CIPHER_AES_CCM,

/**< AES algorithm in CCM mode. When this cipher algorithm is used the
	 * *RTE_CRYPTO_AUTH_AES_CCM* element of the
	 * *rte_crypto_hash_algorithm* enum MUST be used to set up the related
	 * *rte_crypto_auth_xform* structure in the session context or in
	 * the op_params of the crypto operation structure in the case of a
	 * session-less crypto operation
	 */
	RTE_CRYPTO_CIPHER_AES_CTR,


	RTE_CRYPTO_CIPHER_AES_ECB,


	RTE_CRYPTO_CIPHER_AES_F8,


	RTE_CRYPTO_CIPHER_AES_GCM,

/**< AES algorithm in GCM mode. When this cipher algorithm is used the
	 * *RTE_CRYPTO_AUTH_AES_GCM* element of the
	 * *rte_crypto_auth_algorithm* enum MUST be used to set up the related
	 * *rte_crypto_auth_setup_data* structure in the session context or in
	 * the op_params of the crypto operation structure in the case of a
	 * session-less crypto operation.
	 */
	RTE_CRYPTO_CIPHER_AES_XTS,


	RTE_CRYPTO_CIPHER_ARC4,


	RTE_CRYPTO_CIPHER_KASUMI_F8,


	RTE_CRYPTO_CIPHER_SNOW3G_UEA2,


	RTE_CRYPTO_CIPHER_ZUC_EEA3,


	RTE_CRYPTO_CIPHER_LIST_END
};



enum rte_crypto_cipher_operation
{
	RTE_CRYPTO_CIPHER_OP_ENCRYPT,


	RTE_CRYPTO_CIPHER_OP_DECRYPT


};


/**
	* Symmetric Cipher Setup Data.
	* This structure contains data relating to Cipher (Encryption and Decryption)
	*  use to create a session.
	*/
struct rte_crypto_cipher_xform
{
	enum rte_crypto_cipher_operation op;

/**< This parameter determines if the cipher operation is an encrypt or
	 * a decrypt operation. For the RC4 algorithm and the F8/CTR modes,
	 * only encrypt operations are valid.
	 */
	enum rte_crypto_cipher_algorithm algo;


	struct
{
		uint8_t *data; 


		size_t length; 


	} key;

/**< Cipher key
	 *
	 * For the RTE_CRYPTO_CIPHER_AES_F8 mode of operation, key.data will
	 * point to a concatenation of the AES encryption key followed by a
	 * keymask. As per RFC3711, the keymask should be padded with trailing
	 * bytes to match the length of the encryption key used.
	 *
	 * For AES-XTS mode of operation, two keys must be provided and
	 * key.data must point to the two keys concatenated together (Key1 ||
	 * Key2). The cipher key length will contain the total size of both
	 * keys.
	 *
	 * Cipher key length is in bytes. For AES it can be 128 bits (16 bytes),
	 * 192 bits (24 bytes) or 256 bits (32 bytes).
	 *
	 * For the CCM mode of operation, the only supported key length is 128
	 * bits (16 bytes).
	 *
	 * For the RTE_CRYPTO_CIPHER_AES_F8 mode of operation, key.length
	 * should be set to the combined length of the encryption key and the
	 * keymask. Since the keymask and the encryption key are the same size,
	 * key.length should be set to 2 x the AES encryption key length.
	 *
	 * For the AES-XTS mode of operation:
	 *  - Two keys must be provided and key.length refers to total length of
	 *  - Each key can be either 128 bits (16 bytes) or 256 bits (32 bytes).
	 *  - Both keys must have the same size.
	 **/
};



enum rte_crypto_auth_algorithm
{
	RTE_CRYPTO_AUTH_NULL = 1,


	RTE_CRYPTO_AUTH_AES_CBC_MAC,


	RTE_CRYPTO_AUTH_AES_CCM,

/**< AES algorithm in CCM mode. This is an authenticated cipher. When
	 * this hash algorithm is used, the *RTE_CRYPTO_CIPHER_AES_CCM*
	 * element of the *rte_crypto_cipher_algorithm* enum MUST be used to
	 * set up the related rte_crypto_cipher_setup_data structure in the
	 * session context or the corresponding parameter in the crypto
	 * operation data structures op_params parameter MUST be set for a
	 * session-less crypto operation.
	 */
	RTE_CRYPTO_AUTH_AES_CMAC,


	RTE_CRYPTO_AUTH_AES_GCM,

/**< AES algorithm in GCM mode. When this hash algorithm
	 * is used, the RTE_CRYPTO_CIPHER_AES_GCM element of the
	 * rte_crypto_cipher_algorithm enum MUST be used to set up the related
	 * rte_crypto_cipher_setup_data structure in the session context, or
	 * the corresponding parameter in the crypto operation data structures
	 * op_params parameter MUST be set for a session-less crypto operation.
	 */
	RTE_CRYPTO_AUTH_AES_GMAC,

/**< AES GMAC algorithm. When this hash algorithm
	* is used, the RTE_CRYPTO_CIPHER_AES_GCM element of the
	* rte_crypto_cipher_algorithm enum MUST be used to set up the related
	* rte_crypto_cipher_setup_data structure in the session context,  or
	* the corresponding parameter in the crypto operation data structures
	* op_params parameter MUST be set for a session-less crypto operation.
	*/
	RTE_CRYPTO_AUTH_AES_XCBC_MAC,


	RTE_CRYPTO_AUTH_KASUMI_F9,


	RTE_CRYPTO_AUTH_MD5,


	RTE_CRYPTO_AUTH_MD5_HMAC,


	RTE_CRYPTO_AUTH_SHA1,


	RTE_CRYPTO_AUTH_SHA1_HMAC,


	RTE_CRYPTO_AUTH_SHA224,


	RTE_CRYPTO_AUTH_SHA224_HMAC,


	RTE_CRYPTO_AUTH_SHA256,


	RTE_CRYPTO_AUTH_SHA256_HMAC,


	RTE_CRYPTO_AUTH_SHA384,


	RTE_CRYPTO_AUTH_SHA384_HMAC,


	RTE_CRYPTO_AUTH_SHA512,


	RTE_CRYPTO_AUTH_SHA512_HMAC,


	RTE_CRYPTO_AUTH_SNOW3G_UIA2,


	RTE_CRYPTO_AUTH_ZUC_EIA3,


	RTE_CRYPTO_AUTH_LIST_END
};



enum rte_crypto_auth_operation
{
	RTE_CRYPTO_AUTH_OP_VERIFY, 


	RTE_CRYPTO_AUTH_OP_GENERATE 


};


/**
	* Authentication / Hash transform data.
	* This structure contains data relating to an authentication/hash crypto
	* transforms. The fields op, algo and digest_length are common to all
	* authentication transforms and MUST be set.
	*/
struct rte_crypto_auth_xform
{
	enum rte_crypto_auth_operation op;


	enum rte_crypto_auth_algorithm algo;


	struct
{
		uint8_t *data; 


		size_t length; 


	} key;

/**< Authentication key data.
	 * The authentication key length MUST be less than or equal to the
	 * block size of the algorithm. It is the callers responsibility to
	 * ensure that the key length is compliant with the standard being used
	 * (for example RFC 2104, FIPS 198a).
	 */
	uint32_t digest_length;

/**< Length of the digest to be returned. If the verify option is set,
	 * this specifies the length of the digest to be compared for the
	 * session.
	 *
	 * If the value is less than the maximum length allowed by the hash,
	 * the result shall be truncated.  If the value is greater than the
	 * maximum length allowed by the hash then an error will be generated
	 * by *rte_cryptodev_sym_session_create* or by the
	 * *rte_cryptodev_sym_enqueue_burst* if using session-less APIs.
	 */
	uint32_t add_auth_data_length;

/**< The length of the additional authenticated data (AAD) in bytes.
	 * The maximum permitted value is 240 bytes, unless otherwise specified
	 * below.
	 *
	 * This field must be specified when the hash algorithm is one of the
	 * following:
	 *
	 * - For SNOW3G (@ref RTE_CRYPTO_AUTH_SNOW3G_UIA2), this is the
	 *
	 * - For GCM (@ref RTE_CRYPTO_AUTH_AES_GCM).  In this case, this is
	 *
	 * - For CCM (@ref RTE_CRYPTO_AUTH_AES_CCM).  In this case, this is
	 *
	 * @note
	 *  For AES-GMAC (@ref RTE_CRYPTO_AUTH_AES_GMAC) mode of operation
	 *  this field is not used and should be set to 0. Instead the length
	 *  of the AAD data is specified in the message length to hash field of
	 *  the rte_crypto_sym_op_data structure.
	 */
};



enum rte_crypto_sym_xform_type
{
	RTE_CRYPTO_SYM_XFORM_NOT_SPECIFIED = 0, 


	RTE_CRYPTO_SYM_XFORM_AUTH, 


	RTE_CRYPTO_SYM_XFORM_CIPHER 


};


/**
	* Symmetric crypto transform structure.
	* This is used to specify the crypto transforms required, multiple transforms
	* can be chained together to specify a chain transforms such as authentication
	* then cipher, or cipher then authentication. Each transform structure can
	* hold a single transform, the type field is used to specify which transform
	* is contained within the union
	*/
struct rte_crypto_sym_xform
{
	struct rte_crypto_sym_xform *next;


	enum rte_crypto_sym_xform_type type
	; 



	union
{
		struct rte_crypto_auth_xform auth;


		struct rte_crypto_cipher_xform cipher;


	};
};


/**
	* Crypto operation session type. This is used to specify whether a crypto
	* operation has session structure attached for immutable parameters or if all
	* operation information is included in the operation data structure.
	*/
enum rte_crypto_sym_op_sess_type
{
	RTE_CRYPTO_SYM_OP_WITH_SESSION, 


	RTE_CRYPTO_SYM_OP_SESSIONLESS 


};
struct rte_cryptodev_sym_session;


/**
	* Symmetric Cryptographic Operation.
	* This structure contains data relating to performing symmetric cryptographic
	* processing on a referenced mbuf data buffer.
	* When a symmetric crypto operation is enqueued with the device for processing
	* it must have a valid *rte_mbuf* structure attached, via m_src parameter,
	* which contains the source data which the crypto operation is to be performed
	* on.
	*/
struct rte_crypto_sym_op
{
	struct rte_mbuf *m_src; 


	struct rte_mbuf *m_dst; 


	enum rte_crypto_sym_op_sess_type sess_type;

	union
{
		struct rte_cryptodev_sym_session *session;


		struct rte_crypto_sym_xform *xform;


	};
	struct
{
		struct
{
			uint32_t offset;

/**< Starting point for cipher processing, specified
			  * as number of bytes from start of data in the source
			  * buffer. The result of the cipher operation will be
			  * written back into the output buffer starting at
			  * this location.
			  *
			  * @note
			  * For Snow3G @ RTE_CRYPTO_CIPHER_SNOW3G_UEA2
			  * and KASUMI @ RTE_CRYPTO_CIPHER_KASUMI_F8,
			  * this field should be in bits.
			  */
			uint32_t length;

/**< The message length, in bytes, of the source buffer
			  * on which the cryptographic operation will be
			  * computed. This must be a multiple of the block size
			  * if a block cipher is being used. This is also the
			  * same as the result length.
			  *
			  * @note
			  * In the case of CCM @ref RTE_CRYPTO_AUTH_AES_CCM,
			  * this value should not include the length of the
			  * padding or the length of the MAC; the driver will
			  * compute the actual number of bytes over which the
			  * encryption will occur, which will include these
			  * values.
			  *
			  * @note
			  * For AES-GMAC @ref RTE_CRYPTO_AUTH_AES_GMAC, this
			  * field should be set to 0.
			  *
			  * @note
			  * For Snow3G @ RTE_CRYPTO_AUTH_SNOW3G_UEA2
			  * and KASUMI @ RTE_CRYPTO_CIPHER_KASUMI_F8,
			  * this field should be in bits.
			  */
		} data; 


		struct
{
			uint8_t *data;

/**< Initialisation Vector or Counter.
			 *
			 * - For block ciphers in CBC or F8 mode, or for Kasumi
			 * in F8 mode, or for SNOW3G in UEA2 mode, this is the
			 * Initialisation Vector (IV) value.
			 *
			 * - For block ciphers in CTR mode, this is the counter.
			 *
			 * - For GCM mode, this is either the IV (if the length
			 * is 96 bits) or J0 (for other sizes), where J0 is as
			 * defined by NIST SP800-38D. Regardless of the IV
			 * length, a full 16 bytes needs to be allocated.
			 *
			 * - For CCM mode, the first byte is reserved, and the
			 * nonce should be written starting at &iv[1] (to allow
			 * space for the implementation to write in the flags
			 * in the first byte). Note that a full 16 bytes should
			 * be allocated, even though the length field will
			 * have a value less than this.
			 *
			 * - For AES-XTS, this is the 128bit tweak, i, from
			 * IEEE Std 1619-2007.
			 *
			 * For optimum performance, the data pointed to SHOULD
			 * be 8-byte aligned.
			 */
			phys_addr_t phys_addr;
			uint16_t length;

/**< Length of valid IV data.
			 *
			 * - For block ciphers in CBC or F8 mode, or for Kasumi
			 * in F8 mode, or for SNOW3G in UEA2 mode, this is the
			 * length of the IV (which must be the same as the
			 * block length of the cipher).
			 *
			 * - For block ciphers in CTR mode, this is the length
			 * of the counter (which must be the same as the block
			 * length of the cipher).
			 *
			 * - For GCM mode, this is either 12 (for 96-bit IVs)
			 * or 16, in which case data points to J0.
			 *
			 * - For CCM mode, this is the length of the nonce,
			 * which can be in the range 7 to 13 inclusive.
			 */
		} iv; 


	} cipher;
	struct
{
		struct
{
			uint32_t offset;

/**< Starting point for hash processing, specified as
			  * number of bytes from start of packet in source
			  * buffer.
			  *
			  * @note
			  * For CCM and GCM modes of operation, this field is
			  * ignored. The field @ref aad field
			  * should be set instead.
			  *
			  * @note For AES-GMAC (@ref RTE_CRYPTO_AUTH_AES_GMAC)
			  * mode of operation, this field specifies the start
			  * of the AAD data in the source buffer.
			  *
			  * @note
			  * For Snow3G @ RTE_CRYPTO_AUTH_SNOW3G_UIA2
			  * and KASUMI @ RTE_CRYPTO_AUTH_KASUMI_F9,
			  * this field should be in bits.
			  */
			uint32_t length;

/**< The message length, in bytes, of the source
			  * buffer that the hash will be computed on.
			  *
			  * @note
			  * For CCM and GCM modes of operation, this field is
			  * ignored. The field @ref aad field should be set
			  * instead.
			  *
			  * @note
			  * For AES-GMAC @ref RTE_CRYPTO_AUTH_AES_GMAC mode
			  * of operation, this field specifies the length of
			  * the AAD data in the source buffer.
			  *
			  * @note
			  * For Snow3G @ RTE_CRYPTO_AUTH_SNOW3G_UIA2
			  * and KASUMI @ RTE_CRYPTO_AUTH_KASUMI_F9,
			  * this field should be in bits.
			  */
		} data; 


		struct
{
			uint8_t *data;

/**< If this member of this structure is set this is a
			 * pointer to the location where the digest result
			 * should be inserted (in the case of digest generation)
			 * or where the purported digest exists (in the case of
			 * digest verification).
			 *
			 * At session creation time, the client specified the
			 * digest result length with the digest_length member
			 * of the @ref rte_crypto_auth_xform structure. For
			 * physical crypto devices the caller must allocate at
			 * least digest_length of physically contiguous memory
			 * at this location.
			 *
			 * For digest generation, the digest result will
			 * overwrite any data at this location.
			 *
			 * @note
			 * For GCM (@ref RTE_CRYPTO_AUTH_AES_GCM), for
			 * "digest result" read "authentication tag T".
			 *
			 * If this member is not set the digest result is
			 * understood to be in the destination buffer for
			 * digest generation, and in the source buffer for
			 * digest verification. The location of the digest
			 * result in this case is immediately following the
			 * region over which the digest is computed.
			 */
			phys_addr_t phys_addr;


			uint16_t length;


		} digest; 


		struct
{
			uint8_t *data;

/**< Pointer to Additional Authenticated Data (AAD)
			 * needed for authenticated cipher mechanisms (CCM and
			 * GCM), and to the IV for SNOW3G authentication
			 * (@ref RTE_CRYPTO_AUTH_SNOW3G_UIA2). For other
			 * authentication mechanisms this pointer is ignored.
			 *
			 * The length of the data pointed to by this field is
			 * set up for the session in the @ref
			 * rte_crypto_auth_xform structure as part of the @ref
			 * rte_cryptodev_sym_session_create function call.
			 * This length must not exceed 240 bytes.
			 *
			 * Specifically for CCM (@ref RTE_CRYPTO_AUTH_AES_CCM),
			 * the caller should setup this field as follows:
			 *
			 * - the nonce should be written starting at an offset
			 * of one byte into the array, leaving room for the
			 * implementation to write in the flags to the first
			 *  byte.
			 *
			 * - the additional  authentication data itself should
			 * be written starting at an offset of 18 bytes into
			 * the array, leaving room for the length encoding in
			 * the first two bytes of the second block.
			 *
			 * - the array should be big enough to hold the above
			 *  fields, plus any padding to round this up to the
			 *  nearest multiple of the block size (16 bytes).
			 *  Padding will be added by the implementation.
			 *
			 * Finally, for GCM (@ref RTE_CRYPTO_AUTH_AES_GCM), the
			 * caller should setup this field as follows:
			 *
			 * - the AAD is written in starting at byte 0
			 * - the array must be big enough to hold the AAD, plus
			 * any space to round this up to the nearest multiple
			 * of the block size (16 bytes).
			 *
			 * @note
			 * For AES-GMAC (@ref RTE_CRYPTO_AUTH_AES_GMAC) mode of
			 * operation, this field is not used and should be set
			 * to 0. Instead the AAD data should be placed in the
			 * source buffer.
			 */
			phys_addr_t phys_addr; 


			uint16_t length; 


		} aad;


	} auth;
} __attribute__((__aligned__(64)));


/**
	* Reset the fields of a symmetric operation to their default values.
	* @param	op	The crypto operation to be reset.
	*/
static inline void
__rte_crypto_sym_op_reset(struct rte_crypto_sym_op *op)
{
	memset(op, 0, sizeof(*op));
	op->sess_type = RTE_CRYPTO_SYM_OP_SESSIONLESS;
}


/**
	* Allocate space for symmetric crypto xforms in the private data space of the
	* crypto operation. This also defaults the crypto xform type to
	* RTE_CRYPTO_SYM_XFORM_NOT_SPECIFIED and configures the chaining of the xforms
	* in the crypto operation
	* @return
	* - On success returns pointer to first crypto xform in crypto operations chain
	* - On failure returns NULL
	*/
static inline struct rte_crypto_sym_xform *
__rte_crypto_sym_op_sym_xforms_alloc(struct rte_crypto_sym_op *sym_op,
		void *priv_data, uint8_t nb_xforms)
{
	struct rte_crypto_sym_xform *xform;
	sym_op->xform = xform = (struct rte_crypto_sym_xform *)priv_data;
	do
{
		xform->type = RTE_CRYPTO_SYM_XFORM_NOT_SPECIFIED;
		xform = xform->next = --nb_xforms > 0 ? xform + 1 : NULL;
	} while (xform);
	return sym_op->xform;
}


/**
	* Attach a session to a symmetric crypto operation
	* @param	sym_op	crypto operation
	* @param	sess	cryptodev session
	*/
static inline int
__rte_crypto_sym_op_attach_sym_session(struct rte_crypto_sym_op *sym_op,
		struct rte_cryptodev_sym_session *sess)
{
	sym_op->session = sess;
	sym_op->sess_type = RTE_CRYPTO_SYM_OP_WITH_SESSION;
	return 0;
}



enum rte_crypto_op_type
{
	RTE_CRYPTO_OP_TYPE_UNDEFINED,


	RTE_CRYPTO_OP_TYPE_SYMMETRIC,


};



enum rte_crypto_op_status
{
	RTE_CRYPTO_OP_STATUS_SUCCESS,


	RTE_CRYPTO_OP_STATUS_NOT_PROCESSED,


	RTE_CRYPTO_OP_STATUS_ENQUEUED,


	RTE_CRYPTO_OP_STATUS_AUTH_FAILED,


	RTE_CRYPTO_OP_STATUS_INVALID_SESSION,

/**<
	 * Symmetric operation failed due to invalid session arguments, or if
	 * in session-less mode, failed to allocate private operation material.
	 */
	RTE_CRYPTO_OP_STATUS_INVALID_ARGS,


	RTE_CRYPTO_OP_STATUS_ERROR,


};


/**
	* Cryptographic Operation.
	* This structure contains data relating to performing cryptographic
	* operations. This operation structure is used to contain any operation which
	* is supported by the cryptodev API, PMDs should check the type parameter to
	* verify that the operation is a support function of the device. Crypto
	* operations are enqueued and dequeued in crypto PMDs using the
	* rte_cryptodev_enqueue_burst() / rte_cryptodev_dequeue_burst() .
	*/
struct rte_crypto_op
{
	enum rte_crypto_op_type type;


	enum rte_crypto_op_status status;

/**<
	 * operation status - this is reset to
	 * RTE_CRYPTO_OP_STATUS_NOT_PROCESSED on allocation from mempool and
	 * will be set to RTE_CRYPTO_OP_STATUS_SUCCESS after crypto operation
	 * is successfully processed by a crypto PMD
	 */
	struct rte_mempool *mempool;


	phys_addr_t phys_addr;


	void *opaque_data;



	union
{
		struct rte_crypto_sym_op *sym;


	}; 


} __attribute__((__aligned__(64)));


/**
	* Reset the fields of a crypto operation to their default values.
	* @param	op	The crypto operation to be reset.
	* @param	type	The crypto operation type.
	*/
static inline void
__rte_crypto_op_reset(struct rte_crypto_op *op, enum rte_crypto_op_type type)
{
	op->type = type;
	op->status = RTE_CRYPTO_OP_STATUS_NOT_PROCESSED;
	switch (type)
{
	case RTE_CRYPTO_OP_TYPE_SYMMETRIC:

/** Symmetric operation structure starts after the end of the
		 * rte_crypto_op structure.
		 */
		op->sym = (struct rte_crypto_sym_op *)(op + 1);
		op->type = type;
		__rte_crypto_sym_op_reset(op->sym);
		break;
	default:
		break;
	}
	op->opaque_data = NULL;
}


/**
	* Private data structure belonging to a crypto symmetric operation pool.
	*/
struct rte_crypto_op_pool_private
{
	enum rte_crypto_op_type type;


	uint16_t priv_size;


};


/**
	* Returns the size of private data allocated with each rte_crypto_op object by
	* the mempool
	* @param	mempool	rte_crypto_op mempool
	* @return	private data size
	*/
static inline uint16_t
__rte_crypto_op_get_priv_data_size(struct rte_mempool *mempool)
{
	struct rte_crypto_op_pool_private *priv =
		(struct rte_crypto_op_pool_private *) rte_mempool_get_priv(mempool);
	return priv->priv_size;
}


/**
	* Creates a crypto operation pool
	* @param	name		pool name
	* @param	type		crypto operation type, use
	*				RTE_CRYPTO_OP_TYPE_UNDEFINED for a pool which
	*				supports all operation types
	* @param	nb_elts		number of elements in pool
	* @param	cache_size	Number of elements to cache on lcore, see
	*				*rte_mempool_create* for further details about
	*				cache size
	* @param	priv_size	Size of private data to allocate with each
	*				operation
	* @param	socket_id	Socket to allocate memory on
	* @return
	*  - On success pointer to mempool
	*  - On failure NULL
	*/
extern struct rte_mempool *
rte_crypto_op_pool_create(const char *name, enum rte_crypto_op_type type,
		unsigned nb_elts, unsigned cache_size, uint16_t priv_size,
		int socket_id);


/**
	* Bulk allocate raw element from mempool and return as crypto operations
	* @param	mempool		crypto operation mempool.
	* @param	type		crypto operation type.
	* @param	ops		Array to place allocated crypto operations
	* @param	nb_ops		Number of crypto operations to allocate
	* @returns
	* - On success returns  number of ops allocated
	*/
static inline int
__rte_crypto_op_raw_bulk_alloc(struct rte_mempool *mempool,
		enum rte_crypto_op_type type,
		struct rte_crypto_op **ops, uint16_t nb_ops)
{
	struct rte_crypto_op_pool_private *priv;
	priv = (struct rte_crypto_op_pool_private *) rte_mempool_get_priv(mempool);
	if (__builtin_expect((priv->type != type && priv->type != RTE_CRYPTO_OP_TYPE_UNDEFINED),0))
		return -EINVAL;
	if (rte_mempool_get_bulk(mempool, (void **)ops, nb_ops) == 0)
		return nb_ops;
	return 0;
}


/**
	* Allocate a crypto operation from a mempool with default parameters set
	* @param	mempool	crypto operation mempool
	* @param	type	operation type to allocate
	* @returns
	* - On success returns a valid rte_crypto_op structure
	* - On failure returns NULL
	*/
static inline struct rte_crypto_op *
rte_crypto_op_alloc(struct rte_mempool *mempool, enum rte_crypto_op_type type)
{
	struct rte_crypto_op *op = NULL;
	int retval;
	retval = __rte_crypto_op_raw_bulk_alloc(mempool, type, &op, 1);
	if (__builtin_expect((retval != 1),0))
		return NULL;
	__rte_crypto_op_reset(op, type);
	return op;
}


/**
	* Bulk allocate crypto operations from a mempool with default parameters set
	* @param	mempool	crypto operation mempool
	* @param	type	operation type to allocate
	* @param	ops	Array to place allocated crypto operations
	* @param	nb_ops	Number of crypto operations to allocate
	* @returns
	* - On success returns a valid rte_crypto_op structure
	* - On failure returns NULL
	*/
static inline unsigned
rte_crypto_op_bulk_alloc(struct rte_mempool *mempool,
		enum rte_crypto_op_type type,
		struct rte_crypto_op **ops, uint16_t nb_ops)
{
	int i;
	if (__builtin_expect((__rte_crypto_op_raw_bulk_alloc(mempool, type, ops, nb_ops) != nb_ops),0))
		return 0;
	for (i = 0; i < nb_ops; i++)
		__rte_crypto_op_reset(ops[i], type);
	return nb_ops;
}


/**
	* Returns a pointer to the private data of a crypto operation if
	* that operation has enough capacity for requested size.
	* @param	op	crypto operation.
	* @param	size	size of space requested in private data.
	* @returns
	* - if sufficient space available returns pointer to start of private data
	* - if insufficient space returns NULL
	*/
static inline void *
__rte_crypto_op_get_priv_data(struct rte_crypto_op *op, uint32_t size)
{
	uint32_t priv_size;
	if (__builtin_expect((op->mempool != NULL),1))
{
		priv_size = __rte_crypto_op_get_priv_data_size(op->mempool);
		if (__builtin_expect((priv_size >= size),1))
			return (void *)((uint8_t *)(op + 1) +
					sizeof(struct rte_crypto_sym_op));
	}
	return NULL;
}


/**
	* free crypto operation structure
	* If operation has been allocate from a rte_mempool, then the operation will
	* be returned to the mempool.
	* @param	op	symmetric crypto operation
	*/
static inline void
rte_crypto_op_free(struct rte_crypto_op *op)
{
	if (op != NULL && op->mempool != NULL)
		rte_mempool_put(op->mempool, op);
}


/**
	* Allocate a symmetric crypto operation in the private data of an mbuf.
	* @param	m	mbuf which is associated with the crypto operation, the
	*			operation will be allocated in the private data of that
	*			mbuf.
	* @returns
	* - On success returns a pointer to the crypto operation.
	* - On failure returns NULL.
	*/
static inline struct rte_crypto_op *
rte_crypto_sym_op_alloc_from_mbuf_priv_data(struct rte_mbuf *m)
{
	if (__builtin_expect((m == NULL),0))
		return NULL;

/*
	 * check that the mbuf's private data size is sufficient to contain a
	 * crypto operation
	 */
	if (__builtin_expect((m->priv_size < (sizeof(struct rte_crypto_op) + sizeof(struct rte_crypto_sym_op))),0))
		return NULL;


	struct rte_crypto_op *op = (struct rte_crypto_op *)(m + 1);
	__rte_crypto_op_reset(op, RTE_CRYPTO_OP_TYPE_SYMMETRIC);
	op->mempool = NULL;
	op->sym->m_src = m;
	return op;
}


/**
	* Allocate space for symmetric crypto xforms in the private data space of the
	* crypto operation. This also defaults the crypto xform type and configures
	* the chaining of the xforms in the crypto operation
	* @return
	* - On success returns pointer to first crypto xform in crypto operations chain
	* - On failure returns NULL
	*/
static inline struct rte_crypto_sym_xform *
rte_crypto_op_sym_xforms_alloc(struct rte_crypto_op *op, uint8_t nb_xforms)
{
	void *priv_data;
	uint32_t size;
	if (__builtin_expect((op->type != RTE_CRYPTO_OP_TYPE_SYMMETRIC),0))
		return NULL;
	size = sizeof(struct rte_crypto_sym_xform) * nb_xforms;
	priv_data = __rte_crypto_op_get_priv_data(op, size);
	if (priv_data == NULL)
		return NULL;
	return __rte_crypto_sym_op_sym_xforms_alloc(op->sym, priv_data,
			nb_xforms);
}


/**
	* Attach a session to a crypto operation
	* @param	op	crypto operation, must be of type symmetric
	* @param	sess	cryptodev session
	*/
static inline int
rte_crypto_op_attach_sym_session(struct rte_crypto_op *op,
		struct rte_cryptodev_sym_session *sess)
{
	if (__builtin_expect((op->type != RTE_CRYPTO_OP_TYPE_SYMMETRIC),0))
		return -1;
	return __rte_crypto_sym_op_attach_sym_session(op->sym, sess);
}
//#include <rte_cryptodev_pmd.h>  Out of memory


/*-
	*/


/**
	* @file
	* RTE PMD Driver Registration Interface
	* This file manages the list of device drivers.
	*/


/*
	* Copyright (c) 1991, 1993
	*	The Regents of the University of California.  All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	*	@(#)queue.h	8.5 (Berkeley) 8/20/94
	*/


/*-
	*/
__attribute__((format(printf, 2, 0)))
static inline void
rte_pmd_debug_trace(const char *func_name, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	char buffer[vsnprintf(NULL, 0, fmt, ap) + 1];
	va_end(ap);
	va_start(ap, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, ap);
	va_end(ap);
	rte_log(4U, 0x00000020, "%s: %s", func_name, buffer);
}









struct rte_driver_list { struct rte_driver *tqh_first; struct rte_driver * *tqh_last; };


/**
	* Initialization function called for each device driver once.
	*/
typedef int (rte_dev_init_t)(const char *name, const char *args);


/**
	* Uninitilization function called for each device driver once.
	*/
typedef int (rte_dev_uninit_t)(const char *name);


/**
	* Driver type enumeration
	*/
enum pmd_type
{
	PMD_VDEV = 0,
	PMD_PDEV = 1,
};


/**
	* A structure describing a device driver.
	*/
struct rte_driver
{
	struct { struct rte_driver *tqe_next; struct rte_driver * *tqe_prev; } next; 


	enum pmd_type type; 


	const char *name; 


	rte_dev_init_t *init; 


	rte_dev_uninit_t *uninit; 


};


/**
	* Register a device driver.
	* @param driver
	*/
void rte_eal_driver_register(struct rte_driver *driver);


/**
	* Unregister a device driver.
	* @param driver
	*/
void rte_eal_driver_unregister(struct rte_driver *driver);


/**
	* Initalize all the registered drivers in this process
	*/
int rte_eal_dev_init(void);


/**
	* Initialize a driver specified by name.
	* @param name
	* @param args
	* @return
	*  0 on success, negative on error
	*/
int rte_eal_vdev_init(const char *name, const char *args);


/**
	* Uninitalize a driver specified by name.
	* @param name
	* @return
	*  0 on success, negative on error
	*/
int rte_eal_vdev_uninit(const char *name);


/*-
	*/


/*
	* Placeholder for accessing device registers
	*/
struct rte_dev_reg_info
{
	void *data; 


	uint32_t offset; 


	uint32_t length; 


	uint32_t width; 


	uint32_t version; 


};


/*
	* Placeholder for accessing device eeprom
	*/
struct rte_dev_eeprom_info
{
	void *data; 


	uint32_t offset; 


	uint32_t length; 


	uint32_t magic; 


};
//#include <rte_devargs.h>  Out of memory


/*-
	*/


/**
	* @file
	* RTE distributor
	* The distributor is a component which is designed to pass packets
	* one-at-a-time to workers, with dynamic load balancing.
	*/
struct rte_distributor;
struct rte_mbuf;


/**
	* Function to create a new distributor instance
	* Reserves the memory needed for the distributor operation and
	* initializes the distributor to work with the configured number of workers.
	* @param name
	* @param socket_id
	* @param num_workers
	* @return
	*/
struct rte_distributor *
rte_distributor_create(const char *name, unsigned socket_id,
		unsigned num_workers);





/*
	* The following APIs are the public APIs which are designed for use on a
	* single lcore which acts as the distributor lcore for a given distributor
	* instance. These functions cannot be called on multiple cores simultaneously
	* without using locking to protect access to the internals of the distributor.
	* NOTE: a given lcore cannot act as both a distributor lcore and a worker lcore
	* for the same distributor instance, otherwise deadlock will result.
	*/


/**
	* Process a set of packets by distributing them among workers that request
	* packets. The distributor will ensure that no two packets that have the
	* same flow id, or tag, in the mbuf will be procesed at the same time.
	* The user is advocated to set tag for each mbuf before calling this function.
	* If user doesn't set the tag, the tag value can be various values depending on
	* driver implementation and configuration.
	* This is not multi-thread safe and should only be called on a single lcore.
	* @param d
	* @param mbufs
	* @param num_mbufs
	* @return
	*/
int
rte_distributor_process(struct rte_distributor *d,
		struct rte_mbuf **mbufs, unsigned num_mbufs);


/**
	* Get a set of mbufs that have been returned to the distributor by workers
	* This should only be called on the same lcore as rte_distributor_process()
	* @param d
	* @param mbufs
	* @param max_mbufs
	* @return
	*/
int
rte_distributor_returned_pkts(struct rte_distributor *d,
		struct rte_mbuf **mbufs, unsigned max_mbufs);


/**
	* Flush the distributor component, so that there are no in-flight or
	* backlogged packets awaiting processing
	* This should only be called on the same lcore as rte_distributor_process()
	* @param d
	* @return
	*/
int
rte_distributor_flush(struct rte_distributor *d);


/**
	* Clears the array of returned packets used as the source for the
	* rte_distributor_returned_pkts() API call.
	* This should only be called on the same lcore as rte_distributor_process()
	* @param d
	*/
void
rte_distributor_clear_returns(struct rte_distributor *d);





/*
	* The following APIs are the public APIs which are designed for use on
	* multiple lcores which act as workers for a distributor. Each lcore should use
	* a unique worker id when requesting packets.
	* NOTE: a given lcore cannot act as both a distributor lcore and a worker lcore
	* for the same distributor instance, otherwise deadlock will result.
	*/


/**
	* API called by a worker to get a new packet to process. Any previous packet
	* given to the worker is assumed to have completed processing, and may be
	* optionally returned to the distributor via the oldpkt parameter.
	* @param d
	* @param worker_id
	* @param oldpkt
	* @return
	*/
struct rte_mbuf *
rte_distributor_get_pkt(struct rte_distributor *d,
		unsigned worker_id, struct rte_mbuf *oldpkt);


/**
	* API called by a worker to return a completed packet without requesting a
	* new packet, for example, because a worker thread is shutting down
	* @param d
	* @param worker_id
	* @param mbuf
	*/
int
rte_distributor_return_pkt(struct rte_distributor *d, unsigned worker_id,
		struct rte_mbuf *mbuf);


/**
	* API called by a worker to request a new packet to process.
	* Any previous packet given to the worker is assumed to have completed
	* processing, and may be optionally returned to the distributor via
	* the oldpkt parameter.
	* Unlike rte_distributor_get_pkt(), this function does not wait for a new
	* packet to be provided by the distributor.
	* NOTE: after calling this function, rte_distributor_poll_pkt() should
	* be used to poll for the packet requested. The rte_distributor_get_pkt()
	* API should *not* be used to try and retrieve the new packet.
	* @param d
	* @param worker_id
	* @param oldpkt
	*/
void
rte_distributor_request_pkt(struct rte_distributor *d,
		unsigned worker_id, struct rte_mbuf *oldpkt);


/**
	* API called by a worker to check for a new packet that was previously
	* requested by a call to rte_distributor_request_pkt(). It does not wait
	* for the new packet to be available, but returns NULL if the request has
	* not yet been fulfilled by the distributor.
	* @param d
	* @param worker_id
	* @return
	*/
struct rte_mbuf *
rte_distributor_poll_pkt(struct rte_distributor *d,
		unsigned worker_id);


/*-
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	*  Here defines rte_tailq APIs for only internal use
	*/


/*
	* Copyright (c) 1991, 1993
	*	The Regents of the University of California.  All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	*	@(#)queue.h	8.5 (Berkeley) 8/20/94
	*/


/*-
	*/



struct rte_tailq_entry
{
	struct { struct rte_tailq_entry *tqe_next; struct rte_tailq_entry * *tqe_prev; } next; 


	void *data; 


};



struct rte_tailq_entry_head { struct rte_tailq_entry *tqh_first; struct rte_tailq_entry * *tqh_last; };


/**
	* The structure defining a tailq header entry for storing
	* in the rte_config structure in shared memory. Each tailq
	* is identified by name.
	* Any library storing a set of objects e.g. rings, mempools, hash-tables,
	* is recommended to use an entry here, so as to make it easy for
	* a multi-process app to find already-created elements in shared memory.
	*/
struct rte_tailq_head
{
	struct rte_tailq_entry_head tailq_head; 


	char name[32];
};
struct rte_tailq_elem
{

/**
	 * Reference to head in shared mem, updated at init time by
	 * rte_eal_tailqs_init()
	 */
	struct rte_tailq_head *head;
	struct { struct rte_tailq_elem *tqe_next; struct rte_tailq_elem * *tqe_prev; } next;
	const char name[32];
};


/**
	* Return the first tailq entry casted to the right struct.
	*/


/**
	* Utility macro to make looking up a tailqueue for a particular struct easier.
	* @param name
	* @param struct_name
	* @return
	*/


/**
	* Dump tail queues to the console.
	* @param f
	*/
void rte_dump_tailq(FILE *f);


/**
	* Lookup for a tail queue.
	* Get a pointer to a tail queue header of a tail
	* queue identified by the name given as an argument.
	* Note: this function is not multi-thread safe, and should only be called from
	* a single thread at a time
	* @param name
	* @return
	*/
struct rte_tailq_head *rte_eal_tailq_lookup(const char *name);


/**
	* Register a tail queue.
	* Register a tail queue from shared memory.
	* This function is mainly used by EAL_REGISTER_TAILQ macro which is used to
	* register tailq from the different dpdk libraries. Since this macro is a
	* constructor, the function has no access to dpdk shared memory, so the
	* registered tailq can not be used before call to rte_eal_init() which calls
	* rte_eal_tailqs_init().
	* @param t
	* @return
	*/
int rte_eal_tailq_register(struct rte_tailq_elem *t);





/*-
	*/


/*-
	*/


/*-
	*/


/*
	* Copyright (c) 1991, 1993
	*	The Regents of the University of California.  All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	*	@(#)queue.h	8.5 (Berkeley) 8/20/94
	*/


/*-
	*/


/*-
	*/





/**
	* Structure to hold malloc heap
	*/
struct malloc_heap
{
	rte_spinlock_t lock;
	struct { struct malloc_elem *lh_first; } free_head[13];
	unsigned alloc_count;
	size_t total_size;
} __attribute__((__aligned__(64)));


/*-
	*/


/*-
	*/


/**
	* @file
	* RTE Read-Write Locks
	* This file defines an API for read-write locks. The lock is used to
	* protect data that allows multiple readers in parallel, but only
	* one writer. All readers are blocked until the writer is finished
	* writing.
	*/


/*-
	*/


/*-
	*/


/**
	* The rte_rwlock_t type.
	* cnt is -1 when write lock is held, and > 0 when read locks are held.
	*/
typedef struct
{
	volatile int32_t cnt; 


} rte_rwlock_t;


/**
	* A static rwlock initializer.
	*/


/**
	* Initialize the rwlock to an unlocked state.
	* @param rwl
	*/
static inline void
rte_rwlock_init(rte_rwlock_t *rwl)
{
	rwl->cnt = 0;
}


/**
	* Take a read lock. Loop until the lock is held.
	* @param rwl
	*/
static inline void
rte_rwlock_read_lock(rte_rwlock_t *rwl)
{
	int32_t x;
	int success = 0;
	while (success == 0)
{
		x = rwl->cnt;


		if (x < 0)
{
			rte_pause();
			continue;
		}
		success = rte_atomic32_cmpset((volatile uint32_t *)&rwl->cnt,
						     x, x + 1);
	}
}


/**
	* Release a read lock.
	* @param rwl
	*/
static inline void
rte_rwlock_read_unlock(rte_rwlock_t *rwl)
{
	rte_atomic32_dec((rte_atomic32_t *)(intptr_t)&rwl->cnt);
}


/**
	* Take a write lock. Loop until the lock is held.
	* @param rwl
	*/
static inline void
rte_rwlock_write_lock(rte_rwlock_t *rwl)
{
	int32_t x;
	int success = 0;
	while (success == 0)
{
		x = rwl->cnt;


		if (x != 0)
{
			rte_pause();
			continue;
		}
		success = rte_atomic32_cmpset((volatile uint32_t *)&rwl->cnt,
						     0, -1);
	}
}


/**
	* Release a write lock.
	* @param rwl
	*/
static inline void
rte_rwlock_write_unlock(rte_rwlock_t *rwl)
{
	rte_atomic32_inc((rte_atomic32_t *)(intptr_t)&rwl->cnt);
}


/**
	* Try to execute critical section in a hardware memory transaction, if it
	* fails or not available take a read lock
	* NOTE: An attempt to perform a HW I/O operation inside a hardware memory
	* transaction always aborts the transaction since the CPU is not able to
	* roll-back should the transaction fail. Therefore, hardware transactional
	* locks are not advised to be used around rte_eth_rx_burst() and
	* rte_eth_tx_burst() calls.
	* @param rwl
	*/
static inline void
rte_rwlock_read_lock_tm(rte_rwlock_t *rwl);


/**
	* Commit hardware memory transaction or release the read lock if the lock is used as a fall-back
	* @param rwl
	*/
static inline void
rte_rwlock_read_unlock_tm(rte_rwlock_t *rwl);


/**
	* Try to execute critical section in a hardware memory transaction, if it
	* fails or not available take a write lock
	* NOTE: An attempt to perform a HW I/O operation inside a hardware memory
	* transaction always aborts the transaction since the CPU is not able to
	* roll-back should the transaction fail. Therefore, hardware transactional
	* locks are not advised to be used around rte_eth_rx_burst() and
	* rte_eth_tx_burst() calls.
	* @param rwl
	*/
static inline void
rte_rwlock_write_lock_tm(rte_rwlock_t *rwl);


/**
	* Commit hardware memory transaction or release the write lock if the lock is used as a fall-back
	* @param rwl
	*/
static inline void
rte_rwlock_write_unlock_tm(rte_rwlock_t *rwl);


/*-
	*/
static inline void
rte_rwlock_read_lock_tm(rte_rwlock_t *rwl)
{
	if (__builtin_expect((rte_try_tm(&rwl->cnt)),1))
		return;
	rte_rwlock_read_lock(rwl);
}
static inline void
rte_rwlock_read_unlock_tm(rte_rwlock_t *rwl)
{
	if (__builtin_expect((rwl->cnt),0))
		rte_rwlock_read_unlock(rwl);
	else
		rte_xend();
}
static inline void
rte_rwlock_write_lock_tm(rte_rwlock_t *rwl)
{
	if (__builtin_expect((rte_try_tm(&rwl->cnt)),1))
		return;
	rte_rwlock_write_lock(rwl);
}
static inline void
rte_rwlock_write_unlock_tm(rte_rwlock_t *rwl)
{
	if (__builtin_expect((rwl->cnt),0))
		rte_rwlock_write_unlock(rwl);
	else
		rte_xend();
}


/**
	* the structure for the memory configuration for the RTE.
	* Used by the rte_config structure. It is separated out, as for multi-process
	* support, the memory details should be shared across instances
	*/
struct rte_mem_config
{
	volatile uint32_t magic; 




	uint32_t nchannel; 


	uint32_t nrank; 



/**
	 * current lock nest order
	 *  - qlock->mlock (ring/hash/lpm)
	 *  - mplock->qlock->mlock (mempool)
	 * Notice:
	 *  *ALWAYS* obtain qlock first if having to obtain both qlock and mlock
	 */
	rte_rwlock_t mlock; 


	rte_rwlock_t qlock; 


	rte_rwlock_t mplock; 


	uint32_t memzone_cnt; 




	struct rte_memseg memseg[256]; 


	struct rte_memzone memzone[2560]; 


	struct rte_tailq_head tailq_head[32]; 




	struct malloc_heap malloc_heaps[8];

/* address of mem_config in primary process. used to map shared config into
	 * exact same address the primary process maps it.
	 */
	uint64_t mem_cfg_addr;
} __attribute__((__packed__));
inline static void
rte_eal_mcfg_wait_complete(struct rte_mem_config* mcfg)
{


	while(mcfg->magic != 19820526)
		rte_pause();
}


/*-
	*/


/**
	* @file
	* API for error cause tracking
	*/


/*-
	*/
extern __thread __typeof__(int) per_lcore__rte_errno; 




/**
	* Error number value, stored per-thread, which can be queried after
	* calls to certain functions to determine why those functions failed.
	* Uses standard values from errno.h wherever possible, with a small number
	* of additional possible values for RTE-specific conditions.
	*/


/**
	* Function which returns a printable string describing a particular
	* error code. For non-RTE-specific error codes, this function returns
	* the value from the libc strerror function.
	* @param errnum
	* @return
	*/
const char *rte_strerror(int errnum);


/**
	* Check if we have a defined value for the max system-defined errno values.
	* if no max defined, start from 1000 to prevent overlap with standard values
	*/



enum
{
	RTE_MIN_ERRNO = 1000, 


	E_RTE_SECONDARY, 


	E_RTE_NO_CONFIG, 


	RTE_MAX_ERRNO 


};


/*-
	*/


/**
	* @file rte_eth_bond.h
	* RTE Link Bonding Ethernet Device
	* Link Bonding for 1GbE and 10GbE ports to allow the aggregation of multiple
	* (slave) NICs into a single logical interface. The bonded device processes
	* these interfaces based on the mode of operation specified and supported.
	* This implementation supports 4 modes of operation round robin, active backup
	* balance and broadcast. Providing redundant links, fault tolerance and/or
	* load balancing of network ports
	*/


/*-
	*/





/**< Round Robin (Mode 0).
	* In this mode all transmitted packets will be balanced equally across all
	* active slaves of the bonded in a round robin fashion. */


/**< Active Backup (Mode 1).
	* In this mode all packets transmitted will be transmitted on the primary
	* slave until such point as the primary slave is no longer available and then
	* transmitted packets will be sent on the next available slaves. The primary
	* slave can be defined by the user but defaults to the first active slave
	* available if not specified. */


/**< Balance (Mode 2).
	* In this mode all packets transmitted will be balanced across the available
	* slaves using one of three available transmit policies - l2, l2+3 or l3+4.
	* See BALANCE_XMIT_POLICY macros definitions for further details on transmit
	* policies. */


/**< Broadcast (Mode 3).
	* In this mode all transmitted packets will be transmitted on all available
	* active slaves of the bonded. */


/**< 802.3AD (Mode 4).
	* This mode provides auto negotiation/configuration
	* of peers and well as link status changes monitoring using out of band
	* LACP (link aggregation control protocol) messages. For further details of
	* LACP specification see the IEEE 802.3ad/802.1AX standards. It is also
	* described here
	* https://www.kernel.org/doc/Documentation/networking/bonding.txt.
	* Important Usage Notes:
	* - for LACP mode to work the rx/tx burst functions must be invoked
	* at least once every 100ms, otherwise the out-of-band LACP messages will not
	* be handled with the expected latency and this may cause the link status to be
	* incorrectly marked as down or failure to correctly negotiate with peers.
	* - For optimal performance during initial handshaking the array of mbufs provided
	* to rx_burst should be at least 2 times the slave count size.
	*/


/**< Adaptive TLB (Mode 5)
	* This mode provides an adaptive transmit load balancing. It dynamically
	* changes the transmitting slave, according to the computed load. Statistics
	* are collected in 100ms intervals and scheduled every 10ms */


/**< Adaptive Load Balancing (Mode 6)
	* This mode includes adaptive TLB and receive load balancing (RLB). In RLB the
	* bonding driver intercepts ARP replies send by local system and overwrites its
	* source MAC address, so that different peers send data to the server on
	* different slave interfaces. When local system sends ARP request, it saves IP
	* information from it. When ARP reply from that peer is received, its MAC is
	* stored, one of slave MACs assigned and ARP reply send to that peer.
	*/














/**
	* Create a bonded rte_eth_dev device
	* @param name			Name of new link bonding device.
	* @param mode			Mode to initialize bonding device in.
	* @param socket_id		Socket Id on which to allocate eth_dev resources.
	* @return
	*	Port Id of created rte_eth_dev on success, negative value otherwise
	*/
int
rte_eth_bond_create(const char *name, uint8_t mode, uint8_t socket_id);


/**
	* Free a bonded rte_eth_dev device
	* @param name			Name of the link bonding device.
	* @return
	*	0 on success, negative value otherwise
	*/
int
rte_eth_bond_free(const char *name);


/**
	* Add a rte_eth_dev device as a slave to the bonded device
	* @param bonded_port_id	Port ID of bonded device.
	* @param slave_port_id		Port ID of slave device.
	* @return
	*	0 on success, negative value otherwise
	*/
int
rte_eth_bond_slave_add(uint8_t bonded_port_id, uint8_t slave_port_id);


/**
	* Remove a slave rte_eth_dev device from the bonded device
	* @param bonded_port_id	Port ID of bonded device.
	* @param slave_port_id		Port ID of slave device.
	* @return
	*	0 on success, negative value otherwise
	*/
int
rte_eth_bond_slave_remove(uint8_t bonded_port_id, uint8_t slave_port_id);


/**
	* Set link bonding mode of bonded device
	* @param bonded_port_id	Port ID of bonded device.
	* @param mode				Bonding mode to set
	* @return
	*	0 on success, negative value otherwise
	*/
int
rte_eth_bond_mode_set(uint8_t bonded_port_id, uint8_t mode);


/**
	* Get link bonding mode of bonded device
	* @param bonded_port_id	Port ID of bonded device.
	* @return
	*	link bonding mode on success, negative value otherwise
	*/
int
rte_eth_bond_mode_get(uint8_t bonded_port_id);


/**
	* Set slave rte_eth_dev as primary slave of bonded device
	* @param bonded_port_id	Port ID of bonded device.
	* @param slave_port_id		Port ID of slave device.
	* @return
	*	0 on success, negative value otherwise
	*/
int
rte_eth_bond_primary_set(uint8_t bonded_port_id, uint8_t slave_port_id);


/**
	* Get primary slave of bonded device
	* @param bonded_port_id	Port ID of bonded device.
	* @return
	*	Port Id of primary slave on success, -1 on failure
	*/
int
rte_eth_bond_primary_get(uint8_t bonded_port_id);


/**
	* Populate an array with list of the slaves port id's of the bonded device
	* @param bonded_port_id	Port ID of bonded eth_dev to interrogate
	* @param slaves			Array to be populated with the current active slaves
	* @param len				Length of slaves array
	* @return
	*	Number of slaves associated with bonded device on success,
	*	negative value otherwise
	*/
int
rte_eth_bond_slaves_get(uint8_t bonded_port_id, uint8_t slaves[], uint8_t len);


/**
	* Populate an array with list of the active slaves port id's of the bonded
	* device.
	* @param bonded_port_id	Port ID of bonded eth_dev to interrogate
	* @param slaves			Array to be populated with the current active slaves
	* @param len				Length of slaves array
	* @return
	*	Number of active slaves associated with bonded device on success,
	*	negative value otherwise
	*/
int
rte_eth_bond_active_slaves_get(uint8_t bonded_port_id, uint8_t slaves[],
		uint8_t len);


/**
	* Set explicit MAC address to use on bonded device and it's slaves.
	* @param bonded_port_id	Port ID of bonded device.
	* @param mac_addr			MAC Address to use on bonded device overriding
	*							slaves MAC addresses
	* @return
	*	0 on success, negative value otherwise
	*/
int
rte_eth_bond_mac_address_set(uint8_t bonded_port_id,
		struct ether_addr *mac_addr);


/**
	* Reset bonded device to use MAC from primary slave on bonded device and it's
	* slaves.
	* @param bonded_port_id	Port ID of bonded device.
	* @return
	*	0 on success, negative value otherwise
	*/
int
rte_eth_bond_mac_address_reset(uint8_t bonded_port_id);


/**
	* Set the transmit policy for bonded device to use when it is operating in
	* balance mode, this parameter is otherwise ignored in other modes of
	* operation.
	* @param bonded_port_id	Port ID of bonded device.
	* @param policy			Balance mode transmission policy.
	* @return
	*	0 on success, negative value otherwise.
	*/
int
rte_eth_bond_xmit_policy_set(uint8_t bonded_port_id, uint8_t policy);


/**
	* Get the transmit policy set on bonded device for balance mode operation
	* @param bonded_port_id	Port ID of bonded device.
	* @return
	*	Balance transmit policy on success, negative value otherwise.
	*/
int
rte_eth_bond_xmit_policy_get(uint8_t bonded_port_id);


/**
	* Set the link monitoring frequency (in ms) for monitoring the link status of
	* slave devices
	* @param bonded_port_id	Port ID of bonded device.
	* @param internal_ms		Monitoring interval in milliseconds
	* @return
	*	0 on success, negative value otherwise.
	*/
int
rte_eth_bond_link_monitoring_set(uint8_t bonded_port_id, uint32_t internal_ms);


/**
	* Get the current link monitoring frequency (in ms) for monitoring of the link
	* status of slave devices
	* @param bonded_port_id	Port ID of bonded device.
	* @return
	*	Monitoring interval on success, negative value otherwise.
	*/
int
rte_eth_bond_link_monitoring_get(uint8_t bonded_port_id);


/**
	* Set the period in milliseconds for delaying the disabling of a bonded link
	* when the link down status has been detected
	* @param bonded_port_id	Port ID of bonded device.
	* @param delay_ms			Delay period in milliseconds.
	* @return
	*  0 on success, negative value otherwise.
	*/
int
rte_eth_bond_link_down_prop_delay_set(uint8_t bonded_port_id, uint32_t delay_ms);


/**
	* Get the period in milliseconds set for delaying the disabling of a bonded
	* link when the link down status has been detected
	* @param bonded_port_id	Port ID of bonded device.
	* @return
	*  Delay period on success, negative value otherwise.
	*/
int
rte_eth_bond_link_down_prop_delay_get(uint8_t bonded_port_id);


/**
	* Set the period in milliseconds for delaying the enabling of a bonded link
	* when the link up status has been detected
	* @param bonded_port_id	Port ID of bonded device.
	* @param delay_ms			Delay period in milliseconds.
	* @return
	*  0 on success, negative value otherwise.
	*/
int
rte_eth_bond_link_up_prop_delay_set(uint8_t bonded_port_id, uint32_t delay_ms);


/**
	* Get the period in milliseconds set for delaying the enabling of a bonded
	* link when the link up status has been detected
	* @param bonded_port_id	Port ID of bonded device.
	* @return
	*  Delay period on success, negative value otherwise.
	*/
int
rte_eth_bond_link_up_prop_delay_get(uint8_t bonded_port_id);
//#include <rte_eth_bond_8023ad.h>  Out of memory, Illegal Instruction
//#include <rte_eth_ctrl.h>  Out of memory, Illegal Instruction


/*-
	*/
int eth_dev_null_create(const char *name, const unsigned numa_node,
		unsigned packet_size, unsigned packet_copy);


/*-
	*/


/*-
	*/


/*
	* Derived from FreeBSD's bufring.h
	**************************************************************************
	* Copyright (c) 2007-2009 Kip Macy kmacy@freebsd.org
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* 1. Redistributions of source code must retain the above copyright notice,
	* 2. The name of Kip Macy nor the names of other
	* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
	* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	* POSSIBILITY OF SUCH DAMAGE.
	***************************************************************************/


/**
	* Create a new ethdev port from a set of rings
	* @param name
	* @param rx_queues
	* @param nb_rx_queues
	* @param tx_queues
	* @param nb_tx_queues
	* @param numa_node
	* @return
	*/
int rte_eth_from_rings(const char *name,
		struct rte_ring * const rx_queues[],
		const unsigned nb_rx_queues,
		struct rte_ring *const tx_queues[],
		const unsigned nb_tx_queues,
		const unsigned numa_node);


/**
	* Create a new ethdev port from a ring
	* This function is a shortcut call for rte_eth_from_rings for the
	* case where one wants to take a single rte_ring and use it as though
	* it were an ethdev
	* @param ring
	* @return
	*/
int rte_eth_from_ring(struct rte_ring *r);


/*-
	*/


/*-
	*/


/**
	* @file
	* Interface to vhost net
	*/


/*-
	*/


/*-
	*/


/*-
	*/



enum {VIRTIO_RXQ, VIRTIO_TXQ, VIRTIO_QNUM};


/**
	* Device and vring operations.
	* Make sure to set VIRTIO_DEV_RUNNING to the device flags in new_device and
	* remove it in destroy_device.
	*/
struct virtio_net_device_ops
{
	int (*new_device)(int vid); 


	void (*destroy_device)(int vid); 


	int (*vring_state_changed)(int vid, uint16_t queue_id, int enable); 


	void *reserved[5]; 


};


/**
	*  Disable features in feature_mask. Returns 0 on success.
	*/
int rte_vhost_feature_disable(uint64_t feature_mask);


/**
	*  Enable features in feature_mask. Returns 0 on success.
	*/
int rte_vhost_feature_enable(uint64_t feature_mask);



uint64_t rte_vhost_feature_get(void);
int rte_vhost_enable_guest_notification(int vid, uint16_t queue_id, int enable);


/**
	* Register vhost driver. path could be different for multiple
	* instance support.
	*/
int rte_vhost_driver_register(const char *path, uint64_t flags);



int rte_vhost_driver_unregister(const char *path);



int rte_vhost_driver_callback_register(struct virtio_net_device_ops const * const);



int rte_vhost_driver_session_start(void);


/**
	* Get the numa node from which the virtio net device's memory
	* is allocated.
	* @param vid
	*  virtio-net device ID
	* @return
	*  The numa node, -1 on failure
	*/
int rte_vhost_get_numa_node(int vid);


/**
	* Get the number of queues the device supports.
	* @param vid
	*  virtio-net device ID
	* @return
	*  The number of queues, 0 on failure
	*/
uint32_t rte_vhost_get_queue_num(int vid);


/**
	* Get the virtio net device's ifname. For vhost-cuse, ifname is the
	* path of the char device. For vhost-user, ifname is the vhost-user
	* socket file path.
	* @param vid
	*  virtio-net device ID
	* @param buf
	*  The buffer to stored the queried ifname
	* @param len
	*  The length of buf
	* @return
	*  0 on success, -1 on failure
	*/
int rte_vhost_get_ifname(int vid, char *buf, size_t len);


/**
	* Get how many avail entries are left in the queue
	* @param vid
	*  virtio-net device ID
	* @param queue_id
	*  virtio queue index
	* @return
	*  num of avail entires left
	*/
uint16_t rte_vhost_avail_entries(int vid, uint16_t queue_id);


/**
	* This function adds buffers to the virtio devices RX virtqueue. Buffers can
	* be received from the physical port or from another virtual device. A packet
	* count is returned to indicate the number of packets that were succesfully
	* added to the RX queue.
	* @param vid
	*  virtio-net device ID
	* @param queue_id
	*  virtio queue index in mq case
	* @param pkts
	*  array to contain packets to be enqueued
	* @param count
	*  packets num to be enqueued
	* @return
	*  num of packets enqueued
	*/
uint16_t rte_vhost_enqueue_burst(int vid, uint16_t queue_id,
	struct rte_mbuf **pkts, uint16_t count);


/**
	* This function gets guest buffers from the virtio device TX virtqueue,
	* construct host mbufs, copies guest buffer content to host mbufs and
	* store them in pkts to be processed.
	* @param vid
	*  virtio-net device
	* @param queue_id
	*  virtio queue index in mq case
	* @param mbuf_pool
	*  mbuf_pool where host mbuf is allocated.
	* @param pkts
	*  array to contain packets to be dequeued
	* @param count
	*  packets num to be dequeued
	* @return
	*  num of packets dequeued
	*/
uint16_t rte_vhost_dequeue_burst(int vid, uint16_t queue_id,
	struct rte_mempool *mbuf_pool, struct rte_mbuf **pkts, uint16_t count);


/**
	* Disable features in feature_mask.
	* @param feature_mask
	*  Vhost features defined in "linux/virtio_net.h".
	* @return
	*  - On success, zero.
	*  - On failure, a negative value.
	*/
int rte_eth_vhost_feature_disable(uint64_t feature_mask);


/**
	* Enable features in feature_mask.
	* @param feature_mask
	*  Vhost features defined in "linux/virtio_net.h".
	* @return
	*  - On success, zero.
	*  - On failure, a negative value.
	*/
int rte_eth_vhost_feature_enable(uint64_t feature_mask);


/**
	* Returns currently supported vhost features.
	* @return
	*  Vhost features defined in "linux/virtio_net.h".
	*/
uint64_t rte_eth_vhost_feature_get(void);


/*
	* Event description.
	*/
struct rte_eth_vhost_queue_event
{
	uint16_t queue_id;
	bool rx;
	bool enable;
};


/**
	* Get queue events from specified port.
	* If a callback for below event is registered by
	* rte_eth_dev_callback_register(), this function will describe what was
	* changed.
	*  - RTE_ETH_EVENT_QUEUE_STATE
	* Multiple events may cause only one callback kicking, so call this function
	* while returning 0.
	* @param port_id
	*  Port id.
	* @param event
	*  Pointer to a rte_eth_vhost_queue_event structure.
	* @return
	*  - On success, zero.
	*  - On failure, a negative value.
	*/
int rte_eth_vhost_get_queue_event(uint8_t port_id,
		struct rte_eth_vhost_queue_event *event);
//#include <rte_ethdev.h>  Out of memory, Illegal Instruction - ? use of rte_pci.h
// This file is based on rte_ethdev.h from DPDK 16.07, but with alterations so that bindgen can parse it


/*-
	*/


/**
	* @file
	* RTE Ethernet Device API
	* The Ethernet Device API is composed of two parts:
	* - The application-oriented Ethernet API that includes functions to setup
	* - The driver-oriented Ethernet API that exports a function allowing
	* By default, all the functions of the Ethernet Device API exported by a PMD
	* are lock-free functions which assume to not be invoked in parallel on
	* different logical cores to work on the same target object.  For instance,
	* the receive function of a PMD cannot be invoked in parallel on two logical
	* cores to poll the same RX queue [of the same port]. Of course, this function
	* can be invoked in parallel by different logical cores on different RX queues.
	* It is the responsibility of the upper level application to enforce this rule.
	* If needed, parallel accesses by multiple logical cores to shared queues
	* shall be explicitly protected by dedicated inline lock-aware functions
	* built on top of their corresponding lock-free functions of the PMD API.
	* In all functions of the Ethernet API, the Ethernet device is
	* designated by an integer >= 0 named the device port identifier.
	* At the Ethernet driver level, Ethernet devices are represented by a generic
	* data structure of type *rte_eth_dev*.
	* Ethernet devices are dynamically registered during the PCI probing phase
	* performed at EAL initialization time.
	* When an Ethernet device is being probed, an *rte_eth_dev* structure and
	* a new port identifier are allocated for that device. Then, the eth_dev_init()
	* function supplied by the Ethernet driver matching the probed PCI
	* device is invoked to properly initialize the device.
	* The role of the device init function consists of resetting the hardware,
	* checking access to Non-volatile Memory (NVM), reading the MAC address
	* from NVM etc.
	* If the device init operation is successful, the correspondence between
	* the port identifier assigned to the new device and its associated
	* *rte_eth_dev* structure is effectively registered.
	* Otherwise, both the *rte_eth_dev* structure and the port identifier are
	* freed.
	* The functions exported by the application Ethernet API to setup a device
	* designated by its port identifier must be invoked in the following order:
	* Then, the network application can invoke, in any order, the functions
	* exported by the Ethernet API to get the MAC address of a given device, to
	* get the speed and the status of a device physical link, to receive/transmit
	* [burst of] packets, and so on.
	* If the application wants to change the configuration (i.e. call
	* rte_eth_dev_configure(), rte_eth_tx_queue_setup(), or
	* rte_eth_rx_queue_setup()), it must call rte_eth_dev_stop() first to stop the
	* device and then do the reconfiguration before calling rte_eth_dev_start()
	* again. The transmit and receive functions should not be invoked when the
	* device is stopped.
	* Please note that some configuration is not stored between calls to
	* rte_eth_dev_stop()/rte_eth_dev_start(). The following configuration will
	* be retained:
	* Any other configuration will not be stored and will need to be re-entered
	* after a call to rte_eth_dev_start().
	* Finally, a network application can close an Ethernet device by invoking the
	* rte_eth_dev_close() function.
	* Each function of the application Ethernet API invokes a specific function
	* of the PMD that controls the target device designated by its port
	* identifier.
	* For this purpose, all device-specific functions of an Ethernet driver are
	* supplied through a set of pointers contained in a generic structure of type
	* *eth_dev_ops*.
	* The address of the *eth_dev_ops* structure is stored in the *rte_eth_dev*
	* structure by the device init function of the Ethernet driver, which is
	* invoked during the PCI probing phase, as explained earlier.
	* In other words, each function of the Ethernet API simply retrieves the
	* *rte_eth_dev* structure associated with the device port identifier and
	* performs an indirect invocation of the corresponding driver function
	* supplied in the *eth_dev_ops* structure of the *rte_eth_dev* structure.
	* For performance reasons, the address of the burst-oriented RX and TX
	* functions of the Ethernet driver are not contained in the *eth_dev_ops*
	* structure. Instead, they are directly stored at the beginning of the
	* *rte_eth_dev* structure to avoid an extra indirect memory access during
	* their invocation.
	* RTE ethernet device drivers do not use interrupts for transmitting or
	* receiving. Instead, Ethernet drivers export Poll-Mode receive and transmit
	* functions to applications.
	* Both receive and transmit functions are packet-burst oriented to minimize
	* their cost per packet through the following optimizations:
	* - Sharing among multiple packets the incompressible cost of the
	* - Enabling receive/transmit functions to take advantage of burst-oriented
	* The burst-oriented receive function does not provide any error notification,
	* to avoid the corresponding overhead. As a hint, the upper-level application
	* might check the status of the device link once being systematically returned
	* a 0 value by the receive function of the driver for a given number of tries.
	*/


/*-
	*/



// #include <rte_log.h>
// #include <rte_interrupts.h>
// #include <rte_pci.h>
// #include <rte_devargs.h>
// #include "rte_ether.h"
// #include "rte_eth_ctrl.h"
// #include "rte_dev_info.h"


/*-
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* Ethernet device features and related data structures used
	* by control APIs should be defined in this file.
	*/


/*
	* A packet can be identified by hardware as different flow types. Different
	* NIC hardwares may support different flow types.
	* Basically, the NIC hardware identifies the flow type as deep protocol as
	* possible, and exclusively. For example, if a packet is identified as
	* 'RTE_ETH_FLOW_NONFRAG_IPV4_TCP', it will not be any of other flow types,
	* though it is an actual IPV4 packet.
	* Note that the flow types are used to define RSS offload types in
	* rte_ethdev.h.
	*/




/**
	* Feature filter types
	*/
enum rte_filter_type
{
	RTE_ETH_FILTER_NONE = 0,
	RTE_ETH_FILTER_MACVLAN,
	RTE_ETH_FILTER_ETHERTYPE,
	RTE_ETH_FILTER_FLEXIBLE,
	RTE_ETH_FILTER_SYN,
	RTE_ETH_FILTER_NTUPLE,
	RTE_ETH_FILTER_TUNNEL,
	RTE_ETH_FILTER_FDIR,
	RTE_ETH_FILTER_HASH,
	RTE_ETH_FILTER_L2_TUNNEL,
	RTE_ETH_FILTER_MAX
};


/**
	* Generic operations on filters
	*/
enum rte_filter_op
{


	RTE_ETH_FILTER_NOP = 0,
	RTE_ETH_FILTER_ADD, 


	RTE_ETH_FILTER_UPDATE, 


	RTE_ETH_FILTER_DELETE, 


	RTE_ETH_FILTER_FLUSH, 


	RTE_ETH_FILTER_GET, 


	RTE_ETH_FILTER_SET, 


	RTE_ETH_FILTER_INFO, 


	RTE_ETH_FILTER_STATS, 


	RTE_ETH_FILTER_OP_MAX
};


/**
	* MAC filter type
	*/
enum rte_mac_filter_type
{
	RTE_MAC_PERFECT_MATCH = 1, 


	RTE_MACVLAN_PERFECT_MATCH, 


	RTE_MAC_HASH_MATCH, 




	RTE_MACVLAN_HASH_MATCH,
};


/**
	* MAC filter info
	*/
struct rte_eth_mac_filter
{
	uint8_t is_vf; 


	uint16_t dst_id; 


	enum rte_mac_filter_type filter_type; 


	struct ether_addr mac_addr;
};


/**
	* Define all structures for Ethertype Filter type.
	*/


/**
	* A structure used to define the ethertype filter entry
	* to support RTE_ETH_FILTER_ETHERTYPE with RTE_ETH_FILTER_ADD,
	* RTE_ETH_FILTER_DELETE and RTE_ETH_FILTER_GET operations.
	*/
struct rte_eth_ethertype_filter
{
	struct ether_addr mac_addr; 


	uint16_t ether_type; 


	uint16_t flags; 


	uint16_t queue; 


};




/**
	*  A structure used to define the flex filter entry
	*  to support RTE_ETH_FILTER_FLEXIBLE with RTE_ETH_FILTER_ADD,
	*  RTE_ETH_FILTER_DELETE and RTE_ETH_FILTER_GET operations.
	*/
struct rte_eth_flex_filter
{
	uint16_t len;
	uint8_t bytes[128]; 


	uint8_t mask[((__typeof__(((128) + ((__typeof__(128)) (CHAR_BIT) - 1))))((((128) + ((__typeof__(128)) (CHAR_BIT) - 1))) & (~((__typeof__(((128) + ((__typeof__(128)) (CHAR_BIT) - 1))))((CHAR_BIT) - 1)))) / CHAR_BIT)]; 

/**< if mask bit is 1b, do
					not compare corresponding byte. */
	uint8_t priority;
	uint16_t queue; 


};


/**
	* A structure used to define the TCP syn filter entry
	* to support RTE_ETH_FILTER_SYN with RTE_ETH_FILTER_ADD,
	* RTE_ETH_FILTER_DELETE and RTE_ETH_FILTER_GET operations.
	*/
struct rte_eth_syn_filter
{
	uint8_t hig_pri; 

/**< 1 - higher priority than other filters,
				  0 - lower priority. */
	uint16_t queue; 


};


/**
	* Define all structures for ntuple Filter type.
	*/


/**
	* A structure used to define the ntuple filter entry
	* to support RTE_ETH_FILTER_NTUPLE with RTE_ETH_FILTER_ADD,
	* RTE_ETH_FILTER_DELETE and RTE_ETH_FILTER_GET operations.
	*/
struct rte_eth_ntuple_filter
{
	uint16_t flags; 


	uint32_t dst_ip; 


	uint32_t dst_ip_mask; 


	uint32_t src_ip; 


	uint32_t src_ip_mask; 


	uint16_t dst_port; 


	uint16_t dst_port_mask; 


	uint16_t src_port; 


	uint16_t src_port_mask; 


	uint8_t proto; 


	uint8_t proto_mask; 



/** tcp_flags only meaningful when the proto is TCP.
	    The packet matched above ntuple fields and contain
	    any set bit in tcp_flags will hit this filter. */
	uint8_t tcp_flags;
	uint16_t priority; 

/**< seven levels (001b-111b), 111b is highest,
				      used when more than one filter matches. */
	uint16_t queue; 


};


/**
	* Tunneled type.
	*/
enum rte_eth_tunnel_type
{
	RTE_TUNNEL_TYPE_NONE = 0,
	RTE_TUNNEL_TYPE_VXLAN,
	RTE_TUNNEL_TYPE_GENEVE,
	RTE_TUNNEL_TYPE_TEREDO,
	RTE_TUNNEL_TYPE_NVGRE,
	RTE_TUNNEL_TYPE_IP_IN_GRE,
	RTE_L2_TUNNEL_TYPE_E_TAG,
	RTE_TUNNEL_TYPE_MAX,
};


/**
	* filter type of tunneling packet
	*/


/**
	*  Select IPv4 or IPv6 for tunnel filters.
	*/
enum rte_tunnel_iptype
{
	RTE_TUNNEL_IPTYPE_IPV4 = 0, 


	RTE_TUNNEL_IPTYPE_IPV6, 


};


/**
	* Tunneling Packet filter configuration.
	*/
struct rte_eth_tunnel_filter_conf
{
	struct ether_addr outer_mac; 


	struct ether_addr inner_mac; 


	uint16_t inner_vlan; 


	enum rte_tunnel_iptype ip_type; 



/** Outer destination IP address to match if ETH_TUNNEL_FILTER_OIP
	    is set in filter_type, or inner destination IP address to match
	    if ETH_TUNNEL_FILTER_IIP is set in filter_type . */
	union
{
		uint32_t ipv4_addr; 


		uint32_t ipv6_addr[4]; 


	} ip_addr;


	uint16_t filter_type;
	enum rte_eth_tunnel_type tunnel_type; 


	uint32_t tenant_id; 


	uint16_t queue_id; 


};


/**
	* Global eth device configuration type.
	*/
enum rte_eth_global_cfg_type
{
	RTE_ETH_GLOBAL_CFG_TYPE_UNKNOWN = 0,
	RTE_ETH_GLOBAL_CFG_TYPE_GRE_KEY_LEN,
	RTE_ETH_GLOBAL_CFG_TYPE_MAX,
};


/**
	* Global eth device configuration.
	*/
struct rte_eth_global_cfg
{
	enum rte_eth_global_cfg_type cfg_type; 


	union
{
		uint8_t gre_key_len; 


		uint64_t reserved; 


	} cfg;
};


/**
	* Input set fields for Flow Director and Hash filters
	*/
enum rte_eth_input_set_field
{
	RTE_ETH_INPUT_SET_UNKNOWN = 0,


	RTE_ETH_INPUT_SET_L2_SRC_MAC = 1,
	RTE_ETH_INPUT_SET_L2_DST_MAC,
	RTE_ETH_INPUT_SET_L2_OUTER_VLAN,
	RTE_ETH_INPUT_SET_L2_INNER_VLAN,
	RTE_ETH_INPUT_SET_L2_ETHERTYPE,


	RTE_ETH_INPUT_SET_L3_SRC_IP4 = 129,
	RTE_ETH_INPUT_SET_L3_DST_IP4,
	RTE_ETH_INPUT_SET_L3_SRC_IP6,
	RTE_ETH_INPUT_SET_L3_DST_IP6,
	RTE_ETH_INPUT_SET_L3_IP4_TOS,
	RTE_ETH_INPUT_SET_L3_IP4_PROTO,
	RTE_ETH_INPUT_SET_L3_IP6_TC,
	RTE_ETH_INPUT_SET_L3_IP6_NEXT_HEADER,
	RTE_ETH_INPUT_SET_L3_IP4_TTL,
	RTE_ETH_INPUT_SET_L3_IP6_HOP_LIMITS,


	RTE_ETH_INPUT_SET_L4_UDP_SRC_PORT = 257,
	RTE_ETH_INPUT_SET_L4_UDP_DST_PORT,
	RTE_ETH_INPUT_SET_L4_TCP_SRC_PORT,
	RTE_ETH_INPUT_SET_L4_TCP_DST_PORT,
	RTE_ETH_INPUT_SET_L4_SCTP_SRC_PORT,
	RTE_ETH_INPUT_SET_L4_SCTP_DST_PORT,
	RTE_ETH_INPUT_SET_L4_SCTP_VERIFICATION_TAG,


	RTE_ETH_INPUT_SET_TUNNEL_L2_INNER_DST_MAC = 385,
	RTE_ETH_INPUT_SET_TUNNEL_L2_INNER_SRC_MAC,
	RTE_ETH_INPUT_SET_TUNNEL_L2_INNER_VLAN,
	RTE_ETH_INPUT_SET_TUNNEL_L4_UDP_KEY,
	RTE_ETH_INPUT_SET_TUNNEL_GRE_KEY,


	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_1ST_WORD = 641,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_2ND_WORD,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_3RD_WORD,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_4TH_WORD,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_5TH_WORD,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_6TH_WORD,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_7TH_WORD,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_8TH_WORD,
	RTE_ETH_INPUT_SET_DEFAULT = 65533,
	RTE_ETH_INPUT_SET_NONE = 65534,
	RTE_ETH_INPUT_SET_MAX = 65535,
};


/**
	* Filters input set operations
	*/
enum rte_filter_input_set_op
{
	RTE_ETH_INPUT_SET_OP_UNKNOWN,
	RTE_ETH_INPUT_SET_SELECT, 


	RTE_ETH_INPUT_SET_ADD, 


	RTE_ETH_INPUT_SET_OP_MAX
};


/**
	* A structure used to define the input set configuration for
	* flow director and hash filters
	*/
struct rte_eth_input_set_conf
{
	uint16_t flow_type;
	uint16_t inset_size;
	enum rte_eth_input_set_field field[128];
	enum rte_filter_input_set_op op;
};


/**
	* A structure used to define the input for L2 flow
	*/
struct rte_eth_l2_flow
{
	uint16_t ether_type; 


};


/**
	* A structure used to define the input for IPV4 flow
	*/
struct rte_eth_ipv4_flow
{
	uint32_t src_ip; 


	uint32_t dst_ip; 


	uint8_t tos; 


	uint8_t ttl; 


	uint8_t proto; 


};


/**
	* A structure used to define the input for IPV4 UDP flow
	*/
struct rte_eth_udpv4_flow
{
	struct rte_eth_ipv4_flow ip; 


	uint16_t src_port; 


	uint16_t dst_port; 


};


/**
	* A structure used to define the input for IPV4 TCP flow
	*/
struct rte_eth_tcpv4_flow
{
	struct rte_eth_ipv4_flow ip; 


	uint16_t src_port; 


	uint16_t dst_port; 


};


/**
	* A structure used to define the input for IPV4 SCTP flow
	*/
struct rte_eth_sctpv4_flow
{
	struct rte_eth_ipv4_flow ip; 


	uint16_t src_port; 


	uint16_t dst_port; 


	uint32_t verify_tag; 


};


/**
	* A structure used to define the input for IPV6 flow
	*/
struct rte_eth_ipv6_flow
{
	uint32_t src_ip[4]; 


	uint32_t dst_ip[4]; 


	uint8_t tc; 


	uint8_t proto; 


	uint8_t hop_limits; 


};


/**
	* A structure used to define the input for IPV6 UDP flow
	*/
struct rte_eth_udpv6_flow
{
	struct rte_eth_ipv6_flow ip; 


	uint16_t src_port; 


	uint16_t dst_port; 


};


/**
	* A structure used to define the input for IPV6 TCP flow
	*/
struct rte_eth_tcpv6_flow
{
	struct rte_eth_ipv6_flow ip; 


	uint16_t src_port; 


	uint16_t dst_port; 


};


/**
	* A structure used to define the input for IPV6 SCTP flow
	*/
struct rte_eth_sctpv6_flow
{
	struct rte_eth_ipv6_flow ip; 


	uint16_t src_port; 


	uint16_t dst_port; 


	uint32_t verify_tag; 


};


/**
	* A structure used to define the input for MAC VLAN flow
	*/
struct rte_eth_mac_vlan_flow
{
	struct ether_addr mac_addr; 


};


/**
	* Tunnel type for flow director.
	*/
enum rte_eth_fdir_tunnel_type
{
	RTE_FDIR_TUNNEL_TYPE_UNKNOWN = 0,
	RTE_FDIR_TUNNEL_TYPE_NVGRE,
	RTE_FDIR_TUNNEL_TYPE_VXLAN,
};


/**
	* A structure used to define the input for tunnel flow, now it's VxLAN or
	* NVGRE
	*/
struct rte_eth_tunnel_flow
{
	enum rte_eth_fdir_tunnel_type tunnel_type; 




	uint32_t tunnel_id;
	struct ether_addr mac_addr; 


};


/**
	* An union contains the inputs for all types of flow
	* Items in flows need to be in big endian
	*/
union rte_eth_fdir_flow
{
	struct rte_eth_l2_flow l2_flow;
	struct rte_eth_udpv4_flow udp4_flow;
	struct rte_eth_tcpv4_flow tcp4_flow;
	struct rte_eth_sctpv4_flow sctp4_flow;
	struct rte_eth_ipv4_flow ip4_flow;
	struct rte_eth_udpv6_flow udp6_flow;
	struct rte_eth_tcpv6_flow tcp6_flow;
	struct rte_eth_sctpv6_flow sctp6_flow;
	struct rte_eth_ipv6_flow ipv6_flow;
	struct rte_eth_mac_vlan_flow mac_vlan_flow;
	struct rte_eth_tunnel_flow tunnel_flow;
};


/**
	* A structure used to contain extend input of flow
	*/
struct rte_eth_fdir_flow_ext
{
	uint16_t vlan_tci;
	uint8_t flexbytes[16];


	uint8_t is_vf; 


	uint16_t dst_id; 


};


/**
	* A structure used to define the input for a flow director filter entry
	*/
struct rte_eth_fdir_input
{
	uint16_t flow_type;
	union rte_eth_fdir_flow flow;


	struct rte_eth_fdir_flow_ext flow_ext;


};


/**
	* Behavior will be taken if FDIR match
	*/
enum rte_eth_fdir_behavior
{
	RTE_ETH_FDIR_ACCEPT = 0,
	RTE_ETH_FDIR_REJECT,
	RTE_ETH_FDIR_PASSTHRU,
};


/**
	* Flow director report status
	* It defines what will be reported if FDIR entry is matched.
	*/
enum rte_eth_fdir_status
{
	RTE_ETH_FDIR_NO_REPORT_STATUS = 0, 


	RTE_ETH_FDIR_REPORT_ID, 


	RTE_ETH_FDIR_REPORT_ID_FLEX_4, 


	RTE_ETH_FDIR_REPORT_FLEX_8, 


};


/**
	* A structure used to define an action when match FDIR packet filter.
	*/
struct rte_eth_fdir_action
{
	uint16_t rx_queue; 


	enum rte_eth_fdir_behavior behavior; 


	enum rte_eth_fdir_status report_status; 


	uint8_t flex_off;

/**< If report_status is RTE_ETH_FDIR_REPORT_ID_FLEX_4 or
	     RTE_ETH_FDIR_REPORT_FLEX_8, flex_off specifies where the reported
	     flex bytes start from in flexible payload. */
};


/**
	* A structure used to define the flow director filter entry by filter_ctrl API
	* It supports RTE_ETH_FILTER_FDIR with RTE_ETH_FILTER_ADD and
	* RTE_ETH_FILTER_DELETE operations.
	*/
struct rte_eth_fdir_filter
{
	uint32_t soft_id;


	struct rte_eth_fdir_input input; 


	struct rte_eth_fdir_action action; 


};


/**
	*  A structure used to configure FDIR masks that are used by the device
	*  to match the various fields of RX packet headers.
	*/
struct rte_eth_fdir_masks
{
	uint16_t vlan_tci_mask; 




	struct rte_eth_ipv4_flow ipv4_mask;


	struct rte_eth_ipv6_flow ipv6_mask;


	uint16_t src_port_mask;


	uint16_t dst_port_mask;

/** 6 bit mask for proper 6 bytes of Mac address, bit 0 matches the
	    first byte on the wire */
	uint8_t mac_addr_byte_mask;


	uint32_t tunnel_id_mask;
	uint8_t tunnel_type_mask; 

/**< 1 - Match tunnel type,
				       0 - Ignore tunnel type. */
};


/**
	* Payload type
	*/
enum rte_eth_payload_type
{
	RTE_ETH_PAYLOAD_UNKNOWN = 0,
	RTE_ETH_RAW_PAYLOAD,
	RTE_ETH_L2_PAYLOAD,
	RTE_ETH_L3_PAYLOAD,
	RTE_ETH_L4_PAYLOAD,
	RTE_ETH_PAYLOAD_MAX = 8,
};


/**
	* A structure used to select bytes extracted from the protocol layers to
	* flexible payload for filter
	*/
struct rte_eth_flex_payload_cfg
{
	enum rte_eth_payload_type type; 


	uint16_t src_offset[16];

/**< Offset in bytes from the beginning of packet's payload
	     src_offset[i] indicates the flexbyte i's offset in original
	     packet payload. This value should be less than
	     flex_payload_limit in struct rte_eth_fdir_info.*/
};


/**
	* A structure used to define FDIR masks for flexible payload
	* for each flow type
	*/
struct rte_eth_fdir_flex_mask
{
	uint16_t flow_type;
	uint8_t mask[16];


};


/**
	* A structure used to define all flexible payload related setting
	* include flex payload and flex mask
	*/
struct rte_eth_fdir_flex_conf
{
	uint16_t nb_payloads; 


	uint16_t nb_flexmasks; 


	struct rte_eth_flex_payload_cfg flex_set[RTE_ETH_PAYLOAD_MAX];


	struct rte_eth_fdir_flex_mask flex_mask[22];


};


/**
	*  Flow Director setting modes: none, signature or perfect.
	*/
enum rte_fdir_mode
{
	RTE_FDIR_MODE_NONE = 0, 


	RTE_FDIR_MODE_SIGNATURE, 


	RTE_FDIR_MODE_PERFECT, 


	RTE_FDIR_MODE_PERFECT_MAC_VLAN, 


	RTE_FDIR_MODE_PERFECT_TUNNEL, 


};


/**
	* A structure used to get the information of flow director filter.
	* It supports RTE_ETH_FILTER_FDIR with RTE_ETH_FILTER_INFO operation.
	* It includes the mode, flexible payload configuration information,
	* capabilities and supported flow types, flexible payload characters.
	* It can be gotten to help taking specific configurations per device.
	*/
struct rte_eth_fdir_info
{
	enum rte_fdir_mode mode; 


	struct rte_eth_fdir_masks mask;


	struct rte_eth_fdir_flex_conf flex_conf;
	uint32_t guarant_spc; 


	uint32_t best_spc; 




	uint32_t flow_types_mask[((__typeof__(((22) + ((__typeof__(22)) ((CHAR_BIT * sizeof(uint32_t))) - 1))))((((22) + ((__typeof__(22)) ((CHAR_BIT * sizeof(uint32_t))) - 1))) & (~((__typeof__(((22) + ((__typeof__(22)) ((CHAR_BIT * sizeof(uint32_t))) - 1))))(((CHAR_BIT * sizeof(uint32_t))) - 1))))/(CHAR_BIT * sizeof(uint32_t)))];
	uint32_t max_flexpayload; 



/** Flexible payload unit in bytes. Size and alignments of all flex
	    payload segments should be multiplies of this value. */
	uint32_t flex_payload_unit;

/** Max number of flexible payload continuous segments.
	    Each segment should be a multiple of flex_payload_unit.*/
	uint32_t max_flex_payload_segment_num;

/** Maximum src_offset in bytes allowed. It indicates that
	    src_offset[i] in struct rte_eth_flex_payload_cfg should be less
	    than this value. */
	uint16_t flex_payload_limit;

/** Flex bitmask unit in bytes. Size of flex bitmasks should be a
	    multiply of this value. */
	uint32_t flex_bitmask_unit;


	uint32_t max_flex_bitmask_num;
};


/**
	* A structure used to define the statistics of flow director.
	* It supports RTE_ETH_FILTER_FDIR with RTE_ETH_FILTER_STATS operation.
	*/
struct rte_eth_fdir_stats
{
	uint32_t collision; 


	uint32_t free; 


	uint32_t maxhash;

/**< The lookup hash value of the added filter that updated the value
	   of the MAXLEN field */
	uint32_t maxlen; 


	uint64_t add; 


	uint64_t remove; 


	uint64_t f_add; 


	uint64_t f_remove; 


	uint32_t guarant_cnt; 


	uint32_t best_cnt; 


};


/**
	* Flow Director filter information types.
	*/
enum rte_eth_fdir_filter_info_type
{
	RTE_ETH_FDIR_FILTER_INFO_TYPE_UNKNOWN = 0,


	RTE_ETH_FDIR_FILTER_INPUT_SET_SELECT,
	RTE_ETH_FDIR_FILTER_INFO_TYPE_MAX,
};


/**
	* A structure used to set FDIR filter information, to support filter type
	* of 'RTE_ETH_FILTER_FDIR' RTE_ETH_FDIR_FILTER_INPUT_SET_SELECT operation.
	*/
struct rte_eth_fdir_filter_info
{
	enum rte_eth_fdir_filter_info_type info_type; 




	union
{


		struct rte_eth_input_set_conf input_set_conf;
	} info;
};


/**
	* Hash filter information types.
	* - RTE_ETH_HASH_FILTER_SYM_HASH_ENA_PER_PORT is for getting/setting the
	* - RTE_ETH_HASH_FILTER_GLOBAL_CONFIG is for getting/setting the global
	* - RTE_ETH_HASH_FILTER_INPUT_SET_SELECT is for setting the global
	*/
enum rte_eth_hash_filter_info_type
{
	RTE_ETH_HASH_FILTER_INFO_TYPE_UNKNOWN = 0,


	RTE_ETH_HASH_FILTER_SYM_HASH_ENA_PER_PORT,


	RTE_ETH_HASH_FILTER_GLOBAL_CONFIG,


	RTE_ETH_HASH_FILTER_INPUT_SET_SELECT,
	RTE_ETH_HASH_FILTER_INFO_TYPE_MAX,
};


/**
	* Hash function types.
	*/
enum rte_eth_hash_function
{
	RTE_ETH_HASH_FUNCTION_DEFAULT = 0,
	RTE_ETH_HASH_FUNCTION_TOEPLITZ, 


	RTE_ETH_HASH_FUNCTION_SIMPLE_XOR, 


	RTE_ETH_HASH_FUNCTION_MAX,
};


/**
	* A structure used to set or get global hash function configurations which
	* include symmetric hash enable per flow type and hash function type.
	* Each bit in sym_hash_enable_mask[] indicates if the symmetric hash of the
	* corresponding flow type is enabled or not.
	* Each bit in valid_bit_mask[] indicates if the corresponding bit in
	* sym_hash_enable_mask[] is valid or not. For the configurations gotten, it
	* also means if the flow type is supported by hardware or not.
	*/
struct rte_eth_hash_global_conf
{
	enum rte_eth_hash_function hash_func; 




	uint32_t sym_hash_enable_mask[((__typeof__(((22) + ((__typeof__(22)) ((CHAR_BIT * sizeof(uint32_t))) - 1))))((((22) + ((__typeof__(22)) ((CHAR_BIT * sizeof(uint32_t))) - 1))) & (~((__typeof__(((22) + ((__typeof__(22)) ((CHAR_BIT * sizeof(uint32_t))) - 1))))(((CHAR_BIT * sizeof(uint32_t))) - 1))))/(CHAR_BIT * sizeof(uint32_t)))];


	uint32_t valid_bit_mask[((__typeof__(((22) + ((__typeof__(22)) ((CHAR_BIT * sizeof(uint32_t))) - 1))))((((22) + ((__typeof__(22)) ((CHAR_BIT * sizeof(uint32_t))) - 1))) & (~((__typeof__(((22) + ((__typeof__(22)) ((CHAR_BIT * sizeof(uint32_t))) - 1))))(((CHAR_BIT * sizeof(uint32_t))) - 1))))/(CHAR_BIT * sizeof(uint32_t)))];
};


/**
	* A structure used to set or get hash filter information, to support filter
	* type of 'RTE_ETH_FILTER_HASH' and its operations.
	*/
struct rte_eth_hash_filter_info
{
	enum rte_eth_hash_filter_info_type info_type; 




	union
{


		uint8_t enable;


		struct rte_eth_hash_global_conf global_conf;


		struct rte_eth_input_set_conf input_set_conf;
	} info;
};


/**
	* l2 tunnel configuration.
	*/
struct rte_eth_l2_tunnel_conf
{
	enum rte_eth_tunnel_type l2_tunnel_type;
	uint16_t ether_type; 


	uint32_t tunnel_id; 


	uint16_t vf_id; 


	uint32_t pool; 


};


/*-
	*/


/*   BSD LICENSE
	*/


/**
	* @file
	* RTE PCI Interface
	*/


/*
	* Copyright (c) 1991, 1993
	*	The Regents of the University of California.  All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	*	@(#)queue.h	8.5 (Berkeley) 8/20/94
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* The RTE interrupt interface provides functions to register/unregister
	* callbacks for a specific interrupt.
	*/



struct rte_intr_handle;



typedef void (*rte_intr_callback_fn)(struct rte_intr_handle *intr_handle,
						 void *cb_arg);


/*-
	*/
enum rte_intr_handle_type
{
	RTE_INTR_HANDLE_UNKNOWN = 0,
	RTE_INTR_HANDLE_UIO, 


	RTE_INTR_HANDLE_UIO_INTX, 


	RTE_INTR_HANDLE_VFIO_LEGACY, 


	RTE_INTR_HANDLE_VFIO_MSI, 


	RTE_INTR_HANDLE_VFIO_MSIX, 


	RTE_INTR_HANDLE_ALARM, 


	RTE_INTR_HANDLE_EXT, 


	RTE_INTR_HANDLE_MAX
};
typedef void (*rte_intr_event_cb_t)(int fd, void *arg);
struct rte_epoll_data
{
	uint32_t event; 


	void *data; 


	rte_intr_event_cb_t cb_fun; 


	void *cb_arg; 


};
enum
{
	RTE_EPOLL_INVALID = 0,
	RTE_EPOLL_VALID,
	RTE_EPOLL_EXEC,
};



struct rte_epoll_event
{
	volatile uint32_t status; 


	int fd; 


	int epfd; 


	struct rte_epoll_data epdata;
};



struct rte_intr_handle
{

	union
{
		int vfio_dev_fd; 


		int uio_cfg_fd; 

/**< UIO config file descriptor
					for uio_pci_generic */
	};
	int fd; 


	enum rte_intr_handle_type type; 


	uint32_t max_intr; 


	uint32_t nb_efd; 


	int efds[32]; 


	struct rte_epoll_event elist[32];
						     


	int *intr_vec; 


};


/**
	* It waits for events on the epoll instance.
	* @param epfd
	* @param events
	* @param maxevents
	* @param timeout
	* @return
	*/
int
rte_epoll_wait(int epfd, struct rte_epoll_event *events,
						  int maxevents, int timeout);


/**
	* It performs control operations on epoll instance referred by the epfd.
	* It requests that the operation op be performed for the target fd.
	* @param epfd
	* @param op
	* @param fd
	* @param event
	* @return
	*/
int
rte_epoll_ctl(int epfd, int op, int fd,
						 struct rte_epoll_event *event);


/**
	* The function returns the per thread epoll instance.
	* @return
	*/
int
rte_intr_tls_epfd(void);


/**
	* @param intr_handle
	* @param epfd
	* @param op
	* @param vec
	* @param data
	* @return
	*/
int
rte_intr_rx_ctl(struct rte_intr_handle *intr_handle,
		int epfd, int op, unsigned int vec, void *data);


/**
	* It enables the packet I/O interrupt event if it's necessary.
	* It creates event fd for each interrupt vector when MSIX is used,
	* otherwise it multiplexes a single event fd.
	* @param intr_handle
	* @param nb_efd
	* @return
	*/
int
rte_intr_efd_enable(struct rte_intr_handle *intr_handle, uint32_t nb_efd);


/**
	* It disables the packet I/O interrupt event.
	* It deletes registered eventfds and closes the open fds.
	* @param intr_handle
	*/
void
rte_intr_efd_disable(struct rte_intr_handle *intr_handle);


/**
	* The packet I/O interrupt on datapath is enabled or not.
	* @param intr_handle
	*/
int
rte_intr_dp_is_en(struct rte_intr_handle *intr_handle);


/**
	* The interrupt handle instance allows other causes or not.
	* Other causes stand for any none packet I/O interrupts.
	* @param intr_handle
	*/
int
rte_intr_allow_others(struct rte_intr_handle *intr_handle);


/**
	* The multiple interrupt vector capability of interrupt handle instance.
	* It returns zero if no multiple interrupt vector support.
	* @param intr_handle
	*/
int
rte_intr_cap_multiple(struct rte_intr_handle *intr_handle);


/**
	* It registers the callback for the specific interrupt. Multiple
	* callbacks cal be registered at the same time.
	* @param intr_handle
	*  Pointer to the interrupt handle.
	* @param cb
	*  callback address.
	* @param cb_arg
	*  address of parameter for callback.
	* @return
	*  - On success, zero.
	*  - On failure, a negative value.
	*/
int rte_intr_callback_register(struct rte_intr_handle *intr_handle,
				rte_intr_callback_fn cb, void *cb_arg);


/**
	* It unregisters the callback according to the specified interrupt handle.
	* @param intr_handle
	*  pointer to the interrupt handle.
	* @param cb
	*  callback address.
	* @param cb_arg
	*  address of parameter for callback, (void *)-1 means to remove all
	*  registered which has the same callback address.
	* @return
	*  - On success, return the number of callback entities removed.
	*  - On failure, a negative value.
	*/
int rte_intr_callback_unregister(struct rte_intr_handle *intr_handle,
				rte_intr_callback_fn cb, void *cb_arg);


/**
	* It enables the interrupt for the specified handle.
	* @param intr_handle
	*  pointer to the interrupt handle.
	* @return
	*  - On success, zero.
	*  - On failure, a negative value.
	*/
int rte_intr_enable(struct rte_intr_handle *intr_handle);


/**
	* It disables the interrupt for the specified handle.
	* @param intr_handle
	*  pointer to the interrupt handle.
	* @return
	*  - On success, zero.
	*  - On failure, a negative value.
	*/
int rte_intr_disable(struct rte_intr_handle *intr_handle);
struct pci_device_list { struct rte_pci_device *tqh_first; struct rte_pci_device * *tqh_last; }; 


struct pci_driver_list { struct rte_pci_driver *tqh_first; struct rte_pci_driver * *tqh_last; }; 


extern struct pci_driver_list pci_driver_list; 


extern struct pci_device_list pci_device_list; 





const char *pci_get_sysfs_path(void);














/**
	* A structure describing a PCI resource.
	*/
struct rte_pci_resource
{
	uint64_t phys_addr; 


	uint64_t len; 


	void *addr; 


};





/**
	* A structure describing an ID for a PCI driver. Each driver provides a
	* table of these IDs for each device that it supports.
	*/
struct rte_pci_id
{
	uint32_t class_id; 


	uint16_t vendor_id; 


	uint16_t device_id; 


	uint16_t subsystem_vendor_id; 


	uint16_t subsystem_device_id; 


};


/**
	* A structure describing the location of a PCI device.
	*/
struct rte_pci_addr
{
	uint16_t domain; 


	uint8_t bus; 


	uint8_t devid; 


	uint8_t function; 


};
struct rte_devargs;
enum rte_kernel_driver
{
	RTE_KDRV_UNKNOWN = 0,
	RTE_KDRV_IGB_UIO,
	RTE_KDRV_VFIO,
	RTE_KDRV_UIO_GENERIC,
	RTE_KDRV_NIC_UIO,
	RTE_KDRV_NONE,
};


/**
	* A structure describing a PCI device.
	*/
struct rte_pci_device
{
	struct { struct rte_pci_device *tqe_next; struct rte_pci_device * *tqe_prev; } next; 


	struct rte_pci_addr addr; 


	struct rte_pci_id id; 


	struct rte_pci_resource mem_resource[6]; 


	struct rte_intr_handle intr_handle; 


	struct rte_pci_driver *driver; 


	uint16_t max_vfs; 


	int numa_node; 


	struct rte_devargs *devargs; 


	enum rte_kernel_driver kdrv; 


};






struct rte_pci_driver;


/**
	* Initialisation function for the driver called during PCI probing.
	*/
typedef int (pci_devinit_t)(struct rte_pci_driver *, struct rte_pci_device *);


/**
	* Uninitialisation function for the driver called during hotplugging.
	*/
typedef int (pci_devuninit_t)(struct rte_pci_device *);


/**
	* A structure describing a PCI driver.
	*/
struct rte_pci_driver
{
	struct { struct rte_pci_driver *tqe_next; struct rte_pci_driver * *tqe_prev; } next; 


	const char *name; 


	pci_devinit_t *devinit; 


	pci_devuninit_t *devuninit; 


	const struct rte_pci_id *id_table; 


	uint32_t drv_flags; 


};














/**
	* A structure describing a PCI mapping.
	*/
struct pci_map
{
	void *addr;
	char *path;
	uint64_t offset;
	uint64_t size;
	uint64_t phaddr;
};


/**
	* A structure describing a mapped PCI resource.
	* For multi-process we need to reproduce all PCI mappings in secondary
	* processes, so save them in a tailq.
	*/
struct mapped_pci_resource
{
	struct { struct mapped_pci_resource *tqe_next; struct mapped_pci_resource * *tqe_prev; } next;
	struct rte_pci_addr pci_addr;
	char path[PATH_MAX];
	int nb_maps;
	struct pci_map maps[6];
};



struct mapped_pci_res_list { struct mapped_pci_resource *tqh_first; struct mapped_pci_resource * *tqh_last; };





/**
	* Utility function to produce a PCI Bus-Device-Function value
	* given a string representation. Assumes that the BDF is provided without
	* a domain prefix (i.e. domain returned is always 0)
	* @param input
	*	The input string to be parsed. Should have the format XX:XX.X
	* @param dev_addr
	*	The PCI Bus-Device-Function address to be returned. Domain will always be
	*	returned as 0
	* @return
	*  0 on success, negative on error.
	*/
static inline int
eal_parse_pci_BDF(const char *input, struct rte_pci_addr *dev_addr)
{
	dev_addr->domain = 0;
	do { unsigned long val; char *end; errno = 0; val = strtoul((input), &end, 16); if (errno != 0 || end[0] != (':') || val > (UINT8_MAX)) return -EINVAL; (dev_addr->bus) = (__typeof__ (dev_addr->bus))val; (input) = end + 1; } while(0);
	do { unsigned long val; char *end; errno = 0; val = strtoul((input), &end, 16); if (errno != 0 || end[0] != ('.') || val > (UINT8_MAX)) return -EINVAL; (dev_addr->devid) = (__typeof__ (dev_addr->devid))val; (input) = end + 1; } while(0);
	do { unsigned long val; char *end; errno = 0; val = strtoul((input), &end, 16); if (errno != 0 || end[0] != (0) || val > (UINT8_MAX)) return -EINVAL; (dev_addr->function) = (__typeof__ (dev_addr->function))val; (input) = end + 1; } while(0);
	return 0;
}


/**
	* Utility function to produce a PCI Bus-Device-Function value
	* given a string representation. Assumes that the BDF is provided including
	* a domain prefix.
	* @param input
	*	The input string to be parsed. Should have the format XXXX:XX:XX.X
	* @param dev_addr
	*	The PCI Bus-Device-Function address to be returned
	* @return
	*  0 on success, negative on error.
	*/
static inline int
eal_parse_pci_DomBDF(const char *input, struct rte_pci_addr *dev_addr)
{
	do { unsigned long val; char *end; errno = 0; val = strtoul((input), &end, 16); if (errno != 0 || end[0] != (':') || val > (UINT16_MAX)) return -EINVAL; (dev_addr->domain) = (__typeof__ (dev_addr->domain))val; (input) = end + 1; } while(0);
	do { unsigned long val; char *end; errno = 0; val = strtoul((input), &end, 16); if (errno != 0 || end[0] != (':') || val > (UINT8_MAX)) return -EINVAL; (dev_addr->bus) = (__typeof__ (dev_addr->bus))val; (input) = end + 1; } while(0);
	do { unsigned long val; char *end; errno = 0; val = strtoul((input), &end, 16); if (errno != 0 || end[0] != ('.') || val > (UINT8_MAX)) return -EINVAL; (dev_addr->devid) = (__typeof__ (dev_addr->devid))val; (input) = end + 1; } while(0);
	do { unsigned long val; char *end; errno = 0; val = strtoul((input), &end, 16); if (errno != 0 || end[0] != (0) || val > (UINT8_MAX)) return -EINVAL; (dev_addr->function) = (__typeof__ (dev_addr->function))val; (input) = end + 1; } while(0);
	return 0;
}





/**
	* Utility function to compare two PCI device addresses.
	* @param addr
	*	The PCI Bus-Device-Function address to compare
	* @param addr2
	*	The PCI Bus-Device-Function address to compare
	* @return
	*	0 on equal PCI address.
	*	Positive on addr is greater than addr2.
	*	Negative on addr is less than addr2, or error.
	*/
static inline int
rte_eal_compare_pci_addr(const struct rte_pci_addr *addr,
				const struct rte_pci_addr *addr2)
{
	uint64_t dev_addr, dev_addr2;
	if ((addr == NULL) || (addr2 == NULL))
		return -1;
	dev_addr = (addr->domain << 24) | (addr->bus << 16) |
				(addr->devid << 8) | addr->function;
	dev_addr2 = (addr2->domain << 24) | (addr2->bus << 16) |
				(addr2->devid << 8) | addr2->function;
	if (dev_addr > dev_addr2)
		return 1;
	else if (dev_addr < dev_addr2)
		return -1;
	else
		return 0;
}


/**
	* Scan the content of the PCI bus, and the devices in the devices
	* list
	* @return
	*  0 on success, negative on error
	*/
int rte_eal_pci_scan(void);


/**
	* Probe the PCI bus for registered drivers.
	* Scan the content of the PCI bus, and call the probe() function for
	* all registered drivers that have a matching entry in its id_table
	* for discovered devices.
	* @return
	*/
int rte_eal_pci_probe(void);


/**
	* Map the PCI device resources in user space virtual memory address
	* Note that driver should not call this function when flag
	* RTE_PCI_DRV_NEED_MAPPING is set, as EAL will do that for
	* you when it's on.
	* @param dev
	* @return
	*/
int rte_eal_pci_map_device(struct rte_pci_device *dev);


/**
	* Unmap this device
	* @param dev
	*/
void rte_eal_pci_unmap_device(struct rte_pci_device *dev);


/**
	* @internal
	* Map a particular resource from a file.
	* @param requested_addr
	* @param fd
	* @param offset
	* @param size
	* @param additional_flags
	* @return
	*/
void *pci_map_resource(void *requested_addr, int fd, off_t offset,
		size_t size, int additional_flags);


/**
	* @internal
	* Unmap a particular resource.
	* @param requested_addr
	* @param size
	*/
void pci_unmap_resource(void *requested_addr, size_t size);


/**
	* Probe the single PCI device.
	* Scan the content of the PCI bus, and find the pci device specified by pci
	* address, then call the probe() function for registered driver that has a
	* matching entry in its id_table for discovered device.
	* @param addr
	*	The PCI Bus-Device-Function address to probe.
	* @return
	*/
int rte_eal_pci_probe_one(const struct rte_pci_addr *addr);


/**
	* Close the single PCI device.
	* Scan the content of the PCI bus, and find the pci device specified by pci
	* address, then call the devuninit() function for registered driver that has a
	* matching entry in its id_table for discovered device.
	* @param addr
	*	The PCI Bus-Device-Function address to close.
	* @return
	*/
int rte_eal_pci_detach(const struct rte_pci_addr *addr);


/**
	* Dump the content of the PCI bus.
	* @param f
	*/
void rte_eal_pci_dump(FILE *f);


/**
	* Register a PCI driver.
	* @param driver
	*/
void rte_eal_pci_register(struct rte_pci_driver *driver);


/**
	* Unregister a PCI driver.
	* @param driver
	*/
void rte_eal_pci_unregister(struct rte_pci_driver *driver);


/**
	* Read PCI config space.
	* @param device
	* @param buf
	* @param len
	* @param offset
	*/
int rte_eal_pci_read_config(const struct rte_pci_device *device,
						 void *buf, size_t len, off_t offset);


/**
	* Write PCI config space.
	* @param device
	* @param buf
	* @param len
	* @param offset
	*/
int rte_eal_pci_write_config(const struct rte_pci_device *device,
						  const void *buf, size_t len, off_t offset);


/**
	* A structure used to access io resources for a pci device.
	* rte_pci_ioport is arch, os, driver specific, and should not be used outside
	* of pci ioport api.
	*/
struct rte_pci_ioport
{
	struct rte_pci_device *dev;
	uint64_t base;
	uint64_t len; 


};


/**
	* Initialize a rte_pci_ioport object for a pci device io resource.
	* This object is then used to gain access to those io resources (see below).
	* @param dev
	* @param bar
	* @param p
	* @return
	*  0 on success, negative on error.
	*/
int rte_eal_pci_ioport_map(struct rte_pci_device *dev, int bar,
						struct rte_pci_ioport *p);


/**
	* Release any resources used in a rte_pci_ioport object.
	* @param p
	* @return
	*  0 on success, negative on error.
	*/
int rte_eal_pci_ioport_unmap(struct rte_pci_ioport *p);


/**
	* Read from a io pci resource.
	* @param p
	* @param data
	* @param len
	* @param offset
	*/
void rte_eal_pci_ioport_read(struct rte_pci_ioport *p,
						  void *data, size_t len, off_t offset);


/**
	* Write to a io pci resource.
	* @param p
	* @param data
	* @param len
	* @param offset
	*/
void rte_eal_pci_ioport_write(struct rte_pci_ioport *p,
						   const void *data, size_t len, off_t offset);
struct rte_mbuf;


/**
	* A structure used to retrieve statistics for an Ethernet port.
	*/
struct rte_eth_stats
{
	uint64_t ipackets; 


	uint64_t opackets; 


	uint64_t ibytes; 


	uint64_t obytes; 


	uint64_t imissed;

/**< Total of RX packets dropped by the HW,
	 * because there are no available mbufs (i.e. RX queues are full).
	 */
	uint64_t ierrors; 


	uint64_t oerrors; 


	uint64_t rx_nombuf; 


	uint64_t q_ipackets[16];


	uint64_t q_opackets[16];


	uint64_t q_ibytes[16];


	uint64_t q_obytes[16];


	uint64_t q_errors[16];


};


/**
	* Device supported speeds bitmap flags
	*/


/**
	* Ethernet numeric link speeds in Mbps
	*/


/**
	* A structure used to retrieve link-level information of an Ethernet port.
	*/
__extension__
struct rte_eth_link
{
	uint32_t link_speed; 


	uint16_t link_duplex : 1; 


	uint16_t link_autoneg : 1; 


	uint16_t link_status : 1; 


} __attribute__((aligned(8))); 







/**
	* A structure used to configure the ring threshold registers of an RX/TX
	* queue for an Ethernet port.
	*/
struct rte_eth_thresh
{
	uint8_t pthresh; 


	uint8_t hthresh; 


	uint8_t wthresh; 


};


/**
	*  Simple flags are used for rte_eth_conf.rxmode.mq_mode.
	*/


/**
	*  A set of values to identify what method is to be used to route
	*  packets to multiple queues.
	*/
enum rte_eth_rx_mq_mode
{


	ETH_MQ_RX_NONE = 0,


	ETH_MQ_RX_RSS = 0x1,


	ETH_MQ_RX_DCB = 0x2,


	ETH_MQ_RX_DCB_RSS = 0x1 | 0x2,


	ETH_MQ_RX_VMDQ_ONLY = 0x4,


	ETH_MQ_RX_VMDQ_RSS = 0x1 | 0x4,


	ETH_MQ_RX_VMDQ_DCB = 0x4 | 0x2,


	ETH_MQ_RX_VMDQ_DCB_RSS = 0x1 | 0x2 |
					0x4,
};


/**
	* for rx mq mode backward compatible
	*/


/**
	* A set of values to identify what method is to be used to transmit
	* packets using multi-TCs.
	*/
enum rte_eth_tx_mq_mode
{
	ETH_MQ_TX_NONE = 0, 


	ETH_MQ_TX_DCB, 


	ETH_MQ_TX_VMDQ_DCB, 


	ETH_MQ_TX_VMDQ_ONLY, 


};


/**
	* for tx mq mode backward compatible
	*/


/**
	* A structure used to configure the RX features of an Ethernet port.
	*/
struct rte_eth_rxmode
{


	enum rte_eth_rx_mq_mode mq_mode;
	uint32_t max_rx_pkt_len; 


	uint16_t split_hdr_size; 


	__extension__
	uint16_t header_split : 1, 


		hw_ip_checksum : 1, 


		hw_vlan_filter : 1, 


		hw_vlan_strip : 1, 


		hw_vlan_extend : 1, 


		jumbo_frame : 1, 


		hw_strip_crc : 1, 


		enable_scatter : 1, 


		enable_lro : 1; 


};


/**
	* VLAN types to indicate if it is for single VLAN, inner VLAN or outer VLAN.
	* Note that single VLAN is treated the same as inner VLAN.
	*/
enum rte_vlan_type
{
	ETH_VLAN_TYPE_UNKNOWN = 0,
	ETH_VLAN_TYPE_INNER, 


	ETH_VLAN_TYPE_OUTER, 


	ETH_VLAN_TYPE_MAX,
};


/**
	* A structure used to configure the Receive Side Scaling (RSS) feature
	* of an Ethernet port.
	* If not NULL, the *rss_key* pointer of the *rss_conf* structure points
	* to an array holding the RSS key to use for hashing specific header
	* fields of received packets. The length of this array should be indicated
	* by *rss_key_len* below. Otherwise, a default random hash key is used by
	* the device driver.
	* The *rss_key_len* field of the *rss_conf* structure indicates the length
	* in bytes of the array pointed by *rss_key*. To be compatible, this length
	* will be checked in i40e only. Others assume 40 bytes to be used as before.
	* The *rss_hf* field of the *rss_conf* structure indicates the different
	* types of IPv4/IPv6 packets to which the RSS hashing must be applied.
	* Supplying an *rss_hf* equal to zero disables the RSS feature.
	*/
struct rte_eth_rss_conf
{
	uint8_t *rss_key; 


	uint8_t rss_key_len; 


	uint64_t rss_hf; 


};


/*
	* The RSS offload types are defined based on flow types which are defined
	* in rte_eth_ctrl.h. Different NIC hardwares may support different RSS offload
	* types. The supported flow types or RSS offload types can be queried by
	* rte_eth_dev_info_get().
	*/





/*
	* Definitions used for redirection table entry size.
	* Some RSS RETA sizes may not be supported by some drivers, check the
	* documentation or the description of relevant functions for more details.
	*/


























/**
	* A structure used to configure VLAN traffic mirror of an Ethernet port.
	*/
struct rte_eth_vlan_mirror
{
	uint64_t vlan_mask; 




	uint16_t vlan_id[64];
};


/**
	* A structure used to configure traffic mirror of an Ethernet port.
	*/
struct rte_eth_mirror_conf
{
	uint8_t rule_type; 


	uint8_t dst_pool; 


	uint64_t pool_mask; 




	struct rte_eth_vlan_mirror vlan;
};


/**
	* A structure used to configure 64 entries of Redirection Table of the
	* Receive Side Scaling (RSS) feature of an Ethernet port. To configure
	* more than 64 entries supported by hardware, an array of this structure
	* is needed.
	*/
struct rte_eth_rss_reta_entry64
{
	uint64_t mask;


	uint16_t reta[64];


};


/**
	* This enum indicates the possible number of traffic classes
	* in DCB configratioins
	*/
enum rte_eth_nb_tcs
{
	ETH_4_TCS = 4, 


	ETH_8_TCS = 8 


};


/**
	* This enum indicates the possible number of queue pools
	* in VMDQ configurations.
	*/
enum rte_eth_nb_pools
{
	ETH_8_POOLS = 8, 


	ETH_16_POOLS = 16, 


	ETH_32_POOLS = 32, 


	ETH_64_POOLS = 64 


};



struct rte_eth_dcb_rx_conf
{
	enum rte_eth_nb_tcs nb_tcs; 




	uint8_t dcb_tc[8];
};
struct rte_eth_vmdq_dcb_tx_conf
{
	enum rte_eth_nb_pools nb_queue_pools; 




	uint8_t dcb_tc[8];
};
struct rte_eth_dcb_tx_conf
{
	enum rte_eth_nb_tcs nb_tcs; 




	uint8_t dcb_tc[8];
};
struct rte_eth_vmdq_tx_conf
{
	enum rte_eth_nb_pools nb_queue_pools; 


};


/**
	* A structure used to configure the VMDQ+DCB feature
	* of an Ethernet port.
	* Using this feature, packets are routed to a pool of queues, based
	* on the vlan id in the vlan tag, and then to a specific queue within
	* that pool, using the user priority vlan tag field.
	* A default pool may be used, if desired, to route all traffic which
	* does not match the vlan filter rules.
	*/
struct rte_eth_vmdq_dcb_conf
{
	enum rte_eth_nb_pools nb_queue_pools; 


	uint8_t enable_default_pool; 


	uint8_t default_pool; 


	uint8_t nb_pool_maps; 


	struct
{
		uint16_t vlan_id; 


		uint64_t pools; 


	} pool_map[64]; 


	uint8_t dcb_tc[8];


};
struct rte_eth_vmdq_rx_conf
{
	enum rte_eth_nb_pools nb_queue_pools; 


	uint8_t enable_default_pool; 


	uint8_t default_pool; 


	uint8_t enable_loop_back; 


	uint8_t nb_pool_maps; 


	uint32_t rx_mode; 


	struct
{
		uint16_t vlan_id; 


		uint64_t pools; 


	} pool_map[64]; 


};


/**
	* A structure used to configure the TX features of an Ethernet port.
	*/
struct rte_eth_txmode
{
	enum rte_eth_tx_mq_mode mq_mode; 




	uint16_t pvid;
	__extension__
	uint8_t hw_vlan_reject_tagged : 1,


		hw_vlan_reject_untagged : 1,


		hw_vlan_insert_pvid : 1;


};


/**
	* A structure used to configure an RX ring of an Ethernet port.
	*/
struct rte_eth_rxconf
{
	struct rte_eth_thresh rx_thresh; 


	uint16_t rx_free_thresh; 


	uint8_t rx_drop_en; 


	uint8_t rx_deferred_start; 


};


/**
	* A structure used to configure a TX ring of an Ethernet port.
	*/
struct rte_eth_txconf
{
	struct rte_eth_thresh tx_thresh; 


	uint16_t tx_rs_thresh; 


	uint16_t tx_free_thresh; 

/**< Start freeing TX buffers if there are
				      less free descriptors than this value. */
	uint32_t txq_flags; 


	uint8_t tx_deferred_start; 


};


/**
	* A structure contains information about HW descriptor ring limitations.
	*/
struct rte_eth_desc_lim
{
	uint16_t nb_max; 


	uint16_t nb_min; 


	uint16_t nb_align; 


};


/**
	* This enum indicates the flow control mode
	*/
enum rte_eth_fc_mode
{
	RTE_FC_NONE = 0, 


	RTE_FC_RX_PAUSE, 


	RTE_FC_TX_PAUSE, 


	RTE_FC_FULL 


};


/**
	* A structure used to configure Ethernet flow control parameter.
	* These parameters will be configured into the register of the NIC.
	* Please refer to the corresponding data sheet for proper value.
	*/
struct rte_eth_fc_conf
{
	uint32_t high_water; 


	uint32_t low_water; 


	uint16_t pause_time; 


	uint16_t send_xon; 


	enum rte_eth_fc_mode mode; 


	uint8_t mac_ctrl_frame_fwd; 


	uint8_t autoneg; 


};


/**
	* A structure used to configure Ethernet priority flow control parameter.
	* These parameters will be configured into the register of the NIC.
	* Please refer to the corresponding data sheet for proper value.
	*/
struct rte_eth_pfc_conf
{
	struct rte_eth_fc_conf fc; 


	uint8_t priority; 


};


/**
	*  Memory space that can be configured to store Flow Director filters
	*  in the board memory.
	*/
enum rte_fdir_pballoc_type
{
	RTE_FDIR_PBALLOC_64K = 0, 


	RTE_FDIR_PBALLOC_128K, 


	RTE_FDIR_PBALLOC_256K, 


};


/**
	*  Select report mode of FDIR hash information in RX descriptors.
	*/
enum rte_fdir_status_mode
{
	RTE_FDIR_NO_REPORT_STATUS = 0, 


	RTE_FDIR_REPORT_STATUS, 


	RTE_FDIR_REPORT_STATUS_ALWAYS, 


};


/**
	* A structure used to configure the Flow Director (FDIR) feature
	* of an Ethernet port.
	* If mode is RTE_FDIR_DISABLE, the pballoc value is ignored.
	*/
struct rte_fdir_conf
{
	enum rte_fdir_mode mode; 


	enum rte_fdir_pballoc_type pballoc; 


	enum rte_fdir_status_mode status; 




	uint8_t drop_queue;
	struct rte_eth_fdir_masks mask;
	struct rte_eth_fdir_flex_conf flex_conf;


};


/**
	* UDP tunneling configuration.
	* Used to config the UDP port for a type of tunnel.
	* NICs need the UDP port to identify the tunnel type.
	* Normally a type of tunnel has a default UDP port, this structure can be used
	* in case if the users want to change or support more UDP port.
	*/
struct rte_eth_udp_tunnel
{
	uint16_t udp_port; 


	uint8_t prot_type; 


};


/**
	* A structure used to enable/disable specific device interrupts.
	*/
struct rte_intr_conf
{


	uint16_t lsc;


	uint16_t rxq;
};


/**
	* A structure used to configure an Ethernet port.
	* Depending upon the RX multi-queue mode, extra advanced
	* configuration settings may be needed.
	*/
struct rte_eth_conf
{
	uint32_t link_speeds; 

/**< bitmap of ETH_LINK_SPEED_XXX of speeds to be
				used. ETH_LINK_SPEED_FIXED disables link
				autonegotiation, and a unique speed shall be
				set. Otherwise, the bitmap defines the set of
				speeds to be advertised. If the special value
				ETH_LINK_SPEED_AUTONEG (0) is used, all speeds
				supported are advertised. */
	struct rte_eth_rxmode rxmode; 


	struct rte_eth_txmode txmode; 


	uint32_t lpbk_mode; 

/**< Loopback operation mode. By default the value
			         is 0, meaning the loopback mode is disabled.
				 Read the datasheet of given ethernet controller
				 for details. The possible values of this field
				 are defined in implementation of each driver. */
	struct
{
		struct rte_eth_rss_conf rss_conf; 


		struct rte_eth_vmdq_dcb_conf vmdq_dcb_conf;


		struct rte_eth_dcb_rx_conf dcb_rx_conf;


		struct rte_eth_vmdq_rx_conf vmdq_rx_conf;


	} rx_adv_conf; 


	union
{
		struct rte_eth_vmdq_dcb_tx_conf vmdq_dcb_tx_conf;


		struct rte_eth_dcb_tx_conf dcb_tx_conf;


		struct rte_eth_vmdq_tx_conf vmdq_tx_conf;


	} tx_adv_conf; 



/** Currently,Priority Flow Control(PFC) are supported,if DCB with PFC
	    is needed,and the variable must be set ETH_DCB_PFC_SUPPORT. */
	uint32_t dcb_capability_en;
	struct rte_fdir_conf fdir_conf; 


	struct rte_intr_conf intr_conf; 


};


/**
	* A structure used to retrieve the contextual information of
	* an Ethernet device, such as the controlling driver of the device,
	* its PCI context, etc...
	*/


/**
	* RX offload capabilities of a device.
	*/


/**
	* TX offload capabilities of a device.
	*/


/**
	* Ethernet device information
	*/
struct rte_eth_dev_info
{
	struct rte_pci_device *pci_dev; 


	const char *driver_name; 


	unsigned int if_index; 

/**< Index to bound host interface, or 0 if none.
		Use if_indextoname() to translate into an interface name. */
	uint32_t min_rx_bufsize; 


	uint32_t max_rx_pktlen; 


	uint16_t max_rx_queues; 


	uint16_t max_tx_queues; 


	uint32_t max_mac_addrs; 


	uint32_t max_hash_mac_addrs;


	uint16_t max_vfs; 


	uint16_t max_vmdq_pools; 


	uint32_t rx_offload_capa; 


	uint32_t tx_offload_capa; 


	uint16_t reta_size;


	uint8_t hash_key_size; 




	uint64_t flow_type_rss_offloads;
	struct rte_eth_rxconf default_rxconf; 


	struct rte_eth_txconf default_txconf; 


	uint16_t vmdq_queue_base; 


	uint16_t vmdq_queue_num; 


	uint16_t vmdq_pool_base; 


	struct rte_eth_desc_lim rx_desc_lim; 


	struct rte_eth_desc_lim tx_desc_lim; 


	uint32_t speed_capa; 




	uint16_t nb_rx_queues; 


	uint16_t nb_tx_queues; 


};


/**
	* Ethernet device RX queue information structure.
	* Used to retieve information about configured queue.
	*/
struct rte_eth_rxq_info
{
	struct rte_mempool *mp; 


	struct rte_eth_rxconf conf; 


	uint8_t scattered_rx; 


	uint16_t nb_desc; 


} __attribute__((__aligned__(64)));


/**
	* Ethernet device TX queue information structure.
	* Used to retieve information about configured queue.
	*/
struct rte_eth_txq_info
{
	struct rte_eth_txconf conf; 


	uint16_t nb_desc; 


} __attribute__((__aligned__(64)));





/**
	* An Ethernet device extended statistic structure
	* This structure is used by ethdev->eth_xstats_get() to provide
	* statistics that are not provided in the generic rte_eth_stats
	* structure.
	*/
struct rte_eth_xstat
{
	uint64_t id;
	uint64_t value;
};


/**
	* A name-key lookup element for extended statistics.
	* This structure is used to map between names and ID numbers
	* for extended ethernet statistics.
	*/
struct rte_eth_xstat_name
{
	char name[64];
};


/**
	* A structure used to get the information of queue and
	* TC mapping on both TX and RX paths.
	*/
struct rte_eth_dcb_tc_queue_mapping
{


	struct
{
		uint8_t base;
		uint8_t nb_queue;
	} tc_rxq[64][8];


	struct
{
		uint8_t base;
		uint8_t nb_queue;
	} tc_txq[64][8];
};


/**
	* A structure used to get the information of DCB.
	* It includes TC UP mapping and queue TC mapping.
	*/
struct rte_eth_dcb_info
{
	uint8_t nb_tcs; 


	uint8_t prio_tc[8]; 


	uint8_t tc_bws[8]; 




	struct rte_eth_dcb_tc_queue_mapping tc_queue;
};


/**
	* RX/TX queue states
	*/
struct rte_eth_dev;
struct rte_eth_dev_callback;



struct rte_eth_dev_cb_list { struct rte_eth_dev_callback *tqh_first; struct rte_eth_dev_callback * *tqh_last; };





/**
	* l2 tunnel configuration.
	*/














/*
	* Definitions of all functions exported by an Ethernet driver through the
	* the generic structure of type *eth_dev_ops* supplied in the *rte_eth_dev*
	* structure associated with an Ethernet device.
	*/
typedef int (*eth_dev_configure_t)(struct rte_eth_dev *dev);



typedef int (*eth_dev_start_t)(struct rte_eth_dev *dev);



typedef void (*eth_dev_stop_t)(struct rte_eth_dev *dev);



typedef int (*eth_dev_set_link_up_t)(struct rte_eth_dev *dev);



typedef int (*eth_dev_set_link_down_t)(struct rte_eth_dev *dev);



typedef void (*eth_dev_close_t)(struct rte_eth_dev *dev);



typedef void (*eth_promiscuous_enable_t)(struct rte_eth_dev *dev);



typedef void (*eth_promiscuous_disable_t)(struct rte_eth_dev *dev);



typedef void (*eth_allmulticast_enable_t)(struct rte_eth_dev *dev);



typedef void (*eth_allmulticast_disable_t)(struct rte_eth_dev *dev);



typedef int (*eth_link_update_t)(struct rte_eth_dev *dev,
				int wait_to_complete);



typedef void (*eth_stats_get_t)(struct rte_eth_dev *dev,
				struct rte_eth_stats *igb_stats);



typedef void (*eth_stats_reset_t)(struct rte_eth_dev *dev);



typedef int (*eth_xstats_get_t)(struct rte_eth_dev *dev,
	struct rte_eth_xstat *stats, unsigned n);



typedef void (*eth_xstats_reset_t)(struct rte_eth_dev *dev);



typedef int (*eth_xstats_get_names_t)(struct rte_eth_dev *dev,
	struct rte_eth_xstat_name *xstats_names, unsigned size);



typedef int (*eth_queue_stats_mapping_set_t)(struct rte_eth_dev *dev,
						    uint16_t queue_id,
						    uint8_t stat_idx,
						    uint8_t is_rx);



typedef void (*eth_dev_infos_get_t)(struct rte_eth_dev *dev,
						  struct rte_eth_dev_info *dev_info);



typedef const uint32_t *(*eth_dev_supported_ptypes_get_t)(struct rte_eth_dev *dev);



typedef int (*eth_queue_start_t)(struct rte_eth_dev *dev,
						  uint16_t queue_id);



typedef int (*eth_queue_stop_t)(struct rte_eth_dev *dev,
						  uint16_t queue_id);



typedef int (*eth_rx_queue_setup_t)(struct rte_eth_dev *dev,
						  uint16_t rx_queue_id,
						  uint16_t nb_rx_desc,
						  unsigned int socket_id,
						  const struct rte_eth_rxconf *rx_conf,
						  struct rte_mempool *mb_pool);



typedef int (*eth_tx_queue_setup_t)(struct rte_eth_dev *dev,
						  uint16_t tx_queue_id,
						  uint16_t nb_tx_desc,
						  unsigned int socket_id,
						  const struct rte_eth_txconf *tx_conf);



typedef int (*eth_rx_enable_intr_t)(struct rte_eth_dev *dev,
						  uint16_t rx_queue_id);



typedef int (*eth_rx_disable_intr_t)(struct rte_eth_dev *dev,
						  uint16_t rx_queue_id);



typedef void (*eth_queue_release_t)(void *queue);



typedef uint32_t (*eth_rx_queue_count_t)(struct rte_eth_dev *dev,
						uint16_t rx_queue_id);



typedef int (*eth_rx_descriptor_done_t)(void *rxq, uint16_t offset);



typedef void (*eth_rxq_info_get_t)(struct rte_eth_dev *dev,
	uint16_t rx_queue_id, struct rte_eth_rxq_info *qinfo);
typedef void (*eth_txq_info_get_t)(struct rte_eth_dev *dev,
	uint16_t tx_queue_id, struct rte_eth_txq_info *qinfo);
typedef int (*mtu_set_t)(struct rte_eth_dev *dev, uint16_t mtu);



typedef int (*vlan_filter_set_t)(struct rte_eth_dev *dev,
						uint16_t vlan_id,
						int on);



typedef int (*vlan_tpid_set_t)(struct rte_eth_dev *dev,
						    enum rte_vlan_type type, uint16_t tpid);



typedef void (*vlan_offload_set_t)(struct rte_eth_dev *dev, int mask);



typedef int (*vlan_pvid_set_t)(struct rte_eth_dev *dev,
						    uint16_t vlan_id,
						    int on);



typedef void (*vlan_strip_queue_set_t)(struct rte_eth_dev *dev,
						uint16_t rx_queue_id,
						int on);



typedef uint16_t (*eth_rx_burst_t)(void *rxq,
						 struct rte_mbuf **rx_pkts,
						 uint16_t nb_pkts);



typedef uint16_t (*eth_tx_burst_t)(void *txq,
						 struct rte_mbuf **tx_pkts,
						 uint16_t nb_pkts);



typedef int (*flow_ctrl_get_t)(struct rte_eth_dev *dev,
						    struct rte_eth_fc_conf *fc_conf);



typedef int (*flow_ctrl_set_t)(struct rte_eth_dev *dev,
						    struct rte_eth_fc_conf *fc_conf);



typedef int (*priority_flow_ctrl_set_t)(struct rte_eth_dev *dev,
				struct rte_eth_pfc_conf *pfc_conf);



typedef int (*reta_update_t)(struct rte_eth_dev *dev,
						  struct rte_eth_rss_reta_entry64 *reta_conf,
						  uint16_t reta_size);



typedef int (*reta_query_t)(struct rte_eth_dev *dev,
						 struct rte_eth_rss_reta_entry64 *reta_conf,
						 uint16_t reta_size);



typedef int (*rss_hash_update_t)(struct rte_eth_dev *dev,
					struct rte_eth_rss_conf *rss_conf);



typedef int (*rss_hash_conf_get_t)(struct rte_eth_dev *dev,
						 struct rte_eth_rss_conf *rss_conf);



typedef int (*eth_dev_led_on_t)(struct rte_eth_dev *dev);



typedef int (*eth_dev_led_off_t)(struct rte_eth_dev *dev);



typedef void (*eth_mac_addr_remove_t)(struct rte_eth_dev *dev, uint32_t index);



typedef void (*eth_mac_addr_add_t)(struct rte_eth_dev *dev,
						struct ether_addr *mac_addr,
						uint32_t index,
						uint32_t vmdq);



typedef void (*eth_mac_addr_set_t)(struct rte_eth_dev *dev,
						struct ether_addr *mac_addr);



typedef int (*eth_uc_hash_table_set_t)(struct rte_eth_dev *dev,
						struct ether_addr *mac_addr,
						uint8_t on);



typedef int (*eth_uc_all_hash_table_set_t)(struct rte_eth_dev *dev,
						uint8_t on);



typedef int (*eth_set_vf_rx_mode_t)(struct rte_eth_dev *dev,
						uint16_t vf,
						uint16_t rx_mode,
						uint8_t on);



typedef int (*eth_set_vf_rx_t)(struct rte_eth_dev *dev,
				uint16_t vf,
				uint8_t on);



typedef int (*eth_set_vf_tx_t)(struct rte_eth_dev *dev,
				uint16_t vf,
				uint8_t on);



typedef int (*eth_set_vf_vlan_filter_t)(struct rte_eth_dev *dev,
						uint16_t vlan,
						uint64_t vf_mask,
						uint8_t vlan_on);



typedef int (*eth_set_queue_rate_limit_t)(struct rte_eth_dev *dev,
				uint16_t queue_idx,
				uint16_t tx_rate);



typedef int (*eth_set_vf_rate_limit_t)(struct rte_eth_dev *dev,
				uint16_t vf,
				uint16_t tx_rate,
				uint64_t q_msk);



typedef int (*eth_mirror_rule_set_t)(struct rte_eth_dev *dev,
						struct rte_eth_mirror_conf *mirror_conf,
						uint8_t rule_id,
						uint8_t on);



typedef int (*eth_mirror_rule_reset_t)(struct rte_eth_dev *dev,
						uint8_t rule_id);



typedef int (*eth_udp_tunnel_port_add_t)(struct rte_eth_dev *dev,
						struct rte_eth_udp_tunnel *tunnel_udp);



typedef int (*eth_udp_tunnel_port_del_t)(struct rte_eth_dev *dev,
						struct rte_eth_udp_tunnel *tunnel_udp);



typedef int (*eth_set_mc_addr_list_t)(struct rte_eth_dev *dev,
						    struct ether_addr *mc_addr_set,
						    uint32_t nb_mc_addr);



typedef int (*eth_timesync_enable_t)(struct rte_eth_dev *dev);



typedef int (*eth_timesync_disable_t)(struct rte_eth_dev *dev);



typedef int (*eth_timesync_read_rx_timestamp_t)(struct rte_eth_dev *dev,
						struct timespec *timestamp,
						uint32_t flags);



typedef int (*eth_timesync_read_tx_timestamp_t)(struct rte_eth_dev *dev,
						struct timespec *timestamp);



typedef int (*eth_timesync_adjust_time)(struct rte_eth_dev *dev, int64_t);



typedef int (*eth_timesync_read_time)(struct rte_eth_dev *dev,
						    struct timespec *timestamp);



typedef int (*eth_timesync_write_time)(struct rte_eth_dev *dev,
						     const struct timespec *timestamp);



typedef int (*eth_get_reg_t)(struct rte_eth_dev *dev,
				struct rte_dev_reg_info *info);



typedef int (*eth_get_eeprom_length_t)(struct rte_eth_dev *dev);



typedef int (*eth_get_eeprom_t)(struct rte_eth_dev *dev,
				struct rte_dev_eeprom_info *info);



typedef int (*eth_set_eeprom_t)(struct rte_eth_dev *dev,
				struct rte_dev_eeprom_info *info);



typedef int (*eth_l2_tunnel_eth_type_conf_t)
	(struct rte_eth_dev *dev, struct rte_eth_l2_tunnel_conf *l2_tunnel);



typedef int (*eth_l2_tunnel_offload_set_t)
	(struct rte_eth_dev *dev,
		struct rte_eth_l2_tunnel_conf *l2_tunnel,
		uint32_t mask,
		uint8_t en);



typedef int (*eth_filter_ctrl_t)(struct rte_eth_dev *dev,
					enum rte_filter_type filter_type,
					enum rte_filter_op filter_op,
					void *arg);



typedef int (*eth_get_dcb_info)(struct rte_eth_dev *dev,
					struct rte_eth_dcb_info *dcb_info);





/**
	* @internal A structure containing the functions exported by an Ethernet driver.
	*/
struct eth_dev_ops
{
	eth_dev_configure_t dev_configure; 


	eth_dev_start_t dev_start; 


	eth_dev_stop_t dev_stop; 


	eth_dev_set_link_up_t dev_set_link_up; 


	eth_dev_set_link_down_t dev_set_link_down; 


	eth_dev_close_t dev_close; 


	eth_promiscuous_enable_t promiscuous_enable; 


	eth_promiscuous_disable_t promiscuous_disable;


	eth_allmulticast_enable_t allmulticast_enable;


	eth_allmulticast_disable_t allmulticast_disable;


	eth_link_update_t link_update; 


	eth_stats_get_t stats_get; 


	eth_stats_reset_t stats_reset; 


	eth_xstats_get_t xstats_get; 


	eth_xstats_reset_t xstats_reset; 


	eth_xstats_get_names_t xstats_get_names;


	eth_queue_stats_mapping_set_t queue_stats_mapping_set;


	eth_dev_infos_get_t dev_infos_get; 


	eth_dev_supported_ptypes_get_t dev_supported_ptypes_get;


	mtu_set_t mtu_set; 


	vlan_filter_set_t vlan_filter_set; 


	vlan_tpid_set_t vlan_tpid_set; 


	vlan_strip_queue_set_t vlan_strip_queue_set; 


	vlan_offload_set_t vlan_offload_set; 


	vlan_pvid_set_t vlan_pvid_set; 


	eth_queue_start_t rx_queue_start;


	eth_queue_stop_t rx_queue_stop;


	eth_queue_start_t tx_queue_start;


	eth_queue_stop_t tx_queue_stop;


	eth_rx_queue_setup_t rx_queue_setup;


	eth_queue_release_t rx_queue_release;


	eth_rx_queue_count_t rx_queue_count; 


	eth_rx_descriptor_done_t rx_descriptor_done; 




	eth_rx_enable_intr_t rx_queue_intr_enable;


	eth_rx_disable_intr_t rx_queue_intr_disable;
	eth_tx_queue_setup_t tx_queue_setup;


	eth_queue_release_t tx_queue_release;


	eth_dev_led_on_t dev_led_on; 


	eth_dev_led_off_t dev_led_off; 


	flow_ctrl_get_t flow_ctrl_get; 


	flow_ctrl_set_t flow_ctrl_set; 


	priority_flow_ctrl_set_t priority_flow_ctrl_set; 


	eth_mac_addr_remove_t mac_addr_remove; 


	eth_mac_addr_add_t mac_addr_add; 


	eth_mac_addr_set_t mac_addr_set; 


	eth_uc_hash_table_set_t uc_hash_table_set; 


	eth_uc_all_hash_table_set_t uc_all_hash_table_set; 


	eth_mirror_rule_set_t mirror_rule_set; 


	eth_mirror_rule_reset_t mirror_rule_reset; 


	eth_set_vf_rx_mode_t set_vf_rx_mode; 


	eth_set_vf_rx_t set_vf_rx; 


	eth_set_vf_tx_t set_vf_tx; 


	eth_set_vf_vlan_filter_t set_vf_vlan_filter; 




	eth_udp_tunnel_port_add_t udp_tunnel_port_add;


	eth_udp_tunnel_port_del_t udp_tunnel_port_del;
	eth_set_queue_rate_limit_t set_queue_rate_limit; 


	eth_set_vf_rate_limit_t set_vf_rate_limit; 




	reta_update_t reta_update;


	reta_query_t reta_query;
	eth_get_reg_t get_reg;


	eth_get_eeprom_length_t get_eeprom_length;


	eth_get_eeprom_t get_eeprom;


	eth_set_eeprom_t set_eeprom;






	rss_hash_update_t rss_hash_update;


	rss_hash_conf_get_t rss_hash_conf_get;
	eth_filter_ctrl_t filter_ctrl;


	eth_set_mc_addr_list_t set_mc_addr_list; 


	eth_rxq_info_get_t rxq_info_get;


	eth_txq_info_get_t txq_info_get;




	eth_timesync_enable_t timesync_enable;


	eth_timesync_disable_t timesync_disable;


	eth_timesync_read_rx_timestamp_t timesync_read_rx_timestamp;


	eth_timesync_read_tx_timestamp_t timesync_read_tx_timestamp;


	eth_get_dcb_info get_dcb_info;


	eth_timesync_adjust_time timesync_adjust_time;


	eth_timesync_read_time timesync_read_time;


	eth_timesync_write_time timesync_write_time;


	eth_l2_tunnel_eth_type_conf_t l2_tunnel_eth_type_conf;


	eth_l2_tunnel_offload_set_t l2_tunnel_offload_set;
};


/**
	* Function type used for RX packet processing packet callbacks.
	* The callback function is called on RX with a burst of packets that have
	* been received on the given port and queue.
	* @param port
	* @param queue
	* @param pkts
	* @param nb_pkts
	* @param max_pkts
	* @param user_param
	* @return
	*/
typedef uint16_t (*rte_rx_callback_fn)(uint8_t port, uint16_t queue,
	struct rte_mbuf *pkts[], uint16_t nb_pkts, uint16_t max_pkts,
	void *user_param);


/**
	* Function type used for TX packet processing packet callbacks.
	* The callback function is called on TX with a burst of packets immediately
	* before the packets are put onto the hardware queue for transmission.
	* @param port
	* @param queue
	* @param pkts
	* @param nb_pkts
	* @param user_param
	* @return
	*/
typedef uint16_t (*rte_tx_callback_fn)(uint8_t port, uint16_t queue,
	struct rte_mbuf *pkts[], uint16_t nb_pkts, void *user_param);


/**
	* @internal
	* Structure used to hold information about the callbacks to be called for a
	* queue on RX and TX.
	*/
struct rte_eth_rxtx_callback
{
	struct rte_eth_rxtx_callback *next;
	union{
		rte_rx_callback_fn rx;
		rte_tx_callback_fn tx;
	} fn;
	void *param;
};


/**
	* The eth device type.
	*/
enum rte_eth_dev_type
{
	RTE_ETH_DEV_UNKNOWN, 


	RTE_ETH_DEV_PCI,


	RTE_ETH_DEV_VIRTUAL, 


	RTE_ETH_DEV_MAX 


};


/**
	* @internal
	* The generic data structure associated with each ethernet device.
	* Pointers to burst-oriented packet receive and transmit functions are
	* located at the beginning of the structure, along with the pointer to
	* where all the data elements for the particular device are stored in shared
	* memory. This split allows the function pointer and driver data to be per-
	* process, while the actual configuration data for the device is shared.
	*/
struct rte_eth_dev
{
	eth_rx_burst_t rx_pkt_burst; 


	eth_tx_burst_t tx_pkt_burst; 


	struct rte_eth_dev_data *data; 


	const struct eth_driver *driver;


	const struct eth_dev_ops *dev_ops; 


	struct rte_pci_device *pci_dev; 




	struct rte_eth_dev_cb_list link_intr_cbs;

/**
	 * User-supplied functions called from rx_burst to post-process
	 * received packets before passing them to the user
	 */
	struct rte_eth_rxtx_callback *post_rx_burst_cbs[1024];

/**
	 * User-supplied functions called from tx_burst to pre-process
	 * received packets before passing them to the driver for transmission.
	 */
	struct rte_eth_rxtx_callback *pre_tx_burst_cbs[1024];
	uint8_t attached; 


	enum rte_eth_dev_type dev_type; 


} __attribute__((__aligned__(64)));
struct rte_eth_dev_sriov
{
	uint8_t active; 


	uint8_t nb_q_per_pool; 


	uint16_t def_vmdq_idx; 


	uint16_t def_pool_q_idx; 


};


/**
	* @internal
	* The data part, with no function pointers, associated with each ethernet device.
	* This structure is safe to place in shared memory to be common among different
	* processes in a multi-process configuration.
	*/
struct rte_eth_dev_data
{
	char name[(32)]; 


	void **rx_queues; 


	void **tx_queues; 


	uint16_t nb_rx_queues; 


	uint16_t nb_tx_queues; 


	struct rte_eth_dev_sriov sriov; 


	void *dev_private; 


	struct rte_eth_link dev_link;


	struct rte_eth_conf dev_conf; 


	uint16_t mtu; 


	uint32_t min_rx_buf_size;


	uint64_t rx_mbuf_alloc_failed; 


	struct ether_addr* mac_addrs;


	uint64_t mac_pool_sel[128];


	struct ether_addr* hash_mac_addrs;


	uint8_t port_id; 


	__extension__
	uint8_t promiscuous : 1, 


		scattered_rx : 1, 


		all_multicast : 1, 


		dev_started : 1, 


		lro : 1; 


	uint8_t rx_queue_state[1024];


	uint8_t tx_queue_state[1024];


	uint32_t dev_flags; 


	enum rte_kernel_driver kdrv; 


	int numa_node; 


	const char *drv_name; 


};











/**
	* @internal
	* The pool of *rte_eth_dev* structures. The size of the pool
	* is configured at compile-time in the <rte_ethdev.c> file.
	*/


/**
	* Get the total number of Ethernet devices that have been successfully
	* initialized by the [matching] Ethernet driver during the PCI probing phase.
	* All devices whose port identifier is in the range
	* [0,  rte_eth_dev_count() - 1] can be operated on by network applications
	* immediately after invoking rte_eal_init().
	* If the application unplugs a port using hotplug function, The enabled port
	* numbers may be noncontiguous. In the case, the applications need to manage
	* enabled port by themselves.
	* @return
	*/
uint8_t rte_eth_dev_count(void);


/**
	* @internal
	* Returns a ethdev slot specified by the unique identifier name.
	* @param	name
	*  The pointer to the Unique identifier name for each Ethernet device
	* @return
	*/
struct rte_eth_dev *rte_eth_dev_allocated(const char *name);


/**
	* @internal
	* Allocates a new ethdev slot for an ethernet device and returns the pointer
	* to that slot for the driver to use.
	* @param	name	Unique identifier name for each Ethernet device
	* @param	type	Device type of this Ethernet device
	* @return
	*/
struct rte_eth_dev *rte_eth_dev_allocate(const char *name,
		enum rte_eth_dev_type type);


/**
	* @internal
	* Release the specified ethdev port.
	* @param eth_dev
	* The *eth_dev* pointer is the address of the *rte_eth_dev* structure.
	* @return
	*/
int rte_eth_dev_release_port(struct rte_eth_dev *eth_dev);


/**
	* Attach a new Ethernet device specified by aruguments.
	* @param devargs
	*  A pointer to a strings array describing the new device
	*  to be attached. The strings should be a pci address like
	*  '0000:01:00.0' or virtual device name like 'eth_pcap0'.
	* @param port_id
	*  A pointer to a port identifier actually attached.
	* @return
	*  0 on success and port_id is filled, negative on error
	*/
int rte_eth_dev_attach(const char *devargs, uint8_t *port_id);


/**
	* Detach a Ethernet device specified by port identifier.
	* This function must be called when the device is in the
	* closed state.
	* @param port_id
	* @param devname
	*  A pointer to a device name actually detached.
	* @return
	*  0 on success and devname is filled, negative on error
	*/
int rte_eth_dev_detach(uint8_t port_id, char *devname);
struct eth_driver;


/**
	* @internal
	* Initialization function of an Ethernet driver invoked for each matching
	* Ethernet PCI device detected during the PCI probing phase.
	* @param eth_dev
	* @return
	*/
typedef int (*eth_dev_init_t)(struct rte_eth_dev *eth_dev);


/**
	* @internal
	* Finalization function of an Ethernet driver invoked for each matching
	* Ethernet PCI device detected during the PCI closing phase.
	* @param eth_dev
	* @return
	*/
typedef int (*eth_dev_uninit_t)(struct rte_eth_dev *eth_dev);


/**
	* @internal
	* The structure associated with a PMD Ethernet driver.
	* Each Ethernet driver acts as a PCI driver and is represented by a generic
	* *eth_driver* structure that holds:
	* - An *rte_pci_driver* structure (which must be the first field).
	* - The *eth_dev_init* function invoked for each matching PCI device.
	* - The *eth_dev_uninit* function invoked for each matching PCI device.
	* - The size of the private data to allocate for each matching device.
	*/
struct eth_driver
{
	struct rte_pci_driver pci_drv; 


	eth_dev_init_t eth_dev_init; 


	eth_dev_uninit_t eth_dev_uninit; 


	unsigned int dev_private_size; 


};


/**
	* @internal
	* A function invoked by the initialization function of an Ethernet driver
	* to simultaneously register itself as a PCI driver and as an Ethernet
	* Poll Mode Driver (PMD).
	* @param eth_drv
	*/
void rte_eth_driver_register(struct eth_driver *eth_drv);


/**
	* Convert a numerical speed in Mbps to a bitmap flag that can be used in
	* the bitmap link_speeds of the struct rte_eth_conf
	* @param speed
	* @param duplex
	* @return
	*/
uint32_t rte_eth_speed_bitflag(uint32_t speed, int duplex);


/**
	* Configure an Ethernet device.
	* This function must be invoked first before any other function in the
	* Ethernet API. This function can also be re-invoked when a device is in the
	* stopped state.
	* @param port_id
	* @param nb_rx_queue
	* @param nb_tx_queue
	* @param eth_conf
	* @return
	*/
int rte_eth_dev_configure(uint8_t port_id, uint16_t nb_rx_queue,
		uint16_t nb_tx_queue, const struct rte_eth_conf *eth_conf);


/**
	* Allocate and set up a receive queue for an Ethernet device.
	* The function allocates a contiguous block of memory for *nb_rx_desc*
	* receive descriptors from a memory zone associated with *socket_id*
	* and initializes each receive descriptor with a network buffer allocated
	* from the memory pool *mb_pool*.
	* @param port_id
	* @param rx_queue_id
	* @param nb_rx_desc
	* @param socket_id
	* @param rx_conf
	* @param mb_pool
	* @return
	*/
int rte_eth_rx_queue_setup(uint8_t port_id, uint16_t rx_queue_id,
		uint16_t nb_rx_desc, unsigned int socket_id,
		const struct rte_eth_rxconf *rx_conf,
		struct rte_mempool *mb_pool);


/**
	* Allocate and set up a transmit queue for an Ethernet device.
	* @param port_id
	* @param tx_queue_id
	* @param nb_tx_desc
	* @param socket_id
	* @param tx_conf
	* @return
	*/
int rte_eth_tx_queue_setup(uint8_t port_id, uint16_t tx_queue_id,
		uint16_t nb_tx_desc, unsigned int socket_id,
		const struct rte_eth_txconf *tx_conf);


/**
	* Return the NUMA socket to which an Ethernet device is connected
	* @param port_id
	* @return
	*/
int rte_eth_dev_socket_id(uint8_t port_id);


/**
	* Check if port_id of device is attached
	* @param port_id
	* @return
	*/
int rte_eth_dev_is_valid_port(uint8_t port_id);


/**
	* Start specified RX queue of a port. It is used when rx_deferred_start
	* flag of the specified queue is true.
	* @param port_id
	* @param rx_queue_id
	* @return
	*/
int rte_eth_dev_rx_queue_start(uint8_t port_id, uint16_t rx_queue_id);


/**
	* Stop specified RX queue of a port
	* @param port_id
	* @param rx_queue_id
	* @return
	*/
int rte_eth_dev_rx_queue_stop(uint8_t port_id, uint16_t rx_queue_id);


/**
	* Start TX for specified queue of a port. It is used when tx_deferred_start
	* flag of the specified queue is true.
	* @param port_id
	* @param tx_queue_id
	* @return
	*/
int rte_eth_dev_tx_queue_start(uint8_t port_id, uint16_t tx_queue_id);


/**
	* Stop specified TX queue of a port
	* @param port_id
	* @param tx_queue_id
	* @return
	*/
int rte_eth_dev_tx_queue_stop(uint8_t port_id, uint16_t tx_queue_id);


/**
	* Start an Ethernet device.
	* The device start step is the last one and consists of setting the configured
	* offload features and in starting the transmit and the receive units of the
	* device.
	* On success, all basic functions exported by the Ethernet API (link status,
	* receive/transmit, and so on) can be invoked.
	* @param port_id
	* @return
	*/
int rte_eth_dev_start(uint8_t port_id);


/**
	* Stop an Ethernet device. The device can be restarted with a call to
	* rte_eth_dev_start()
	* @param port_id
	*/
void rte_eth_dev_stop(uint8_t port_id);


/**
	* Link up an Ethernet device.
	* Set device link up will re-enable the device rx/tx
	* functionality after it is previously set device linked down.
	* @param port_id
	* @return
	*/
int rte_eth_dev_set_link_up(uint8_t port_id);


/**
	* Link down an Ethernet device.
	* The device rx/tx functionality will be disabled if success,
	* and it can be re-enabled with a call to
	* rte_eth_dev_set_link_up()
	* @param port_id
	*/
int rte_eth_dev_set_link_down(uint8_t port_id);


/**
	* Close a stopped Ethernet device. The device cannot be restarted!
	* The function frees all resources except for needed by the
	* closed state. To free these resources, call rte_eth_dev_detach().
	* @param port_id
	*/
void rte_eth_dev_close(uint8_t port_id);


/**
	* Enable receipt in promiscuous mode for an Ethernet device.
	* @param port_id
	*/
void rte_eth_promiscuous_enable(uint8_t port_id);


/**
	* Disable receipt in promiscuous mode for an Ethernet device.
	* @param port_id
	*/
void rte_eth_promiscuous_disable(uint8_t port_id);


/**
	* Return the value of promiscuous mode for an Ethernet device.
	* @param port_id
	* @return
	*/
int rte_eth_promiscuous_get(uint8_t port_id);


/**
	* Enable the receipt of any multicast frame by an Ethernet device.
	* @param port_id
	*/
void rte_eth_allmulticast_enable(uint8_t port_id);


/**
	* Disable the receipt of all multicast frames by an Ethernet device.
	* @param port_id
	*/
void rte_eth_allmulticast_disable(uint8_t port_id);


/**
	* Return the value of allmulticast mode for an Ethernet device.
	* @param port_id
	* @return
	*/
int rte_eth_allmulticast_get(uint8_t port_id);


/**
	* Retrieve the status (ON/OFF), the speed (in Mbps) and the mode (HALF-DUPLEX
	* or FULL-DUPLEX) of the physical link of an Ethernet device. It might need
	* to wait up to 9 seconds in it.
	* @param port_id
	* @param link
	*/
void rte_eth_link_get(uint8_t port_id, struct rte_eth_link *link);


/**
	* Retrieve the status (ON/OFF), the speed (in Mbps) and the mode (HALF-DUPLEX
	* or FULL-DUPLEX) of the physical link of an Ethernet device. It is a no-wait
	* version of rte_eth_link_get().
	* @param port_id
	* @param link
	*/
void rte_eth_link_get_nowait(uint8_t port_id, struct rte_eth_link *link);


/**
	* Retrieve the general I/O statistics of an Ethernet device.
	* @param port_id
	* @param stats
	* @return
	*/
int rte_eth_stats_get(uint8_t port_id, struct rte_eth_stats *stats);


/**
	* Reset the general I/O statistics of an Ethernet device.
	* @param port_id
	*/
void rte_eth_stats_reset(uint8_t port_id);


/**
	* Retrieve names of extended statistics of an Ethernet device.
	* @param port_id
	* @param xstats_names
	*  Block of memory to insert names into. Must be at least size in capacity.
	*  If set to NULL, function returns required capacity.
	* @param size
	*  Capacity of xstats_names (number of names).
	* @return
	*/
int rte_eth_xstats_get_names(uint8_t port_id,
		struct rte_eth_xstat_name *xstats_names,
		unsigned size);


/**
	* Retrieve extended statistics of an Ethernet device.
	* @param port_id
	* @param xstats
	* @param n
	* @return
	*/
int rte_eth_xstats_get(uint8_t port_id, struct rte_eth_xstat *xstats,
		unsigned n);


/**
	* Reset extended statistics of an Ethernet device.
	* @param port_id
	*/
void rte_eth_xstats_reset(uint8_t port_id);


/**
	*  Set a mapping for the specified transmit queue to the specified per-queue
	*  statistics counter.
	* @param port_id
	* @param tx_queue_id
	* @param stat_idx
	* @return
	*/
int rte_eth_dev_set_tx_queue_stats_mapping(uint8_t port_id,
		uint16_t tx_queue_id, uint8_t stat_idx);


/**
	*  Set a mapping for the specified receive queue to the specified per-queue
	*  statistics counter.
	* @param port_id
	* @param rx_queue_id
	* @param stat_idx
	* @return
	*/
int rte_eth_dev_set_rx_queue_stats_mapping(uint8_t port_id,
						  uint16_t rx_queue_id,
						  uint8_t stat_idx);


/**
	* Retrieve the Ethernet address of an Ethernet device.
	* @param port_id
	* @param mac_addr
	*/
void rte_eth_macaddr_get(uint8_t port_id, struct ether_addr *mac_addr);


/**
	* Retrieve the contextual information of an Ethernet device.
	* @param port_id
	* @param dev_info
	*/
void rte_eth_dev_info_get(uint8_t port_id, struct rte_eth_dev_info *dev_info);


/**
	* Retrieve the supported packet types of an Ethernet device.
	* When a packet type is announced as supported, it *must* be recognized by
	* the PMD. For instance, if RTE_PTYPE_L2_ETHER, RTE_PTYPE_L2_ETHER_VLAN
	* and RTE_PTYPE_L3_IPV4 are announced, the PMD must return the following
	* packet types for these packets:
	* - Ether/IPv4              -> RTE_PTYPE_L2_ETHER | RTE_PTYPE_L3_IPV4
	* - Ether/Vlan/IPv4         -> RTE_PTYPE_L2_ETHER_VLAN | RTE_PTYPE_L3_IPV4
	* - Ether/[anything else]   -> RTE_PTYPE_L2_ETHER
	* - Ether/Vlan/[anything else] -> RTE_PTYPE_L2_ETHER_VLAN
	* When a packet is received by a PMD, the most precise type must be
	* returned among the ones supported. However a PMD is allowed to set
	* packet type that is not in the supported list, at the condition that it
	* is more precise. Therefore, a PMD announcing no supported packet types
	* can still set a matching packet type in a received packet.
	* @note
	* @note
	* @param port_id
	* @param ptype_mask
	* @param ptypes
	* @param num
	*  Size of the array pointed by param ptypes.
	* @return
	*/
int rte_eth_dev_get_supported_ptypes(uint8_t port_id, uint32_t ptype_mask,
						   uint32_t *ptypes, int num);


/**
	* Retrieve the MTU of an Ethernet device.
	* @param port_id
	* @param mtu
	* @return
	*/
int rte_eth_dev_get_mtu(uint8_t port_id, uint16_t *mtu);


/**
	* Change the MTU of an Ethernet device.
	* @param port_id
	* @param mtu
	* @return
	*/
int rte_eth_dev_set_mtu(uint8_t port_id, uint16_t mtu);


/**
	* Enable/Disable hardware filtering by an Ethernet device of received
	* VLAN packets tagged with a given VLAN Tag Identifier.
	* @param port_id
	* @param vlan_id
	* @param on
	* @return
	*/
int rte_eth_dev_vlan_filter(uint8_t port_id, uint16_t vlan_id, int on);


/**
	* Enable/Disable hardware VLAN Strip by a rx queue of an Ethernet device.
	* 82599/X540/X550 can support VLAN stripping at the rx queue level
	* @param port_id
	* @param rx_queue_id
	* @param on
	* @return
	*/
int rte_eth_dev_set_vlan_strip_on_queue(uint8_t port_id, uint16_t rx_queue_id,
		int on);


/**
	* Set the Outer VLAN Ether Type by an Ethernet device, it can be inserted to
	* the VLAN Header. This is a register setup available on some Intel NIC, not
	* but all, please check the data sheet for availability.
	* @param port_id
	* @param vlan_type
	* @param tag_type
	* @return
	*/
int rte_eth_dev_set_vlan_ether_type(uint8_t port_id,
						  enum rte_vlan_type vlan_type,
						  uint16_t tag_type);


/**
	* Set VLAN offload configuration on an Ethernet device
	* Enable/Disable Extended VLAN by an Ethernet device, This is a register setup
	* available on some Intel NIC, not but all, please check the data sheet for
	* availability.
	* Enable/Disable VLAN Strip can be done on rx queue for certain NIC, but here
	* the configuration is applied on the port level.
	* @param port_id
	* @param offload_mask
	* @return
	*/
int rte_eth_dev_set_vlan_offload(uint8_t port_id, int offload_mask);


/**
	* Read VLAN Offload configuration from an Ethernet device
	* @param port_id
	* @return
	*/
int rte_eth_dev_get_vlan_offload(uint8_t port_id);


/**
	* Set port based TX VLAN insersion on or off.
	* @param port_id
	*  The port identifier of the Ethernet device.
	* @param pvid
	*  Port based TX VLAN identifier togeth with user priority.
	* @param on
	*  Turn on or off the port based TX VLAN insertion.
	* @return
	*/
int rte_eth_dev_set_vlan_pvid(uint8_t port_id, uint16_t pvid, int on);


/**
	* Retrieve a burst of input packets from a receive queue of an Ethernet
	* device. The retrieved packets are stored in *rte_mbuf* structures whose
	* pointers are supplied in the *rx_pkts* array.
	* The rte_eth_rx_burst() function loops, parsing the RX ring of the
	* receive queue, up to *nb_pkts* packets, and for each completed RX
	* descriptor in the ring, it performs the following operations:
	* - Initialize the *rte_mbuf* data structure associated with the
	* - Store the *rte_mbuf* data structure into the next entry of the
	* - Replenish the RX descriptor with a new *rte_mbuf* buffer
	* When retrieving an input packet that was scattered by the controller
	* into multiple receive descriptors, the rte_eth_rx_burst() function
	* appends the associated *rte_mbuf* buffers to the first buffer of the
	* packet.
	* The rte_eth_rx_burst() function returns the number of packets
	* actually retrieved, which is the number of *rte_mbuf* data structures
	* effectively supplied into the *rx_pkts* array.
	* A return value equal to *nb_pkts* indicates that the RX queue contained
	* at least *rx_pkts* packets, and this is likely to signify that other
	* received packets remain in the input queue. Applications implementing
	* a "retrieve as much received packets as possible" policy can check this
	* specific case and keep invoking the rte_eth_rx_burst() function until
	* a value less than *nb_pkts* is returned.
	* This receive method has the following advantages:
	* - It allows a run-to-completion network stack engine to retrieve and
	* - Conversely, it also allows an asynchronous-oriented processing
	* - It allows the rte_eth_rx_burst() function of the driver to take
	* To summarize, the proposed receive API enables many
	* burst-oriented optimizations in both synchronous and asynchronous
	* packet processing environments with no overhead in both cases.
	* The rte_eth_rx_burst() function does not provide any error
	* notification to avoid the corresponding overhead. As a hint, the
	* upper-level application might check the status of the device link once
	* being systematically returned a 0 value for a given number of tries.
	* @param port_id
	* @param queue_id
	* @param rx_pkts
	* @param nb_pkts
	* @return
	*/
static inline uint16_t
rte_eth_rx_burst(uint8_t port_id, uint16_t queue_id,
			struct rte_mbuf **rx_pkts, const uint16_t nb_pkts)
{
	struct rte_eth_dev *dev = &rte_eth_devices[port_id];
	int16_t nb_rx = (*dev->rx_pkt_burst)(dev->data->rx_queues[queue_id],
			rx_pkts, nb_pkts);
	struct rte_eth_rxtx_callback *cb = dev->post_rx_burst_cbs[queue_id];
	if (__builtin_expect((cb != NULL),0))
{
		do
{
			nb_rx = cb->fn.rx(port_id, queue_id, rx_pkts, nb_rx,
						nb_pkts, cb->param);
			cb = cb->next;
		} while (cb != NULL);
	}
	return nb_rx;
}


/**
	* Get the number of used descriptors in a specific queue
	* @param port_id
	*  The port identifier of the Ethernet device.
	* @param queue_id
	*  The queue id on the specific port.
	* @return
	*  The number of used descriptors in the specific queue, or:
	*/
static inline int
rte_eth_rx_queue_count(uint8_t port_id, uint16_t queue_id)
{
	struct rte_eth_dev *dev = &rte_eth_devices[port_id];
	do { if (!rte_eth_dev_is_valid_port(port_id)) { ; return -EINVAL; } } while (0);
	do { if ((*dev->dev_ops->rx_queue_count) == NULL) { ; return -ENOTSUP; } } while (0);
						  return (*dev->dev_ops->rx_queue_count)(dev, queue_id);
}


/**
	* Check if the DD bit of the specific RX descriptor in the queue has been set
	* @param port_id
	*  The port identifier of the Ethernet device.
	* @param queue_id
	*  The queue id on the specific port.
	* @param offset
	*  The offset of the descriptor ID from tail.
	* @return
	*  - (1) if the specific DD bit is set.
	*  - (0) if the specific DD bit is not set.
	*  - (-ENODEV) if *port_id* invalid.
	*  - (-ENOTSUP) if the device does not support this function
	*/
static inline int
rte_eth_rx_descriptor_done(uint8_t port_id, uint16_t queue_id, uint16_t offset)
{
	struct rte_eth_dev *dev = &rte_eth_devices[port_id];
	do { if (!rte_eth_dev_is_valid_port(port_id)) { ; return -ENODEV; } } while (0);
	do { if ((*dev->dev_ops->rx_descriptor_done) == NULL) { ; return -ENOTSUP; } } while (0);
	return (*dev->dev_ops->rx_descriptor_done)( dev->data->rx_queues[queue_id], offset);
}


/**
	* Send a burst of output packets on a transmit queue of an Ethernet device.
	* The rte_eth_tx_burst() function is invoked to transmit output packets
	* on the output queue *queue_id* of the Ethernet device designated by its
	* *port_id*.
	* The *nb_pkts* parameter is the number of packets to send which are
	* supplied in the *tx_pkts* array of *rte_mbuf* structures, each of them
	* allocated from a pool created with rte_pktmbuf_pool_create().
	* The rte_eth_tx_burst() function loops, sending *nb_pkts* packets,
	* up to the number of transmit descriptors available in the TX ring of the
	* transmit queue.
	* For each packet to send, the rte_eth_tx_burst() function performs
	* the following operations:
	* - Pick up the next available descriptor in the transmit ring.
	* - Free the network buffer previously sent with that descriptor, if any.
	* - Initialize the transmit descriptor with the information provided
	* In the case of a segmented packet composed of a list of *rte_mbuf* buffers,
	* the rte_eth_tx_burst() function uses several transmit descriptors
	* of the ring.
	* The rte_eth_tx_burst() function returns the number of packets it
	* actually sent. A return value equal to *nb_pkts* means that all packets
	* have been sent, and this is likely to signify that other output packets
	* could be immediately transmitted again. Applications that implement a
	* "send as many packets to transmit as possible" policy can check this
	* specific case and keep invoking the rte_eth_tx_burst() function until
	* a value less than *nb_pkts* is returned.
	* It is the responsibility of the rte_eth_tx_burst() function to
	* transparently free the memory buffers of packets previously sent.
	* This feature is driven by the *tx_free_thresh* value supplied to the
	* rte_eth_dev_configure() function at device configuration time.
	* When the number of free TX descriptors drops below this threshold, the
	* rte_eth_tx_burst() function must [attempt to] free the *rte_mbuf*  buffers
	* of those packets whose transmission was effectively completed.
	* @param port_id
	* @param queue_id
	* @param tx_pkts
	* @param nb_pkts
	* @return
	*/
static inline uint16_t
rte_eth_tx_burst(uint8_t port_id, uint16_t queue_id,
			struct rte_mbuf **tx_pkts, uint16_t nb_pkts)
{
	struct rte_eth_dev *dev = &rte_eth_devices[port_id];
	struct rte_eth_rxtx_callback *cb = dev->pre_tx_burst_cbs[queue_id];
	if (__builtin_expect((cb != NULL),0))
{
		do
{
			nb_pkts = cb->fn.tx(port_id, queue_id, tx_pkts, nb_pkts,
					cb->param);
			cb = cb->next;
		} while (cb != NULL);
	}
	return (*dev->tx_pkt_burst)(dev->data->tx_queues[queue_id], tx_pkts, nb_pkts);
}
typedef void (*buffer_tx_error_fn)(struct rte_mbuf **unsent, uint16_t count,
		void *userdata);


/**
	* Structure used to buffer packets for future TX
	* Used by APIs rte_eth_tx_buffer and rte_eth_tx_buffer_flush
	*/
struct rte_eth_dev_tx_buffer
{
	buffer_tx_error_fn error_callback;
	void *error_userdata;
	uint16_t size; 


	uint16_t length; 


	struct rte_mbuf *pkts[];


};


/**
	* Calculate the size of the tx buffer.
	* @param sz
	*/


/**
	* Initialize default values for buffered transmitting
	* @param buffer
	* @param size
	* @return
	*/
int
rte_eth_tx_buffer_init(struct rte_eth_dev_tx_buffer *buffer, uint16_t size);


/**
	* Send any packets queued up for transmission on a port and HW queue
	* This causes an explicit flush of packets previously buffered via the
	* rte_eth_tx_buffer() function. It returns the number of packets successfully
	* sent to the NIC, and calls the error callback for any unsent packets. Unless
	* explicitly set up otherwise, the default callback simply frees the unsent
	* packets back to the owning mempool.
	* @param port_id
	* @param queue_id
	* @param buffer
	* @return
	*/
static inline uint16_t
rte_eth_tx_buffer_flush(uint8_t port_id, uint16_t queue_id,
		struct rte_eth_dev_tx_buffer *buffer)
{
	uint16_t sent;
	uint16_t to_send = buffer->length;
	if (to_send == 0)
		return 0;
	sent = rte_eth_tx_burst(port_id, queue_id, buffer->pkts, to_send);
	buffer->length = 0;


	if (__builtin_expect((sent != to_send),0))
		buffer->error_callback(&buffer->pkts[sent], to_send - sent,
				buffer->error_userdata);
	return sent;
}


/**
	* Buffer a single packet for future transmission on a port and queue
	* This function takes a single mbuf/packet and buffers it for later
	* transmission on the particular port and queue specified. Once the buffer is
	* full of packets, an attempt will be made to transmit all the buffered
	* packets. In case of error, where not all packets can be transmitted, a
	* callback is called with the unsent packets as a parameter. If no callback
	* is explicitly set up, the unsent packets are just freed back to the owning
	* mempool. The function returns the number of packets actually sent i.e.
	* 0 if no buffer flush occurred, otherwise the number of packets successfully
	* flushed
	* @param port_id
	* @param queue_id
	* @param buffer
	* @param tx_pkt
	* @return
	*/
static inline uint16_t __attribute__((always_inline))
rte_eth_tx_buffer(uint8_t port_id, uint16_t queue_id,
		struct rte_eth_dev_tx_buffer *buffer, struct rte_mbuf *tx_pkt)
{
	buffer->pkts[buffer->length++] = tx_pkt;
	if (buffer->length < buffer->size)
		return 0;
	return rte_eth_tx_buffer_flush(port_id, queue_id, buffer);
}


/**
	* Configure a callback for buffered packets which cannot be sent
	* Register a specific callback to be called when an attempt is made to send
	* all packets buffered on an ethernet port, but not all packets can
	* successfully be sent. The callback registered here will be called only
	* from calls to rte_eth_tx_buffer() and rte_eth_tx_buffer_flush() APIs.
	* The default callback configured for each queue by default just frees the
	* packets back to the calling mempool. If additional behaviour is required,
	* for example, to count dropped packets, or to retry transmission of packets
	* which cannot be sent, this function should be used to register a suitable
	* callback function to implement the desired behaviour.
	* The example callback "rte_eth_count_unsent_packet_callback()" is also
	* provided as reference.
	* @param buffer
	* @param callback
	* @param userdata
	* @return
	*/
int
rte_eth_tx_buffer_set_err_callback(struct rte_eth_dev_tx_buffer *buffer,
		buffer_tx_error_fn callback, void *userdata);


/**
	* Callback function for silently dropping unsent buffered packets.
	* This function can be passed to rte_eth_tx_buffer_set_err_callback() to
	* adjust the default behavior when buffered packets cannot be sent. This
	* function drops any unsent packets silently and is used by tx buffered
	* operations as default behavior.
	* NOTE: this function should not be called directly, instead it should be used
	* NOTE: when configuring this function as a callback with
	* @param pkts
	* @param unsent
	* @param userdata
	*/
void
rte_eth_tx_buffer_drop_callback(struct rte_mbuf **pkts, uint16_t unsent,
		void *userdata);


/**
	* Callback function for tracking unsent buffered packets.
	* This function can be passed to rte_eth_tx_buffer_set_err_callback() to
	* adjust the default behavior when buffered packets cannot be sent. This
	* function drops any unsent packets, but also updates a user-supplied counter
	* to track the overall number of packets dropped. The counter should be an
	* uint64_t variable.
	* NOTE: this function should not be called directly, instead it should be used
	* NOTE: when configuring this function as a callback with
	* @param pkts
	* @param unsent
	* @param userdata
	*/
void
rte_eth_tx_buffer_count_callback(struct rte_mbuf **pkts, uint16_t unsent,
		void *userdata);


/**
	* The eth device event type for interrupt, and maybe others in the future.
	*/
enum rte_eth_event_type
{
	RTE_ETH_EVENT_UNKNOWN, 


	RTE_ETH_EVENT_INTR_LSC, 


	RTE_ETH_EVENT_QUEUE_STATE,


	RTE_ETH_EVENT_INTR_RESET,


	RTE_ETH_EVENT_MAX 


};
typedef void (*rte_eth_dev_cb_fn)(uint8_t port_id, enum rte_eth_event_type event, void *cb_arg);





/**
	* Register a callback function for specific port id.
	* @param port_id
	*  Port id.
	* @param event
	*  Event interested.
	* @param cb_fn
	*  User supplied callback function to be called.
	* @param cb_arg
	*  Pointer to the parameters for the registered callback.
	* @return
	*  - On success, zero.
	*  - On failure, a negative value.
	*/
int rte_eth_dev_callback_register(uint8_t port_id,
			enum rte_eth_event_type event,
		rte_eth_dev_cb_fn cb_fn, void *cb_arg);


/**
	* Unregister a callback function for specific port id.
	* @param port_id
	*  Port id.
	* @param event
	*  Event interested.
	* @param cb_fn
	*  User supplied callback function to be called.
	* @param cb_arg
	*  Pointer to the parameters for the registered callback. -1 means to
	*  remove all for the same callback address and same event.
	* @return
	*  - On success, zero.
	*  - On failure, a negative value.
	*/
int rte_eth_dev_callback_unregister(uint8_t port_id,
			enum rte_eth_event_type event,
		rte_eth_dev_cb_fn cb_fn, void *cb_arg);


/**
	* @internal Executes all the user application registered callbacks for
	* the specific device. It is for DPDK internal user only. User
	* application should not call it directly.
	* @param dev
	*  Pointer to struct rte_eth_dev.
	* @param event
	*  Eth device interrupt event type.
	* @return
	*  void
	*/
void _rte_eth_dev_callback_process(struct rte_eth_dev *dev,
				enum rte_eth_event_type event);


/**
	* When there is no rx packet coming in Rx Queue for a long time, we can
	* sleep lcore related to RX Queue for power saving, and enable rx interrupt
	* to be triggered when rx packect arrives.
	* The rte_eth_dev_rx_intr_enable() function enables rx queue
	* interrupt on specific rx queue of a port.
	* @param port_id
	* @param queue_id
	* @return
	*/
int rte_eth_dev_rx_intr_enable(uint8_t port_id, uint16_t queue_id);


/**
	* When lcore wakes up from rx interrupt indicating packet coming, disable rx
	* interrupt and returns to polling mode.
	* The rte_eth_dev_rx_intr_disable() function disables rx queue
	* interrupt on specific rx queue of a port.
	* @param port_id
	* @param queue_id
	* @return
	*/
int rte_eth_dev_rx_intr_disable(uint8_t port_id, uint16_t queue_id);


/**
	* RX Interrupt control per port.
	* @param port_id
	* @param epfd
	* @param op
	* @param data
	* @return
	*/
int rte_eth_dev_rx_intr_ctl(uint8_t port_id, int epfd, int op, void *data);


/**
	* RX Interrupt control per queue.
	* @param port_id
	* @param queue_id
	* @param epfd
	* @param op
	* @param data
	* @return
	*/
int rte_eth_dev_rx_intr_ctl_q(uint8_t port_id, uint16_t queue_id,
						   int epfd, int op, void *data);


/**
	* Turn on the LED on the Ethernet device.
	* This function turns on the LED on the Ethernet device.
	* @param port_id
	* @return
	*/
int rte_eth_led_on(uint8_t port_id);


/**
	* Turn off the LED on the Ethernet device.
	* This function turns off the LED on the Ethernet device.
	* @param port_id
	* @return
	*/
int rte_eth_led_off(uint8_t port_id);


/**
	* Get current status of the Ethernet link flow control for Ethernet device
	* @param port_id
	* @param fc_conf
	* @return
	*/
int rte_eth_dev_flow_ctrl_get(uint8_t port_id,
						   struct rte_eth_fc_conf *fc_conf);


/**
	* Configure the Ethernet link flow control for Ethernet device
	* @param port_id
	* @param fc_conf
	* @return
	*/
int rte_eth_dev_flow_ctrl_set(uint8_t port_id,
						   struct rte_eth_fc_conf *fc_conf);


/**
	* Configure the Ethernet priority flow control under DCB environment
	* for Ethernet device.
	* @param port_id
	* The port identifier of the Ethernet device.
	* @param pfc_conf
	* The pointer to the structure of the priority flow control parameters.
	* @return
	*/
int rte_eth_dev_priority_flow_ctrl_set(uint8_t port_id,
				struct rte_eth_pfc_conf *pfc_conf);


/**
	* Add a MAC address to an internal array of addresses used to enable whitelist
	* filtering to accept packets only if the destination MAC address matches.
	* @param port
	* @param mac_addr
	* @param pool
	* @return
	*/
int rte_eth_dev_mac_addr_add(uint8_t port, struct ether_addr *mac_addr,
				uint32_t pool);


/**
	* Remove a MAC address from the internal array of addresses.
	* @param port
	* @param mac_addr
	* @return
	*/
int rte_eth_dev_mac_addr_remove(uint8_t port, struct ether_addr *mac_addr);


/**
	* Set the default MAC address.
	* @param port
	* @param mac_addr
	* @return
	*/
int rte_eth_dev_default_mac_addr_set(uint8_t port, struct ether_addr *mac_addr);


/**
	* Update Redirection Table(RETA) of Receive Side Scaling of Ethernet device.
	* @param port
	* @param reta_conf
	* @param reta_size
	* @return
	*/
int rte_eth_dev_rss_reta_update(uint8_t port,
				struct rte_eth_rss_reta_entry64 *reta_conf,
				uint16_t reta_size);

/**
	* Query Redirection Table(RETA) of Receive Side Scaling of Ethernet device.
	* @param port
	* @param reta_conf
	* @param reta_size
	* @return
	*/
int rte_eth_dev_rss_reta_query(uint8_t port,
						    struct rte_eth_rss_reta_entry64 *reta_conf,
						    uint16_t reta_size);

/**
	* Updates unicast hash table for receiving packet with the given destination
	* MAC address, and the packet is routed to all VFs for which the RX mode is
	* accept packets that match the unicast hash table.
	* @param port
	* @param addr
	* @param on
	* @return
		*  - (-ENODEV) if *port_id* invalid.
	*/
int rte_eth_dev_uc_hash_table_set(uint8_t port,struct ether_addr *addr,
					uint8_t on);

/**
	* Updates all unicast hash bitmaps for receiving packet with any Unicast
	* Ethernet MAC addresses,the packet is routed to all VFs for which the RX
	* mode is accept packets that match the unicast hash table.
	* @param port
	* @param on
	* @return
		*  - (-ENODEV) if *port_id* invalid.
	*/
int rte_eth_dev_uc_all_hash_table_set(uint8_t port,uint8_t on);

/**
	* Set RX L2 Filtering mode of a VF of an Ethernet device.
	* @param port
	* @param vf
	* @param rx_mode
	* @param on
	* @return
	*/
int rte_eth_dev_set_vf_rxmode(uint8_t port, uint16_t vf, uint16_t rx_mode,
				uint8_t on);


/**
* Enable or disable a VF traffic transmit of the Ethernet device.
*
* @param port
*   The port identifier of the Ethernet device.
* @param vf
*   VF id.
* @param on
*    1 - Enable a VF traffic transmit.
*    0 - Disable a VF traffic transmit.
* @return
*   - (0) if successful.
*   - (-ENODEV) if *port_id* invalid.
*   - (-ENOTSUP) if hardware doesn't support.
*   - (-EINVAL) if bad parameter.
*/
int
rte_eth_dev_set_vf_tx(uint8_t port,uint16_t vf, uint8_t on);


/**
* Enable or disable a VF traffic receive of an Ethernet device.
*
* @param port
*   The port identifier of the Ethernet device.
* @param vf
*   VF id.
* @param on
*    1 - Enable a VF traffic receive.
*    0 - Disable a VF traffic receive.
* @return
*   - (0) if successful.
*   - (-ENOTSUP) if hardware doesn't support.
*   - (-ENODEV) if *port_id* invalid.
*   - (-EINVAL) if bad parameter.
*/
int
rte_eth_dev_set_vf_rx(uint8_t port,uint16_t vf, uint8_t on);


/**
* Enable/Disable hardware VF VLAN filtering by an Ethernet device of
* received VLAN packets tagged with a given VLAN Tag Identifier.
*
* @param port id
*   The port identifier of the Ethernet device.
* @param vlan_id
*   The VLAN Tag Identifier whose filtering must be enabled or disabled.
* @param vf_mask
*    Bitmap listing which VFs participate in the VLAN filtering.
* @param vlan_on
*    1 - Enable VFs VLAN filtering.
*    0 - Disable VFs VLAN filtering.
* @return
*   - (0) if successful.
*   - (-ENOTSUP) if hardware doesn't support.
*   - (-ENODEV) if *port_id* invalid.
*   - (-EINVAL) if bad parameter.
*/
int
rte_eth_dev_set_vf_vlan_filter(uint8_t port, uint16_t vlan_id,
				uint64_t vf_mask,
				uint8_t vlan_on);


/**
	* Set a traffic mirroring rule on an Ethernet device
	* @param port_id
	* @param mirror_conf
	* @param rule_id
	* @param on
	* @return
	*/
int rte_eth_mirror_rule_set(uint8_t port_id,
			struct rte_eth_mirror_conf *mirror_conf,
			uint8_t rule_id,
			uint8_t on);


/**
	* Reset a traffic mirroring rule on an Ethernet device.
	* @param port_id
	* @param rule_id
	* @return
	*/
int rte_eth_mirror_rule_reset(uint8_t port_id,
						uint8_t rule_id);


/**
	* Set the rate limitation for a queue on an Ethernet device.
	* @param port_id
	* @param queue_idx
	* @param tx_rate
	* @return
	*/
int rte_eth_set_queue_rate_limit(uint8_t port_id, uint16_t queue_idx,
			uint16_t tx_rate);


/**
	* Set the rate limitation for a vf on an Ethernet device.
	* @param port_id
	* @param vf
	* @param tx_rate
	* @param q_msk
	* @return
	*/
int rte_eth_set_vf_rate_limit(uint8_t port_id, uint16_t vf,
			uint16_t tx_rate, uint64_t q_msk);


/**
	* Initialize bypass logic. This function needs to be called before
	* executing any other bypass API.
	* @param port
	* @return
	*/
int rte_eth_dev_bypass_init(uint8_t port);


/**
	* Return bypass state.
	* @param port
	* @param state
	* @return
	*/
int rte_eth_dev_bypass_state_show(uint8_t port, uint32_t *state);


/**
	* Set bypass state
	* @param port
	* @param new_state
	* @return
	*/
int rte_eth_dev_bypass_state_set(uint8_t port, uint32_t *new_state);


/**
	* Return bypass state when given event occurs.
	* @param port
	* @param event
	* @param state
	* @return
	*/
int rte_eth_dev_bypass_event_show(uint8_t port, uint32_t event, uint32_t *state);


/**
	* Set bypass state when given event occurs.
	* @param port
	* @param event
	* @param state
	* @return
	*/
int rte_eth_dev_bypass_event_store(uint8_t port, uint32_t event, uint32_t state);


/**
	* Set bypass watchdog timeout count.
	* @param port
	* @param timeout
	* @return
	*/
int rte_eth_dev_wd_timeout_store(uint8_t port, uint32_t timeout);


/**
	* Get bypass firmware version.
	* @param port
	* @param ver
	* @return
	*/
int rte_eth_dev_bypass_ver_show(uint8_t port, uint32_t *ver);


/**
	* Return bypass watchdog timeout in seconds
	* @param port
	* @param wd_timeout
	* @return
	*/
int rte_eth_dev_bypass_wd_timeout_show(uint8_t port, uint32_t *wd_timeout);


/**
	* Reset bypass watchdog timer
	* @param port
	* @return
	*/
int rte_eth_dev_bypass_wd_reset(uint8_t port);

/**
	* Configuration of Receive Side Scaling hash computation of Ethernet device.
	* @param port_id
	* @param rss_conf
	* @return
	*/
int rte_eth_dev_rss_hash_update(uint8_t port_id,
				struct rte_eth_rss_conf *rss_conf);

/**
	* Retrieve current configuration of Receive Side Scaling hash computation
	* of Ethernet device.
	* @param port_id
	* @param rss_conf
	* @return
	*/
int
rte_eth_dev_rss_hash_conf_get(uint8_t port_id,
						   struct rte_eth_rss_conf *rss_conf);

/**
	* Add UDP tunneling port for a specific type of tunnel.
	* The packets with this UDP port will be identified as this type of tunnel.
	* Before enabling any offloading function for a tunnel, users can call this API
	* to change or add more UDP port for the tunnel. So the offloading function
	* can take effect on the packets with the sepcific UDP port.
	* @param port_id
	* @param tunnel_udp
	* @return
	*/
int
rte_eth_dev_udp_tunnel_port_add(uint8_t port_id,
				struct rte_eth_udp_tunnel *tunnel_udp);

/**
	* Delete UDP tunneling port a specific type of tunnel.
	* The packets with this UDP port will not be identified as this type of tunnel
	* any more.
	* Before enabling any offloading function for a tunnel, users can call this API
	* to delete a UDP port for the tunnel. So the offloading function will not take
	* effect on the packets with the sepcific UDP port.
	* @param port_id
	* @param tunnel_udp
	* @return
	*/
int
rte_eth_dev_udp_tunnel_port_delete(uint8_t port_id,
						 struct rte_eth_udp_tunnel *tunnel_udp);


/**
	* Check whether the filter type is supported on an Ethernet device.
	* All the supported filter types are defined in 'rte_eth_ctrl.h'.
	* @param port_id
	* @param filter_type
	* @return
	*/
int rte_eth_dev_filter_supported(uint8_t port_id, enum rte_filter_type filter_type);


/**
	* Take operations to assigned filter type on an Ethernet device.
	* All the supported operations and filter types are defined in 'rte_eth_ctrl.h'.
	* @param port_id
	* @param filter_type
	* @param filter_op
	* @param arg
	* @return
	*/
int rte_eth_dev_filter_ctrl(uint8_t port_id, enum rte_filter_type filter_type,
			enum rte_filter_op filter_op, void *arg);


/**
	* Get DCB information on an Ethernet device.
	* @param port_id
	* @param dcb_info
	* @return
	*/
int rte_eth_dev_get_dcb_info(uint8_t port_id,
						  struct rte_eth_dcb_info *dcb_info);


/**
	* Add a callback to be called on packet RX on a given port and queue.
	* This API configures a function to be called for each burst of
	* packets received on a given NIC port queue. The return value is a pointer
	* that can be used to later remove the callback using
	* rte_eth_remove_rx_callback().
	* Multiple functions are called in the order that they are added.
	* @param port_id
	* @param queue_id
	* @param fn
	* @param user_param
	* @return
	*/
void *rte_eth_add_rx_callback(uint8_t port_id, uint16_t queue_id,
		rte_rx_callback_fn fn, void *user_param);


/*
* Add a callback that must be called first on packet RX on a given port
* and queue.
*
* This API configures a first function to be called for each burst of
* packets received on a given NIC port queue. The return value is a pointer
* that can be used to later remove the callback using
* rte_eth_remove_rx_callback().
*
* Multiple functions are called in the order that they are added.
*
* @param port_id
*   The port identifier of the Ethernet device.
* @param queue_id
*   The queue on the Ethernet device on which the callback is to be added.
* @param fn
*   The callback function
* @param user_param
*   A generic pointer parameter which will be passed to each invocation of the
*   callback function on this port and queue.
*
* @return
*   NULL on error.
*   On success, a pointer value which can later be used to remove the callback.
*/
void *rte_eth_add_first_rx_callback(uint8_t port_id, uint16_t queue_id,
		rte_rx_callback_fn fn, void *user_param);


/**
	* Add a callback to be called on packet TX on a given port and queue.
	* This API configures a function to be called for each burst of
	* packets sent on a given NIC port queue. The return value is a pointer
	* that can be used to later remove the callback using
	* rte_eth_remove_tx_callback().
	* Multiple functions are called in the order that they are added.
	* @param port_id
	* @param queue_id
	* @param fn
	* @param user_param
	* @return
	*/
void *rte_eth_add_tx_callback(uint8_t port_id, uint16_t queue_id,
		rte_tx_callback_fn fn, void *user_param);


/**
	* Remove an RX packet callback from a given port and queue.
	* This function is used to removed callbacks that were added to a NIC port
	* queue using rte_eth_add_rx_callback().
	* Note: the callback is removed from the callback list but it isn't freed
	* since the it may still be in use. The memory for the callback can be
	* subsequently freed back by the application by calling rte_free():
	* - Immediately - if the port is stopped, or the user knows that no
	* - After a short delay - where the delay is sufficient to allow any
	* @param port_id
	* @param queue_id
	* @param user_cb
	* @return
	*/
int rte_eth_remove_rx_callback(uint8_t port_id, uint16_t queue_id,
		struct rte_eth_rxtx_callback *user_cb);


/**
	* Remove a TX packet callback from a given port and queue.
	* This function is used to removed callbacks that were added to a NIC port
	* queue using rte_eth_add_tx_callback().
	* Note: the callback is removed from the callback list but it isn't freed
	* since the it may still be in use. The memory for the callback can be
	* subsequently freed back by the application by calling rte_free():
	* - Immediately - if the port is stopped, or the user knows that no
	* - After a short delay - where the delay is sufficient to allow any
	* @param port_id
	* @param queue_id
	* @param user_cb
	* @return
	*/
int rte_eth_remove_tx_callback(uint8_t port_id, uint16_t queue_id,
		struct rte_eth_rxtx_callback *user_cb);


/**
	* Retrieve information about given port's RX queue.
	* @param port_id
	* @param queue_id
	* @param qinfo
	* @return
	*/
int rte_eth_rx_queue_info_get(uint8_t port_id, uint16_t queue_id,
	struct rte_eth_rxq_info *qinfo);


/**
	* Retrieve information about given port's TX queue.
	* @param port_id
	* @param queue_id
	* @param qinfo
	* @return
	*/
int rte_eth_tx_queue_info_get(uint8_t port_id, uint16_t queue_id,
	struct rte_eth_txq_info *qinfo);


/**
	* Retrieve device registers and register attributes (number of registers and
	* register size)
	* @param port_id
	* @param info
	* @return
	*/
int rte_eth_dev_get_reg_info(uint8_t port_id, struct rte_dev_reg_info *info);


/**
	* Retrieve size of device EEPROM
	* @param port_id
	* @return
	*/
int rte_eth_dev_get_eeprom_length(uint8_t port_id);


/**
	* Retrieve EEPROM and EEPROM attribute
	* @param port_id
	* @param info
	* @return
	*/
int rte_eth_dev_get_eeprom(uint8_t port_id, struct rte_dev_eeprom_info *info);


/**
	* Program EEPROM with provided data
	* @param port_id
	* @param info
	* @return
	*/
int rte_eth_dev_set_eeprom(uint8_t port_id, struct rte_dev_eeprom_info *info);


/**
	* Set the list of multicast addresses to filter on an Ethernet device.
	* @param port_id
	* @param mc_addr_set
	* @param nb_mc_addr
	* @return
	*/
int rte_eth_dev_set_mc_addr_list(uint8_t port_id,
					struct ether_addr *mc_addr_set,
					uint32_t nb_mc_addr);


/**
	* Enable IEEE1588/802.1AS timestamping for an Ethernet device.
	* @param port_id
	* @return
	*/
int rte_eth_timesync_enable(uint8_t port_id);


/**
	* Disable IEEE1588/802.1AS timestamping for an Ethernet device.
	* @param port_id
	* @return
	*/
int rte_eth_timesync_disable(uint8_t port_id);


/**
	* Read an IEEE1588/802.1AS RX timestamp from an Ethernet device.
	* @param port_id
	* @param timestamp
	* @param flags
	* @return
	*/
int rte_eth_timesync_read_rx_timestamp(uint8_t port_id,
		struct timespec *timestamp, uint32_t flags);


/**
	* Read an IEEE1588/802.1AS TX timestamp from an Ethernet device.
	* @param port_id
	* @param timestamp
	* @return
	*/
int rte_eth_timesync_read_tx_timestamp(uint8_t port_id,
		struct timespec *timestamp);


/**
	* Adjust the timesync clock on an Ethernet device.
	* This is usually used in conjunction with other Ethdev timesync functions to
	* synchronize the device time using the IEEE1588/802.1AS protocol.
	* @param port_id
	* @param delta
	* @return
	*/
int rte_eth_timesync_adjust_time(uint8_t port_id, int64_t delta);


/**
	* Read the time from the timesync clock on an Ethernet device.
	* This is usually used in conjunction with other Ethdev timesync functions to
	* synchronize the device time using the IEEE1588/802.1AS protocol.
	* @param port_id
	* @param time
	* @return
	*/
int rte_eth_timesync_read_time(uint8_t port_id, struct timespec *time);


/**
	* Set the time of the timesync clock on an Ethernet device.
	* This is usually used in conjunction with other Ethdev timesync functions to
	* synchronize the device time using the IEEE1588/802.1AS protocol.
	* @param port_id
	* @param time
	* @return
	*/
int rte_eth_timesync_write_time(uint8_t port_id, const struct timespec *time);


/**
	* Copy pci device info to the Ethernet device data.
	* @param eth_dev
	* The *eth_dev* pointer is the address of the *rte_eth_dev* structure.
	* @param pci_dev
	* The *pci_dev* pointer is the address of the *rte_pci_device* structure.
	* @return
	*/
void rte_eth_copy_pci_info(struct rte_eth_dev *eth_dev,
		struct rte_pci_device *pci_dev);


/**
	* Create memzone for HW rings.
	* malloc can't be used as the physical address is needed.
	* If the memzone is already created, then this function returns a ptr
	* to the old one.
	* @param eth_dev
	* @param name
	* @param queue_id
	* @param size
	* @param align
	* @param socket_id
	*/
const struct rte_memzone *
rte_eth_dma_zone_reserve(const struct rte_eth_dev *eth_dev, const char *name,
				uint16_t queue_id, size_t size,
				unsigned align, int socket_id);


/**
	* Config l2 tunnel ether type of an Ethernet device for filtering specific
	* tunnel packets by ether type.
	* @param port_id
	* @param l2_tunnel
	* @return
	*/
int
rte_eth_dev_l2_tunnel_eth_type_conf(uint8_t port_id,
						  struct rte_eth_l2_tunnel_conf *l2_tunnel);


/**
	* Enable/disable l2 tunnel offload functions. Include,
	* 1, The ability of parsing a type of l2 tunnel of an Ethernet device.
	* 2, Stripping the l2 tunnel tag.
	* 3, Insertion of the l2 tunnel tag.
	* 4, Forwarding the packets based on the l2 tunnel tag.
	* @param port_id
	* @param l2_tunnel
	* @param mask
	* @param en
	* @return
	*/
int
rte_eth_dev_l2_tunnel_offload_set(uint8_t port_id,
						struct rte_eth_l2_tunnel_conf *l2_tunnel,
						uint32_t mask,
						uint8_t en);


/**
* Get the port id from pci adrress or device name
* Ex: 0000:2:00.0 or vdev name eth_pcap0
*
* @param name
*  pci address or name of the device
* @param port_id
*   pointer to port identifier of the device
* @return
*   - (0) if successful.
*   - (-ENODEV or -EINVAL) on failure.
*/
int
rte_eth_dev_get_port_by_name(const char *name, uint8_t *port_id);


/**
* Get the device name from port id
*
* @param port_id
*   pointer to port identifier of the device
* @param name
*  pci address or name of the device
* @return
*   - (0) if successful.
*   - (-EINVAL) on failure.
*/
int
rte_eth_dev_get_name_by_port(uint8_t port_id, char *name);


/*-
	*/


/*-
	*/


/**
	* @file
	* This is a hash table implementation for four byte keys (fbk).
	* Note that the return value of the add function should always be checked as,
	* if a bucket is full, the key is not added even if there is space in other
	* buckets. This keeps the lookup function very simple and therefore fast.
	*/


/*
	* Copyright (c) 1991, 1993
	*	The Regents of the University of California.  All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	*	@(#)queue.h	8.5 (Berkeley) 8/20/94
	*/


/*-
	*/


/**
	* @file
	* jhash functions.
	*/


/*-
	*/


/*-
	*/


/* jhash.h: Jenkins hash support.
	* Copyright (C) 2006 Bob Jenkins (bob_jenkins@burtleburtle.net)
	* http://burtleburtle.net/bob/hash/
	* These are the credits from Bob's sources:
	* lookup3.c, by Bob Jenkins, May 2006, Public Domain.
	* These are functions for producing 32-bit hashes for hash table lookup.
	* hashword(), hashlittle(), hashlittle2(), hashbig(), mix(), and final()
	* are externally useful functions.  Routines to test the hash are included
	* if SELF_TEST is defined.  You can use this free for any purpose.  It's in
	* the public domain.  It has no warranty.
	* $FreeBSD$
	*/






static inline void
__rte_jhash_2hashes(const void *key, uint32_t length, uint32_t *pc,
		uint32_t *pb, unsigned check_align)
{
	uint32_t a, b, c;


	a = b = c = 0xdeadbeef + ((uint32_t)length) + *pc;
	c += *pb;

/*
	 * Check key alignment. For x86 architecture, first case is always optimal
	 * If check_align is not set, first case will be used
	 */
	const uint32_t *k = (const uint32_t *)key;
	const uint32_t s = 0;
	if (!check_align || s == 0)
{
		while (length > 12)
{
			a += k[0];
			b += k[1];
			c += k[2];
			do { a -= c; a ^= (((c) << (4)) | ((c) >> (32-(4)))); c += b; b -= a; b ^= (((a) << (6)) | ((a) >> (32-(6)))); a += c; c -= b; c ^= (((b) << (8)) | ((b) >> (32-(8)))); b += a; a -= c; a ^= (((c) << (16)) | ((c) >> (32-(16)))); c += b; b -= a; b ^= (((a) << (19)) | ((a) >> (32-(19)))); a += c; c -= b; c ^= (((b) << (4)) | ((b) >> (32-(4)))); b += a; } while (0);
			k += 3;
			length -= 12;
		}
		switch (length)
{
		case 12:
			c += k[2]; b += k[1]; a += k[0]; break;
		case 11:
			c += k[2] & (0xffffff); b += k[1]; a += k[0]; break;
		case 10:
			c += k[2] & (0xffff); b += k[1]; a += k[0]; break;
		case 9:
			c += k[2] & (0xff); b += k[1]; a += k[0]; break;
		case 8:
			b += k[1]; a += k[0]; break;
		case 7:
			b += k[1] & (0xffffff); a += k[0]; break;
		case 6:
			b += k[1] & (0xffff); a += k[0]; break;
		case 5:
			b += k[1] & (0xff); a += k[0]; break;
		case 4:
			a += k[0]; break;
		case 3:
			a += k[0] & (0xffffff); break;
		case 2:
			a += k[0] & (0xffff); break;
		case 1:
			a += k[0] & (0xff); break;


		case 0:
			*pc = c;
			*pb = b;
			return;
		};
	} else
{


		while (length > 12)
{
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s))));
			b += (((k[1]) >> (s)) | ((uint64_t)(k[2]) << (32-(s))));
			c += (((k[2]) >> (s)) | ((uint64_t)(k[3]) << (32-(s))));
			do { a -= c; a ^= (((c) << (4)) | ((c) >> (32-(4)))); c += b; b -= a; b ^= (((a) << (6)) | ((a) >> (32-(6)))); a += c; c -= b; c ^= (((b) << (8)) | ((b) >> (32-(8)))); b += a; a -= c; a ^= (((c) << (16)) | ((c) >> (32-(16)))); c += b; b -= a; b ^= (((a) << (19)) | ((a) >> (32-(19)))); a += c; c -= b; c ^= (((b) << (4)) | ((b) >> (32-(4)))); b += a; } while (0);
			k += 3;
			length -= 12;
		}


		switch (length)
{
		case 12:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s))));
			b += (((k[1]) >> (s)) | ((uint64_t)(k[2]) << (32-(s))));
			c += (((k[2]) >> (s)) | ((uint64_t)(k[3]) << (32-(s))));
			break;
		case 11:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s))));
			b += (((k[1]) >> (s)) | ((uint64_t)(k[2]) << (32-(s))));
			c += (((k[2]) >> (s)) | ((uint64_t)(k[3]) << (32-(s)))) & (0xffffff);
			break;
		case 10:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s))));
			b += (((k[1]) >> (s)) | ((uint64_t)(k[2]) << (32-(s))));
			c += (((k[2]) >> (s)) | ((uint64_t)(k[3]) << (32-(s)))) & (0xffff);
			break;
		case 9:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s))));
			b += (((k[1]) >> (s)) | ((uint64_t)(k[2]) << (32-(s))));
			c += (((k[2]) >> (s)) | ((uint64_t)(k[3]) << (32-(s)))) & (0xff);
			break;
		case 8:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s))));
			b += (((k[1]) >> (s)) | ((uint64_t)(k[2]) << (32-(s))));
			break;
		case 7:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s))));
			b += (((k[1]) >> (s)) | ((uint64_t)(k[2]) << (32-(s)))) & (0xffffff);
			break;
		case 6:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s))));
			b += (((k[1]) >> (s)) | ((uint64_t)(k[2]) << (32-(s)))) & (0xffff);
			break;
		case 5:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s))));
			b += (((k[1]) >> (s)) | ((uint64_t)(k[2]) << (32-(s)))) & (0xff);
			break;
		case 4:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s))));
			break;
		case 3:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s)))) & (0xffffff);
			break;
		case 2:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s)))) & (0xffff);
			break;
		case 1:
			a += (((k[0]) >> (s)) | ((uint64_t)(k[1]) << (32-(s)))) & (0xff);
			break;


		case 0:
			*pc = c;
			*pb = b;
			return;
		}
	}
	do { c ^= b; c -= (((b) << (14)) | ((b) >> (32-(14)))); a ^= c; a -= (((c) << (11)) | ((c) >> (32-(11)))); b ^= a; b -= (((a) << (25)) | ((a) >> (32-(25)))); c ^= b; c -= (((b) << (16)) | ((b) >> (32-(16)))); a ^= c; a -= (((c) << (4)) | ((c) >> (32-(4)))); b ^= a; b -= (((a) << (14)) | ((a) >> (32-(14)))); c ^= b; c -= (((b) << (24)) | ((b) >> (32-(24)))); } while (0);
	*pc = c;
	*pb = b;
}


/**
	* Same as rte_jhash, but takes two seeds and return two uint32_ts.
	* pc and pb must be non-null, and *pc and *pb must both be initialized
	* with seeds. If you pass in (*pb)=0, the output (*pc) will be
	* the same as the return value from rte_jhash.
	* @param key
	* @param length
	* @param pc
	* @param pb
	*/
static inline void
rte_jhash_2hashes(const void *key, uint32_t length, uint32_t *pc, uint32_t *pb)
{
	__rte_jhash_2hashes(key, length, pc, pb, 1);
}


/**
	* Same as rte_jhash_32b, but takes two seeds and return two uint32_ts.
	* pc and pb must be non-null, and *pc and *pb must both be initialized
	* with seeds. If you pass in (*pb)=0, the output (*pc) will be
	* the same as the return value from rte_jhash_32b.
	* @param k
	* @param length
	* @param pc
	* @param pb
	*/
static inline void
rte_jhash_32b_2hashes(const uint32_t *k, uint32_t length, uint32_t *pc, uint32_t *pb)
{
	__rte_jhash_2hashes((const void *) k, (length << 2), pc, pb, 0);
}


/**
	* The most generic version, hashes an arbitrary sequence
	* of bytes.  No alignment or length assumptions are made about
	* the input key.
	* @param key
	* @param length
	* @param initval
	* @return
	*/
static inline uint32_t
rte_jhash(const void *key, uint32_t length, uint32_t initval)
{
	uint32_t initval2 = 0;
	rte_jhash_2hashes(key, length, &initval, &initval2);
	return initval;
}


/**
	* A special optimized version that handles 1 or more of uint32_ts.
	* The length parameter here is the number of uint32_ts in the key.
	* @param k
	* @param length
	* @param initval
	* @return
	*/
static inline uint32_t
rte_jhash_32b(const uint32_t *k, uint32_t length, uint32_t initval)
{
	uint32_t initval2 = 0;
	rte_jhash_32b_2hashes(k, length, &initval, &initval2);
	return initval;
}
static inline uint32_t
__rte_jhash_3words(uint32_t a, uint32_t b, uint32_t c, uint32_t initval)
{
	a += 0xdeadbeef + initval;
	b += 0xdeadbeef + initval;
	c += 0xdeadbeef + initval;
	do { c ^= b; c -= (((b) << (14)) | ((b) >> (32-(14)))); a ^= c; a -= (((c) << (11)) | ((c) >> (32-(11)))); b ^= a; b -= (((a) << (25)) | ((a) >> (32-(25)))); c ^= b; c -= (((b) << (16)) | ((b) >> (32-(16)))); a ^= c; a -= (((c) << (4)) | ((c) >> (32-(4)))); b ^= a; b -= (((a) << (14)) | ((a) >> (32-(14)))); c ^= b; c -= (((b) << (24)) | ((b) >> (32-(24)))); } while (0);
	return c;
}


/**
	* A special ultra-optimized versions that knows it is hashing exactly
	* 3 words.
	* @param a
	* @param b
	* @param c
	* @param initval
	* @return
	*/
static inline uint32_t
rte_jhash_3words(uint32_t a, uint32_t b, uint32_t c, uint32_t initval)
{
	return __rte_jhash_3words(a + 12, b + 12, c + 12, initval);
}


/**
	* A special ultra-optimized versions that knows it is hashing exactly
	* 2 words.
	* @param a
	* @param b
	* @param initval
	* @return
	*/
static inline uint32_t
rte_jhash_2words(uint32_t a, uint32_t b, uint32_t initval)
{
	return __rte_jhash_3words(a + 8, b + 8, 8, initval);
}


/**
	* A special ultra-optimized versions that knows it is hashing exactly
	* 1 word.
	* @param a
	* @param initval
	* @return
	*/
static inline uint32_t
rte_jhash_1word(uint32_t a, uint32_t initval)
{
	return __rte_jhash_3words(a + 4, 4, 4, initval);
}















typedef uint32_t (*rte_fbk_hash_fn)(uint32_t key, uint32_t init_val);



struct rte_fbk_hash_params
{
	const char *name; 


	uint32_t entries; 


	uint32_t entries_per_bucket; 


	int socket_id; 


	rte_fbk_hash_fn hash_func; 


	uint32_t init_val; 


};



union rte_fbk_hash_entry
{
	uint64_t whole_entry; 


	struct
{
		uint16_t is_entry; 


		uint16_t value; 


		uint32_t key; 


	} entry; 


};



struct rte_fbk_hash_table
{
	char name[32]; 


	uint32_t entries; 


	uint32_t entries_per_bucket; 


	uint32_t used_entries; 


	uint32_t bucket_mask; 


	uint32_t bucket_shift; 


	rte_fbk_hash_fn hash_func; 


	uint32_t init_val; 




	union rte_fbk_hash_entry t[];
};


/**
	* Find the offset into hash table of the bucket containing a particular key.
	* @param ht
	* @param key
	* @return
	*/
static inline uint32_t
rte_fbk_hash_get_bucket(const struct rte_fbk_hash_table *ht, uint32_t key)
{
	return (ht->hash_func(key, ht->init_val) & ht->bucket_mask) <<
			ht->bucket_shift;
}


/**
	* Add a key to an existing hash table with bucket id.
	* This operation is not multi-thread safe
	* and should only be called from one thread.
	* @param ht
	* @param key
	* @param value
	* @param bucket
	* @return
	*/
static inline int
rte_fbk_hash_add_key_with_bucket(struct rte_fbk_hash_table *ht,
			uint32_t key, uint16_t value, uint32_t bucket)
{

/*
	 * The writing of a new value to the hash table is done as a single
	 * 64bit operation. This should help prevent individual entries being
	 * corrupted due to race conditions, but it's still possible to
	 * overwrite entries that have just been made valid.
	 */
	const uint64_t new_entry = ((uint64_t)(key) << 32) |
			((uint64_t)(value) << 16) |
			1; 


	uint32_t i;
	for (i = 0; i < ht->entries_per_bucket; i++)
{


		if (! ht->t[bucket + i].entry.is_entry)
{
			ht->t[bucket + i].whole_entry = new_entry;
			ht->used_entries++;
			return 0;
		}


		if (ht->t[bucket + i].entry.key == key)
{
			ht->t[bucket + i].entry.value = value;
			return 0;
		}
	}
	return -ENOSPC; 


}


/**
	* Add a key to an existing hash table. This operation is not multi-thread safe
	* and should only be called from one thread.
	* @param ht
	* @param key
	* @param value
	* @return
	*/
static inline int
rte_fbk_hash_add_key(struct rte_fbk_hash_table *ht,
			uint32_t key, uint16_t value)
{
	return rte_fbk_hash_add_key_with_bucket(ht,
				key, value, rte_fbk_hash_get_bucket(ht, key));
}


/**
	* Remove a key with a given bucket id from an existing hash table.
	* This operation is not multi-thread
	* safe and should only be called from one thread.
	* @param ht
	* @param key
	* @param bucket
	* @return
	*/
static inline int
rte_fbk_hash_delete_key_with_bucket(struct rte_fbk_hash_table *ht,
					uint32_t key, uint32_t bucket)
{
	uint32_t last_entry = ht->entries_per_bucket - 1;
	uint32_t i, j;
	for (i = 0; i < ht->entries_per_bucket; i++)
{
		if (ht->t[bucket + i].entry.key == key)
{


			for (j = ht->entries_per_bucket - 1; j > i; j-- )
{
				if (! ht->t[bucket + j].entry.is_entry)
{
					last_entry = j - 1;
				}
			}

/*
			 * Move the last key to the deleted key's position, and
			 * delete the last key. lastEntry and i may be same but
			 * it doesn't matter.
			 */
			ht->t[bucket + i].whole_entry =
					ht->t[bucket + last_entry].whole_entry;
			ht->t[bucket + last_entry].whole_entry = 0;
			ht->used_entries--;
			return 0;
		}
	}
	return -ENOENT; 


}


/**
	* Remove a key from an existing hash table. This operation is not multi-thread
	* safe and should only be called from one thread.
	* @param ht
	* @param key
	* @return
	*/
static inline int
rte_fbk_hash_delete_key(struct rte_fbk_hash_table *ht, uint32_t key)
{
	return rte_fbk_hash_delete_key_with_bucket(ht,
				key, rte_fbk_hash_get_bucket(ht, key));
}


/**
	* Find a key in the hash table with a given bucketid.
	* This operation is multi-thread safe.
	* @param ht
	* @param key
	* @param bucket
	* @return
	*/
static inline int
rte_fbk_hash_lookup_with_bucket(const struct rte_fbk_hash_table *ht,
				uint32_t key, uint32_t bucket)
{
	union rte_fbk_hash_entry current_entry;
	uint32_t i;
	for (i = 0; i < ht->entries_per_bucket; i++)
{


		current_entry.whole_entry = ht->t[bucket + i].whole_entry;
		if (! current_entry.entry.is_entry)
{
			return -ENOENT; 


		}
		if (current_entry.entry.key == key)
{
			return current_entry.entry.value;
		}
	}
	return -ENOENT; 


}


/**
	* Find a key in the hash table. This operation is multi-thread safe.
	* @param ht
	* @param key
	* @return
	*/
static inline int
rte_fbk_hash_lookup(const struct rte_fbk_hash_table *ht, uint32_t key)
{
	return rte_fbk_hash_lookup_with_bucket(ht,
				key, rte_fbk_hash_get_bucket(ht, key));
}


/**
	* Delete all entries in a hash table. This operation is not multi-thread
	* safe and should only be called from one thread.
	* @param ht
	*/
static inline void
rte_fbk_hash_clear_all(struct rte_fbk_hash_table *ht)
{
	memset(ht->t, 0, sizeof(ht->t[0]) * ht->entries);
	ht->used_entries = 0;
}


/**
	* Find what fraction of entries are being used.
	* @param ht
	* @return
	*/
static inline double
rte_fbk_hash_get_load_factor(struct rte_fbk_hash_table *ht)
{
	return (double)ht->used_entries / (double)ht->entries;
}


/**
	* Performs a lookup for an existing hash table, and returns a pointer to
	* the table if found.
	* @param name
	* @return
	*/
struct rte_fbk_hash_table *rte_fbk_hash_find_existing(const char *name);


/**
	* Create a new hash table for use with four byte keys.
	* @param params
	* @return
	*/
struct rte_fbk_hash_table * rte_fbk_hash_create(const struct rte_fbk_hash_params *params);


/**
	* Free all memory used by a hash table.
	* Has no effect on hash tables allocated in memory zones
	* @param ht
	*/
void rte_fbk_hash_free(struct rte_fbk_hash_table *ht);


/*-
	*/


/**
	* @file
	* RTE Hash Table
	*/


















typedef uint32_t hash_sig_t;



typedef uint32_t (*rte_hash_function)(const void *key, uint32_t key_len,
						    uint32_t init_val);



typedef int (*rte_hash_cmp_eq_t)(const void *key1, const void *key2, size_t key_len);


/**
	* Parameters used when creating the hash table.
	*/
struct rte_hash_parameters
{
	const char *name; 


	uint32_t entries; 


	uint32_t reserved; 


	uint32_t key_len; 


	rte_hash_function hash_func; 


	uint32_t hash_func_init_val; 


	int socket_id; 


	uint8_t extra_flag; 


};



struct rte_hash;


/**
	* Create a new hash table.
	* @param params
	* @return
	*/
struct rte_hash *
rte_hash_create(const struct rte_hash_parameters *params);


/**
	* Set a new hash compare function other than the default one.
	* @note Function pointer does not work with multi-process, so do not use it
	* in multi-process mode.
	* @param h
	* @param func
	*/
void rte_hash_set_cmp_func(struct rte_hash *h, rte_hash_cmp_eq_t func);


/**
	* Find an existing hash table object and return a pointer to it.
	* @param name
	* @return
	*/
struct rte_hash *
rte_hash_find_existing(const char *name);


/**
	* De-allocate all memory used by hash table.
	* @param h
	*/
void
rte_hash_free(struct rte_hash *h);


/**
	* Reset all hash structure, by zeroing all entries
	* @param h
	*/
void
rte_hash_reset(struct rte_hash *h);


/**
	* Add a key-value pair to an existing hash table.
	* This operation is not multi-thread safe
	* and should only be called from one thread.
	* @param h
	* @param key
	* @param data
	* @return
	*/
int
rte_hash_add_key_data(const struct rte_hash *h, const void *key, void *data);


/**
	* Add a key-value pair with a pre-computed hash value
	* to an existing hash table.
	* This operation is not multi-thread safe
	* and should only be called from one thread.
	* @param h
	* @param key
	* @param sig
	* @param data
	* @return
	*/
int32_t
rte_hash_add_key_with_hash_data(const struct rte_hash *h, const void *key,
						hash_sig_t sig, void *data);


/**
	* Add a key to an existing hash table. This operation is not multi-thread safe
	* and should only be called from one thread.
	* @param h
	* @param key
	* @return
	*/
int32_t
rte_hash_add_key(const struct rte_hash *h, const void *key);


/**
	* Add a key to an existing hash table.
	* This operation is not multi-thread safe
	* and should only be called from one thread.
	* @param h
	* @param key
	* @param sig
	* @return
	*/
int32_t
rte_hash_add_key_with_hash(const struct rte_hash *h, const void *key, hash_sig_t sig);


/**
	* Remove a key from an existing hash table.
	* This operation is not multi-thread safe
	* and should only be called from one thread.
	* @param h
	* @param key
	* @return
	*/
int32_t
rte_hash_del_key(const struct rte_hash *h, const void *key);


/**
	* Remove a key from an existing hash table.
	* This operation is not multi-thread safe
	* and should only be called from one thread.
	* @param h
	* @param key
	* @param sig
	* @return
	*/
int32_t
rte_hash_del_key_with_hash(const struct rte_hash *h, const void *key, hash_sig_t sig);


/**
	* Find a key in the hash table given the position.
	* This operation is multi-thread safe.
	* @param h
	* @param position
	* @param key
	* @return
	*/
int
rte_hash_get_key_with_position(const struct rte_hash *h, const int32_t position,
						    void **key);


/**
	* Find a key-value pair in the hash table.
	* This operation is multi-thread safe.
	* @param h
	* @param key
	* @param data
	* @return
	*/
int
rte_hash_lookup_data(const struct rte_hash *h, const void *key, void **data);


/**
	* Find a key-value pair with a pre-computed hash value
	* to an existing hash table.
	* This operation is multi-thread safe.
	* @param h
	* @param key
	* @param sig
	* @param data
	* @return
	*/
int
rte_hash_lookup_with_hash_data(const struct rte_hash *h, const void *key,
					hash_sig_t sig, void **data);


/**
	* Find a key in the hash table.
	* This operation is multi-thread safe.
	* @param h
	* @param key
	* @return
	*/
int32_t
rte_hash_lookup(const struct rte_hash *h, const void *key);


/**
	* Find a key in the hash table.
	* This operation is multi-thread safe.
	* @param h
	* @param key
	* @param sig
	* @return
	*/
int32_t
rte_hash_lookup_with_hash(const struct rte_hash *h,
				const void *key, hash_sig_t sig);


/**
	* Calc a hash value by key.
	* This operation is not multi-thread safe.
	* @param h
	* @param key
	* @return
	*/
hash_sig_t
rte_hash_hash(const struct rte_hash *h, const void *key);


/**
	* Find multiple keys in the hash table.
	* This operation is multi-thread safe.
	* @param h
	* @param keys
	* @param num_keys
	* @param hit_mask
	* @param data
	* @return
	*/
int
rte_hash_lookup_bulk_data(const struct rte_hash *h, const void **keys,
						  uint32_t num_keys, uint64_t *hit_mask, void *data[]);


/**
	* Find multiple keys in the hash table.
	* This operation is multi-thread safe.
	* @param h
	* @param keys
	* @param num_keys
	* @param positions
	* @return
	*/
int
rte_hash_lookup_bulk(const struct rte_hash *h, const void **keys,
						  uint32_t num_keys, int32_t *positions);


/**
	* Iterate through the hash table, returning key-value pairs.
	* @param h
	* @param key
	* @param data
	* @param next
	* @return
	*/
int32_t
rte_hash_iterate(const struct rte_hash *h, const void **key, void **data, uint32_t *next);


/*-
	*/


/**
	* @file
	* RTE CRC Hash
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* Branch Prediction Helpers in RTE
	*/


/*-
	*/



static const uint32_t crc32c_tables[8][256] = {{
	0x00000000, 0xF26B8303, 0xE13B70F7, 0x1350F3F4, 0xC79A971F, 0x35F1141C, 0x26A1E7E8, 0xD4CA64EB,
	0x8AD958CF, 0x78B2DBCC, 0x6BE22838, 0x9989AB3B, 0x4D43CFD0, 0xBF284CD3, 0xAC78BF27, 0x5E133C24,
	0x105EC76F, 0xE235446C, 0xF165B798, 0x030E349B, 0xD7C45070, 0x25AFD373, 0x36FF2087, 0xC494A384,
	0x9A879FA0, 0x68EC1CA3, 0x7BBCEF57, 0x89D76C54, 0x5D1D08BF, 0xAF768BBC, 0xBC267848, 0x4E4DFB4B,
	0x20BD8EDE, 0xD2D60DDD, 0xC186FE29, 0x33ED7D2A, 0xE72719C1, 0x154C9AC2, 0x061C6936, 0xF477EA35,
	0xAA64D611, 0x580F5512, 0x4B5FA6E6, 0xB93425E5, 0x6DFE410E, 0x9F95C20D, 0x8CC531F9, 0x7EAEB2FA,
	0x30E349B1, 0xC288CAB2, 0xD1D83946, 0x23B3BA45, 0xF779DEAE, 0x05125DAD, 0x1642AE59, 0xE4292D5A,
	0xBA3A117E, 0x4851927D, 0x5B016189, 0xA96AE28A, 0x7DA08661, 0x8FCB0562, 0x9C9BF696, 0x6EF07595,
	0x417B1DBC, 0xB3109EBF, 0xA0406D4B, 0x522BEE48, 0x86E18AA3, 0x748A09A0, 0x67DAFA54, 0x95B17957,
	0xCBA24573, 0x39C9C670, 0x2A993584, 0xD8F2B687, 0x0C38D26C, 0xFE53516F, 0xED03A29B, 0x1F682198,
	0x5125DAD3, 0xA34E59D0, 0xB01EAA24, 0x42752927, 0x96BF4DCC, 0x64D4CECF, 0x77843D3B, 0x85EFBE38,
	0xDBFC821C, 0x2997011F, 0x3AC7F2EB, 0xC8AC71E8, 0x1C661503, 0xEE0D9600, 0xFD5D65F4, 0x0F36E6F7,
	0x61C69362, 0x93AD1061, 0x80FDE395, 0x72966096, 0xA65C047D, 0x5437877E, 0x4767748A, 0xB50CF789,
	0xEB1FCBAD, 0x197448AE, 0x0A24BB5A, 0xF84F3859, 0x2C855CB2, 0xDEEEDFB1, 0xCDBE2C45, 0x3FD5AF46,
	0x7198540D, 0x83F3D70E, 0x90A324FA, 0x62C8A7F9, 0xB602C312, 0x44694011, 0x5739B3E5, 0xA55230E6,
	0xFB410CC2, 0x092A8FC1, 0x1A7A7C35, 0xE811FF36, 0x3CDB9BDD, 0xCEB018DE, 0xDDE0EB2A, 0x2F8B6829,
	0x82F63B78, 0x709DB87B, 0x63CD4B8F, 0x91A6C88C, 0x456CAC67, 0xB7072F64, 0xA457DC90, 0x563C5F93,
	0x082F63B7, 0xFA44E0B4, 0xE9141340, 0x1B7F9043, 0xCFB5F4A8, 0x3DDE77AB, 0x2E8E845F, 0xDCE5075C,
	0x92A8FC17, 0x60C37F14, 0x73938CE0, 0x81F80FE3, 0x55326B08, 0xA759E80B, 0xB4091BFF, 0x466298FC,
	0x1871A4D8, 0xEA1A27DB, 0xF94AD42F, 0x0B21572C, 0xDFEB33C7, 0x2D80B0C4, 0x3ED04330, 0xCCBBC033,
	0xA24BB5A6, 0x502036A5, 0x4370C551, 0xB11B4652, 0x65D122B9, 0x97BAA1BA, 0x84EA524E, 0x7681D14D,
	0x2892ED69, 0xDAF96E6A, 0xC9A99D9E, 0x3BC21E9D, 0xEF087A76, 0x1D63F975, 0x0E330A81, 0xFC588982,
	0xB21572C9, 0x407EF1CA, 0x532E023E, 0xA145813D, 0x758FE5D6, 0x87E466D5, 0x94B49521, 0x66DF1622,
	0x38CC2A06, 0xCAA7A905, 0xD9F75AF1, 0x2B9CD9F2, 0xFF56BD19, 0x0D3D3E1A, 0x1E6DCDEE, 0xEC064EED,
	0xC38D26C4, 0x31E6A5C7, 0x22B65633, 0xD0DDD530, 0x0417B1DB, 0xF67C32D8, 0xE52CC12C, 0x1747422F,
	0x49547E0B, 0xBB3FFD08, 0xA86F0EFC, 0x5A048DFF, 0x8ECEE914, 0x7CA56A17, 0x6FF599E3, 0x9D9E1AE0,
	0xD3D3E1AB, 0x21B862A8, 0x32E8915C, 0xC083125F, 0x144976B4, 0xE622F5B7, 0xF5720643, 0x07198540,
	0x590AB964, 0xAB613A67, 0xB831C993, 0x4A5A4A90, 0x9E902E7B, 0x6CFBAD78, 0x7FAB5E8C, 0x8DC0DD8F,
	0xE330A81A, 0x115B2B19, 0x020BD8ED, 0xF0605BEE, 0x24AA3F05, 0xD6C1BC06, 0xC5914FF2, 0x37FACCF1,
	0x69E9F0D5, 0x9B8273D6, 0x88D28022, 0x7AB90321, 0xAE7367CA, 0x5C18E4C9, 0x4F48173D, 0xBD23943E,
	0xF36E6F75, 0x0105EC76, 0x12551F82, 0xE03E9C81, 0x34F4F86A, 0xC69F7B69, 0xD5CF889D, 0x27A40B9E,
	0x79B737BA, 0x8BDCB4B9, 0x988C474D, 0x6AE7C44E, 0xBE2DA0A5, 0x4C4623A6, 0x5F16D052, 0xAD7D5351
},
{
	0x00000000, 0x13A29877, 0x274530EE, 0x34E7A899, 0x4E8A61DC, 0x5D28F9AB, 0x69CF5132, 0x7A6DC945,
	0x9D14C3B8, 0x8EB65BCF, 0xBA51F356, 0xA9F36B21, 0xD39EA264, 0xC03C3A13, 0xF4DB928A, 0xE7790AFD,
	0x3FC5F181, 0x2C6769F6, 0x1880C16F, 0x0B225918, 0x714F905D, 0x62ED082A, 0x560AA0B3, 0x45A838C4,
	0xA2D13239, 0xB173AA4E, 0x859402D7, 0x96369AA0, 0xEC5B53E5, 0xFFF9CB92, 0xCB1E630B, 0xD8BCFB7C,
	0x7F8BE302, 0x6C297B75, 0x58CED3EC, 0x4B6C4B9B, 0x310182DE, 0x22A31AA9, 0x1644B230, 0x05E62A47,
	0xE29F20BA, 0xF13DB8CD, 0xC5DA1054, 0xD6788823, 0xAC154166, 0xBFB7D911, 0x8B507188, 0x98F2E9FF,
	0x404E1283, 0x53EC8AF4, 0x670B226D, 0x74A9BA1A, 0x0EC4735F, 0x1D66EB28, 0x298143B1, 0x3A23DBC6,
	0xDD5AD13B, 0xCEF8494C, 0xFA1FE1D5, 0xE9BD79A2, 0x93D0B0E7, 0x80722890, 0xB4958009, 0xA737187E,
	0xFF17C604, 0xECB55E73, 0xD852F6EA, 0xCBF06E9D, 0xB19DA7D8, 0xA23F3FAF, 0x96D89736, 0x857A0F41,
	0x620305BC, 0x71A19DCB, 0x45463552, 0x56E4AD25, 0x2C896460, 0x3F2BFC17, 0x0BCC548E, 0x186ECCF9,
	0xC0D23785, 0xD370AFF2, 0xE797076B, 0xF4359F1C, 0x8E585659, 0x9DFACE2E, 0xA91D66B7, 0xBABFFEC0,
	0x5DC6F43D, 0x4E646C4A, 0x7A83C4D3, 0x69215CA4, 0x134C95E1, 0x00EE0D96, 0x3409A50F, 0x27AB3D78,
	0x809C2506, 0x933EBD71, 0xA7D915E8, 0xB47B8D9F, 0xCE1644DA, 0xDDB4DCAD, 0xE9537434, 0xFAF1EC43,
	0x1D88E6BE, 0x0E2A7EC9, 0x3ACDD650, 0x296F4E27, 0x53028762, 0x40A01F15, 0x7447B78C, 0x67E52FFB,
	0xBF59D487, 0xACFB4CF0, 0x981CE469, 0x8BBE7C1E, 0xF1D3B55B, 0xE2712D2C, 0xD69685B5, 0xC5341DC2,
	0x224D173F, 0x31EF8F48, 0x050827D1, 0x16AABFA6, 0x6CC776E3, 0x7F65EE94, 0x4B82460D, 0x5820DE7A,
	0xFBC3FAF9, 0xE861628E, 0xDC86CA17, 0xCF245260, 0xB5499B25, 0xA6EB0352, 0x920CABCB, 0x81AE33BC,
	0x66D73941, 0x7575A136, 0x419209AF, 0x523091D8, 0x285D589D, 0x3BFFC0EA, 0x0F186873, 0x1CBAF004,
	0xC4060B78, 0xD7A4930F, 0xE3433B96, 0xF0E1A3E1, 0x8A8C6AA4, 0x992EF2D3, 0xADC95A4A, 0xBE6BC23D,
	0x5912C8C0, 0x4AB050B7, 0x7E57F82E, 0x6DF56059, 0x1798A91C, 0x043A316B, 0x30DD99F2, 0x237F0185,
	0x844819FB, 0x97EA818C, 0xA30D2915, 0xB0AFB162, 0xCAC27827, 0xD960E050, 0xED8748C9, 0xFE25D0BE,
	0x195CDA43, 0x0AFE4234, 0x3E19EAAD, 0x2DBB72DA, 0x57D6BB9F, 0x447423E8, 0x70938B71, 0x63311306,
	0xBB8DE87A, 0xA82F700D, 0x9CC8D894, 0x8F6A40E3, 0xF50789A6, 0xE6A511D1, 0xD242B948, 0xC1E0213F,
	0x26992BC2, 0x353BB3B5, 0x01DC1B2C, 0x127E835B, 0x68134A1E, 0x7BB1D269, 0x4F567AF0, 0x5CF4E287,
	0x04D43CFD, 0x1776A48A, 0x23910C13, 0x30339464, 0x4A5E5D21, 0x59FCC556, 0x6D1B6DCF, 0x7EB9F5B8,
	0x99C0FF45, 0x8A626732, 0xBE85CFAB, 0xAD2757DC, 0xD74A9E99, 0xC4E806EE, 0xF00FAE77, 0xE3AD3600,
	0x3B11CD7C, 0x28B3550B, 0x1C54FD92, 0x0FF665E5, 0x759BACA0, 0x663934D7, 0x52DE9C4E, 0x417C0439,
	0xA6050EC4, 0xB5A796B3, 0x81403E2A, 0x92E2A65D, 0xE88F6F18, 0xFB2DF76F, 0xCFCA5FF6, 0xDC68C781,
	0x7B5FDFFF, 0x68FD4788, 0x5C1AEF11, 0x4FB87766, 0x35D5BE23, 0x26772654, 0x12908ECD, 0x013216BA,
	0xE64B1C47, 0xF5E98430, 0xC10E2CA9, 0xD2ACB4DE, 0xA8C17D9B, 0xBB63E5EC, 0x8F844D75, 0x9C26D502,
	0x449A2E7E, 0x5738B609, 0x63DF1E90, 0x707D86E7, 0x0A104FA2, 0x19B2D7D5, 0x2D557F4C, 0x3EF7E73B,
	0xD98EEDC6, 0xCA2C75B1, 0xFECBDD28, 0xED69455F, 0x97048C1A, 0x84A6146D, 0xB041BCF4, 0xA3E32483
},
{
	0x00000000, 0xA541927E, 0x4F6F520D, 0xEA2EC073, 0x9EDEA41A, 0x3B9F3664, 0xD1B1F617, 0x74F06469,
	0x38513EC5, 0x9D10ACBB, 0x773E6CC8, 0xD27FFEB6, 0xA68F9ADF, 0x03CE08A1, 0xE9E0C8D2, 0x4CA15AAC,
	0x70A27D8A, 0xD5E3EFF4, 0x3FCD2F87, 0x9A8CBDF9, 0xEE7CD990, 0x4B3D4BEE, 0xA1138B9D, 0x045219E3,
	0x48F3434F, 0xEDB2D131, 0x079C1142, 0xA2DD833C, 0xD62DE755, 0x736C752B, 0x9942B558, 0x3C032726,
	0xE144FB14, 0x4405696A, 0xAE2BA919, 0x0B6A3B67, 0x7F9A5F0E, 0xDADBCD70, 0x30F50D03, 0x95B49F7D,
	0xD915C5D1, 0x7C5457AF, 0x967A97DC, 0x333B05A2, 0x47CB61CB, 0xE28AF3B5, 0x08A433C6, 0xADE5A1B8,
	0x91E6869E, 0x34A714E0, 0xDE89D493, 0x7BC846ED, 0x0F382284, 0xAA79B0FA, 0x40577089, 0xE516E2F7,
	0xA9B7B85B, 0x0CF62A25, 0xE6D8EA56, 0x43997828, 0x37691C41, 0x92288E3F, 0x78064E4C, 0xDD47DC32,
	0xC76580D9, 0x622412A7, 0x880AD2D4, 0x2D4B40AA, 0x59BB24C3, 0xFCFAB6BD, 0x16D476CE, 0xB395E4B0,
	0xFF34BE1C, 0x5A752C62, 0xB05BEC11, 0x151A7E6F, 0x61EA1A06, 0xC4AB8878, 0x2E85480B, 0x8BC4DA75,
	0xB7C7FD53, 0x12866F2D, 0xF8A8AF5E, 0x5DE93D20, 0x29195949, 0x8C58CB37, 0x66760B44, 0xC337993A,
	0x8F96C396, 0x2AD751E8, 0xC0F9919B, 0x65B803E5, 0x1148678C, 0xB409F5F2, 0x5E273581, 0xFB66A7FF,
	0x26217BCD, 0x8360E9B3, 0x694E29C0, 0xCC0FBBBE, 0xB8FFDFD7, 0x1DBE4DA9, 0xF7908DDA, 0x52D11FA4,
	0x1E704508, 0xBB31D776, 0x511F1705, 0xF45E857B, 0x80AEE112, 0x25EF736C, 0xCFC1B31F, 0x6A802161,
	0x56830647, 0xF3C29439, 0x19EC544A, 0xBCADC634, 0xC85DA25D, 0x6D1C3023, 0x8732F050, 0x2273622E,
	0x6ED23882, 0xCB93AAFC, 0x21BD6A8F, 0x84FCF8F1, 0xF00C9C98, 0x554D0EE6, 0xBF63CE95, 0x1A225CEB,
	0x8B277743, 0x2E66E53D, 0xC448254E, 0x6109B730, 0x15F9D359, 0xB0B84127, 0x5A968154, 0xFFD7132A,
	0xB3764986, 0x1637DBF8, 0xFC191B8B, 0x595889F5, 0x2DA8ED9C, 0x88E97FE2, 0x62C7BF91, 0xC7862DEF,
	0xFB850AC9, 0x5EC498B7, 0xB4EA58C4, 0x11ABCABA, 0x655BAED3, 0xC01A3CAD, 0x2A34FCDE, 0x8F756EA0,
	0xC3D4340C, 0x6695A672, 0x8CBB6601, 0x29FAF47F, 0x5D0A9016, 0xF84B0268, 0x1265C21B, 0xB7245065,
	0x6A638C57, 0xCF221E29, 0x250CDE5A, 0x804D4C24, 0xF4BD284D, 0x51FCBA33, 0xBBD27A40, 0x1E93E83E,
	0x5232B292, 0xF77320EC, 0x1D5DE09F, 0xB81C72E1, 0xCCEC1688, 0x69AD84F6, 0x83834485, 0x26C2D6FB,
	0x1AC1F1DD, 0xBF8063A3, 0x55AEA3D0, 0xF0EF31AE, 0x841F55C7, 0x215EC7B9, 0xCB7007CA, 0x6E3195B4,
	0x2290CF18, 0x87D15D66, 0x6DFF9D15, 0xC8BE0F6B, 0xBC4E6B02, 0x190FF97C, 0xF321390F, 0x5660AB71,
	0x4C42F79A, 0xE90365E4, 0x032DA597, 0xA66C37E9, 0xD29C5380, 0x77DDC1FE, 0x9DF3018D, 0x38B293F3,
	0x7413C95F, 0xD1525B21, 0x3B7C9B52, 0x9E3D092C, 0xEACD6D45, 0x4F8CFF3B, 0xA5A23F48, 0x00E3AD36,
	0x3CE08A10, 0x99A1186E, 0x738FD81D, 0xD6CE4A63, 0xA23E2E0A, 0x077FBC74, 0xED517C07, 0x4810EE79,
	0x04B1B4D5, 0xA1F026AB, 0x4BDEE6D8, 0xEE9F74A6, 0x9A6F10CF, 0x3F2E82B1, 0xD50042C2, 0x7041D0BC,
	0xAD060C8E, 0x08479EF0, 0xE2695E83, 0x4728CCFD, 0x33D8A894, 0x96993AEA, 0x7CB7FA99, 0xD9F668E7,
	0x9557324B, 0x3016A035, 0xDA386046, 0x7F79F238, 0x0B899651, 0xAEC8042F, 0x44E6C45C, 0xE1A75622,
	0xDDA47104, 0x78E5E37A, 0x92CB2309, 0x378AB177, 0x437AD51E, 0xE63B4760, 0x0C158713, 0xA954156D,
	0xE5F54FC1, 0x40B4DDBF, 0xAA9A1DCC, 0x0FDB8FB2, 0x7B2BEBDB, 0xDE6A79A5, 0x3444B9D6, 0x91052BA8
},
{
	0x00000000, 0xDD45AAB8, 0xBF672381, 0x62228939, 0x7B2231F3, 0xA6679B4B, 0xC4451272, 0x1900B8CA,
	0xF64463E6, 0x2B01C95E, 0x49234067, 0x9466EADF, 0x8D665215, 0x5023F8AD, 0x32017194, 0xEF44DB2C,
	0xE964B13D, 0x34211B85, 0x560392BC, 0x8B463804, 0x924680CE, 0x4F032A76, 0x2D21A34F, 0xF06409F7,
	0x1F20D2DB, 0xC2657863, 0xA047F15A, 0x7D025BE2, 0x6402E328, 0xB9474990, 0xDB65C0A9, 0x06206A11,
	0xD725148B, 0x0A60BE33, 0x6842370A, 0xB5079DB2, 0xAC072578, 0x71428FC0, 0x136006F9, 0xCE25AC41,
	0x2161776D, 0xFC24DDD5, 0x9E0654EC, 0x4343FE54, 0x5A43469E, 0x8706EC26, 0xE524651F, 0x3861CFA7,
	0x3E41A5B6, 0xE3040F0E, 0x81268637, 0x5C632C8F, 0x45639445, 0x98263EFD, 0xFA04B7C4, 0x27411D7C,
	0xC805C650, 0x15406CE8, 0x7762E5D1, 0xAA274F69, 0xB327F7A3, 0x6E625D1B, 0x0C40D422, 0xD1057E9A,
	0xABA65FE7, 0x76E3F55F, 0x14C17C66, 0xC984D6DE, 0xD0846E14, 0x0DC1C4AC, 0x6FE34D95, 0xB2A6E72D,
	0x5DE23C01, 0x80A796B9, 0xE2851F80, 0x3FC0B538, 0x26C00DF2, 0xFB85A74A, 0x99A72E73, 0x44E284CB,
	0x42C2EEDA, 0x9F874462, 0xFDA5CD5B, 0x20E067E3, 0x39E0DF29, 0xE4A57591, 0x8687FCA8, 0x5BC25610,
	0xB4868D3C, 0x69C32784, 0x0BE1AEBD, 0xD6A40405, 0xCFA4BCCF, 0x12E11677, 0x70C39F4E, 0xAD8635F6,
	0x7C834B6C, 0xA1C6E1D4, 0xC3E468ED, 0x1EA1C255, 0x07A17A9F, 0xDAE4D027, 0xB8C6591E, 0x6583F3A6,
	0x8AC7288A, 0x57828232, 0x35A00B0B, 0xE8E5A1B3, 0xF1E51979, 0x2CA0B3C1, 0x4E823AF8, 0x93C79040,
	0x95E7FA51, 0x48A250E9, 0x2A80D9D0, 0xF7C57368, 0xEEC5CBA2, 0x3380611A, 0x51A2E823, 0x8CE7429B,
	0x63A399B7, 0xBEE6330F, 0xDCC4BA36, 0x0181108E, 0x1881A844, 0xC5C402FC, 0xA7E68BC5, 0x7AA3217D,
	0x52A0C93F, 0x8FE56387, 0xEDC7EABE, 0x30824006, 0x2982F8CC, 0xF4C75274, 0x96E5DB4D, 0x4BA071F5,
	0xA4E4AAD9, 0x79A10061, 0x1B838958, 0xC6C623E0, 0xDFC69B2A, 0x02833192, 0x60A1B8AB, 0xBDE41213,
	0xBBC47802, 0x6681D2BA, 0x04A35B83, 0xD9E6F13B, 0xC0E649F1, 0x1DA3E349, 0x7F816A70, 0xA2C4C0C8,
	0x4D801BE4, 0x90C5B15C, 0xF2E73865, 0x2FA292DD, 0x36A22A17, 0xEBE780AF, 0x89C50996, 0x5480A32E,
	0x8585DDB4, 0x58C0770C, 0x3AE2FE35, 0xE7A7548D, 0xFEA7EC47, 0x23E246FF, 0x41C0CFC6, 0x9C85657E,
	0x73C1BE52, 0xAE8414EA, 0xCCA69DD3, 0x11E3376B, 0x08E38FA1, 0xD5A62519, 0xB784AC20, 0x6AC10698,
	0x6CE16C89, 0xB1A4C631, 0xD3864F08, 0x0EC3E5B0, 0x17C35D7A, 0xCA86F7C2, 0xA8A47EFB, 0x75E1D443,
	0x9AA50F6F, 0x47E0A5D7, 0x25C22CEE, 0xF8878656, 0xE1873E9C, 0x3CC29424, 0x5EE01D1D, 0x83A5B7A5,
	0xF90696D8, 0x24433C60, 0x4661B559, 0x9B241FE1, 0x8224A72B, 0x5F610D93, 0x3D4384AA, 0xE0062E12,
	0x0F42F53E, 0xD2075F86, 0xB025D6BF, 0x6D607C07, 0x7460C4CD, 0xA9256E75, 0xCB07E74C, 0x16424DF4,
	0x106227E5, 0xCD278D5D, 0xAF050464, 0x7240AEDC, 0x6B401616, 0xB605BCAE, 0xD4273597, 0x09629F2F,
	0xE6264403, 0x3B63EEBB, 0x59416782, 0x8404CD3A, 0x9D0475F0, 0x4041DF48, 0x22635671, 0xFF26FCC9,
	0x2E238253, 0xF36628EB, 0x9144A1D2, 0x4C010B6A, 0x5501B3A0, 0x88441918, 0xEA669021, 0x37233A99,
	0xD867E1B5, 0x05224B0D, 0x6700C234, 0xBA45688C, 0xA345D046, 0x7E007AFE, 0x1C22F3C7, 0xC167597F,
	0xC747336E, 0x1A0299D6, 0x782010EF, 0xA565BA57, 0xBC65029D, 0x6120A825, 0x0302211C, 0xDE478BA4,
	0x31035088, 0xEC46FA30, 0x8E647309, 0x5321D9B1, 0x4A21617B, 0x9764CBC3, 0xF54642FA, 0x2803E842
},
{
	0x00000000, 0x38116FAC, 0x7022DF58, 0x4833B0F4, 0xE045BEB0, 0xD854D11C, 0x906761E8, 0xA8760E44,
	0xC5670B91, 0xFD76643D, 0xB545D4C9, 0x8D54BB65, 0x2522B521, 0x1D33DA8D, 0x55006A79, 0x6D1105D5,
	0x8F2261D3, 0xB7330E7F, 0xFF00BE8B, 0xC711D127, 0x6F67DF63, 0x5776B0CF, 0x1F45003B, 0x27546F97,
	0x4A456A42, 0x725405EE, 0x3A67B51A, 0x0276DAB6, 0xAA00D4F2, 0x9211BB5E, 0xDA220BAA, 0xE2336406,
	0x1BA8B557, 0x23B9DAFB, 0x6B8A6A0F, 0x539B05A3, 0xFBED0BE7, 0xC3FC644B, 0x8BCFD4BF, 0xB3DEBB13,
	0xDECFBEC6, 0xE6DED16A, 0xAEED619E, 0x96FC0E32, 0x3E8A0076, 0x069B6FDA, 0x4EA8DF2E, 0x76B9B082,
	0x948AD484, 0xAC9BBB28, 0xE4A80BDC, 0xDCB96470, 0x74CF6A34, 0x4CDE0598, 0x04EDB56C, 0x3CFCDAC0,
	0x51EDDF15, 0x69FCB0B9, 0x21CF004D, 0x19DE6FE1, 0xB1A861A5, 0x89B90E09, 0xC18ABEFD, 0xF99BD151,
	0x37516AAE, 0x0F400502, 0x4773B5F6, 0x7F62DA5A, 0xD714D41E, 0xEF05BBB2, 0xA7360B46, 0x9F2764EA,
	0xF236613F, 0xCA270E93, 0x8214BE67, 0xBA05D1CB, 0x1273DF8F, 0x2A62B023, 0x625100D7, 0x5A406F7B,
	0xB8730B7D, 0x806264D1, 0xC851D425, 0xF040BB89, 0x5836B5CD, 0x6027DA61, 0x28146A95, 0x10050539,
	0x7D1400EC, 0x45056F40, 0x0D36DFB4, 0x3527B018, 0x9D51BE5C, 0xA540D1F0, 0xED736104, 0xD5620EA8,
	0x2CF9DFF9, 0x14E8B055, 0x5CDB00A1, 0x64CA6F0D, 0xCCBC6149, 0xF4AD0EE5, 0xBC9EBE11, 0x848FD1BD,
	0xE99ED468, 0xD18FBBC4, 0x99BC0B30, 0xA1AD649C, 0x09DB6AD8, 0x31CA0574, 0x79F9B580, 0x41E8DA2C,
	0xA3DBBE2A, 0x9BCAD186, 0xD3F96172, 0xEBE80EDE, 0x439E009A, 0x7B8F6F36, 0x33BCDFC2, 0x0BADB06E,
	0x66BCB5BB, 0x5EADDA17, 0x169E6AE3, 0x2E8F054F, 0x86F90B0B, 0xBEE864A7, 0xF6DBD453, 0xCECABBFF,
	0x6EA2D55C, 0x56B3BAF0, 0x1E800A04, 0x269165A8, 0x8EE76BEC, 0xB6F60440, 0xFEC5B4B4, 0xC6D4DB18,
	0xABC5DECD, 0x93D4B161, 0xDBE70195, 0xE3F66E39, 0x4B80607D, 0x73910FD1, 0x3BA2BF25, 0x03B3D089,
	0xE180B48F, 0xD991DB23, 0x91A26BD7, 0xA9B3047B, 0x01C50A3F, 0x39D46593, 0x71E7D567, 0x49F6BACB,
	0x24E7BF1E, 0x1CF6D0B2, 0x54C56046, 0x6CD40FEA, 0xC4A201AE, 0xFCB36E02, 0xB480DEF6, 0x8C91B15A,
	0x750A600B, 0x4D1B0FA7, 0x0528BF53, 0x3D39D0FF, 0x954FDEBB, 0xAD5EB117, 0xE56D01E3, 0xDD7C6E4F,
	0xB06D6B9A, 0x887C0436, 0xC04FB4C2, 0xF85EDB6E, 0x5028D52A, 0x6839BA86, 0x200A0A72, 0x181B65DE,
	0xFA2801D8, 0xC2396E74, 0x8A0ADE80, 0xB21BB12C, 0x1A6DBF68, 0x227CD0C4, 0x6A4F6030, 0x525E0F9C,
	0x3F4F0A49, 0x075E65E5, 0x4F6DD511, 0x777CBABD, 0xDF0AB4F9, 0xE71BDB55, 0xAF286BA1, 0x9739040D,
	0x59F3BFF2, 0x61E2D05E, 0x29D160AA, 0x11C00F06, 0xB9B60142, 0x81A76EEE, 0xC994DE1A, 0xF185B1B6,
	0x9C94B463, 0xA485DBCF, 0xECB66B3B, 0xD4A70497, 0x7CD10AD3, 0x44C0657F, 0x0CF3D58B, 0x34E2BA27,
	0xD6D1DE21, 0xEEC0B18D, 0xA6F30179, 0x9EE26ED5, 0x36946091, 0x0E850F3D, 0x46B6BFC9, 0x7EA7D065,
	0x13B6D5B0, 0x2BA7BA1C, 0x63940AE8, 0x5B856544, 0xF3F36B00, 0xCBE204AC, 0x83D1B458, 0xBBC0DBF4,
	0x425B0AA5, 0x7A4A6509, 0x3279D5FD, 0x0A68BA51, 0xA21EB415, 0x9A0FDBB9, 0xD23C6B4D, 0xEA2D04E1,
	0x873C0134, 0xBF2D6E98, 0xF71EDE6C, 0xCF0FB1C0, 0x6779BF84, 0x5F68D028, 0x175B60DC, 0x2F4A0F70,
	0xCD796B76, 0xF56804DA, 0xBD5BB42E, 0x854ADB82, 0x2D3CD5C6, 0x152DBA6A, 0x5D1E0A9E, 0x650F6532,
	0x081E60E7, 0x300F0F4B, 0x783CBFBF, 0x402DD013, 0xE85BDE57, 0xD04AB1FB, 0x9879010F, 0xA0686EA3
},
{
	0x00000000, 0xEF306B19, 0xDB8CA0C3, 0x34BCCBDA, 0xB2F53777, 0x5DC55C6E, 0x697997B4, 0x8649FCAD,
	0x6006181F, 0x8F367306, 0xBB8AB8DC, 0x54BAD3C5, 0xD2F32F68, 0x3DC34471, 0x097F8FAB, 0xE64FE4B2,
	0xC00C303E, 0x2F3C5B27, 0x1B8090FD, 0xF4B0FBE4, 0x72F90749, 0x9DC96C50, 0xA975A78A, 0x4645CC93,
	0xA00A2821, 0x4F3A4338, 0x7B8688E2, 0x94B6E3FB, 0x12FF1F56, 0xFDCF744F, 0xC973BF95, 0x2643D48C,
	0x85F4168D, 0x6AC47D94, 0x5E78B64E, 0xB148DD57, 0x370121FA, 0xD8314AE3, 0xEC8D8139, 0x03BDEA20,
	0xE5F20E92, 0x0AC2658B, 0x3E7EAE51, 0xD14EC548, 0x570739E5, 0xB83752FC, 0x8C8B9926, 0x63BBF23F,
	0x45F826B3, 0xAAC84DAA, 0x9E748670, 0x7144ED69, 0xF70D11C4, 0x183D7ADD, 0x2C81B107, 0xC3B1DA1E,
	0x25FE3EAC, 0xCACE55B5, 0xFE729E6F, 0x1142F576, 0x970B09DB, 0x783B62C2, 0x4C87A918, 0xA3B7C201,
	0x0E045BEB, 0xE13430F2, 0xD588FB28, 0x3AB89031, 0xBCF16C9C, 0x53C10785, 0x677DCC5F, 0x884DA746,
	0x6E0243F4, 0x813228ED, 0xB58EE337, 0x5ABE882E, 0xDCF77483, 0x33C71F9A, 0x077BD440, 0xE84BBF59,
	0xCE086BD5, 0x213800CC, 0x1584CB16, 0xFAB4A00F, 0x7CFD5CA2, 0x93CD37BB, 0xA771FC61, 0x48419778,
	0xAE0E73CA, 0x413E18D3, 0x7582D309, 0x9AB2B810, 0x1CFB44BD, 0xF3CB2FA4, 0xC777E47E, 0x28478F67,
	0x8BF04D66, 0x64C0267F, 0x507CEDA5, 0xBF4C86BC, 0x39057A11, 0xD6351108, 0xE289DAD2, 0x0DB9B1CB,
	0xEBF65579, 0x04C63E60, 0x307AF5BA, 0xDF4A9EA3, 0x5903620E, 0xB6330917, 0x828FC2CD, 0x6DBFA9D4,
	0x4BFC7D58, 0xA4CC1641, 0x9070DD9B, 0x7F40B682, 0xF9094A2F, 0x16392136, 0x2285EAEC, 0xCDB581F5,
	0x2BFA6547, 0xC4CA0E5E, 0xF076C584, 0x1F46AE9D, 0x990F5230, 0x763F3929, 0x4283F2F3, 0xADB399EA,
	0x1C08B7D6, 0xF338DCCF, 0xC7841715, 0x28B47C0C, 0xAEFD80A1, 0x41CDEBB8, 0x75712062, 0x9A414B7B,
	0x7C0EAFC9, 0x933EC4D0, 0xA7820F0A, 0x48B26413, 0xCEFB98BE, 0x21CBF3A7, 0x1577387D, 0xFA475364,
	0xDC0487E8, 0x3334ECF1, 0x0788272B, 0xE8B84C32, 0x6EF1B09F, 0x81C1DB86, 0xB57D105C, 0x5A4D7B45,
	0xBC029FF7, 0x5332F4EE, 0x678E3F34, 0x88BE542D, 0x0EF7A880, 0xE1C7C399, 0xD57B0843, 0x3A4B635A,
	0x99FCA15B, 0x76CCCA42, 0x42700198, 0xAD406A81, 0x2B09962C, 0xC439FD35, 0xF08536EF, 0x1FB55DF6,
	0xF9FAB944, 0x16CAD25D, 0x22761987, 0xCD46729E, 0x4B0F8E33, 0xA43FE52A, 0x90832EF0, 0x7FB345E9,
	0x59F09165, 0xB6C0FA7C, 0x827C31A6, 0x6D4C5ABF, 0xEB05A612, 0x0435CD0B, 0x308906D1, 0xDFB96DC8,
	0x39F6897A, 0xD6C6E263, 0xE27A29B9, 0x0D4A42A0, 0x8B03BE0D, 0x6433D514, 0x508F1ECE, 0xBFBF75D7,
	0x120CEC3D, 0xFD3C8724, 0xC9804CFE, 0x26B027E7, 0xA0F9DB4A, 0x4FC9B053, 0x7B757B89, 0x94451090,
	0x720AF422, 0x9D3A9F3B, 0xA98654E1, 0x46B63FF8, 0xC0FFC355, 0x2FCFA84C, 0x1B736396, 0xF443088F,
	0xD200DC03, 0x3D30B71A, 0x098C7CC0, 0xE6BC17D9, 0x60F5EB74, 0x8FC5806D, 0xBB794BB7, 0x544920AE,
	0xB206C41C, 0x5D36AF05, 0x698A64DF, 0x86BA0FC6, 0x00F3F36B, 0xEFC39872, 0xDB7F53A8, 0x344F38B1,
	0x97F8FAB0, 0x78C891A9, 0x4C745A73, 0xA344316A, 0x250DCDC7, 0xCA3DA6DE, 0xFE816D04, 0x11B1061D,
	0xF7FEE2AF, 0x18CE89B6, 0x2C72426C, 0xC3422975, 0x450BD5D8, 0xAA3BBEC1, 0x9E87751B, 0x71B71E02,
	0x57F4CA8E, 0xB8C4A197, 0x8C786A4D, 0x63480154, 0xE501FDF9, 0x0A3196E0, 0x3E8D5D3A, 0xD1BD3623,
	0x37F2D291, 0xD8C2B988, 0xEC7E7252, 0x034E194B, 0x8507E5E6, 0x6A378EFF, 0x5E8B4525, 0xB1BB2E3C
},
{
	0x00000000, 0x68032CC8, 0xD0065990, 0xB8057558, 0xA5E0C5D1, 0xCDE3E919, 0x75E69C41, 0x1DE5B089,
	0x4E2DFD53, 0x262ED19B, 0x9E2BA4C3, 0xF628880B, 0xEBCD3882, 0x83CE144A, 0x3BCB6112, 0x53C84DDA,
	0x9C5BFAA6, 0xF458D66E, 0x4C5DA336, 0x245E8FFE, 0x39BB3F77, 0x51B813BF, 0xE9BD66E7, 0x81BE4A2F,
	0xD27607F5, 0xBA752B3D, 0x02705E65, 0x6A7372AD, 0x7796C224, 0x1F95EEEC, 0xA7909BB4, 0xCF93B77C,
	0x3D5B83BD, 0x5558AF75, 0xED5DDA2D, 0x855EF6E5, 0x98BB466C, 0xF0B86AA4, 0x48BD1FFC, 0x20BE3334,
	0x73767EEE, 0x1B755226, 0xA370277E, 0xCB730BB6, 0xD696BB3F, 0xBE9597F7, 0x0690E2AF, 0x6E93CE67,
	0xA100791B, 0xC90355D3, 0x7106208B, 0x19050C43, 0x04E0BCCA, 0x6CE39002, 0xD4E6E55A, 0xBCE5C992,
	0xEF2D8448, 0x872EA880, 0x3F2BDDD8, 0x5728F110, 0x4ACD4199, 0x22CE6D51, 0x9ACB1809, 0xF2C834C1,
	0x7AB7077A, 0x12B42BB2, 0xAAB15EEA, 0xC2B27222, 0xDF57C2AB, 0xB754EE63, 0x0F519B3B, 0x6752B7F3,
	0x349AFA29, 0x5C99D6E1, 0xE49CA3B9, 0x8C9F8F71, 0x917A3FF8, 0xF9791330, 0x417C6668, 0x297F4AA0,
	0xE6ECFDDC, 0x8EEFD114, 0x36EAA44C, 0x5EE98884, 0x430C380D, 0x2B0F14C5, 0x930A619D, 0xFB094D55,
	0xA8C1008F, 0xC0C22C47, 0x78C7591F, 0x10C475D7, 0x0D21C55E, 0x6522E996, 0xDD279CCE, 0xB524B006,
	0x47EC84C7, 0x2FEFA80F, 0x97EADD57, 0xFFE9F19F, 0xE20C4116, 0x8A0F6DDE, 0x320A1886, 0x5A09344E,
	0x09C17994, 0x61C2555C, 0xD9C72004, 0xB1C40CCC, 0xAC21BC45, 0xC422908D, 0x7C27E5D5, 0x1424C91D,
	0xDBB77E61, 0xB3B452A9, 0x0BB127F1, 0x63B20B39, 0x7E57BBB0, 0x16549778, 0xAE51E220, 0xC652CEE8,
	0x959A8332, 0xFD99AFFA, 0x459CDAA2, 0x2D9FF66A, 0x307A46E3, 0x58796A2B, 0xE07C1F73, 0x887F33BB,
	0xF56E0EF4, 0x9D6D223C, 0x25685764, 0x4D6B7BAC, 0x508ECB25, 0x388DE7ED, 0x808892B5, 0xE88BBE7D,
	0xBB43F3A7, 0xD340DF6F, 0x6B45AA37, 0x034686FF, 0x1EA33676, 0x76A01ABE, 0xCEA56FE6, 0xA6A6432E,
	0x6935F452, 0x0136D89A, 0xB933ADC2, 0xD130810A, 0xCCD53183, 0xA4D61D4B, 0x1CD36813, 0x74D044DB,
	0x27180901, 0x4F1B25C9, 0xF71E5091, 0x9F1D7C59, 0x82F8CCD0, 0xEAFBE018, 0x52FE9540, 0x3AFDB988,
	0xC8358D49, 0xA036A181, 0x1833D4D9, 0x7030F811, 0x6DD54898, 0x05D66450, 0xBDD31108, 0xD5D03DC0,
	0x8618701A, 0xEE1B5CD2, 0x561E298A, 0x3E1D0542, 0x23F8B5CB, 0x4BFB9903, 0xF3FEEC5B, 0x9BFDC093,
	0x546E77EF, 0x3C6D5B27, 0x84682E7F, 0xEC6B02B7, 0xF18EB23E, 0x998D9EF6, 0x2188EBAE, 0x498BC766,
	0x1A438ABC, 0x7240A674, 0xCA45D32C, 0xA246FFE4, 0xBFA34F6D, 0xD7A063A5, 0x6FA516FD, 0x07A63A35,
	0x8FD9098E, 0xE7DA2546, 0x5FDF501E, 0x37DC7CD6, 0x2A39CC5F, 0x423AE097, 0xFA3F95CF, 0x923CB907,
	0xC1F4F4DD, 0xA9F7D815, 0x11F2AD4D, 0x79F18185, 0x6414310C, 0x0C171DC4, 0xB412689C, 0xDC114454,
	0x1382F328, 0x7B81DFE0, 0xC384AAB8, 0xAB878670, 0xB66236F9, 0xDE611A31, 0x66646F69, 0x0E6743A1,
	0x5DAF0E7B, 0x35AC22B3, 0x8DA957EB, 0xE5AA7B23, 0xF84FCBAA, 0x904CE762, 0x2849923A, 0x404ABEF2,
	0xB2828A33, 0xDA81A6FB, 0x6284D3A3, 0x0A87FF6B, 0x17624FE2, 0x7F61632A, 0xC7641672, 0xAF673ABA,
	0xFCAF7760, 0x94AC5BA8, 0x2CA92EF0, 0x44AA0238, 0x594FB2B1, 0x314C9E79, 0x8949EB21, 0xE14AC7E9,
	0x2ED97095, 0x46DA5C5D, 0xFEDF2905, 0x96DC05CD, 0x8B39B544, 0xE33A998C, 0x5B3FECD4, 0x333CC01C,
	0x60F48DC6, 0x08F7A10E, 0xB0F2D456, 0xD8F1F89E, 0xC5144817, 0xAD1764DF, 0x15121187, 0x7D113D4F
},
{
	0x00000000, 0x493C7D27, 0x9278FA4E, 0xDB448769, 0x211D826D, 0x6821FF4A, 0xB3657823, 0xFA590504,
	0x423B04DA, 0x0B0779FD, 0xD043FE94, 0x997F83B3, 0x632686B7, 0x2A1AFB90, 0xF15E7CF9, 0xB86201DE,
	0x847609B4, 0xCD4A7493, 0x160EF3FA, 0x5F328EDD, 0xA56B8BD9, 0xEC57F6FE, 0x37137197, 0x7E2F0CB0,
	0xC64D0D6E, 0x8F717049, 0x5435F720, 0x1D098A07, 0xE7508F03, 0xAE6CF224, 0x7528754D, 0x3C14086A,
	0x0D006599, 0x443C18BE, 0x9F789FD7, 0xD644E2F0, 0x2C1DE7F4, 0x65219AD3, 0xBE651DBA, 0xF759609D,
	0x4F3B6143, 0x06071C64, 0xDD439B0D, 0x947FE62A, 0x6E26E32E, 0x271A9E09, 0xFC5E1960, 0xB5626447,
	0x89766C2D, 0xC04A110A, 0x1B0E9663, 0x5232EB44, 0xA86BEE40, 0xE1579367, 0x3A13140E, 0x732F6929,
	0xCB4D68F7, 0x827115D0, 0x593592B9, 0x1009EF9E, 0xEA50EA9A, 0xA36C97BD, 0x782810D4, 0x31146DF3,
	0x1A00CB32, 0x533CB615, 0x8878317C, 0xC1444C5B, 0x3B1D495F, 0x72213478, 0xA965B311, 0xE059CE36,
	0x583BCFE8, 0x1107B2CF, 0xCA4335A6, 0x837F4881, 0x79264D85, 0x301A30A2, 0xEB5EB7CB, 0xA262CAEC,
	0x9E76C286, 0xD74ABFA1, 0x0C0E38C8, 0x453245EF, 0xBF6B40EB, 0xF6573DCC, 0x2D13BAA5, 0x642FC782,
	0xDC4DC65C, 0x9571BB7B, 0x4E353C12, 0x07094135, 0xFD504431, 0xB46C3916, 0x6F28BE7F, 0x2614C358,
	0x1700AEAB, 0x5E3CD38C, 0x857854E5, 0xCC4429C2, 0x361D2CC6, 0x7F2151E1, 0xA465D688, 0xED59ABAF,
	0x553BAA71, 0x1C07D756, 0xC743503F, 0x8E7F2D18, 0x7426281C, 0x3D1A553B, 0xE65ED252, 0xAF62AF75,
	0x9376A71F, 0xDA4ADA38, 0x010E5D51, 0x48322076, 0xB26B2572, 0xFB575855, 0x2013DF3C, 0x692FA21B,
	0xD14DA3C5, 0x9871DEE2, 0x4335598B, 0x0A0924AC, 0xF05021A8, 0xB96C5C8F, 0x6228DBE6, 0x2B14A6C1,
	0x34019664, 0x7D3DEB43, 0xA6796C2A, 0xEF45110D, 0x151C1409, 0x5C20692E, 0x8764EE47, 0xCE589360,
	0x763A92BE, 0x3F06EF99, 0xE44268F0, 0xAD7E15D7, 0x572710D3, 0x1E1B6DF4, 0xC55FEA9D, 0x8C6397BA,
	0xB0779FD0, 0xF94BE2F7, 0x220F659E, 0x6B3318B9, 0x916A1DBD, 0xD856609A, 0x0312E7F3, 0x4A2E9AD4,
	0xF24C9B0A, 0xBB70E62D, 0x60346144, 0x29081C63, 0xD3511967, 0x9A6D6440, 0x4129E329, 0x08159E0E,
	0x3901F3FD, 0x703D8EDA, 0xAB7909B3, 0xE2457494, 0x181C7190, 0x51200CB7, 0x8A648BDE, 0xC358F6F9,
	0x7B3AF727, 0x32068A00, 0xE9420D69, 0xA07E704E, 0x5A27754A, 0x131B086D, 0xC85F8F04, 0x8163F223,
	0xBD77FA49, 0xF44B876E, 0x2F0F0007, 0x66337D20, 0x9C6A7824, 0xD5560503, 0x0E12826A, 0x472EFF4D,
	0xFF4CFE93, 0xB67083B4, 0x6D3404DD, 0x240879FA, 0xDE517CFE, 0x976D01D9, 0x4C2986B0, 0x0515FB97,
	0x2E015D56, 0x673D2071, 0xBC79A718, 0xF545DA3F, 0x0F1CDF3B, 0x4620A21C, 0x9D642575, 0xD4585852,
	0x6C3A598C, 0x250624AB, 0xFE42A3C2, 0xB77EDEE5, 0x4D27DBE1, 0x041BA6C6, 0xDF5F21AF, 0x96635C88,
	0xAA7754E2, 0xE34B29C5, 0x380FAEAC, 0x7133D38B, 0x8B6AD68F, 0xC256ABA8, 0x19122CC1, 0x502E51E6,
	0xE84C5038, 0xA1702D1F, 0x7A34AA76, 0x3308D751, 0xC951D255, 0x806DAF72, 0x5B29281B, 0x1215553C,
	0x230138CF, 0x6A3D45E8, 0xB179C281, 0xF845BFA6, 0x021CBAA2, 0x4B20C785, 0x906440EC, 0xD9583DCB,
	0x613A3C15, 0x28064132, 0xF342C65B, 0xBA7EBB7C, 0x4027BE78, 0x091BC35F, 0xD25F4436, 0x9B633911,
	0xA777317B, 0xEE4B4C5C, 0x350FCB35, 0x7C33B612, 0x866AB316, 0xCF56CE31, 0x14124958, 0x5D2E347F,
	0xE54C35A1, 0xAC704886, 0x7734CFEF, 0x3E08B2C8, 0xC451B7CC, 0x8D6DCAEB, 0x56294D82, 0x1F1530A5
}};
static inline uint32_t
crc32c_1byte(uint8_t data, uint32_t init_val)
{
	uint32_t crc;
	crc = init_val;
	crc ^= data;
	return crc32c_tables[0][crc & 0xff] ^ (crc >> 8);
}
static inline uint32_t
crc32c_2bytes(uint16_t data, uint32_t init_val)
{
	uint32_t crc;
	crc = init_val;
	crc ^= data;
	crc = (crc32c_tables[(1)][(crc) & 0xFF] ^ crc32c_tables[(1)-1][((crc) >> 8) & 0xFF]) ^ (crc >> 16);
	return crc;
}
static inline uint32_t
crc32c_1word(uint32_t data, uint32_t init_val)
{
	uint32_t crc, term1, term2;
	crc = init_val;
	crc ^= data;
	term1 = (crc32c_tables[(3)][(crc) & 0xFF] ^ crc32c_tables[(3)-1][((crc) >> 8) & 0xFF]);
	term2 = crc >> 16;
	crc = term1 ^ (crc32c_tables[(1)][(term2) & 0xFF] ^ crc32c_tables[(1)-1][((term2) >> 8) & 0xFF]);
	return crc;
}
static inline uint32_t
crc32c_2words(uint64_t data, uint32_t init_val)
{
	union
{
		uint64_t u64;
		uint32_t u32[2];
	} d;
	d.u64 = data;
	uint32_t crc, term1, term2;
	crc = init_val;
	crc ^= d.u32[0];
	term1 = (crc32c_tables[(7)][(crc) & 0xFF] ^ crc32c_tables[(7)-1][((crc) >> 8) & 0xFF]);
	term2 = crc >> 16;
	crc = term1 ^ (crc32c_tables[(5)][(term2) & 0xFF] ^ crc32c_tables[(5)-1][((term2) >> 8) & 0xFF]);
	term1 = (crc32c_tables[(3)][(d.u32[1]) & 0xFF] ^ crc32c_tables[(3)-1][((d.u32[1]) >> 8) & 0xFF]);
	term2 = d.u32[1] >> 16;
	crc ^= term1 ^ (crc32c_tables[(1)][(term2) & 0xFF] ^ crc32c_tables[(1)-1][((term2) >> 8) & 0xFF]);
	return crc;
}
static inline uint32_t
crc32c_sse42_u8(uint8_t data, uint32_t init_val)
{
	__asm__ volatile(
			"crc32b %[data], %[init_val];"
			: [init_val] "+r" (init_val)
			: [data] "rm" (data));
	return init_val;
}
static inline uint32_t
crc32c_sse42_u16(uint16_t data, uint32_t init_val)
{
	__asm__ volatile(
			"crc32w %[data], %[init_val];"
			: [init_val] "+r" (init_val)
			: [data] "rm" (data));
	return init_val;
}
static inline uint32_t
crc32c_sse42_u32(uint32_t data, uint32_t init_val)
{
	__asm__ volatile(
			"crc32l %[data], %[init_val];"
			: [init_val] "+r" (init_val)
			: [data] "rm" (data));
	return init_val;
}
static inline uint32_t
crc32c_sse42_u64_mimic(uint64_t data, uint64_t init_val)
{
	union
{
		uint32_t u32[2];
		uint64_t u64;
	} d;
	d.u64 = data;
	init_val = crc32c_sse42_u32(d.u32[0], init_val);
	init_val = crc32c_sse42_u32(d.u32[1], init_val);
	return init_val;
}
static inline uint32_t
crc32c_sse42_u64(uint64_t data, uint64_t init_val)
{
	__asm__ volatile(
			"crc32q %[data], %[init_val];"
			: [init_val] "+r" (init_val)
			: [data] "rm" (data));
	return init_val;
}
static uint8_t crc32_alg = (1U << 0);


/**
	* Allow or disallow use of SSE4.2 instrinsics for CRC32 hash
	* calculation.
	* @param alg
	*/
static inline void
rte_hash_crc_set_alg(uint8_t alg)
{
	switch (alg)
{
	case ((1U << 2)|(1U << 1)):
		if (! rte_cpu_get_flag_enabled(RTE_CPUFLAG_EM64T))
			alg = (1U << 1);
	case (1U << 1):
		if (! rte_cpu_get_flag_enabled(RTE_CPUFLAG_SSE4_2))
			alg = (1U << 0);
	case (1U << 0):
		crc32_alg = alg;
	default:
		break;
	}
}



static inline void __attribute__((constructor))
rte_hash_crc_init_alg(void)
{
	rte_hash_crc_set_alg(((1U << 2)|(1U << 1)));
}


/**
	* Use single crc32 instruction to perform a hash on a byte value.
	* Fall back to software crc32 implementation in case SSE4.2 is
	* not supported
	* @param data
	* @param init_val
	* @return
	*/
static inline uint32_t
rte_hash_crc_1byte(uint8_t data, uint32_t init_val)
{
	if (__builtin_expect((crc32_alg & (1U << 1)),1))
		return crc32c_sse42_u8(data, init_val);
	return crc32c_1byte(data, init_val);
}


/**
	* Use single crc32 instruction to perform a hash on a 2 bytes value.
	* Fall back to software crc32 implementation in case SSE4.2 is
	* not supported
	* @param data
	* @param init_val
	* @return
	*/
static inline uint32_t
rte_hash_crc_2byte(uint16_t data, uint32_t init_val)
{
	if (__builtin_expect((crc32_alg & (1U << 1)),1))
		return crc32c_sse42_u16(data, init_val);
	return crc32c_2bytes(data, init_val);
}


/**
	* Use single crc32 instruction to perform a hash on a 4 byte value.
	* Fall back to software crc32 implementation in case SSE4.2 is
	* not supported
	* @param data
	* @param init_val
	* @return
	*/
static inline uint32_t
rte_hash_crc_4byte(uint32_t data, uint32_t init_val)
{
	if (__builtin_expect((crc32_alg & (1U << 1)),1))
		return crc32c_sse42_u32(data, init_val);
	return crc32c_1word(data, init_val);
}


/**
	* Use single crc32 instruction to perform a hash on a 8 byte value.
	* Fall back to software crc32 implementation in case SSE4.2 is
	* not supported
	* @param data
	* @param init_val
	* @return
	*/
static inline uint32_t
rte_hash_crc_8byte(uint64_t data, uint32_t init_val)
{
	if (__builtin_expect((crc32_alg == ((1U << 2)|(1U << 1))),1))
		return crc32c_sse42_u64(data, init_val);
	if (__builtin_expect((crc32_alg & (1U << 1)),1))
		return crc32c_sse42_u64_mimic(data, init_val);
	return crc32c_2words(data, init_val);
}


/**
	* Calculate CRC32 hash on user-supplied byte array.
	* @param data
	* @param data_len
	* @param init_val
	* @return
	*/
static inline uint32_t
rte_hash_crc(const void *data, uint32_t data_len, uint32_t init_val)
{
	unsigned i;
	uintptr_t pd = (uintptr_t) data;
	for (i = 0; i < data_len / 8; i++)
{
		init_val = rte_hash_crc_8byte(*(const uint64_t *)pd, init_val);
		pd += 8;
	}
	if (data_len & 0x4)
{
		init_val = rte_hash_crc_4byte(*(const uint32_t *)pd, init_val);
		pd += 4;
	}
	if (data_len & 0x2)
{
		init_val = rte_hash_crc_2byte(*(const uint16_t *)pd, init_val);
		pd += 2;
	}
	if (data_len & 0x1)
		init_val = rte_hash_crc_1byte(*(const uint8_t *)pd, init_val);
	return init_val;
}


/*-
	*/


/**
	* @file
	* Simple API to dump out memory in a special hex format.
	*/


/**
* Dump out memory in a special hex dump format.
*
* @param f
*		A pointer to a file for output
* @param title
*		If not NULL this string is printed as a header to the output.
* @param buf
*		This is the buffer address to print out.
* @param len
*		The number of bytes to dump out
* @return
*		None.
*/
extern void
rte_hexdump(FILE *f, const char * title, const void * buf, unsigned int len);


/**
* Dump out memory in a hex format with colons between bytes.
*
* @param f
*		A pointer to a file for output
* @param title
*		If not NULL this string is printed as a header to the output.
* @param buf
*		This is the buffer address to print out.
* @param len
*		The number of bytes to dump out
* @return
*		None.
*/
void
rte_memdump(FILE *f, const char * title, const void * buf, unsigned int len);


/*   BSD LICENSE
	*/


/*
	* Copyright (c) 1982, 1986, 1990, 1993
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. All advertising materials mentioning features or use of this software
	* 4. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	* $FreeBSD: src/sys/netinet/in.h, 1.82 2003/10/25 09:37:10 ume Exp $
	*/


/**
	* @file
	* ICMP-related defines
	*/


/**
	* ICMP Header
	*/
struct icmp_hdr
{
	uint8_t icmp_type; 


	uint8_t icmp_code; 


	uint16_t icmp_cksum; 


	uint16_t icmp_ident; 


	uint16_t icmp_seq_nb; 


} __attribute__((__packed__));





/*-
	*/


/*-
	*/


/*
	* Copyright (c) 1982, 1986, 1990, 1993
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. All advertising materials mentioning features or use of this software
	* 4. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	* $FreeBSD: src/sys/netinet/in.h, 1.82 2003/10/25 09:37:10 ume Exp $
	*/


/**
	* @file
	* IP-related defines
	*/


/*-
	*/


/*-
	*/


/**
	* IPv4 Header
	*/
struct ipv4_hdr
{
	uint8_t version_ihl; 


	uint8_t type_of_service; 


	uint16_t total_length; 


	uint16_t packet_id; 


	uint16_t fragment_offset; 


	uint8_t time_to_live; 


	uint8_t next_proto_id; 


	uint16_t hdr_checksum; 


	uint32_t src_addr; 


	uint32_t dst_addr; 


} __attribute__((__packed__));











/**
	* Internet header length field multiplier (IHL field specifies overall header
	* length in number of 4-byte words)
	*/





/*
	* IPv4 address types
	*/


/*
	* IPv4 Multicast-related macros
	*/


/**
	* @internal Calculate a sum of all words in the buffer.
	* Helper routine for the rte_raw_cksum().
	* @param buf
	* @param len
	* @param sum
	* @return
	*/
static inline uint32_t
__rte_raw_cksum(const void *buf, size_t len, uint32_t sum)
{


	uintptr_t ptr = (uintptr_t)buf;
	typedef uint16_t __attribute__((__may_alias__)) u16_p;
	const u16_p *u16 = (const u16_p *)ptr;
	while (len >= (sizeof(*u16) * 4))
{
		sum += u16[0];
		sum += u16[1];
		sum += u16[2];
		sum += u16[3];
		len -= sizeof(*u16) * 4;
		u16 += 4;
	}
	while (len >= sizeof(*u16))
{
		sum += *u16;
		len -= sizeof(*u16);
		u16 += 1;
	}


	if (len == 1)
		sum += *((const uint8_t *)u16);
	return sum;
}


/**
	* @internal Reduce a sum to the non-complemented checksum.
	* Helper routine for the rte_raw_cksum().
	* @param sum
	* @return
	*/
static inline uint16_t
__rte_raw_cksum_reduce(uint32_t sum)
{
	sum = ((sum & 0xffff0000) >> 16) + (sum & 0xffff);
	sum = ((sum & 0xffff0000) >> 16) + (sum & 0xffff);
	return (uint16_t)sum;
}


/**
	* Process the non-complemented checksum of a buffer.
	* @param buf
	* @param len
	* @return
	*/
static inline uint16_t
rte_raw_cksum(const void *buf, size_t len)
{
	uint32_t sum;
	sum = __rte_raw_cksum(buf, len, 0);
	return __rte_raw_cksum_reduce(sum);
}


/**
	* Process the IPv4 checksum of an IPv4 header.
	* The checksum field must be set to 0 by the caller.
	* @param ipv4_hdr
	* @return
	*/
static inline uint16_t
rte_ipv4_cksum(const struct ipv4_hdr *ipv4_hdr)
{
	uint16_t cksum;
	cksum = rte_raw_cksum(ipv4_hdr, sizeof(struct ipv4_hdr));
	return (cksum == 0xffff) ? cksum : ~cksum;
}


/**
	* Process the pseudo-header checksum of an IPv4 header.
	* The checksum field must be set to 0 by the caller.
	* Depending on the ol_flags, the pseudo-header checksum expected by the
	* drivers is not the same. For instance, when TSO is enabled, the IP
	* payload length must not be included in the packet.
	* When ol_flags is 0, it computes the standard pseudo-header checksum.
	* @param ipv4_hdr
	* @param ol_flags
	* @return
	*/
static inline uint16_t
rte_ipv4_phdr_cksum(const struct ipv4_hdr *ipv4_hdr, uint64_t ol_flags)
{
	struct ipv4_psd_header
{
		uint32_t src_addr; 


		uint32_t dst_addr; 


		uint8_t zero; 


		uint8_t proto; 


		uint16_t len; 


	} psd_hdr;
	psd_hdr.src_addr = ipv4_hdr->src_addr;
	psd_hdr.dst_addr = ipv4_hdr->dst_addr;
	psd_hdr.zero = 0;
	psd_hdr.proto = ipv4_hdr->next_proto_id;
	if (ol_flags & (1ULL << 50))
{
		psd_hdr.len = 0;
	} else
{
		psd_hdr.len = ((uint16_t)(__builtin_constant_p((uint16_t)(((uint16_t)(__builtin_constant_p(ipv4_hdr->total_length) ? rte_constant_bswap16(ipv4_hdr->total_length) : rte_arch_bswap16(ipv4_hdr->total_length))) - sizeof(struct ipv4_hdr))) ? rte_constant_bswap16((uint16_t)(((uint16_t)(__builtin_constant_p(ipv4_hdr->total_length) ? rte_constant_bswap16(ipv4_hdr->total_length) : rte_arch_bswap16(ipv4_hdr->total_length))) - sizeof(struct ipv4_hdr))) : rte_arch_bswap16((uint16_t)(((uint16_t)(__builtin_constant_p(ipv4_hdr->total_length) ? rte_constant_bswap16(ipv4_hdr->total_length) : rte_arch_bswap16(ipv4_hdr->total_length))) - sizeof(struct ipv4_hdr)))));
	}
	return rte_raw_cksum(&psd_hdr, sizeof(psd_hdr));
}


/**
	* Process the IPv4 UDP or TCP checksum.
	* The IPv4 header should not contains options. The IP and layer 4
	* checksum must be set to 0 in the packet by the caller.
	* @param ipv4_hdr
	* @param l4_hdr
	* @return
	*/
static inline uint16_t
rte_ipv4_udptcp_cksum(const struct ipv4_hdr *ipv4_hdr, const void *l4_hdr)
{
	uint32_t cksum;
	uint32_t l4_len;
	l4_len = ((uint16_t)(__builtin_constant_p(ipv4_hdr->total_length) ? rte_constant_bswap16(ipv4_hdr->total_length) : rte_arch_bswap16(ipv4_hdr->total_length))) -
		sizeof(struct ipv4_hdr);
	cksum = rte_raw_cksum(l4_hdr, l4_len);
	cksum += rte_ipv4_phdr_cksum(ipv4_hdr, 0);
	cksum = ((cksum & 0xffff0000) >> 16) + (cksum & 0xffff);
	cksum = (~cksum) & 0xffff;
	if (cksum == 0)
		cksum = 0xffff;
	return cksum;
}


/**
	* IPv6 Header
	*/
struct ipv6_hdr
{
	uint32_t vtc_flow; 


	uint16_t payload_len; 


	uint8_t proto; 


	uint8_t hop_limits; 


	uint8_t src_addr[16]; 


	uint8_t dst_addr[16]; 


} __attribute__((__packed__));


/**
	* Process the pseudo-header checksum of an IPv6 header.
	* Depending on the ol_flags, the pseudo-header checksum expected by the
	* drivers is not the same. For instance, when TSO is enabled, the IPv6
	* payload length must not be included in the packet.
	* When ol_flags is 0, it computes the standard pseudo-header checksum.
	* @param ipv6_hdr
	* @param ol_flags
	* @return
	*/
static inline uint16_t
rte_ipv6_phdr_cksum(const struct ipv6_hdr *ipv6_hdr, uint64_t ol_flags)
{
	uint32_t sum;
	struct
{
		uint32_t len; 


		uint32_t proto; 


	} psd_hdr;
	psd_hdr.proto = (ipv6_hdr->proto << 24);
	if (ol_flags & (1ULL << 50))
{
		psd_hdr.len = 0;
	} else
{
		psd_hdr.len = ipv6_hdr->payload_len;
	}
	sum = __rte_raw_cksum(ipv6_hdr->src_addr,
		sizeof(ipv6_hdr->src_addr) + sizeof(ipv6_hdr->dst_addr),
		0);
	sum = __rte_raw_cksum(&psd_hdr, sizeof(psd_hdr), sum);
	return __rte_raw_cksum_reduce(sum);
}


/**
	* Process the IPv6 UDP or TCP checksum.
	* The IPv4 header should not contains options. The layer 4 checksum
	* must be set to 0 in the packet by the caller.
	* @param ipv6_hdr
	* @param l4_hdr
	* @return
	*/
static inline uint16_t
rte_ipv6_udptcp_cksum(const struct ipv6_hdr *ipv6_hdr, const void *l4_hdr)
{
	uint32_t cksum;
	uint32_t l4_len;
	l4_len = ((uint16_t)(__builtin_constant_p(ipv6_hdr->payload_len) ? rte_constant_bswap16(ipv6_hdr->payload_len) : rte_arch_bswap16(ipv6_hdr->payload_len)));
	cksum = rte_raw_cksum(l4_hdr, l4_len);
	cksum += rte_ipv6_phdr_cksum(ipv6_hdr, 0);
	cksum = ((cksum & 0xffff0000) >> 16) + (cksum & 0xffff);
	cksum = (~cksum) & 0xffff;
	if (cksum == 0)
		cksum = 0xffff;
	return cksum;
}


/*-
	*/


/**
	* @file
	* RTE IP Fragmentation and Reassembly
	* Implementation of IP packet fragmentation and reassembly.
	*/


/*-
	*/


/**
	* @file
	* RTE Malloc. This library provides methods for dynamically allocating memory
	* from hugepages.
	*/


/*-
	*/


/**
	*  Structure to hold heap statistics obtained from rte_malloc_get_socket_stats function.
	*/
struct rte_malloc_socket_stats
{
	size_t heap_totalsz_bytes; 


	size_t heap_freesz_bytes; 


	size_t greatest_free_size; 


	unsigned free_count; 


	unsigned alloc_count; 


	size_t heap_allocsz_bytes; 


};


/**
	* This function allocates memory from the huge-page area of memory. The memory
	* is not cleared. In NUMA systems, the memory allocated resides on the same
	* NUMA socket as the core that calls this function.
	* @param type
	* @param size
	* @param align
	* @return
	*/
void *
rte_malloc(const char *type, size_t size, unsigned align);


/**
	* Allocate zero'ed memory from the heap.
	* Equivalent to rte_malloc() except that the memory zone is
	* initialised with zeros. In NUMA systems, the memory allocated resides on the
	* same NUMA socket as the core that calls this function.
	* @param type
	* @param size
	* @param align
	* @return
	*/
void *
rte_zmalloc(const char *type, size_t size, unsigned align);


/**
	* Replacement function for calloc(), using huge-page memory. Memory area is
	* initialised with zeros. In NUMA systems, the memory allocated resides on the
	* same NUMA socket as the core that calls this function.
	* @param type
	* @param num
	* @param size
	* @param align
	* @return
	*/
void *
rte_calloc(const char *type, size_t num, size_t size, unsigned align);


/**
	* Replacement function for realloc(), using huge-page memory. Reserved area
	* memory is resized, preserving contents. In NUMA systems, the new area
	* resides on the same NUMA socket as the old area.
	* @param ptr
	* @param size
	* @param align
	* @return
	*/
void *
rte_realloc(void *ptr, size_t size, unsigned align);


/**
	* This function allocates memory from the huge-page area of memory. The memory
	* is not cleared.
	* @param type
	* @param size
	* @param align
	* @param socket
	* @return
	*/
void *
rte_malloc_socket(const char *type, size_t size, unsigned align, int socket);


/**
	* Allocate zero'ed memory from the heap.
	* Equivalent to rte_malloc() except that the memory zone is
	* initialised with zeros.
	* @param type
	* @param size
	* @param align
	* @param socket
	* @return
	*/
void *
rte_zmalloc_socket(const char *type, size_t size, unsigned align, int socket);


/**
	* Replacement function for calloc(), using huge-page memory. Memory area is
	* initialised with zeros.
	* @param type
	* @param num
	* @param size
	* @param align
	* @param socket
	* @return
	*/
void *
rte_calloc_socket(const char *type, size_t num, size_t size, unsigned align, int socket);


/**
	* Frees the memory space pointed to by the provided pointer.
	* This pointer must have been returned by a previous call to
	* rte_malloc(), rte_zmalloc(), rte_calloc() or rte_realloc(). The behaviour of
	* rte_free() is undefined if the pointer does not match this requirement.
	* If the pointer is NULL, the function does nothing.
	* @param ptr
	*/
void
rte_free(void *ptr);


/**
	* If malloc debug is enabled, check a memory block for header
	* and trailer markers to indicate that all is well with the block.
	* If size is non-null, also return the size of the block.
	* @param ptr
	* @param size
	* @return
	*/
int
rte_malloc_validate(const void *ptr, size_t *size);


/**
	* Get heap statistics for the specified heap.
	* @param socket
	* @param socket_stats
	* @return
	*/
int
rte_malloc_get_socket_stats(int socket,
		struct rte_malloc_socket_stats *socket_stats);


/**
	* Dump statistics.
	* Dump for the specified type to the console. If the type argument is
	* NULL, all memory types will be dumped.
	* @param f
	* @param type
	*/
void
rte_malloc_dump_stats(FILE *f, const char *type);


/**
	* Set the maximum amount of allocated memory for this type.
	* This is not yet implemented
	* @param type
	* @param max
	* @return
	*/
int
rte_malloc_set_limit(const char *type, size_t max);


/**
	* Return the physical address of a virtual address obtained through
	* rte_malloc
	* @param addr
	* @return
	*/
phys_addr_t
rte_malloc_virt2phy(const void *addr);


/*-
	*/


/*-
	*/


/*
	* Copyright (c) 1982, 1986, 1990, 1993
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. All advertising materials mentioning features or use of this software
	* 4. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	* $FreeBSD: src/sys/netinet/in.h, 1.82 2003/10/25 09:37:10 ume Exp $
	*/


/*-
	*/
struct rte_mbuf;
enum
{
	IP_LAST_FRAG_IDX, 


	IP_FIRST_FRAG_IDX, 


	IP_MIN_FRAG_NUM, 


	IP_MAX_FRAG_NUM = 4,


};



struct ip_frag
{
	uint16_t ofs; 


	uint16_t len; 


	struct rte_mbuf *mb; 


};



struct ip_frag_key
{
	uint64_t src_dst[4]; 


	uint32_t id; 


	uint32_t key_len; 


};


/**
	* @internal Fragmented packet to reassemble.
	* First two entries in the frags[] array are for the last and first fragments.
	*/
struct ip_frag_pkt
{
	struct { struct ip_frag_pkt *tqe_next; struct ip_frag_pkt * *tqe_prev; } lru; 


	struct ip_frag_key key; 


	uint64_t start; 


	uint32_t total_size; 


	uint32_t frag_size; 


	uint32_t last_idx; 


	struct ip_frag frags[IP_MAX_FRAG_NUM]; 


} __attribute__((__aligned__(64)));



struct rte_ip_frag_death_row
{
	uint32_t cnt; 


	struct rte_mbuf *row[32 * (IP_MAX_FRAG_NUM + 1)];


};
struct ip_pkt_list { struct ip_frag_pkt *tqh_first; struct ip_frag_pkt * *tqh_last; }; 





struct ip_frag_tbl_stat
{
	uint64_t find_num; 


	uint64_t add_num; 


	uint64_t del_num; 


	uint64_t reuse_num; 


	uint64_t fail_total; 


	uint64_t fail_nospace; 


} __attribute__((__aligned__(64)));



struct rte_ip_frag_tbl
{
	uint64_t max_cycles; 


	uint32_t entry_mask; 


	uint32_t max_entries; 


	uint32_t use_entries; 


	uint32_t bucket_entries; 


	uint32_t nb_entries; 


	uint32_t nb_buckets; 


	struct ip_frag_pkt *last; 


	struct ip_pkt_list lru; 


	struct ip_frag_tbl_stat stat; 


	struct ip_frag_pkt pkt[]; 


};



struct ipv6_extension_fragment
{
	uint8_t next_header; 


	uint8_t reserved; 


	uint16_t frag_data; 


	uint32_t id; 


} __attribute__((__packed__));


/**
	* Create a new IP fragmentation table.
	* @param bucket_num
	* @param bucket_entries
	* @param max_entries
	* @param max_cycles
	* @param socket_id
	* @return
	*/
struct rte_ip_frag_tbl * rte_ip_frag_table_create(uint32_t bucket_num,
		uint32_t bucket_entries, uint32_t max_entries,
		uint64_t max_cycles, int socket_id);


/**
	* Free allocated IP fragmentation table.
	* @param tbl
	*/
static inline void
rte_ip_frag_table_destroy(struct rte_ip_frag_tbl *tbl)
{
	rte_free(tbl);
}


/**
	* This function implements the fragmentation of IPv6 packets.
	* @param pkt_in
	* @param pkts_out
	* @param nb_pkts_out
	* @param mtu_size
	* @param pool_direct
	* @param pool_indirect
	* @return
	*/
int32_t
rte_ipv6_fragment_packet(struct rte_mbuf *pkt_in,
		struct rte_mbuf **pkts_out,
		uint16_t nb_pkts_out,
		uint16_t mtu_size,
		struct rte_mempool *pool_direct,
		struct rte_mempool *pool_indirect);


/**
	* This function implements reassembly of fragmented IPv6 packets.
	* Incoming mbuf should have its l2_len/l3_len fields setup correctly.
	* @param tbl
	* @param dr
	* @param mb
	* @param tms
	* @param ip_hdr
	* @param frag_hdr
	* @return
	*/
struct rte_mbuf *rte_ipv6_frag_reassemble_packet(struct rte_ip_frag_tbl *tbl,
		struct rte_ip_frag_death_row *dr,
		struct rte_mbuf *mb, uint64_t tms, struct ipv6_hdr *ip_hdr,
		struct ipv6_extension_fragment *frag_hdr);


/**
	* Return a pointer to the packet's fragment header, if found.
	* It only looks at the extension header that's right after the fixed IPv6
	* header, and doesn't follow the whole chain of extension headers.
	* @param hdr
	* @return
	*/
static inline struct ipv6_extension_fragment *
rte_ipv6_frag_get_ipv6_fragment_header(struct ipv6_hdr *hdr)
{
	if (hdr->proto == IPPROTO_FRAGMENT)
{
		return (struct ipv6_extension_fragment *) ++hdr;
	}
	else
		return NULL;
}


/**
	* IPv4 fragmentation.
	* This function implements the fragmentation of IPv4 packets.
	* @param pkt_in
	* @param pkts_out
	* @param nb_pkts_out
	* @param mtu_size
	* @param pool_direct
	* @param pool_indirect
	* @return
	*/
int32_t rte_ipv4_fragment_packet(struct rte_mbuf *pkt_in,
			struct rte_mbuf **pkts_out,
			uint16_t nb_pkts_out, uint16_t mtu_size,
			struct rte_mempool *pool_direct,
			struct rte_mempool *pool_indirect);


/**
	* This function implements reassembly of fragmented IPv4 packets.
	* Incoming mbufs should have its l2_len/l3_len fields setup correclty.
	* @param tbl
	* @param dr
	* @param mb
	* @param tms
	* @param ip_hdr
	* @return
	*/
struct rte_mbuf * rte_ipv4_frag_reassemble_packet(struct rte_ip_frag_tbl *tbl,
		struct rte_ip_frag_death_row *dr,
		struct rte_mbuf *mb, uint64_t tms, struct ipv4_hdr *ip_hdr);


/**
	* Check if the IPv4 packet is fragmented
	* @param hdr
	* @return
	*/
static inline int
rte_ipv4_frag_pkt_is_fragmented(const struct ipv4_hdr * hdr)
{
	uint16_t flag_offset, ip_flag, ip_ofs;
	flag_offset = ((uint16_t)(__builtin_constant_p(hdr->fragment_offset) ? rte_constant_bswap16(hdr->fragment_offset) : rte_arch_bswap16(hdr->fragment_offset)));
	ip_ofs = (uint16_t)(flag_offset & ((1 << 13) - 1));
	ip_flag = (uint16_t)(flag_offset & (1 << 13));
	return ip_flag != 0 || ip_ofs != 0;
}


/**
	* Free mbufs on a given death row.
	* @param dr
	* @param prefetch
	*/
void rte_ip_frag_free_death_row(struct rte_ip_frag_death_row *dr,
		uint32_t prefetch);


/**
	* Dump fragmentation table statistics to file.
	* @param f
	* @param tbl
	*/
void
rte_ip_frag_table_statistics_dump(FILE * f, const struct rte_ip_frag_tbl *tbl);


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/



struct rte_jobstats_context;
struct rte_jobstats;


/**
	* This function should calculate new period and set it using
	* rte_jobstats_set_period() function. Time spent in this function will be
	* added to job's runtime.
	* @param job
	*  The job data structure handler.
	* @param job_result
	*  Result of calling job callback.
	*/
typedef void (*rte_job_update_period_cb_t)(struct rte_jobstats *job,
		int64_t job_result);
struct rte_jobstats
{
	uint64_t period;


	uint64_t min_period;


	uint64_t max_period;


	int64_t target;


	rte_job_update_period_cb_t update_period_cb;


	uint64_t exec_time;


	uint64_t min_exec_time;


	uint64_t max_exec_time;


	uint64_t exec_cnt;


	char name[32];


	struct rte_jobstats_context *context;


} __attribute__((__aligned__(64)));
struct rte_jobstats_context
{

/** Viariable holding time at different points:
	 * -# loop start time if loop was started but no job executed yet.
	 * -# job start time if job is currently executing.
	 * -# job finish time if job finished its execution.
	 * -# loop finish time if loop finished its execution. */
	uint64_t state_time;
	uint64_t loop_executed_jobs;




	uint64_t exec_time;


	uint64_t min_exec_time;


	uint64_t max_exec_time;



/**
	 * Sum of time that is not the execute time (ex: from job finish to next
	 * job start).
	 *
	 * This time might be considered as overhead of library + job scheduling.
	 */
	uint64_t management_time;
	uint64_t min_management_time;


	uint64_t max_management_time;


	uint64_t start_time;


	uint64_t job_exec_cnt;


	uint64_t loop_cnt;


} __attribute__((__aligned__(64)));


/**
	* Initialize given context object with default values.
	* @param ctx
	*  Job stats context object to initialize.
	* @return
	*  0 on success
	*  -EINVAL if *ctx* is NULL
	*/
int
rte_jobstats_context_init(struct rte_jobstats_context *ctx);


/**
	* Mark that new set of jobs start executing.
	* @param ctx
	*  Job stats context object.
	*/
void
rte_jobstats_context_start(struct rte_jobstats_context *ctx);


/**
	* Mark that there is no more jobs ready to execute in this turn. Calculate
	* stats for this loop turn.
	* @param ctx
	*  Job stats context.
	*/
void
rte_jobstats_context_finish(struct rte_jobstats_context *ctx);


/**
	* Function resets job context statistics.
	* @param ctx
	*  Job stats context which statistics will be reset.
	*/
void
rte_jobstats_context_reset(struct rte_jobstats_context *ctx);


/**
	* Initialize given job stats object.
	* @param job
	*  Job object.
	* @param name
	*  Optional job name.
	* @param min_period
	*  Minimum period that this job can accept.
	* @param max_period
	*  Maximum period that this job can accept.
	* @param initial_period
	*  Initial period. It will be checked against *min_period* and *max_period*.
	* @param target
	*  Target value that this job try to achieve.
	* @return
	*  0 on success
	*  -EINVAL if *job* is NULL
	*/
int
rte_jobstats_init(struct rte_jobstats *job, const char *name,
		uint64_t min_period, uint64_t max_period, uint64_t initial_period,
		int64_t target);


/**
	* Set job desired target value. Difference between target and job value
	* value must be used to properly adjust job execute period value.
	* @param job
	*  The job object.
	* @param target
	*  New target.
	*/
void
rte_jobstats_set_target(struct rte_jobstats *job, int64_t target);


/**
	* Mark that *job* is starting of its execution in context of *ctx* object.
	* @param ctx
	*  Job stats context.
	* @param job
	*  Job object.
	* @return
	*  0 on success
	*  -EINVAL if *ctx* or *job* is NULL or *job* is executing in another context
	*  context already,
	*/
int
rte_jobstats_start(struct rte_jobstats_context *ctx, struct rte_jobstats *job);


/**
	* Mark that *job* finished its execution, but time of this work will be skipped
	* and added to management time.
	* @param job
	*  Job object.
	* @return
	*  0 on success
	*  -EINVAL if job is NULL or job was not started (it have no context).
	*/
int
rte_jobstats_abort(struct rte_jobstats *job);


/**
	* Mark that *job* finished its execution. Context in which it was executing
	* will receive stat update. After this function call *job* object is ready to
	* be executed in other context.
	* @param job
	*  Job object.
	* @param job_value
	*  Job value. Job should pass in this parameter a value that it try to optimize
	*  for example the number of packets it processed.
	* @return
	*  0 if job's period was not updated (job target equals *job_value*)
	*  1 if job's period was updated
	*  -EINVAL if job is NULL or job was not started (it have no context).
	*/
int
rte_jobstats_finish(struct rte_jobstats *job, int64_t job_value);


/**
	* Set execute period of given job.
	* @param job
	*  The job object.
	* @param period
	*  New period value.
	* @param saturate
	*  If zero, skip period saturation to min, max range.
	*/
void
rte_jobstats_set_period(struct rte_jobstats *job, uint64_t period,
		uint8_t saturate);


/**
	* Set minimum execute period of given job. Current period will be checked
	* against new minimum value.
	* @param job
	*  The job object.
	* @param period
	*  New minimum period value.
	*/
void
rte_jobstats_set_min(struct rte_jobstats *job, uint64_t period);


/**
	* Set maximum execute period of given job. Current period will be checked
	* against new maximum value.
	* @param job
	*  The job object.
	* @param period
	*  New maximum period value.
	*/
void
rte_jobstats_set_max(struct rte_jobstats *job, uint64_t period);


/**
	* Set update period callback that is invoked after job finish.
	* If application wants to do more sophisticated calculations than default
	* it can provide this handler.
	* @param job
	*  Job object.
	* @param update_pedriod_cb
	*  Callback to set. If NULL restore default update function.
	*/
void
rte_jobstats_set_update_period_function(struct rte_jobstats *job,
		rte_job_update_period_cb_t update_period_cb);


/**
	* Function resets job statistics.
	* @param job
	*  Job which statistics will be reset.
	*/
void
rte_jobstats_reset(struct rte_jobstats *job);


/*-
	*/


/**
	* @file rte_keepalive.h
	* DPDK RTE LCore Keepalive Monitor.
	**/


/*-
	*/


/**
	* Number of cores to track.
	* @note Must be larger than the highest core id. */
enum rte_keepalive_state
{
	RTE_KA_STATE_UNUSED = 0,
	RTE_KA_STATE_ALIVE = 1,
	RTE_KA_STATE_MISSING = 4,
	RTE_KA_STATE_DEAD = 2,
	RTE_KA_STATE_GONE = 3,
	RTE_KA_STATE_DOZING = 5,
	RTE_KA_STATE_SLEEP = 6
};


/**
	* Keepalive failure callback.
	*  Receives a data pointer passed to rte_keepalive_create() and the id of the
	*  failed core.
	*  @param data Data pointer passed to rte_keepalive_create()
	*  @param id_core ID of the core that has failed
	*/
typedef void (*rte_keepalive_failure_callback_t)(
	void *data,
	const int id_core);


/**
	* Keepalive relay callback.
	*  Receives a data pointer passed to rte_keepalive_register_relay_callback(),
	*  the id of the core for which state is to be forwarded, and details of the
	*  current core state.
	*  @param data Data pointer passed to rte_keepalive_register_relay_callback()
	*  @param id_core ID of the core for which state is being reported
	*  @param core_state The current state of the core
	*  @param Timestamp of when core was last seen alive
	*/
typedef void (*rte_keepalive_relay_callback_t)(
	void *data,
	const int id_core,
	enum rte_keepalive_state core_state,
	uint64_t last_seen
	);


/**
	* Keepalive state structure.
	* @internal
	*/
struct rte_keepalive;


/**
	* Initialise keepalive sub-system.
	* @param callback
	* @param data
	* @return
	*/
struct rte_keepalive *rte_keepalive_create(
	rte_keepalive_failure_callback_t callback,
	void *data);


/**
	* Checks & handles keepalive state of monitored cores.
	* @param *ptr_timer Triggering timer (unused)
	* @param *ptr_data  Data pointer (keepalive structure)
	*/
void rte_keepalive_dispatch_pings(void *ptr_timer, void *ptr_data);


/**
	* Registers a core for keepalive checks.
	* @param *keepcfg
	* @param id_core
	*/
void rte_keepalive_register_core(struct rte_keepalive *keepcfg,
	const int id_core);


/**
	* Per-core keepalive check.
	* @param *keepcfg
	* This function needs to be called from within the main process loop of
	* the LCore to be checked.
	*/
void
rte_keepalive_mark_alive(struct rte_keepalive *keepcfg);


/**
	* Per-core sleep-time indication.
	* @param *keepcfg
	* If CPU idling is enabled, this function needs to be called from within
	* the main process loop of the LCore going to sleep, in order to avoid
	* the LCore being mis-detected as dead.
	*/
void
rte_keepalive_mark_sleep(struct rte_keepalive *keepcfg);


/**
	* Registers a 'live core' callback.
	* The complement of the 'dead core' callback. This is called when a
	* core is known to be alive, and is intended for cases when an app
	* needs to know 'liveness' beyond just knowing when a core has died.
	* @param *keepcfg
	* @param callback
	* @param data
	*/
void
rte_keepalive_register_relay_callback(struct rte_keepalive *keepcfg,
	rte_keepalive_relay_callback_t callback,
	void *data);


/*-
	*/


/**
	* @file
	* RTE Argument parsing
	* This module can be used to parse arguments whose format is
	* key1=value1,key2=value2,key3=value3,...
	* The same key can appear several times with the same or a different
	* value. Indeed, the arguments are stored as a list of key/values
	* associations and not as a dictionary.
	* This file provides some helpers that are especially used by virtual
	* ethernet devices at initialization for arguments parsing.
	*/












typedef int (*arg_handler_t)(const char *key, const char *value, void *opaque);



struct rte_kvargs_pair
{
	char *key; 


	char *value; 


};



struct rte_kvargs
{
	char *str; 


	unsigned count; 


	struct rte_kvargs_pair pairs[32]; 


};


/**
	* Allocate a rte_kvargs and store key/value associations from a string
	* The function allocates and fills a rte_kvargs structure from a given
	* string whose format is key1=value1,key2=value2,...
	* The structure can be freed with rte_kvargs_free().
	* @param args
	* @param valid_keys
	* @return
	*/
struct rte_kvargs *rte_kvargs_parse(const char *args, const char *valid_keys[]);


/**
	* Free a rte_kvargs structure
	* Free a rte_kvargs structure previously allocated with
	* rte_kvargs_parse().
	* @param kvlist
	*/
void rte_kvargs_free(struct rte_kvargs *kvlist);


/**
	* Call a handler function for each key/value matching the key
	* For each key/value association that matches the given key, calls the
	* handler function with the for a given arg_name passing the value on the
	* dictionary for that key and a given extra argument. If *kvlist* is NULL
	* function does nothing.
	* @param kvlist
	* @param key_match
	* @param handler
	* @param opaque_arg
	* @return
	*/
int rte_kvargs_process(const struct rte_kvargs *kvlist,
	const char *key_match, arg_handler_t handler, void *opaque_arg);


/**
	* Count the number of associations matching the given key
	* @param kvlist
	* @param key_match

	* @return
	*/
unsigned rte_kvargs_count(const struct rte_kvargs *kvlist,
	const char *key_match);


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* RTE Longest Prefix Match (LPM)
	*/


/*
	* Copyright (c) 1991, 1993
	*	The Regents of the University of California.  All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	*	@(#)queue.h	8.5 (Berkeley) 8/20/94
	*/


/*-
	*/


/**
	* @file
	* Branch Prediction Helpers in RTE
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*
	* No symbol versioning in use
	*/


/*
	* RTE_BUILD_SHARED_LIB=n
	*/

































__extension__
struct rte_lpm_tbl_entry_v20
{

/**
	 * Stores Next hop (tbl8 or tbl24 when valid_group is not set) or
	 * a group index pointing to a tbl8 structure (tbl24 only, when
	 * valid_group is set)
	 */

	union
{
		uint8_t next_hop;
		uint8_t group_idx;
	};


	uint8_t valid :1; 



/**
	 * For tbl24:
	 *  - valid_group == 0: entry stores a next hop
	 *  - valid_group == 1: entry stores a group_index pointing to a tbl8
	 * For tbl8:
	 *  - valid_group indicates whether the current tbl8 is in use or not
	 */
	uint8_t valid_group :1;
	uint8_t depth :6; 


};
__extension__
struct rte_lpm_tbl_entry
{

/**
	 * Stores Next hop (tbl8 or tbl24 when valid_group is not set) or
	 * a group index pointing to a tbl8 structure (tbl24 only, when
	 * valid_group is set)
	 */
	uint32_t next_hop :24;


	uint32_t valid :1; 



/**
	 * For tbl24:
	 *  - valid_group == 0: entry stores a next hop
	 *  - valid_group == 1: entry stores a group_index pointing to a tbl8
	 * For tbl8:
	 *  - valid_group indicates whether the current tbl8 is in use or not
	 */
	uint32_t valid_group :1;
	uint32_t depth :6; 


};



struct rte_lpm_config
{
	uint32_t max_rules; 


	uint32_t number_tbl8s; 


	int flags; 


};



struct rte_lpm_rule_v20
{
	uint32_t ip; 


	uint8_t next_hop; 


};
struct rte_lpm_rule
{
	uint32_t ip; 


	uint32_t next_hop; 


};



struct rte_lpm_rule_info
{
	uint32_t used_rules; 


	uint32_t first_rule; 


};



struct rte_lpm_v20
{


	char name[32]; 


	uint32_t max_rules; 


	struct rte_lpm_rule_info rule_info[32]; 




	struct rte_lpm_tbl_entry_v20 tbl24[(1 << 24)]
			__attribute__((__aligned__(64))); 


	struct rte_lpm_tbl_entry_v20 tbl8[(256 * 256)]
			__attribute__((__aligned__(64))); 


	struct rte_lpm_rule_v20 rules_tbl[]
			__attribute__((__aligned__(64))); 


};
struct rte_lpm
{


	char name[32]; 


	uint32_t max_rules; 


	uint32_t number_tbl8s; 


	struct rte_lpm_rule_info rule_info[32]; 




	struct rte_lpm_tbl_entry tbl24[(1 << 24)]
			__attribute__((__aligned__(64))); 


	struct rte_lpm_tbl_entry *tbl8; 


	struct rte_lpm_rule *rules_tbl; 


};


/**
	* Create an LPM object.
	* @param name
	* @param socket_id
	* @param config
	* @return
	*/
struct rte_lpm *
rte_lpm_create(const char *name, int socket_id,
		const struct rte_lpm_config *config);
struct rte_lpm_v20 *
rte_lpm_create_v20(const char *name, int socket_id, int max_rules, int flags);
struct rte_lpm *
rte_lpm_create_v1604(const char *name, int socket_id,
		const struct rte_lpm_config *config);


/**
	* Find an existing LPM object and return a pointer to it.
	* @param name
	* @return
	*/
struct rte_lpm *
rte_lpm_find_existing(const char *name);
struct rte_lpm_v20 *
rte_lpm_find_existing_v20(const char *name);
struct rte_lpm *
rte_lpm_find_existing_v1604(const char *name);


/**
	* Free an LPM object.
	* @param lpm
	* @return
	*/
void
rte_lpm_free(struct rte_lpm *lpm);
void
rte_lpm_free_v20(struct rte_lpm_v20 *lpm);
void
rte_lpm_free_v1604(struct rte_lpm *lpm);


/**
	* Add a rule to the LPM table.
	* @param lpm
	* @param ip
	* @param depth
	* @param next_hop
	* @return
	*/
int
rte_lpm_add(struct rte_lpm *lpm, uint32_t ip, uint8_t depth, uint32_t next_hop);
int
rte_lpm_add_v20(struct rte_lpm_v20 *lpm, uint32_t ip, uint8_t depth,
		uint8_t next_hop);
int
rte_lpm_add_v1604(struct rte_lpm *lpm, uint32_t ip, uint8_t depth,
		uint32_t next_hop);


/**
	* Check if a rule is present in the LPM table,
	* and provide its next hop if it is.
	* @param lpm
	* @param ip
	* @param depth
	* @param next_hop
	* @return
	*/
int
rte_lpm_is_rule_present(struct rte_lpm *lpm, uint32_t ip, uint8_t depth,
uint32_t *next_hop);
int
rte_lpm_is_rule_present_v20(struct rte_lpm_v20 *lpm, uint32_t ip, uint8_t depth,
uint8_t *next_hop);
int
rte_lpm_is_rule_present_v1604(struct rte_lpm *lpm, uint32_t ip, uint8_t depth,
uint32_t *next_hop);


/**
	* Delete a rule from the LPM table.
	* @param lpm
	* @param ip
	* @param depth
	* @return
	*/
int
rte_lpm_delete(struct rte_lpm *lpm, uint32_t ip, uint8_t depth);
int
rte_lpm_delete_v20(struct rte_lpm_v20 *lpm, uint32_t ip, uint8_t depth);
int
rte_lpm_delete_v1604(struct rte_lpm *lpm, uint32_t ip, uint8_t depth);


/**
	* Delete all rules from the LPM table.
	* @param lpm
	*/
void
rte_lpm_delete_all(struct rte_lpm *lpm);
void
rte_lpm_delete_all_v20(struct rte_lpm_v20 *lpm);
void
rte_lpm_delete_all_v1604(struct rte_lpm *lpm);


/**
	* Lookup an IP into the LPM table.
	* @param lpm
	* @param ip
	* @param next_hop
	* @return
	*/
static inline int
rte_lpm_lookup(struct rte_lpm *lpm, uint32_t ip, uint32_t *next_hop)
{
	unsigned tbl24_index = (ip >> 8);
	uint32_t tbl_entry;
	const uint32_t *ptbl;


	;


	ptbl = (const uint32_t *)(&lpm->tbl24[tbl24_index]);
	tbl_entry = *ptbl;


	if (__builtin_expect(((tbl_entry & 0x03000000) == 0x03000000),0))
{
		unsigned tbl8_index = (uint8_t)ip +
				(((uint32_t)tbl_entry & 0x00FFFFFF) *
						256);
		ptbl = (const uint32_t *)&lpm->tbl8[tbl8_index];
		tbl_entry = *ptbl;
	}
	*next_hop = ((uint32_t)tbl_entry & 0x00FFFFFF);
	return (tbl_entry & 0x01000000) ? 0 : -ENOENT;
}


/**
	* Lookup multiple IP addresses in an LPM table. This may be implemented as a
	* macro, so the address of the function should not be used.
	* @param lpm
	* @param ips
	* @param next_hops
	* @param n
	*  @return
	*/
static inline int
rte_lpm_lookup_bulk_func(const struct rte_lpm *lpm, const uint32_t *ips,
		uint32_t *next_hops, const unsigned n)
{
	unsigned i;
	unsigned tbl24_indexes[n];
	const uint32_t *ptbl;


	;
	for (i = 0; i < n; i++)
{
		tbl24_indexes[i] = ips[i] >> 8;
	}
	for (i = 0; i < n; i++)
{


		ptbl = (const uint32_t *)&lpm->tbl24[tbl24_indexes[i]];
		next_hops[i] = *ptbl;


		if (__builtin_expect(((next_hops[i] & 0x03000000) == 0x03000000),0))
{
			unsigned tbl8_index = (uint8_t)ips[i] +
					(((uint32_t)next_hops[i] & 0x00FFFFFF) *
						256);
			ptbl = (const uint32_t *)&lpm->tbl8[tbl8_index];
			next_hops[i] = *ptbl;
		}
	}
	return 0;
}





/**
	* Lookup four IP addresses in an LPM table.
	* @param lpm
	* @param ip
	* @param hop
	* @param defv
	*/
static inline void
rte_lpm_lookupx4(const struct rte_lpm *lpm, xmm_t ip, uint32_t hop[4],
	uint32_t defv);


/*-
	*/


/*-
	*/


/**
	* @file
	* Branch Prediction Helpers in RTE
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/
static inline void
rte_lpm_lookupx4(const struct rte_lpm *lpm, xmm_t ip, uint32_t hop[4],
	uint32_t defv)
{
	__m128i i24;
	rte_xmm_t i8;
	uint32_t tbl[4];
	uint64_t idx, pt, pt2;
	const uint32_t *ptbl;
	const __m128i mask8 =
		_mm_set_epi32(UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX);

/*
	 * RTE_LPM_VALID_EXT_ENTRY_BITMASK for 2 LPM entries
	 * as one 64-bit value (0x0300000003000000).
	 */
	const uint64_t mask_xv =
		((uint64_t)0x03000000 |
		(uint64_t)0x03000000 << 32);

/*
	 * RTE_LPM_LOOKUP_SUCCESS for 2 LPM entries
	 * as one 64-bit value (0x0100000001000000).
	 */
	const uint64_t mask_v =
		((uint64_t)0x01000000 |
		(uint64_t)0x01000000 << 32);


	i24 = _mm_srli_epi32(ip, CHAR_BIT);


	idx = _mm_cvtsi128_si64(i24);
	i24 = _mm_srli_si128(i24, sizeof(uint64_t));
	ptbl = (const uint32_t *)&lpm->tbl24[(uint32_t)idx];
	tbl[0] = *ptbl;
	ptbl = (const uint32_t *)&lpm->tbl24[idx >> 32];
	tbl[1] = *ptbl;
	idx = _mm_cvtsi128_si64(i24);
	ptbl = (const uint32_t *)&lpm->tbl24[(uint32_t)idx];
	tbl[2] = *ptbl;
	ptbl = (const uint32_t *)&lpm->tbl24[idx >> 32];
	tbl[3] = *ptbl;


	i8.x = _mm_and_si128(ip, mask8);
	pt = (uint64_t)tbl[0] |
		(uint64_t)tbl[1] << 32;
	pt2 = (uint64_t)tbl[2] |
		(uint64_t)tbl[3] << 32;


	if (__builtin_expect(((pt & mask_xv) == mask_v),1) &&
			__builtin_expect(((pt2 & mask_xv) == mask_v),1))
{
		*(uint64_t *)hop = pt & UINT64_C(0x00ffffff00ffffff);
		*(uint64_t *)(hop + 2) = pt2 & UINT64_C(0x00ffffff00ffffff);
		return;
	}
	if (__builtin_expect(((pt & 0x03000000) == 0x03000000),0))
{
		i8.u32[0] = i8.u32[0] +
			(uint8_t)tbl[0] * 256;
		ptbl = (const uint32_t *)&lpm->tbl8[i8.u32[0]];
		tbl[0] = *ptbl;
	}
	if (__builtin_expect(((pt >> 32 & 0x03000000) == 0x03000000),0))
{
		i8.u32[1] = i8.u32[1] +
			(uint8_t)tbl[1] * 256;
		ptbl = (const uint32_t *)&lpm->tbl8[i8.u32[1]];
		tbl[1] = *ptbl;
	}
	if (__builtin_expect(((pt2 & 0x03000000) == 0x03000000),0))
{
		i8.u32[2] = i8.u32[2] +
			(uint8_t)tbl[2] * 256;
		ptbl = (const uint32_t *)&lpm->tbl8[i8.u32[2]];
		tbl[2] = *ptbl;
	}
	if (__builtin_expect(((pt2 >> 32 & 0x03000000) == 0x03000000),0))
{
		i8.u32[3] = i8.u32[3] +
			(uint8_t)tbl[3] * 256;
		ptbl = (const uint32_t *)&lpm->tbl8[i8.u32[3]];
		tbl[3] = *ptbl;
	}
	hop[0] = (tbl[0] & 0x01000000) ? tbl[0] & 0x00FFFFFF : defv;
	hop[1] = (tbl[1] & 0x01000000) ? tbl[1] & 0x00FFFFFF : defv;
	hop[2] = (tbl[2] & 0x01000000) ? tbl[2] & 0x00FFFFFF : defv;
	hop[3] = (tbl[3] & 0x01000000) ? tbl[3] & 0x00FFFFFF : defv;
}


/*-
	*/


/**
	* @file
	* RTE Longest Prefix Match for IPv6 (LPM6)
	*/






struct rte_lpm6;



struct rte_lpm6_config
{
	uint32_t max_rules; 


	uint32_t number_tbl8s; 


	int flags; 


};


/**
	* Create an LPM object.
	* @param name
	* @param socket_id
	* @param config
	* @return
	*/
struct rte_lpm6 *
rte_lpm6_create(const char *name, int socket_id,
		const struct rte_lpm6_config *config);


/**
	* Find an existing LPM object and return a pointer to it.
	* @param name
	* @return
	*/
struct rte_lpm6 *
rte_lpm6_find_existing(const char *name);


/**
	* Free an LPM object.
	* @param lpm
	* @return
	*/
void
rte_lpm6_free(struct rte_lpm6 *lpm);


/**
	* Add a rule to the LPM table.
	* @param lpm
	* @param ip
	* @param depth
	* @param next_hop
	* @return
	*/
int
rte_lpm6_add(struct rte_lpm6 *lpm, uint8_t *ip, uint8_t depth,
		uint8_t next_hop);


/**
	* Check if a rule is present in the LPM table,
	* and provide its next hop if it is.
	* @param lpm
	* @param ip
	* @param depth
	* @param next_hop
	* @return
	*/
int
rte_lpm6_is_rule_present(struct rte_lpm6 *lpm, uint8_t *ip, uint8_t depth,
uint8_t *next_hop);


/**
	* Delete a rule from the LPM table.
	* @param lpm
	* @param ip
	* @param depth
	* @return
	*/
int
rte_lpm6_delete(struct rte_lpm6 *lpm, uint8_t *ip, uint8_t depth);


/**
	* Delete a rule from the LPM table.
	* @param lpm
	* @param ips
	* @param depths
	* @param n
	* @return
	*/
int
rte_lpm6_delete_bulk_func(struct rte_lpm6 *lpm,
		uint8_t ips[][16], uint8_t *depths, unsigned n);


/**
	* Delete all rules from the LPM table.
	* @param lpm
	*/
void
rte_lpm6_delete_all(struct rte_lpm6 *lpm);


/**
	* Lookup an IP into the LPM table.
	* @param lpm
	* @param ip
	* @param next_hop
	* @return
	*/
int
rte_lpm6_lookup(const struct rte_lpm6 *lpm, uint8_t *ip, uint8_t *next_hop);


/**
	* Lookup multiple IP addresses in an LPM table.
	* @param lpm
	* @param ips
	* @param next_hops
	* @param n
	*  @return
	*/
int
rte_lpm6_lookup_bulk_func(const struct rte_lpm6 *lpm,
		uint8_t ips[][16],
		int16_t * next_hops, unsigned n);


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* RTE Traffic Metering
	* Traffic metering algorithms:
	***/


/*
	* Application Programmer's Interface (API)
	***/



enum rte_meter_color
{
	e_RTE_METER_GREEN = 0, 


	e_RTE_METER_YELLOW, 


	e_RTE_METER_RED, 


	e_RTE_METER_COLORS 


};


/** srTCM parameters per metered traffic flow. The CIR, CBS and EBS parameters only
count bytes of IP packets and do not include link specific headers. At least one of
the CBS or EBS parameters has to be greater than zero. */
struct rte_meter_srtcm_params
{
	uint64_t cir; 


	uint64_t cbs; 


	uint64_t ebs; 


};


/** trTCM parameters per metered traffic flow. The CIR, PIR, CBS and PBS parameters
only count bytes of IP packets and do not include link specific headers. PIR has to
be greater than or equal to CIR. Both CBS or EBS have to be greater than zero. */
struct rte_meter_trtcm_params
{
	uint64_t cir; 


	uint64_t pir; 


	uint64_t cbs; 


	uint64_t pbs; 


};



struct rte_meter_srtcm;



struct rte_meter_trtcm;


/**
	* srTCM configuration per metered traffic flow
	* @param m
	* @param params
	* @return
	*/
int
rte_meter_srtcm_config(struct rte_meter_srtcm *m,
	struct rte_meter_srtcm_params *params);


/**
	* trTCM configuration per metered traffic flow
	* @param m
	* @param params
	* @return
	*/
int
rte_meter_trtcm_config(struct rte_meter_trtcm *m,
	struct rte_meter_trtcm_params *params);


/**
	* srTCM color blind traffic metering
	* @param m
	* @param time
	* @param pkt_len
	* @return
	*/
static inline enum rte_meter_color
rte_meter_srtcm_color_blind_check(struct rte_meter_srtcm *m,
	uint64_t time,
	uint32_t pkt_len);


/**
	* srTCM color aware traffic metering
	* @param m
	* @param time
	* @param pkt_len
	* @param pkt_color
	* @return
	*/
static inline enum rte_meter_color
rte_meter_srtcm_color_aware_check(struct rte_meter_srtcm *m,
	uint64_t time,
	uint32_t pkt_len,
	enum rte_meter_color pkt_color);


/**
	* trTCM color blind traffic metering
	* @param m
	* @param time
	* @param pkt_len
	* @return
	*/
static inline enum rte_meter_color
rte_meter_trtcm_color_blind_check(struct rte_meter_trtcm *m,
	uint64_t time,
	uint32_t pkt_len);


/**
	* trTCM color aware traffic metering
	* @param m
	* @param time
	* @param pkt_len
	* @param pkt_color
	* @return
	*/
static inline enum rte_meter_color
rte_meter_trtcm_color_aware_check(struct rte_meter_trtcm *m,
	uint64_t time,
	uint32_t pkt_len,
	enum rte_meter_color pkt_color);


/*
	* Inline implementation of run-time methods
	***/



struct rte_meter_srtcm
{
	uint64_t time; 


	uint64_t tc; 


	uint64_t te; 


	uint64_t cbs; 


	uint64_t ebs; 


	uint64_t cir_period; 


	uint64_t cir_bytes_per_period; 


};



struct rte_meter_trtcm
{
	uint64_t time_tc; 


	uint64_t time_tp; 


	uint64_t tc; 


	uint64_t tp; 


	uint64_t cbs; 


	uint64_t pbs; 


	uint64_t cir_period; 


	uint64_t cir_bytes_per_period; 


	uint64_t pir_period; 


	uint64_t pir_bytes_per_period; 


};
static inline enum rte_meter_color
rte_meter_srtcm_color_blind_check(struct rte_meter_srtcm *m,
	uint64_t time,
	uint32_t pkt_len)
{
	uint64_t time_diff, n_periods, tc, te;


	time_diff = time - m->time;
	n_periods = time_diff / m->cir_period;
	m->time += n_periods * m->cir_period;


	tc = m->tc + n_periods * m->cir_bytes_per_period;
	te = m->te;
	if (tc > m->cbs)
{
		te += (tc - m->cbs);
		if (te > m->ebs)
			te = m->ebs;
		tc = m->cbs;
	}


	if (tc >= pkt_len)
{
		m->tc = tc - pkt_len;
		m->te = te;
		return e_RTE_METER_GREEN;
	}
	if (te >= pkt_len)
{
		m->tc = tc;
		m->te = te - pkt_len;
		return e_RTE_METER_YELLOW;
	}
	m->tc = tc;
	m->te = te;
	return e_RTE_METER_RED;
}
static inline enum rte_meter_color
rte_meter_srtcm_color_aware_check(struct rte_meter_srtcm *m,
	uint64_t time,
	uint32_t pkt_len,
	enum rte_meter_color pkt_color)
{
	uint64_t time_diff, n_periods, tc, te;


	time_diff = time - m->time;
	n_periods = time_diff / m->cir_period;
	m->time += n_periods * m->cir_period;


	tc = m->tc + n_periods * m->cir_bytes_per_period;
	te = m->te;
	if (tc > m->cbs)
{
		te += (tc - m->cbs);
		if (te > m->ebs)
			te = m->ebs;
		tc = m->cbs;
	}


	if ((pkt_color == e_RTE_METER_GREEN) && (tc >= pkt_len))
{
		m->tc = tc - pkt_len;
		m->te = te;
		return e_RTE_METER_GREEN;
	}
	if ((pkt_color != e_RTE_METER_RED) && (te >= pkt_len))
{
		m->tc = tc;
		m->te = te - pkt_len;
		return e_RTE_METER_YELLOW;
	}
	m->tc = tc;
	m->te = te;
	return e_RTE_METER_RED;
}
static inline enum rte_meter_color
rte_meter_trtcm_color_blind_check(struct rte_meter_trtcm *m,
	uint64_t time,
	uint32_t pkt_len)
{
	uint64_t time_diff_tc, time_diff_tp, n_periods_tc, n_periods_tp, tc, tp;


	time_diff_tc = time - m->time_tc;
	time_diff_tp = time - m->time_tp;
	n_periods_tc = time_diff_tc / m->cir_period;
	n_periods_tp = time_diff_tp / m->pir_period;
	m->time_tc += n_periods_tc * m->cir_period;
	m->time_tp += n_periods_tp * m->pir_period;
	tc = m->tc + n_periods_tc * m->cir_bytes_per_period;
	if (tc > m->cbs)
		tc = m->cbs;
	tp = m->tp + n_periods_tp * m->pir_bytes_per_period;
	if (tp > m->pbs)
		tp = m->pbs;


	if (tp < pkt_len)
{
		m->tc = tc;
		m->tp = tp;
		return e_RTE_METER_RED;
	}
	if (tc < pkt_len)
{
		m->tc = tc;
		m->tp = tp - pkt_len;
		return e_RTE_METER_YELLOW;
	}
	m->tc = tc - pkt_len;
	m->tp = tp - pkt_len;
	return e_RTE_METER_GREEN;
}
static inline enum rte_meter_color
rte_meter_trtcm_color_aware_check(struct rte_meter_trtcm *m,
	uint64_t time,
	uint32_t pkt_len,
	enum rte_meter_color pkt_color)
{
	uint64_t time_diff_tc, time_diff_tp, n_periods_tc, n_periods_tp, tc, tp;


	time_diff_tc = time - m->time_tc;
	time_diff_tp = time - m->time_tp;
	n_periods_tc = time_diff_tc / m->cir_period;
	n_periods_tp = time_diff_tp / m->pir_period;
	m->time_tc += n_periods_tc * m->cir_period;
	m->time_tp += n_periods_tp * m->pir_period;
	tc = m->tc + n_periods_tc * m->cir_bytes_per_period;
	if (tc > m->cbs)
		tc = m->cbs;
	tp = m->tp + n_periods_tp * m->pir_bytes_per_period;
	if (tp > m->pbs)
		tp = m->pbs;


	if ((pkt_color == e_RTE_METER_RED) || (tp < pkt_len))
{
		m->tc = tc;
		m->tp = tp;
		return e_RTE_METER_RED;
	}
	if ((pkt_color == e_RTE_METER_YELLOW) || (tc < pkt_len))
{
		m->tc = tc;
		m->tp = tp - pkt_len;
		return e_RTE_METER_YELLOW;
	}
	m->tc = tc - pkt_len;
	m->tp = tp - pkt_len;
	return e_RTE_METER_GREEN;
}
//#include <rte_pci.h>  Out of memory, Illegal Instruction


/*-
	* This file is provided under a dual BSD/GPLv2 license.  When using or
	*/



enum rte_intr_mode
{
	RTE_INTR_MODE_NONE = 0,
	RTE_INTR_MODE_LEGACY,
	RTE_INTR_MODE_MSI,
	RTE_INTR_MODE_MSIX
};


/*-
	* This file is provided under a dual BSD/GPLv2 license.  When using or
	*/


/*-
	* This file is provided under a dual BSD/GPLv2 license.  When using or
	*/


/*-
	*/


/**
	* @file
	* RTE pdump
	* packet dump library to provide packet capturing support on dpdk.
	*/


/*-
	*/


/*-
	*/


/*
	* Derived from FreeBSD's bufring.h
	**************************************************************************
	* Copyright (c) 2007-2009 Kip Macy kmacy@freebsd.org
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* 1. Redistributions of source code must retain the above copyright notice,
	* 2. The name of Kip Macy nor the names of other
	* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
	* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	* POSSIBILITY OF SUCH DAMAGE.
	***************************************************************************/
enum
{
	RTE_PDUMP_FLAG_RX = 1, 


	RTE_PDUMP_FLAG_TX = 2, 




	RTE_PDUMP_FLAG_RXTX = (RTE_PDUMP_FLAG_RX|RTE_PDUMP_FLAG_TX)
};
enum rte_pdump_socktype
{
	RTE_PDUMP_SOCKET_SERVER = 1,
	RTE_PDUMP_SOCKET_CLIENT = 2
};


/**
	* Initialize packet capturing handling
	* Creates pthread and server socket for handling clients
	* requests to enable/disable rxtx callbacks.
	* @param path
	* directory path for server socket.
	* @return
	*/
int
rte_pdump_init(const char *path);


/**
	* Un initialize packet capturing handling
	* Cancels pthread, close server socket, removes server socket address.
	* @return
	*/
int
rte_pdump_uninit(void);


/**
	* Enables packet capturing on given port and queue.
	* @param port
	*  port on which packet capturing should be enabled.
	* @param queue
	*  queue of a given port on which packet capturing should be enabled.
	*  users should pass on value UINT16_MAX to enable packet capturing on all
	*  queues of a given port.
	* @param flags
	*  flags specifies RTE_PDUMP_FLAG_RX/RTE_PDUMP_FLAG_TX/RTE_PDUMP_FLAG_RXTX
	*  on which packet capturing should be enabled for a given port and queue.
	* @param ring
	*  ring on which captured packets will be enqueued for user.
	* @param mp
	*  mempool on to which original packets will be mirrored or duplicated.
	* @param filter
	*  place holder for packet filtering.
	* @return
	*/
int
rte_pdump_enable(uint8_t port, uint16_t queue, uint32_t flags,
		struct rte_ring *ring,
		struct rte_mempool *mp,
		void *filter);


/**
	* Disables packet capturing on given port and queue.
	* @param port
	*  port on which packet capturing should be disabled.
	* @param queue
	*  queue of a given port on which packet capturing should be disabled.
	*  users should pass on value UINT16_MAX to disable packet capturing on all
	*  queues of a given port.
	* @param flags
	*  flags specifies RTE_PDUMP_FLAG_RX/RTE_PDUMP_FLAG_TX/RTE_PDUMP_FLAG_RXTX
	*  on which packet capturing should be enabled for a given port and queue.
	* @return
	*/
int
rte_pdump_disable(uint8_t port, uint16_t queue, uint32_t flags);


/**
	* Enables packet capturing on given device id and queue.
	* device_id can be name or pci address of device.
	* @param device_id
	*  device id on which packet capturing should be enabled.
	* @param queue
	*  queue of a given device id on which packet capturing should be enabled.
	*  users should pass on value UINT16_MAX to enable packet capturing on all
	*  queues of a given device id.
	* @param flags
	*  flags specifies RTE_PDUMP_FLAG_RX/RTE_PDUMP_FLAG_TX/RTE_PDUMP_FLAG_RXTX
	*  on which packet capturing should be enabled for a given port and queue.
	* @param ring
	*  ring on which captured packets will be enqueued for user.
	* @param mp
	*  mempool on to which original packets will be mirrored or duplicated.
	* @param filter
	*  place holder for packet filtering.
	* @return
	*/
int
rte_pdump_enable_by_deviceid(char *device_id, uint16_t queue,
				uint32_t flags,
				struct rte_ring *ring,
				struct rte_mempool *mp,
				void *filter);


/**
	* Disables packet capturing on given device_id and queue.
	* device_id can be name or pci address of device.
	* @param device_id
	*  pci address or name of the device on which packet capturing
	*  should be disabled.
	* @param queue
	*  queue of a given device on which packet capturing should be disabled.
	*  users should pass on value UINT16_MAX to disable packet capturing on all
	*  queues of a given device id.
	* @param flags
	*  flags specifies RTE_PDUMP_FLAG_RX/RTE_PDUMP_FLAG_TX/RTE_PDUMP_FLAG_RXTX
	*  on which packet capturing should be enabled for a given port and queue.
	* @return
	*/
int
rte_pdump_disable_by_deviceid(char *device_id, uint16_t queue,
				uint32_t flags);


/**
	* Allows applications to set server and client socket paths.
	* If specified path is null default path will be selected, i.e.
	*"/var/run/" for root user and "$HOME" for non root user.
	* Clients also need to call this API to set their server path if the
	* server path is different from default path.
	* This API is not thread-safe.
	* @param path
	* directory path for server or client socket.
	* @type
	* specifies RTE_PDUMP_SOCKET_SERVER if socket path is for server.
	* (or)
	* specifies RTE_PDUMP_SOCKET_CLIENT if socket path is for client.
	* @return
	* 0 on success, -EINVAL on error
	*/
int
rte_pdump_set_socket_dir(const char *path, enum rte_pdump_socktype type);


/*-
	*/


/*-
	*/


/**
	* @file
	* RTE Pipeline
	* This tool is part of the DPDK Packet Framework tool suite and provides
	* a standard methodology (logically similar to OpenFlow) for rapid development
	* of complex packet processing pipelines out of ports, tables and actions.
	* <B>Basic operation.</B> A pipeline is constructed by connecting its input
	* ports to its output ports through a chain of lookup tables. As result of
	* lookup operation into the current table, one of the table entries (or the
	* default table entry, in case of lookup miss) is identified to provide the
	* actions to be executed on the current packet and the associated action
	* meta-data. The behavior of user actions is defined through the configurable
	* table action handler, while the reserved actions define the next hop for the
	* current packet (either another table, an output port or packet drop) and are
	* handled transparently by the framework.
	* <B>Initialization and run-time flows.</B> Once all the pipeline elements
	* (input ports, tables, output ports) have been created, input ports connected
	* to tables, table action handlers configured, tables populated with the
	* initial set of entries (actions and action meta-data) and input ports
	* enabled, the pipeline runs automatically, pushing packets from input ports
	* to tables and output ports. At each table, the identified user actions are
	* being executed, resulting in action meta-data (stored in the table entry)
	* and packet meta-data (stored with the packet descriptor) being updated. The
	* pipeline tables can have further updates and input ports can be disabled or
	* enabled later on as required.
	* <B>Multi-core scaling.</B> Typically, each CPU core will run its own
	* pipeline instance. Complex application-level pipelines can be implemented by
	* interconnecting multiple CPU core-level pipelines in tree-like topologies,
	* as the same port devices (e.g. SW rings) can serve as output ports for the
	* pipeline running on CPU core A, as well as input ports for the pipeline
	* running on CPU core B. This approach enables the application development
	* using the pipeline (CPU cores connected serially), cluster/run-to-completion
	* (CPU cores connected in parallel) or mixed (pipeline of CPU core clusters)
	* programming models.
	* <B>Thread safety.</B> It is possible to have multiple pipelines running on
	* the same CPU core, but it is not allowed (for thread safety reasons) to have
	* multiple CPU cores running the same pipeline instance.
	***/


/*-
	*/


/**
	* @file
	* RTE Port
	* This tool is part of the DPDK Packet Framework tool suite and provides
	* a standard interface to implement different types of packet ports.
	***/


/*-
	*/


/**@{
	* Macros to allow accessing metadata stored in the mbuf headroom
	* just beyond the end of the mbuf data structure returned by a port
	*/





/*
	* Port IN
	*/


/** Maximum number of packets read from any input port in a single burst.
Cannot be changed. */



struct rte_port_in_stats
{
	uint64_t n_pkts_in;
	uint64_t n_pkts_drop;
};


/**
	* Input port create
	* @param params
	* @param socket_id
	* @return
	*/
typedef void* (*rte_port_in_op_create)(void *params, int socket_id);


/**
	* Input port free
	* @param port
	* @return
	*/
typedef int (*rte_port_in_op_free)(void *port);


/**
	* Input port packet burst RX
	* @param port
	* @param pkts
	* @param n_pkts
	* @return
	*/
typedef int (*rte_port_in_op_rx)(
	void *port,
	struct rte_mbuf **pkts,
	uint32_t n_pkts);


/**
	* Input port stats get
	* @param port
	* @param stats
	* @param clear
	* @return
	*/
typedef int (*rte_port_in_op_stats_read)(
		void *port,
		struct rte_port_in_stats *stats,
		int clear);



struct rte_port_in_ops
{
	rte_port_in_op_create f_create; 


	rte_port_in_op_free f_free; 


	rte_port_in_op_rx f_rx; 


	rte_port_in_op_stats_read f_stats; 


};


/*
	* Port OUT
	*/



struct rte_port_out_stats
{
	uint64_t n_pkts_in;
	uint64_t n_pkts_drop;
};


/**
	* Output port create
	* @param params
	* @param socket_id
	* @return
	*/
typedef void* (*rte_port_out_op_create)(void *params, int socket_id);


/**
	* Output port free
	* @param port
	* @return
	*/
typedef int (*rte_port_out_op_free)(void *port);


/**
	* Output port single packet TX
	* @param port
	* @param pkt
	* @return
	*/
typedef int (*rte_port_out_op_tx)(
	void *port,
	struct rte_mbuf *pkt);


/**
	* Output port packet burst TX
	* @param port
	* @param pkts
	* @param pkts_mask
	* @return
	*/
typedef int (*rte_port_out_op_tx_bulk)(
	void *port,
	struct rte_mbuf **pkt,
	uint64_t pkts_mask);


/**
	* Output port flush
	* @param port
	* @return
	*/
typedef int (*rte_port_out_op_flush)(void *port);


/**
	* Output port stats read
	* @param port
	* @param stats
	* @param clear
	* @return
	*/
typedef int (*rte_port_out_op_stats_read)(
		void *port,
		struct rte_port_out_stats *stats,
		int clear);



struct rte_port_out_ops
{
	rte_port_out_op_create f_create; 


	rte_port_out_op_free f_free; 


	rte_port_out_op_tx f_tx; 


	rte_port_out_op_tx_bulk f_tx_bulk; 


	rte_port_out_op_flush f_flush; 


	rte_port_out_op_stats_read f_stats; 


};


/*-
	*/


/**
	* @file
	* RTE Table
	* This tool is part of the DPDK Packet Framework tool suite and provides
	* a standard interface to implement different types of lookup tables for data
	* plane processing.
	* Virtually any search algorithm that can uniquely associate data to a lookup
	* key can be fitted under this lookup table abstraction. For the flow table
	* use-case, the lookup key is an n-tuple of packet fields that uniquely
	* identifies a traffic flow, while data represents actions and action
	* meta-data associated with the same traffic flow.
	***/


/*-
	*/
struct rte_mbuf;



struct rte_table_stats
{
	uint64_t n_pkts_in;
	uint64_t n_pkts_lookup_miss;
};


/**
	* Lookup table create
	* @param params
	* @param socket_id
	* @param entry_size
	* @return
	*/
typedef void* (*rte_table_op_create)(void *params, int socket_id,
	uint32_t entry_size);


/**
	* Lookup table free
	* @param table
	* @return
	*/
typedef int (*rte_table_op_free)(void *table);


/**
	* Lookup table entry add
	* @param table
	* @param key
	* @param entry
	* @param key_found
	* @param entry_ptr
	* @return
	*/
typedef int (*rte_table_op_entry_add)(
	void *table,
	void *key,
	void *entry,
	int *key_found,
	void **entry_ptr);


/**
	* Lookup table entry delete
	* @param table
	* @param key
	* @param key_found
	* @param entry
	* @return
	*/
typedef int (*rte_table_op_entry_delete)(
	void *table,
	void *key,
	int *key_found,
	void *entry);


/**
	* Lookup table entry add bulk
	* @param table
	* @param key
	* @param entries
	* @param n_keys
	* @param key_found
	* @param entries_ptr
	* @return
	*/
typedef int (*rte_table_op_entry_add_bulk)(
	void *table,
	void **keys,
	void **entries,
	uint32_t n_keys,
	int *key_found,
	void **entries_ptr);


/**
	* Lookup table entry delete bulk
	* @param table
	* @param key
	* @param n_keys
	* @param key_found
	* @param entries
	* @return
	*/
typedef int (*rte_table_op_entry_delete_bulk)(
	void *table,
	void **keys,
	uint32_t n_keys,
	int *key_found,
	void **entries);


/**
	* Lookup table lookup
	* @param table
	* @param pkts
	* @param pkts_mask
	* @param lookup_hit_mask
	* @param entries
	* @return
	*/
typedef int (*rte_table_op_lookup)(
	void *table,
	struct rte_mbuf **pkts,
	uint64_t pkts_mask,
	uint64_t *lookup_hit_mask,
	void **entries);


/**
	* Lookup table stats read
	* @param table
	* @param stats
	* @param clear
	* @return
	*/
typedef int (*rte_table_op_stats_read)(
	void *table,
	struct rte_table_stats *stats,
	int clear);



struct rte_table_ops
{
	rte_table_op_create f_create; 


	rte_table_op_free f_free; 


	rte_table_op_entry_add f_add; 


	rte_table_op_entry_delete f_delete; 


	rte_table_op_entry_add_bulk f_add_bulk; 


	rte_table_op_entry_delete_bulk f_delete_bulk; 


	rte_table_op_lookup f_lookup; 


	rte_table_op_stats_read f_stats; 


};


/*-
	*/
struct rte_mbuf;


/*
	* Pipeline
	*/



struct rte_pipeline;



struct rte_pipeline_params
{


	const char *name;

/** CPU socket ID where memory for the pipeline and its elements (ports
	and tables) should be allocated */
	int socket_id;

/** Offset within packet meta-data to port_id to be used by action
	"Send packet to output port read from packet meta-data". Has to be
	4-byte aligned. */
	uint32_t offset_port_id;
};



struct rte_pipeline_port_in_stats
{


	struct rte_port_in_stats stats;


	uint64_t n_pkts_dropped_by_ah;
};



struct rte_pipeline_port_out_stats
{


	struct rte_port_out_stats stats;


	uint64_t n_pkts_dropped_by_ah;
};



struct rte_pipeline_table_stats
{


	struct rte_table_stats stats;


	uint64_t n_pkts_dropped_by_lkp_hit_ah;


	uint64_t n_pkts_dropped_by_lkp_miss_ah;

/** Number of packets dropped by pipeline in behalf of this
	 * table based on action specified in table entry. */
	uint64_t n_pkts_dropped_lkp_hit;

/** Number of packets dropped by pipeline in behalf of this
	 *  table based on action specified in table entry. */
	uint64_t n_pkts_dropped_lkp_miss;
};


/**
	* Pipeline create
	* @param params
	* @return
	*/
struct rte_pipeline *rte_pipeline_create(struct rte_pipeline_params *params);


/**
	* Pipeline free
	* @param p
	* @return
	*/
int rte_pipeline_free(struct rte_pipeline *p);


/**
	* Pipeline consistency check
	* @param p
	* @return
	*/
int rte_pipeline_check(struct rte_pipeline *p);


/**
	* Pipeline run
	* @param p
	* @return
	*/
int rte_pipeline_run(struct rte_pipeline *p);


/**
	* Pipeline flush
	* @param p
	* @return
	*/
int rte_pipeline_flush(struct rte_pipeline *p);


/*
	* Actions
	*/



enum rte_pipeline_action
{


	RTE_PIPELINE_ACTION_DROP = 0,


	RTE_PIPELINE_ACTION_PORT,


	RTE_PIPELINE_ACTION_PORT_META,


	RTE_PIPELINE_ACTION_TABLE,


	RTE_PIPELINE_ACTIONS
};


/*
	* Table
	*/


/** Maximum number of tables allowed for any given pipeline instance. The
	value of this parameter cannot be changed. */


/**
	* Head format for the table entry of any pipeline table. For any given
	* pipeline table, all table entries should have the same size and format. For
	* any given pipeline table, the table entry has to start with a head of this
	* structure, which contains the reserved actions and their associated
	* meta-data, and then optionally continues with user actions and their
	* associated meta-data. As all the currently defined reserved actions are
	* mutually exclusive, only one reserved action can be set per table entry.
	*/
struct rte_pipeline_table_entry
{


	enum rte_pipeline_action action;

	union
{

/** Output port ID (meta-data for "Send packet to output port"
		action) */
		uint32_t port_id;


		uint32_t table_id;
	};


	__extension__ uint8_t action_data[0];
};


/**
	* Pipeline table action handler on lookup hit
	* The action handler can decide to drop packets by resetting the associated
	* packet bit in the pkts_mask parameter. In this case, the action handler is
	* required not to free the packet buffer, which will be freed eventually by
	* the pipeline.
	* @param p
	* @param pkts
	* @param pkts_mask
	* @param entries
	* @param arg
	* @return
	*/
typedef int (*rte_pipeline_table_action_handler_hit)(
	struct rte_pipeline *p,
	struct rte_mbuf **pkts,
	uint64_t pkts_mask,
	struct rte_pipeline_table_entry **entries,
	void *arg);


/**
	* Pipeline table action handler on lookup miss
	* The action handler can decide to drop packets by resetting the associated
	* packet bit in the pkts_mask parameter. In this case, the action handler is
	* required not to free the packet buffer, which will be freed eventually by
	* the pipeline.
	* @param p
	* @param pkts
	* @param pkts_mask
	* @param entry
	* @param arg
	* @return
	*/
typedef int (*rte_pipeline_table_action_handler_miss)(
	struct rte_pipeline *p,
	struct rte_mbuf **pkts,
	uint64_t pkts_mask,
	struct rte_pipeline_table_entry *entry,
	void *arg);


/** Parameters for pipeline table creation. Action handlers have to be either
				both enabled or both disabled (they can be disabled by setting them to
				NULL). */
struct rte_pipeline_table_params
{


	struct rte_table_ops *ops;

/** Opaque param to be passed to the table create operation when
	invoked */
	void *arg_create;

/** Callback function to execute the user actions on input packets in
	case of lookup hit */
	rte_pipeline_table_action_handler_hit f_action_hit;

/** Callback function to execute the user actions on input packets in
	case of lookup miss */
	rte_pipeline_table_action_handler_miss f_action_miss;

/** Opaque parameter to be passed to lookup hit and/or lookup miss
	action handlers when invoked */
	void *arg_ah;

/** Memory size to be reserved per table entry for storing the user
	actions and their meta-data */
	uint32_t action_data_size;
};


/**
	* Pipeline table create
	* @param p
	* @param params
	* @param table_id
	* @return
	*/
int rte_pipeline_table_create(struct rte_pipeline *p,
	struct rte_pipeline_table_params *params,
	uint32_t *table_id);


/**
	* Pipeline table default entry add
	* The contents of the table default entry is updated with the provided actions
	* and meta-data. When the default entry is not configured (by using this
	* function), the built-in default entry has the action "Drop" and meta-data
	* set to all-zeros.
	* @param p
	* @param table_id
	* @param default_entry
	* @param default_entry_ptr
	* @return
	*/
int rte_pipeline_table_default_entry_add(struct rte_pipeline *p,
	uint32_t table_id,
	struct rte_pipeline_table_entry *default_entry,
	struct rte_pipeline_table_entry **default_entry_ptr);


/**
	* Pipeline table default entry delete
	* The new contents of the table default entry is set to reserved action "Drop
	* the packet" with meta-data cleared (i.e. set to all-zeros).
	* @param p
	* @param table_id
	* @param entry
	* @return
	*/
int rte_pipeline_table_default_entry_delete(struct rte_pipeline *p,
	uint32_t table_id,
	struct rte_pipeline_table_entry *entry);


/**
	* Pipeline table entry add
	* @param p
	* @param table_id
	* @param key
	* @param entry
	* @param key_found
	* @param entry_ptr
	* @return
	*/
int rte_pipeline_table_entry_add(struct rte_pipeline *p,
	uint32_t table_id,
	void *key,
	struct rte_pipeline_table_entry *entry,
	int *key_found,
	struct rte_pipeline_table_entry **entry_ptr);


/**
	* Pipeline table entry delete
	* @param p
	* @param table_id
	* @param key
	* @param key_found
	* @param entry
	* @return
	*/
int rte_pipeline_table_entry_delete(struct rte_pipeline *p,
	uint32_t table_id,
	void *key,
	int *key_found,
	struct rte_pipeline_table_entry *entry);


/**
	* Pipeline table entry add bulk
	* @param p
	* @param table_id
	* @param keys
	* @param entries
	* @param n_keys
	* @param key_found
	* @param entries_ptr
	* @return
	*/
int rte_pipeline_table_entry_add_bulk(struct rte_pipeline *p,
	uint32_t table_id,
	void **keys,
	struct rte_pipeline_table_entry **entries,
	uint32_t n_keys,
	int *key_found,
	struct rte_pipeline_table_entry **entries_ptr);


/**
	* Pipeline table entry delete bulk
	* @param p
	* @param table_id
	* @param keys
	* @param n_keys
	* @param key_found
	* @param entries
	* @return
	*/
int rte_pipeline_table_entry_delete_bulk(struct rte_pipeline *p,
	uint32_t table_id,
	void **keys,
	uint32_t n_keys,
	int *key_found,
	struct rte_pipeline_table_entry **entries);


/**
	* Read pipeline table stats.
	* This function reads table statistics identified by *table_id* of given
	* pipeline *p*.
	* @param p
	* @param table_id
	* @param stats
	* @param clear
	* @return
	*/
int rte_pipeline_table_stats_read(struct rte_pipeline *p, uint32_t table_id,
	struct rte_pipeline_table_stats *stats, int clear);


/*
	* Port IN
	*/


/** Maximum number of input ports allowed for any given pipeline instance. The
	value of this parameter cannot be changed. */


/**
	* Pipeline input port action handler
	* The action handler can decide to drop packets by resetting the associated
	* packet bit in the pkts_mask parameter. In this case, the action handler is
	* required not to free the packet buffer, which will be freed eventually by
	* the pipeline.
	* @param p
	* @param pkts
	* @param n
	* @param arg
	* @return
	*/
typedef int (*rte_pipeline_port_in_action_handler)(
	struct rte_pipeline *p,
	struct rte_mbuf **pkts,
	uint32_t n,
	void *arg);



struct rte_pipeline_port_in_params
{


	struct rte_port_in_ops *ops;


	void *arg_create;

/** Callback function to execute the user actions on input packets.
		Disabled if set to NULL. */
	rte_pipeline_port_in_action_handler f_action;


	void *arg_ah;


	uint32_t burst_size;
};


/**
	* Pipeline input port create
	* @param p
	* @param params
	* @param port_id
	* @return
	*/
int rte_pipeline_port_in_create(struct rte_pipeline *p,
	struct rte_pipeline_port_in_params *params,
	uint32_t *port_id);


/**
	* Pipeline input port connect to table
	* @param p
	* @param port_id
	* @param table_id
	* @return
	*/
int rte_pipeline_port_in_connect_to_table(struct rte_pipeline *p,
	uint32_t port_id,
	uint32_t table_id);


/**
	* Pipeline input port enable
	* @param p
	* @param port_id
	* @return
	*/
int rte_pipeline_port_in_enable(struct rte_pipeline *p,
	uint32_t port_id);


/**
	* Pipeline input port disable
	* @param p
	* @param port_id
	* @return
	*/
int rte_pipeline_port_in_disable(struct rte_pipeline *p,
	uint32_t port_id);


/**
	* Read pipeline port in stats.
	* This function reads port in statistics identified by *port_id* of given
	* pipeline *p*.
	* @param p
	* @param port_id
	* @param stats
	* @param clear
	* @return
	*/
int rte_pipeline_port_in_stats_read(struct rte_pipeline *p, uint32_t port_id,
	struct rte_pipeline_port_in_stats *stats, int clear);


/*
	* Port OUT
	*/


/** Maximum number of output ports allowed for any given pipeline instance. The
	value of this parameter cannot be changed. */


/**
	* Pipeline output port action handler
	* The action handler can decide to drop packets by resetting the associated
	* packet bit in the pkts_mask parameter. In this case, the action handler is
	* required not to free the packet buffer, which will be freed eventually by
	* the pipeline.
	* @param p
	* @param pkts
	* @param pkts_mask
	* @param arg
	* @return
	*/
typedef int (*rte_pipeline_port_out_action_handler)(
	struct rte_pipeline *p,
	struct rte_mbuf **pkts,
	uint64_t pkts_mask,
	void *arg);


/** Parameters for pipeline output port creation. The action handlers have to
be either both enabled or both disabled (by setting them to NULL). When
enabled, the pipeline selects between them at different moments, based on the
number of packets that have to be sent to the same output port. */
struct rte_pipeline_port_out_params
{


	struct rte_port_out_ops *ops;


	void *arg_create;

/** Callback function executing the user actions on bust of input
	packets */
	rte_pipeline_port_out_action_handler f_action;


	void *arg_ah;
};


/**
	* Pipeline output port create
	* @param p
	* @param params
	* @param port_id
	* @return
	*/
int rte_pipeline_port_out_create(struct rte_pipeline *p,
	struct rte_pipeline_port_out_params *params,
	uint32_t *port_id);


/**
	* Read pipeline port out stats.
	* This function reads port out statistics identified by *port_id* of given
	* pipeline *p*.
	* @param p
	* @param port_id
	* @param stats
	* @param clear
	* @return
	*/
int rte_pipeline_port_out_stats_read(struct rte_pipeline *p, uint32_t port_id,
	struct rte_pipeline_port_out_stats *stats, int clear);


/*
	* Functions to be called as part of the port IN/OUT or table action handlers
	*/


/**
	* Action handler packet insert to output port
	* This function can be called by any input/output port or table action handler
	* to send a packet out through one of the pipeline output ports. This packet is
	* generated by the action handler, i.e. this packet is not part of the burst of
	* packets read from one of the pipeline input ports and currently processed by
	* the pipeline (this packet is not an element of the pkts array input parameter
	* of the action handler).
	* @param p
	* @param port_id
	* @param pkt
	* @return
	*/
int rte_pipeline_port_out_packet_insert(struct rte_pipeline *p,
	uint32_t port_id,
	struct rte_mbuf *pkt);


/**
	* Action handler packet hijack
	* This function can be called by any input/output port or table action handler
	* to hijack selected packets from the burst of packets read from one of the
	* pipeline input ports and currently processed by the pipeline. The hijacked
	* packets are removed from any further pipeline processing, with the action
	* handler now having the full ownership for these packets.
	* The action handler can further send the hijacked packets out through any
	* pipeline output port by calling the rte_pipeline_ah_port_out_packet_insert()
	* function. The action handler can also drop these packets by calling the
	* rte_pktmbuf_free() function, although a better alternative is provided by
	* the action handler using the rte_pipeline_ah_packet_drop() function.
	* @param p
	* @param pkts_mask
	* @return
	*/
int rte_pipeline_ah_packet_hijack(struct rte_pipeline *p,
	uint64_t pkts_mask);


/**
	* Action handler packet drop
	* This function is called by the pipeline action handlers (port in/out, table)
	* to drop the packets selected using packet mask.
	* This function can be called by any input/output port or table action handler
	* to drop selected packets from the burst of packets read from one of the
	* pipeline input ports and currently processed by the pipeline. The dropped
	* packets are removed from any further pipeline processing and the packet
	* buffers are eventually freed to their buffer pool.
	* This function updates the drop statistics counters correctly, therefore the
	* recommended approach for dropping packets by the action handlers is to call
	* this function as opposed to the action handler hijacking the packets first
	* and then dropping them invisibly to the pipeline (by using the
	* rte_pktmbuf_free() function).
	* @param p
	* @param pkts_mask
	* @return
	*/
int rte_pipeline_ah_packet_drop(struct rte_pipeline *p,
	uint64_t pkts_mask);


/*-
	*/


/*-
	*/


/**
	* @file
	* RTE Port Ethernet Device
	* ethdev_reader: input port built on top of pre-initialized NIC RX queue
	* ethdev_writer: output port built on top of pre-initialized NIC TX queue
	***/


/*-
	*/



struct rte_port_ethdev_reader_params
{


	uint8_t port_id;


	uint16_t queue_id;
};






struct rte_port_ethdev_writer_params
{


	uint8_t port_id;


	uint16_t queue_id;

/** Recommended burst size to NIC TX queue. The actual burst size can be
	bigger or smaller than this value. */
	uint32_t tx_burst_sz;
};






struct rte_port_ethdev_writer_nodrop_params
{


	uint8_t port_id;


	uint16_t queue_id;

/** Recommended burst size to NIC TX queue. The actual burst size can be
	bigger or smaller than this value. */
	uint32_t tx_burst_sz;


	uint32_t n_retries;
};





/*-
	*/


/**
	* @file
	* RTE Port for IPv4 Fragmentation
	* This port is built on top of pre-initialized single consumer rte_ring. In
	* order to minimize the amount of packets stored in the ring at any given
	* time, the IP fragmentation functionality is executed on ring read operation,
	* hence this port is implemented as an input port. A regular ring_writer port
	* can be created to write to the same ring.
	* The packets written to the ring are either complete IP datagrams or jumbo
	* frames (i.e. IP packets with length bigger than provided MTU value). The
	* packets read from the ring are all non-jumbo frames. The complete IP
	* datagrams written to the ring are not changed. The jumbo frames are
	* fragmented into several IP packets with length less or equal to MTU.
	***/


/*-
	*/


/*
	* Derived from FreeBSD's bufring.h
	**************************************************************************
	* Copyright (c) 2007-2009 Kip Macy kmacy@freebsd.org
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* 1. Redistributions of source code must retain the above copyright notice,
	* 2. The name of Kip Macy nor the names of other
	* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
	* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	* POSSIBILITY OF SUCH DAMAGE.
	***************************************************************************/


/*-
	*/



struct rte_port_ring_reader_frag_params
{


	struct rte_ring *ring;


	uint32_t mtu;

/** Size of application dependent meta-data stored per each input packet
	    that has to be copied to each of the fragments originating from the
	    same input IP datagram. */
	uint32_t metadata_size;

/** Pre-initialized buffer pool used for allocating direct buffers for
	    the output fragments. */
	struct rte_mempool *pool_direct;

/** Pre-initialized buffer pool used for allocating indirect buffers for
	    the output fragments. */
	struct rte_mempool *pool_indirect;
};








/*-
	*/


/**
	* @file
	* RTE Port for IPv4 Reassembly
	* This port is built on top of pre-initialized single producer rte_ring. In
	* order to minimize the amount of packets stored in the ring at any given
	* time, the IP reassembly functionality is executed on ring write operation,
	* hence this port is implemented as an output port. A regular ring_reader port
	* can be created to read from the same ring.
	* The packets written to the ring are either complete IP datagrams or IP
	* fragments. The packets read from the ring are all complete IP datagrams,
	* either jumbo frames (i.e. IP packets with length bigger than MTU) or not.
	* The complete IP datagrams written to the ring are not changed. The IP
	* fragments written to the ring are first reassembled and into complete IP
	* datagrams or dropped on error or IP reassembly time-out.
	***/


/*-
	*/


/*
	* Derived from FreeBSD's bufring.h
	**************************************************************************
	* Copyright (c) 2007-2009 Kip Macy kmacy@freebsd.org
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* 1. Redistributions of source code must retain the above copyright notice,
	* 2. The name of Kip Macy nor the names of other
	* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
	* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	* POSSIBILITY OF SUCH DAMAGE.
	***************************************************************************/


/*-
	*/



struct rte_port_ring_writer_ras_params
{


	struct rte_ring *ring;

/** Recommended burst size to ring. The actual burst size can be bigger
	or smaller than this value. */
	uint32_t tx_burst_sz;
};








/*-
	*/


/**
	* @file
	* RTE Port Ring
	* ring_reader:
	* ring_writer:
	* ring_multi_reader:
	* ring_multi_writer:
	***/


/*-
	*/


/*
	* Derived from FreeBSD's bufring.h
	**************************************************************************
	* Copyright (c) 2007-2009 Kip Macy kmacy@freebsd.org
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* 1. Redistributions of source code must retain the above copyright notice,
	* 2. The name of Kip Macy nor the names of other
	* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
	* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	* POSSIBILITY OF SUCH DAMAGE.
	***************************************************************************/


/*-
	*/



struct rte_port_ring_reader_params
{


	struct rte_ring *ring;
};






struct rte_port_ring_writer_params
{


	struct rte_ring *ring;

/** Recommended burst size to ring. The actual burst size can be
		bigger or smaller than this value. */
	uint32_t tx_burst_sz;
};






struct rte_port_ring_writer_nodrop_params
{


	struct rte_ring *ring;

/** Recommended burst size to ring. The actual burst size can be
		bigger or smaller than this value. */
	uint32_t tx_burst_sz;


	uint32_t n_retries;
};























/*-
	*/


/**
	* @file
	* RTE Port Hierarchical Scheduler
	* sched_reader: input port built on top of pre-initialized rte_sched_port
	* sched_writer: output port built on top of pre-initialized rte_sched_port
	***/


/*-
	*/


/**
	* @file
	* RTE Hierarchical Scheduler
	* The hierarchical scheduler prioritizes the transmission of packets
	* from different users and traffic classes according to the Service
	* Level Agreements (SLAs) defined for the current network node.
	* The scheduler supports thousands of packet queues grouped under a
	* 5-level hierarchy:
	*	    equal priority;
	*	    (one bucket per subport);
	*	    bandwidth currently unused by higher priority traffic
	*	    classes of the same subport;
	*	    (configuration time event), the usage of subport member
	*	    pipes with high demand for thattraffic class pipes is
	*	    truncated to a dynamically adjusted value with no
	*	    (one bucket per pipe);
	*	    priority order;
	*	    bandwidth currently unused by higher priority traffic
	*	    classes of the same pipe;
	*	    multiple connections of same traffic class belonging to
	*	    the same user;
	*	    queues within same pipe traffic class.
	*/


/*-
	*/


/*-
	*/





/** Number of traffic classes per pipe (as well as subport).
	* Cannot be changed.
	*/








/** Maximum number of pipe profiles that can be defined per port.
	* Compile-time configurable.
	*/


/*
	* Ethernet framing overhead. Overhead fields per Ethernet frame:
	* 1. Preamble:                             7 bytes;
	* 2. Start of Frame Delimiter (SFD):       1 byte;
	* 3. Frame Check Sequence (FCS):           4 bytes;
	* 4. Inter Frame Gap (IFG):               12 bytes.
	* The FCS is considered overhead only if not included in the packet
	* length (field pkt_len of struct rte_mbuf).
	*/


/*
	* Subport configuration parameters. The period and credits_per_period
	* parameters are measured in bytes, with one byte meaning the time
	* duration associated with the transmission of one byte on the
	* physical medium of the output port, with pipe or pipe traffic class
	* rate (measured as percentage of output port rate) determined as
	* credits_per_period divided by period. One credit represents one
	* byte.
	*/
struct rte_sched_subport_params
{


	uint32_t tb_rate; 


	uint32_t tb_size; 




	uint32_t tc_rate[4];


	uint32_t tc_period;


};



struct rte_sched_subport_stats
{


	uint32_t n_pkts_tc[4];


	uint32_t n_pkts_tc_dropped[4];




	uint32_t n_bytes_tc[4];


	uint32_t n_bytes_tc_dropped[4];


};


/*
	* Pipe configuration parameters. The period and credits_per_period
	* parameters are measured in bytes, with one byte meaning the time
	* duration associated with the transmission of one byte on the
	* physical medium of the output port, with pipe or pipe traffic class
	* rate (measured as percentage of output port rate) determined as
	* credits_per_period divided by period. One credit represents one
	* byte.
	*/
struct rte_sched_pipe_params
{


	uint32_t tb_rate; 


	uint32_t tb_size; 




	uint32_t tc_rate[4];


	uint32_t tc_period;




	uint8_t wrr_weights[(4 * 4)]; 


};



struct rte_sched_queue_stats
{


	uint32_t n_pkts; 


	uint32_t n_pkts_dropped; 




	uint32_t n_bytes; 


	uint32_t n_bytes_dropped; 


};



struct rte_sched_port_params
{
	const char *name; 


	int socket; 


	uint32_t rate; 

/**< Output port rate
					  * (measured in bytes per second) */
	uint32_t mtu; 

/**< Maximum Ethernet frame size
					  * (measured in bytes).
					  * Should not include the framing overhead. */
	uint32_t frame_overhead; 

/**< Framing overhead per packet
					  * (measured in bytes) */
	uint32_t n_subports_per_port; 


	uint32_t n_pipes_per_subport; 


	uint16_t qsize[4];

/**< Packet queue size for each traffic class.
	 * All queues within the same pipe traffic class have the same
	 * size. Queues from different pipes serving the same traffic
	 * class have the same size. */
	struct rte_sched_pipe_params *pipe_profiles;

/**< Pipe profile table.
	 * Every pipe is configured using one of the profiles from this table. */
	uint32_t n_pipe_profiles; 


};


/*
	* Configuration
	***/


/**
	* Hierarchical scheduler port configuration
	* @param params
	* @return
	*/
struct rte_sched_port *
rte_sched_port_config(struct rte_sched_port_params *params);


/**
	* Hierarchical scheduler port free
	* @param port
	*/
void
rte_sched_port_free(struct rte_sched_port *port);


/**
	* Hierarchical scheduler subport configuration
	* @param port
	* @param subport_id
	* @param params
	* @return
	*/
int
rte_sched_subport_config(struct rte_sched_port *port,
	uint32_t subport_id,
	struct rte_sched_subport_params *params);


/**
	* Hierarchical scheduler pipe configuration
	* @param port
	* @param subport_id
	* @param pipe_id
	* @param pipe_profile
	* @return
	*/
int
rte_sched_pipe_config(struct rte_sched_port *port,
	uint32_t subport_id,
	uint32_t pipe_id,
	int32_t pipe_profile);


/**
	* Hierarchical scheduler memory footprint size per port
	* @param params
	* @return
	*/
uint32_t
rte_sched_port_get_memory_footprint(struct rte_sched_port_params *params);


/*
	* Statistics
	***/


/**
	* Hierarchical scheduler subport statistics read
	* @param port
	* @param subport_id
	* @param stats
	* @param tc_ov
	* @return
	*/
int
rte_sched_subport_read_stats(struct rte_sched_port *port,
	uint32_t subport_id,
	struct rte_sched_subport_stats *stats,
	uint32_t *tc_ov);


/**
	* Hierarchical scheduler queue statistics read
	* @param port
	* @param queue_id
	* @param stats
	* @param qlen
	* @return
	*/
int
rte_sched_queue_read_stats(struct rte_sched_port *port,
	uint32_t queue_id,
	struct rte_sched_queue_stats *stats,
	uint16_t *qlen);


/**
	* Scheduler hierarchy path write to packet descriptor. Typically
	* called by the packet classification stage.
	* @param pkt
	* @param subport
	* @param pipe
	* @param traffic_class
	* @param queue
	* @param color
	*/
void
rte_sched_port_pkt_write(struct rte_mbuf *pkt,
				uint32_t subport, uint32_t pipe, uint32_t traffic_class,
				uint32_t queue, enum rte_meter_color color);


/**
	* Scheduler hierarchy path read from packet descriptor (struct
	* rte_mbuf). Typically called as part of the hierarchical scheduler
	* enqueue operation. The subport, pipe, traffic class and queue
	* parameters need to be pre-allocated by the caller.
	* @param pkt
	* @param subport
	* @param pipe
	* @param traffic_class
	* @param queue
	*/
void
rte_sched_port_pkt_read_tree_path(const struct rte_mbuf *pkt,
						uint32_t *subport, uint32_t *pipe,
						uint32_t *traffic_class, uint32_t *queue);
enum rte_meter_color
rte_sched_port_pkt_read_color(const struct rte_mbuf *pkt);


/**
	* Hierarchical scheduler port enqueue. Writes up to n_pkts to port
	* scheduler and returns the number of packets actually written. For
	* each packet, the port scheduler queue to write the packet to is
	* identified by reading the hierarchy path from the packet
	* descriptor; if the queue is full or congested and the packet is not
	* written to the queue, then the packet is automatically dropped
	* without any action required from the caller.
	* @param port
	* @param pkts
	* @param n_pkts
	* @return
	*/
int
rte_sched_port_enqueue(struct rte_sched_port *port, struct rte_mbuf **pkts, uint32_t n_pkts);


/**
	* Hierarchical scheduler port dequeue. Reads up to n_pkts from the
	* port scheduler and stores them in the pkts array and returns the
	* number of packets actually read.  The pkts array needs to be
	* pre-allocated by the caller with at least n_pkts entries.
	* @param port
	* @param pkts
	* @param n_pkts
	* @return
	*/
int
rte_sched_port_dequeue(struct rte_sched_port *port, struct rte_mbuf **pkts, uint32_t n_pkts);


/*-
	*/



struct rte_port_sched_reader_params
{


	struct rte_sched_port *sched;
};






struct rte_port_sched_writer_params
{


	struct rte_sched_port *sched;

/** Recommended burst size. The actual burst size can be bigger or
	smaller than this value. */
	uint32_t tx_burst_sz;
};





/*-
	*/


/**
	* @file
	* RTE Port Source/Sink
	* source: input port that can be used to generate packets
	* sink: output port that drops all packets written to it
	***/


/*-
	*/



struct rte_port_source_params
{


	struct rte_mempool *mempool;


	char *file_name;

/** The number of bytes to be read from each packet in the
	 *  pcap file. If this value is 0, the whole packet is read;
	 *  if it is bigger than packet size, the generated packets
	 *  will contain the whole packet */
	uint32_t n_bytes_per_pkt;
};






struct rte_port_sink_params
{


	char *file_name;

/** The maximum number of packets write to the pcap file.
	 *  If this value is 0, the "infinite" write will be carried
	 *  out.
	 */
	uint32_t max_n_pkts;
};





/*-
	*/


/**
	* @file
	* RTE Power Management
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* String-related functions as replacement for libc equivalents
	*/


/**
	* Takes string "string" parameter and splits it at character "delim"
	* up to maxtokens-1 times - to give "maxtokens" resulting tokens. Like
	* strtok or strsep functions, this modifies its input string, by replacing
	* instances of "delim" with '\\0'. All resultant tokens are returned in the
	* "tokens" array which must have enough entries to hold "maxtokens".
	* @param string
	* @param stringlen
	* @param tokens
	* @param maxtokens
	* @param delim
	* @return
	*/
int
rte_strsplit(char *string, int stringlen,
						       char **tokens, int maxtokens, char delim);



enum power_management_env {PM_ENV_NOT_SET, PM_ENV_ACPI_CPUFREQ, PM_ENV_KVM_VM};


/**
	* Set the default power management implementation. If this is not called prior
	* to rte_power_init(), then auto-detect of the environment will take place.
	* It is not thread safe.
	* @param env
	*  env. The environment in which to initialise Power Management for.
	* @return
	*  - 0 on success.
	*  - Negative on error.
	*/
int rte_power_set_env(enum power_management_env env);


/**
	* Unset the global environment configuration.
	* This can only be called after all threads have completed.
	*/
void rte_power_unset_env(void);


/**
	* Get the default power management implementation.
	* @return
	*  power_management_env The configured environment.
	*/
enum power_management_env rte_power_get_env(void);


/**
	* Initialize power management for a specific lcore. If rte_power_set_env() has
	* not been called then an auto-detect of the environment will start and
	* initialise the corresponding resources.
	* @param lcore_id
	*  lcore id.
	* @return
	*  - 0 on success.
	*  - Negative on error.
	*/
int rte_power_init(unsigned lcore_id);


/**
	* Exit power management on a specific lcore. This will call the environment
	* dependent exit function.
	* @param lcore_id
	*  lcore id.
	* @return
	*  - 0 on success.
	*  - Negative on error.
	*/
int rte_power_exit(unsigned lcore_id);


/**
	* Get the available frequencies of a specific lcore.
	* Function pointer definition. Review each environments
	* specific documentation for usage.
	* @param lcore_id
	*  lcore id.
	* @param freqs
	*  The buffer array to save the frequencies.
	* @param num
	*  The number of frequencies to get.
	* @return
	*  The number of available frequencies.
	*/
typedef uint32_t (*rte_power_freqs_t)(unsigned lcore_id, uint32_t *freqs,
		uint32_t num);


/**
	* Return the current index of available frequencies of a specific lcore.
	* Function pointer definition. Review each environments
	* specific documentation for usage.
	* @param lcore_id
	*  lcore id.
	* @return
	*  The current index of available frequencies.
	*/
typedef uint32_t (*rte_power_get_freq_t)(unsigned lcore_id);


/**
	* Set the new frequency for a specific lcore by indicating the index of
	* available frequencies.
	* Function pointer definition. Review each environments
	* specific documentation for usage.
	* @param lcore_id
	*  lcore id.
	* @param index
	*  The index of available frequencies.
	* @return
	*  - 1 on success with frequency changed.
	*  - 0 on success without frequency changed.
	*  - Negative on error.
	*/
typedef int (*rte_power_set_freq_t)(unsigned lcore_id, uint32_t index);


/**
	* Function pointer definition for generic frequency change functions. Review
	* each environments specific documentation for usage.
	* @param lcore_id
	*  lcore id.
	* @return
	*  - 1 on success with frequency changed.
	*  - 0 on success without frequency changed.
	*  - Negative on error.
	*/
typedef int (*rte_power_freq_change_t)(unsigned lcore_id);


/**
	* Scale up the frequency of a specific lcore according to the available
	* frequencies.
	* Review each environments specific documentation for usage.
	* @param lcore_id
	*  lcore id.
	* @return
	*  - 1 on success with frequency changed.
	*  - 0 on success without frequency changed.
	*  - Negative on error.
	*/


/**
	* Scale down the frequency of a specific lcore according to the available
	* frequencies.
	* Review each environments specific documentation for usage.
	* @param lcore_id
	*  lcore id.
	* @return
	*  - 1 on success with frequency changed.
	*  - 0 on success without frequency changed.
	*  - Negative on error.
	*/


/**
	* Scale up the frequency of a specific lcore to the highest according to the
	* available frequencies.
	* Review each environments specific documentation for usage.
	* @param lcore_id
	*  lcore id.
	* @return
	*  - 1 on success with frequency changed.
	*  - 0 on success without frequency changed.
	*  - Negative on error.
	*/


/**
	* Scale down the frequency of a specific lcore to the lowest according to the
	* available frequencies.
	* Review each environments specific documentation for usage..
	* @param lcore_id
	*  lcore id.
	* @return
	*  - 1 on success with frequency changed.
	*  - 0 on success without frequency changed.
	*  - Negative on error.
	*/


/*-
	*/


/*-
	*/


/*
	* Reciprocal divide
	* Used with permission from original authors
	*  Hannes Frederic Sowa and Daniel Borkmann
	* This algorithm is based on the paper "Division by Invariant
	* Integers Using Multiplication" by Torbjörn Granlund and Peter
	* L. Montgomery.
	* The assembler implementation from Agner Fog, which this code is
	* based on, can be found here:
	* http://www.agner.org/optimize/asmlib.zip
	* This optimization for A/B is helpful if the divisor B is mostly
	* runtime invariant. The reciprocal of B is calculated in the
	* slow-path with reciprocal_value(). The fast-path can then just use
	* a much faster multiplication operation with a variable dividend A
	* to calculate the division A/B.
	*/
struct rte_reciprocal
{
	uint32_t m;
	uint8_t sh1, sh2;
};
static inline uint32_t rte_reciprocal_divide(uint32_t a, struct rte_reciprocal R)
{
	uint32_t t = (uint32_t)(((uint64_t)a * R.m) >> 32);
	return (t + ((a - t) >> R.sh1)) >> R.sh2;
}
struct rte_reciprocal rte_reciprocal_value(uint32_t d);


/*-
	*/


/**
	* @file
	* RTE Random Early Detection (RED)
	***/


/*-
	*/


/*-
	*/


/*-
	*/


/*   BSD LICENSE
	*/


/*-
	*/


/*   BSD LICENSE
	*/


/**
	* @file
	* Simple Time Reference Functions (Cycles and HPET).
	*/


/*-
	*/


/*-
	*/
enum timer_source
{
	EAL_TIMER_TSC = 0,
	EAL_TIMER_HPET
};


/**
	* Get the measured frequency of the RDTSC counter
	* @return
	*/
uint64_t
rte_get_tsc_hz(void);


/**
	* Return the number of TSC cycles since boot
		* @return
	*/
static inline uint64_t
rte_get_tsc_cycles(void);


/**
	* Get the number of cycles since boot from the default timer.
	* @return
	*/
static inline uint64_t
rte_get_timer_cycles(void)
{
	switch(eal_timer_source)
{
	case EAL_TIMER_TSC:
		return rte_get_tsc_cycles();
	case EAL_TIMER_HPET:
	default: __rte_panic(__func__, "Invalid timer source specified\n" "%.0s", "dummy");
	}
}


/**
	* Get the number of cycles in one second for the default timer.
	* @return
	*/
static inline uint64_t
rte_get_timer_hz(void)
{
	switch(eal_timer_source)
{
	case EAL_TIMER_TSC:
		return rte_get_tsc_hz();
	case EAL_TIMER_HPET:
	default: __rte_panic(__func__, "Invalid timer source specified\n" "%.0s", "dummy");
	}
}


/**
	* Wait at least us microseconds.
	* @param us
	*/
void
rte_delay_us(unsigned us);


/**
	* Wait at least ms milliseconds.
	* @param ms
	*/
static inline void
rte_delay_ms(unsigned ms)
{
	rte_delay_us(ms * 1000);
}





/*-
	*/


/**
	* @file
	* Branch Prediction Helpers in RTE
	*/


/*-
	*/
static inline uint64_t
rte_rdtsc(void)
{
	union
{
		uint64_t tsc_64;
		struct
{
			uint32_t lo_32;
			uint32_t hi_32;
		};
	} tsc;
	if (__builtin_expect((rte_cycles_vmware_tsc_map),0))
{


		__asm__ volatile("rdpmc" :
						         "=a" (tsc.lo_32),
						         "=d" (tsc.hi_32) :
						         "c"(0x10000));
		return tsc.tsc_64;
	}
	__asm__ volatile("rdtsc" :
						 "=a" (tsc.lo_32),
						 "=d" (tsc.hi_32));
	return tsc.tsc_64;
}
static inline uint64_t
rte_rdtsc_precise(void)
{
	_mm_mfence();
	return rte_rdtsc();
}
static inline uint64_t
rte_get_tsc_cycles(void) { return rte_rdtsc(); }


/*-
	*/


/**
	* @file
	* Branch Prediction Helpers in RTE
	*/


/**
	* Externs
	*/


/**
	* RED configuration parameters passed by user
	*/
struct rte_red_params
{
	uint16_t min_th; 


	uint16_t max_th; 


	uint16_t maxp_inv; 


	uint16_t wq_log2; 


};


/**
	* RED configuration parameters
	*/
struct rte_red_config
{
	uint32_t min_th; 


	uint32_t max_th; 


	uint32_t pa_const; 


	uint8_t maxp_inv; 


	uint8_t wq_log2; 


};


/**
	* RED run-time data
	*/
struct rte_red
{
	uint32_t avg; 


	uint32_t count; 


	uint64_t q_time; 


};


/**
	* @brief Initialises run-time data
	* @param red [in,out] data pointer to RED runtime data
	* @return Operation status
	* @retval 0 success
	* @retval !0 error
	*/
int
rte_red_rt_data_init(struct rte_red *red);


/**
	* @brief Configures a single RED configuration parameter structure.
	* @param red_cfg [in,out] config pointer to a RED configuration parameter structure
	* @param wq_log2 [in]  log2 of the filter weight, valid range is:
	* @param min_th [in] queue minimum threshold in number of packets
	* @param max_th [in] queue maximum threshold in number of packets
	* @param maxp_inv [in] inverse maximum mark probability
	* @return Operation status
	* @retval 0 success
	* @retval !0 error
	*/
int
rte_red_config_init(struct rte_red_config *red_cfg,
	const uint16_t wq_log2,
	const uint16_t min_th,
	const uint16_t max_th,
	const uint16_t maxp_inv);


/**
	* @brief Generate random number for RED
	* Implemenetation based on:
	* http://software.intel.com/en-us/articles/fast-random-number-generator-on-the-intel-pentiumr-4-processor/
	* 10 bit shift has been found through empirical tests (was 16).
	* @return Random number between 0 and (2^22 - 1)
	*/
static inline uint32_t
rte_fast_rand(void)
{
	rte_red_rand_seed = (214013 * rte_red_rand_seed) + 2531011;
	return rte_red_rand_seed >> 10;
}


/**
	* @brief calculate factor to scale average queue size when queue
	* @param wq_log2 [in] where EWMA filter weight wq = 1/(2 ^ wq_log2)
	* @param m [in] exponent in the computed value (1 - wq) ^ m
	* @return computed value
	* @retval ((1 - wq) ^ m) scaled in fixed-point format
	*/
static inline uint16_t
__rte_red_calc_qempty_factor(uint8_t wq_log2, uint16_t m)
{
	uint32_t n = 0;
	uint32_t f = 0;

/**
	 * Basic math tells us that:
	 *
	 * in our case:
	 *  Wq = 1/ (2^log2n)
	 *
	 * So we are computing this equation:
	 *
	 * First we are computing:
	 *
	 * To avoid dealing with signed numbers log2 values are positive
	 * but they should be negative because (1-Wq) is always < 1.
	 * Contents of log2 table values are also scaled for precision.
	 */
	n = m * rte_red_log2_1_minus_Wq[wq_log2 - 1];

/**
	 * The tricky part is computing 2^n, for this I split n into
	 * integer part and fraction part.
	 *
	 * Now using basic math we compute 2^n:
	 */
	f = (n >> 6) & 0xf;
	n >>= 10;
	if (n < 10)
		return (uint16_t) ((rte_red_pow2_frac_inv[f] + (1 << (n - 1))) >> n);
	return 0;
}


/**
	* @brief Updates queue average in condition when queue is empty
	* Note: packet is never dropped in this particular case.
	* @param red_cfg [in] config pointer to a RED configuration parameter structure
	* @param red [in,out] data pointer to RED runtime data
	* @param time [in] current time stamp
	* @return Operation status
	* @retval 0 enqueue the packet
	* @retval 1 drop the packet based on max threshold criterion
	* @retval 2 drop the packet based on mark probability criterion
	*/
static inline int
rte_red_enqueue_empty(const struct rte_red_config *red_cfg,
	struct rte_red *red,
	const uint64_t time)
{
	uint64_t time_diff = 0, m = 0;
	do {} while (0);
	do {} while (0);
	red->count ++;

/**
	 * We compute avg but we don't compare avg against
	 *  min_th or max_th, nor calculate drop probability
	 */
	time_diff = time - red->q_time;

/**
	 * m is the number of packets that might have arrived while the queue was empty.
	 * In this case we have time stamps provided by scheduler in byte units (bytes
	 * transmitted on network port). Such time stamp translates into time units as
	 * port speed is fixed but such approach simplifies the code.
	 */
	m = time_diff / (1 << 22);

/**
	 * Check that m will fit into 16-bit unsigned integer
	 */
	if (m >= (1<<16))
{
		red->avg = 0;
	} else
{
		red->avg = (red->avg >> 10) * __rte_red_calc_qempty_factor(red_cfg->wq_log2, (uint16_t) m);
	}
	return 0;
}


/**
	*  Drop probability (Sally Floyd and Van Jacobson):
	*  We define pa_const as: pa_const =  2 * (max_th - min_th) * maxp_inv. Then:
	*/


/**
	* @brief make a decision to drop or enqueue a packet based on mark probability
	* @param red_cfg [in] config pointer to structure defining RED parameters
	* @param red [in,out] data pointer to RED runtime data
	* @return operation status
	* @retval 0 enqueue the packet
	* @retval 1 drop the packet
	*/
static inline int
__rte_red_drop(const struct rte_red_config *red_cfg, struct rte_red *red)
{
	uint32_t pa_num = 0; 


	uint32_t pa_den = 0; 


	uint32_t pa_num_count = 0;
	pa_num = (red->avg - red_cfg->min_th) >> (red_cfg->wq_log2);
	pa_num_count = red->count * pa_num;
	if (red_cfg->pa_const <= pa_num_count)
		return 1;
	pa_den = red_cfg->pa_const - pa_num_count;


	if (__builtin_expect(((rte_red_rand_val % pa_den) < pa_num),0))
{
		rte_red_rand_val = rte_fast_rand();
		return 1;
	}


	return 0;
}


/**
	* @brief Decides if new packet should be enqeued or dropped in queue non-empty case
	* @param red_cfg [in] config pointer to a RED configuration parameter structure
	* @param red [in,out] data pointer to RED runtime data
	* @param q [in] current queue size (measured in packets)
	* @return Operation status
	* @retval 0 enqueue the packet
	* @retval 1 drop the packet based on max threshold criterion
	* @retval 2 drop the packet based on mark probability criterion
	*/
static inline int
rte_red_enqueue_nonempty(const struct rte_red_config *red_cfg,
	struct rte_red *red,
	const unsigned q)
{
	do {} while (0);
	do {} while (0);

/**
	* EWMA filter (Sally Floyd and Van Jacobson):
	*    avg = (1 - wq) * avg + wq * q
	*    avg = avg + q * wq - avg * wq
	*
	* We select: wq = 2^(-n). Let scaled version of avg be: avg_s = avg * 2^(N+n). We get:
	*    avg_s = avg_s + q * 2^N - avg_s * 2^(-n)
	*
	* By using shift left/right operations, we get:
	*    avg_s = avg_s + (q << N) - (avg_s >> n)
	*    avg_s += (q << N) - (avg_s >> n)
	*/


	red->avg += (q << 10) - (red->avg >> red_cfg->wq_log2);


	if (red->avg < red_cfg->min_th)
{
		red->count ++;
		return 0;
	}


	if (red->avg < red_cfg->max_th)
{
		if (!__rte_red_drop(red_cfg, red))
{
			red->count ++;
			return 0;
		}
		red->count = 0;
		return 2;
	}


	red->count = 0;
	return 1;
}


/**
	* @brief Decides if new packet should be enqeued or dropped
	* Updates run time data based on new queue size value.
	* Based on new queue average and RED configuration parameters
	* gives verdict whether to enqueue or drop the packet.
	* @param red_cfg [in] config pointer to a RED configuration parameter structure
	* @param red [in,out] data pointer to RED runtime data
	* @param q [in] updated queue size in packets
	* @param time [in] current time stamp
	* @return Operation status
	* @retval 0 enqueue the packet
	* @retval 1 drop the packet based on max threshold criteria
	* @retval 2 drop the packet based on mark probability criteria
	*/
static inline int
rte_red_enqueue(const struct rte_red_config *red_cfg,
	struct rte_red *red,
	const unsigned q,
	const uint64_t time)
{
	do {} while (0);
	do {} while (0);
	if (q != 0)
{
		return rte_red_enqueue_nonempty(red_cfg, red, q);
	} else
{
		return rte_red_enqueue_empty(red_cfg, red, time);
	}
}


/**
	* @brief Callback to records time that queue became empty
	* @param red [in,out] data pointer to RED runtime data
	* @param time [in] current time stamp
	*/
static inline void
rte_red_mark_queue_empty(struct rte_red *red, const uint64_t time)
{
	red->q_time = time;
}


/*-
	*/


/**
	* @file
	* RTE reorder
	* Reorder library is a component which is designed to
	* provide ordering of out of ordered packets based on
	* sequence number present in mbuf.
	*/


/*-
	*/
struct rte_reorder_buffer;


/**
	* Create a new reorder buffer instance
	* Allocate memory and initialize a new reorder buffer in that
	* memory, returning the reorder buffer pointer to the user
	* @param name
	* @param socket_id
	* @param size
	* @return
	*/
struct rte_reorder_buffer *
rte_reorder_create(const char *name, unsigned socket_id, unsigned int size);


/**
	* Initializes given reorder buffer instance
	* @param b
	* @param bufsize
	* @param name
	* @param size
	* @return
	*/
struct rte_reorder_buffer *
rte_reorder_init(struct rte_reorder_buffer *b, unsigned int bufsize,
		const char *name, unsigned int size);


/**
	* Find an existing reorder buffer instance
	* and return a pointer to it.
	* @param name
	* @return
	*/
struct rte_reorder_buffer *
rte_reorder_find_existing(const char *name);


/**
	* Reset the given reorder buffer instance with initial values.
	* @param b
	*/
void
rte_reorder_reset(struct rte_reorder_buffer *b);


/**
	* Free reorder buffer instance.
	* @param b
	* @return
	*/
void
rte_reorder_free(struct rte_reorder_buffer *b);


/**
	* Insert given mbuf in reorder buffer in its correct position
	* The given mbuf is to be reordered relative to other mbufs in the system.
	* The mbuf must contain a sequence number which is then used to place
	* the buffer in the correct position in the reorder buffer. Reordered
	* packets can later be taken from the buffer using the rte_reorder_drain()
	* API.
	* @param b
	* @param mbuf
	* @return
	*/
int
rte_reorder_insert(struct rte_reorder_buffer *b, struct rte_mbuf *mbuf);


/**
	* Fetch reordered buffers
	* Returns a set of in-order buffers from the reorder buffer structure. Gaps
	* may be present in the sequence numbers of the mbuf if packets have been
	* delayed too long before reaching the reorder window, or have been previously
	* dropped by the system.
	* @param b
	* @param mbufs
	* @param max_mbufs
	* @return
	*/
unsigned int
rte_reorder_drain(struct rte_reorder_buffer *b, struct rte_mbuf **mbufs,
		unsigned max_mbufs);


/*-
	*/


/*
	* Derived from FreeBSD's bufring.h
	**************************************************************************
	* Copyright (c) 2007-2009 Kip Macy kmacy@freebsd.org
	* All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	* 1. Redistributions of source code must retain the above copyright notice,
	* 2. The name of Kip Macy nor the names of other
	* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
	* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	* POSSIBILITY OF SUCH DAMAGE.
	***************************************************************************/


/*-
	*/


/*-
	*/


/*-
	*/
static inline uint32_t
rte_sched_min_val_2_u32(uint32_t x, uint32_t y)
{
	return (x < y)? x : y;
}



static inline uint32_t
rte_min_pos_4_u16(uint16_t *x)
{
	uint32_t pos0 = 0;
	uint32_t pos1 = 2;
	if (x[1] <= x[0]) pos0 = 1;
	if (x[3] <= x[2]) pos1 = 3;
	if (x[pos1] <= x[pos0]) pos0 = pos1;
	return pos0;
}


/*
	* Compute the Greatest Common Divisor (GCD) of two numbers.
	* This implementation uses Euclid's algorithm:
	*/
static inline uint32_t
rte_get_gcd(uint32_t a, uint32_t b)
{
	uint32_t c;
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a < b)
{
		c = a;
		a = b;
		b = c;
	}
	while (b != 0)
{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}


/*
	* Compute the Lowest Common Denominator (LCD) of two numbers.
	* This implementation computes GCD first:
	*/
static inline uint32_t
rte_get_lcd(uint32_t a, uint32_t b)
{
	return (a * b) / rte_get_gcd(a, b);
}


/*-
	*/


/*
	* Copyright (c) 1982, 1986, 1990, 1993
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. All advertising materials mentioning features or use of this software
	* 4. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	* $FreeBSD: src/sys/netinet/in.h, 1.82 2003/10/25 09:37:10 ume Exp $
	*/


/**
	* @file
	* SCTP-related defines
	*/


/**
	* SCTP Header
	*/
struct sctp_hdr
{
	uint16_t src_port; 


	uint16_t dst_port; 


	uint32_t tag; 


	uint32_t cksum; 


} __attribute__((__packed__));


/*-
	*/


/*-
	*/


/**
	* @file
	* String-related functions as replacement for libc equivalents
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* RTE Table ACL
	* This table uses the Access Control List (ACL) algorithm to uniquely
	* associate data to lookup keys.
	* Use-cases: Firewall rule database, etc.
	***/


/*-
	*/


/**
	* @file
	* RTE Classifier.
	*/


/*-
	*/


/**
	* @file
	* RTE ACL DPDK/OS dependent file.
	*/


/*
	* Copyright (c) 1991, 1993
	*	The Regents of the University of California.  All rights reserved.
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	*	@(#)queue.h	8.5 (Berkeley) 8/20/94
	*/


/*
	* Common defines.
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* Branch Prediction Helpers in RTE
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/*-
	*/


/**
	* @file
	* API for error cause tracking
	*/


/*-
	*/


/**
	* @file
	* String-related functions as replacement for libc equivalents
	*/


/*-
	*/


/*-
	*/


/*-
	*/
union rte_acl_field_types
{
	uint8_t u8;
	uint16_t u16;
	uint32_t u32;
	uint64_t u64;
};
enum
{
	RTE_ACL_FIELD_TYPE_MASK = 0,
	RTE_ACL_FIELD_TYPE_RANGE,
	RTE_ACL_FIELD_TYPE_BITMASK
};


/**
	* ACL Field definition.
	* Each field in the ACL rule has an associate definition.
	* It defines the type of field, its size, its offset in the input buffer,
	* the field index, and the input index.
	* For performance reasons, the inner loop of the search function is unrolled
	* to process four input bytes at a time. This requires the input to be grouped
	* into sets of 4 consecutive bytes. The loop processes the first input byte as
	* part of the setup and then subsequent bytes must be in groups of 4
	* consecutive bytes.
	*/
struct rte_acl_field_def
{
	uint8_t type; 


	uint8_t size; 


	uint8_t field_index; 


	uint8_t input_index; 


	uint32_t offset; 


};


/**
	* ACL build configuration.
	* Defines the fields of an ACL trie and number of categories to build with.
	*/
struct rte_acl_config
{
	uint32_t num_categories; 


	uint32_t num_fields; 


	struct rte_acl_field_def defs[64];


	size_t max_size;


};


/**
	* Defines the value of a field for a rule.
	*/
struct rte_acl_field
{
	union rte_acl_field_types value;


	union rte_acl_field_types mask_range;

/**<
	 * depending on field type:
	 * mask -> 1.2.3.4/32 value=0x1020304, mask_range=32,
	 * range -> 0 : 65535 value=0, mask_range=65535,
	 * bitmask -> 0x06/0xff value=6, mask_range=0xff.
	 */
};
enum
{
	RTE_ACL_TYPE_SHIFT = 29,
	RTE_ACL_MAX_INDEX = ((uint32_t)((uint64_t)-1 >> (sizeof(uint64_t) * CHAR_BIT - (RTE_ACL_TYPE_SHIFT)))),
	RTE_ACL_MAX_PRIORITY = RTE_ACL_MAX_INDEX,
	RTE_ACL_MIN_PRIORITY = 0,
};


/**
	* Miscellaneous data for ACL rule.
	*/
struct rte_acl_rule_data
{
	uint32_t category_mask; 


	int32_t priority; 


	uint32_t userdata; 


};


/**
	* Defines single ACL rule.
	* data - miscellaneous data for the rule.
	* field[] - value and mask or range for each field.
	*/
struct rte_acl_rule { struct rte_acl_rule_data data; struct rte_acl_field field[]; };





/**
	* Parameters used when creating the ACL context.
	*/
struct rte_acl_param
{
	const char *name; 


	int socket_id; 


	uint32_t rule_size; 


	uint32_t max_rule_num; 


};


/**
	* Create a new ACL context.
	* @param param
	* @return
	*/
struct rte_acl_ctx *
rte_acl_create(const struct rte_acl_param *param);


/**
	* Find an existing ACL context object and return a pointer to it.
	* @param name
	* @return
	*/
struct rte_acl_ctx *
rte_acl_find_existing(const char *name);


/**
	* De-allocate all memory used by ACL context.
	* @param ctx
	*/
void
rte_acl_free(struct rte_acl_ctx *ctx);


/**
	* Add rules to an existing ACL context.
	* This function is not multi-thread safe.
	* @param ctx
	* @param rules
	* @param num
	* @return
	*/
int
rte_acl_add_rules(struct rte_acl_ctx *ctx, const struct rte_acl_rule *rules,
	uint32_t num);


/**
	* Delete all rules from the ACL context.
	* This function is not multi-thread safe.
	* Note that internal run-time structures are not affected.
	* @param ctx
	*/
void
rte_acl_reset_rules(struct rte_acl_ctx *ctx);


/**
	* Analyze set of rules and build required internal run-time structures.
	* This function is not multi-thread safe.
	* @param ctx
	* @param cfg
	* @return
	*/
int
rte_acl_build(struct rte_acl_ctx *ctx, const struct rte_acl_config *cfg);


/**
	* Delete all rules from the ACL context and
	* destroy all internal run-time structures.
	* This function is not multi-thread safe.
	* @param ctx
	*/
void
rte_acl_reset(struct rte_acl_ctx *ctx);


/**
	*  Available implementations of ACL classify.
	*/
enum rte_acl_classify_alg
{
	RTE_ACL_CLASSIFY_DEFAULT = 0,
	RTE_ACL_CLASSIFY_SCALAR = 1, 


	RTE_ACL_CLASSIFY_SSE = 2, 


	RTE_ACL_CLASSIFY_AVX2 = 3, 


	RTE_ACL_CLASSIFY_NEON = 4, 


	RTE_ACL_CLASSIFY_ALTIVEC = 5, 


	RTE_ACL_CLASSIFY_NUM 


};


/**
	* Perform search for a matching ACL rule for each input data buffer.
	* Each input data buffer can have up to *categories* matches.
	* That implies that results array should be big enough to hold
	* (categories * num) elements.
	* Also categories parameter should be either one or multiple of
	* RTE_ACL_RESULTS_MULTIPLIER and can't be bigger than RTE_ACL_MAX_CATEGORIES.
	* If more than one rule is applicable for given input buffer and
	* given category, then rule with highest priority will be returned as a match.
	* Note, that it is a caller's responsibility to ensure that input parameters
	* are valid and point to correct memory locations.
	* @param ctx
	* @param data
	* @param results
	* @param num
	* @param categories
	* @return
	*/
extern int
rte_acl_classify(const struct rte_acl_ctx *ctx,
			const uint8_t **data,
			uint32_t *results, uint32_t num,
			uint32_t categories);


/**
	* Perform search using specified algorithm for a matching ACL rule for
	* each input data buffer.
	* Each input data buffer can have up to *categories* matches.
	* That implies that results array should be big enough to hold
	* (categories * num) elements.
	* Also categories parameter should be either one or multiple of
	* RTE_ACL_RESULTS_MULTIPLIER and can't be bigger than RTE_ACL_MAX_CATEGORIES.
	* If more than one rule is applicable for given input buffer and
	* given category, then rule with highest priority will be returned as a match.
	* Note, that it is a caller's responsibility to ensure that input parameters
	* are valid and point to correct memory locations.
	* @param ctx
	* @param data
	* @param results
	* @param num
	* @param categories
	* @param alg
	* @return
	*/
extern int
rte_acl_classify_alg(const struct rte_acl_ctx *ctx,
			const uint8_t **data,
			uint32_t *results, uint32_t num,
			uint32_t categories,
			enum rte_acl_classify_alg alg);


/*
	* Override the default classifier function for a given ACL context.
	* @param ctx
	* @param alg
	* @return
	*/
extern int
rte_acl_set_ctx_classify(struct rte_acl_ctx *ctx,
	enum rte_acl_classify_alg alg);


/**
	* Dump an ACL context structure to the console.
	* @param ctx
	*/
void
rte_acl_dump(const struct rte_acl_ctx *ctx);


/**
	* Dump all ACL context structures to the console.
	*/
void
rte_acl_list_dump(void);


/*-
	*/



struct rte_table_acl_params
{


	const char *name;


	uint32_t n_rules;


	uint32_t n_rule_fields;


	struct rte_acl_field_def field_format[64];
};



struct rte_table_acl_rule_add_params
{


	int32_t priority;


	struct rte_acl_field field_value[64];
};



struct rte_table_acl_rule_delete_params
{


	struct rte_acl_field field_value[64];
};





/*-
	*/


/**
	* @file
	* RTE Table Array
	* Simple array indexing. Lookup key is the array entry index.
	***/


/*-
	*/



struct rte_table_array_params
{


	uint32_t n_entries;

/** Byte offset within input packet meta-data where lookup key (i.e. the
	    array entry index) is located. */
	uint32_t offset;
};



struct rte_table_array_key
{


	uint32_t pos;
};





/*-
	*/


/**
	* @file
	* RTE Table Hash
	* These tables use the exact match criterion to uniquely associate data to
	* lookup keys.
	* Use-cases: Flow classification table, Address Resolution Protocol (ARP) table
	* Hash table types:
	* 1. Entry add strategy on bucket full:
	* 2. Key signature computation:
	* 3. Key size:
	***/


/*-
	*/



typedef uint64_t (*rte_table_hash_op_hash)(
	void *key,
	uint32_t key_size,
	uint64_t seed);


/**
	* Hash tables with configurable key size
	*/



struct rte_table_hash_ext_params
{


	uint32_t key_size;


	uint32_t n_keys;


	uint32_t n_buckets;

/** Number of hash table bucket extensions. Each bucket extension has
	space for 4 keys and each bucket can have 0, 1 or more extensions. */
	uint32_t n_buckets_ext;


	rte_table_hash_op_hash f_hash;


	uint64_t seed;

/** Byte offset within packet meta-data where the 4-byte key signature
	is located. Valid for pre-computed key signature tables, ignored for
	do-sig tables. */
	uint32_t signature_offset;


	uint32_t key_offset;
};





/** Extendible bucket hash table operations for key signature computed on
	lookup ("do-sig") */



struct rte_table_hash_lru_params
{


	uint32_t key_size;


	uint32_t n_keys;


	uint32_t n_buckets;


	rte_table_hash_op_hash f_hash;


	uint64_t seed;

/** Byte offset within packet meta-data where the 4-byte key signature
	is located. Valid for pre-computed key signature tables, ignored for
	do-sig tables. */
	uint32_t signature_offset;


	uint32_t key_offset;
};








/**
	* 8-byte key hash tables
	*/



struct rte_table_hash_key8_lru_params
{


	uint32_t n_entries;


	rte_table_hash_op_hash f_hash;


	uint64_t seed;

/** Byte offset within packet meta-data where the 4-byte key signature
	is located. Valid for pre-computed key signature tables, ignored for
	do-sig tables. */
	uint32_t signature_offset;


	uint32_t key_offset;


	uint8_t *key_mask;
};









struct rte_table_hash_key8_ext_params
{


	uint32_t n_entries;

/** Number of entries (and keys) for hash table bucket extensions. Each
		bucket is extended in increments of 4 keys. */
	uint32_t n_entries_ext;


	rte_table_hash_op_hash f_hash;


	uint64_t seed;

/** Byte offset within packet meta-data where the 4-byte key signature
	is located. Valid for pre-computed key signature tables, ignored for
	do-sig tables. */
	uint32_t signature_offset;


	uint32_t key_offset;


	uint8_t *key_mask;
};





/** Extendible bucket hash table operations for key signature computed on
				lookup ("do-sig") */


/**
	* 16-byte key hash tables
	*/



struct rte_table_hash_key16_lru_params
{


	uint32_t n_entries;


	rte_table_hash_op_hash f_hash;


	uint64_t seed;

/** Byte offset within packet meta-data where the 4-byte key signature
	is located. Valid for pre-computed key signature tables, ignored for
	do-sig tables. */
	uint32_t signature_offset;


	uint32_t key_offset;


	uint8_t *key_mask;
};





/** LRU hash table operations for key signature computed on lookup
				("do-sig") */



struct rte_table_hash_key16_ext_params
{


	uint32_t n_entries;

/** Number of entries (and keys) for hash table bucket extensions. Each
	bucket is extended in increments of 4 keys. */
	uint32_t n_entries_ext;


	rte_table_hash_op_hash f_hash;


	uint64_t seed;

/** Byte offset within packet meta-data where the 4-byte key signature
	is located. Valid for pre-computed key signature tables, ignored for
	do-sig tables. */
	uint32_t signature_offset;


	uint32_t key_offset;


	uint8_t *key_mask;
};





/** Extendible bucket hash table operations for key signature computed on
				lookup ("do-sig") */


/**
	* 32-byte key hash tables
	*/



struct rte_table_hash_key32_lru_params
{


	uint32_t n_entries;


	rte_table_hash_op_hash f_hash;


	uint64_t seed;

/** Byte offset within packet meta-data where the 4-byte key signature
	is located. Valid for pre-computed key signature tables, ignored for
	do-sig tables. */
	uint32_t signature_offset;


	uint32_t key_offset;
};






struct rte_table_hash_key32_ext_params
{


	uint32_t n_entries;

/** Number of entries (and keys) for hash table bucket extensions. Each
		bucket is extended in increments of 4 keys. */
	uint32_t n_entries_ext;


	rte_table_hash_op_hash f_hash;


	uint64_t seed;

/** Byte offset within packet meta-data where the 4-byte key signature
	is located. Valid for pre-computed key signature tables, ignored for
	do-sig tables. */
	uint32_t signature_offset;


	uint32_t key_offset;
};





/*-
	*/


/**
	* @file
	* RTE Table LPM for IPv4
	* This table uses the Longest Prefix Match (LPM) algorithm to uniquely
	* associate data to lookup keys.
	* Use-case: IP routing table. Routes that are added to the table associate a
	* next hop to an IP prefix. The IP prefix is specified as IP address and depth
	* and cover for a multitude of lookup keys (i.e. destination IP addresses)
	* that all share the same data (i.e. next hop). The next hop information
	* typically contains the output interface ID, the IP address of the next hop
	* station (which is part of the same IP network the output interface is
	* connected to) and other flags and counters.
	* The LPM primitive only allows associating an 8-bit number (next hop ID) to
	* an IP prefix, while a routing table can potentially contain thousands of
	* routes or even more. This means that the same next hop ID (and next hop
	* information) has to be shared by multiple routes, which makes sense, as
	* multiple remote networks could be reached through the same next hop.
	* Therefore, when a route is added or updated, the LPM table has to check
	* whether the same next hop is already in use before using a new next hop ID
	* for this route.
	* The comparison between different next hops is done for the first
	* “entry_unique_size” bytes of the next hop information (configurable
	* parameter), which have to uniquely identify the next hop, therefore the user
	* has to carefully manage the format of the LPM table entry (i.e.  the next
	* hop information) so that any next hop data that changes value during
	* run-time (e.g. counters) is placed outside of this area.
	***/


/*-
	*/



struct rte_table_lpm_params
{


	const char *name;


	uint32_t n_rules;


	uint32_t number_tbl8s;


	int flags;

/** Number of bytes at the start of the table entry that uniquely
	identify the entry. Cannot be bigger than table entry size. */
	uint32_t entry_unique_size;

/** Byte offset within input packet meta-data where lookup key (i.e.
	the destination IP address) is located. */
	uint32_t offset;
};


/** LPM table rule (i.e. route), specified as IP prefix. While the key used by
the lookup operation is the destination IP address (read from the input packet
meta-data), the entry add and entry delete operations work with LPM rules, with
each rule covering for a multitude of lookup keys (destination IP addresses)
that share the same data (next hop). */
struct rte_table_lpm_key
{


	uint32_t ip;

/** IP address depth. The most significant "depth" bits of the IP
	address specify the network part of the IP address, while the rest of
	the bits specify the host part of the address and are ignored for the
	purpose of route specification. */
	uint8_t depth;
};





/*-
	*/


/**
	* @file
	* RTE Table LPM for IPv6
	* This table uses the Longest Prefix Match (LPM) algorithm to uniquely
	* associate data to lookup keys.
	* Use-case: IP routing table. Routes that are added to the table associate a
	* next hop to an IP prefix. The IP prefix is specified as IP address and depth
	* and cover for a multitude of lookup keys (i.e. destination IP addresses)
	* that all share the same data (i.e. next hop). The next hop information
	* typically contains the output interface ID, the IP address of the next hop
	* station (which is part of the same IP network the output interface is
	* connected to) and other flags and counters.
	* The LPM primitive only allows associating an 8-bit number (next hop ID) to
	* an IP prefix, while a routing table can potentially contain thousands of
	* routes or even more. This means that the same next hop ID (and next hop
	* information) has to be shared by multiple routes, which makes sense, as
	* multiple remote networks could be reached through the same next hop.
	* Therefore, when a route is added or updated, the LPM table has to check
	* whether the same next hop is already in use before using a new next hop ID
	* for this route.
	* The comparison between different next hops is done for the first
	* “entry_unique_size” bytes of the next hop information (configurable
	* parameter), which have to uniquely identify the next hop, therefore the user
	* has to carefully manage the format of the LPM table entry (i.e.  the next
	* hop information) so that any next hop data that changes value during
	* run-time (e.g. counters) is placed outside of this area.
	***/


/*-
	*/



struct rte_table_lpm_ipv6_params
{


	const char *name;


	uint32_t n_rules;
	uint32_t number_tbl8s;

/** Number of bytes at the start of the table entry that uniquely
	identify the entry. Cannot be bigger than table entry size. */
	uint32_t entry_unique_size;

/** Byte offset within input packet meta-data where lookup key (i.e.
	the destination IP address) is located. */
	uint32_t offset;
};


/** LPM table rule (i.e. route), specified as IP prefix. While the key used by
the lookup operation is the destination IP address (read from the input packet
meta-data), the entry add and entry delete operations work with LPM rules, with
each rule covering for a multitude of lookup keys (destination IP addresses)
that share the same data (next hop). */
struct rte_table_lpm_ipv6_key
{


	uint8_t ip[16];

/** IP address depth. The most significant "depth" bits of the IP
	address specify the network part of the IP address, while the rest of
	the bits specify the host part of the address and are ignored for the
	purpose of route specification. */
	uint8_t depth;
};





/*-
	*/


/**
	* @file
	* RTE Table Stub
	* The stub table lookup operation produces lookup miss for all input packets.
	***/


/*-
	*/








/*-
	*/


/*-
	*/


/*
	* Copyright (c) 1982, 1986, 1990, 1993
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. All advertising materials mentioning features or use of this software
	* 4. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	* $FreeBSD: src/sys/netinet/in.h, 1.82 2003/10/25 09:37:10 ume Exp $
	*/


/**
	* @file
	* TCP-related defines
	*/


/**
	* TCP Header
	*/
struct tcp_hdr
{
	uint16_t src_port; 


	uint16_t dst_port; 


	uint32_t sent_seq; 


	uint32_t recv_ack; 


	uint8_t data_off; 


	uint8_t tcp_flags; 


	uint16_t rx_win; 


	uint16_t cksum; 


	uint16_t tcp_urp; 


} __attribute__((__packed__));


/*-
	*/


/**
	* @file
	* toeplitz hash functions.
	*/


/**
	* Software implementation of the Toeplitz hash function used by RSS.
	* Can be used either for packet distribution on single queue NIC
	* or for simulating of RSS computation on specific NIC (for example
	* after GRE header decapsulating)
	*/


/*-
	*/


/*-
	*/


/*
	* Copyright (c) 1982, 1986, 1990, 1993
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. All advertising materials mentioning features or use of this software
	* 4. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	* $FreeBSD: src/sys/netinet/in.h, 1.82 2003/10/25 09:37:10 ume Exp $
	*/


/*-
	*/


/**
	* length in dwords of input tuple to
	* calculate hash of ipv4 header only
	*/


/**
	* length in dwords of input tuple to
	* calculate hash of ipv4 header +
	* transport header
	*/


/**
	* length in dwords of input tuple to
	* calculate hash of ipv6 header only
	*/


/**
	* length in dwords of input tuple to
	* calculate hash of ipv6 header +
	* transport header
	*/


/**
	* IPv4 tuple
	* addresses and ports/sctp_tag have to be CPU byte order
	*/
struct rte_ipv4_tuple
{
	uint32_t src_addr;
	uint32_t dst_addr;

	union
{
		struct
{
			uint16_t dport;
			uint16_t sport;
		};
		uint32_t sctp_tag;
	};
};


/**
	* IPv6 tuple
	* Addresses have to be filled by rte_thash_load_v6_addr()
	* ports/sctp_tag have to be CPU byte order
	*/
struct rte_ipv6_tuple
{
	uint8_t src_addr[16];
	uint8_t dst_addr[16];

	union
{
		struct
{
			uint16_t dport;
			uint16_t sport;
		};
		uint32_t sctp_tag;
	};
};
union rte_thash_tuple
{
	struct rte_ipv4_tuple v4;
	struct rte_ipv6_tuple v6;
};


/**
	* Prepare special converted key to use with rte_softrss_be()
	* @param orig
	* @param targ
	* @param len
	*/
static inline void
rte_convert_rss_key(const uint32_t *orig, uint32_t *targ, int len)
{
	int i;
	for (i = 0; i < (len >> 2); i++)
		targ[i] = ((uint32_t)(__builtin_constant_p(orig[i]) ? rte_constant_bswap32(orig[i]) : rte_arch_bswap32(orig[i])));
}


/**
	* Prepare and load IPv6 addresses (src and dst)
	* into target tuple
	* @param orig
	* @param targ
	*/
static inline void
rte_thash_load_v6_addrs(const struct ipv6_hdr *orig, union rte_thash_tuple *targ)
{
	int i;
	for (i = 0; i < 4; i++)
{
		*((uint32_t *)targ->v6.src_addr + i) =
			((uint32_t)(__builtin_constant_p(*((const uint32_t *)orig->src_addr + i)) ? rte_constant_bswap32(*((const uint32_t *)orig->src_addr + i)) : rte_arch_bswap32(*((const uint32_t *)orig->src_addr + i))));
		*((uint32_t *)targ->v6.dst_addr + i) =
			((uint32_t)(__builtin_constant_p(*((const uint32_t *)orig->dst_addr + i)) ? rte_constant_bswap32(*((const uint32_t *)orig->dst_addr + i)) : rte_arch_bswap32(*((const uint32_t *)orig->dst_addr + i))));
	}
}


/**
	* Generic implementation. Can be used with original rss_key
	* @param input_tuple
	* @param input_len
	* @param rss_key
	* @return
	*/
static inline uint32_t
rte_softrss(uint32_t *input_tuple, uint32_t input_len,
		const uint8_t *rss_key)
{
	uint32_t i, j, ret = 0;
	for (j = 0; j < input_len; j++)
{
		for (i = 0; i < 32; i++)
{
			if (input_tuple[j] & (1 << (31 - i)))
{
				ret ^= ((uint32_t)(__builtin_constant_p(((const uint32_t *)rss_key)[j]) ? rte_constant_bswap32(((const uint32_t *)rss_key)[j]) : rte_arch_bswap32(((const uint32_t *)rss_key)[j]))) << i |
					(uint32_t)((uint64_t)(((uint32_t)(__builtin_constant_p(((const uint32_t *)rss_key)[j + 1]) ? rte_constant_bswap32(((const uint32_t *)rss_key)[j + 1]) : rte_arch_bswap32(((const uint32_t *)rss_key)[j + 1])))) >>
					(32 - i));
			}
		}
	}
	return ret;
}


/**
	* Optimized implementation.
	* If you want the calculated hash value matches NIC RSS value
	* you have to use special converted key with rte_convert_rss_key() fn.
	* @param input_tuple
	* @param input_len
	* @param *rss_key
	* @return
	*/
static inline uint32_t
rte_softrss_be(uint32_t *input_tuple, uint32_t input_len,
		const uint8_t *rss_key)
{
	uint32_t i, j, ret = 0;
	for (j = 0; j < input_len; j++)
{
		for (i = 0; i < 32; i++)
{
			if (input_tuple[j] & (1 << (31 - i)))
{
				ret ^= ((const uint32_t *)rss_key)[j] << i |
					(uint32_t)((uint64_t)(((const uint32_t *)rss_key)[j + 1]) >> (32 - i));
			}
		}
	}
	return ret;
}


/*-
	*/


/**
	* Structure to hold the parameters of a running cycle counter to assist
	* in converting cycles to nanoseconds.
	*/
struct rte_timecounter
{


	uint64_t cycle_last;


	uint64_t nsec;


	uint64_t nsec_mask;


	uint64_t nsec_frac;


	uint64_t cc_mask;


	uint32_t cc_shift;
};


/**
	* Converts cyclecounter cycles to nanoseconds.
	*/
static inline uint64_t
rte_cyclecounter_cycles_to_ns(struct rte_timecounter *tc, uint64_t cycles)
{
	uint64_t ns;


	ns = cycles + tc->nsec_frac;
	tc->nsec_frac = ns & tc->nsec_mask;


	return ns >> tc->cc_shift;
}


/**
	* Update the internal nanosecond count in the structure.
	*/
static inline uint64_t
rte_timecounter_update(struct rte_timecounter *tc, uint64_t cycle_now)
{
	uint64_t cycle_delta, ns_offset;


	if (tc->cycle_last <= cycle_now)
		cycle_delta = (cycle_now - tc->cycle_last) & tc->cc_mask;
	else


		cycle_delta = (~(tc->cycle_last - cycle_now) & tc->cc_mask) + 1;


	ns_offset = rte_cyclecounter_cycles_to_ns(tc, cycle_delta);


	tc->cycle_last = cycle_now;


	tc->nsec += ns_offset;
	return tc->nsec;
}


/**
	* Convert from timespec structure into nanosecond units.
	*/
static inline uint64_t
rte_timespec_to_ns(const struct timespec *ts)
{
	return ((uint64_t) ts->tv_sec * 1000000000L) + ts->tv_nsec;
}


/**
	* Convert from nanosecond units into timespec structure.
	*/
static inline struct timespec
rte_ns_to_timespec(uint64_t nsec)
{
	struct timespec ts = {0, 0};
	if (nsec == 0)
		return ts;
	ts.tv_sec = nsec / 1000000000L;
	ts.tv_nsec = nsec % 1000000000L;
	return ts;
}


/*-
	*/


/**
	* @file
	RTE Timer
	* This library provides a timer service to RTE Data Plane execution
	* units that allows the execution of callback functions asynchronously.
	* - Timers can be periodic or single (one-shot).
	* - The timers can be loaded from one core and executed on another. This has
	* - High precision is possible. NOTE: this depends on the call frequency to
	* - If not used in an application, for improved performance, it can be
	* The timer library uses the rte_get_hpet_cycles() function that
	* uses the HPET, when available, to provide a reliable time reference. [HPET
	* routines are provided by EAL, which falls back to using the chip TSC (time-
	* stamp counter) as fallback when HPET is not available]
	* This library provides an interface to add, delete and restart a
	* timer. The API is based on the BSD callout(9) API with a few
	* differences.
	* See the RTE architecture documentation for more information about the
	* design of this library.
	*/


/*-
	*/


/**
	* Timer type: Periodic or single (one-shot).
	*/
enum rte_timer_type
{
	SINGLE,
	PERIODICAL
};


/**
	* Timer status: A union of the state (stopped, pending, running,
	* config) and an owner (the id of the lcore that owns the timer).
	*/
union rte_timer_status
{

	struct
{
		uint16_t state; 


		int16_t owner; 


	};
	uint32_t u32; 


};
struct rte_timer;


/**
	* Callback function type for timer expiry.
	*/
typedef void (*rte_timer_cb_t)(struct rte_timer *, void *);


/**
	* A structure describing a timer in RTE.
	*/
struct rte_timer
{
	uint64_t expire; 


	struct rte_timer *sl_next[10];
	volatile union rte_timer_status status; 


	uint64_t period; 


	rte_timer_cb_t f; 


	void *arg; 


};


/**
	* A static initializer for a timer structure.
	*/


/**
	* Initialize the timer library.
	* Initializes internal variables (list, locks and so on) for the RTE
	* timer library.
	*/
void rte_timer_subsystem_init(void);


/**
	* Initialize a timer handle.
	* The rte_timer_init() function initializes the timer handle *tim*
	* for use. No operations can be performed on a timer before it is
	* initialized.
	* @param tim
	*/
void rte_timer_init(struct rte_timer *tim);


/**
	* Reset and start the timer associated with the timer handle.
	* The rte_timer_reset() function resets and starts the timer
	* associated with the timer handle *tim*. When the timer expires after
	* *ticks* HPET cycles, the function specified by *fct* will be called
	* with the argument *arg* on core *tim_lcore*.
	* If the timer associated with the timer handle is already running
	* (in the RUNNING state), the function will fail. The user has to check
	* the return value of the function to see if there is a chance that the
	* timer is in the RUNNING state.
	* If the timer is being configured on another core (the CONFIG state),
	* it will also fail.
	* If the timer is pending or stopped, it will be rescheduled with the
	* new parameters.
	* @param tim
	* @param ticks
	* @param type
	* @param tim_lcore
	* @param fct
	* @param arg
	* @return
	*/
int rte_timer_reset(struct rte_timer *tim, uint64_t ticks,
						enum rte_timer_type type, unsigned tim_lcore,
						rte_timer_cb_t fct, void *arg);


/**
	* Loop until rte_timer_reset() succeeds.
	* Reset and start the timer associated with the timer handle. Always
	* succeed. See rte_timer_reset() for details.
	* @param tim
	* @param ticks
	* @param type
	* @param tim_lcore
	* @param fct
	* @param arg
	*/
void
rte_timer_reset_sync(struct rte_timer *tim, uint64_t ticks,
						 enum rte_timer_type type, unsigned tim_lcore,
						 rte_timer_cb_t fct, void *arg);


/**
	* Stop a timer.
	* The rte_timer_stop() function stops the timer associated with the
	* timer handle *tim*. It may fail if the timer is currently running or
	* being configured.
	* If the timer is pending or stopped (for instance, already expired),
	* the function will succeed. The timer handle tim must have been
	* initialized using rte_timer_init(), otherwise, undefined behavior
	* will occur.
	* This function can be called safely from a timer callback. If it
	* succeeds, the timer is not referenced anymore by the timer library
	* and the timer structure can be freed (even in the callback
	* function).
	* @param tim
	* @return
	*/
int rte_timer_stop(struct rte_timer *tim);


/**
	* Loop until rte_timer_stop() succeeds.
	* After a call to this function, the timer identified by *tim* is
	* stopped. See rte_timer_stop() for details.
	* @param tim
	*/
void rte_timer_stop_sync(struct rte_timer *tim);


/**
	* Test if a timer is pending.
	* The rte_timer_pending() function tests the PENDING status
	* of the timer handle *tim*. A PENDING timer is one that has been
	* scheduled and whose function has not yet been called.
	* @param tim
	* @return
	*/
int rte_timer_pending(struct rte_timer *tim);


/**
	* Manage the timer list and execute callback functions.
	* This function must be called periodically from EAL lcores
	* main_loop(). It browses the list of pending timers and runs all
	* timers that are expired.
	* The precision of the timer depends on the call frequency of this
	* function. However, the more often the function is called, the more
	* CPU resources it will use.
	*/
void rte_timer_manage(void);


/**
	* Dump statistics about timers.
	* @param f
	*/
void rte_timer_dump_stats(FILE *f);


/*-
	*/


/*
	* Copyright (c) 1982, 1986, 1990, 1993
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions
	* are met:
	* 1. Redistributions of source code must retain the above copyright
	* 2. Redistributions in binary form must reproduce the above copyright
	* 3. All advertising materials mentioning features or use of this software
	* 4. Neither the name of the University nor the names of its contributors
	* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
	* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
	* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
	* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
	* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	* SUCH DAMAGE.
	* $FreeBSD: src/sys/netinet/in.h, 1.82 2003/10/25 09:37:10 ume Exp $
	*/


/**
	* @file
	* UDP-related defines
	*/


/**
	* UDP Header
	*/
struct udp_hdr
{
	uint16_t src_port; 


	uint16_t dst_port; 


	uint16_t dgram_len; 


	uint16_t dgram_cksum; 


} __attribute__((__packed__));


/*-
	*/


/**
	* @file
	* Definitions of DPDK version numbers
	*/


/*-
	*/


/**
	* String that appears before the version number
	*/


/**
	* Major version/year number i.e. the yy in yy.mm.z
	*/


/**
	* Minor version/month number i.e. the mm in yy.mm.z
	*/


/**
	* Patch level number i.e. the z in yy.mm.z
	*/


/**
	* Extra string to be appended to version number
	*/


/**
	* Patch release number
	*/


/**
	* Macro to compute a version number usable for comparisons
	*/


/**
	* All version numbers in one to compare with RTE_VERSION_NUM()
	*/


/**
	* Function returning version string
	* @return
	*/
static inline const char *
rte_version(void)
{
	static char version[32];
	if (version[0] != 0)
		return version;
	if (strlen("-rc") == 0)
		snprintf(version, sizeof(version), "%s %d.%02d.%d",
			"DPDK",
			16,
			11,
			0);
	else
		snprintf(version, sizeof(version), "%s %d.%02d.%d%s%d",
			"DPDK",
			16,
			11,
			0,
			"-rc",
			0 < 16 ?
				0 :
				0 - 16);
	return version;
}


/*-
	*/
