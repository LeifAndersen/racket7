(library (thread)
  (export)
  (import (chezpart)
          (rename (only (chezscheme)
                        sleep
                        printf)
                  [sleep chez:sleep])
          (rename (core)
                  [core:break-enabled-key break-enabled-key]
                  ;; These are extracted via `#%linklet`:
                  [make-engine core:make-engine]
                  [engine-block core:engine-block]
                  [engine-return core:engine-return]
                  [root-continuation-prompt-tag core:root-continuation-prompt-tag]))

  (define (sleep secs)
    (define isecs (inexact->exact (floor secs)))
    (chez:sleep (make-time 'time-duration
                           (inexact->exact (floor (* (- secs isecs) 1e9)))
                           isecs)))

  (define (primitive-table key)
    (case key
      [(|#%engine|) (hash
                     'make-engine core:make-engine
                     'engine-block core:engine-block
                     'engine-return core:engine-return
                     'root-continuation-prompt-tag core:root-continuation-prompt-tag
                     'break-enabled-key break-enabled-key
                     'exn:break/non-engine exn:break)]
      [else #f]))

  (include "compiled/thread.scm"))
