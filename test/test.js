aFuncDeclaration();
function aFuncDeclaration() {
  console.log("aFunc Function Statement or Declaration");
  // aFunc Function Statement or Declaration
}

aConsFuncExpression(); //Uncaught ReferenceError: Cannot access 'makeCoffee' before initialization
const aConsFuncExpression = function () {
  console.log("aConst Function Expression");
};
