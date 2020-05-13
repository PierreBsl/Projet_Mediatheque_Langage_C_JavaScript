function getAuthorOrBookName() {
    let selected_id = $("select option:selected").attr("id");

    if (selected_id == "author"){

        writeFile1('search_form', 'findByAuthor');
    }
    else if (selected_id == "Book name"){

        writeFile1('search_form', 'findByName');
    }
    else if (selected_id == "genre"){

        writeFile1('search_form', 'findByGenre');
    }
    window.location.reload();
}
function reload(){

    location.reload();
}

function writeFile1(id_form,func) {

    var element = document.createElement('a');

    let text1 = document.getElementById(id_form);
    let count = text1.elements.length;
    let textToSave = func;
    for(let i = 1;i<count-1;i++){
        textToSave += ";" + text1[i].value;
    }

    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(textToSave));
    element.setAttribute('download', 'request.txt');

    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);
}

function free(text){

    var element = document.createElement('a');

    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
    element.setAttribute('download', 'request.txt');

    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);
}

function main(){

    let elt = document.getElementById('search_button');
    elt.addEventListener('click', function(){
        getAuthorOrBookName();
    });

    let elt5 = document.getElementById('lien_books');
    elt5.addEventListener('click', function(){
        free('getAll');
    });

    let elt3 = document.getElementById('power');
    elt3.addEventListener('click', function(){
        free('end');
    });
}
main();