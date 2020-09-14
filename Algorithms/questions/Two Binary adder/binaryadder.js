const inputEle = document.querySelectorAll(".inputField");
const btn = document.querySelector(".submitBtn");

const adder = ([...numbers]) => {
  const numberA = numbers[0]
    .split("")
    .reverse()
    .map((num) => parseInt(num, 10));
  const numberB = numbers[1]
    .split("")
    .reverse()
    .map((num) => parseInt(num, 10));
  let carry = 0;
  const collectionArray = numberA.map((num, index) => {
    const retNum = (num + numberB[index] + carry) % 2;
    carry = Math.floor((num + numberB[index] + carry) / 2);
    return retNum;
  });
  collectionArray.push(carry);
  console.log(collectionArray.reverse().join(""));
};
const checkNumber = (number) => {
  const numbers = number.split("").reduce((accum, cur) => {
    if (cur === "0" || cur === "1") accum += 1;
    return accum;
  }, 0);
  return numbers === number.length;
};

btn.addEventListener("click", (e) => {
  e.preventDefault();
  const storeArr = [];
  for ([key, value] of inputEle.entries()) {
    if (checkNumber(value.value)) {
      storeArr.push(value.value);
    } else {
      alert("Invalid binary");
      return;
    }
  }
  if (storeArr[0].length !== storeArr[1].length) {
    alert("Please enter valid value");
  } else {
    adder(storeArr);
  }
});
