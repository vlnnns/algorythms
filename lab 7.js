function karatsuba(x, y) {
    console.log("Karatsuba started");
    let base;
    base = 10;

    //base case
    if ((x < base) || (y < base)) {
        console.log("x * y = ", x, y, x * y);
        console.log("Karatsuba ended");
        return x * y;
    }

    let tmp_x = x.toString();
    let tmp_y = y.toString();

    let n = (tmp_x.length > tmp_y.length) ? tmp_y.length : tmp_x.length;
    let m = Math.round(n / 2);
    console.log("Number size:", n);

    let A = parseInt(tmp_x.substring(0, tmp_x.length - m));
    let B = parseInt(tmp_x.substring(tmp_x.length - m, tmp_x.length));

    let C = parseInt(tmp_y.substring(0, tmp_y.length - m));
    let D = parseInt(tmp_y.substring(tmp_y.length - m, tmp_y.length));

    console.log("Devided parts:", A, B, C, D);
    let z2 = karatsuba(A, C);
    let z0 = karatsuba(B, D);
    let z1 = karatsuba(B + A, C + D);


    let res = (z2 * Math.pow(10, 2 * m)) + ((z1 - z2 - z0) * Math.pow(10, m)) + z0;
    console.log("Karatsuba ended");
    return res;

}

let a = 12345;
let b = 6789;

console.log((karatsuba(a, b)));
console.log(a*b);
