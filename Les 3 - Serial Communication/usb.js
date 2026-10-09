const encoder = new TextEncoder();
const decoder = new TextDecoder();
var port = null, reader = null, writer = null, 
usbResponse = null, isSetup = false, asciiRes = "";

document.addEventListener('click', ()=> {

});

async function RequestSerialIO() {

}

async function WriteToSerial(jsonObj) {

}

async function ReadUntilClosed() {

}

function ParseResponse() {
    while(asciiRes.indexOf("{") >= 0 
          && asciiRes.indexOf("}", asciiRes.indexOf("{")) >= 0 
          && asciiRes.length > 0) {

        // get current substring
        let res = "", 
        inxa = asciiRes.indexOf("{"),
        inxb = asciiRes.indexOf("}", inxa) + 1;
        res = asciiRes.substring(inxa, inxb);
        console.log("asciiRes >> " + asciiRes + "\nres >> " + res);
        usbResponse = JSON.parse(res);
        console.log(usbResponse);

        // remove substring + excess from total response
        asciiRes = asciiRes.substring(asciiRes.indexOf("}") + 1);
    }
}
