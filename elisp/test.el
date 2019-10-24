(defun hello-world (NAME)
  "Say hello to NAME"
  (message "Hello, %s!" NAME))
(setq var "1")
(defvar var 2 "document string")
(message var)

(if t
    (message "true")
  (message "false"))
