# utmpwrap

Wrap shell invocation with utmp add/remove, for de-utmpified
gnome-terminal etc.

---

Modern terminal emulators no longer write to utmp ([see
here](https://bugzilla.gnome.org/show_bug.cgi?id=747046), for example).
Consequently things like `wall`, `who`, `rwho`, `talk`, `rtvtty` etc. no
longer work.  This tiny wrapper can be used to restore that
functionality.

Example usage would be to edit your profile for `gnome-terminal` to run
a custom command based on this template instead of your default login
shell:

```sh
/full/path/to/utmp_wrap /your/shell --login
```

… so a `tcsh` user might set this to `…/utmp_wrap /bin/tcsh -l`.

This code is enabled by, and dependent on, libutempter; unfortunately
[version 1.1.6-3 of this on Debian is
broken](https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=869617).  The
patch attached to that report enables successful use of utmp\_wrap.
