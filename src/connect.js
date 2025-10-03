const SIZE = 10000;
const THRESHOLD = 0.5;

class DataSet {
    constructor(size) {
        this.data = Array.from({ length: size }, (_, i) => Math.sin(i) * Math.cos(i));
    }

    analyze() {
        this.data = this.data.map(value => {
            return value > THRESHOLD ? Math.sqrt(value) : Math.log(Math.abs(value) + 1);
        });
    }

    printAnalysis() {
        this.data.forEach((value, index) => {
            console.log(`Data[${index}]: ${value.toFixed(4)}`);
        });
    }
}

const main = () => {
    const ds = new DataSet(SIZE);
    ds.analyze();
    ds.printAnalysis();
};

main();
