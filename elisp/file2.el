(defun hello-world (name)
  "Say hello to use whose name is NAME."
  (message "Hello, %s" name))

(hello-world "Emacser")

(setq foo "i'm foo")
(message foo)

(defvar foo "Did i have a value?"
  "A demo variable")
foo
(defvar bar "I'm bar"
  "A demo variable named \"bar\"")
bar

(defun circle-area (radix)
  (let ((pi 3.1415926) area))
    (message "直径为%.2f的圆面积是%.2f"radix area)))

(circle-area 3)

