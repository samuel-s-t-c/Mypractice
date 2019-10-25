(defun hello-world (NAME)
  "Say hello to NAME"
  (message "Hello, %s!" NAME))
(setq var "1")
(defvar var 2 "document string")
(message var)

(if t
    (message "true")
  (message "false"))
(integerp 1.)
(setq a -4 b 3)
(setq a ?a)

(setq val nil)
(setq \12 "12")
(message \12)
(setq foo "1")
emacs-build-time
emacs-version
emacs-major-version
emacs-minor-version
emacs-build-number
?\s-
?\C-
?\M-
(current-time)
(message "\s")
(message "")
?\N{U+C1}
?\N{LATIN SMALL LETTER A WITH GRAVE}
?\u00c1
?\xC1
?\U000000C0
?\^i
?\^I
?\C-i
?\C-I
