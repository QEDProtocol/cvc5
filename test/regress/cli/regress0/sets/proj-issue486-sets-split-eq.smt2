(set-logic ALL)
(set-info :status sat)
(declare-const x Int)
(declare-const _x Int)
(check-sat-assuming ((= x (set.card (set.insert _x 1 (set.singleton (* 2 _x)))))))