userInterface();

function userInterface(){
    var submit=document.querySelector('#submit');
submit.addEventListener('click',function(e){
    var expression= document.querySelector("#expression").value;
    var answerDisplay=document.querySelector("#answerDisplay");
    answerDisplay.textContent=`Answer:${calculate(expression)
    }`;
    e.preventDefault();   
});
}

function calculate(expr){
    var operands=[];
    var operators=[];
    arrayData(expr, operands, operators);    
    return computation(expr,operands,operators);
}

function arrayData(expr, operands, operators ){
    var size=expr.length;   
    var num='';
    for(var i=0; i<size;i++){
       if((expr[i]==='-') && (i===0)){//Skip beginning neg sign
        continue;        
        }
        else if ((expr[i]!=='-') && (expr[i]!=='+')){
            num+=expr[i];
            if(i===size-1){
                operands.push(Number(num));//Pushes the last #
            }
        }
        else{
          operators.push(expr[i]);
          operands.push(Number(num));//Whole number complete so push
          num='';//Startover              
          }
        }        
    }

function firstOperand(expr,operands){
    if(expr[0]==='-'){
        operands[0]*=-1;                
    }
    return operands[0];
}

function computation(expr,operands,operators){
    var ans=firstOperand(expr,operands);
    operators.forEach(function(op,index){
        if(op==='+'){  
            ans+=operands[index+1];
        }
        else{
            ans-=operands[index+1]; 
        }
    });
    return ans;
}


