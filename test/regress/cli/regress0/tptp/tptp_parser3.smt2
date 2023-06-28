(set-logic ALL)
(set-info :status unsat)
(declare-sort $$unsorted 0)
(declare-fun tptp.a () $$unsorted)
(declare-fun tptp.d () $$unsorted)
(declare-fun tptp.p ($$unsorted $$unsorted) Bool)
(declare-fun tptp.b () Bool)
(assert (or (tptp.p tptp.a tptp.d) tptp.b))
(declare-fun tptp.c () Bool)
(assert (or tptp.b tptp.c))
(assert (or (not (tptp.p tptp.a tptp.d)) (not tptp.c)))
(assert (not tptp.b))
(set-info :filename tptp_parser3)
(check-sat)