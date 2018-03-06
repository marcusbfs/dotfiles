function git_prepare() {
     if [ -n "$BUFFER" ];
         then
             BUFFER="git add --all; git commit -m \"$BUFFER\" && git push origin master"
     fi

     if [ -z "$BUFFER" ];
         then
             BUFFER="git add -A; git commit -v && git push"
     fi

     zle accept-line
 }
 zle -N git_prepare
 bindkey "^g" git_prepare
