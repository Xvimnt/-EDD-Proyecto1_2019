
//==============================ARCHIVO CONSTANT.JS====================
const ap_user="http://localhost:9098/a1/echo..";

//============================FILL the table.JS==============================

//Method 2 - With custom columns

//Will create and return table data
var Columns = ["Names", "Sites"];

var tbl = js.CreateTable(DataArr,Columns);

//Out put table
$('.mytablediv').html(tbl);

var CreateTable = function (DataArr,Columns)
{
	var GetHeaderNames = _.size(Columns) <1 ? DataArr[0] : Columns;
	var GetRows = DataArr;

	var d ='';
	d += '<table class="table table-hover table-bordered " width="100%">';

	//--->Create Header- Start
	d += '<thead>';
	d += '<tr>';
	$.each(GetHeaderNames,function(index, value)
	{
		var col_value = _.size(Columns) <1 ? index : value;
		d += '<th >'+_.startCase(col_value)+'</th>';
	})
	d += '</tr>';
	d += '</thead>';
	//--->Create Header- End

	//--->Create Rows - Start
	d += '<tbody>';
	$.each(GetRows,function(index, v1)
	{
		d += '<tr>';
		$.each(v1,function(index, v2)
		{
			d += '<td id="myTable" >'+v2+'</td>';
		})
		d += '</tr>';
	})
	d += "</tbody>";
	//--->Create Rows - End

	d +=" </table>";
	return d;
}

//============================CONTROLER.JS==============================

function ini_session(form) {  
    var user = document.getElementById('TUser').value;
    var password = document.getElementById('TPass').value;
    //LAS ALERTAS SI SE EJECUTAN PERO NO REDIRECCIONA
    if(password == '201700831'){
        switch(user){
            case 'gestor':
                alert('si'); 
                location.href ='index.html';
                alert('ya se ejecutó'); 
                break;
            case 'admin':
                alert('si admin');
                location.href ='index2.html';
                break;
            default:
                alert('usuario y/o contraseña incorrecta');
                break;
        }
    }else{
        alert('Usuario y/o contraseña incorrectos');
    }
    
    httpPost(ap_user,function(response){
        var result = JSON.parse(response);
        if(result.result==true){
            window.location.href="index.html";
        }

    });
}

//===========================================REQUEST==========================
function httpPost(url,callback){
    
    var xmlHTTP= new XMLHttpRequest();
    xmlHTTP.open("POST",url,true);
    xmlHTTP.setRequestHeader('Content-Type','application/json');
    xmlHTTP.onreadystatechange=function(){
        if(xmlHTTP.readyState==4 && xmlHTTP.status==200){
            callback(xmlHTTP.responseText);
        }
    }
    xmlHTTP.send(JSON.stringify(abc));     
}

function httpGet(url,callback){
    
    var xmlHTTP= new XMLHttpRequest();
    xmlHTTP.open("GET",url,true);
    xmlHTTP.setRequestHeader('Content-Type','application/json');
    xmlHTTP.onreadystatechange=function(){
        if(xmlHTTP.readyState==4 && xmlHTTP.status==200){
            callback(xmlHTTP.responseText);
        }
    }
    xmlHTTP.send();     
}
