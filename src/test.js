const foo = () => {
    console.log("here");
}

function func(callback){
    callback();
}

function main(){
    func(foo);
}

main();