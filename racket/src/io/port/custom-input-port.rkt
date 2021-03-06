#lang racket/base
(require (rename-in "input-port.rkt"
                    [make-input-port raw:make-input-port])
         "peek-to-read-port.rkt")

(provide make-input-port)

(define (make-input-port name
                         user-read-in
                         user-peek-in
                         user-close
                         [user-get-progress-evt #f]
                         [user-commit #f]
                         [user-get-location #f]
                         [user-count-lines! void]
                         [user-init-position 1]
                         [user-buffer-mode #f])
  
  (define (protect-in dest-bstr dest-start dest-end copy? read-in)
    ;; We don't trust `read-in` to refrain from modifying its
    ;; byte-string argument after it returns, and the `read-in`
    ;; interface doesn't deal with start and end positions, so copy`
    ;; dest-bstr` if needed
    (define len (- dest-end dest-start))
    (define user-bstr
      (if (or copy?
              (not (zero? dest-start))
              (not (= len dest-end)))
          (make-bytes len)
          dest-bstr))
    (define n (read-in user-bstr))
    (when (exact-positive-integer? n)
      (unless (eq? user-bstr dest-bstr)
        (bytes-copy! dest-bstr dest-start user-bstr 0 len)))
    n)
  
  (define (read-in dest-bstr dest-start dest-end copy?)
    (protect-in dest-bstr dest-start dest-end copy? user-read-in))
  
  (define (read-byte)
    (define bstr (make-bytes 1))
    (define n (user-read-in bstr))
    (cond
     [(eof-object? n) n]
     [(= n 1) (bytes-ref bstr 0)]
     [else (read-byte)]))
  
  ;; Used only if `user-peek-in` is a function:
  (define (peek-in dest-bstr dest-start dest-end skip-k copy?)
    (protect-in dest-bstr dest-start dest-end copy?
                (lambda (user-bstr) (user-peek-in user-bstr skip-k #f))))
  
  (cond
   [user-peek-in
    (raw:make-input-port
     #:name name
     #:read-in 
     (if (input-port? user-read-in)
         user-read-in
         read-in)
     #:peek-in
     (if (input-port? user-peek-in)
         user-peek-in
         peek-in)
     #:close user-close)]
   [else
    (open-input-peek-to-read
     #:name name
     #:read-byte read-byte
     #:read-in read-in
     #:close user-close)]))
