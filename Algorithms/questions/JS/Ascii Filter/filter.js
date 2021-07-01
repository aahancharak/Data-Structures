const moreZeros = s => {
  let dataArr = [];
  s.split('').forEach(ele => {
    if (!dataArr.includes(ele)) {
      if (convertToBinary(ele.charCodeAt(0))) dataArr.push(ele);
    }
  });
  return dataArr;
};

const convertToBinary = num => {
  let digitArr = [];
  let numZeros = 0;
  let numOne = 0;
  while (num !== 0) {
    digitArr.push(num % 2);
    num % 2 === 0 ? numZeros++ : numOne++;
    num = Math.floor(num / 2);
  }
  if (numZeros > numOne) return digitArr.reverse().join();
  return null;
};
