# utmpwrap

Wrap shell invocation with utmp add/remove, for de-utmpified
gnome-terminal etc.

---

Intention is to wrap shell invocation in gnome-terminal or similar, such
that utmp entries are created.

Context is [stuff like
this](https://bugzilla.gnome.org/show_bug.cgi?id=747046), wherein
support for utmp has been removed from modern terminal emulators.

Invocation example:

```sh
utmp_wrap /bin/tcsh -l
```

Currently this doesn't appear to work since I don't understand how to
invoke libutempter correctly.  `utempter_add_record` seems to think it
has succeeded, but on deeper investigation it hasn't: it invokes
`/usr/lib/x86_64-linux-gnu/utempter/utempter`, which fails silently, but
`utempter_add_record` returns happily regardless.

`utempter`'s fail appears to be because `ptsname(STDIN_FILENO)` fails
with errno 25 (ENOTTY, reported as "Inappropriate ioctl for device", but
interpreted by `ptsname`'s manpage as having not been invoked on a
master pty.
