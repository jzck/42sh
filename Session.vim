let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/minishell
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +26 includes/minishell.h
badd +1 src/user-interaction/ft_word_left.c
badd +11 src/user-interaction/ft_cursor_left.c
badd +8 src/user-interaction/ft_interactive_sh.c
badd +5 src/user-interaction/ft_word_right.c
badd +18 src/user-interaction/ft_cursor_right.c
badd +7 src/user-interaction/ft_clear_line.c
badd +1 src/user-interaction/ft_line_start.c
badd +5 src/user-interaction/ft_line_end.c
badd +24 src/main/main.c
badd +12 src/builtin/builtin_exit.c
badd +1 src/user-interaction/ft_cmd.c
badd +8 src/line-editing/ft_cmd.c
badd +2 src/main/ft_cmd.c
badd +13 src/main/sig_handler.c
badd +1 src/main/prompt.c
badd +3 src/main/ft_prompt.c
badd +45 src/line-editing/ft_interactive_sh.c
badd +7 src/line-editing/ft_key_ctrl_d.c
badd +32 src/builtin/builtin_cd.c
badd +4 src/main/lib_expansion.c
badd +19 libft/src/str/ft_strjoin.c
badd +19 libft/src/str/ft_strlen.c
badd +22 libft/src/str/ft_strcat.c
badd +20 src/minishell-exec/ft_cmd.c
badd +10 src/line-editing/ft_key_enter.c
badd +16 src/line-editing/ft_history_add.c
badd +9 src/line-editing/ft_history_up.c
badd +18 src/line-editing/ft_history_down.c
badd +19 src/token/ft_tokenize.c
badd +30 src/line-editing/line-editing.h
badd +1 libft/Makefile
badd +36 Makefile
badd +18 line-editing/Makefile
badd +14 line-editing/includes/line_editing.h
badd +15 src/line-editing/includes/line_editing.h
badd +47 src/line-editing/src/ft_interactive_sh.c
badd +20 src/line-editing/src/ft_key_enter.c
badd +14 src/line-editing/ft_prompt.c
badd +22 src/line-editing/ft_tc_init.c
badd +33 libft/includes/libft.h
badd +5 libft/includes/get_next_line.h
badd +22 src/token/token_init.c
badd +19 src/token/includes/token.h
badd +15 src/token/token_recognition.c
silent! argdel *
edit includes/minishell.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 91 + 91) / 182)
exe 'vert 2resize ' . ((&columns * 90 + 91) / 182)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 52 - ((51 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
52
normal! 042l
wincmd w
argglobal
edit src/line-editing/includes/line_editing.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 46 - ((45 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
46
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 91 + 91) / 182)
exe 'vert 2resize ' . ((&columns * 90 + 91) / 182)
tabedit src/main/main.c
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 91 + 91) / 182)
exe 'vert 2resize ' . ((&columns * 90 + 91) / 182)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 22 - ((19 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
22
normal! 09l
wincmd w
argglobal
edit src/line-editing/ft_interactive_sh.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 56 - ((55 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
56
normal! 012l
wincmd w
exe 'vert 1resize ' . ((&columns * 91 + 91) / 182)
exe 'vert 2resize ' . ((&columns * 90 + 91) / 182)
tabedit src/token/includes/token.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 91 + 91) / 182)
exe 'vert 2resize ' . ((&columns * 90 + 91) / 182)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 18 - ((17 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
18
normal! 0
wincmd w
argglobal
edit src/token/ft_tokenize.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 35 - ((34 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
35
normal! 01l
wincmd w
exe 'vert 1resize ' . ((&columns * 91 + 91) / 182)
exe 'vert 2resize ' . ((&columns * 90 + 91) / 182)
tabedit src/token/token_init.c
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 19 - ((18 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
19
normal! 031l
tabnext 3
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
let g:this_session = v:this_session
let g:this_obsession = v:this_session
let g:this_obsession_status = 2
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
