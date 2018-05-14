" Leaderkey
let mapleader = "\<Space>"
let maplocalleader = ','

set nocompatible
filetype off

" Instalar vim-plug se necessário
if empty(glob('~/.vim/autoload/plug.vim'))
    silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
         \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
    autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif

"--- Plugins ---"
call plug#begin('~/.vim/plugged')

Plug 'christoomey/vim-tmux-navigator'
Plug 'jiangmiao/auto-pairs'
Plug 'scrooloose/nerdcommenter'
Plug 'junegunn/vim-easy-align'

call plug#end()

filetype plugin indent on

let g:pymode_python = 'python3'
set shell=/usr/bin/zsh

"--- Remaps e funções ---"
" easyalign maps
" Start interactive EasyAlign in visual mode (e.g. vipga)
xmap ga <Plug>(EasyAlign)
" Start interactive EasyAlign for a motion/text object (e.g. gaip)
nmap ga <Plug>(EasyAlign)"
noremap <leader>u :w<Home>silent <End> !urlview<CR>
autocmd Filetype rmd map <F5> :!echo<space>"require(rmarkdown);<space>render('<c-r>%')"<space>\|<space>R<space>--vanilla<enter>
nnoremap ; :
nnoremap Y y$
" Editar .vimrc
nnoremap <leader>ev :e ~/.vimrc<cr>
" Sair do parenteses, modo de inserção
inoremap <C-l> <esc>:normal! %%a<cr>
" Recarregar ~/.vimrc
nmap <leader>sop :w<cr>:source %<cr>
" Vai para o 'placeholder' <++>
nnoremap <c-j> <esc>/<++><cr><esc>cf>
" Renomeia uma variavel
nnoremap <leader>ren *:%s/<c-r>///g<left><left>
" Salvar e sair
nmap <silent> <leader>w :w<CR>
nmap <silent> <leader>q :q<CR>
" Navegar entre splits windows
nnoremap <leader>vne :vne<cr>
nnoremap H <c-w>h
nnoremap J <c-w>j
nnoremap K <c-w>k
nnoremap L <c-w>l
" Controlar buffers
nnoremap <leader>l :ls<cr>:b<space>
" Reselcionar ao usar '<' ou '>'
vnoremap < <gv
vnoremap > >gv
" Convertar para ROT13
nnoremap <leader>rot mmggg?G`m
" Bracketes
"inoremap <c-l> <c-o>%<c-o>%<c-o>a
"inoremap <c-h> <c-o>%<c-o>i
"inoremap {      {}<Left>
"inoremap {<CR>  {<CR>}<Esc>O
"inoremap {{     {
"inoremap {}     {}
"inoremap ( ()<Left>
"inoremap (( (
"inoremap () ()
"inoremap [ []<Left>
"inoremap [[ [
"inoremap [] []


"--- Outras configurações ---"
syntax enable
set omnifunc=syntaxcomplete#Complete

" Esquema de cores
let g:kolor_italic=1                    " Enable italic. Default: 1
let g:kolor_bold=1                      " Enable bold. Default: 1
let g:kolor_underlined=0                " Enable underline. Default: 0
let g:kolor_alternative_matchparen=0    " Gray 'MatchParen' color. Default: 0

let g:vimtex_compiler_latexmk = {'callback' : 0}
let g:vimtex_view_method = 'mupdf'

" Background transparente (xcompmgr)
hi Normal ctermbg=none
highlight NonText ctermbg=none

" Opções - markdown
let g:vim_markdown_folding_disabled=1
 autocmd BufRead,BufNew *.md set filetype=markdown
set conceallevel=2

" Remove espaços vazios no final da linha ao salvar
function! StripWhitespace()
    let save_cursor = getpos(".")
    let old_query = getreg('/')
    :%s/\s\+$//e
    call setpos('.', save_cursor)
    call setreg('/', old_query)
endfunction
autocmd BufWritePre * :call StripWhitespace()

" text with = 79, coluna para delimitar
"set textwidth=79
"set colorcolumn=+1

set encoding=utf8
set fileencoding=utf8
set ffs=unix,dos,mac
set number

" Números relativos
set relativenumber

"Usar espaço quando TAB
set expandtab

" 1 tab == 4 espaços
set shiftwidth=4
set tabstop=4

" Identação
set si
set wrap

set path+=**
set wildmenu

" Não exige que buffer seja salvo para trocar
set hidden

if exists('g:loaded_sensible') || &compatible
  finish
else
  let g:loaded_sensible = 1
endif

if has('autocmd')
  filetype plugin indent on
endif
if has('syntax') && !exists('g:syntax_on')
  syntax enable
endif

set autoindent
set backspace=indent,eol,start
set complete-=i
set smarttab

set nrformats-=octal

set ttimeout
set ttimeoutlen=100

set incsearch

if maparg('<C-L>', 'n') ==# ''
  nnoremap <silent> <C-L> :nohlsearch<C-R>=has('diff')?'<Bar>diffupdate':''<CR><CR><C-L>
endif

set laststatus=2
set ruler
set wildmenu

if !&scrolloff
  set scrolloff=1
endif
if !&sidescrolloff
  set sidescrolloff=5
endif
set display+=lastline

if &encoding ==# 'latin1' && has('gui_running')
  set encoding=utf-8
endif

if &listchars ==# 'eol:$'
  set listchars=tab:>\ ,trail:-,extends:>,precedes:<,nbsp:+
endif

if v:version > 703 || v:version == 703 && has("patch541")
  set formatoptions+=j
endif

if has('path_extra')
  setglobal tags-=./tags tags-=./tags; tags^=./tags;
endif

set autoread

if &history < 1000
  set history=1000
endif
if &tabpagemax < 50
  set tabpagemax=50
endif
if !empty(&viminfo)
  set viminfo^=!
endif
set sessionoptions-=options

if &t_Co == 8 && $TERM !~# '^linux\|^Eterm'
  set t_Co=16
endif

if !exists('g:loaded_matchit') && findfile('plugin/matchit.vim', &rtp) ==# ''
  runtime! macros/matchit.vim
endif

inoremap <C-U> <C-G>u<C-U>

autocmd FileType tex :NoMatchParen
au FileType tex setlocal nocursorline

set noerrorbells visualbell t_vb=
autocmd GUIEnter * set visualbell t_vb=
