const toPostfix =infix=> {
  let stack=[];
  let postFix=[];
  const isOperator=op=>{
   if(op==='+' ||op==='-' ||op==='/' ||op==='*' ||op==='^')
    return true;
   else
   return false;
  }
  const priority=op=>{
   if(op==='^')
    return 3;
    else if(op==='/' ||op==='*')
    return 2;
    else if(op==='+' ||op==='-')
    return 1;
  }
  stack.push('(');
  infix=infix.split('');
  infix.push(')');
  infix.forEach(ele=>{
   if(ele==='(')
    stack.push(ele);
  else if(parseInt(ele,10))
    postFix.push(ele);
  else if(isOperator(ele)){
    let x=stack.pop();
    while(isOperator(x) && priority(x)>=priority(ele))
    { postFix.push(x);
       x=stack.pop();
     }
     stack.push(x);
     stack.push(ele);
  }
  else if(ele===')'){
 let  x=stack.pop();
   while(x!=='(')
   {
    postFix.push(x);
    x=stack.pop();
   }
  }
  });
  return postFix.join('');
}