const change=(s, prog, version)=> {
let obj={};
s=s.split(':').join('');
s=s.split('\n');
obj.title=prog;
obj.author='g964';
obj.date='2019-01-01';
const checkVar=s[5].replace('Version ','');
if(checkVar==='2.0')
obj.version='2.0';

else if(checkVar.indexOf('.')>=1 &&checkVar.lastIndexOf('.')===checkVar.indexOf('.') &&parseFloat(checkVar,10)){
obj.version=version;
}
else
return 'ERROR: VERSION or PHONE';

let valid='+1-xxx-xxx-xxxx';
let dup=s[3].replace('Phone ','');
let dup2=dup;
dup=dup.split('');
dup2.split('').forEach((ele,index)=>{
if(ele==='+' ||ele==='-' ||(ele==='1'&& index===1)){}
else if(parseInt(ele,10)||ele==='0')
{dup[index]='x';
}});
if(dup.join('')===valid)
obj.phone='+1-503-555-0090';
else
return 'ERROR: VERSION or PHONE';

return  `Program: ${obj.title} Author: ${obj.author} Phone: ${obj.phone} Date: ${obj.date} Version: ${obj.version}`
}