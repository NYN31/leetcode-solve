const min = 1,
  max = 1000000;
let randomList = [];
for (let i = 0; i < 1000000; i++) {
  randomList[i] = Math.floor(Math.random() * (max - min) + min);
}

//for (let i = 0; i < 10; i++) console.log(randomList[i]);
const ifStart = Date.now();
for (let i = 0; i < 1000000; i++) {
  if (randomList[i] == 1) console.log(1);
  else if (randomList[i] == 2) console.log(2);
  else if (randomList[i] == 3) console.log(3);
  else if (randomList[i] == 4) console.log(4);
  else if (randomList[i] == 5) console.log(5);
}
const ifEnd = Date.now();
console.log("If ===========> ", ifStart, ifEnd, ifEnd - ifStart);

const switchStart = Date.now();
for (let i = 0; i < 1000000; i++) {
  if (randomList[i] == 1) console.log(1);
  else if (randomList[i] == 2) console.log(2);
  else if (randomList[i] == 3) console.log(3);
  else if (randomList[i] == 4) console.log(4);
  else if (randomList[i] == 5) console.log(5);
}
const switchEnd = Date.now();
console.log(
  "Switch ===========> ",
  switchStart,
  switchEnd,
  switchEnd - switchStart
);
