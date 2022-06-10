""" MAPPINGS
inoremap jk <ESC>
inoremap JK <ESC>
inoremap {<CR> {<CR>}<C-O>O
"inoremap {<CR> {<CR>x<C-O>o}<ESC>kwxA
inoremap <C-A> <ESC>ggVG

nmap <c-s> :w<CR>
imap <c-s> <Esc>:w<CR>a

noremap <C-C> "+y
noremap EE ZZ
noremap EQ ZQ
nnoremap <C-0> :set hlsearch!<CR>
nnoremap <C-J> gT
nnoremap <C-K> gt
nnoremap <C-I> :NERDTreeToggle<CR>
nnoremap <C-A> ggVG
nnoremap t 0i//<ESC>$
nnoremap T 0xx$

autocmd filetype cpp nnoremap <F5> : <bar> !g++ % -DLOCAL -o %:r && ./%:r < ./entrada.txt <CR>
autocmd filetype cpp nnoremap <F9> : <bar> !g++ % -DLOCAL -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -o %:r && ./%:r <CR>
autocmd filetype cpp nnoremap <F10> : <bar> ./%:r <CR>
autocmd filetype py nnoremap <F6> : <bar>

""" SETS

let mapleader = "'"

set number
set relativenumber
set noswapfile
set hlsearch
set ignorecase
set incsearch
set showcmd

set tabstop=8 softtabstop=0 expandtab shiftwidth=4 smarttab autoindent

execute pathogen#infect()
filetype plugin indent on

""" NERDTree

"autocmd VimEnter * NERDTree

""" SYNSTATIC

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_wq = 0

""" VIM COLORS

filetype on
syntax on
syntax enable
colorscheme monokai
