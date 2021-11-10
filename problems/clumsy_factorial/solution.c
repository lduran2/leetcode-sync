

int clumsy(int n){
    int total = 0;  /* accumulates the total */
    int prod = n;   /* accumulates the product from op[0:3] */
    int iop;        /* the operation index */
    /* decreasing from [n, 0[ */
    for (int curr = (n - 1); curr; --curr) {
        /* op = {-, *, /, +}; */
        /* so len(op) = 4 */
        /* and (n - curr) gives #(iterations since start) */
        /* so we find iop s.t. (n - curr) = iop (mod 4) */
        iop = ((n - curr) & 0b11);
        switch (iop) {
            case 0b01:  /* multiply on (iop = 1 (mod 4)) */
                prod *= curr;
                break;
            case 0b10:  /*   divide on (iop = 2 (mod 4)) */
                prod /= curr;
                break;
            case 0b11:  /*      add on (iop = 3 (mod 4)) */
                total += (prod + curr);
                prod = 0;   /* reset the product */
                break;
            case 0b00:  /* subtract on (iop = 4 = 0 (mod 4)) */
                prod -= curr;
                break;
            default:    /* should never reach this case */
                return -1;
        } /* end switch (iop) */
    } /* end for (int curr = (n - 1); curr; --curr) */

    /* add any left over product */
    total += prod;
    /* return the total */
    return total;
} /* end int clumsy(int n) */
