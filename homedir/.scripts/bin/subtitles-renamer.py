#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from __future__ import print_function, division, absolute_import

import os
import argparse
import re


class MainProgram():
    def __init__(self):
        parser = argparse.ArgumentParser()

        parser.add_argument(
            "path",
            nargs='?',
            default=os.getcwd(),
            help='path to directory.' \
            ' Default value is the current working directory'
        )
        parser.add_argument(
            '-m',
            '--movie',
            help=
            "rename movie subtitile." \
            " Must be only one video/subtitle pair in the current directory",
            action='store_true')
        parser.add_argument(
            '--confirm',
            help='asks for confirmation at each pair',
            action='store_true')
        parser.add_argument(
            '-q',
            '--quiet',
            help="do not show any output",
            action='store_true')

        self.args = parser.parse_args()

    def main(self):

        self.aux_printer()
        t = "  "
        rootdir = self.args.path
        subtitles_ext = ('.srt', '.sub', '.ssa')
        video_ext = ('.mkv', '.avi', '.mp4')

        os.chdir(rootdir)

        if self.args.movie:

            sub = self.get_files_by_ext('.', subtitles_ext)
            mov = self.get_files_by_ext('.', video_ext)

            if (len(sub) != 1 or len(mov) != 1):
                print("Error: there is more than one pair")
                return 0

            file = sub[0]
            NEW_NAME = os.path.splitext(mov[0])[0] + os.path.splitext(file)[-1]

            self.verbose_print('Found ' + self.inquotes(file))
            self.rename_file(file, NEW_NAME, confirm=self.args.confirm)
            return 1

        for file in self.get_files_by_ext('.', subtitles_ext):
            self.verbose_print('Found ' + self.inquotes(file))

            regex = r'[sS]?\d?(\d)[a-zA-Z]?(\d{2})'
            ext = os.path.splitext(file)[-1].lower()
            m = re.search(regex, file)
            SEASON = m.group(1)
            EPISODE = m.group(2)

            for vfile in self.get_files_by_ext('.', video_ext):

                vext = os.path.splitext(vfile)[-1].lower()
                vm = re.search(regex, vfile)
                vSEASON = vm.group(1)
                vEPISODE = vm.group(2)

                if SEASON == vSEASON and EPISODE == vEPISODE:
                    NEW_NAME = os.path.splitext(vfile)[0] + ext
                    self.rename_file(file, NEW_NAME, confirm=self.args.confirm)
                    break

    def aux_printer(self):
        if self.args.quiet:
            self.verbose_print = lambda *a: None
        else:
            self.verbose_print = lambda *args, **kwargs: print(*args, **kwargs)

    def rename_file(self, file, NEW_NAME, confirm=False):
        t = "   "
        if NEW_NAME == file:
            self.verbose_print(t + 'Already ok')
        elif os.path.isfile(NEW_NAME):
            self.verbose_print(t + 'A file named ' + self.inquotes(NEW_NAME) +
                               ' already exists')
        else:
            self.verbose_print(t + self.inquotes(file) + ' -> ' +
                               self.inquotes(NEW_NAME))
            if confirm:
                ans = input(2 * t + 'Proceed? ([y]/n) ')
                if ans.lower() == 'n':
                    return None
            os.rename(file, NEW_NAME)

    def inquotes(self, string):
        return '"' + string + '"'

    def get_files_by_ext(self, path, ext):
        files = [
            f for f in os.listdir(path)
            if os.path.splitext(f)[-1].lower() in map(str.lower, ext)
        ]
        return files


if __name__ == '__main__':
    main = MainProgram()
    main.main()
