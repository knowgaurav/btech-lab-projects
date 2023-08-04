function merge(args, i, m, j) {
    var temp = new Array(args.length);
    var p = i;
    var q = m + 1;
    var k = 0;

    while (p <= m && q <= j) {
        if (args[p] < args[q]) {
            temp[k] = args[p];
            p++;
            k++;
        }
        else {
            temp[k] = args[q];
            q++;
            k++;
        }
    }

    while (p <= m) {
        temp[k] = args[p];
        p++;
        k++;
    }

    while (q <= j) {
        temp[k] = args[q];
        q++;
        k++;
    }

    k = 0;
    for (let idx = i; idx < j; idx++) {
        args[idx] = temp[k];
        k++;
    }
}

function mergeSort(args, i, j) {
    if (i < j) {
        var m = Math.floor((i + j) / 2);
        mergeSort(args, i, m);
        mergeSort(args, m + 1, j);
        merge(args, i, m, j);
    }
}