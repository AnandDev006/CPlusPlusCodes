function debounce(func, delay) {
    let debounceTimeout = null;
    return function () {
        const context = this;
        const args = arguments;
        clearTimeout(debounceTimeout);
        debounceTimeout = setTimeout(() => func.apply(context, args), delay);
    }
}

const late = debounce( () => {
    console.log(2);
}, 2000);

console.log(1);
late();
console.log(3);