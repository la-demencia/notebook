syntax on
set number
set relativenumber
set noerrorbells
set belloff=all
set tabstop=4 softtabstop=4
set shiftwidth=4
set autoindent
set smartindent
set cindent
set nowrap
nnoremap <F1> :!./%:r.out < in <CR>
nnoremap <F2> :!./%:r.out < in2 <CR>
nnoremap <F3> :!./%:r.out < in3 <CR>
nnoremap <F4> :!./%:r.out < in4 <CR>
nnoremap <F5> :w <bar> !g++ -o  %:r.out % -std=c++17 -Wall -O2 <Enter>
nnoremap <F6> :%y+<CR>
nnoremap <F7> :w <bar> !ulimit -s unlimited g++ -o  %:r.out % -std=c++17 -Wall -O2 <Enter>
nnoremap <F8> :terminal<CR>
nnoremap <F9> :!./%:r.out<Enter>
