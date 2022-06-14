// Variable declaration Using let keyword  
let name="Suyash";

// Array
let colors=['red','blue'];
colors[4]='green'

//Object
            let person={
                firstname:"Raman",
                age:40
            };

            // Accessing member of object
                // -- Dot operator
                    person.age=40;

                // -- Key value pairs
                    person['age']=10;


// FUNCTIONS
  // function definition
  function greet(name){
      console.log('Hello '+name)
  }
  //function call
  greet(name);

  //function with return
  function square(num){
      return num*num;
  }



//Printing Values on console
console.log(square(5));
