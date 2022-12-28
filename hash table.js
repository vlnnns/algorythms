
class HashTable {
    constructor() {
        this.values = new Array(5);
        for (let i = 0; i < 5;i++){
            this.values[i] = []
        }
    }
    calculateHash(x) {
        return ((x + 2003) % 12)%5;
    }
    add(value) {
        const hash = this.calculateHash(value);
        this.values[hash].push(value);
    }

    collis(){
        let count = 0;
        for(let i = 0; i < 5; i++){
            if(this.values[i].length != 0){
                count += this.values[i].length - 1;
            }
        }
        console.log("Colissions: ", count);
    }
    output(){
        for(let i = 0; i < 5; i++){
            console.log(`${i} = ${JSON.stringify(this.values[i])}`);
        }
        
    }

}

const ht = new HashTable();
let k = 0;
for(let i = 0; i < 30; i++){
    k = Math.floor((Math.random() * 100) + 1);
    ht.add(k);
}
ht.output();
ht.collis();