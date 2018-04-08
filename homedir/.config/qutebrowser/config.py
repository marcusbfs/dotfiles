# Autogenerated config.py
# Documentation:
#   qute://help/configuring.html
#   qute://help/settings.html

# Uncomment this to still load settings configured via autoconfig.yml
# config.load_autoconfig()

# Aliases for commands. The keys of the given dictionary are the
# aliases, while the values are the commands they map to.
# Type: Dict
c.aliases = {'w': 'session-save',
        'q': 'quit',
        'wq': 'quit --save',
        'ww': 'open https://web.whatsapp.com/',
        'yts': 'open https://www.youtube.com/feed/subscriptions',
        'ghm': 'open https://github.com/mrcsbrn',
        'ip': 'open 192.168.1.1',
        'bib': 'open http://www.biblioteca.ufla.br/pergamum/biblioteca_s/php/login_usu.php?flag=index.php',
        'cv': 'open https://acesso.ufla.br/sso/login?service=https%3A%2F%2Fcampusvirtual.ufla.br%2Fpresencial%2Flogin%2Findex.php%3FauthCAS%3DCAS',
        }

# Always restore open sites when qutebrowser is reopened.
# Type: Bool
c.auto_save.session = True

# Directory to save downloads to. If unset, a sensible OS-specific
# default is used.
# Type: Directory
c.downloads.location.directory = '~/Downloads'

# Prompt the user for the download location. If set to false,
# `downloads.location.directory` will be used.
# Type: Bool
c.downloads.location.prompt = True

# Editor (and arguments) to use for the `open-editor` command. The
# following placeholders are defined: * `{file}`: Filename of the file
# to be edited. * `{line}`: Line in which the caret is found in the
# text. * `{column}`: Column in which the caret is found in the text. *
# `{line0}`: Same as `{line}`, but starting from index 0. * `{column0}`:
# Same as `{column}`, but starting from index 0.
# Type: ShellCommand
c.editor.command = ['st', '-e', 'vim' ,'{file}']

# Search engines which can be used via the address bar. Maps a search
# engine name (such as `DEFAULT`, or `ddg`) to a URL with a `{}`
# placeholder. The placeholder will be replaced by the search term, use
# `{{` and `}}` for literal `{`/`}` signs. The search engine named
# `DEFAULT` is used when `url.auto_search` is turned on and something
# else than a URL was entered to be opened. Other search engines can be
# used by prepending the search engine name to the search term, e.g.
# `:open google qutebrowser`.
# Type: Dict
c.url.searchengines = {'DEFAULT': 'https://www.google.com.br/search?q={}',
        'a': 'https://wiki.archlinux.org/?search={}',
        'yt': 'https://www.youtube.com/results?search_query={}',
        'w': 'https://en.wikipedia.org/wiki/Special:Search/{}',
        'gh': 'https://github.com/search?q={}&type=Code',
        'r': 'https://reddit.com/r/{}',
        'rw': 'https://www.reddit.com/r/{}/top/?sort=top&t=week',
        'rs': 'https://www.google.com.br/search?q={}%20site%3Areddit.com',
        'tpb': 'https://thepiratebay.org/search/{}/0/99/0',
        }

# bindings
_mpv_common = ' --autofit=1280x720 --volume=60 --geometry=50%:15% '
_mpv_720 = 'mpv' + _mpv_common + '--ytdl-format="bestvideo[height<=?720][fps<=?30]+bestaudio/best"'
# _mpv_1080 = 'mpv ' + _mpv_common + '--ytdl-format="bestvideo[height<=?1080][fps<=?30]+bestaudio/best"'
from os.path import expanduser
_mpv_1080 = 'bash ' + expanduser('~') + '/.scripts/bin/dmpv.sh'
config.bind(',v', 'hint links spawn tsp ' + _mpv_720 + ' {hint-url}')
config.bind(',V', 'spawn tsp ' + _mpv_720 + ' {url}')
config.bind(',b', 'hint links spawn tsp ' + _mpv_1080 + ' {hint-url}')
config.bind(',B', 'spawn tsp ' + _mpv_1080 + ' {url}')
config.bind(',f', 'spawn firefox {url}')
config.bind(',F', 'hint links spawn firefox {hint-url}')
config.bind(',t', 'hint links spawn transmission-remote --add {hint-url}')
config.bind(',g', 'open --tab {primary}', mode='normal')
