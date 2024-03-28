<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Button Click Example</title>
  <script>
    function sendRequest(method) {
      var xhr = new XMLHttpRequest();
      var url = "http://localhost:8080/try_war_exploded/response";
      xhr.open(method, url, true);
      xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
      xhr.onreadystatechange = function() {
        if (xhr.readyState === 4) {
          if (xhr.status === 200) {
            alert("Button clicked successfully! Response: " + xhr.responseText);
          } else {
            alert("Failed to click button! Status: " + xhr.status);
          }
        }
      };
      var data = null;
      if (method === "POST" || method === "PUT") {
        data = "buttonClicked=true";
      }
      xhr.send(data);
    }
  </script>
</head>
<body>
<h2>Click the buttons below to send requests to the backend</h2>
<button onclick="sendRequest('GET')">GET 200</button>
<button onclick="sendRequest('POST')">POST 302</button>
<button onclick="sendRequest('PUT')">PUT 403</button>
<button onclick="sendRequest('DELETE')">DELETE 504</button>


</body>
</html>